#pragma once
#include <utility>

#include "gmlib/gm/economics/EconomicsSystem.h"
#include "ll/api/event/Event.h"
namespace gmlib::economics {
class TransferEvent final : public ll::event::Event {
    const mce::UUID&               mFrom;
    const mce::UUID&               mTo;
    const uint64&                  mValue;
    std::weak_ptr<EconomicsSystem> mSystem;

public:
    TransferEvent(
        const mce::UUID&               from,
        const mce::UUID&               to,
        const uint64&                  value,
        std::weak_ptr<EconomicsSystem> system
    )
    : mFrom(from),
      mTo(to),
      mValue(value),
      mSystem(std::move(system)) {}
    const mce::UUID&               from() const { return mFrom; }
    const mce::UUID&               to() const { return mTo; }
    const uint64&                  value() const { return mValue; }
    std::weak_ptr<EconomicsSystem> system() { return mSystem; }
};
class ApprovalEvent final : public ll::event::Event {
    const mce::UUID&               mOwner;
    const mce::UUID&               mSpender;
    const uint64&                  mValue;
    std::weak_ptr<EconomicsSystem> mSystem;

public:
    ApprovalEvent(
        const mce::UUID&               owner,
        const mce::UUID&               spender,
        const uint64&                  value,
        std::weak_ptr<EconomicsSystem> system
    )
    : mOwner(owner),
      mSpender(spender),
      mValue(value),
      mSystem(std::move(system)) {}
    const mce::UUID&               owner() const { return mOwner; }
    const mce::UUID&               spender() const { return mSpender; }
    const uint64&                  value() const { return mValue; }
    std::weak_ptr<EconomicsSystem> system() { return mSystem; }
};
} // namespace gmlib::economics