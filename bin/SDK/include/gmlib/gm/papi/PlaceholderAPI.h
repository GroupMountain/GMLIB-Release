#pragma once
#include "gmlib/Macros.h"
#include <MC/world/actor/Actor.h>
#include <functional>
#include <ll/api/mod/NativeMod.h>
#include <mc/deps/core/utility/optional_ref.h>
#include <optional>
#include <string>
#include <utility>

class Actor;

namespace gmlib {
namespace details {
template <std::derived_from<Actor> T>
inline bool tryCast(optional_ref<T>& res, optional_ref<Actor> actor) {
    if (!actor) return true;
    if constexpr (std::is_same_v<T, Actor>) {
        res = actor;
        return true;
    } else if constexpr (std::same_as<T, Player>) {
        if (actor && actor->isPlayer()) {
            res = *reinterpret_cast<Player*>(actor.as_ptr());
            return true;
        }
        return false;
    } else if constexpr (std::same_as<T, Mob>) {
        if (actor && actor->isType(::ActorType::Mob)) {
            res = *reinterpret_cast<Mob*>(actor.as_ptr());
            return true;
        }
        return false;
    } else if (actor && *reinterpret_cast<void***>(actor.as_ptr()) == T::$vftable()) {
        res = *reinterpret_cast<T*>(actor.as_ptr());
        return true;
    } else return false;
}
struct AutoCast {
    optional_ref<Actor> actor;
    template <typename U>
    operator optional_ref<U>() const /*NOLINT*/ {
        optional_ref<U> res;
        tryCast(res, actor);
        return res;
    }
};

} // namespace details
class GMActor;

class PlaceholderAPI {
public:
    PlaceholderAPI()                                 = delete;
    PlaceholderAPI(PlaceholderAPI const&)            = delete;
    PlaceholderAPI& operator=(PlaceholderAPI const&) = delete;
    PlaceholderAPI(PlaceholderAPI&&)                 = delete;
    PlaceholderAPI& operator=(PlaceholderAPI&&)      = delete;

public:
    struct PlaceholderData {
        std::weak_ptr<ll::mod::Mod> mod;
        std::function<std::optional<std::string>(
            optional_ref<Actor>                                 actor,
            std::unordered_map<std::string, std::string> const& params,
            std::string const&                                  language
        )>
            callback;
    };

public:
    GMLIB_API static std::string&
    translate(std::string& value, optional_ref<Actor> actor = std::nullopt, std::string language = "");

    GMLIB_API static std::string
    translate(std::string const& value, optional_ref<Actor> actor = std::nullopt, std::string language = "");

    GMLIB_API static bool registerPlaceholder(
        std::string const&          placeholder,
        std::function<std::optional<std::string>(
            optional_ref<Actor>                                 actor,
            std::unordered_map<std::string, std::string> const& params,
            std::string const&                                  language
        )>&&                        callback,
        std::weak_ptr<ll::mod::Mod> mod = ll::mod::NativeMod::current()
    );
    template <typename T>
    static inline bool registerPlaceholder(
        std::string const&                 placeholder,
        T&&                                callback,
        const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current()
    ) {
        return registerPlaceholder(
            placeholder,
            std::function<std::optional<std::string>(
                optional_ref<Actor>                                 actor,
                std::unordered_map<std::string, std::string> const& params,
                std::string const&                                  language
            )>{[cb = std::forward<T>(callback)](
                   optional_ref<Actor>                                 actor,
                   std::unordered_map<std::string, std::string> const& params,
                   std::string const&                                  language
               ) -> std::optional<std::string> {
                if constexpr (requires { cb(details::AutoCast{actor}); }) {
                    return cb(details::AutoCast{actor});
                } else if constexpr (requires { cb(details::AutoCast{actor}, language); }) {
                    return cb(details::AutoCast{actor}, language);
                } else if constexpr (requires { cb(details::AutoCast{actor}, language, params); }) {
                    return cb(details::AutoCast{actor}, language, params);
                } else if constexpr (requires { cb(details::AutoCast{actor}, params); }) {
                    return cb(details::AutoCast{actor}, params);
                } else if constexpr (requires { cb(details::AutoCast{actor}, params, language); }) {
                    return cb(details::AutoCast{actor}, params, language);
                } else if constexpr (requires { cb(language); }) {
                    return cb(language);
                } else if constexpr (requires { cb(language, details::AutoCast{actor}); }) {
                    return cb(language, details::AutoCast{actor});
                } else if constexpr (requires { cb(language, details::AutoCast{actor}, params); }) {
                    return cb(language, details::AutoCast{actor}, params);
                } else if constexpr (requires { cb(language, params); }) {
                    return cb(language, params);
                } else if constexpr (requires { cb(language, params, details::AutoCast{actor}); }) {
                    return cb(language, params, details::AutoCast{actor});
                } else if constexpr (requires { cb(params); }) {
                    return cb(params);
                } else if constexpr (requires { cb(params, details::AutoCast{actor}); }) {
                    return cb(params, details::AutoCast{actor});
                } else if constexpr (requires { cb(params, details::AutoCast{actor}, language); }) {
                    return cb(params, details::AutoCast{actor}, language);
                } else if constexpr (requires { cb(params, language); }) {
                    return cb(params, language);
                } else if constexpr (requires { cb(params, language, details::AutoCast{actor}); }) {
                    return cb(params, language, details::AutoCast{actor});
                } else if constexpr (requires { cb(); }) {
                    return cb();
                } else {
                    static_assert(ll::traits::always_false<>, "fail to call.");
                }
            }},
            mod
        );
    }

    GMLIB_API static bool unregisterPlaceholder(std::string const& placeholder);

    GMLIB_API static bool unregisterPlaceholder(std::weak_ptr<ll::mod::Mod> mod);

    GMLIB_NDAPI static std::optional<std::string> getValue(
        std::string const&                                  placeholder,
        optional_ref<Actor>                                 actor    = std::nullopt,
        std::unordered_map<std::string, std::string> const& params   = {},
        std::string const&                                  language = ""
    );

    GMLIB_NDAPI static std::optional<PlaceholderData> getPlaceholderData(std::string const& placeholder);

    GMLIB_NDAPI static std::unordered_map<std::string, PlaceholderData> getAllPlaceholderData();

    GMLIB_NDAPI static std::unordered_map<std::string, PlaceholderData>
    getAllPlaceholderData(std::weak_ptr<ll::mod::Mod> mod);
};

} // namespace gmlib