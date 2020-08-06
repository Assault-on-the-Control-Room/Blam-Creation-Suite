#include "gameframework-private-pch.h"

c_discord_presense_api::c_discord_presense_api(const char* app_id) :
	is_connected(false),
	is_state_update_pending(true),
	is_state_empty(true)
{
	DiscordEventHandlers handlers = {};
	handlers.userData = this;
	handlers.ready = on_discord_ready;
	handlers.disconnected = on_discord_disconnected;
	handlers.errored = on_discord_error;
	handlers.joinGame = on_discord_join;
	handlers.spectateGame = on_discord_spectate;
	handlers.joinRequest = on_discord_join_request;
	Discord_Initialize(app_id, &handlers, 1, NULL);

	s_apis.push_back(this);
}

c_discord_presense_api::~c_discord_presense_api()
{
	Discord_Shutdown();
	vector_erase_by_value_helper(s_apis, this);
}

void c_discord_presense_api::set_state_impl(s_presense_info* presense_info)
{
	is_state_empty = presense_info == nullptr;
	if (!is_state_empty)
	{
		match_secret = "#TODO";
		if (presense_info->is_joinable)
		{
			join_secret.format("#TODO"); // #TODO: Playfab Match Join ID
		}
		else
		{
			join_secret.clear();
		}
		spectate_secret.clear();

		const char* engine_name = engine_type_to_folder_name<decltype(engine_name)>(presense_info->engine_type);
		if (engine_name == nullptr)
		{
			engine_name = "not_set";
		}
		large_image_name.format("engine_%s", engine_name);
		large_image_name.lowercase();
		small_image_name.clear();

		const char* engine_nice_name = engine_type_to_folder_nice_name<decltype(engine_nice_name)>(presense_info->engine_type);
		const char* map_name = presense_info->map_name.c_str();
		if (presense_info->engine_type == _engine_type_not_set)
		{
			map_name = "Lobby";
			engine_nice_name = "Main Menu";
		}

		if (!presense_info->gametype_name.is_empty())
		{
			details.format("%s: %s", engine_nice_name, presense_info->gametype_name.c_str());
		}
		else
		{
			details.format("%s", engine_nice_name);
		}

		state = map_name;
		start_timestamp = presense_info->start_timestamp;
		end_timestamp = presense_info->end_timestamp;
		party_size = presense_info->party_size;
		party_max = presense_info->party_max;
	}

	is_state_update_pending = true;
}

void c_discord_presense_api::update_impl()
{
#ifdef DISCORD_DISABLE_IO_THREAD
	Discord_UpdateConnection();
#endif
	Discord_RunCallbacks();

	if (!is_connected)
	{
		return;
	}

	if (is_state_update_pending)
	{
		if (is_state_empty)
		{
			Discord_ClearPresence();
		}
		else
		{
			DiscordRichPresence discord_presence = {};
			discord_presence.state = state.c_str();
			discord_presence.details = details.c_str();
			discord_presence.startTimestamp = start_timestamp;
			discord_presence.endTimestamp = end_timestamp;
			discord_presence.largeImageKey = large_image_name.c_str();
			discord_presence.smallImageKey = small_image_name.c_str();
			discord_presence.partyId = "party1234";
			discord_presence.partySize = party_size;
			discord_presence.partyMax = party_max;
			discord_presence.matchSecret = match_secret.c_str();
			discord_presence.joinSecret = join_secret.c_str();
			discord_presence.spectateSecret = spectate_secret.c_str();
			discord_presence.instance = 0;

			Discord_UpdatePresence(&discord_presence);
		}

		is_state_update_pending = false;
	}
}

void c_discord_presense_api::on_discord_ready(void* user_data, const DiscordUser* connected_user)
{
	static_cast<c_discord_presense_api*>(user_data)->on_discord_ready(connected_user);
}

void c_discord_presense_api::on_discord_ready(const DiscordUser* connected_user)
{
	c_console::write_line(
		"Discord: connected to user %s#%s - %s\n",
		connected_user->username,
		connected_user->discriminator,
		connected_user->userId);

	is_connected = true;
	is_state_update_pending = true;
}

void c_discord_presense_api::on_discord_disconnected(void* user_data, int error_code, const char* message)
{
	static_cast<c_discord_presense_api*>(user_data)->on_discord_disconnected(error_code, message);
}

void c_discord_presense_api::on_discord_disconnected(int error_code, const char* message)
{
	c_console::write_line("Discord: disconnected (%d: %s)\n", error_code, message);

	is_connected = false;
	is_state_update_pending = true;
}

void c_discord_presense_api::on_discord_error(void* user_data, int error_code, const char* message)
{
	static_cast<c_discord_presense_api*>(user_data)->on_discord_error(error_code, message);
}

void c_discord_presense_api::on_discord_error(int error_code, const char* message)
{
	c_console::write_line("Discord: error (%d: %s)\n", error_code, message);
}

void c_discord_presense_api::on_discord_join(void* user_data, const char* secret)
{
	static_cast<c_discord_presense_api*>(user_data)->on_discord_join(secret);
}

void c_discord_presense_api::on_discord_join(const char* secret)
{
	c_console::write_line("Discord: join (%s)\n", secret);
}

void c_discord_presense_api::on_discord_spectate(void* user_data, const char* secret)
{
	static_cast<c_discord_presense_api*>(user_data)->on_discord_spectate(secret);
}

void c_discord_presense_api::on_discord_spectate(const char* secret)
{
	c_console::write_line("Discord: spectate (%s)\n", secret);
}

void c_discord_presense_api::on_discord_join_request(void* user_data, const DiscordUser* request)
{
	static_cast<c_discord_presense_api*>(user_data)->on_discord_join_request(request);
}

void c_discord_presense_api::on_discord_join_request(const DiscordUser* request)
{
	c_console::write_line(
		"Discord: join request from %s#%s - %s\n",
		request->username,
		request->discriminator,
		request->userId);

	Discord_Respond(request->userId, DISCORD_REPLY_NO);
}