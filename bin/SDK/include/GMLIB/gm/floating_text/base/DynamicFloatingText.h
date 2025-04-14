#pragma once
#include "StaticFloatingText.h"

namespace gmlib {

class DynamicFloatingText : public StaticFloatingText {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_API
    DynamicFloatingText(
        std::string const& text,
        Vec3 const&        position,
        DimensionType      dimensionId,
        uint               seconds,
        bool               translatePlaceholderApi = true
    );

public:
    GMLIB_API ~DynamicFloatingText() override;

    GMLIB_NDAPI bool isDynamic() const override;

public:
    GMLIB_API bool stopUpdate();

    GMLIB_API bool startUpdate();

    GMLIB_API uint getUpdateInterval() const;

    GMLIB_API void setUpdateInterval(uint seconds);
};


} // namespace gmlib