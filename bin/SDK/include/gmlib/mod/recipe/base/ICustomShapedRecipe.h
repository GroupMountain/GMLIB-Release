#pragma once
#include <gmlib/mod/recipe/base/ICustomRecipe.h>
#include <mc/world/item/ItemInstance.h>

namespace gmlib::mod {

class ICustomShapedRecipe : public ICustomRecipe {
public:
    struct ShapedIngredients {
        std::unordered_map<std::string, Ingredient> mIngredients;

        GMLIB_NDAPI ShapedIngredients();
        GMLIB_NDAPI ShapedIngredients(std::unordered_map<std::string, Ingredient> const& mIngredients);
        GMLIB_NDAPI ShapedIngredients(std::initializer_list<std::pair<const std::string, Ingredient>> init);

        GMLIB_API void add(std::string_view key, Ingredient const& ingredient);
    };

public:
    GMLIB_NDAPI ICustomShapedRecipe();

    GMLIB_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual std::vector<std::string> getShape() const = 0;

    virtual ShapedIngredients getIngredients() const = 0;

    virtual ::ItemInstance getResult() const = 0;

    GMLIB_NDAPI virtual int getPriority() const;

    GMLIB_NDAPI virtual UnlockingRequirement getUnlockingRequirement() const;

    GMLIB_NDAPI virtual bool isAssumeSymmetry() const;

protected:
    GMLIB_API void _init() override;
};

} // namespace gmlib::mod