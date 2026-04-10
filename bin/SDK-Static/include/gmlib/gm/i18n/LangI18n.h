#pragma once
#include <gmlib/gm/i18n/base/LangLanguage.h>
#if __has_include(<gmlib/gm/papi/PlaceholderAPI.h>)
#include <gmlib/gm/papi/PlaceholderAPI.h>
#endif
#include <ll/api/base/FixedString.h>
#include <ll/api/utils/SystemUtils.h>
#include <memory>

namespace gmlib::i18n {

class LangI18n {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    explicit LangI18n(std::filesystem::path const& languageDirectory, std::string const& languageCode = "en_US");

    LangI18n() = delete;

public:
    virtual ~LangI18n();

public:
    bool updateOrCreateLanguage(std::string const& languageCode, std::string const& language);

    bool updateOrCreateLanguage(std::string const& languageCode, McLang const& language);

    bool updateOrCreateLanguage(
        std::string const&            languageCode,
        int                           resourceId,
        ll::utils::sys_utils::HandleT handle = ll::sys_utils::getCurrentModuleHandle()
    );

    bool loadAllLanguages();

    void reloadAllLanguages();

    bool chooseLanguage(std::string const& languageCode = "en_US");

    void setDefaultLanguage(std::string const& languageCode = "en_US");

    std::string
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

    std::string translate(
        std::string const&              key,
        std::string const&              localLanguage,
        std::vector<std::string> const& params = {},
        std::string const&              data   = "%0$s"
    );

    std::string
    get(std::string const& key, std::vector<std::string> const& params = {}, std::string const& data = "%0$s");

    std::string
    get(std::string const&              key,
        std::string const&              localLanguage,
        std::vector<std::string> const& params = {},
        std::string const&              data   = "%0$s");

private:
    bool loadOrCreateLanguage(std::string const& languageCode, const std::shared_ptr<LangLanguage>& language);
};

} // namespace gmlib::i18n

#if __has_include(<gmlib/gm/papi/PlaceholderAPI.h>)
#define GMLIB_LANGI18N_LITERALS_PAPI(i18nInstance)                                                                     \
    template <::ll::FixedString Fmt>                                                                                   \
    [[nodiscard]] constexpr auto operator""_trp() {                                                                    \
        return [=]<class... Args>(optional_ref<Actor> actor, Args&&... args) {                                         \
            return gmlib::PlaceholderAPI::getInstance().translate(i18nInstance.tr(Fmt.str(), args...), actor);         \
        };                                                                                                             \
    }                                                                                                                  \
    template <::ll::FixedString Fmt>                                                                                   \
    [[nodiscard]] constexpr auto operator""_trlp() {                                                                   \
        return [=]<class... Args>(std::string const& languageCode, optional_ref<Actor> actor, Args&&... args) {        \
            return gmlib::PlaceholderAPI::getInstance().translate(                                                     \
                i18nInstance.trl(Fmt.str(), languageCode, args...),                                                    \
                actor                                                                                                  \
            );                                                                                                         \
        };                                                                                                             \
    }
#else
#define GMLIB_LANGI18N_LITERALS_PAPI(i18nInstance)
#endif

#define GMLIB_LANGI18N_LITERALS(i18nInstance)                                                                          \
    template <::ll::FixedString Fmt>                                                                                   \
    [[nodiscard]] constexpr auto operator""_tr() {                                                                     \
        return [=]<class... Args>(Args&&... args) { return (i18nInstance).tr(Fmt.str(), args...); };                   \
    }                                                                                                                  \
    template <::ll::FixedString Fmt>                                                                                   \
    [[nodiscard]] constexpr auto operator""_trl() {                                                                    \
        return [=]<class... Args>(std::string const& languageCode, Args&&... args) {                                   \
            return (i18nInstance).trl(Fmt.str(), languageCode, args...);                                               \
        };                                                                                                             \
    }                                                                                                                  \
    GMLIB_LANGI18N_LITERALS_PAPI(i18nInstance)