#pragma once
#include <ll/api/Expected.h>
#include <ll/api/data/Version.h>
#include <mc/world/actor/player/Player.h>

namespace glacie {

ll::Expected<int> getClientProtocolVersion(NetworkIdentifier const& netId);

ll::Expected<ll::data::Version> getClientVersion(NetworkIdentifier const& netId);

ll::Expected<std::string> getClientVersionString(NetworkIdentifier const& netId);

ll::Expected<bool> isSupportedProtocol(int protocol);

ll::Expected<bool> isAllowIncomingProtocol(int protocol);

ll::Expected<bool> setProtocolAllowIncoming(int protocol, bool status);

ll::Expected<std::vector<int>> getSupportedProtocolList();

ll::Expected<std::vector<int>> getAllowIncomingProtocolList();

ll::Expected<ll::data::Version> getGlacieVersion();

ll::Expected<ll::data::Version> getProtocolLibVersion();

ll::Expected<std::filesystem::path> getProtocolLibPath();

ll::Expected<bool> enable();

ll::Expected<bool> disable();

} // namespace glacie