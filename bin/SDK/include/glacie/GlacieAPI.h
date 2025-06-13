#pragma once
#include <filesystem>
#include <gmlib/Macros.h>
#include <ll/api/Expected.h>
#include <ll/api/data/Version.h>
#include <mc/world/actor/player/Player.h>

namespace glacie {

GMLIB_NDAPI ll::Expected<int> getClientProtocolVersion(NetworkIdentifier const& netId);

GMLIB_NDAPI ll::Expected<ll::data::Version> getClientVersion(NetworkIdentifier const& netId);

GMLIB_NDAPI ll::Expected<std::string> getClientVersionString(NetworkIdentifier const& netId);

GMLIB_NDAPI ll::Expected<bool> isSupportedProtocol(int protocol);

GMLIB_NDAPI ll::Expected<bool> isAllowIncomingProtocol(int protocol);

GMLIB_NDAPI ll::Expected<bool> setProtocolAllowIncoming(int protocol, bool status);

GMLIB_NDAPI ll::Expected<std::vector<int>> getSupportedProtocolList();

GMLIB_NDAPI ll::Expected<std::vector<int>> getAllowIncomingProtocolList();

GMLIB_NDAPI ll::Expected<ll::data::Version> getGlacieVersion();

GMLIB_NDAPI ll::Expected<ll::data::Version> getProtocolLibVersion();

GMLIB_NDAPI ll::Expected<std::filesystem::path> getProtocolLibPath();

GMLIB_NDAPI ll::Expected<bool> enable();

GMLIB_NDAPI ll::Expected<bool> disable();

} // namespace glacie