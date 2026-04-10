#pragma once
#include "mc/deps/core/math/Vec3.h"
#include "mc/deps/nbt/CompoundTag.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/platform/UUID.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/level/dimension/Dimension.h"


namespace gmlib {

class OfflinePlayer {

protected:
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    explicit OfflinePlayer(mce::UUID const& uuid, std::string const& serverId);

    OfflinePlayer(OfflinePlayer&& other) noexcept;

    ~OfflinePlayer();

public:
    // It will contain online players.
    // isOffline: Whether the server.properties chioce "online-mode" is true
    static std::vector<OfflinePlayer> getAllOfflinePlayers(bool isOnlineMode = true);

    // It maybe can't get a existing player if the UuidDBTag is missing
    // (waiting for verification, it's not a clear aphenomenon)
    static std::optional<OfflinePlayer> fromUuid(mce::UUID const& uuid);
    static std::optional<OfflinePlayer> fromServerId(std::string const& serverId);
    static std::optional<OfflinePlayer> fromActorUniqueId(ActorUniqueID const& uniqueId);

    // Some static delete ways
    // Waring:
    // If having a instance of OfflinePlayer, please always prefer using OfflinePlayer::remove().
    // Otherwise, the instance may cause some ub.
    // If using deletePlayer(), the serverId will reset.
    static bool deletePlayer(mce::UUID const& uuid);

    static bool deletePlayerNbt(mce::UUID const& uuid);

    static bool deletePlayerNbt(std::string const& serverId);

    // Using this to create a new player tag in leveldb
    // If existing, return the existing OfflinePlayer, and the serverId will be existing one
    // If serverId is empty, the serverId will be generated randomly
    // If return nullopt, the player is created faild
    static std::optional<OfflinePlayer>
    createNewPlayerNbt(mce::UUID const& uuid, CompoundTag& nbt, bool isOnlineMode = true, std::string serverId = {});
    // callback: return true to continue

    static void forEachOfflinePlayer(std::function<bool(OfflinePlayer&&)>&& func, bool isOnlineMode = true);

public:
    std::string getServerId() const;

    mce::UUID getUUID() const;

    // Warning: this maybe a nullptr because some player only has uuid and serverid
    // If nullptr, all the following optional is nullopt, amd auid is ActorUniqueID::INVALID_ID()
    // If nullptr, you are suggested to use setNbt() to create a new nbt(should be a valid player nbt)
    ll::Expected<CompoundTag> getNbt() const;

    ActorUniqueID getActorUniqueID() const;

    std::optional<std::pair<Vec3, DimensionType>> getPlayerPosition() const;

    optional_ref<Player> getPlayer() const;

    bool isValid() const;

    bool hasNbt() const;

public:
    // If doesn't have a nbt, will create a new nbt
    bool setNbt(CompoundTag& nbt);
    bool setPosition(Vec3 const& pos, DimensionType dim);

    // delete the player in leveldb
    // Warning: If using remove(), the serverId will reset
    bool remove();
    bool removeNbt();
};

} // namespace gmlib