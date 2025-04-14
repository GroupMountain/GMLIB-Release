#pragma once
#include <gmlib/mod/recipe/base/ICustomRecipe.h>
#include <mc/world/item/ItemInstance.h>

namespace gmlib::mod {

class ICustomFurnaceRecipe : public ICustomRecipe {
public:
    GMLIB_NDAPI ICustomFurnaceRecipe();

    GMLIB_NDAPI std::string getRecipeId() const override;

    GMLIB_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual Ingredient getIngredient() const = 0;

    virtual ::ItemInstance getResult() const = 0;

protected:
    GMLIB_API void _init() override;
};

} // namespace gmlib::mod