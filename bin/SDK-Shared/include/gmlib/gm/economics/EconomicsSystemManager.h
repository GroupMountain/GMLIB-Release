#pragma once
#include "gmlib/Macros.h"
#include "gmlib/gm/economics/EconomicsSystem.h"
#include <ll/api/coro/Generator.h>

namespace gmlib::economics {

// 请注意，由于时间紧迫，我们并没有提供默认的经济系统，我们将会在后续的版本中添加。
// Please note that due to the tight schedule, we have not provided a default economic system. We will add it in
// subsequent versions.

class EconomicsSystemManager {
private:
    struct Impl;
    std::unique_ptr<Impl> mImpl;

    EconomicsSystemManager();
    ~EconomicsSystemManager();

public:
    GMLIB_NDAPI static EconomicsSystemManager& getInstance();

    GMLIB_NDAPI std::weak_ptr<EconomicsSystem> get(std::string_view name);
    GMLIB_API bool                             add(std::shared_ptr<EconomicsSystem> const& system);
    GMLIB_API bool                             erase(std::string_view name);
    GMLIB_NDAPI bool                           contains(std::string_view name);

    GMLIB_NDAPI ll::coro::Generator<std::shared_ptr<EconomicsSystem>> getSystems();

    GMLIB_NDAPI ll::coro::Generator<std::string_view> getName();
    GMLIB_NDAPI ll::coro::Generator<std::string_view> getSymbol();
    GMLIB_NDAPI ll::coro::Generator<uint8> getDecimals();

    GMLIB_NDAPI ll::coro::Generator<uint64> totalSupply();
    GMLIB_NDAPI ll::coro::Generator<uint64> balanceOf(mce::UUID const& owner);
    GMLIB_NDAPI ll::coro::Generator<bool> transfer(mce::UUID const& owner, mce::UUID const& to, uint64 amount);

    GMLIB_NDAPI ll::coro::Generator<bool>
                transferFrom(mce::UUID const& owner, mce::UUID const& from, mce::UUID const& to, uint64 amount);
    GMLIB_NDAPI ll::coro::Generator<bool> approve(mce::UUID const& owner, mce::UUID const& spender, uint64 amount);
    GMLIB_NDAPI ll::coro::Generator<uint64> allowance(mce::UUID const& owner, mce::UUID const& spender);
};

} // namespace gmlib::economics

#define GMLIB_REGISTER_ECONOMICS_SYSTEM(T, ...)                                                                        \
    struct T##Registry {                                                                                               \
        std::shared_ptr<T> system;                                                                                     \
        T##Registry() : system(std::make_shared<T>(__VA_ARGS__)) {                                                     \
            ::gmlib::economics::EconomicsSystemManager::getInstance().add(system);                                     \
        }                                                                                                              \
        ~T##Registry() { ::gmlib::economics::EconomicsSystemManager::getInstance().erase(system->getName()); }         \
    } T##Register
