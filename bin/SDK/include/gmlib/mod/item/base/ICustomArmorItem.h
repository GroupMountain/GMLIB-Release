#pragma once
#include <gmlib/Macros.h>
#include <gmlib/mod/item/types/DamageChance.h>
#include <gmlib/mod/item/types/ItemIcon.h>
#include <gmlib/mod/item/types/RepairItems.h>
#include <gmlib/mod/item/types/mc/HumanoidArmorItem.h>
#include <mc/deps/shared_types/legacy/item/UseAnimation.h>
#include <mc/nbt/CompoundTag.h>
#include <mc/world/item/Rarity.h>
#include <mc/world/item/enchanting/Enchant.h>

namespace gmlib::mod {

class ICustomArmorItem : public ::HumanoidArmorItem {
public:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_NDAPI ICustomArmorItem(std::string const& identifier);

    GMLIB_API ~ICustomArmorItem();

    virtual ItemIcon getIcon() const = 0;

    virtual ::SharedTypes::Legacy::ArmorSlot getArmorSlot() const = 0;

    GMLIB_API virtual HumanoidArmorItem::Tier getArmorTier() const;

    GMLIB_API virtual int getModelIndex() const;

    GMLIB_API virtual uint8_t getItemMaxStackSize() const;

    GMLIB_API virtual std::vector<std::string> getItemTags() const;

    GMLIB_API virtual bool allowOffhand() const;

    GMLIB_API virtual std::string getHoverTextColorFormat() const;

    GMLIB_API virtual bool shouldDespawn() const;

    GMLIB_API virtual ::Enchant::Slot getEnchantmentSlot() const;

    GMLIB_API virtual bool isFoil() const;

    GMLIB_API virtual DamageChance getItemDamageChance() const;

    GMLIB_API virtual short getItemDurability() const;

    GMLIB_API virtual std::vector<RepairItems> getRepairItems() const;

    GMLIB_API virtual ::SharedTypes::Legacy::UseAnimation getUseAnimation() const;

    GMLIB_API virtual ::std::string getCooldownCategory() const;

    GMLIB_API virtual bool requiresWorldBuilder() const;

    GMLIB_API virtual bool isExplodable() const;

    GMLIB_API virtual bool isFireResistant() const;

    GMLIB_API virtual bool shouldIgnoresPermissions() const;

    GMLIB_API virtual bool shouldAnimatesInToolbar() const;

    GMLIB_API virtual std::string getDisplayName() const;

    GMLIB_API virtual int getUseDuration() const;

    GMLIB_API virtual ::Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const;

    GMLIB_API virtual ::CreativeItemCategory getCreativeCategory() const;

    GMLIB_API virtual ::std::string getCreativeGroup() const;

    GMLIB_API virtual bool isFuel() const;

    GMLIB_API virtual float getFurnaceBurnInterval() const;

    GMLIB_API virtual float getFurnaceXPmultiplier() const;

    GMLIB_API virtual ::ItemCommandVisibility shouldHiddenInCommands() const;

    GMLIB_API virtual bool isSmithingTransformable() const;

    GMLIB_API virtual bool isSmithingTransformMaterial() const;

    GMLIB_API virtual bool isSmithingTemplate() const;

    GMLIB_API virtual bool canDestroyInCreative() const;

    GMLIB_API virtual float getMiningSpeed() const;

    GMLIB_API virtual int getFrameCount() const;

    GMLIB_API virtual std::string getInteractButtonText() const;

    GMLIB_API const HashedString& getCooldownType() const override;

    GMLIB_API int getArmorValue() const override;

    GMLIB_API int getToughnessValue() const override;

    GMLIB_API float getArmorKnockbackResistance() const override;

    GMLIB_API bool isDyeable() const override;

    GMLIB_API bool isTrimAllowed() const override;

    GMLIB_API bool
    isValidRepairItem(::ItemStackBase const&, ::ItemStackBase const&, ::BaseGameVersion const&) const override;

    GMLIB_API int getEnchantSlot() const override;

    GMLIB_API int getDamageChance(int) const override;

    GMLIB_API short getMaxDamage() const override;

    GMLIB_API bool isComponentBased() const override;

    GMLIB_API std::unique_ptr<CompoundTag> buildNetworkTag() const override;

    GMLIB_API std::string getInteractText(::Player const& player) const override;

    GMLIB_API virtual void _init();
};

} // namespace gmlib::mod
