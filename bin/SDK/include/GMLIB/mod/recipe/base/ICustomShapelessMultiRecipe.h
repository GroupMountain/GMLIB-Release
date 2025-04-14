#pragma once
#include <gmlib/mod/recipe/base/ICustomShapelessRecipe.h>
#include <mc/world/item/ItemStack.h>

namespace gmlib::mod {

class ICustomShapelessMultiRecipe : public ICustomShapelessRecipe {
public:
    using CraftingContainerInput = std::vector<::ItemStack const*>;
    using CraftingCallback       = std::function<void(CraftingContainerInput const& input, ::ItemInstance& output)>;

public:
    GMLIB_NDAPI ICustomShapelessMultiRecipe();

    virtual CraftingCallback getCraftingCallback() const = 0;

protected:
    GMLIB_API void _init() override;
};

} // namespace gmlib::mod