#pragma once

#include "FileSystem/FileSystem.h"
#include "MCC/MCC.h"
#include "ApplicationReflection/ApplicationReflection.h"
#include "RuntimeManipulation/RuntimeManipulation.h"
#include "is_valid.h"
#include "platform_configuration.h"
#include "session_manager.h"

#define DISCORD_DISABLE_IO_THREAD
#include <discord_rpc.h>

#pragma comment(lib, "discord-rpc.lib")

#include "Presense/presense_info.h"
#include "Presense/presense_api.h"
#include "Presense/discord_presense_api.h"
