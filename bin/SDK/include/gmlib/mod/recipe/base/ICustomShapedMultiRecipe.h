#pragma once
#include <gmlib/mod/recipe/base/ICustomShapedRecipe.h>
#include <mc/world/item/ItemStack.h>

namespace gmlib::mod {

class ICustomShapedMultiRecipe : public ICustomShapedRecipe {
public:
    using CraftingContainerInput = std::unordered_map<std::string, std::vector<::ItemStack const*>>;
    using CraftingCallback       = std::function<void(CraftingContainerInput const& input, ::ItemInstance& output)>;

public:
    GMLIB_NDAPI ICustomShapedMultiRecipe();

    virtual CraftingCallback getCraftingCallback() const = 0;

protected:
    GMLIB_API void _init() override;
};

} // namespace gmlib::mod