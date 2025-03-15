#pragma once
#include "BaseFloatingText.h"

namespace gmlib::tools {
class StaticFloatingText : public BaseFloatingText {
public:
    GMLIB_API
    StaticFloatingText(
        std::string const& text,
        Vec3 const&        position,
        DimensionType      dimensionId,
        bool               translatePlaceholderApi = false
    );

public:
    GMLIB_API void setText(std::string const& newText) override;

    GMLIB_API void setPosition(Vec3 const& pos) override;

    GMLIB_API void setDimensionId(DimensionType dimId) override;
};

} // namespace gmlib::tools
