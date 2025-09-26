#pragma once
#include "gmlib/Macros.h"
#include "gmlib/gm/enum/ChestType.h"
#include <functional>
#include <mc/deps/core/utility/optional_ref.h>
#include <memory>

namespace gmlib {
class GMItemStack;
class GMCompoundTag;
class GMPlayer;
} // namespace gmlib

namespace gmlib::ui {

/*
    This class provide a way to create a chest ui without a real chest block.
    It's just a certain kind of ui, not a form.
    If you want to use a chest form, please use ui::ChestForm.
*/
class ChestUI {
public:
    struct ChangingSlot {
        int           mSlot;
        ChestSlotType mType;
    };

    // src is the slot where player pick the item.
    // dst is the slot where player place the item.
    // amount is the amount of item changes.
    using ChestUICallback =
        std::function<void(GMPlayer&, ChangingSlot const& src, ChangingSlot const& dst, int amount)>;

public:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_NDAPI explicit ChestUI(
        std::string const& name,
        ChestType          formType = ChestType::BigChest,
        ChestUICallback&&  callback = {}
    );

    GMLIB_NDAPI        ChestUI(const ChestUI&);
    GMLIB_NDAPI        ChestUI(ChestUI&&) noexcept;
    GMLIB_API ChestUI& operator=(const ChestUI&);
    GMLIB_API ChestUI& operator=(ChestUI&&) noexcept;

    // Notice: This destructor will not close the form.
    //         Using ChestUI::close() to close a player's form.
    GMLIB_API virtual ~ChestUI();

public:
    GMLIB_NDAPI std::string& getTitle() const;
    GMLIB_NDAPI ChestType    getType() const;

public:
    /**
     * Init a slot in the form.
     * @param slot If the type is SlotType::Cursor, this param won't take effect(The cursor has only one slot).
     * @attention A big chest's slot index is from 0 to 53. A chest's slot index is from 0 to 26, and a inventory's
     * slot index is from 0 to 35. If the slot param is out of the index, it won't take effect.
     */
    GMLIB_API ChestUI& registerSlot(int slot, GMItemStack const& item, ChestSlotType type = ChestSlotType::Chest);
    GMLIB_API ChestUI& registerSlot(int slot, GMCompoundTag const& nbt, ChestSlotType type = ChestSlotType::Chest);

    //Return what the slot contains.
    GMLIB_API optional_ref<GMCompoundTag> getSlot(int slot, ChestSlotType type = ChestSlotType::Chest) const;

    GMLIB_API ChestUI& registerCallback(ChestUICallback&& callback);

    // overideInventory: If true, the player's inventory in cliend will be overide by the form. (Will not affect the
    // player's inventory in server)
    //                   If false, the registered slots with inventory type will be ignored
    GMLIB_API ChestUI& sendTo(GMPlayer& pl);

public:
    GMLIB_API static bool close(GMPlayer& pl);

    GMLIB_NDAPI static optional_ref<ChestUI> getChestUI(GMPlayer& pl);

    // Hot change, return true if succeed
    GMLIB_API static bool
    setSlot(int slot, GMItemStack const& item, GMPlayer& pl, ChestSlotType type = ChestSlotType::Chest);
    GMLIB_API static bool
    setSlot(int slot, GMCompoundTag const& nbt, GMPlayer& pl, ChestSlotType type = ChestSlotType::Chest);
};

} // namespace gmlib::ui