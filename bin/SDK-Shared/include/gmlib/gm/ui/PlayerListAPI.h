#pragma once
#include "gmlib/Macros.h"
#include "gmlib/gm/enum/PlayerListType.h"
#include "mc/server/commands/PlayerPermissionLevel.h"
#include <mc/platform/UUID.h>

class ActorUniqueID;
class PlayerListEntry;


namespace gmlib::ui::PlayerListAPI {

GMLIB_API void setType(PlayerListType type);

// The following func is dynamic and will effect the players who are already online
// Warning: The PlayerListType::Bottom type is not supported to dynamicly change
GMLIB_API void push_back(
    std::string const&    name,
    std::string const&    xuid,
    mce::UUID const&      uuid       = mce::UUID::random(),
    PlayerPermissionLevel permission = PlayerPermissionLevel::Member
);

GMLIB_API bool erase(std::string const& nameOrXuid);

GMLIB_API void clear();

// Use this to get the entries vector reference
// If it changed, it would only effect the players who login in the future
// —— It can't change the show of the players who are already online
GMLIB_NDAPI std::vector<PlayerListEntry>& getFakeEntrys();

// Use this to replace a real player's name in the player list
GMLIB_API void setReplacedName(std::string const& realName, std::string const& fakeName);

GMLIB_API bool resetListName(std::string const& realName);

// Use this to get the map of the replaced maps
GMLIB_NDAPI std::unordered_map<std::string, std::string>& getReplaceMap();

} // namespace gmlib::ui::PlayerListAPI