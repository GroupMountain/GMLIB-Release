#pragma once

namespace gmlib::ui {

enum class ChestSlotType : int {
    Chest,
    Inventory,
    Cursor,
    AnvilInput, // Invalid if ChestType is not Anvil

    // The SlotType::None will be showed in callback in some special circumstances,
    // such as player throwing the item out of the chest.
    // Do not use SlotType::None to register a slot
    None,
};

enum class ChestType : int {
    SingleChest,
    BigChest,
    Anvil,
};

} // namespace gmlib::ui