#pragma once

#include "gmlib/Macros.h"
#include <mc/world/actor/Actor.h>


namespace gmlib::world::actor {

class GMActor : public Actor {
public:
    using Actor::addEffect;
    using ::Actor::removeEffect;

public:
    GMLIB_NDAPI std::unique_ptr<CompoundTag> getNbt();

public:
    // link and throw a exist entity as a projectile
    // If u want to spawn a new entity as a projectile, use Spawner::spawnProjectile
    GMLIB_API void setProjectile(GMActor& projectile, float speed, float offset);
    GMLIB_API bool setNbt(CompoundTag const& nbt);
    // a simple way to set the max and current value of an attribute
    // Any attribute, such as health, hunger, etc.
    GMLIB_API void setAttributeMax(Attribute, float value);
    GMLIB_API void setAttributeCurrent(Attribute, float value);

public:
    // Some inline functions in 1.21.60
    GMLIB_NDAPI Vec2& getRotation();
    GMLIB_NDAPI Vec3& getVelocity();
};


} // namespace gmlib::world::actor
