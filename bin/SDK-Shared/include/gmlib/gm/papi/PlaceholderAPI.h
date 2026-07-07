#pragma once
#include <utility>
#if __has_include("gmlib/Macros.h")                                                                                    \
                  && __has_include("gmlib/mc/world/actor/Actor.h") && __has_include("gmlib/mc/world/actor/Player.h")
#define INCLUDE_GMLIB
#include "gmlib/Macros.h"
#include "gmlib/mc/world/actor/Actor.h"
#include "gmlib/mc/world/actor/Player.h"
#else
#include <ll/api/mod/ModManagerRegistry.h>
#include <ll/api/mod/NativeMod.h>
#include <mc/world/actor/player/Player.h>
#endif
#include <ll/api/mod/NativeMod.h>
#include <mc/deps/core/utility/optional_ref.h>
#include <mc/deps/ecs/gamerefs_entity/EntityContext.h>
#include <mc/deps/vanilla_components/ActorTypeComponent.h>
#include <mc/world/actor/ActorType.h>
#include <variant>

namespace gmlib::inline papi {

class PlaceholderAPI {
private:
    struct Impl;
    std::unique_ptr<Impl> mImpl;
    PlaceholderAPI();
    ~PlaceholderAPI();

public:
    // clang-format off
    struct AutoCast {
    public:
        optional_ref<Actor> mActor;

    public:
        template <std::derived_from<Actor> T>
        inline bool tryCast(optional_ref<T>& res) const {
            if (!mActor) return true;
            if constexpr (
                std::is_same_v<T, Actor>
#ifdef INCLUDE_GMLIB
                || std::is_same_v<T, GMActor>
#endif
            ) {
                res = mActor;
                return true;
            } else if constexpr (
                std::same_as<T, Player>
#ifdef INCLUDE_GMLIB
                || std::same_as<T, GMPlayer>
#endif
            ) {
                if (mActor && mActor->getEntityTypeId() == ActorType::Player) {
                    res = *reinterpret_cast<T*>(mActor.as_ptr());
                    return true;
                }
                return false;
            } else if constexpr (std::same_as<T, Mob>) {
                if (mActor
                    && (std::to_underlying(mActor->mEntityContext->tryGetComponent<ActorTypeComponent>()->mType)
                        & std::to_underlying(ActorType::Mob))
                        == std::to_underlying(ActorType::Mob)) {
                    res = *reinterpret_cast<Mob*>(mActor.as_ptr());
                    return true;
                }
                return false;
            } else if (mActor && *reinterpret_cast<void***>(mActor.as_ptr()) == T::$vftable()) {
                res = *reinterpret_cast<T*>(mActor.as_ptr());
                return true;
            } else {
                return false;
            }
        }

        template <typename U>
        operator optional_ref<U>() const /*NOLINT*/ {
            optional_ref<U> result;
            tryCast(result);
            return result;
        }
    };
    using Callback = std::function<std::optional<std::string>(
        optional_ref<Actor>                    actor,
        ll::SmallStringMap<std::string> const& params,
        std::string const&                     language
    )>;
    using TranslateVariables = ll::DenseMap<
        std::string,
        std::variant<std::string, Callback>
    >;
    struct PlaceholderData {
        std::weak_ptr<ll::mod::Mod> mod;
        Callback                    callback;
    };
    // clang-format on

private:
    void registerBuiltinPlaceholders();

public:
#ifdef INCLUDE_GMLIB
    GMLIB_API static PlaceholderAPI& getInstance();
#else
    inline static PlaceholderAPI& getInstance() {
        static auto& instance = []() -> PlaceholderAPI& {
            // clang-format off
            auto mod = ll::mod::ModManagerRegistry::getInstance().getMod("GMLIB");
            if (!mod) throw std::runtime_error("GMLIB mod not found.");
            if (mod->getType() != ll::mod::NativeModManagerName) throw std::runtime_error("GMLIB mod is not a native mod.");
            auto handle = static_cast<ll::mod::NativeMod&>(*mod).getHandle();
            auto func = reinterpret_cast<ll::sys_utils::DynamicLibrary*>(&handle)->getAddress<PlaceholderAPI& (*)()>(
                "?getInstance@PlaceholderAPI@papi@gmlib@@SAAEAV123@XZ"
            );
            if (!func) throw std::runtime_error("GMLIB PlaceholderAPI::getInstance function not found.");
            return func();
            // clang-format on
        }();
        return instance;
    }
#endif

    // NOLINTBEGIN(google-default-arguments)
    virtual std::string translate(
        std::string const&        value,
        optional_ref<Actor>       actor     = std::nullopt,
        std::string const&        language  = {},
        TranslateVariables const& variables = {}
    );
    virtual bool registerPlaceholder(
        std::string const&                 placeholder,
        Callback&&                         callback,
        bool                               override = false,
        std::weak_ptr<ll::mod::Mod> const& mod      = ll::mod::NativeMod::current()
    );
    virtual bool unregisterPlaceholder(std::string const& placeholder);
    virtual bool unregisterPlaceholder(const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current());
    virtual std::optional<std::string> getValue(
        std::string const&                     placeholder,
        optional_ref<Actor>                    actor    = std::nullopt,
        ll::SmallStringMap<std::string> const& params   = {},
        std::string const&                     language = {}
    );
    virtual std::optional<PlaceholderData> getPlaceholderData(std::string const& placeholder);
    virtual ll::SmallDenseMap<std::string, PlaceholderData>
    getAllPlaceholderData(const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current());
    // NOLINTEND(google-default-arguments)

    inline std::string& translate(
        std::string&              value,
        optional_ref<Actor>       actor     = std::nullopt,
        std::string const&        language  = {},
        TranslateVariables const& variables = {}
    ) {
        return value = translate(std::as_const(value), actor, language, variables);
    }
    template <typename T>
    inline bool registerPlaceholder(
        std::string const&                 placeholder,
        T&&                                callback,
        bool                               override = false,
        std::weak_ptr<ll::mod::Mod> const& mod      = ll::mod::NativeMod::current()
    ) {
        // clang-format off
        return registerPlaceholder(
            placeholder,
            Callback{[cb = std::move(std::forward<T>(callback))](
                optional_ref<Actor>                                 actor,
                ll::SmallStringMap<std::string> const& params,
                std::string const&                                  language
            ) -> std::optional<std::string> {
                if constexpr (requires { cb(AutoCast{actor}); }) {
                    return cb(AutoCast{actor});
                } else if constexpr (requires { cb(AutoCast{actor}, language); }) {
                    return cb(AutoCast{actor}, language);
                } else if constexpr (requires { cb(AutoCast{actor}, language, params); }) {
                    return cb(AutoCast{actor}, language, params);
                } else if constexpr (requires { cb(AutoCast{actor}, params); }) {
                    return cb(AutoCast{actor}, params);
                } else if constexpr (requires { cb(AutoCast{actor}, params, language); }) {
                    return cb(AutoCast{actor}, params, language);
                } else if constexpr (requires { cb(language); }) {
                    return cb(language);
                } else if constexpr (requires { cb(language, AutoCast{actor}); }) {
                    return cb(language, AutoCast{actor});
                } else if constexpr (requires { cb(language, AutoCast{actor}, params); }) {
                    return cb(language, AutoCast{actor}, params);
                } else if constexpr (requires { cb(language, params); }) {
                    return cb(language, params);
                } else if constexpr (requires { cb(language, params, AutoCast{actor}); }) {
                    return cb(language, params, AutoCast{actor});
                } else if constexpr (requires { cb(params); }) {
                    return cb(params);
                } else if constexpr (requires { cb(params, AutoCast{actor}); }) {
                    return cb(params, AutoCast{actor});
                } else if constexpr (requires { cb(params, AutoCast{actor}, language); }) {
                    return cb(params, AutoCast{actor}, language);
                } else if constexpr (requires { cb(params, language); }) {
                    return cb(params, language);
                } else if constexpr (requires { cb(params, language, AutoCast{actor}); }) {
                    return cb(params, language, AutoCast{actor});
                } else if constexpr (requires { cb(); }) {
                    return cb();
                } else {
                    static_assert(ll::traits::always_false<T>, "fail to call.");
                }
            }},
            override,
            mod
        );
        // clang-format on
    }
};

} // namespace gmlib::inline papi

#undef INCLUDE_GMLIB