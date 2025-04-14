#pragma once
#include <gmlib/mod/recipe/base/ICustomRecipe.h>
#include <mc/world/item/ItemInstance.h>

namespace gmlib::mod {

class ICustomSmithingTransformRecipe : public ICustomRecipe {
public:
    GMLIB_NDAPI ICustomSmithingTransformRecipe();

    GMLIB_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual Ingredient getSmithingTemplate() const = 0;

    virtual Ingredient getBaseIngredient() const = 0;

    virtual Ingredient getAdditionIngredient() const = 0;

    virtual ::ItemInstance getResult() const = 0;

protected:
    GMLIB_API void _init() override;
};

} // namespace gmlib::mod