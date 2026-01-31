#pragma once
#include <mc/world/item/ItemLockMode.h>
#include <mc/world/item/ItemStack.h>

namespace gmlib {
class GMCompoundTag;

class GMItemStack : public ItemStack {
public:
    GMItemStack();
    GMItemStack(ItemStack const& rhs);
    explicit GMItemStack(::ItemInstance const& rhs);
    GMItemStack(::BlockType const& block, int count = 1, GMCompoundTag const* _userData = nullptr);

    GMItemStack(::Item const& item, int count = 1, int auxValue = 0, GMCompoundTag const* _userData = nullptr);

    GMItemStack(std::string_view name, int count = 1, int auxValue = 0, GMCompoundTag const* _userData = nullptr);

public:
    std::unique_ptr<GMCompoundTag> getNbt() const;
    void                           setNbt(GMCompoundTag const& nbt);

    [[deprecated("use bool getUnbreakable() const to instead")]] bool isUnbreakable() const;

    bool getUnbreakable() const;
    void setUnbreakable(bool value);

    // If success, the item will have gloss of enchantment bt not have any enchantment tag.
    // Only can use when item has no enchantment.
    bool setEmptyEnchanted();

    void         setShouldKeepOnDeath(bool keepOnDeath);
    bool         getShouldKeepOnDeath() const;
    void         setItemLockMode(ItemLockMode mode);
    ItemLockMode getItemLockMode() const;
};
} // namespace gmlib