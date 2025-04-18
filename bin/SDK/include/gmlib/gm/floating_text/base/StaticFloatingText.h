#pragma once
#include "FloatingText.h"

namespace gmlib {

class StaticFloatingText : public FloatingText {
public:
    GMLIB_API
    StaticFloatingText(
        std::string const& text,
        Vec3 const&        position,
        DimensionType      dimensionId,
        bool               translatePlaceholderApi = false
    );

public:
    GMLIB_NDAPI bool isDynamic() const override;

public:
    GMLIB_API void setText(std::string const& newText) override;

    GMLIB_API void setPosition(Vec3 const& pos) override;

    GMLIB_API void setDimensionId(DimensionType dimId) override;
};

} // namespace gmlib
