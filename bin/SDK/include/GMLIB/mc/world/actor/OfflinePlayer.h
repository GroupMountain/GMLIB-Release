#pragma once
#include "gmlib/Macros.h"
#include "gmlib/mc/world/Level.h"
#include "mc/deps/core/math/Vec3.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/nbt/CompoundTag.h"
#include "mc/platform/UUID.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/level/dimension/Dimension.h"


namespace gmlib {

class OfflinePlayer {

protected:
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_NDAPI explicit OfflinePlayer(mce::UUID const& uuid, std::string const& serverId);

    GMLIB_API OfflinePlayer(OfflinePlayer&& other);

    GMLIB_API ~OfflinePlayer();

public:
    // It will contain online players.
    // isOffline: Whether the server.properties chioce "online-mode" is true
    GMLIB_NDAPI static std::vector<OfflinePlayer> getAllOfflinePlayers(bool isOnlineMode = true);
    // It maybe can't get a existing player if the UuidDBTag is missing
    // (waiting for verification, it's not a clear aphenomenon)
    GMLIB_NDAPI static std::optional<OfflinePlayer> getOfflinePlayer(mce::UUID const& uuid);

    GMLIB_NDAPI static std::optional<OfflinePlayer> getOfflinePlayer(std::string const& serverId);
    // Some static delete ways
    // Waring:
    // If having a instance of OfflinePlayer, please always prefer using OfflinePlayer::remove().
    // Otherwise, the instance may cause some ub.
    // If using deletePlayer(), the serverId will reset.
    GMLIB_API static bool deletePlayer(mce::UUID const& uuid);

    GMLIB_API static bool deletePlayerNbt(mce::UUID const& uuid);

    GMLIB_API static bool deletePlayerNbt(std::string const& serverId);

    // Using this to create a new player tag in leveldb
    // If existing, return the existing OfflinePlayer, and the serverId will be existing one
    // If serverId is empty, the serverId will be generated randomly
    // If return nullopt, the player is created faild
    GMLIB_API static std::optional<OfflinePlayer>
    createNewPlayerNbt(mce::UUID const& uuid, CompoundTag& nbt, bool isOnlineMode = true, std::string serverId = {});
    // callback: return true to continue

    GMLIB_API static void foreachOfflinePlayer(std::function<bool(OfflinePlayer&)>&& func, bool isOnlineMode = true);

public:
    GMLIB_NDAPI std::string getServerId() const;

    GMLIB_NDAPI mce::UUID getUUID() const;

    // Warning: this maybe a nullptr because some player only has uuid and serverid
    // If nullptr, all the following optional is nullopt, amd auid is ActorUniqueID::INVALID_ID()
    // If nullptr, you are suggested to use setNbt() to create a new nbt(should be a valid player nbt)
    GMLIB_NDAPI ll::Expected<CompoundTag> getNbt() const;

    GMLIB_NDAPI ActorUniqueID getActorUniqueID() const;

    GMLIB_NDAPI std::optional<std::pair<Vec3, DimensionType>> getPlayerPosition() const;

    GMLIB_NDAPI optional_ref<Player> getPlayer() const;

    GMLIB_NDAPI bool isValid() const;

    GMLIB_NDAPI bool hasNbt() const;

public:
    // If doesn't have a nbt, will create a new nbt
    GMLIB_API bool setNbt(CompoundTag& nbt);
    GMLIB_API bool setPosition(Vec3 const& pos, DimensionType dim);

    // delete the player in leveldb
    // Warning: If using remove(), the serverId will reset
    GMLIB_API bool remove();
    GMLIB_API bool removeNbt();
};

} // namespace gmlib