#pragma once
#include "GMLIB/Macros.h"
#include "mc/deps/core/string/HashedString.h"
#include "mc/deps/core/sem_ver/SemVersion.h"
#include "mc/world/item/crafting/RecipeUnlockingRequirement.h"
#include "mc/world/item/crafting/Recipes.h"

namespace GMLIB::Mod {

class CustomShapedRecipe {
public:
    virtual std::string getRecipeId() = 0;

    virtual ItemInstance getResult() = 0;

    virtual std::vector<std::string> getShape() = 0;

    virtual std::vector<Recipes::Type> getIngredients() = 0;

    virtual std::vector<HashedString> getCraftingTags() { return {"crafting_table"}; }

    virtual int getPriority() { return 50; }

    virtual std::function<std::unique_ptr<
        ShapedRecipe>(std::string, int, int, std::vector<class RecipeIngredient> const&, std::vector<class ItemInstance> const&, class HashedString, int, class mce::UUID const*, std::optional<class RecipeUnlockingRequirement>, class SemVersion const&)>
    getConstructor() {
        return nullptr;
    }

    virtual std::optional<class RecipeUnlockingRequirement> getRecipeUnlockingRequirement() { return {}; }

    virtual SemVersion getSemVersion() { return SemVersion(1, 20, 80, "", ""); }
};

} // namespace GMLIB::Mod