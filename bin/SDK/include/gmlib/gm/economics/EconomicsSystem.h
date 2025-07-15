#pragma once
#include "gmlib/Macros.h"
#include <ll/api/base/StdInt.h>
#include <mc/platform/UUID.h>

namespace gmlib::economics {

class EconomicsSystem {
public:
    GMLIB_API EconomicsSystem();
    GMLIB_API virtual ~EconomicsSystem();
    EconomicsSystem(EconomicsSystem&&)                 = delete;
    EconomicsSystem& operator=(EconomicsSystem&&)      = delete;
    EconomicsSystem(EconomicsSystem const&)            = delete;
    EconomicsSystem& operator=(EconomicsSystem const&) = delete;

    virtual std::string_view getName() const = 0; // Name of the economics system (Immutable)
    virtual std::string_view getSymbol() const;
    virtual uint8            getDecimals() const;

    virtual uint64 totalSupply() const                                                  = 0;
    virtual uint64 balanceOf(mce::UUID const& owner) const                              = 0;
    virtual bool   transfer(mce::UUID const& owner, mce::UUID const& to, uint64 amount) = 0;

    virtual bool   transferFrom(mce::UUID const& owner, mce::UUID const& from, mce::UUID const& to, uint64 amount) = 0;
    virtual bool   approve(mce::UUID const& owner, mce::UUID const& spender, uint64 amount)                        = 0;
    virtual uint64 allowance(mce::UUID const& owner, mce::UUID const& spender) const                               = 0;
};

} // namespace gmlib::economics