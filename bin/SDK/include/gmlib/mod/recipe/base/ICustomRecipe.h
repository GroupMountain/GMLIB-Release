#pragma once
#include <gmlib/Macros.h>
#include <gmlib/gm/enum/Recipes.h>
#include <iostream>
#include <optional>
#include <vector>

namespace gmlib::mod {

class CustomRecipeRegistry;

class ICustomRecipe {
public:
    struct Impl;
    ::std::unique_ptr<Impl> pImpl;
    friend class CustomRecipeRegistry;

public:
    struct Ingredient {
        struct Impl;
        ::std::unique_ptr<Impl> pImpl;

        GMLIB_NDAPI Ingredient(const char* type);
        GMLIB_NDAPI explicit Ingredient(
            ::std::string_view   type,
            RecipeIngredientType ingredientType = RecipeIngredientType::Item,
            uint8_t              count          = 1
        );
        GMLIB_NDAPI explicit Ingredient(::std::string_view type, uint8_t count, ::std::optional<short> aux = {});

        GMLIB_NDAPI Ingredient(Ingredient const&);
        GMLIB_NDAPI Ingredient(Ingredient&&);

        GMLIB_API Ingredient& operator=(Ingredient const&);
        GMLIB_API Ingredient& operator=(Ingredient&&);

        GMLIB_API ~Ingredient();
    };

    struct UnlockingRequirement {
        struct Impl;
        ::std::unique_ptr<Impl> pImpl;

        GMLIB_NDAPI UnlockingRequirement(
            ::std::vector<Ingredient> const& items,
            RecipeUnlockingContext = RecipeUnlockingContext::None
        );
        GMLIB_NDAPI UnlockingRequirement(RecipeUnlockingContext context);

        GMLIB_NDAPI UnlockingRequirement(UnlockingRequirement const&);
        GMLIB_NDAPI UnlockingRequirement(UnlockingRequirement&&);

        GMLIB_API UnlockingRequirement& operator=(UnlockingRequirement const&);
        GMLIB_API UnlockingRequirement& operator=(UnlockingRequirement&&);

        GMLIB_API ~UnlockingRequirement();
    };

public:
    ICustomRecipe();
    ICustomRecipe& operator=(ICustomRecipe const&) = delete;
    ICustomRecipe(ICustomRecipe const&)            = delete;

public:
    GMLIB_API virtual ~ICustomRecipe();

    virtual ::std::string getRecipeId() const = 0;

    virtual ::std::vector<::std::string> getCraftingTags() const = 0;

    virtual void _init() = 0;
};

} // namespace gmlib::mod
