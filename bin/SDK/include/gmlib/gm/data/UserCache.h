#pragma once
#include "gmlib/Macros.h"
#include "ll/api/Expected.h"
#include "ll/api/coro/Generator.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/platform/UUID.h"


namespace gmlib {
class UserCache {
    struct Impl;
    std::unique_ptr<Impl> pimpl;
    explicit UserCache(std::unique_ptr<Impl>&&);

public:
    UserCache()                 = delete;
    UserCache(UserCache&&)      = delete;
    UserCache(const UserCache&) = delete;

    struct UserCacheEntry {
        mce::UUID     mUuid;
        std::string   mName;
        std::string   mXuid;
        std::string   mServerId;
        ActorUniqueID mActorUniqueID = ActorUniqueID::INVALID_ID();
    };
    struct QueryType : std::bitset<sizeof(int)> {
        using std::bitset<sizeof(int)>::bitset;
        static LL_CONSTEXPR23 std::bitset<sizeof(int)> Name{1 << 0};
        static LL_CONSTEXPR23 std::bitset<sizeof(int)> Xuid{1 << 1};
        static LL_CONSTEXPR23 std::bitset<sizeof(int)> ServerId{1 << 2};
        static LL_CONSTEXPR23 std::bitset<sizeof(int)> Default = {Name | Xuid | ServerId};
        LL_CONSTEXPR23 QueryType(std::bitset<sizeof(int)> val) /*NOLINT*/ : std::bitset<sizeof(int)>(val) {}
    };

public:
    GMLIB_API ~UserCache();

    GMLIB_NDAPI optional_ref<UserCacheEntry const> from(mce::UUID uuid);

    GMLIB_NDAPI optional_ref<UserCacheEntry const> from(ActorUniqueID actorUniqueID);

    GMLIB_NDAPI optional_ref<UserCacheEntry const> from(std::string const& key, QueryType type);

    GMLIB_NDAPI ll::coro::Generator<UserCacheEntry const&> entries();

    GMLIB_API ll::Expected<void> add(const std::shared_ptr<UserCacheEntry>& entry);

    GMLIB_API ll::Expected<void>
    add(mce::UUID uuid, std::string name, std::string xuid, std::string serverId, ActorUniqueID actorUniqueID);

    GMLIB_API ll::Expected<void> remove(mce::UUID uuid);

    GMLIB_API ll::Expected<void> remove(ActorUniqueID actorUniqueID);

    GMLIB_API
    ll::Expected<void> remove(std::string const& key, QueryType type = {QueryType::Default});

    GMLIB_NDAPI static optional_ref<UserCache> getInstance();
};
} // namespace gmlib

template <typename CharT>
struct std::formatter<gmlib::UserCache::UserCacheEntry, CharT> : std::formatter<std::string, CharT> {
    template <class FormatContext>
    auto format(gmlib::UserCache::UserCacheEntry const& cache, FormatContext& ctx) const {
        std::string res = format(
            "uuid:{} name:{} xuid:{} serverId:{} actorUniqueID:{}",
            cache.mUuid.asString(),
            cache.mName,
            cache.mXuid,
            cache.mServerId,
            cache.mActorUniqueID.rawID
        );
        return formatter<std::string>::format(res, ctx);
    }
};

template <typename CharT>
struct fmt::formatter<gmlib::UserCache::UserCacheEntry, CharT> : fmt::formatter<std::string, CharT> {
    template <class FormatContext>
    auto format(gmlib::UserCache::UserCacheEntry const& cache, FormatContext& ctx) const {
        std::string res = fmt::format(
            "uuid:{} name:{} xuid:{} serverId:{} actorUniqueID:{}",
            cache.mUuid.asString(),
            cache.mName,
            cache.mXuid,
            cache.mServerId,
            cache.mActorUniqueID.rawID
        );
        return formatter<std::string>::format(res, ctx);
    }
};