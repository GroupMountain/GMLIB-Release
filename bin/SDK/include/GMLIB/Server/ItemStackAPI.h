#pragma once
#include "GMLIB/Macros.h"
#include "mc/world/item/ItemLockMode.h"
#include "mc/world/item/ItemStack.h"

class GMLIB_ItemStack : public ItemStack {
public:
    GMLIB_NDAPI GMLIB_ItemStack();

    GMLIB_NDAPI explicit GMLIB_ItemStack(class ItemInstance const& item);

    GMLIB_NDAPI GMLIB_ItemStack(class ItemStack const& item);

    GMLIB_NDAPI explicit GMLIB_ItemStack(class RecipeIngredient const& ingredient);

    GMLIB_NDAPI GMLIB_ItemStack(class BlockLegacy const& blockLegacy, int count = 1);

    GMLIB_NDAPI GMLIB_ItemStack(class Block const& block, int count = 1, class CompoundTag const* userData = nullptr);

    GMLIB_NDAPI
    GMLIB_ItemStack(
        class Item const&        item,
        int                      count    = 1,
        int                      auxValue = 0,
        class CompoundTag const* userData = nullptr
    );

    GMLIB_NDAPI
    GMLIB_ItemStack(
        std::string_view         name,
        int                      count    = 1,
        int                      auxValue = 0,
        class CompoundTag const* userData = nullptr
    );

public:
    GMLIB_NDAPI std::unique_ptr<CompoundTag> getNbt();

    GMLIB_API void setNbt(CompoundTag& nbt);

    GMLIB_API void setItem(std::string const& name, int count = 1, short auxValue = 0);

    GMLIB_API int getCount();

    GMLIB_API void setCount(int value);

    GMLIB_API void addCount(int value);

    GMLIB_API void removeCount(int value);

    GMLIB_API short getAuxValue();

    GMLIB_API void setAuxValue(short auxValue);

    GMLIB_API bool isUnbreakable();

    GMLIB_API void setUnbreakable(bool value = true);

    GMLIB_NDAPI std::vector<const BlockLegacy*> getCanDestroy();

    GMLIB_API void setCanDestroy(std::vector<const BlockLegacy*> blocks);

    GMLIB_API void setCanDestroy(std::vector<std::string> const& blocks);

    GMLIB_NDAPI std::vector<const BlockLegacy*> getCanPlaceOn();

    GMLIB_API void setCanPlaceOn(std::vector<const BlockLegacy*> blocks);

    GMLIB_API void setCanPlaceOn(std::vector<std::string> const& blocks);

    GMLIB_API void setShouldKeepOnDeath(bool value);

    GMLIB_NDAPI bool getShouldKeepOnDeath();

    GMLIB_API void setItemLockMode(::ItemLockMode mode);

    GMLIB_API bool setEmptyEnchanted();

    GMLIB_API void setEmptyCustomName();

    GMLIB_NDAPI ::ItemLockMode getItemLockMode();
};