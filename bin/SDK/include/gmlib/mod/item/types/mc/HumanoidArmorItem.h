#pragma once
#include "mc/_HeaderOutputPredefine.h"
#include "mc/deps/shared_types/legacy/LevelSoundEvent.h"
#include "mc/deps/shared_types/legacy/actor/ActorLocation.h"
#include "mc/deps/shared_types/legacy/actor/ArmorSlot.h"
#include "mc/world/item/Item.h"
#include <gmlib/Macros.h>

class Actor;
class BaseGameVersion;
class BlockSource;
class CompoundTag;
class Container;
class ItemDescriptor;
class ItemInstance;
class ItemStack;
class ItemStackBase;
class Level;
class Mob;
class Player;
class Vec3;
struct ResolvedItemIconInfo;
namespace Bedrock::Safety {
class RedactableString;
}
namespace mce {
class Color;
}

class HumanoidArmorItem : public ::Item {
public:
    class ArmorMaterial;

    enum class Tier : int {
        Leather   = 0,
        Chain     = 1,
        Iron      = 2,
        Diamond   = 3,
        Gold      = 4,
        Elytra    = 5,
        Turtle    = 6,
        Netherite = 7,
    };

    class ArmorMaterial {
    public:
        char filler[32];

    public:
        ArmorMaterial& operator=(ArmorMaterial const&) = default;
        ArmorMaterial(ArmorMaterial const&)            = default;
        ArmorMaterial()                                = default;
    };

public:
    ::SharedTypes::Legacy::ArmorSlot    mSlot;
    int                                 mDefense;
    int                                 mModelIndex;
    ::HumanoidArmorItem::ArmorMaterial& mArmorType;
    bool                                mCurrentVersionAllowsTrim;

public:
    GMLIB_NDAPI HumanoidArmorItem(std::string const& name);

    virtual bool isHumanoidArmor() const;

    virtual bool isValidRepairItem(
        ::ItemStackBase const&   source,
        ::ItemStackBase const&   repairItem,
        ::BaseGameVersion const& baseGameVersion
    ) const;

    virtual int getEnchantSlot() const;

    virtual int getEnchantValue() const;

    virtual int getArmorValue() const;

    virtual int getToughnessValue() const;

    virtual float getArmorKnockbackResistance() const;

    virtual bool hasCustomColor(::CompoundTag const* userData) const;

    virtual ::mce::Color getColor(::CompoundTag const* userData, ::ItemDescriptor const&) const;

    virtual void clearColor(::ItemStackBase& instance) const;

    virtual void setColor(::ItemStackBase& item, ::mce::Color const& color) const;

    virtual bool isDyeable() const;

    virtual bool isTrimAllowed() const;

    virtual ::SharedTypes::Legacy::ActorLocation getEquipLocation() const;

    virtual ::SharedTypes::Legacy::LevelSoundEvent getEquipSound() const;

    virtual int getDamageChance(int unbreaking) const;

    virtual bool dispense(::BlockSource& region, ::Container& container, int slot, ::Vec3 const& pos, uchar) const;

    virtual void appendFormattedHovertext(
        ::ItemStackBase const&               stack,
        ::Level&                             level,
        ::Bedrock::Safety::RedactableString& hovertext,
        bool const                           showCategory
    ) const;

    virtual void hurtActor(::ItemStack& item, ::Actor& actor, ::Mob& attacker) const;

    virtual ::ResolvedItemIconInfo
    getIconInfo(::ItemStackBase const& item, int newAnimationFrame, bool inInventoryPane) const;

    virtual ::ItemStack& use(::ItemStack& item, ::Player& player) const;

    virtual int buildIdAux(short auxValue, ::CompoundTag const* userData) const;

    virtual ~HumanoidArmorItem() = default;

public:
    MCAPI ::ItemInstance getTierItem() const;

public:
    MCAPI static ::HumanoidArmorItem::ArmorMaterial const& CHAIN();

    MCAPI static ::mce::Color& DEFAULT_LEATHER_COLOR();

    MCAPI static ::HumanoidArmorItem::ArmorMaterial const& DIAMOND();

    MCAPI static ::HumanoidArmorItem::ArmorMaterial const& ELYTRA();

    MCAPI static ::HumanoidArmorItem::ArmorMaterial const& GOLD();

    MCAPI static ::HumanoidArmorItem::ArmorMaterial const& IRON();

    MCAPI static ::HumanoidArmorItem::ArmorMaterial const& LEATHER();

    MCAPI static ::HumanoidArmorItem::ArmorMaterial const& NETHERITE();

    MCAPI static ::HumanoidArmorItem::ArmorMaterial const& TURTLE();

    MCAPI static ::std::add_lvalue_reference_t<int const[]> mHealthPerSlot();
};
