#pragma once
#include "gmlib/Macros.h"
#include "gmlib/gm/ui/ChestUI.h"

namespace gmlib::ui {

class ChestForm {
protected:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_API explicit ChestForm(std::string const& name, ChestType formType = ChestType::BigChest);

    // @param defaultFiller: The deafault itemstack to fill the chest with
    GMLIB_API explicit ChestForm(
        std::string const& name,
        GMItemStack const& defaultFiller,
        ChestType          formType = ChestType::BigChest
    );

public:
    GMLIB_NDAPI            ChestForm(const ChestForm&);
    GMLIB_NDAPI            ChestForm(ChestForm&&) noexcept;
    GMLIB_NDAPI ChestForm& operator=(const ChestForm&);
    GMLIB_NDAPI ChestForm& operator=(ChestForm&&) noexcept;
    GMLIB_API virtual ~ChestForm();

public:
    GMLIB_NDAPI std::string& getTitle();
    GMLIB_NDAPI ChestType    getFormType() const;

public:
    GMLIB_API ChestForm& setTitle(std::string const& name);

    // Any slot can be regarded as a button, and the callback will be called when the player clicks on it
    GMLIB_API ChestForm&
    registerSlot(int slot, GMItemStack const& item, std::function<void(GMPlayer&)>&& callback = {});

    GMLIB_API ChestForm& registerCloseCallback(std::function<void(GMPlayer&)>&& callback = {});
    // @param autoClose: If true, the chest will close automatically after the player clicks on the item
    GMLIB_API ChestForm& sendTo(GMPlayer& pl, bool autoClose = true);

public:
    GMLIB_API static bool close(GMPlayer& pl);
};

} // namespace gmlib::ui