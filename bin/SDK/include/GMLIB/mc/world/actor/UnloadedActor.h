#pragma once

#include "gmlib/Macros.h"
#include "mc/deps/core/math/Vec3.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/nbt/CompoundTag.h"
#include "mc/world/actor/Actor.h"
#include <mc/world/attribute/SharedAttributes.h>
#include <memory>
#include <unordered_map>


namespace gmlib::world::actor {

// This is the actor that is stored in the world database
// It can be a loaded actor or an unloaded actor
// You can cast it if it is loaded (dont use forced cast)
class UnloadedActor {
protected:
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_NDAPI explicit UnloadedActor(ActorUniqueID const& uniqueId, int64_t storageKey);

    GMLIB_API UnloadedActor(UnloadedActor&& other);

    GMLIB_API ~UnloadedActor();

public:
    GMLIB_NDAPI static std::optional<UnloadedActor> getUnloadedActor(int64_t storageKey);

    // It also contains loaded actor
    GMLIB_NDAPI static std::vector<UnloadedActor> getAllUnloadedActors();

    GMLIB_NDAPI static std::unordered_map<ActorUniqueID, UnloadedActor> getAllUnloadedActorsMap();

    // callback: return true to continue
    GMLIB_API static void foreachUnloadedActor(std::function<bool(UnloadedActor& actor)>&& func);

public:
    // The key storage in leveldb, it is unique
    GMLIB_NDAPI int64_t getStorageKey() const;

    GMLIB_NDAPI ActorUniqueID getUniqueId() const;

    GMLIB_NDAPI ll::Expected<CompoundTag> getNbt() const;

    // If the actor is loaded, return the actor
    GMLIB_NDAPI optional_ref<Actor> getActor() const;

    // Get the actor type name
    GMLIB_NDAPI std::string getTypeName() const;

    // Get the actor position
    GMLIB_NDAPI Vec3 getPosition() const;

    GMLIB_NDAPI DimensionType getDimensionId() const;

    // If the actor is removed return false
    GMLIB_NDAPI bool isValid() const;

public:
    // Remove a unloaded actor from the database.
    GMLIB_API void remove();

    // Set the actor nbt in the database (it allows to set it even if the actor is unloaded)
    GMLIB_API bool setNbt(CompoundTag const& nbt);
};

} // namespace gmlib::world::actor
