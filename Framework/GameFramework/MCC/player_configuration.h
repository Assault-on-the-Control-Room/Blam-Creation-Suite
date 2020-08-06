#pragma once

enum class e_customization_item_v1 : long
{
	HR_Helmet_MarkVB_Base,
	HR_Helmet_MarkVB_UA,
	HR_Helmet_MarkVB_UAHUL,
	HR_Helmet_CQC_Base,
	HR_Helmet_CQC_CBRN,
	HR_Helmet_CQC_UAHUL,
	HR_Helmet_ODST_Base,
	HR_Helmet_ODST_UACNM,
	HR_Helmet_ODST_CBRNHUL,
	HR_Helmet_HAZOP_Base,
	HR_Helmet_HAZOP_CBRNHUL,
	HR_Helmet_HAZOP_CNMI,
	HR_Helmet_EOD_Base,
	HR_Helmet_EOD_CNM,
	HR_Helmet_EOD_UAHUL,
	HR_Helmet_Operator_Base,
	HR_Helmet_Operator_UAHUL,
	HR_Helmet_Operator_CNM,
	HR_Helmet_Grenadier_Base,
	HR_Helmet_Grenadier_UA,
	HR_Helmet_Grenadier_UAFC,
	HR_Helmet_AirAssault_Base,
	HR_Helmet_AirAssault_UACNM,
	HR_Helmet_AirAssault_FCI,
	HR_Helmet_Scout_Base,
	HR_Helmet_Scout_HURS,
	HR_Helmet_Scout_CBRNCNM,
	HR_Helmet_EVA_Base,
	HR_Helmet_EVA_CNM,
	HR_Helmet_EVA_UAHUL3,
	HR_Helmet_JFO_Base,
	HR_Helmet_JFO_HULI,
	HR_Helmet_JFO_UA,
	HR_Helmet_Commando_Base,
	HR_Helmet_Commando_CBRNCNM,
	HR_Helmet_Commando_UAFCI2,
	HR_Helmet_EVAC_Base,
	HR_Helmet_EVAC_CNM,
	HR_Helmet_EVAC_UAHUL3,
	HR_Helmet_MjolnirMKV_Base,
	HR_Helmet_MjolnirMKV_CNM,
	HR_Helmet_MjolnirMKV_UA,
	HR_Helmet_Pilot_Base,
	HR_Helmet_Pilot_HUL3,
	HR_Helmet_Pilot_UAHUL3,
	HR_Helmet_Pilot_Haunted,
	HR_Helmet_Recon_Base,
	HR_Helmet_Recon_HUL,
	HR_Helmet_Recon_UAHUL3,
	HR_Helmet_MjolnirMKVI_Base,
	HR_Helmet_MjolnirMKVI_FCI2,
	HR_Helmet_MjolnirMKVI_UAHULI,
	HR_Helmet_Gungnir_Base,
	HR_Helmet_Gungnir_HURS,
	HR_Helmet_Gungnir_CBRN,
	HR_Helmet_Security_Base,
	HR_Helmet_Security_UAHUL,
	HR_Helmet_Security_CBRNCNM,
	HR_Helmet_MilitaryPolice_Base,
	HR_Helmet_MilitaryPolice_CBRNHURS,
	HR_Helmet_MilitaryPolice_HURSCNM,
	HR_Helmet_CQB_Base,
	HR_Helmet_CQB_HURSCNM,
	HR_Helmet_CQB_UAHUL,

	HR_LeftShoulder_Default,
	HR_LeftShoulder_FJPARA,
	HR_LeftShoulder_HAZOP,
	HR_LeftShoulder_JFO,
	HR_LeftShoulder_Recon,
	HR_LeftShoulder_UAMultiThreat,
	HR_LeftShoulder_Jumpjet,
	HR_LeftShoulder_EVA,
	HR_LeftShoulder_Gungnir,
	HR_LeftShoulder_ODST,
	HR_LeftShoulder_UABaseSecurity,
	HR_LeftShoulder_CQC,
	HR_LeftShoulder_Operator,
	HR_LeftShoulder_Commando,
	HR_LeftShoulder_Grenadier,
	HR_LeftShoulder_Sniper,
	HR_LeftShoulder_MjolnirMarkV,
	HR_LeftShoulder_Security,

	HR_RightShoulder_Default,
	HR_RightShoulder_FJPARA,
	HR_RightShoulder_HAZOP,
	HR_RightShoulder_JFO,
	HR_RightShoulder_Recon,
	HR_RightShoulder_UAMultiThreat,
	HR_RightShoulder_Jumpjet,
	HR_RightShoulder_EVA,
	HR_RightShoulder_Gungnir,
	HR_RightShoulder_ODST,
	HR_RightShoulder_UABaseSecurity,
	HR_RightShoulder_CQC,
	HR_RightShoulder_Operator,
	HR_RightShoulder_Commando,
	HR_RightShoulder_Grenadier,
	HR_RightShoulder_Sniper,
	HR_RightShoulder_MjolnirMarkV,
	HR_RightShoulder_Security,

	HR_Chest_Default,
	HR_Chest_HPHalo,
	HR_Chest_UACounterAssault,
	HR_Chest_TacticalLRP,
	HR_Chest_UAODST,
	HR_Chest_TacticalRecon,
	HR_Chest_CollarGrenadier,
	HR_Chest_TacticalPatrol,
	HR_Chest_CollarBreacher,
	HR_Chest_AssaultSapper,
	HR_Chest_AssaultCommando,
	HR_Chest_HPParaFoil,
	HR_Chest_CollarGrenadierUA,
	HR_Chest_UABaseSecurityW,
	HR_Chest_CollarBreacherR,
	HR_Chest_HPParaFoilR,
	HR_Chest_AssaultSapperR,

	HR_Wrist_Default,
	HR_Wrist_UABuckler,
	HR_Wrist_UABracer,
	HR_Wrist_TacticalTACPAD,
	HR_Wrist_TacticalUGPS,
	HR_Wrist_AssaultBreacher,

	HR_Utility_Default,
	HR_Utility_UACHOBHAM,
	HR_Utility_TacticalHardcase,
	HR_Utility_UANXRA,
	HR_Utility_TacticalTraumaKit,
	HR_Utility_TacticalSoftcase,

	HR_VisorColor_Default,
	HR_VisorColor_Silver,
	HR_VisorColor_Blue,
	HR_VisorColor_Black,
	HR_VisorColor_Gold,

	HR_KneeGuards_Default,
	HR_KneeGuards_FJPARA,
	HR_KneeGuards_Gungnir,
	HR_KneeGuards_Grenadier,

	HR_ArmorEffect_Default,
	HR_ArmorEffect_BirthdayParty,
	HR_ArmorEffect_HeartAttack,
	HR_ArmorEffect_Pestilence,
	HR_ArmorEffect_InclementWeather,
	HR_ArmorEffect_Flames,
	HR_ArmorEffect_BlueFlames,

	HR_FirefightVoice_NobleSix,
	HR_FirefightVoice_JorgeS052,
	HR_FirefightVoice_JunS266,
	HR_FirefightVoice_EmileS239,
	HR_FirefightVoice_KatS320,
	HR_FirefightVoice_AuntieDotAI,
	HR_FirefightVoice_CarterS259,
	HR_FirefightVoice_GYSGTStacker,
	HR_FirefightVoice_GYSGTBuck,
	HR_FirefightVoice_SGTMAJJohnson,
	HR_FirefightVoice_CortanaAI,
	HR_FirefightVoice_JohnS117,

	HR_Spartan_Male,
	HR_Spartan_Female,

	HR_Elite_Minor,
	HR_Elite_SpecOps,
	HR_Elite_Ranger,
	HR_Elite_Ultra,
	HR_Elite_Zealot,
	HR_Elite_General,
	HR_Elite_FieldMarshall,
	HR_Elite_Officer,

	HR_Color_Steel,
	HR_Color_Silver,
	HR_Color_White,
	HR_Color_Brown,
	HR_Color_Tan,
	HR_Color_Khaki,
	HR_Color_Sage,
	HR_Color_Olive,
	HR_Color_Drab,
	HR_Color_Forest,
	HR_Color_Green,
	HR_Color_SeaFoam,
	HR_Color_Teal,
	HR_Color_Aqua,
	HR_Color_Cyan,
	HR_Color_Blue,
	HR_Color_Cobalt,
	HR_Color_Ice,
	HR_Color_Violet,
	HR_Color_Orchid,
	HR_Color_Lavender,
	HR_Color_Maroon,
	HR_Color_Brick,
	HR_Color_Rose,
	HR_Color_Rust,
	HR_Color_Coral,
	HR_Color_Peach,
	HR_Color_Gold,
	HR_Color_Yellow,
	HR_Color_Pale,

	HR_Chest_UABaseSecurity,
	HR_Chest_UAMultiThreat,
	HR_Chest_UAMultiThreatW,

	HR_Species_Spartan,
	HR_Species_Elite,

	H1_Color_1,
	H1_Color_2,
	H1_Color_3,
	H1_Color_4,
	H1_Color_5,
	H1_Color_6,
	H1_Color_7,
	H1_Color_8,
	H1_Color_9,
	H1_Color_10,
	H1_Color_11,
	H1_Color_12,
	H1_Color_13,
	H1_Color_14,
	H1_Color_15,
	H1_Color_16,
	H1_Color_17,
	H1_Color_18,

	H2_Color_1,
	H2_Color_2,
	H2_Color_3,
	H2_Color_4,
	H2_Color_5,
	H2_Color_6,
	H2_Color_7,
	H2_Color_8,
	H2_Color_9,
	H2_Color_10,
	H2_Color_11,
	H2_Color_12,
	H2_Color_13,
	H2_Color_14,
	H2_Color_15,
	H2_Color_16,
	H2_Color_17,
	H2_Color_18,

	H2A_Color_1,
	H2A_Color_2,
	H2A_Color_3,
	H2A_Color_4,
	H2A_Color_5,
	H2A_Color_6,
	H2A_Color_7,
	H2A_Color_8,
	H2A_Color_9,
	H2A_Color_10,
	H2A_Color_11,
	H2A_Color_12,
	H2A_Color_13,
	H2A_Color_14,
	H2A_Color_15,
	H2A_Color_16,
	H2A_Color_17,
	H2A_Color_18,
	H2A_Color_19,
	H2A_Color_22,
	H2A_Color_23,
	H2A_Color_24,
	H2A_Color_25,
	H2A_Color_26,
	H2A_Color_27,
	H2A_Color_28,
	H2A_Color_29,

	H2A_ARMOR_ELITE1,
	H2A_ARMOR_ELITE2,
	H2A_ARMOR_ELITE3,

	H2A_ARMOR0_MARKVI,
	H2A_ARMOR1_CENTURION,
	H2A_ARMOR_SPARTAN3,

	H3_ARMOR0_MARK_VI,
	H3_ARMOR1_CQB,
	H3_ARMOR2_EVA,
	H3_ARMOR3_RECON,
	H3_ARMOR4_HAYABUSA,
	H3_ARMOR5_EOD,
	H3_ARMOR6_SCOUT,
	H3_ARMOR7_ODST_CQB,
	H3_ARMOR9_MARK_V,
	H3_ARMOR10_ROGUE,
	H3_ARMOR11_FLAMING_HEAD,
	H3_ARMOR12_SECURITY,
	H3_ARMOR13_KATANA,
	H3_ARMOR14_COMBAT,
	H3_ARMOR15_ASSAULT,
	H3_ARMOR16_FLIGHT,
	H3_ARMOR17_ASCETIC,
	H3_ARMOR18_COMMANDO,

	H3_Color_1,
	H3_Color_2,
	H3_Color_3,
	H3_Color_4,
	H3_Color_5,
	H3_Color_6,
	H3_Color_7,
	H3_Color_8,
	H3_Color_9,
	H3_Color_10,
	H3_Color_11,
	H3_Color_12,
	H3_Color_13,
	H3_Color_14,
	H3_Color_15,
	H3_Color_16,
	H3_Color_17,
	H3_Color_18,
	H3_Color_19,
	H3_Color_20,
	H3_Color_21,
	H3_Color_22,
	H3_Color_23,
	H3_Color_24,
	H3_Color_25,
	H3_Color_26,
	H3_Color_27,
	H3_Color_28,
	H3_Color_29,

	k_customization_item_count,
	k_customization_item_none = -1
};

enum class e_customization_item_v2 : long
{
	HR_Helmet_MarkVB_Base,
	HR_Helmet_MarkVB_UA,
	HR_Helmet_MarkVB_UAHUL,
	HR_Helmet_CQC_Base,
	HR_Helmet_CQC_CBRN,
	HR_Helmet_CQC_UAHUL,
	HR_Helmet_ODST_Base,
	HR_Helmet_ODST_UACNM,
	HR_Helmet_ODST_CBRNHUL,
	HR_Helmet_HAZOP_Base,
	HR_Helmet_HAZOP_CBRNHUL,
	HR_Helmet_HAZOP_CNMI,
	HR_Helmet_EOD_Base,
	HR_Helmet_EOD_CNM,
	HR_Helmet_EOD_UAHUL,
	HR_Helmet_Operator_Base,
	HR_Helmet_Operator_UAHUL,
	HR_Helmet_Operator_CNM,
	HR_Helmet_Grenadier_Base,
	HR_Helmet_Grenadier_UA,
	HR_Helmet_Grenadier_UAFC,
	HR_Helmet_AirAssault_Base,
	HR_Helmet_AirAssault_UACNM,
	HR_Helmet_AirAssault_FCI,
	HR_Helmet_Scout_Base,
	HR_Helmet_Scout_HURS,
	HR_Helmet_Scout_CBRNCNM,
	HR_Helmet_EVA_Base,
	HR_Helmet_EVA_CNM,
	HR_Helmet_EVA_UAHUL3,
	HR_Helmet_JFO_Base,
	HR_Helmet_JFO_HULI,
	HR_Helmet_JFO_UA,
	HR_Helmet_Commando_Base,
	HR_Helmet_Commando_CBRNCNM,
	HR_Helmet_Commando_UAFCI2,
	HR_Helmet_EVAC_Base,
	HR_Helmet_EVAC_CNM,
	HR_Helmet_EVAC_UAHUL3,
	HR_Helmet_MjolnirMKV_Base,
	HR_Helmet_MjolnirMKV_CNM,
	HR_Helmet_MjolnirMKV_UA,
	HR_Helmet_Pilot_Base,
	HR_Helmet_Pilot_HUL3,
	HR_Helmet_Pilot_UAHUL3,
	HR_Helmet_Pilot_Haunted,
	HR_Helmet_Recon_Base,
	HR_Helmet_Recon_HUL,
	HR_Helmet_Recon_UAHUL3,
	HR_Helmet_MjolnirMKVI_Base,
	HR_Helmet_MjolnirMKVI_FCI2,
	HR_Helmet_MjolnirMKVI_UAHULI,
	HR_Helmet_Gungnir_Base,
	HR_Helmet_Gungnir_HURS,
	HR_Helmet_Gungnir_CBRN,
	HR_Helmet_Security_Base,
	HR_Helmet_Security_UAHUL,
	HR_Helmet_Security_CBRNCNM,
	HR_Helmet_MilitaryPolice_Base,
	HR_Helmet_MilitaryPolice_CBRNHURS,
	HR_Helmet_MilitaryPolice_HURSCNM,
	HR_Helmet_CQB_Base,
	HR_Helmet_CQB_HURSCNM,
	HR_Helmet_CQB_UAHUL,

	HR_LeftShoulder_Default,
	HR_LeftShoulder_FJPARA,
	HR_LeftShoulder_HAZOP,
	HR_LeftShoulder_JFO,
	HR_LeftShoulder_Recon,
	HR_LeftShoulder_UAMultiThreat,
	HR_LeftShoulder_Jumpjet,
	HR_LeftShoulder_EVA,
	HR_LeftShoulder_Gungnir,
	HR_LeftShoulder_ODST,
	HR_LeftShoulder_UABaseSecurity,
	HR_LeftShoulder_CQC,
	HR_LeftShoulder_Operator,
	HR_LeftShoulder_Commando,
	HR_LeftShoulder_Grenadier,
	HR_LeftShoulder_Sniper,
	HR_LeftShoulder_MjolnirMarkV,
	HR_LeftShoulder_Security,

	HR_RightShoulder_Default,
	HR_RightShoulder_FJPARA,
	HR_RightShoulder_HAZOP,
	HR_RightShoulder_JFO,
	HR_RightShoulder_Recon,
	HR_RightShoulder_UAMultiThreat,
	HR_RightShoulder_Jumpjet,
	HR_RightShoulder_EVA,
	HR_RightShoulder_Gungnir,
	HR_RightShoulder_ODST,
	HR_RightShoulder_UABaseSecurity,
	HR_RightShoulder_CQC,
	HR_RightShoulder_Operator,
	HR_RightShoulder_Commando,
	HR_RightShoulder_Grenadier,
	HR_RightShoulder_Sniper,
	HR_RightShoulder_MjolnirMarkV,
	HR_RightShoulder_Security,

	HR_Chest_Default,
	HR_Chest_HPHalo,
	HR_Chest_UACounterAssault,
	HR_Chest_TacticalLRP,
	HR_Chest_UAODST,
	HR_Chest_TacticalRecon,
	HR_Chest_CollarGrenadier,
	HR_Chest_TacticalPatrol,
	HR_Chest_CollarBreacher,
	HR_Chest_AssaultSapper,
	HR_Chest_AssaultCommando,
	HR_Chest_HPParaFoil,
	HR_Chest_CollarGrenadierUA,
	HR_Chest_UABaseSecurityW,
	HR_Chest_CollarBreacherR,
	HR_Chest_HPParaFoilR,
	HR_Chest_AssaultSapperR,

	HR_Wrist_Default,
	HR_Wrist_UABuckler,
	HR_Wrist_UABracer,
	HR_Wrist_TacticalTACPAD,
	HR_Wrist_TacticalUGPS,
	HR_Wrist_AssaultBreacher,

	HR_Utility_Default,
	HR_Utility_UACHOBHAM,
	HR_Utility_TacticalHardcase,
	HR_Utility_UANXRA,
	HR_Utility_TacticalTraumaKit,
	HR_Utility_TacticalSoftcase,

	HR_VisorColor_Default,
	HR_VisorColor_Silver,
	HR_VisorColor_Blue,
	HR_VisorColor_Black,
	HR_VisorColor_Gold,

	HR_KneeGuards_Default,
	HR_KneeGuards_FJPARA,
	HR_KneeGuards_Gungnir,
	HR_KneeGuards_Grenadier,

	HR_ArmorEffect_Default,
	HR_ArmorEffect_BirthdayParty,
	HR_ArmorEffect_HeartAttack,
	HR_ArmorEffect_Pestilence,
	HR_ArmorEffect_InclementWeather,
	HR_ArmorEffect_Flames,
	HR_ArmorEffect_BlueFlames,

	HR_FirefightVoice_NobleSix,
	HR_FirefightVoice_JorgeS052,
	HR_FirefightVoice_JunS266,
	HR_FirefightVoice_EmileS239,
	HR_FirefightVoice_KatS320,
	HR_FirefightVoice_AuntieDotAI,
	HR_FirefightVoice_CarterS259,
	HR_FirefightVoice_GYSGTStacker,
	HR_FirefightVoice_GYSGTBuck,
	HR_FirefightVoice_SGTMAJJohnson,
	HR_FirefightVoice_CortanaAI,
	HR_FirefightVoice_JohnS117,

	HR_Spartan_Male,
	HR_Spartan_Female,

	HR_Elite_Minor,
	HR_Elite_SpecOps,
	HR_Elite_Ranger,
	HR_Elite_Ultra,
	HR_Elite_Zealot,
	HR_Elite_General,
	HR_Elite_FieldMarshall,
	HR_Elite_Officer,

	HR_Color_Steel,
	HR_Color_Silver,
	HR_Color_White,
	HR_Color_Brown,
	HR_Color_Tan,
	HR_Color_Khaki,
	HR_Color_Sage,
	HR_Color_Olive,
	HR_Color_Drab,
	HR_Color_Forest,
	HR_Color_Green,
	HR_Color_SeaFoam,
	HR_Color_Teal,
	HR_Color_Aqua,
	HR_Color_Cyan,
	HR_Color_Blue,
	HR_Color_Cobalt,
	HR_Color_Ice,
	HR_Color_Violet,
	HR_Color_Orchid,
	HR_Color_Lavender,
	HR_Color_Maroon,
	HR_Color_Brick,
	HR_Color_Rose,
	HR_Color_Rust,
	HR_Color_Coral,
	HR_Color_Peach,
	HR_Color_Gold,
	HR_Color_Yellow,
	HR_Color_Pale,
	HR_Chest_UABaseSecurity,
	HR_Chest_UAMultiThreat,
	HR_Chest_UAMultiThreatW,
	HR_Species_Spartan,
	HR_Species_Elite,

	H1_Color_1,
	H1_Color_2,
	H1_Color_3,
	H1_Color_4,
	H1_Color_5,
	H1_Color_6,
	H1_Color_7,
	H1_Color_8,
	H1_Color_9,
	H1_Color_10,
	H1_Color_11,
	H1_Color_12,
	H1_Color_13,
	H1_Color_14,
	H1_Color_15,
	H1_Color_16,
	H1_Color_17,
	H1_Color_18,

	H2_Color_1,
	H2_Color_2,
	H2_Color_3,
	H2_Color_4,
	H2_Color_5,
	H2_Color_6,
	H2_Color_7,
	H2_Color_8,
	H2_Color_9,
	H2_Color_10,
	H2_Color_11,
	H2_Color_12,
	H2_Color_13,
	H2_Color_14,
	H2_Color_15,
	H2_Color_16,
	H2_Color_17,
	H2_Color_18,

	H2A_Color_1,
	H2A_Color_2,
	H2A_Color_3,
	H2A_Color_4,
	H2A_Color_5,
	H2A_Color_6,
	H2A_Color_7,
	H2A_Color_8,
	H2A_Color_9,
	H2A_Color_10,
	H2A_Color_11,
	H2A_Color_12,
	H2A_Color_13,
	H2A_Color_14,
	H2A_Color_15,
	H2A_Color_16,
	H2A_Color_17,
	H2A_Color_18,
	H2A_Color_19,
	H2A_Color_20,
	H2A_Color_21,
	H2A_Color_22,
	H2A_Color_23,
	H2A_Color_24,
	H2A_Color_25,
	H2A_Color_26,
	H2A_Color_27,
	H2A_Color_28,
	H2A_Color_29,

	H2A_ARMOR_ELITE1,
	H2A_ARMOR_ELITE2,
	H2A_ARMOR_ELITE3,

	H2A_ARMOR0_MARKVI,
	H2A_ARMOR1_CENTURION,
	H2A_ARMOR_SPARTAN3,

	H3_CHEST_BUNGIE,
	H3_CHEST_CQB,
	H3_CHEST_EOD,
	H3_CHEST_EVA,
	H3_CHEST_HAYABUSA,
	H3_CHEST_KATANA,
	H3_CHEST_MARK_VI,
	H3_CHEST_RECON,
	H3_CHEST_SCOUT,

	H3_HELMET_CQB,
	H3_HELMET_EOD,
	H3_HELMET_EVA,
	H3_HELMET_HAYABUSA,
	H3_HELMET_MARK_V,
	H3_HELMET_MARK_VI,
	H3_HELMET_RECON,
	H3_HELMET_ROGUE,
	H3_HELMET_SECURITY,
	H3_HELMET_ODST,
	H3_HELMET_SCOUT,

	H3_LEFT_SHOULDER_CQB,
	H3_LEFT_SHOULDER_EOD,
	H3_LEFT_SHOULDER_EVA,
	H3_LEFT_SHOULDER_HAYABUSA,
	H3_LEFT_SHOULDER_MARK_VI,
	H3_LEFT_SHOULDER_RECON,
	H3_LEFT_SHOULDER_SCOUT,
	H3_LEFT_SHOULDER_SECURITY,

	H3_RIGHT_SHOULDER_CQB,
	H3_RIGHT_SHOULDER_EOD,
	H3_RIGHT_SHOULDER_EVA,
	H3_RIGHT_SHOULDER_HAYABUSA,
	H3_RIGHT_SHOULDER_MARK_VI,
	H3_RIGHT_SHOULDER_RECON,
	H3_RIGHT_SHOULDER_SCOUT,
	H3_RIGHT_SHOULDER_SECURITY,

	H3_chest_ASCETIC,
	H3_helmet_ASCETIC,
	H3_leftShoulder_ASCETIC,
	H3_rightShoulder_ASCETIC,

	H3_chest_ASSAULT,
	H3_helmet_ASSAULT,
	H3_leftShoulder_ASSAULT,
	H3_rightShoulder_ASSAULT,

	H3_helmet_COMBAT,
	H3_leftShoulder_COMBAT,
	H3_rightShoulder_COMBAT,

	H3_chest_COMMANDO,
	H3_helmet_COMMANDO,
	H3_leftShoulder_COMMANDO,
	H3_rightShoulder_COMMANDO,

	H3_chest_FLIGHT,
	H3_helmet_FLIGHT,
	H3_leftShoulder_FLIGHT,
	H3_rightShoulder_FLIGHT,

	H3_COLOR0_STEEL,
	H3_COLOR1_SILVER,
	H3_COLOR2_WHITE,
	H3_COLOR3_RED,
	H3_COLOR4_MAUVE,
	H3_COLOR5_SALMON,
	H3_COLOR6_ORANGE,
	H3_COLOR7_CORAL,
	H3_COLOR8_PEACH,
	H3_COLOR9_GOLD,
	H3_COLOR10_YELLOW,
	H3_COLOR11_PALE,
	H3_COLOR12_SAGE,
	H3_COLOR13_GREEN,
	H3_COLOR14_OLIVE,
	H3_COLOR15_TEAL,
	H3_COLOR16_AQUA,
	H3_COLOR17_CYAN,
	H3_COLOR18_BLUE,
	H3_COLOR19_COBALT,
	H3_COLOR20_SAPHIRE,
	H3_COLOR21_VIOLET,
	H3_COLOR22_ORCHID,
	H3_COLOR23_LAVENDER,
	H3_COLOR24_CRIMSON,
	H3_COLOR25_RUBINE,
	H3_COLOR26_PINK,
	H3_COLOR27_BROWN,
	H3_COLOR28_TAN,
	H3_COLOR29_KHAKI,

	ODST_DUTCH,
	ODST_JOHNSON,
	ODST_MICKEY,
	ODST_RECON,
	ODST_ROMEO,
	ODST_SERGEANT,

	H4_Helmet_Default,
	H4_Helmet_Warrior,
	H4_Helmet_Scout,
	H4_Helmet_Soldier,
	H4_Helmet_Recon,
	H4_Helmet_Breather,
	H4_Helmet_EOD,
	H4_Helmet_Scientist,
	H4_Helmet_Demo,
	H4_Helmet_Orbital,
	H4_Helmet_AirAssault,
	H4_Helmet_Cyclops,
	H4_Helmet_ECM,
	H4_Helmet_Gungnir,
	H4_Helmet_Mongoose,
	H4_Helmet_Optimus,
	H4_Helmet_Triclops,
	H4_Helmet_Unicorn,
	H4_Helmet_Budokan,
	H4_Helmet_Utility,
	H4_Helmet_Pilot,
	H4_Helmet_Stealth,
	H4_Helmet_Commando,
	H4_Helmet_Ninja,
	H4_Helmet_Iron,
	H4_Helmet_Ranger,
	H4_Helmet_Boxhead,
	H4_Helmet_EVA,
	H4_Helmet_Engineer,
	H4_Helmet_Stalker,
	H4_Helmet_Rogue,
	H4_Helmet_Tracker,
	H4_Helmet_Mjolnir,
	H4_Helmet_Gungnir2,
	H4_Helmet_01,
	H4_Helmet_02,
	H4_Helmet_03,
	H4_Helmet_04,
	H4_Helmet_Gungnir_Alt,

	H4_Chest_Default,
	H4_Chest_Warrior,
	H4_Chest_Scout,
	H4_Chest_Soldier,
	H4_Chest_Recon,
	H4_Chest_Breather,
	H4_Chest_EOD,
	H4_Chest_Scientist,
	H4_Chest_Demo,
	H4_Chest_Orbital,
	H4_Chest_AirAssault,
	H4_Chest_Cyclops,
	H4_Chest_ECM,
	H4_Chest_Gungnir,
	H4_Chest_Mongoose,
	H4_Chest_Optimus,
	H4_Chest_Triclops,
	H4_Chest_Unicorn,
	H4_Chest_Budokan,
	H4_Chest_Utility,
	H4_Chest_Pilot,
	H4_Chest_Stealth,
	H4_Chest_Commando,
	H4_Chest_Ninja,
	H4_Chest_Iron,
	H4_Chest_Ranger,
	H4_Chest_Boxhead,
	H4_Chest_EVA,
	H4_Chest_Engineer,
	H4_Chest_Stalker,
	H4_Chest_Mjolnir,
	H4_Chest_Rogue,
	H4_Chest_Tracker,
	H4_Chest_Gungnir2,
	H4_Chest_Gungnir_Alt,

	H4_LeftShoulder_Default,
	H4_LeftShoulder_Warrior,
	H4_LeftShoulder_Scout,
	H4_LeftShoulder_Soldier,
	H4_LeftShoulder_Recon,
	H4_LeftShoulder_Breather,
	H4_LeftShoulder_EOD,
	H4_LeftShoulder_Scientist,
	H4_LeftShoulder_Demo,
	H4_LeftShoulder_Orbital,
	H4_LeftShoulder_AirAssault,
	H4_LeftShoulder_Cyclops,
	H4_LeftShoulder_ECM,
	H4_LeftShoulder_Gungnir,
	H4_LeftShoulder_Mongoose,
	H4_LeftShoulder_Optimus,
	H4_LeftShoulder_Triclops,
	H4_LeftShoulder_Unicorn,
	H4_LeftShoulder_Budokan,
	H4_LeftShoulder_Utility,
	H4_LeftShoulder_Pilot,
	H4_LeftShoulder_Stealth,
	H4_LeftShoulder_Commando,
	H4_LeftShoulder_Ninja,
	H4_LeftShoulder_Iron,
	H4_LeftShoulder_Ranger,
	H4_LeftShoulder_Boxhead,
	H4_LeftShoulder_EVA,
	H4_LeftShoulder_Engineer,
	H4_LeftShoulder_Stalker,
	H4_LeftShoulder_Mjolnir,
	H4_LeftShoulder_Rogue,
	H4_LeftShoulder_Tracker,
	H4_LeftShoulder_Gungnir2,
	H4_LeftShoulder_Gungnir_Alt,

	H4_RightShoulder_Default,
	H4_RightShoulder_Warrior,
	H4_RightShoulder_Scout,
	H4_RightShoulder_Soldier,
	H4_RightShoulder_Recon,
	H4_RightShoulder_Breather,
	H4_RightShoulder_EOD,
	H4_RightShoulder_Scientist,
	H4_RightShoulder_Demo,
	H4_RightShoulder_Orbital,
	H4_RightShoulder_AirAssault,
	H4_RightShoulder_Cyclops,
	H4_RightShoulder_ECM,
	H4_RightShoulder_Gungnir,
	H4_RightShoulder_Mongoose,
	H4_RightShoulder_Optimus,
	H4_RightShoulder_Triclops,
	H4_RightShoulder_Unicorn,
	H4_RightShoulder_Budokan,
	H4_RightShoulder_Utility,
	H4_RightShoulder_Pilot,
	H4_RightShoulder_Stealth,
	H4_RightShoulder_Commando,
	H4_RightShoulder_Ninja,
	H4_RightShoulder_Iron,
	H4_RightShoulder_Ranger,
	H4_RightShoulder_Boxhead,
	H4_RightShoulder_EVA,
	H4_RightShoulder_Engineer,
	H4_RightShoulder_Stalker,
	H4_RightShoulder_Mjolnir,
	H4_RightShoulder_Rogue,
	H4_RightShoulder_Tracker,
	H4_RightShoulder_Gungnir2,
	H4_RightShoulder_Gungnir_Alt,

	H4_Arms_Warrior,
	H4_Arms_Scout,
	H4_Arms_Orbital,
	H4_Arms_Unicorn,
	H4_Arms_Budokan,
	H4_Arms_Pilot,
	H4_Arms_Stealth,
	H4_Arms_Ninja,
	H4_Arms_Mjolnir,
	H4_Arms_Budokan_Alt,

	H4_Legs_Default,
	H4_Legs_Warrior,
	H4_Legs_Scout,
	H4_Legs_ECM,
	H4_Legs_Unicorn,
	H4_Legs_Utility,
	H4_Legs_Stealth,
	H4_Legs_Ninja,
	H4_Legs_Mjolnir,
	H4_Legs_Utility_Alt,

	H4_Male,
	H4_Female,

	H4_Color0_Steel,
	H4_Color1_Silver,
	H4_Color2_White,
	H4_Color3_Brown,
	H4_Color4_Tan,
	H4_Color5_Khaki,
	H4_Color6_Sage,
	H4_Color7_Olive,
	H4_Color8_Drab,
	H4_Color9_Forest,
	H4_Color10_Green,
	H4_Color11_SeaFoam,
	H4_Color12_Teal,
	H4_Color13_Aqua,
	H4_Color14_Cyan,
	H4_Color15_Blue,
	H4_Color16_Cobalt,
	H4_Color17_Ice,
	H4_Color18_Violet,
	H4_Color19_Orchid,
	H4_Color20_Lavender,
	H4_Color21_Maroon,
	H4_Color22_Brick,
	H4_Color23_Rose,
	H4_Color24_Rust,
	H4_Color25_Coral,
	H4_Color26_Peach,
	H4_Color27_Gold,
	H4_Color28_Yellow,

	H1S2_WEAPONSKIN_ASSAULTRIFLEGOLDEN,
	H1S2_WEAPONSKIN_ASSAULTRIFLEDESERT,

	H1S2_VISORCOLOR_BRONZE,
	H1S2_VISORCOLOR_DARKBLUE,
	H1S2_VISORCOLOR_DARKGREEN,
	H1S2_VISORCOLOR_DARKORANGE,
	H1S2_VISORCOLOR_DARKPURPLE,
	H1S2_VISORCOLOR_DARKRED,
	H1S2_VISORCOLOR_DARKYELLOW,
	H1S2_VISORCOLOR_GREEN,
	H1S2_VISORCOLOR_GROOVY,
	H1S2_VISORCOLOR_ONYX,
	H1S2_VISORCOLOR_ORANGE,
	H1S2_VISORCOLOR_PASTELBLUE,
	H1S2_VISORCOLOR_PASTELGREEN,
	H1S2_VISORCOLOR_PASTELORANGE,
	H1S2_VISORCOLOR_PASTELPURPLE,
	H1S2_VISORCOLOR_PASTELRED,
	H1S2_VISORCOLOR_PASTELYELLOW,
	H1S2_VISORCOLOR_PEARLBLUE,
	H1S2_VISORCOLOR_PEARLGREEN,
	H1S2_VISORCOLOR_PEARLORANGE,
	H1S2_VISORCOLOR_PEARLPURPLE,
	H1S2_VISORCOLOR_PEARLRED,
	H1S2_VISORCOLOR_PEARLYELLOW,
	H1S2_VISORCOLOR_PLATINUM,
	H1S2_VISORCOLOR_PURPLE,
	H1S2_VISORCOLOR_RED,
	H1S2_VISORCOLOR_SILVER,
	H1S2_VISORCOLOR_SPECTRUM,
	H1S2_VISORCOLOR_YELLOW,

	k_customization_item_count,
	k_customization_item_none = -1
};

enum class e_customization_item_v3 : long
{
	HR_Helmet_MarkVB_Base,
	HR_Helmet_MarkVB_UA,
	HR_Helmet_MarkVB_UAHUL,
	HR_Helmet_CQC_Base,
	HR_Helmet_CQC_CBRN,
	HR_Helmet_CQC_UAHUL,
	HR_Helmet_ODST_Base,
	HR_Helmet_ODST_UACNM,
	HR_Helmet_ODST_CBRNHUL,
	HR_Helmet_HAZOP_Base,
	HR_Helmet_HAZOP_CBRNHUL,
	HR_Helmet_HAZOP_CNMI,
	HR_Helmet_EOD_Base,
	HR_Helmet_EOD_CNM,
	HR_Helmet_EOD_UAHUL,
	HR_Helmet_Operator_Base,
	HR_Helmet_Operator_UAHUL,
	HR_Helmet_Operator_CNM,
	HR_Helmet_Grenadier_Base,
	HR_Helmet_Grenadier_UA,
	HR_Helmet_Grenadier_UAFC,
	HR_Helmet_AirAssault_Base,
	HR_Helmet_AirAssault_UACNM,
	HR_Helmet_AirAssault_FCI,
	HR_Helmet_Scout_Base,
	HR_Helmet_Scout_HURS,
	HR_Helmet_Scout_CBRNCNM,
	HR_Helmet_EVA_Base,
	HR_Helmet_EVA_CNM,
	HR_Helmet_EVA_UAHUL3,
	HR_Helmet_JFO_Base,
	HR_Helmet_JFO_HULI,
	HR_Helmet_JFO_UA,
	HR_Helmet_Commando_Base,
	HR_Helmet_Commando_CBRNCNM,
	HR_Helmet_Commando_UAFCI2,
	HR_Helmet_EVAC_Base,
	HR_Helmet_EVAC_CNM,
	HR_Helmet_EVAC_UAHUL3,
	HR_Helmet_MjolnirMKV_Base,
	HR_Helmet_MjolnirMKV_CNM,
	HR_Helmet_MjolnirMKV_UA,
	HR_Helmet_Pilot_Base,
	HR_Helmet_Pilot_HUL3,
	HR_Helmet_Pilot_UAHUL3,
	HR_Helmet_Pilot_Haunted,
	HR_Helmet_Recon_Base,
	HR_Helmet_Recon_HUL,
	HR_Helmet_Recon_UAHUL3,
	HR_Helmet_MjolnirMKVI_Base,
	HR_Helmet_MjolnirMKVI_FCI2,
	HR_Helmet_MjolnirMKVI_UAHULI,
	HR_Helmet_Gungnir_Base,
	HR_Helmet_Gungnir_HURS,
	HR_Helmet_Gungnir_CBRN,
	HR_Helmet_Security_Base,
	HR_Helmet_Security_UAHUL,
	HR_Helmet_Security_CBRNCNM,
	HR_Helmet_MilitaryPolice_Base,
	HR_Helmet_MilitaryPolice_CBRNHURS,
	HR_Helmet_MilitaryPolice_HURSCNM,
	HR_Helmet_CQB_Base,
	HR_Helmet_CQB_HURSCNM,
	HR_Helmet_CQB_UAHUL,

	HR_LeftShoulder_Default,
	HR_LeftShoulder_FJPARA,
	HR_LeftShoulder_HAZOP,
	HR_LeftShoulder_JFO,
	HR_LeftShoulder_Recon,
	HR_LeftShoulder_UAMultiThreat,
	HR_LeftShoulder_Jumpjet,
	HR_LeftShoulder_EVA,
	HR_LeftShoulder_Gungnir,
	HR_LeftShoulder_ODST,
	HR_LeftShoulder_UABaseSecurity,
	HR_LeftShoulder_CQC,
	HR_LeftShoulder_Operator,
	HR_LeftShoulder_Commando,
	HR_LeftShoulder_Grenadier,
	HR_LeftShoulder_Sniper,
	HR_LeftShoulder_MjolnirMarkV,
	HR_LeftShoulder_Security,

	HR_RightShoulder_Default,
	HR_RightShoulder_FJPARA,
	HR_RightShoulder_HAZOP,
	HR_RightShoulder_JFO,
	HR_RightShoulder_Recon,
	HR_RightShoulder_UAMultiThreat,
	HR_RightShoulder_Jumpjet,
	HR_RightShoulder_EVA,
	HR_RightShoulder_Gungnir,
	HR_RightShoulder_ODST,
	HR_RightShoulder_UABaseSecurity,
	HR_RightShoulder_CQC,
	HR_RightShoulder_Operator,
	HR_RightShoulder_Commando,
	HR_RightShoulder_Grenadier,
	HR_RightShoulder_Sniper,
	HR_RightShoulder_MjolnirMarkV,
	HR_RightShoulder_Security,

	HR_Chest_Default,
	HR_Chest_HPHalo,
	HR_Chest_UACounterAssault,
	HR_Chest_TacticalLRP,
	HR_Chest_UAODST,
	HR_Chest_TacticalRecon,
	HR_Chest_CollarGrenadier,
	HR_Chest_TacticalPatrol,
	HR_Chest_CollarBreacher,
	HR_Chest_AssaultSapper,
	HR_Chest_AssaultCommando,
	HR_Chest_HPParaFoil,
	HR_Chest_CollarGrenadierUA,
	HR_Chest_UABaseSecurityW,
	HR_Chest_CollarBreacherR,
	HR_Chest_HPParaFoilR,
	HR_Chest_AssaultSapperR,

	HR_Wrist_Default,
	HR_Wrist_UABuckler,
	HR_Wrist_UABracer,
	HR_Wrist_TacticalTACPAD,
	HR_Wrist_TacticalUGPS,
	HR_Wrist_AssaultBreacher,

	HR_Utility_Default,
	HR_Utility_UACHOBHAM,
	HR_Utility_TacticalHardcase,
	HR_Utility_UANXRA,
	HR_Utility_TacticalTraumaKit,
	HR_Utility_TacticalSoftcase,

	HR_VisorColor_Default,
	HR_VisorColor_Silver,
	HR_VisorColor_Blue,
	HR_VisorColor_Black,
	HR_VisorColor_Gold,

	HR_KneeGuards_Default,
	HR_KneeGuards_FJPARA,
	HR_KneeGuards_Gungnir,
	HR_KneeGuards_Grenadier,

	HR_ArmorEffect_Default,
	HR_ArmorEffect_BirthdayParty,
	HR_ArmorEffect_HeartAttack,
	HR_ArmorEffect_Pestilence,
	HR_ArmorEffect_InclementWeather,
	HR_ArmorEffect_Flames,
	HR_ArmorEffect_BlueFlames,

	HR_FirefightVoice_NobleSix,
	HR_FirefightVoice_JorgeS052,
	HR_FirefightVoice_JunS266,
	HR_FirefightVoice_EmileS239,
	HR_FirefightVoice_KatS320,
	HR_FirefightVoice_AuntieDotAI,
	HR_FirefightVoice_CarterS259,
	HR_FirefightVoice_GYSGTStacker,
	HR_FirefightVoice_GYSGTBuck,
	HR_FirefightVoice_SGTMAJJohnson,
	HR_FirefightVoice_CortanaAI,
	HR_FirefightVoice_JohnS117,

	HR_Spartan_Male,
	HR_Spartan_Female,

	HR_Elite_Minor,
	HR_Elite_SpecOps,
	HR_Elite_Ranger,
	HR_Elite_Ultra,
	HR_Elite_Zealot,
	HR_Elite_General,
	HR_Elite_FieldMarshall,
	HR_Elite_Officer,

	HR_Color_Steel,
	HR_Color_Silver,
	HR_Color_White,
	HR_Color_Brown,
	HR_Color_Tan,
	HR_Color_Khaki,
	HR_Color_Sage,
	HR_Color_Olive,
	HR_Color_Drab,
	HR_Color_Forest,
	HR_Color_Green,
	HR_Color_SeaFoam,
	HR_Color_Teal,
	HR_Color_Aqua,
	HR_Color_Cyan,
	HR_Color_Blue,
	HR_Color_Cobalt,
	HR_Color_Ice,
	HR_Color_Violet,
	HR_Color_Orchid,
	HR_Color_Lavender,
	HR_Color_Maroon,
	HR_Color_Brick,
	HR_Color_Rose,
	HR_Color_Rust,
	HR_Color_Coral,
	HR_Color_Peach,
	HR_Color_Gold,
	HR_Color_Yellow,
	HR_Color_Pale,
	HR_Chest_UABaseSecurity,
	HR_Chest_UAMultiThreat,
	HR_Chest_UAMultiThreatW,

	HR_Species_Spartan,
	HR_Species_Elite,

	H1_Color_1,
	H1_Color_2,
	H1_Color_3,
	H1_Color_4,
	H1_Color_5,
	H1_Color_6,
	H1_Color_7,
	H1_Color_8,
	H1_Color_9,
	H1_Color_10,
	H1_Color_11,
	H1_Color_12,
	H1_Color_13,
	H1_Color_14,
	H1_Color_15,
	H1_Color_16,
	H1_Color_17,
	H1_Color_18,

	H1S2_WS_PISTOL_DEFAULT,
	H1S2_WS_PISTOL_GOLDEN,
	H1S2_WS_PISTOL_WOODLAND,
	H1S2_WS_PISTOL_DESERT,
	H1S2_WS_PISTOL_GREATJOURNEY,
	H1S2_WS_PISTOL_BLACKCHERRY,
	H1S2_WS_PISTOL_HAZARDPAY,
	H1S2_WS_PISTOL_TOYSOLDIER,
	H1S2_WS_ASSAULTRIFLE_DEFAULT,
	H1S2_WS_ASSAULTRIFLE_GOLDEN,
	H1S2_WS_ASSAULTRIFLE_WOODLAND,
	H1S2_WS_ASSAULTRIFLE_DESERT,
	H1S2_WS_ASSAULTRIFLE_GREATJOURNEY,
	H1S2_WS_ASSAULTRIFLE_CORROSION,
	H1S2_WS_ASSAULTRIFLE_SQUIRT,
	H1S2_WS_ASSAULTRIFLE_LUCKYSHOT,
	H1S2_WS_PLASMAPISTOL_DEFAULT,
	H1S2_WS_PLASMAPISTOL_ULTRA,
	H1S2_WS_PLASMAPISTOL_BRUTAL,
	H1S2_WS_PLASMAPISTOL_SCHISM,
	H1S2_WS_PLASMAPISTOL_ZEALOT,
	H1S2_WS_PLASMARIFLE_DEFAULT,
	H1S2_WS_PLASMARIFLE_ULTRA,
	H1S2_WS_PLASMARIFLE_BRUTAL,
	H1S2_WS_PLASMARIFLE_SCHISM,
	H1S2_WS_PLASMARIFLE_ZEALOT,
	H1S2_WS_ROCKETLAUNCHER_DEFAULT,
	H1S2_WS_ROCKETLAUNCHER_HUNTERSBLOOD,
	H1S2_WS_ROCKETLAUNCHER_CORROSION,
	H1S2_WS_ROCKETLAUNCHER_DESERT,
	H1S2_WS_SNIPERRIFLE_DEFAULT,
	H1S2_WS_SNIPERRIFLE_GOLDEN,
	H1S2_WS_SNIPERRIFLE_WOODLAND,
	H1S2_WS_SNIPERRIFLE_DESERT,
	H1S2_WS_SNIPERRIFLE_GREATJOURNEY,
	H1S2_WS_SNIPERRIFLE_AVALANCHE,
	H1S2_WS_SHOTGUN_DEFAULT,
	H1S2_WS_SHOTGUN_GOLDEN,
	H1S2_WS_SHOTGUN_WOODLAND,
	H1S2_WS_SHOTGUN_DESERT,
	H1S2_WS_SHOTGUN_GREATJOURNEY,
	H1S2_WS_SHOTGUN_HUNTERSBLOOD,
	H1S2_WS_NEEDLER_DEFAULT,
	H1S2_WS_NEEDLER_ULTRA,
	H1S2_WS_NEEDLER_BRUTAL,
	H1S2_WS_NEEDLER_SCHISM,
	H1S2_WS_NEEDLER_ZEALOT,
	H1S2_WS_FLAMETHROWER_DEFAULT,
	H1S2_WS_FLAMETHROWER_DEARJOHN,
	H1S2_WS_FLAMETHROWER_WHITEHOT,
	H1S2_WS_FLAMETHROWER_HOTPEPPER,
	H1S2_WS_FUELRODGUN_DEFAULT,
	H1S2_WS_FUELRODGUN_ULTRA,
	H1S2_WS_FUELRODGUN_BRUTAL,
	H1S2_WS_FUELRODGUN_HERETIC,
	H1S2_WS_FUELRODGUN_ZEALOT,
	H1S2_VS_WARTHOG_DEFAULT,
	H1S2_VS_WARTHOG_HOTROD,
	H1S2_VS_WARTHOG_PARKRANGER,
	H1S2_VS_WARTHOG_RALLYHOG,
	H1S2_VS_ROCKETWARTHOG_DEFAULT,
	H1S2_VS_ROCKETWARTHOG_SUPERSTAR,
	H1S2_VS_ROCKETWARTHOG_SHARK,
	H1S2_VS_ROCKETWARTHOG_CLEVERGIRL,
	H1S2_VS_GHOST_DEFAULT,
	H1S2_VS_GHOST_BRUTAL,
	H1S2_VS_GHOST_SCHISM,
	H1S2_VS_GHOST_ZEALOT,
	H1S2_VS_GHOST_ULTRA,
	H1S2_VS_SCORPION_DEFAULT,
	H1S2_VS_SCORPION_BENGAL,
	H1S2_VS_SCORPION_GRIMREAPER,
	H1S2_VS_SCORPION_ARCTIC,
	H1S2_VS_SCORPION_THEPACKAGE,
	H1S2_VS_BANSHEE_DEFAULT,
	H1S2_VS_BANSHEE_BRUTAL,
	H1S2_VS_BANSHEE_SCHISM,
	H1S2_VS_BANSHEE_ZEALOT,
	H1S2_VS_BANSHEE_ULTRA,

	H1S2_VISOR_DEFAULT,
	H1S2_VISOR_BRONZE,
	H1S2_VISOR_SILVER,
	H1S2_VISOR_PLATINUM,
	H1S2_VISOR_OBSIDIAN,
	H1S2_VISOR_TRIPPY,
	H1S2_VISOR_RAINBOW,
	H1S2_VISOR_PURPLE_PASTEL,
	H1S2_VISOR_BLUE_PASTEL,
	H1S2_VISOR_GREEN_PASTEL,
	H1S2_VISOR_YELLOW_PASTEL,
	H1S2_VISOR_ORANGE_PASTEL,
	H1S2_VISOR_RED_PASTEL,
	H1S2_VISOR_DARK_PURPLE,
	H1S2_VISOR_DARK_BLUE,
	H1S2_VISOR_DARK_GREEN,
	H1S2_VISOR_DARK_YELLOW,
	H1S2_VISOR_DARK_ORANGE,
	H1S2_VISOR_DARK_RED,
	H1S2_VISOR_PURPLE,
	H1S2_VISOR_BLUE,
	H1S2_VISOR_GREEN,
	H1S2_VISOR_YELLOW,
	H1S2_VISOR_ORANGE,
	H1S2_VISOR_RED,
	H1S2_VISOR_PEARL_PURPLE,
	H1S2_VISOR_PEARL_BLUE,
	H1S2_VISOR_PEARL_GREEN,
	H1S2_VISOR_PEARL_YELLOW,
	H1S2_VISOR_PEARL_ORANGE,
	H1S2_VISOR_PEARL_RED,

	REFLECTION_BRUTAL,
	REFLECTION_SCHISM,
	REFLECTION_ULTRA,
	REFLECTION_ZEALOT,

	H1S2_WS_PISTOL_DEFAULT_MULTIPURPOSE,
	H1S2_WS_PISTOL_GOLDEN_MULTIPURPOSE,
	H1S2_WS_PISTOL_WOODLAND_MULTIPURPOSE,
	H1S2_WS_PISTOL_DESERT_MULTIPURPOSE,
	H1S2_WS_PISTOL_GREATJOURNEY_MULTIPURPOS,
	H1S2_WS_PISTOL_BLACKCHERRY_MULTIPURPOSE,
	H1S2_WS_PISTOL_HAZARDPAY_MULTIPURPOSE,
	H1S2_WS_PISTOL_TOYSOLDIER_MULTIPURPOSE,

	H1S2_VS_SCORPION_BENGAL_MULTIPURPOSE,
	H1S2_VS_SCORPION_GRIMREAPER_MULTIPURPOS,
	H1S2_VS_SCORPION_ARCTIC_MULTIPURPOSE,
	H1S2_VS_SCORPION_THEPACKAGE_MULTIPURPOS,

	H1S2_WS_FUELRODGUN_FP_DEFAULT,
	H1S2_WS_FUELRODGUN_FP_ULTRA,
	H1S2_WS_FUELRODGUN_FP_BRUTAL,
	H1S2_WS_FUELRODGUN_FP_HERETIC,
	H1S2_WS_FUELRODGUN_FP_ZEALOT,

	H1S2_VS_WARTHOG_TIRES_HOTROD,
	H1S2_VS_WARTHOG_TIRES_PARKRANGER,
	H1S2_VS_WARTHOG_TIRES_RALLYHOG,

	H1S2_VS_ROCKETWARTHOG_TIRES_SUPERSTAR,
	H1S2_VS_ROCKETWARTHOG_TIRES_SHARK,
	H1S2_VS_ROCKETWARTHOG_TIRES_CLEVERGIRL,

	H2_Color_1,
	H2_Color_2,
	H2_Color_3,
	H2_Color_4,
	H2_Color_5,
	H2_Color_6,
	H2_Color_7,
	H2_Color_8,
	H2_Color_9,
	H2_Color_10,
	H2_Color_11,
	H2_Color_12,
	H2_Color_13,
	H2_Color_14,
	H2_Color_15,
	H2_Color_16,
	H2_Color_17,
	H2_Color_18,

	H2A_Color_1,
	H2A_Color_2,
	H2A_Color_3,
	H2A_Color_4,
	H2A_Color_5,
	H2A_Color_6,
	H2A_Color_7,
	H2A_Color_8,
	H2A_Color_9,
	H2A_Color_10,
	H2A_Color_11,
	H2A_Color_12,
	H2A_Color_13,
	H2A_Color_14,
	H2A_Color_15,
	H2A_Color_16,
	H2A_Color_17,
	H2A_Color_18,
	H2A_Color_19,
	H2A_Color_20,
	H2A_Color_21,
	H2A_Color_22,
	H2A_Color_23,
	H2A_Color_24,
	H2A_Color_25,
	H2A_Color_26,
	H2A_Color_27,
	H2A_Color_28,
	H2A_Color_29,

	H2A_ARMOR_ELITE1,
	H2A_ARMOR_ELITE2,
	H2A_ARMOR_ELITE3,

	H2A_ARMOR0_MARKVI,
	H2A_ARMOR1_CENTURION,
	H2A_ARMOR_SPARTAN3,

	Voice_Female,
	Voice_Male,

	H3_CHEST_BUNGIE,
	H3_CHEST_CQB,
	H3_CHEST_EOD,
	H3_CHEST_EVA,
	H3_CHEST_HAYABUSA,
	H3_CHEST_KATANA,
	H3_CHEST_MARK_VI,
	H3_CHEST_RECON,
	H3_CHEST_SCOUT,

	H3_HELMET_CQB,
	H3_HELMET_EOD,
	H3_HELMET_EVA,
	H3_HELMET_HAYABUSA,
	H3_HELMET_MARK_V,
	H3_HELMET_MARK_VI,
	H3_HELMET_RECON,
	H3_HELMET_ROGUE,
	H3_HELMET_SECURITY,
	H3_HELMET_ODST,
	H3_HELMET_SCOUT,

	H3_LEFTSHOULDER_CQB,
	H3_LEFTSHOULDER_EOD,
	H3_LEFTSHOULDER_EVA,
	H3_LEFTSHOULDER_HAYABUSA,
	H3_LEFTSHOULDER_MARK_VI,
	H3_LEFTSHOULDER_RECON,
	H3_LEFTSHOULDER_SCOUT,
	H3_LEFTSHOULDER_SECURITY,

	H3_RIGHTSHOULDER_CQB,
	H3_RIGHTSHOULDER_EOD,
	H3_RIGHTSHOULDER_EVA,
	H3_RIGHTSHOULDER_HAYABUSA,
	H3_RIGHTSHOULDER_MARK_VI,
	H3_RIGHTSHOULDER_RECON,
	H3_RIGHTSHOULDER_SCOUT,
	H3_RIGHTSHOULDER_SECURITY,

	H3_chest_ASCETIC,
	H3_helmet_ASCETIC,
	H3_leftShoulder_ASCETIC,
	H3_rightShoulder_ASCETIC,

	H3_chest_ASSAULT,
	H3_helmet_ASSAULT,
	H3_leftShoulder_ASSAULT,
	H3_rightShoulder_ASSAULT,

	H3_helmet_COMBAT,
	H3_leftShoulder_COMBAT,
	H3_rightShoulder_COMBAT,

	H3_chest_COMMANDO,
	H3_helmet_COMMANDO,
	H3_leftShoulder_COMMANDO,
	H3_rightShoulder_COMMANDO,

	H3_chest_FLIGHT,
	H3_helmet_FLIGHT,
	H3_leftShoulder_FLIGHT,
	H3_rightShoulder_FLIGHT,

	H3_COLOR0_STEEL,
	H3_COLOR1_SILVER,
	H3_COLOR2_WHITE,
	H3_COLOR3_RED,
	H3_COLOR4_MAUVE,
	H3_COLOR5_SALMON,
	H3_COLOR6_ORANGE,
	H3_COLOR7_CORAL,
	H3_COLOR8_PEACH,
	H3_COLOR9_GOLD,
	H3_COLOR10_YELLOW,
	H3_COLOR11_PALE,
	H3_COLOR12_SAGE,
	H3_COLOR13_GREEN,
	H3_COLOR14_OLIVE,
	H3_COLOR15_TEAL,
	H3_COLOR16_AQUA,
	H3_COLOR17_CYAN,
	H3_COLOR18_BLUE,
	H3_COLOR19_COBALT,
	H3_COLOR20_SAPHIRE,
	H3_COLOR21_VIOLET,
	H3_COLOR22_ORCHID,
	H3_COLOR23_LAVENDER,
	H3_COLOR24_CRIMSON,
	H3_COLOR25_RUBINE,
	H3_COLOR26_PINK,
	H3_COLOR27_BROWN,
	H3_COLOR28_TAN,
	H3_COLOR29_KHAKI,

	ODST_DUTCH,
	ODST_JOHNSON,
	ODST_MICKEY,
	ODST_RECON,
	ODST_ROMEO,
	ODST_SERGEANT,

	H4_Helmet_Default,
	H4_Helmet_Warrior,
	H4_Helmet_Scout,
	H4_Helmet_Soldier,
	H4_Helmet_Recon,
	H4_Helmet_Breather,
	H4_Helmet_EOD,
	H4_Helmet_Scientist,
	H4_Helmet_Demo,
	H4_Helmet_Orbital,
	H4_Helmet_AirAssault,
	H4_Helmet_Cyclops,
	H4_Helmet_ECM,
	H4_Helmet_Gungnir,
	H4_Helmet_Mongoose,
	H4_Helmet_Optimus,
	H4_Helmet_Triclops,
	H4_Helmet_Unicorn,
	H4_Helmet_Budokan,
	H4_Helmet_Utility,
	H4_Helmet_Pilot,
	H4_Helmet_Stealth,
	H4_Helmet_Commando,
	H4_Helmet_Ninja,
	H4_Helmet_Iron,
	H4_Helmet_Ranger,
	H4_Helmet_Boxhead,
	H4_Helmet_EVA,
	H4_Helmet_Engineer,
	H4_Helmet_Stalker,
	H4_Helmet_Rogue,
	H4_Helmet_Tracker,
	H4_Helmet_Mjolnir,
	H4_Helmet_Gungnir2,
	H4_Helmet_01,
	H4_Helmet_02,
	H4_Helmet_03,
	H4_Helmet_04,

	H4_Helmet_Gungnir_Alt,
	H4_Chest_Default,
	H4_Chest_Warrior,
	H4_Chest_Scout,
	H4_Chest_Soldier,
	H4_Chest_Recon,
	H4_Chest_Breather,
	H4_Chest_EOD,
	H4_Chest_Scientist,
	H4_Chest_Demo,
	H4_Chest_Orbital,
	H4_Chest_AirAssault,
	H4_Chest_Cyclops,
	H4_Chest_ECM,
	H4_Chest_Gungnir,
	H4_Chest_Mongoose,
	H4_Chest_Optimus,
	H4_Chest_Triclops,
	H4_Chest_Unicorn,
	H4_Chest_Budokan,
	H4_Chest_Utility,
	H4_Chest_Pilot,
	H4_Chest_Stealth,
	H4_Chest_Commando,
	H4_Chest_Ninja,
	H4_Chest_Iron,
	H4_Chest_Ranger,
	H4_Chest_Boxhead,
	H4_Chest_EVA,
	H4_Chest_Engineer,
	H4_Chest_Stalker,
	H4_Chest_Mjolnir,
	H4_Chest_Rogue,
	H4_Chest_Tracker,
	H4_Chest_Gungnir2,
	H4_Chest_Gungnir_Alt,

	H4_LeftShoulder_Default,
	H4_LeftShoulder_Warrior,
	H4_LeftShoulder_Scout,
	H4_LeftShoulder_Soldier,
	H4_LeftShoulder_Recon,
	H4_LeftShoulder_Breather,
	H4_LeftShoulder_EOD,
	H4_LeftShoulder_Scientist,
	H4_LeftShoulder_Demo,
	H4_LeftShoulder_Orbital,
	H4_LeftShoulder_AirAssault,
	H4_LeftShoulder_Cyclops,
	H4_LeftShoulder_ECM,
	H4_LeftShoulder_Gungnir,
	H4_LeftShoulder_Mongoose,
	H4_LeftShoulder_Optimus,
	H4_LeftShoulder_Triclops,
	H4_LeftShoulder_Unicorn,
	H4_LeftShoulder_Budokan,
	H4_LeftShoulder_Utility,
	H4_LeftShoulder_Pilot,
	H4_LeftShoulder_Stealth,
	H4_LeftShoulder_Commando,
	H4_LeftShoulder_Ninja,
	H4_LeftShoulder_Iron,
	H4_LeftShoulder_Ranger,
	H4_LeftShoulder_Boxhead,
	H4_LeftShoulder_EVA,
	H4_LeftShoulder_Engineer,
	H4_LeftShoulder_Stalker,
	H4_LeftShoulder_Mjolnir,
	H4_LeftShoulder_Rogue,
	H4_LeftShoulder_Tracker,
	H4_LeftShoulder_Gungnir2,
	H4_LeftShoulder_Gungnir_Alt,

	H4_RightShoulder_Default,
	H4_RightShoulder_Warrior,
	H4_RightShoulder_Scout,
	H4_RightShoulder_Soldier,
	H4_RightShoulder_Recon,
	H4_RightShoulder_Breather,
	H4_RightShoulder_EOD,
	H4_RightShoulder_Scientist,
	H4_RightShoulder_Demo,
	H4_RightShoulder_Orbital,
	H4_RightShoulder_AirAssault,
	H4_RightShoulder_Cyclops,
	H4_RightShoulder_ECM,
	H4_RightShoulder_Gungnir,
	H4_RightShoulder_Mongoose,
	H4_RightShoulder_Optimus,
	H4_RightShoulder_Triclops,
	H4_RightShoulder_Unicorn,
	H4_RightShoulder_Budokan,
	H4_RightShoulder_Utility,
	H4_RightShoulder_Pilot,
	H4_RightShoulder_Stealth,
	H4_RightShoulder_Commando,
	H4_RightShoulder_Ninja,
	H4_RightShoulder_Iron,
	H4_RightShoulder_Ranger,
	H4_RightShoulder_Boxhead,
	H4_RightShoulder_EVA,
	H4_RightShoulder_Engineer,
	H4_RightShoulder_Stalker,
	H4_RightShoulder_Mjolnir,
	H4_RightShoulder_Rogue,
	H4_RightShoulder_Tracker,
	H4_RightShoulder_Gungnir2,
	H4_RightShoulder_Gungnir_Alt,

	H4_Arms_Warrior,
	H4_Arms_Scout,
	H4_Arms_Orbital,
	H4_Arms_Unicorn,
	H4_Arms_Budokan,
	H4_Arms_Pilot,
	H4_Arms_Stealth,
	H4_Arms_Ninja,
	H4_Arms_Mjolnir,
	H4_Arms_Budokan_Alt,
	H4_Legs_Default,
	H4_Legs_Warrior,
	H4_Legs_Scout,
	H4_Legs_ECM,
	H4_Legs_Unicorn,
	H4_Legs_Utility,
	H4_Legs_Stealth,
	H4_Legs_Ninja,
	H4_Legs_Mjolnir,
	H4_Legs_Utility_Alt,

	H4_Male,
	H4_Female,

	H4_Color0_Steel,
	H4_Color1_Silver,
	H4_Color2_White,
	H4_Color3_Brown,
	H4_Color4_Tan,
	H4_Color5_Khaki,
	H4_Color6_Sage,
	H4_Color7_Olive,
	H4_Color8_Drab,
	H4_Color9_Forest,
	H4_Color10_Green,
	H4_Color11_SeaFoam,
	H4_Color12_Teal,
	H4_Color13_Aqua,
	H4_Color14_Cyan,
	H4_Color15_Blue,
	H4_Color16_Cobalt,
	H4_Color17_Ice,
	H4_Color18_Violet,
	H4_Color19_Orchid,
	H4_Color20_Lavender,
	H4_Color21_Maroon,
	H4_Color22_Brick,
	H4_Color23_Rose,
	H4_Color24_Rust,
	H4_Color25_Coral,
	H4_Color26_Peach,
	H4_Color27_Gold,
	H4_Color28_Yellow,

	k_customization_item_count,
	k_customization_item_none = -1
};

struct s_user_skin
{
	long ObjectID;
	long SkinID; // e_customization_item_v2
};

struct s_loadout_slot
{
	long TacticalPackageIndex;
	long SupportUpgradeIndex;
	long PrimaryWeaponIndex;
	long SecondaryWeaponIndex;
	long PrimaryWeaponVariantIndex;
	long SecondaryWeaponVariantIndex;
	long EquipmentIndex;
	long GrenadeIndex;
	wchar_t Name[13];
};

struct s_custom_key_mapping
{
	long AbstractButton;
	long VirtualKeyCodes[5];
};

struct s_weapon_display_offset
{
	float Y;
	float Z;
};

enum e_abstract_button : long
{
	_abstract_button_jump_v1,
	_abstract_button_switch_grenade_v1,
	_abstract_button_context_primary_v1,
	_abstract_button_reload_v1,
	_abstract_button_switch_weapon_v1,
	_abstract_button_melee_v1,
	_abstract_button_flashlight_v1,
	_abstract_button_throw_grenade_v1,
	_abstract_button_fire_v1,
	_abstract_button_crouch_v1,
	_abstract_button_zoom_v1,
	_abstract_button_zoom_in_v1,
	_abstract_button_zoom_out_v1,
	_abstract_button_exchange_weapon_v1,
	_abstract_button_trick_v1,
	_abstract_button_brake_v1,
	_abstract_button_ebrake_v1,
	_abstract_button_sprint_v1,
	_abstract_button_banshee_bomb_v1,
	_abstract_button_forward_v1,
	_abstract_button_backward_v1,
	_abstract_button_left_v1,
	_abstract_button_right_v1,
	_abstract_button_lean_left_v1,
	_abstract_button_lean_right_v1,
	_abstract_button_start_v1,
	_abstract_button_back_v1,
	_abstract_button_show_scores_v1,
	_abstract_button_accept_v1,
	_abstract_button_cancel_v1,
	_abstract_button_primary_vehicle_trick_v1,
	_abstract_button_secondary_vehicle_trick_v1,
	_abstract_button_magnify_zoom_v1,
	_abstract_button_equipment_v1,

	_abstract_button_fire_secondary_v2,

	_abstract_button_lift_editor_v3,
	_abstract_button_drop_editor_v3,
	_abstract_button_grab_object_editor_v3,
	_abstract_button_boost_editor_v3,
	_abstract_button_crouch_editor_v3,
	_abstract_button_delete_object_editor_v3,
	_abstract_button_create_object_editor_v3,
	_abstract_button_open_tool_menu_editor_v3,
	_abstract_button_switch_player_mode_editor_v3,
	_abstract_button_scope_zoom_editor_v3,
	_abstract_button_player_lock_for_manipulation_editor_v3,
	_abstract_button_show_hide_pannel_theater_v3,
	_abstract_button_show_hide_interface_theater_v3,
	_abstract_button_toggle_first_third_person_view_theater_v3,
	_abstract_button_camera_focus_theater_v3,
	_abstract_button_fast_forward_theater_v3,
	_abstract_button_fast_rewind_theater_v3,
	_abstract_button_stop_continue_playback_theater_v3,
	_abstract_button_playback_speed_up_theater_v3,
	_abstract_button_enter_free_camera_mode_theater_v3,

	_abstract_button_movement_speed_up_theater_v4,

	_abstract_button_panning_camera_theater_v5,
	_abstract_button_camera_move_up_theater_v5,
	_abstract_button_camera_move_down_theater_v5,
	_abstract_button_dual_wield_v5,
	_abstract_button_zoom_camera_theater_v5,

	_abstract_button_toggle_rotation_axes_editor_v6 = _abstract_button_show_hide_pannel_theater_v3,
	_abstract_button_show_hide_pannel_theater_v6,
	_abstract_button_show_hide_interface_theater_v6,
	_abstract_button_toggle_first_third_person_view_theater_v6,
	_abstract_button_camera_focus_theater_v6,
	_abstract_button_fast_forward_theater_v6,
	_abstract_button_fast_rewind_theater_v6,
	_abstract_button_stop_continue_playback_theater_v6,
	_abstract_button_playback_speed_up_theater_v6,
	_abstract_button_enter_free_camera_mode_theater_v6,
	_abstract_button_movement_speed_up_theater_v6,
	_abstract_button_panning_camera_theater_v6,
	_abstract_button_camera_move_up_theater_v6,
	_abstract_button_camera_move_down_theater_v6,
	_abstract_button_dual_wield_v6,
	_abstract_button_duplicate_object_editor_v6,
	_abstract_button_lock_object_editor_v6,
	_abstract_button_reset_orientation_editor_v6,
	_abstract_button_zoom_camera_theater_v6,
	_abstract_button_reload_secondary_v6,
	_abstract_button_previous_grenade_v6,
	_abstract_button_special_action_v6,

	k_number_of_abstract_buttons,

	k_number_of_abstract_buttons_v1 = _abstract_button_equipment_v1 + 1,
	k_number_of_abstract_buttons_v2 = _abstract_button_fire_secondary_v2 + 1,
	k_number_of_abstract_buttons_v3 = _abstract_button_enter_free_camera_mode_theater_v3 + 1,
	k_number_of_abstract_buttons_v4 = _abstract_button_movement_speed_up_theater_v4 + 1,
	k_number_of_abstract_buttons_v5 = _abstract_button_zoom_camera_theater_v5 + 1,
	k_number_of_abstract_buttons_v6 = _abstract_button_special_action_v6 + 1,
};

template<size_t abstract_button_count>
struct s_player_configuration_v1
{
	long SubtitleSetting;
	long CrosshairLocation;
	long FOVSetting;
	bool LookControlsInverted;
	bool VibrationDisabled;
	bool ImpulseTriggersDisabled;
	bool AircraftControlsInverted;
	bool AutoCenterEnabled;
	bool CrouchLockEnabled;
	bool ClenchProtectionEnabled;
	bool UseFemaleVoice;
	bool HoldToZoom;
	char __padding0[3];
	long PlayerModelPrimaryColorIndex;
	long PlayerModelSecondaryColorIndex;
	long PlayerModelTertiaryColorIndex;
	bool UseEliteModel;
	bool LockMaxAspectRatio;
	char __padding1[2];
	long PlayerModelPermutation;
	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	float VerticalLookSensitivity;
	float HorizontalLookSensitivity;
	long LookAcceleration;
	float LookAxialDeadZone;
	float LookRadialDeadZone;
	float ZoomLookSensitivityMultiplier;
	float VehicleLookSensitivityMultiplier;
	long ButtonPreset;
	long StickPreset;
	long LeftyToggle;
	long FlyingCameraTurnSensitivity;
	long FlyingCameraPanning;
	long FlyingCameraSpeed;
	long FlyingCameraThrust;
	long TheaterTurnSensitivity;
	long TheaterPanning;
	long TheaterSpeed;
	long TheaterThrust;
	bool SwapTriggersAndBumpers;
	bool UseModernAimControl;
	bool UseDoublePressJumpToJetpack;
	bool DualWieldInverted;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding2[2];
	s_loadout_slot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding3[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	s_custom_key_mapping CustomKeyboardMouseMappings[abstract_button_count];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding4[20];
	long Brightness;
};

template<size_t abstract_button_count>
struct s_player_configuration_v2
{
	long SubtitleSetting;
	long CrosshairLocation;
	long FOVSetting;

	/* new in this version */ long VehicleFOVSetting;

	bool LookControlsInverted;

	/* new in this version */ bool MouseLookControlsInverted;

	bool VibrationDisabled;
	bool ImpulseTriggersDisabled;
	bool AircraftControlsInverted;

	/* new in this version */ bool MouseAircraftControlsInverted;

	bool AutoCenterEnabled;
	bool CrouchLockEnabled;

	/* new in this version */ bool MKCrouchLockEnabled;

	bool ClenchProtectionEnabled;
	bool UseFemaleVoice;
	bool HoldToZoom;
	long PlayerModelPrimaryColorIndex;
	long PlayerModelSecondaryColorIndex;
	long PlayerModelTertiaryColorIndex;
	bool UseEliteModel;
	bool LockMaxAspectRatio;
	char __padding0[2];
	long PlayerModelPermutation;

	/* new in this version */ long HelmetIndex;					 // e_customization_item_v1
	/* new in this version */ long LeftShoulderIndex;			 // e_customization_item_v1
	/* new in this version */ long RightShoulderIndex;			 // e_customization_item_v1
	/* new in this version */ long ChestIndex;					 // e_customization_item_v1
	/* new in this version */ long WristIndex;					 // e_customization_item_v1
	/* new in this version */ long UtilityIndex;				 // e_customization_item_v1
	/* new in this version */ long PaintSchemeIndex;			 // e_customization_item_v1
	/* new in this version */ long VisorColorIndex;				 // e_customization_item_v1
	/* new in this version */ long SpartanArmorEffectIndex;		 // e_customization_item_v1
	/* new in this version */ long SpartanBodyIndex;			 // e_customization_item_v1
	/* new in this version */ long EliteArmorIndex;				 // e_customization_item_v1
	/* new in this version */ long EliteArmorEffectIndex;		 // e_customization_item_v1
	/* new in this version */ long VoiceIndex;					 // e_customization_item_v1
	/* new in this version */ long PlayerModelPrimaryColor;		 // e_customization_item_v1
	/* new in this version */ long PlayerModelSecondaryColor;	 // e_customization_item_v1
	/* new in this version */ long PlayerModelTertiaryColor;	 // e_customization_item_v1

	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	float VerticalLookSensitivity;
	float HorizontalLookSensitivity;
	long LookAcceleration;
	float LookAxialDeadZone;
	float LookRadialDeadZone;
	float ZoomLookSensitivityMultiplier;
	float VehicleLookSensitivityMultiplier;
	long ButtonPreset;
	long StickPreset;
	long LeftyToggle;
	long FlyingCameraTurnSensitivity;
	long FlyingCameraPanning;
	long FlyingCameraSpeed;
	long FlyingCameraThrust;
	long TheaterTurnSensitivity;
	long TheaterPanning;
	long TheaterSpeed;
	long TheaterThrust;
	bool SwapTriggersAndBumpers;
	bool UseModernAimControl;
	bool UseDoublePressJumpToJetpack;
	bool DualWieldInverted;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding1[2];
	s_loadout_slot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding2[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	s_custom_key_mapping CustomKeyboardMouseMappings[abstract_button_count];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding3[16];
	long Brightness;
};

template<size_t abstract_button_count>
struct s_player_configuration_v4 : s_player_configuration_v2<abstract_button_count>
{
	/* new in this version */ s_weapon_display_offset WeaponDisplayOffsets[5];
};

template<size_t abstract_button_count>
struct s_player_configuration_v6
{
	long SubtitleSetting;
	long CrosshairLocation;
	long FOVSetting;
	long VehicleFOVSetting;
	bool LookControlsInverted;
	bool MouseLookControlsInverted;
	bool VibrationDisabled;
	bool ImpulseTriggersDisabled;
	bool AircraftControlsInverted;
	bool MouseAircraftControlsInverted;
	bool AutoCenterEnabled;
	bool CrouchLockEnabled;
	bool MKCrouchLockEnabled;
	bool ClenchProtectionEnabled;
	bool UseFemaleVoice;
	bool HoldToZoom;
	long PlayerModelPrimaryColorIndex;
	long PlayerModelSecondaryColorIndex;
	long PlayerModelTertiaryColorIndex;
	bool UseEliteModel;
	bool LockMaxAspectRatio;
	char __padding0[2];
	long PlayerModelPermutation;

	/* new in this version */ long HelmetIndex;					 // e_customization_item_v1
	/* new in this version */ long LeftShoulderIndex;			 // e_customization_item_v1
	/* new in this version */ long RightShoulderIndex;			 // e_customization_item_v1
	/* new in this version */ long ChestIndex;					 // e_customization_item_v1
	/* new in this version */ long WristIndex;					 // e_customization_item_v1
	/* new in this version */ long UtilityIndex;				 // e_customization_item_v1
	/* new in this version */ long PaintSchemeIndex;			 // e_customization_item_v1
	/* new in this version */ long VisorColorIndex;				 // e_customization_item_v1
	/* new in this version */ long SpartanArmorEffectIndex;		 // e_customization_item_v1
	/* new in this version */ long SpartanBodyIndex;			 // e_customization_item_v1
	/* new in this version */ long EliteArmorIndex;				 // e_customization_item_v1
	/* new in this version */ long EliteArmorEffectIndex;		 // e_customization_item_v1
	/* new in this version */ long VoiceIndex;					 // e_customization_item_v1
	/* new in this version */ long PlayerModelPrimaryColor;		 // e_customization_item_v1
	/* new in this version */ long PlayerModelSecondaryColor;	 // e_customization_item_v1
	/* new in this version */ long PlayerModelTertiaryColor;	 // e_customization_item_v1

	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	float VerticalLookSensitivity;
	float HorizontalLookSensitivity;
	long LookAcceleration;
	float LookAxialDeadZone;
	float LookRadialDeadZone;
	float ZoomLookSensitivityMultiplier;
	float VehicleLookSensitivityMultiplier;
	long ButtonPreset;
	long StickPreset;
	long LeftyToggle;
	long FlyingCameraTurnSensitivity;
	long FlyingCameraPanning;
	long FlyingCameraSpeed;
	long FlyingCameraThrust;
	long TheaterTurnSensitivity;
	long TheaterPanning;
	long TheaterSpeed;
	long TheaterThrust;

	/* new in this version */ char __unknown0[16];

	bool SwapTriggersAndBumpers;
	bool UseModernAimControl;
	bool UseDoublePressJumpToJetpack;
	bool DualWieldInverted;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding1[2];
	s_loadout_slot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding2[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	s_custom_key_mapping CustomKeyboardMouseMappings[abstract_button_count];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding3[16];
	long Brightness;
	s_weapon_display_offset WeaponDisplayOffsets[5];
};

template<size_t abstract_button_count>
struct s_player_configuration_v7
{
	long SubtitleSetting;
	long CrosshairLocation;
	long FOVSetting;
	long VehicleFOVSetting;
	bool LookControlsInverted;
	bool MouseLookControlsInverted;
	bool VibrationDisabled;
	bool ImpulseTriggersDisabled;
	bool AircraftControlsInverted;
	bool MouseAircraftControlsInverted;
	bool AutoCenterEnabled;
	bool CrouchLockEnabled;
	bool MKCrouchLockEnabled;
	bool ClenchProtectionEnabled;
	bool UseFemaleVoice;
	bool HoldToZoom;
	long PlayerModelPrimaryColorIndex;
	long PlayerModelSecondaryColorIndex;
	long PlayerModelTertiaryColorIndex;
	bool UseEliteModel;
	bool LockMaxAspectRatio;
	char __padding0;

	/* new in this version */ bool UsersSkinsEnabled;

	long PlayerModelPermutation;

	long HelmetIndex;											 // e_customization_item_v2
	long LeftShoulderIndex;										 // e_customization_item_v2
	long RightShoulderIndex;									 // e_customization_item_v2
	long ChestIndex;											 // e_customization_item_v2
	long WristIndex;											 // e_customization_item_v2
	long UtilityIndex;											 // e_customization_item_v2
	long ArmsIndex;												 // e_customization_item_v2

	/* new in this version */ long LegsIndex;					 // e_customization_item_v2

	long PaintSchemeIndex;										 // e_customization_item_v2
	long VisorColorIndex;										 // e_customization_item_v2
	long SpartanArmorEffectIndex;								 // e_customization_item_v2
	long SpartanBodyIndex;										 // e_customization_item_v2
	long EliteArmorIndex;										 // e_customization_item_v2
	long EliteArmorEffectIndex;									 // e_customization_item_v2

	/* new in this version */ long EliteHelmetIndex;			 // e_customization_item_v2
	/* new in this version */ long EliteLeftShoulderIndex;		 // e_customization_item_v2
	/* new in this version */ long EliteRightShoulderIndex;		 // e_customization_item_v2
	/* new in this version */ long EliteChestIndex;				 // e_customization_item_v2
	/* new in this version */ long MaybeEliteWristIndex;		 // e_customization_item_v2
	/* new in this version */ long MaybeEliteUtilityIndex;		 // e_customization_item_v2
	/* new in this version */ long MaybeEliteArmsIndex;			 // e_customization_item_v2
	/* new in this version */ long MaybeEliteLegsIndex;			 // e_customization_item_v2

	long VoiceIndex;											 // e_customization_item_v2
	long PlayerModelPrimaryColor;								 // e_customization_item_v2
	long PlayerModelSecondaryColor;								 // e_customization_item_v2
	long PlayerModelTertiaryColor;								 // e_customization_item_v2

	/* new in this version */ s_user_skin UserSkins[15];

	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	float VerticalLookSensitivity;
	float HorizontalLookSensitivity;
	long LookAcceleration;
	float LookAxialDeadZone;
	float LookRadialDeadZone;
	float ZoomLookSensitivityMultiplier;
	float VehicleLookSensitivityMultiplier;
	long ButtonPreset;
	long StickPreset;
	long LeftyToggle;
	long FlyingCameraTurnSensitivity;
	long FlyingCameraPanning;
	long FlyingCameraSpeed;
	long FlyingCameraThrust;
	long TheaterTurnSensitivity;
	long TheaterPanning;
	long TheaterSpeed;
	long TheaterThrust;
	char __unknown0[16];
	bool SwapTriggersAndBumpers;
	bool UseModernAimControl;
	bool UseDoublePressJumpToJetpack;
	bool DualWieldInverted;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding1[2];
	s_loadout_slot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding2[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	s_custom_key_mapping CustomKeyboardMouseMappings[abstract_button_count];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding3[16];
	long Brightness;
	s_weapon_display_offset WeaponDisplayOffsets[5];
};

using t_player_configuration_v1 = s_player_configuration_v1<k_number_of_abstract_buttons_v1>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v1, 0x624);
using t_player_configuration_v2 = s_player_configuration_v2<k_number_of_abstract_buttons_v1>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v2, 0x664);
using t_player_configuration_v3 = s_player_configuration_v2<k_number_of_abstract_buttons_v2>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v3, 0x67C);
using t_player_configuration_v4 = s_player_configuration_v4<k_number_of_abstract_buttons_v3>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v4, 0x884);
using t_player_configuration_v5 = s_player_configuration_v4<k_number_of_abstract_buttons_v4>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v5, 0x89C);
using t_player_configuration_v6 = s_player_configuration_v6<k_number_of_abstract_buttons_v5>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v6, 0x924);
using t_player_configuration_v7 = s_player_configuration_v7<k_number_of_abstract_buttons_v6>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v7, 0xA6C);

enum e_player_configuration_version
{
	_player_configuration_version_1,
	_player_configuration_version_2,
	_player_configuration_version_3,
	_player_configuration_version_4,
	_player_configuration_version_5,
	_player_configuration_version_6,
	_player_configuration_version_7,
};

class c_player_configuration
{
private:
	union
	{
		t_player_configuration_v1 player_configuration_v1;
		t_player_configuration_v2 player_configuration_v2;
		t_player_configuration_v3 player_configuration_v3;
		t_player_configuration_v4 player_configuration_v4;
		t_player_configuration_v5 player_configuration_v5;
		t_player_configuration_v6 player_configuration_v6;
		t_player_configuration_v7 player_configuration_v7;
	};
public:
	e_player_configuration_version const player_configuration_version;
	e_abstract_button const abstract_button_count;
	bool waiting_on_file_save;

	long& SubtitleSetting;
	long& CrosshairLocation;
	long& FOVSetting;
	long& VehicleFOVSetting;
	bool& LookControlsInverted;
	bool& MouseLookControlsInverted;
	bool& VibrationDisabled;
	bool& ImpulseTriggersDisabled;
	bool& AircraftControlsInverted;
	bool& MouseAircraftControlsInverted;
	bool& AutoCenterEnabled;
	bool& CrouchLockEnabled;
	bool& MKCrouchLockEnabled;
	bool& ClenchProtectionEnabled;
	bool& UseFemaleVoice;
	bool& HoldToZoom;
	long& PlayerModelPrimaryColorIndex;
	long& PlayerModelSecondaryColorIndex;
	long& PlayerModelTertiaryColorIndex;
	bool& UseEliteModel;
	bool& LockMaxAspectRatio;
	bool& UsersSkinsEnabled;
	long& PlayerModelPermutation;
	long& HelmetIndex;
	long& LeftShoulderIndex;
	long& RightShoulderIndex;
	long& ChestIndex;
	long& WristIndex;
	long& UtilityIndex;
	long& ArmsIndex;
	long& LegsIndex;
	long& PaintSchemeIndex;
	long& VisorColorIndex;
	long& SpartanArmorEffectIndex;
	long& SpartanBodyIndex;
	long& EliteArmorIndex;
	long& EliteArmorEffectIndex;
	long& EliteHelmetIndex;
	long& EliteLeftShoulderIndex;
	long& EliteRightShoulderIndex;
	long& EliteChestIndex;
	long& MaybeEliteWristIndex;
	long& MaybeEliteUtilityIndex;
	long& MaybeEliteArmsIndex;
	long& MaybeEliteLegsIndex;
	long& VoiceIndex;
	long& PlayerModelPrimaryColor;
	long& PlayerModelSecondaryColor;
	long& PlayerModelTertiaryColor;
	s_user_skin(&UserSkins)[15];
	wchar_t(&ServiceTag)[4];
	long& OnlineMedalFlasher;
	float& VerticalLookSensitivity;
	float& HorizontalLookSensitivity;
	long& LookAcceleration;
	float& LookAxialDeadZone;
	float& LookRadialDeadZone;
	float& ZoomLookSensitivityMultiplier;
	float& VehicleLookSensitivityMultiplier;
	long& ButtonPreset;
	long& StickPreset;
	long& LeftyToggle;
	long& FlyingCameraTurnSensitivity;
	long& FlyingCameraPanning;
	long& FlyingCameraSpeed;
	long& FlyingCameraThrust;
	long& TheaterTurnSensitivity;
	long& TheaterPanning;
	long& TheaterSpeed;
	long& TheaterThrust;
	bool& SwapTriggersAndBumpers;
	bool& UseModernAimControl;
	bool& UseDoublePressJumpToJetpack;
	char& EnemyPlayerNameColor;
	char& GameEngineTimer;
	s_loadout_slot(&LoadoutSlots)[5];
	char(&GameSpecific)[256];
	float& MouseSensitivity;
	bool& MouseSmoothing;
	bool& MouseAcceleration;
	float& MouseAccelerationMinRate;
	float& MouseAccelerationMaxAccel;
	float& MouseAccelerationScale;
	float& MouseAccelerationExp;
	long& KeyboardMouseButtonPreset;
	//s_custom_key_mapping CustomKeyboardMouseMappings[k_number_of_abstract_buttons];
	float& MasterVolume;
	float& MusicVolume;
	float& SfxVolume;
	long& Brightness;
	s_weapon_display_offset(&WeaponDisplayOffsets)[5];

private:

#define reference_getter_v1(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_1: return &player_configuration_v1.field_name; \
		case _player_configuration_version_2: return &player_configuration_v2.field_name; \
		case _player_configuration_version_3: return &player_configuration_v3.field_name; \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		} \
		return nullptr; \
	}
#define reference_getter_v2(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_2: return &player_configuration_v2.field_name; \
		case _player_configuration_version_3: return &player_configuration_v3.field_name; \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		} \
		return nullptr; \
	}
#define reference_getter_v3(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_3: return &player_configuration_v3.field_name; \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		} \
		return nullptr; \
	}
#define reference_getter_v4(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		} \
		return nullptr; \
	}
#define reference_getter_v5(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		} \
		return nullptr; \
	}
#define reference_getter_v6(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		} \
		return nullptr; \
	}
#define reference_getter_v7(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		} \
		return nullptr; \
	}

	reference_getter_v1(SubtitleSetting);
	reference_getter_v1(CrosshairLocation);
	reference_getter_v1(FOVSetting);
	reference_getter_v2(VehicleFOVSetting);
	reference_getter_v1(LookControlsInverted);
	reference_getter_v2(MouseLookControlsInverted);
	reference_getter_v1(VibrationDisabled);
	reference_getter_v1(ImpulseTriggersDisabled);
	reference_getter_v1(AircraftControlsInverted);
	reference_getter_v2(MouseAircraftControlsInverted);
	reference_getter_v1(AutoCenterEnabled);
	reference_getter_v1(CrouchLockEnabled);
	reference_getter_v2(MKCrouchLockEnabled);
	reference_getter_v1(ClenchProtectionEnabled);
	reference_getter_v1(UseFemaleVoice);
	reference_getter_v1(HoldToZoom);
	reference_getter_v1(PlayerModelPrimaryColorIndex);
	reference_getter_v1(PlayerModelSecondaryColorIndex);
	reference_getter_v1(PlayerModelTertiaryColorIndex);
	reference_getter_v1(UseEliteModel);
	reference_getter_v1(LockMaxAspectRatio);
	reference_getter_v7(UsersSkinsEnabled);
	reference_getter_v1(PlayerModelPermutation);
	reference_getter_v2(HelmetIndex);
	reference_getter_v2(LeftShoulderIndex);
	reference_getter_v2(RightShoulderIndex);
	reference_getter_v2(ChestIndex);
	reference_getter_v2(WristIndex);
	reference_getter_v2(UtilityIndex);
	reference_getter_v7(ArmsIndex);
	reference_getter_v7(LegsIndex);
	reference_getter_v2(PaintSchemeIndex);
	reference_getter_v2(VisorColorIndex);
	reference_getter_v2(SpartanArmorEffectIndex);
	reference_getter_v2(SpartanBodyIndex);
	reference_getter_v2(EliteArmorIndex);
	reference_getter_v2(EliteArmorEffectIndex);
	reference_getter_v7(EliteHelmetIndex);
	reference_getter_v7(EliteLeftShoulderIndex);
	reference_getter_v7(EliteRightShoulderIndex);
	reference_getter_v7(EliteChestIndex);
	reference_getter_v7(MaybeEliteWristIndex);
	reference_getter_v7(MaybeEliteUtilityIndex);
	reference_getter_v7(MaybeEliteArmsIndex);
	reference_getter_v7(MaybeEliteLegsIndex);
	reference_getter_v2(VoiceIndex);
	reference_getter_v2(PlayerModelPrimaryColor);
	reference_getter_v2(PlayerModelSecondaryColor);
	reference_getter_v2(PlayerModelTertiaryColor);
	reference_getter_v7(UserSkins);
	reference_getter_v1(ServiceTag);
	reference_getter_v1(OnlineMedalFlasher);
	reference_getter_v1(VerticalLookSensitivity);
	reference_getter_v1(HorizontalLookSensitivity);
	reference_getter_v1(LookAcceleration);
	reference_getter_v1(LookAxialDeadZone);
	reference_getter_v1(LookRadialDeadZone);
	reference_getter_v1(ZoomLookSensitivityMultiplier);
	reference_getter_v1(VehicleLookSensitivityMultiplier);
	reference_getter_v1(ButtonPreset);
	reference_getter_v1(StickPreset);
	reference_getter_v1(LeftyToggle);
	reference_getter_v1(FlyingCameraTurnSensitivity);
	reference_getter_v1(FlyingCameraPanning);
	reference_getter_v1(FlyingCameraSpeed);
	reference_getter_v1(FlyingCameraThrust);
	reference_getter_v1(TheaterTurnSensitivity);
	reference_getter_v1(TheaterPanning);
	reference_getter_v1(TheaterSpeed);
	reference_getter_v1(TheaterThrust);
	reference_getter_v1(SwapTriggersAndBumpers);
	reference_getter_v1(UseModernAimControl);
	reference_getter_v1(UseDoublePressJumpToJetpack);
	reference_getter_v1(EnemyPlayerNameColor);
	reference_getter_v1(GameEngineTimer);
	reference_getter_v1(LoadoutSlots);
	reference_getter_v1(GameSpecific);
	reference_getter_v1(MouseSensitivity);
	reference_getter_v1(MouseSmoothing);
	reference_getter_v1(MouseAcceleration);
	reference_getter_v1(MouseAccelerationMinRate);
	reference_getter_v1(MouseAccelerationMaxAccel);
	reference_getter_v1(MouseAccelerationScale);
	reference_getter_v1(MouseAccelerationExp);
	reference_getter_v1(KeyboardMouseButtonPreset);
	reference_getter_v1(MasterVolume);
	reference_getter_v1(MusicVolume);
	reference_getter_v1(SfxVolume);
	reference_getter_v1(Brightness);
	reference_getter_v4(WeaponDisplayOffsets)

#undef reference_getter_v1
#undef reference_getter_v2
#undef reference_getter_v3
#undef reference_getter_v4
#undef reference_getter_v5
#undef reference_getter_v6
#undef reference_getter_v7

	class c_virtual_player_configuration_game_keyboard_mouse_mapping_interface
	{
	public:
		c_virtual_player_configuration_game_keyboard_mouse_mapping_interface(c_player_configuration& parent) :
			parent(parent)
		{ }

		c_player_configuration& parent;

		s_custom_key_mapping& operator[](size_t abstract_button_index) const
		{
			switch (parent.player_configuration_version)
			{
			case _player_configuration_version_1: return parent.player_configuration_v1.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_2: return parent.player_configuration_v2.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_3: return parent.player_configuration_v3.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_4: return parent.player_configuration_v4.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_5: return parent.player_configuration_v5.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_6: return parent.player_configuration_v6.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_7: return parent.player_configuration_v7.CustomKeyboardMouseMappings[abstract_button_index];
			}
			throw;
		}
	};

	e_abstract_button GetAbstractButtonCount()
	{
		switch (player_configuration_version)
		{
		case _player_configuration_version_1:
		case _player_configuration_version_2:
			return k_number_of_abstract_buttons_v1;
		case _player_configuration_version_3:
			return k_number_of_abstract_buttons_v2;
		case _player_configuration_version_4:
			return k_number_of_abstract_buttons_v3;
		case _player_configuration_version_5:
			return k_number_of_abstract_buttons_v4;
		case _player_configuration_version_6:
			return k_number_of_abstract_buttons_v5;
		case _player_configuration_version_7:
			return k_number_of_abstract_buttons_v6;
		}

		return k_number_of_abstract_buttons;
	}

public:
	c_virtual_player_configuration_game_keyboard_mouse_mapping_interface CustomKeyboardMouseMappings;

	c_player_configuration(e_player_configuration_version player_configuration_version) :
		player_configuration_v1(),
		//player_configuration_v2(),
		//player_configuration_v3(),
		//player_configuration_v4(),
		//player_configuration_v5(),
		//player_configuration_v6(),

		player_configuration_version(player_configuration_version),
		abstract_button_count(GetAbstractButtonCount()),
		waiting_on_file_save(false),

		SubtitleSetting(*GetSubtitleSetting()),
		CrosshairLocation(*GetCrosshairLocation()),
		FOVSetting(*GetFOVSetting()),
		VehicleFOVSetting(*GetVehicleFOVSetting()),
		LookControlsInverted(*GetLookControlsInverted()),
		MouseLookControlsInverted(*GetMouseLookControlsInverted()),
		VibrationDisabled(*GetVibrationDisabled()),
		ImpulseTriggersDisabled(*GetImpulseTriggersDisabled()),
		AircraftControlsInverted(*GetAircraftControlsInverted()),
		MouseAircraftControlsInverted(*GetMouseAircraftControlsInverted()),
		AutoCenterEnabled(*GetAutoCenterEnabled()),
		CrouchLockEnabled(*GetCrouchLockEnabled()),
		MKCrouchLockEnabled(*GetMKCrouchLockEnabled()),
		ClenchProtectionEnabled(*GetClenchProtectionEnabled()),
		UseFemaleVoice(*GetUseFemaleVoice()),
		HoldToZoom(*GetHoldToZoom()),
		PlayerModelPrimaryColorIndex(*GetPlayerModelPrimaryColorIndex()),
		PlayerModelSecondaryColorIndex(*GetPlayerModelSecondaryColorIndex()),
		PlayerModelTertiaryColorIndex(*GetPlayerModelTertiaryColorIndex()),
		UseEliteModel(*GetUseEliteModel()),
		LockMaxAspectRatio(*GetLockMaxAspectRatio()),
		UsersSkinsEnabled(*GetUsersSkinsEnabled()),
		PlayerModelPermutation(*GetPlayerModelPermutation()),
		HelmetIndex(*GetHelmetIndex()),
		LeftShoulderIndex(*GetLeftShoulderIndex()),
		RightShoulderIndex(*GetRightShoulderIndex()),
		ChestIndex(*GetChestIndex()),
		WristIndex(*GetWristIndex()),
		UtilityIndex(*GetUtilityIndex()),
		ArmsIndex(*GetArmsIndex()),
		LegsIndex(*GetLegsIndex()),
		PaintSchemeIndex(*GetPaintSchemeIndex()),
		VisorColorIndex(*GetVisorColorIndex()),
		SpartanArmorEffectIndex(*GetSpartanArmorEffectIndex()),
		SpartanBodyIndex(*GetSpartanBodyIndex()),
		EliteArmorIndex(*GetEliteArmorIndex()),
		EliteArmorEffectIndex(*GetEliteArmorEffectIndex()),
		EliteHelmetIndex(*GetEliteHelmetIndex()),
		EliteLeftShoulderIndex(*GetEliteLeftShoulderIndex()),
		EliteRightShoulderIndex(*GetEliteRightShoulderIndex()),
		EliteChestIndex(*GetEliteChestIndex()),
		MaybeEliteWristIndex(*GetMaybeEliteWristIndex()),
		MaybeEliteUtilityIndex(*GetMaybeEliteUtilityIndex()),
		MaybeEliteArmsIndex(*GetMaybeEliteArmsIndex()),
		MaybeEliteLegsIndex(*GetMaybeEliteLegsIndex()),
		VoiceIndex(*GetVoiceIndex()),
		PlayerModelPrimaryColor(*GetPlayerModelPrimaryColor()),
		PlayerModelSecondaryColor(*GetPlayerModelSecondaryColor()),
		PlayerModelTertiaryColor(*GetPlayerModelTertiaryColor()),
		UserSkins(*GetUserSkins()),
		ServiceTag(*GetServiceTag()),
		OnlineMedalFlasher(*GetOnlineMedalFlasher()),
		VerticalLookSensitivity(*GetVerticalLookSensitivity()),
		HorizontalLookSensitivity(*GetHorizontalLookSensitivity()),
		LookAcceleration(*GetLookAcceleration()),
		LookAxialDeadZone(*GetLookAxialDeadZone()),
		LookRadialDeadZone(*GetLookRadialDeadZone()),
		ZoomLookSensitivityMultiplier(*GetZoomLookSensitivityMultiplier()),
		VehicleLookSensitivityMultiplier(*GetVehicleLookSensitivityMultiplier()),
		ButtonPreset(*GetButtonPreset()),
		StickPreset(*GetStickPreset()),
		LeftyToggle(*GetLeftyToggle()),
		FlyingCameraTurnSensitivity(*GetFlyingCameraTurnSensitivity()),
		FlyingCameraPanning(*GetFlyingCameraPanning()),
		FlyingCameraSpeed(*GetFlyingCameraSpeed()),
		FlyingCameraThrust(*GetFlyingCameraThrust()),
		TheaterTurnSensitivity(*GetTheaterTurnSensitivity()),
		TheaterPanning(*GetTheaterPanning()),
		TheaterSpeed(*GetTheaterSpeed()),
		TheaterThrust(*GetTheaterThrust()),
		SwapTriggersAndBumpers(*GetSwapTriggersAndBumpers()),
		UseModernAimControl(*GetUseModernAimControl()),
		UseDoublePressJumpToJetpack(*GetUseDoublePressJumpToJetpack()),
		EnemyPlayerNameColor(*GetEnemyPlayerNameColor()),
		GameEngineTimer(*GetGameEngineTimer()),
		LoadoutSlots(*GetLoadoutSlots()),
		GameSpecific(*GetGameSpecific()),
		MouseSensitivity(*GetMouseSensitivity()),
		MouseSmoothing(*GetMouseSmoothing()),
		MouseAcceleration(*GetMouseAcceleration()),
		MouseAccelerationMinRate(*GetMouseAccelerationMinRate()),
		MouseAccelerationMaxAccel(*GetMouseAccelerationMaxAccel()),
		MouseAccelerationScale(*GetMouseAccelerationScale()),
		MouseAccelerationExp(*GetMouseAccelerationExp()),
		KeyboardMouseButtonPreset(*GetKeyboardMouseButtonPreset()),
		CustomKeyboardMouseMappings(*this),
		MasterVolume(*GetMasterVolume()),
		MusicVolume(*GetMusicVolume()),
		SfxVolume(*GetSfxVolume()),
		Brightness(*GetBrightness()),
		WeaponDisplayOffsets(*GetWeaponDisplayOffsets())
	{
		memset(&player_configuration_v1, 0, sizeof(player_configuration_v1));
		memset(&player_configuration_v2, 0, sizeof(player_configuration_v2));
		memset(&player_configuration_v3, 0, sizeof(player_configuration_v3));
		memset(&player_configuration_v4, 0, sizeof(player_configuration_v4));
		memset(&player_configuration_v5, 0, sizeof(player_configuration_v5));
		memset(&player_configuration_v6, 0, sizeof(player_configuration_v6));
		memset(&player_configuration_v7, 0, sizeof(player_configuration_v7));
	}
};

#pragma warning(disable:4244)
#pragma warning(disable:4305)
#define write_control_to_config(field_name) { \
	if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(bool).hash_code()) \
	{ \
		c_settings::write_boolean(_settings_section_player_configuration, STRINGIFY(##field_name), player_configuration.##field_name); \
	} \
	else if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(float).hash_code()) \
	{ \
		c_settings::write_float(_settings_section_player_configuration, STRINGIFY(##field_name), player_configuration.##field_name); \
	} \
	else if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(int).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(char).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(short).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(long).hash_code()) \
	{ \
		c_settings::write_integer(_settings_section_player_configuration, STRINGIFY(##field_name), player_configuration.##field_name); \
	} \
}

#define read_control_from_config(field_name, default_value) { \
	if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(bool).hash_code()) \
	{ \
		player_configuration.##field_name = c_settings::read_boolean(_settings_section_player_configuration, STRINGIFY(##field_name), default_value); \
	} \
	else if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(float).hash_code()) \
	{ \
		player_configuration.##field_name = c_settings::read_float(_settings_section_player_configuration, STRINGIFY(##field_name), default_value); \
	} \
	else if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(int).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(char).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(short).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(long).hash_code()) \
	{ \
		player_configuration.##field_name = c_settings::read_integer(_settings_section_player_configuration, STRINGIFY(##field_name), default_value); \
	} \
}

#define write_custom_key_mapping_to_config(abstract_button_index, custom_key_mappings) { \
	std::string custom_key_mapping_for_write##abstract_button_index(STRINGIFY(##custom_key_mappings)); \
	custom_key_mapping_for_write##abstract_button_index.append("[").append(std::to_string(##abstract_button_index)).append("]."); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(AbstractButton)).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].AbstractButton); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[0])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[0]); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[1])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[1]); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[2])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[2]); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[3])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[3]); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[4])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[4]); \
}

#define read_custom_key_mapping_from_config(abstract_button_index, custom_key_mappings, custom_key_mapping) { \
	std::string custom_key_mapping_for_read##abstract_button_index(STRINGIFY(##custom_key_mappings)); \
	custom_key_mapping_for_read##abstract_button_index.append("[").append(std::to_string(##abstract_button_index)).append("]."); \
	player_configuration.##custom_key_mappings[abstract_button_index].AbstractButton = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(AbstractButton)).c_str(), custom_key_mapping.AbstractButton); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[0] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[0])).c_str(), custom_key_mapping.VirtualKeyCodes[0]); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[1] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[1])).c_str(), custom_key_mapping.VirtualKeyCodes[1]); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[2] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[2])).c_str(), custom_key_mapping.VirtualKeyCodes[2]); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[3] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[3])).c_str(), custom_key_mapping.VirtualKeyCodes[3]); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[4] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[4])).c_str(), custom_key_mapping.VirtualKeyCodes[4]); \
}

inline void save_player_configuration_to_file(c_player_configuration& player_configuration)
{
	write_control_to_config(SubtitleSetting);
	write_control_to_config(CrosshairLocation);
	write_control_to_config(FOVSetting);
	write_control_to_config(VehicleFOVSetting);
	write_control_to_config(LookControlsInverted);
	write_control_to_config(MouseLookControlsInverted);
	write_control_to_config(VibrationDisabled);
	write_control_to_config(ImpulseTriggersDisabled);
	write_control_to_config(AircraftControlsInverted);
	write_control_to_config(MouseAircraftControlsInverted);
	write_control_to_config(AutoCenterEnabled);
	write_control_to_config(CrouchLockEnabled);
	write_control_to_config(MKCrouchLockEnabled);
	write_control_to_config(ClenchProtectionEnabled);
	write_control_to_config(UseFemaleVoice);
	write_control_to_config(HoldToZoom);
	write_control_to_config(PlayerModelPrimaryColorIndex);
	write_control_to_config(PlayerModelSecondaryColorIndex);
	write_control_to_config(PlayerModelTertiaryColorIndex);
	write_control_to_config(UseEliteModel);
	write_control_to_config(LockMaxAspectRatio);
	write_control_to_config(UsersSkinsEnabled);
	write_control_to_config(PlayerModelPermutation);
	write_control_to_config(HelmetIndex);
	write_control_to_config(LeftShoulderIndex);
	write_control_to_config(RightShoulderIndex);
	write_control_to_config(ChestIndex);
	write_control_to_config(WristIndex);
	write_control_to_config(UtilityIndex);
	write_control_to_config(ArmsIndex);
	write_control_to_config(LegsIndex);
	write_control_to_config(PaintSchemeIndex);
	write_control_to_config(VisorColorIndex);
	write_control_to_config(SpartanArmorEffectIndex);
	write_control_to_config(SpartanBodyIndex);
	write_control_to_config(EliteArmorIndex);
	write_control_to_config(EliteArmorEffectIndex);
	write_control_to_config(EliteHelmetIndex);
	write_control_to_config(EliteLeftShoulderIndex);
	write_control_to_config(EliteRightShoulderIndex);
	write_control_to_config(EliteChestIndex);
	write_control_to_config(MaybeEliteWristIndex);
	write_control_to_config(MaybeEliteUtilityIndex);
	write_control_to_config(MaybeEliteArmsIndex);
	write_control_to_config(MaybeEliteLegsIndex);
	write_control_to_config(VoiceIndex);
	write_control_to_config(PlayerModelPrimaryColor);
	write_control_to_config(PlayerModelSecondaryColor);
	write_control_to_config(PlayerModelTertiaryColor);

	c_settings::write_wstring(_settings_section_player_configuration, "ServiceTag", player_configuration.ServiceTag);

	write_control_to_config(OnlineMedalFlasher);
	write_control_to_config(VerticalLookSensitivity);
	write_control_to_config(HorizontalLookSensitivity);
	write_control_to_config(LookAcceleration);
	write_control_to_config(LookAxialDeadZone);
	write_control_to_config(LookRadialDeadZone);
	write_control_to_config(ZoomLookSensitivityMultiplier);
	write_control_to_config(VehicleLookSensitivityMultiplier);
	write_control_to_config(ButtonPreset);
	write_control_to_config(StickPreset);
	write_control_to_config(LeftyToggle);
	write_control_to_config(FlyingCameraTurnSensitivity);
	write_control_to_config(FlyingCameraPanning);
	write_control_to_config(FlyingCameraSpeed);
	write_control_to_config(FlyingCameraThrust);
	write_control_to_config(TheaterTurnSensitivity);
	write_control_to_config(TheaterPanning);
	write_control_to_config(TheaterSpeed);
	write_control_to_config(TheaterThrust);
	write_control_to_config(SwapTriggersAndBumpers);
	write_control_to_config(UseModernAimControl);
	write_control_to_config(UseDoublePressJumpToJetpack);
	write_control_to_config(EnemyPlayerNameColor);
	write_control_to_config(GameEngineTimer);
	write_control_to_config(MouseSensitivity);
	write_control_to_config(MouseSmoothing);
	write_control_to_config(MouseAcceleration);
	write_control_to_config(MouseAccelerationMinRate);
	write_control_to_config(MouseAccelerationMaxAccel);
	write_control_to_config(MouseAccelerationScale);
	write_control_to_config(MouseAccelerationExp);
	write_control_to_config(KeyboardMouseButtonPreset);
	write_control_to_config(MasterVolume);
	write_control_to_config(MusicVolume);
	write_control_to_config(SfxVolume);
	write_control_to_config(Brightness);

	for (long abstract_button_index = 0; abstract_button_index < player_configuration.abstract_button_count; abstract_button_index++)
	{
		write_custom_key_mapping_to_config(abstract_button_index, CustomKeyboardMouseMappings);
	}
}

inline void load_player_configuration_from_file(c_player_configuration& player_configuration, e_build build, e_engine_type engine_type)
{
	read_control_from_config(SubtitleSetting, 0l);
	read_control_from_config(CrosshairLocation, 0l);
	read_control_from_config(FOVSetting, 90l);

	if (player_configuration.player_configuration_version >= e_player_configuration_version::_player_configuration_version_2)
		read_control_from_config(VehicleFOVSetting, 90l);

	read_control_from_config(LookControlsInverted, false);

	if (player_configuration.player_configuration_version >= e_player_configuration_version::_player_configuration_version_2)
		read_control_from_config(MouseLookControlsInverted, false);

	read_control_from_config(VibrationDisabled, false);
	read_control_from_config(ImpulseTriggersDisabled, false);
	read_control_from_config(AircraftControlsInverted, false);

	if (player_configuration.player_configuration_version >= e_player_configuration_version::_player_configuration_version_2)
		read_control_from_config(MouseAircraftControlsInverted, false);

	read_control_from_config(AutoCenterEnabled, false);
	read_control_from_config(CrouchLockEnabled, false);

	if (player_configuration.player_configuration_version >= e_player_configuration_version::_player_configuration_version_2)
		read_control_from_config(MKCrouchLockEnabled, false);

	read_control_from_config(ClenchProtectionEnabled, false);
	read_control_from_config(UseFemaleVoice, false);
	read_control_from_config(HoldToZoom, true);
	read_control_from_config(PlayerModelPrimaryColorIndex, 0l);
	read_control_from_config(PlayerModelSecondaryColorIndex, 0l);
	read_control_from_config(PlayerModelTertiaryColorIndex, 0l);
	read_control_from_config(UseEliteModel, false);
	read_control_from_config(LockMaxAspectRatio, false);

	if (player_configuration.player_configuration_version >= e_player_configuration_version::_player_configuration_version_7)
		read_control_from_config(UsersSkinsEnabled, false);

	read_control_from_config(PlayerModelPermutation, 0l);

	if (player_configuration.player_configuration_version >= e_player_configuration_version::_player_configuration_version_2)
	{
		switch (engine_type)
		{
		case _engine_type_haloreach:
			read_control_from_config(HelmetIndex, (long)e_customization_item_v1::HR_Helmet_EOD_Base);
			read_control_from_config(LeftShoulderIndex, (long)e_customization_item_v1::HR_LeftShoulder_Gungnir);
			read_control_from_config(RightShoulderIndex, (long)e_customization_item_v1::HR_RightShoulder_EVA);
			read_control_from_config(ChestIndex, (long)e_customization_item_v1::HR_Chest_UABaseSecurityW);
			read_control_from_config(WristIndex, (long)e_customization_item_v1::HR_Wrist_Default);
			read_control_from_config(UtilityIndex, (long)e_customization_item_v1::HR_Utility_Default);
			read_control_from_config(PaintSchemeIndex, (long)e_customization_item_v1::HR_KneeGuards_FJPARA);
			read_control_from_config(VisorColorIndex, (long)e_customization_item_v1::HR_VisorColor_Blue);
			read_control_from_config(SpartanArmorEffectIndex, (long)e_customization_item_v1::HR_ArmorEffect_BlueFlames);
			read_control_from_config(SpartanBodyIndex, (long)e_customization_item_v1::HR_Spartan_Female);
			read_control_from_config(EliteArmorIndex, (long)e_customization_item_v1::HR_Elite_FieldMarshall);
			read_control_from_config(EliteArmorEffectIndex, (long)e_customization_item_v1::HR_ArmorEffect_Pestilence);
			read_control_from_config(VoiceIndex, (long)e_customization_item_v1::HR_FirefightVoice_JohnS117);
			read_control_from_config(PlayerModelPrimaryColor, (long)e_customization_item_v1::HR_Color_Brick);
			read_control_from_config(PlayerModelSecondaryColor, (long)e_customization_item_v1::HR_Color_Cyan);
			read_control_from_config(PlayerModelTertiaryColor, (long)e_customization_item_v1::HR_Color_Cyan);
			break;
		case _engine_type_halo1:
			read_control_from_config(HelmetIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(LeftShoulderIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(RightShoulderIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(ChestIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(WristIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(UtilityIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(PaintSchemeIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(VisorColorIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(SpartanArmorEffectIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(SpartanBodyIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(EliteArmorIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(EliteArmorEffectIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(VoiceIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(PlayerModelPrimaryColor, (long)e_customization_item_v1::H1_Color_1);
			read_control_from_config(PlayerModelSecondaryColor, (long)e_customization_item_v1::H1_Color_1);
			read_control_from_config(PlayerModelTertiaryColor, (long)e_customization_item_v1::H1_Color_1);
			break;
		case _engine_type_groundhog:
			read_control_from_config(HelmetIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(LeftShoulderIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(RightShoulderIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(ChestIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(WristIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(UtilityIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(PaintSchemeIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(VisorColorIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(SpartanArmorEffectIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(SpartanBodyIndex, (long)e_customization_item_v1::HR_Spartan_Female);
			read_control_from_config(EliteArmorIndex, (long)e_customization_item_v1::H2A_ARMOR_ELITE1);
			read_control_from_config(EliteArmorEffectIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(VoiceIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(PlayerModelPrimaryColor, (long)e_customization_item_v1::H2A_Color_1);
			read_control_from_config(PlayerModelSecondaryColor, (long)e_customization_item_v1::H2A_Color_1);
			read_control_from_config(PlayerModelTertiaryColor, (long)e_customization_item_v1::H2A_Color_1);
			break;
		}
	}

	c_settings::read_wstring(_settings_section_player_configuration, "ServiceTag", player_configuration.ServiceTag, 4, L"117");

	read_control_from_config(OnlineMedalFlasher, 0l);
	read_control_from_config(VerticalLookSensitivity, 1.0f);
	read_control_from_config(HorizontalLookSensitivity, 1.0f);
	read_control_from_config(LookAcceleration, 0l);
	read_control_from_config(LookAxialDeadZone, 0.0f);
	read_control_from_config(LookRadialDeadZone, 0.0f);
	read_control_from_config(ZoomLookSensitivityMultiplier, 0.0f);
	read_control_from_config(VehicleLookSensitivityMultiplier, 0.0f);
	read_control_from_config(ButtonPreset, 0l);
	read_control_from_config(StickPreset, 0l);
	read_control_from_config(LeftyToggle, 0l);
	read_control_from_config(FlyingCameraTurnSensitivity, 0l);
	read_control_from_config(FlyingCameraPanning, 0l);
	read_control_from_config(FlyingCameraSpeed, 0l);
	read_control_from_config(FlyingCameraThrust, 0l);
	read_control_from_config(TheaterTurnSensitivity, 0l);
	read_control_from_config(TheaterPanning, 0l);
	read_control_from_config(TheaterSpeed, 0l);
	read_control_from_config(TheaterThrust, 0l);
	read_control_from_config(SwapTriggersAndBumpers, false);
	read_control_from_config(UseModernAimControl, false);
	read_control_from_config(UseDoublePressJumpToJetpack, true);
	read_control_from_config(EnemyPlayerNameColor, 0i8);
	read_control_from_config(GameEngineTimer, 0i8);
	read_control_from_config(MouseSensitivity, 0.0f);
	read_control_from_config(MouseSmoothing, false);
	read_control_from_config(MouseAcceleration, false);
	read_control_from_config(MouseAccelerationMinRate, 0.0f);
	read_control_from_config(MouseAccelerationMaxAccel, 0.0f);
	read_control_from_config(MouseAccelerationScale, 0.0f);
	read_control_from_config(MouseAccelerationExp, 0.0f);
	read_control_from_config(KeyboardMouseButtonPreset, 0l);
	read_control_from_config(MasterVolume, 60.0f);
	read_control_from_config(MusicVolume, 20.0f);
	read_control_from_config(SfxVolume, 80.0f);
	read_control_from_config(Brightness, 0l);

	s_custom_key_mapping CustomKeyboardMouseMappings[k_number_of_abstract_buttons] = {};

	for (long i = 0; i < k_number_of_abstract_buttons; i++)
	{
		CustomKeyboardMouseMappings[i].AbstractButton = i;
	}

	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v1)
	{
		CustomKeyboardMouseMappings[_abstract_button_jump_v1].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_switch_grenade_v1].VirtualKeyCodes[0] = 'G';
		CustomKeyboardMouseMappings[_abstract_button_context_primary_v1].VirtualKeyCodes[0] = 'E';
		CustomKeyboardMouseMappings[_abstract_button_reload_v1].VirtualKeyCodes[0] = 'R';
		CustomKeyboardMouseMappings[_abstract_button_switch_weapon_v1].VirtualKeyCodes[0] = 'C';
		CustomKeyboardMouseMappings[_abstract_button_melee_v1].VirtualKeyCodes[0] = 'V';
		CustomKeyboardMouseMappings[_abstract_button_flashlight_v1].VirtualKeyCodes[0] = '4';
		CustomKeyboardMouseMappings[_abstract_button_throw_grenade_v1].VirtualKeyCodes[0] = 'F';
		CustomKeyboardMouseMappings[_abstract_button_fire_v1].VirtualKeyCodes[0] = VK_LBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_crouch_v1].VirtualKeyCodes[0] = VK_LCONTROL;
		CustomKeyboardMouseMappings[_abstract_button_zoom_v1].VirtualKeyCodes[0] = VK_RBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_zoom_in_v1].VirtualKeyCodes[0] = 'Z';
		CustomKeyboardMouseMappings[_abstract_button_zoom_out_v1].VirtualKeyCodes[0] = 'X';
		CustomKeyboardMouseMappings[_abstract_button_exchange_weapon_v1].VirtualKeyCodes[0] = 'E';
		CustomKeyboardMouseMappings[_abstract_button_trick_v1].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_brake_v1].VirtualKeyCodes[0] = VK_LSHIFT;
		CustomKeyboardMouseMappings[_abstract_button_ebrake_v1].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_sprint_v1].VirtualKeyCodes[0] = VK_LSHIFT;
		CustomKeyboardMouseMappings[_abstract_button_banshee_bomb_v1].VirtualKeyCodes[0] = 'F';
		CustomKeyboardMouseMappings[_abstract_button_forward_v1].VirtualKeyCodes[0] = 'W';
		CustomKeyboardMouseMappings[_abstract_button_backward_v1].VirtualKeyCodes[0] = 'S';
		CustomKeyboardMouseMappings[_abstract_button_left_v1].VirtualKeyCodes[0] = 'A';
		CustomKeyboardMouseMappings[_abstract_button_right_v1].VirtualKeyCodes[0] = 'D';
		CustomKeyboardMouseMappings[_abstract_button_lean_left_v1].VirtualKeyCodes[0] = '8';
		CustomKeyboardMouseMappings[_abstract_button_lean_right_v1].VirtualKeyCodes[0] = '9';
		CustomKeyboardMouseMappings[_abstract_button_start_v1].VirtualKeyCodes[0] = '7';
		CustomKeyboardMouseMappings[_abstract_button_back_v1].VirtualKeyCodes[0] = VK_TAB;
		CustomKeyboardMouseMappings[_abstract_button_show_scores_v1].VirtualKeyCodes[0] = VK_TAB;
		CustomKeyboardMouseMappings[_abstract_button_accept_v1].VirtualKeyCodes[0] = '5';
		CustomKeyboardMouseMappings[_abstract_button_cancel_v1].VirtualKeyCodes[0] = '6';
		CustomKeyboardMouseMappings[_abstract_button_primary_vehicle_trick_v1].VirtualKeyCodes[0] = VK_LCONTROL;
		CustomKeyboardMouseMappings[_abstract_button_secondary_vehicle_trick_v1].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_magnify_zoom_v1].VirtualKeyCodes[0] = 'Z';
		CustomKeyboardMouseMappings[_abstract_button_equipment_v1].VirtualKeyCodes[0] = VK_LSHIFT;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v2)
	{
		CustomKeyboardMouseMappings[_abstract_button_fire_secondary_v2].VirtualKeyCodes[0] = VK_LSHIFT;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v3)
	{
		CustomKeyboardMouseMappings[_abstract_button_lift_editor_v3].VirtualKeyCodes[0] = 'R';
		CustomKeyboardMouseMappings[_abstract_button_drop_editor_v3].VirtualKeyCodes[0] = 'F';
		CustomKeyboardMouseMappings[_abstract_button_grab_object_editor_v3].VirtualKeyCodes[0] = VK_LBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_boost_editor_v3].VirtualKeyCodes[0] = VK_LSHIFT;
		CustomKeyboardMouseMappings[_abstract_button_crouch_editor_v3].VirtualKeyCodes[0] = VK_LCONTROL;
		CustomKeyboardMouseMappings[_abstract_button_delete_object_editor_v3].VirtualKeyCodes[0] = VK_DELETE;
		CustomKeyboardMouseMappings[_abstract_button_create_object_editor_v3].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_open_tool_menu_editor_v3].VirtualKeyCodes[0] = 'X';
		CustomKeyboardMouseMappings[_abstract_button_switch_player_mode_editor_v3].VirtualKeyCodes[0] = VK_UP;
		CustomKeyboardMouseMappings[_abstract_button_scope_zoom_editor_v3].VirtualKeyCodes[0] = VK_RBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_player_lock_for_manipulation_editor_v3].VirtualKeyCodes[0] = VK_LMENU;
		CustomKeyboardMouseMappings[_abstract_button_show_hide_pannel_theater_v3].VirtualKeyCodes[0] = 'X';
		CustomKeyboardMouseMappings[_abstract_button_show_hide_interface_theater_v3].VirtualKeyCodes[0] = 'Z';
		CustomKeyboardMouseMappings[_abstract_button_toggle_first_third_person_view_theater_v3].VirtualKeyCodes[0] = 'C';
		CustomKeyboardMouseMappings[_abstract_button_camera_focus_theater_v3].VirtualKeyCodes[0] = VK_RBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_fast_forward_theater_v3].VirtualKeyCodes[0] = VK_RIGHT;
		CustomKeyboardMouseMappings[_abstract_button_fast_rewind_theater_v3].VirtualKeyCodes[0] = VK_LEFT;
		CustomKeyboardMouseMappings[_abstract_button_stop_continue_playback_theater_v3].VirtualKeyCodes[0] = VK_RETURN;
		CustomKeyboardMouseMappings[_abstract_button_playback_speed_up_theater_v3].VirtualKeyCodes[0] = VK_LMENU;
		CustomKeyboardMouseMappings[_abstract_button_enter_free_camera_mode_theater_v3].VirtualKeyCodes[0] = VK_SPACE;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v4)
	{
		CustomKeyboardMouseMappings[_abstract_button_movement_speed_up_theater_v4].VirtualKeyCodes[0] = VK_LSHIFT;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v5)
	{
		CustomKeyboardMouseMappings[_abstract_button_panning_camera_theater_v5].VirtualKeyCodes[0] = VK_OEM_RESET;
		CustomKeyboardMouseMappings[_abstract_button_camera_move_up_theater_v5].VirtualKeyCodes[0] = 'Q';
		CustomKeyboardMouseMappings[_abstract_button_camera_move_down_theater_v5].VirtualKeyCodes[0] = 'E';
		CustomKeyboardMouseMappings[_abstract_button_dual_wield_v5].VirtualKeyCodes[0] = 'Q';
		CustomKeyboardMouseMappings[_abstract_button_zoom_camera_theater_v5].VirtualKeyCodes[0] = VK_OEM_RESET;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v6)
	{
		CustomKeyboardMouseMappings[_abstract_button_toggle_rotation_axes_editor_v6].VirtualKeyCodes[0] = 'O';
		CustomKeyboardMouseMappings[_abstract_button_show_hide_pannel_theater_v6].VirtualKeyCodes[0] = 'X';
		CustomKeyboardMouseMappings[_abstract_button_show_hide_interface_theater_v6].VirtualKeyCodes[0] = 'Z';
		CustomKeyboardMouseMappings[_abstract_button_toggle_first_third_person_view_theater_v6].VirtualKeyCodes[0] = 'C';
		CustomKeyboardMouseMappings[_abstract_button_camera_focus_theater_v6].VirtualKeyCodes[0] = VK_RBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_fast_forward_theater_v6].VirtualKeyCodes[0] = VK_RIGHT;
		CustomKeyboardMouseMappings[_abstract_button_fast_rewind_theater_v6].VirtualKeyCodes[0] = VK_LEFT;
		CustomKeyboardMouseMappings[_abstract_button_stop_continue_playback_theater_v6].VirtualKeyCodes[0] = VK_RETURN;
		CustomKeyboardMouseMappings[_abstract_button_playback_speed_up_theater_v6].VirtualKeyCodes[0] = VK_LMENU;
		CustomKeyboardMouseMappings[_abstract_button_enter_free_camera_mode_theater_v6].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_movement_speed_up_theater_v6].VirtualKeyCodes[0] = VK_LSHIFT;
		CustomKeyboardMouseMappings[_abstract_button_panning_camera_theater_v6].VirtualKeyCodes[0] = VK_OEM_RESET;
		CustomKeyboardMouseMappings[_abstract_button_camera_move_up_theater_v6].VirtualKeyCodes[0] = 'Q';
		CustomKeyboardMouseMappings[_abstract_button_camera_move_down_theater_v6].VirtualKeyCodes[0] = 'E';
		CustomKeyboardMouseMappings[_abstract_button_dual_wield_v6].VirtualKeyCodes[0] = 'Q';
		CustomKeyboardMouseMappings[_abstract_button_zoom_camera_theater_v6].VirtualKeyCodes[0] = VK_OEM_RESET;
	}

	for (long abstract_button_index = 0; abstract_button_index < player_configuration.abstract_button_count; abstract_button_index++)
	{
		read_custom_key_mapping_from_config(abstract_button_index, CustomKeyboardMouseMappings, CustomKeyboardMouseMappings[abstract_button_index]);
	}
}

#undef read_control_from_config
#undef write_control_to_config
#undef read_custom_key_mapping_from_config
#undef write_custom_key_mapping_to_config
#pragma warning(default:4244)
#pragma warning(default:4305)