#pragma once
#include <mc/world/actor/Actor.h>

namespace gmlib {

class GMActor : public Actor {
public:
    std::unique_ptr<CompoundTag> getNbt();

public:
    // link and throw a exist entity as a projectile
    // If u want to spawn a new entity as a projectile, use Spawner::spawnProjectile
    void setProjectile(GMActor& projectile, float speed, float offset);
    bool setNbt(CompoundTag const& nbt);
    // a simple way to set the max and current value of an attribute
    // Any attribute, such as health, hunger, etc.
    void setAttributeMax(const Attribute&, float value);
    void setAttributeMin(const Attribute&, float value);
    void setAttributeCurrent(const Attribute&, float value);

    void setAttributeMax(std::string_view name, float value);
    void setAttributeMin(std::string_view name, float value);
    void setAttributeCurrent(std::string_view name, float value);

public:
    // Some inline functions in 1.21.60
    Vec2& getRotation();
    Vec3& getVelocity();
};


} // namespace gmlib
