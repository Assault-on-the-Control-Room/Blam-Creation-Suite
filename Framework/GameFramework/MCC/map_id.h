#pragma once

enum e_map_id : uint32_t
{
	_map_id_halo1_pillar_of_autumn = 0,
	_map_id_halo1_halo,
	_map_id_halo1_truth_and_reconciliation,
	_map_id_halo1_silent_cartographer,
	_map_id_halo1_assault_on_the_control_room,
	_map_id_halo1_343_guilty_spark,
	_map_id_halo1_the_library,
	_map_id_halo1_two_betrayals,
	_map_id_halo1_keyes,
	_map_id_halo1_the_maw,
	_map_id_halo1_battle_creek,
	_map_id_halo1_sidewinder,
	_map_id_halo1_damnation,
	_map_id_halo1_rat_race,
	_map_id_halo1_prisoner,
	_map_id_halo1_hang_em_high,
	_map_id_halo1_chill_out,
	_map_id_halo1_derelict,
	_map_id_halo1_boarding_action,
	_map_id_halo1_chiron,
	_map_id_halo1_blood_gulch,
	_map_id_halo1_wizard,
	_map_id_halo1_longest,
	_map_id_halo1_death_island,
	_map_id_halo1_danger_canyon,
	_map_id_halo1_infinity,
	_map_id_halo1_timberland,
	_map_id_halo1_ice_fields,
	_map_id_halo1_gephyrophobia,
	_map_id_halo2_the_heretic,
	_map_id_halo2_the_armory,
	_map_id_halo2_cairo_station,
	_map_id_halo2_outskirts,
	_map_id_halo2_metropolis,
	_map_id_halo2_the_arbiter,
	_map_id_halo2_the_oracle,
	_map_id_halo2_delta_halo,
	_map_id_halo2_regret,
	_map_id_halo2_sacred_icon,
	_map_id_halo2_quarantine_zone,
	_map_id_halo2_gravemind,
	_map_id_halo2_uprising,
	_map_id_halo2_high_charity,
	_map_id_halo2_the_great_journey,
	_map_id_halo2_lockout,
	_map_id_halo2_ascension,
	_map_id_halo2_midship,
	_map_id_halo2_ivory_tower,
	_map_id_halo2_beaver_creek,
	_map_id_halo2_burial_mounds,
	_map_id_halo2_colossus,
	_map_id_halo2_zanzibar,
	_map_id_halo2_coagulation,
	_map_id_halo2_headlong,
	_map_id_halo2_waterworks,
	_map_id_halo2_foundation,
	_map_id_halo2_containment,
	_map_id_halo2_warlock,
	_map_id_halo2_sanctuary,
	_map_id_halo2_turf,
	_map_id_halo2_backwash,
	_map_id_halo2_elongation,
	_map_id_halo2_gemini,
	_map_id_halo2_relic,
	_map_id_halo2_terminal,
	_map_id_halo2_desolation,
	_map_id_halo2_tombstone,
	_map_id_halo2_district,
	_map_id_halo2_uplift,
	_map_id_halo3_arrival,
	_map_id_halo3_sierra_117,
	_map_id_halo3_crows_nest,
	_map_id_halo3_tsavo_highway,
	_map_id_halo3_the_storm,
	_map_id_halo3_floodgate,
	_map_id_halo3_the_ark,
	_map_id_halo3_the_covenant,
	_map_id_halo3_cortana,
	_map_id_halo3_halo,
	_map_id_halo3_construct,
	_map_id_halo3_epitaph,
	_map_id_halo3_guardian,
	_map_id_halo3_high_ground,
	_map_id_halo3_isolation,
	_map_id_halo3_last_resort,
	_map_id_halo3_narrows,
	_map_id_halo3_sandtrap,
	_map_id_halo3_snowbound,
	_map_id_halo3_the_pit,
	_map_id_halo3_valhalla,
	_map_id_halo3_foundry,
	_map_id_halo3_rats_nest,
	_map_id_halo3_standoff,
	_map_id_halo3_avalanche,
	_map_id_halo3_blackout,
	_map_id_halo3_ghost_town,
	_map_id_halo3_cold_storage,
	_map_id_halo3_assembly,
	_map_id_halo3_orbital,
	_map_id_halo3_sandbox,
	_map_id_halo3_citadel,
	_map_id_halo3_heretic,
	_map_id_halo3_longshore,
	_map_id_halo4_prologue,
	_map_id_halo4_dawn,
	_map_id_halo4_requiem,
	_map_id_halo4_forerunner,
	_map_id_halo4_infinity,
	_map_id_halo4_reclaimer,
	_map_id_halo4_shutdown,
	_map_id_halo4_composer,
	_map_id_halo4_midnight,
	_map_id_halo4_epilogue,
	_map_id_halo4_multiplayer_first_DONOTUSE_OR_REMOVE,
	_map_id_halo4_adrift,
	_map_id_halo4_abandon,
	_map_id_halo4_complex,
	_map_id_halo4_exile,
	_map_id_halo4_haven,
	_map_id_halo4_longbow,
	_map_id_halo4_meltdown,
	_map_id_halo4_ragnarok,
	_map_id_halo4_solace,
	_map_id_halo4_vortex,
	_map_id_halo4_ravine,
	_map_id_halo4_impact,
	_map_id_halo4_erosion,
	_map_id_halo4_forge_island,
	_map_id_halo4_wreckage,
	_map_id_halo4_harvest,
	_map_id_halo4_shatter,
	_map_id_halo4_landfall,
	_map_id_halo4_monolith,
	_map_id_halo4_skyline,
	_map_id_halo4_daybreak,
	_map_id_halo4_outcast,
	_map_id_halo4_perdition,
	_map_id_halo4_pitfall,
	_map_id_halo4_vertigo,
	_map_id_halo4_spartan_ops_first_DONOTUSE_OR_REMOVE,
	_map_id_halo4_ff_chopperbowl,
	_map_id_halo4_ff_sniperalley,
	_map_id_halo4_ff_fortsw,
	_map_id_halo4_ff_temple,
	_map_id_halo4_ff_scurve,
	_map_id_halo4_ff_courtyard,
	_map_id_halo4_ff_complex,
	_map_id_halo4_ff_valhalla,
	_map_id_halo4_ff_factory,
	_map_id_halo4_ff_mezzanie,
	_map_id_halo4_ff_caverns,
	_map_id_halo4_ff_vortex,
	_map_id_halo4_ff_breach,
	_map_id_halo4_ff_hillside,
	_map_id_halo4_ff_engine,
	_map_id_groundhog_lockout,
	_map_id_groundhog_ascension,
	_map_id_groundhog_zanzibar,
	_map_id_groundhog_coagulation,
	_map_id_groundhog_warlock,
	_map_id_groundhog_sanctuary,
	_map_id_groundhog_forge_skybox01,
	_map_id_groundhog_forge_skybox02,
	_map_id_groundhog_forge_skybox03,
	_map_id_halo3_extracredit_first_DONOTUSE_OR_REMOVE,
	_map_id_halo3_epilogue,
	_map_id_halo3odst_prepare_to_drop,
	_map_id_halo3odst_mombasa_streets,
	_map_id_halo3odst_tayari_plaza,
	_map_id_halo3odst_uplift_reserve,
	_map_id_halo3odst_kizingo_boulevard,
	_map_id_halo3odst_oni_alpha_site,
	_map_id_halo3odst_nmpd_hq,
	_map_id_halo3odst_kikowani_station,
	_map_id_halo3odst_data_hive,
	_map_id_halo3odst_coastal_highway,
	_map_id_halo3odst_epilogue,
	_map_id_groundhog_relic,
	_map_id_haloreach_noble_actual,
	_map_id_haloreach_winter_contingency,
	_map_id_haloreach_oni_sword_base,
	_map_id_haloreach_nightfall,
	_map_id_haloreach_tip_of_the_spear,
	_map_id_haloreach_long_night_of_solace,
	_map_id_haloreach_exodus,
	_map_id_haloreach_new_alexandria,
	_map_id_haloreach_the_package,
	_map_id_haloreach_the_pillar_of_autumn,
	_map_id_haloreach_the_pillar_of_autumn_credits,
	_map_id_haloreach_lone_wolf,
	_map_id_haloreach_boardwalk,
	_map_id_haloreach_boneyard,
	_map_id_haloreach_countdown,
	_map_id_haloreach_powerhouse,
	_map_id_haloreach_reflection,
	_map_id_haloreach_spire,
	_map_id_haloreach_sword_base,
	_map_id_haloreach_zealot,
	_map_id_haloreach_anchor_9,
	_map_id_haloreach_breakpoint,
	_map_id_haloreach_tempest,
	_map_id_haloreach_condemned,
	_map_id_haloreach_highlands,
	_map_id_haloreach_battle_canyon,
	_map_id_haloreach_penance,
	_map_id_haloreach_ridgeline,
	_map_id_haloreach_solitary,
	_map_id_haloreach_high_noon,
	_map_id_haloreach_breakneck,
	_map_id_haloreach_forge_world,
	_map_id_haloreach_beachhead,
	_map_id_haloreach_corvette,
	_map_id_haloreach_courtyard,
	_map_id_haloreach_glacier,
	_map_id_haloreach_holdout,
	_map_id_haloreach_outpost,
	_map_id_haloreach_overlook,
	_map_id_haloreach_waterfront,
	_map_id_haloreach_unearthed,
	_map_id_haloreach_installation_04,

	k_number_of_map_ids,
	_map_id_none = ~0u,
	_map_id_mainmenu = 0x10231971,
};

extern BCS_RESULT get_map_id_pretty_string(e_map_id map_id, const char** result);
extern BCS_RESULT get_map_id_string(e_map_id map_id, const char** result);


e_engine_type map_id_to_engine_type(e_map_id map_id);
e_mcc_game_mode map_id_to_game_mode(e_map_id map_id);
std::vector<signed int>& map_id_to_available_insertion_points(long map_id, bool is_firefight);

