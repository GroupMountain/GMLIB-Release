#pragma once
#include <gmlib/gm/i18n/base/LangLanguage.h>
#include <gmlib/gm/papi/PlaceholderAPI.h>
#include <ll/api/base/FixedString.h>
#include <ll/api/utils/SystemUtils.h>
#include <memory>

namespace gmlib::i18n {

class LangI18n {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_NDAPI LangI18n(std::filesystem::path const& languageDirectory, std::string const& languageCode = "en_US");

    LangI18n() = delete;

public:
    GMLIB_API virtual ~LangI18n();

public:
    GMLIB_API bool updateOrCreateLanguage(std::string const& languageCode, std::string const& language);

    GMLIB_API bool updateOrCreateLanguage(std::string const& languageCode, McLang const& language);

    GMLIB_API bool updateOrCreateLanguage(
        std::string const&            languageCode,
        int                           resourceId,
        ll::utils::sys_utils::HandleT handle = ll::sys_utils::getCurrentModuleHandle()
    );

    GMLIB_API bool loadAllLanguages();

    GMLIB_API void reloadAllLanguages();

    GMLIB_API bool chooseLanguage(std::string const& languageCode = "en_US");

    GMLIB_API void setDefaultLanguage(std::string const& languageCode = "en_US");

    GMLIB_NDAPI std::string
    translate(std::string const& key, std::vector<std::string> const& params = {}, std::string const& data = "%0$s");

    template <typename... Args>
    [[nodiscard]] std::string tr(std::string const& key, Args&&... args) {
        std::vector<std::string> params;
        (params.push_back(fmt::format("{}", std::forward<Args>(args))), ...);
        return get(key, params);
    }

    template <typename... Args>
    [[nodiscard]] std::string trl(std::string const& key, std::string const& languageCode, Args&&... args) {
        std::vector<std::string> params;
        (params.push_back(fmt::format("{}", std::forward<Args>(args))), ...);
        return get(key, languageCode, params);
    }

    GMLIB_NDAPI std::string translate(
        std::string const&              key,
        std::string const&              localLanguage,
        std::vector<std::string> const& params = {},
        std::string const&              data   = "%0$s"
    );

    GMLIB_NDAPI std::string
    get(std::string const& key, std::vector<std::string> const& params = {}, std::string const& data = "%0$s");

    GMLIB_NDAPI std::string
                get(std::string const&              key,
                    std::string const&              localLanguage,
                    std::vector<std::string> const& params = {},
                    std::string const&              data   = "%0$s");

private:
    bool loadOrCreateLanguage(std::string const& languageCode, std::shared_ptr<LangLanguage> language);
};

} // namespace gmlib::i18n

#define GMLIB_LANGI18N_LITERALS(i18nInstance)                                                                          \
    template <::ll::FixedString Fmt>                                                                                   \
    [[nodiscard]] constexpr auto operator""_tr() {                                                                     \
        return [=]<class... Args>(Args&&... args) { return i18nInstance.tr(Fmt.str(), args...); };                     \
    }                                                                                                                  \
    template <::ll::FixedString Fmt>                                                                                   \
    [[nodiscard]] constexpr auto operator""_trl() {                                                                    \
        return [=]<class... Args>(std::string const& languageCode, Args&&... args) {                                   \
            return i18nInstance.trl(Fmt.str(), languageCode, args...);                                                 \
        };                                                                                                             \
    }                                                                                                                  \
    template <::ll::FixedString Fmt>                                                                                   \
    [[nodiscard]] constexpr auto operator""_trp() {                                                                    \
        return [=]<class... Args>(optional_ref<Actor> actor, Args&&... args) {                                         \
            return gmlib::PlaceholderAPI::translate(i18nInstance.tr(Fmt.str(), args...), actor);                       \
        };                                                                                                             \
    }                                                                                                                  \
    template <::ll::FixedString Fmt>                                                                                   \
    [[nodiscard]] constexpr auto operator""_trlp() {                                                                   \
        return [=]<class... Args>(std::string const& languageCode, optional_ref<Actor> actor, Args&&... args) {        \
            return gmlib::PlaceholderAPI::translate(i18nInstance.trl(Fmt.str(), languageCode, args...), actor);        \
        };                                                                                                             \
    }