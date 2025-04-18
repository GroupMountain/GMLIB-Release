#pragma once
#include "gmlib/Macros.h"
#include "ll/api/coro/Generator.h"
#include "mc/platform/UUID.h"

namespace gmlib::UserCache {

struct UserCacheEntry {
    mce::UUID   mUuid;
    std::string mName;
    std::string mXuid;
};

GMLIB_NDAPI optional_ref<UserCacheEntry const> fromUuid(mce::UUID uuid);

GMLIB_NDAPI optional_ref<UserCacheEntry const> fromName(std::string const& name);

GMLIB_NDAPI optional_ref<UserCacheEntry const> fromXuid(std::string const& xuid);

GMLIB_NDAPI std::optional<std::string> getXuidByUuid(mce::UUID const& uuid);

GMLIB_NDAPI std::optional<std::string> getNameByUuid(mce::UUID const& uuid);

GMLIB_NDAPI std::optional<mce::UUID> getUuidByXuid(std::string const& xuid);

GMLIB_NDAPI std::optional<std::string> getNameByXuid(std::string const& xuid);

GMLIB_NDAPI std::optional<std::string> getXuidByName(std::string const& name);

GMLIB_NDAPI std::optional<mce::UUID> getUuidByName(std::string const& name);

GMLIB_NDAPI ll::coro::Generator<UserCacheEntry const&> entries();

GMLIB_API void add(std::shared_ptr<UserCacheEntry> entry);

GMLIB_API void add(mce::UUID uuid, std::string name, std::string xuid);

GMLIB_API void remove(mce::UUID uuid);

GMLIB_API void remove(std::string const& nameOrXuid);

} // namespace gmlib::UserCache