#pragma once

class c_discord_presense_api :
	public c_presense_api
{
public:
	c_discord_presense_api(const char* app_id);
	~c_discord_presense_api();

	virtual void update_impl();
	virtual void set_state_impl(s_presense_info* presense_info);

protected:
	void on_discord_ready(const DiscordUser* connected_user);
	void on_discord_disconnected(int error_code, const char* message);
	void on_discord_error(int error_code, const char* message);
	void on_discord_join(const char* secret);
	void on_discord_spectate(const char* secret);
	void on_discord_join_request(const DiscordUser* request);

	bool is_connected;
	bool is_state_update_pending;
	bool is_state_empty;
	c_fixed_string_128 details;
	c_fixed_string_128 state;
	c_fixed_string_128 large_image_name;
	c_fixed_string_128 small_image_name;
	int64_t start_timestamp;
	int64_t end_timestamp;
	int party_size;
	int party_max;
	c_fixed_string_128 match_secret;
	c_fixed_string_128 join_secret;
	c_fixed_string_128 spectate_secret;

private:
	static void on_discord_ready(void* user_data, const DiscordUser* connected_user);
	static void on_discord_disconnected(void* user_data, int error_code, const char* message);
	static void on_discord_error(void* user_data, int error_code, const char* message);
	static void on_discord_join(void* user_data, const char* secret);
	static void on_discord_spectate(void* user_data, const char* secret);
	static void on_discord_join_request(void* user_data, const DiscordUser* request);
};