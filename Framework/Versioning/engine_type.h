#pragma once

enum e_engine_type : uint8_t
{
	_engine_type_not_set,
	_engine_type_mcc,
	_engine_type_halo1,
	_engine_type_halo2,
	_engine_type_halo3,
	_engine_type_halo3odst,
	_engine_type_haloreach,
	_engine_type_halo4,
	_engine_type_groundhog,
	_engine_type_eldorado,
	_engine_type_halo5,
	_engine_type_gen3_xbox360,
	k_number_of_engine_types
};

template<typename string_type, bool pretty_string>
inline string_type get_enum_string(e_engine_type engine_type)
{
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_not_set, "Not Set");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_mcc, "Master Chief Collection");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_haloreach, "Halo Reach");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_halo1, "Halo 1");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_halo2, "Halo 2");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_halo3, "Halo 3");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_halo3odst, "Halo 3: ODST");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_halo4, "Halo 4");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_groundhog, "Groundhog");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_eldorado, "Eldorado");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_halo5, "Halo 5 Forge");
	enum_string_ex(string_type, pretty_string, engine_type, _engine_type_gen3_xbox360, "Xbox 360 Gen3");
	return nullptr;
}

template<typename string_type>
constexpr string_type engine_type_to_folder_name(e_engine_type engine_type) // #TODO: Create CPP files, or generate these using LLVM
{
	enum_string_ex(string_type, true, engine_type, _engine_type_haloreach, "haloreach");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo1, "halo1");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo2, "halo2");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo3, "halo3");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo3odst, "halo3odst");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo4, "halo4");
	enum_string_ex(string_type, true, engine_type, _engine_type_groundhog, "groundhog");
	enum_string_ex(string_type, true, engine_type, _engine_type_gen3_xbox360, "xbox360_gen3");
	return nullptr;
}

template<typename string_type>
constexpr string_type engine_type_to_simple_name(e_engine_type engine_type) // #TODO: Create CPP files, or generate these using LLVM
{
	enum_string_ex(string_type, true, engine_type, _engine_type_haloreach, "haloreach");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo1, "halo1");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo2, "halo2");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo3, "halo3");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo3odst, "halo3odst");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo4, "halo4");
	enum_string_ex(string_type, true, engine_type, _engine_type_groundhog, "groundhog");
	enum_string_ex(string_type, true, engine_type, _engine_type_gen3_xbox360, "xbox360_gen3");
	return nullptr;
}

template<typename string_type>
constexpr string_type engine_type_to_folder_nice_name(e_engine_type engine_type) // #TODO: Create CPP files, or generate these using LLVM
{
	enum_string_ex(string_type, true, engine_type, _engine_type_haloreach, "HaloReach");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo1, "Halo1");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo2, "Halo2");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo3, "Halo3");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo3odst, "Halo3Odst");
	enum_string_ex(string_type, true, engine_type, _engine_type_halo4, "Halo4");
	enum_string_ex(string_type, true, engine_type, _engine_type_groundhog, "Halo2A");
	return nullptr;
}