#pragma once
#include "GMLIB/Macros.h"
#include "ll/api/event/Cancellable.h"
#include "ll/api/event/entity/ActorEvent.h"

namespace GMLIB::Event::EntityEvent {

class DeathMessageBeforeEvent final : public ll::event::Cancellable<ll::event::entity::ActorEvent> {
protected:
    ActorDamageSource& mDamageSource;
    std::string&       mDeadName;

public:
    constexpr explicit DeathMessageBeforeEvent(Actor& actor, ActorDamageSource& damageSource, std::string& deadName)
    : Cancellable(actor),
      mDamageSource(damageSource),
      mDeadName(deadName) {}

    GMLIB_NDAPI ActorDamageSource& getDamageSource() const;
    GMLIB_NDAPI std::string& getDeadName() const;
};

class DeathMessageAfterEvent final : public ll::event::entity::ActorEvent {
    ActorDamageSource&                                mDamageSource;
    std::string&                                      mDeadName;
    std::pair<std::string, std::vector<std::string>>& mDeathMessage;

public:
    constexpr explicit DeathMessageAfterEvent(
        Actor&                                            actor,
        ActorDamageSource&                                damageSource,
        std::string&                                      deadName,
        std::pair<std::string, std::vector<std::string>>& deathMessage
    )
    : ActorEvent(actor),
      mDamageSource(damageSource),
      mDeadName(deadName),
      mDeathMessage(deathMessage) {}

    GMLIB_NDAPI ActorDamageSource& getDamageSource() const;
    GMLIB_NDAPI std::string& getDeadName() const;
    GMLIB_NDAPI std::pair<std::string, std::vector<std::string>>& getDeathMessage() const;
};

} // namespace GMLIB::Event::EntityEvent