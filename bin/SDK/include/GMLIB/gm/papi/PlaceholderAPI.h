#pragma once
#include "gmlib/Macros.h"
#include "gmlib/mc/locale/I18nAPI.h"
#include <ll/api/mod/NativeMod.h>
#include <mc/deps/core/utility/optional_ref.h>
#include <optional>
#include <string>


namespace gmlib::world::actor {
class GMActor;
}

namespace gmlib::papi {
class PlaceholderAPI {
public:
    PlaceholderAPI()                                 = delete;
    PlaceholderAPI(PlaceholderAPI const&)            = delete;
    PlaceholderAPI& operator=(PlaceholderAPI const&) = delete;
    PlaceholderAPI(PlaceholderAPI&&)                 = delete;
    PlaceholderAPI& operator=(PlaceholderAPI&&)      = delete;

public:
    using GMActor = world::actor::GMActor;
    using I18nAPI = locale::I18nAPI;
    struct PlaceholderData {
        std::weak_ptr<ll::mod::Mod> mod;
        std::function<std::optional<std::string>(
            optional_ref<GMActor>                               actor,
            std::unordered_map<std::string, std::string> const& params,
            std::string const&                                  language
        )>
            callback;
    };

public:
    GMLIB_API static std::string& translate(
        std::string&          value,
        optional_ref<GMActor> actor,
        std::string           language = I18nAPI::getCurrentLanguageCode()
    );

    GMLIB_API static std::string translate(
        std::string const&    value,
        optional_ref<GMActor> actor,
        std::string           language = I18nAPI::getCurrentLanguageCode()
    );

    GMLIB_API static bool registerPlaceholder(
        std::string const&          placeholder,
        std::function<std::optional<std::string>(
            optional_ref<GMActor>                               actor,
            std::unordered_map<std::string, std::string> const& params,
            std::string const&                                  language
        )>                          callback,
        std::weak_ptr<ll::mod::Mod> mod = ll::mod::NativeMod::current()
    );

    GMLIB_API static bool registerPlaceholder(
        std::string const& placeholder,
        std::optional<std::string> (*callback)(
            optional_ref<GMActor>                               actor,
            std::unordered_map<std::string, std::string> const& params,
            std::string const&                                  language
        ),
        std::weak_ptr<ll::mod::Mod> mod = ll::mod::NativeMod::current()
    );

    GMLIB_API static bool unregisterPlaceholder(std::string const& placeholder);

    GMLIB_API static bool unregisterPlaceholder(std::weak_ptr<ll::mod::Mod> mod);

    GMLIB_NDAPI static std::optional<std::string> getValue(
        std::string const&                                  placeholder,
        optional_ref<GMActor>                               actor    = std::nullopt,
        std::unordered_map<std::string, std::string> const& params   = {},
        std::string const&                                  language = I18nAPI::getCurrentLanguageCode()
    );

    GMLIB_NDAPI static std::optional<PlaceholderData> getPlaceholderData(std::string const& placeholder);

    GMLIB_NDAPI static std::unordered_map<std::string, PlaceholderData> getAllPlaceholderData();

    GMLIB_NDAPI static std::unordered_map<std::string, PlaceholderData>
    getAllPlaceholderData(std::weak_ptr<ll::mod::Mod> mod);
};

} // namespace gmlib::papi