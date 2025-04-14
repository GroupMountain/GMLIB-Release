#pragma once
#include <gmlib/mod/recipe/base/ICustomRecipe.h>

namespace gmlib::mod {

class ICustomBrewingRecipe : public ICustomRecipe {
public:
    GMLIB_NDAPI ICustomBrewingRecipe();

    GMLIB_NDAPI std::string getRecipeId() const override;

    GMLIB_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual Ingredient getInput() const = 0;

    virtual Ingredient getReagent() const = 0;

    virtual Ingredient getOutput() const = 0;

protected:
    GMLIB_API void _init() override;
};

} // namespace gmlib::mod