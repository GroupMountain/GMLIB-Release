#pragma once
#include <gmlib/gm/enum/MobEffectType.h>
#include <gmlib/mod/item/base/ICustomItem.h>
#include <mc/deps/core/math/Vec3.h>
#include <mc/world/effect/MobEffectInstance.h>

namespace gmlib::mod {

class ICustomFoodItem : public ICustomItem {
public:
    enum class UseAction : int {
        None                 = -1,
        ChorusTeleport       = 0,
        SuspiciousStewEffect = 1,
    };

public:
    GMLIB_NDAPI ICustomFoodItem(std::string const& identifier);

    virtual int getNutrition() const = 0;

    virtual float getSaturation() const = 0;

    GMLIB_API virtual bool canAlwaysEat() const;

    GMLIB_API virtual std::string getUsingConvertTo() const;

    GMLIB_API virtual UseAction getUseAction() const;

    GMLIB_API virtual Vec3 getOnUseRange() const;

    GMLIB_API virtual std::vector<::MobEffectInstance> getEffects() const;

    GMLIB_API virtual std::vector<uint32_t> getRemoveEffects() const;

    GMLIB_API bool isFood() const override;

    GMLIB_API ::SharedTypes::Legacy::UseAnimation getUseAnimation() const override;

    GMLIB_API ::ItemUseMethod useTimeDepleted(::ItemStack&, ::Level*, ::Player*) const override;

    GMLIB_API void _init() override;

public:
    GMLIB_NDAPI static ::MobEffectInstance createEffect(
        MobEffectType effectType,
        int           durationTicks = 600,
        int           amplifier     = 0,
        bool          visible       = true,
        bool          ambient       = false,
        bool          animation     = false
    );
};

} // namespace gmlib::mod