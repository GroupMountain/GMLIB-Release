#pragma once
#include <functional>
#include <gmlib/mod/gamerule/base/ICustomGameRule.h>

namespace gmlib::mod {

class CustomGameRuleRegistry {
public:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    CustomGameRuleRegistry();
    CustomGameRuleRegistry& operator=(CustomGameRuleRegistry const&) = delete;
    CustomGameRuleRegistry(CustomGameRuleRegistry const&)            = delete;

public:
    GMLIB_NDAPI static CustomGameRuleRegistry& getInstance();

public:
    CustomGameRuleRegistry& registerGameRuleBool(
        std::string const& identifier,
        bool               defaultValue,
        bool               requiresCheats        = false,
        bool               shouleSaveToDisk      = true,
        bool               allowUseInCommand     = true,
        bool               allowUseInScripting   = true,
        bool               canBeModifiedByPlayer = true
    );

    CustomGameRuleRegistry& registerGameRuleInt(
        std::string const& identifier,
        int                defaultValue,
        bool               requiresCheats        = false,
        bool               shouleSaveToDisk      = true,
        bool               allowUseInCommand     = true,
        bool               allowUseInScripting   = true,
        bool               canBeModifiedByPlayer = true
    );

    CustomGameRuleRegistry& registerGameRuleFloat(
        std::string const& identifier,
        float              defaultValue,
        bool               requiresCheats        = false,
        bool               shouleSaveToDisk      = true,
        bool               allowUseInCommand     = true,
        bool               allowUseInScripting   = true,
        bool               canBeModifiedByPlayer = true
    );

    template <typename T, class... Args>
        requires(
            std::is_base_of_v<ICustomGameRule<bool>, T> || std::is_base_of_v<ICustomGameRule<int>, T>
            || std::is_base_of_v<ICustomGameRule<float>, T>
        )
    CustomGameRuleRegistry& registerGameRule(Args&&... args) {
        if constexpr (std::is_base_of_v<ICustomGameRule<bool>, T>) {
            return _registerGameRule([... args = std::forward<Args>(args)]() -> std::unique_ptr<ICustomGameRule<bool>> {
                return std::make_unique<T>(args...);
            });
        } else if constexpr (std::is_base_of_v<ICustomGameRule<int>, T>) {
            return _registerGameRule([... args = std::forward<Args>(args)]() -> std::unique_ptr<ICustomGameRule<int>> {
                return std::make_unique<T>(args...);
            });
        } else if constexpr (std::is_base_of_v<ICustomGameRule<float>, T>) {
            return _registerGameRule(
                [... args = std::forward<Args>(args)]() -> std::unique_ptr<ICustomGameRule<float>> {
                    return std::make_unique<T>(args...);
                }
            );
        }
        return *this;
    }

protected:
    GMLIB_NDAPI CustomGameRuleRegistry& _registerGameRule(std::function<std::unique_ptr<ICustomGameRule<bool>>()>&&);
    GMLIB_NDAPI CustomGameRuleRegistry& _registerGameRule(std::function<std::unique_ptr<ICustomGameRule<int>>()>&&);
    GMLIB_NDAPI CustomGameRuleRegistry& _registerGameRule(std::function<std::unique_ptr<ICustomGameRule<float>>()>&&);
};

} // namespace gmlib::mod

#define GMLIB_REGISTER_GAME_RULE(RULE_CLASS, ...)                                                                      \
    inline static auto GMLIB_CUSTOM_GAME_RULE_##RULE_CLASS = [] {                                                      \
        ::gmlib::mod::CustomGameRuleRegistry::getInstance().registerGameRule<RULE_CLASS>(__VA_ARGS__);                 \
        return 0;                                                                                                      \
    }();

#define GMLIB_REGISTER_GAME_RULES(IDENTIFIER, RULE_CLASS, ...)                                                         \
    inline static auto GMLIB_CUSTOM_GAME_RULE_##IDENTIFIER = [] {                                                      \
        ::gmlib::mod::CustomGameRuleRegistry::getInstance().registerGameRule<RULE_CLASS>(__VA_ARGS__);                 \
        return 0;                                                                                                      \
    }();