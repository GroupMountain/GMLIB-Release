#pragma once
#include "gmlib/Macros.h"
#include "ll/api/Expected.h"
#include "mc/deps/core/utility/BinaryStream.h"
#include "mc/world/actor/player/Player.h"

namespace glacie {

GMLIB_NDAPI ll::Expected<int> getClientProtocolVersion(NetworkIdentifier const& netId);

GMLIB_NDAPI ll::Expected<std::vector<int>> getSupportedProtocolList();

[[deprecated("will be deleted at bds 1.21.7x version")]] GMLIB_API ll::Expected<void> translateBinaryStream(BinaryStream& stream, int toVersion);

} // namespace glacie