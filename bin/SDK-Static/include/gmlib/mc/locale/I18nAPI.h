#pragma once
#if __has_include(<gmlib/gm/papi/PlaceholderAPI.h>)
#include <gmlib/gm/papi/PlaceholderAPI.h>
#endif
#include <ll/api/base/FixedString.h>
#include <ll/api/utils/SystemUtils.h>
#include <mc/deps/core/utility/optional_ref.h>
#include <mc/world/actor/Actor.h>
#include <nlohmann/json.hpp>

class Localization;
namespace gmlib::i18n {
class McLang;
}

/*
    Attetion!
    This file's API is to get mc vanilla i18n
    Not recommended for use in custom mod
    Mod's i18n is suggested to use the class in gmlib/gm/i18n
*/


namespace gmlib {

class I18nAPI {
private:
    I18nAPI()                          = delete;
    ~I18nAPI()                         = delete;
    I18nAPI(I18nAPI const&)            = delete;
    I18nAPI(I18nAPI&&)                 = delete;
    I18nAPI& operator=(I18nAPI const&) = delete;
    I18nAPI& operator=(I18nAPI&&)      = delete;

public:
    static void chooseLanguage(std::string const& languageCode);

    static void chooseLanguage(::Localization const& localization);

    static std::weak_ptr<Localization> getCurrentLanguage();

    static std::string getCurrentLanguageCode();

    static std::vector<std::string> getSupportedLanguageCodes();

    static std::optional<std::string> tryGet(
        std::string const&              key,
        std::vector<std::string> const& params       = {},
        std::string const&              languageCode = getCurrentLanguageCode()
    );

    static std::optional<std::string> tryGet(
        std::string const&                     key,
        std::vector<std::string> const&        params,
        const std::shared_ptr<::Localization>& localization
    );

    static std::string
    get(std::string const&              key,
        std::vector<std::string> const& params       = {},
        std::string const&              languageCode = getCurrentLanguageCode());

    static std::string
    get(std::string const&                     key,
        std::vector<std::string> const&        params,
        const std::shared_ptr<::Localization>& localization);

    template <typename... Args>
    [[nodiscard]] static std::string tr(std::string const& key, Args&&... args) {
        std::vector<std::string> params;
        (params.push_back(fmt::format("{}", std::forward<Args>(args))), ...);
        return get(key, params);
    }

    template <typename... Args>
    [[nodiscard]] static std::string trl(std::string const& key, std::string const& languageCode, Args&&... args) {
        std::vector<std::string> params;
        (params.push_back(fmt::format("{}", std::forward<Args>(args))), ...);
        return get(key, params, languageCode);
    }

public:
    static void
    loadLanguage(std::string const& languageCode, std::unordered_map<std::string, std::string> const& language);

    static void loadLanguage(std::string const& languageCode, i18n::McLang const& language);

    static void loadLanguage(std::string const& languageCode, nlohmann::json const& language);

    static void loadLanguageFromFile(std::string const& languageCode, std::filesystem::path const& path);

    static void loadLanguageFromResource(
        std::string const&            languageCode,
        int                           resourceId,
        ll::utils::sys_utils::HandleT handle = ll::sys_utils::getCurrentModuleHandle()
    );

    static void updateOrCreateLanguageFile(
        std::filesystem::path const& path,
        std::string const&           languageCode,
        std::string const&           language
    );

    static void updateOrCreateLanguageFile(
        std::filesystem::path const& path,
        std::string const&           languageCode,
        i18n::McLang const&          language
    );

    static void updateOrCreateLanguageFile(
        std::filesystem::path const&                        path,
        std::string const&                                  languageCode,
        std::unordered_map<std::string, std::string> const& language
    );

    static void updateOrCreateLanguageFile(
        std::filesystem::path const& path,
        std::string const&           languageCode,
        nlohmann::json const&        language
    );

    static void loadLanguagesFromDirectory(std::filesystem::path const& path);
};

namespace literals {

template <::ll::FixedString Fmt>
[[nodiscard]] constexpr auto operator""_trans() {
    return [=]<class... Args>(Args&&... args) { return I18nAPI::tr(Fmt.str(), args...); };
}

template <::ll::FixedString Fmt>
[[nodiscard]] constexpr auto operator""_transl() {
    return [=]<class... Args>(std::string const& languageCode, Args&&... args) {
        return I18nAPI::trl(Fmt.str(), languageCode, args...);
    };
}

#if __has_include(<gmlib/gm/papi/PlaceholderAPI.h>)

template <::ll::FixedString Fmt>
[[nodiscard]] constexpr auto operator""_transp() {
    return [=]<class... Args>(optional_ref<Actor> actor, Args&&... args) {
        return gmlib::PlaceholderAPI::getInstance().translate(I18nAPI::tr(Fmt.str(), args...), actor);
    };
}

template <::ll::FixedString Fmt>
[[nodiscard]] constexpr auto operator""_translp() {
    return [=]<class... Args>(std::string const& languageCode, optional_ref<Actor> actor, Args&&... args) {
        return gmlib::PlaceholderAPI::getInstance().translate(I18nAPI::trl(Fmt.str(), languageCode, args...), actor);
    };
}

#endif

} // namespace literals

} // namespace gmlib