#pragma once
#include <gmlib/mod/recipe/base/ICustomRecipe.h>
#include <mc/world/item/ItemInstance.h>

namespace gmlib::mod {

class ICustomShapelessRecipe : public ICustomRecipe {
public:
    GMLIB_NDAPI ICustomShapelessRecipe();

    GMLIB_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual std::vector<Ingredient> getIngredients() const = 0;

    virtual ::ItemInstance getResult() const = 0;

    GMLIB_NDAPI virtual int getPriority() const;

    GMLIB_NDAPI virtual UnlockingRequirement getUnlockingRequirement() const;

protected:
    GMLIB_API void _init() override;
};

} // namespace gmlib::mod