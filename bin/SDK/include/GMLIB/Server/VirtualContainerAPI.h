#pragma once
#include "GMLIB/Macros.h"
#include "GMLIB/Server/FormAPI/ChestForm.h"

namespace GMLIB {


class GMLIB_Container {

public:
    using ChestType    = GMLIB::Server::Form::ChestType;
    using ChangingSlot = GMLIB::Server::Form::ChangingSlot;
    using ChestUI      = GMLIB::Server::Form::ChestUI;

    using ContainerCallback =
        std::function<bool(Player&, ChangingSlot const& src, ChangingSlot const& dst, int amount)>;

public:
private:
    std::array<ItemStack, 54>             mItemsData;
    std::string                           mName;
    ChestType                             mFormType = ChestType::BigChest;
    std::unordered_map<Player*, ChestUI*> mOpenersMap;
    ContainerCallback                     mCallback;
    int                                   mSize;

public:
    GMLIB_API GMLIB_Container(
        std::string const& name     = "Chest",
        ChestType          formType = ChestType::BigChest,
        ContainerCallback  callback = {}
    );

    GMLIB_API GMLIB_Container(Container& container, ContainerCallback callback = {});

    GMLIB_API ~GMLIB_Container();

public:
    // return true if open successfully
    GMLIB_API bool open(Player& pl);
    GMLIB_API bool close(Player& pl);

    GMLIB_API ChestType getType() const { return mFormType; }
    GMLIB_API std::string const& getName() const { return mName; }
    GMLIB_API std::unordered_map<Player*, ChestUI*> getOpenersMap() const { return mOpenersMap; }
    GMLIB_API std::array<ItemStack, 54> const& getItemsData() const { return mItemsData; }
    GMLIB_API const int                        getContainerSize() const { return mSize; }

    
    GMLIB_API bool isOpen() const {return mOpenersMap.size();}
    GMLIB_API bool isEmpty() const;
    // return -1 if has no room
    GMLIB_API int findFirstSlotForItem(ItemStack const& item) const;

    GMLIB_API void removeAllItems();
    // return the count of the rest item
    // 0 if all of the item is saved;
    GMLIB_API int  addItem(ItemStack const& item);
    GMLIB_API bool removeItem(int slot, int count);
    GMLIB_API void setItem(int slot, ItemStack const& item);

    // refresh show to player
    GMLIB_API bool refresh();

public:
    [[nodiscard]] GMLIB_API ItemStack& operator[](int index) { return mItemsData[index]; }
};
} // namespace GMLIB
