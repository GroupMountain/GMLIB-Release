#pragma once
#include "gmlib/Macros.h"
#include "gmlib/gm/economics/EconomicsSystem.h"
#include <ll/api/coro/Generator.h>

namespace gmlib::economics {

// 请注意，由于时间紧迫，我们并没有提供默认的经济系统，我们将会在后续的版本中添加。
// Please note that due to the tight schedule, we have not provided a default economic system. We will add it in subsequent versions.

class EconomicsSystemManager {
private:
    struct Impl;
    std::unique_ptr<Impl> mImpl;

    EconomicsSystemManager();
    ~EconomicsSystemManager();

public:
    GMLIB_NDAPI static EconomicsSystemManager& getInstance();

    GMLIB_NDAPI std::weak_ptr<EconomicsSystem> get(std::string const& name);
    GMLIB_API bool                             add(std::shared_ptr<EconomicsSystem> const& system);
    GMLIB_API bool                             erase(std::string const& name);

    GMLIB_NDAPI ll::coro::Generator<std::shared_ptr<EconomicsSystem>> getSystems();
};

} // namespace gmlib::economics