#pragma once
#include "gmlib/Macros.h"
#include "ll/api/base/FixedString.h"
#include "ll/api/utils/SystemUtils.h"
#include <mc/deps/core/utility/optional_ref.h>
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
    GMLIB_API static void chooseLanguage(std::string const& languageCode);

    GMLIB_API static void chooseLanguage(::Localization const& localization);

    GMLIB_NDAPI static std::weak_ptr<Localization> getCurrentLanguage();

    GMLIB_NDAPI static std::string getCurrentLanguageCode();

    GMLIB_NDAPI static std::vector<std::string> getSupportedLanguageCodes();

    GMLIB_NDAPI static std::optional<std::string> tryGet(
        std::string const&              key,
        std::vector<std::string> const& params       = {},
        std::string const&              languageCode = getCurrentLanguageCode()
    );

    GMLIB_NDAPI static std::optional<std::string> tryGet(
        std::string const&              key,
        std::vector<std::string> const& params,
        std::shared_ptr<::Localization> localization
    );

    GMLIB_NDAPI static std::string
    get(std::string const&              key,
        std::vector<std::string> const& params       = {},
        std::string const&              languageCode = getCurrentLanguageCode());

    GMLIB_NDAPI static std::string
    get(std::string const& key, std::vector<std::string> const& params, std::shared_ptr<::Localization> localization);

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
    GMLIB_API static void
    loadLanguage(std::string const& languageCode, std::unordered_map<std::string, std::string> const& language);

    GMLIB_API static void loadLanguage(std::string const& languageCode, i18n::McLang const& language);

    GMLIB_API static void loadLanguage(std::string const& languageCode, nlohmann::json const& language);

    GMLIB_API static void loadLanguageFromFile(std::string const& languageCode, std::filesystem::path const& path);

    GMLIB_API static void loadLanguageFromResource(
        std::string const&            languageCode,
        int                           resourceId,
        ll::utils::sys_utils::HandleT handle = ll::sys_utils::getCurrentModuleHandle()
    );

    GMLIB_API static void updateOrCreateLanguageFile(
        std::filesystem::path const& path,
        std::string const&           languageCode,
        std::string const&           language
    );

    GMLIB_API static void updateOrCreateLanguageFile(
        std::filesystem::path const& path,
        std::string const&           languageCode,
        i18n::McLang const&          language
    );

    GMLIB_API static void updateOrCreateLanguageFile(
        std::filesystem::path const&                        path,
        std::string const&                                  languageCode,
        std::unordered_map<std::string, std::string> const& language
    );

    GMLIB_API static void updateOrCreateLanguageFile(
        std::filesystem::path const& path,
        std::string const&           languageCode,
        nlohmann::json const&        language
    );

    GMLIB_API static void loadLanguagesFromDirectory(std::filesystem::path const& path);
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

} // namespace literals

} // namespace gmlib