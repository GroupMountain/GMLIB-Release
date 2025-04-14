#pragma once
#include <gmlib/mod/recipe/base/ICustomShapelessRecipe.h>

namespace gmlib::mod {

class ICustomStoneCutterRecipe : public ICustomShapelessRecipe {
public:
    GMLIB_NDAPI ICustomStoneCutterRecipe();

    GMLIB_NDAPI std::vector<std::string> getCraftingTags() const override;

    GMLIB_NDAPI std::vector<Ingredient> getIngredients() const override;

    virtual Ingredient getIngredient() const = 0;
};

} // namespace gmlib::mod