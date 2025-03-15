#pragma once
#include "texts/DynamicFloatingText.h"
#include <mc/deps/core/utility/AutomaticID.h>
#include <memory>

namespace gmlib::tools::FloatingText {

template <typename T, typename... Args>
GMLIB_NDAPI typename std::enable_if<std::is_base_of<BaseFloatingText, T>::value, std::weak_ptr<BaseFloatingText>>::type
create(Args... args) {
    std::shared_ptr<T> text = std::make_shared<T>(std::forward<Args>(args)...);
    add(text);
    return text;
}

GMLIB_NDAPI std::shared_ptr<StaticFloatingText>
createStatic(std::string const& text, Vec3 const& position, DimensionType dimensionId, bool translatePlaceholderApi);

GMLIB_NDAPI std::shared_ptr<DynamicFloatingText> createDynamic(
    std::string const& text,
    Vec3 const&        position,
    DimensionType      dimensionId,
    uint               updateInterval,
    bool               translatePlaceholderApi
);


GMLIB_API bool add(std::shared_ptr<BaseFloatingText> floatingText);

GMLIB_API bool remove(std::shared_ptr<BaseFloatingText> floatingText);

GMLIB_API bool remove(int runtimeId);

GMLIB_NDAPI optional_ref<BaseFloatingText> getFloatingText(int runtimeId);

GMLIB_NDAPI std::vector<std::weak_ptr<BaseFloatingText>> getAllFloatingTexts();

GMLIB_NDAPI std::vector<std::weak_ptr<BaseFloatingText>> getAllFloatingTexts(DimensionType dimId);

} // namespace gmlib::tools::FloatingText