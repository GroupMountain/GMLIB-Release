#pragma once
#include "gmlib/Macros.h"
#include "gmlib/gm/utils/FlagEnum.h"
#include "ll/api/Expected.h"
#include "ll/api/coro/Generator.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/platform/UUID.h"


namespace gmlib {
class UserCache;
using QueryType = FlagEnum<std::uint16_t, UserCache>;
class UserCache {
    struct Impl;
    std::unique_ptr<Impl> pimpl;
    UserCache();

public:
    UserCache(UserCache&&)      = delete;
    UserCache(const UserCache&) = delete;

    struct UserCacheEntry {
        mce::UUID     mUuid;
        std::string   mName;
        std::string   mXuid;
        std::string   mServerId;
        ActorUniqueID mActorUniqueID = ActorUniqueID::INVALID_ID();
    };

    ~UserCache();

public:
    GMLIB_NDAPI optional_ref<UserCacheEntry const> from(mce::UUID uuid);

    GMLIB_NDAPI optional_ref<UserCacheEntry const> from(ActorUniqueID actorUniqueID);

    GMLIB_NDAPI ll::coro::Generator<UserCacheEntry const&> entries();

    GMLIB_API ll::Expected<void> add(const std::shared_ptr<UserCacheEntry>& entry);

    GMLIB_API ll::Expected<void>
    add(mce::UUID uuid, std::string name, std::string xuid, std::string serverId, ActorUniqueID actorUniqueID);

    GMLIB_API ll::Expected<void> remove(mce::UUID uuid);

    GMLIB_API ll::Expected<void> remove(ActorUniqueID actorUniqueID);

    /***
    @details if you want use UserCache, please call it before first player enters server.
     */
    GMLIB_NDAPI static optional_ref<UserCache> getInstance();

    static inline LL_CONSTEXPR23 ::gmlib::QueryType Name{1 << 0};
    static inline LL_CONSTEXPR23 ::gmlib::QueryType Xuid{1 << 1};
    static inline LL_CONSTEXPR23 ::gmlib::QueryType ServerId{1 << 2};
    static inline LL_CONSTEXPR23 ::gmlib::QueryType ActorUniqueID{1 << 3};
    static inline LL_CONSTEXPR23 ::gmlib::QueryType Uuid{1 << 4};
    static inline LL_CONSTEXPR23 ::gmlib::QueryType Default{Name | Xuid | ServerId};
    static inline LL_CONSTEXPR23 ::gmlib::QueryType All{Name | Xuid | ServerId | ActorUniqueID | Uuid};

    GMLIB_NDAPI optional_ref<UserCacheEntry const> from(std::string_view key, const ::gmlib::QueryType& type = Default);
    GMLIB_API
    ll::Expected<void> remove(std::string_view key, const ::gmlib::QueryType& type = {Default});
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