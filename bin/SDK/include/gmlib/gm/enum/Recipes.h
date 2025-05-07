#pragma once
#include <cstdint>

namespace gmlib::mod {

enum class RecipeUnlockingContext : int {
    None               = 0,
    AlwaysUnlocked     = 1,
    PlayerInWater      = 2,
    PlayerHasManyItems = 3,
};

enum class RecipeIngredientType : uint8_t {
    Item = 0,
    Tag  = 1,
};

} // namespace gmlib::mod
