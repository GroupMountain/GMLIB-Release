#pragma once
#include "gmlib/Macros.h"
#include <mc/world/item/ItemLockMode.h>
#include <mc/world/item/ItemStack.h>

namespace gmlib::world {
class GMCompoundTag;
}

namespace gmlib::world {
class GMItemStack : public ItemStack {
public:
    GMLIB_NDAPI GMItemStack();
    GMLIB_NDAPI GMItemStack(ItemStack const& rhs);
    GMLIB_NDAPI explicit GMItemStack(::ItemInstance const& rhs);
    GMLIB_NDAPI GMItemStack(::BlockLegacy const& block, int count = 1);
    GMLIB_NDAPI
    GMItemStack(::Item const& item, int count = 1, int auxValue = 0, GMCompoundTag const* _userData = nullptr);
    GMLIB_NDAPI
    GMItemStack(std::string_view name, int count = 1, int auxValue = 0, GMCompoundTag const* _userData = nullptr);

public:
    GMLIB_NDAPI std::unique_ptr<GMCompoundTag> getNbt() const;
    GMLIB_API void                             setNbt(GMCompoundTag const& nbt);

    GMLIB_NDAPI bool isUnbreakable() const;
    GMLIB_API void   setUnbreakable(bool value);

    // If success, the item will have gloss of enchantment bt not have any enchantment tag.
    // Only can use when item has no enchantment.
    GMLIB_API bool setEmptyEnchanted();

    GMLIB_NDAPI bool         getShouldKeepOnDeath() const;
    GMLIB_API void           setItemLockMode(ItemLockMode mode);
    GMLIB_NDAPI ItemLockMode getItemLockMode() const;
};
} // namespace gmlib::world