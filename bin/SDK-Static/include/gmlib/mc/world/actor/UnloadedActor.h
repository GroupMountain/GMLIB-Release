#pragma once
#include "mc/deps/core/math/Vec3.h"
#include "mc/deps/nbt/CompoundTag.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/world/actor/Actor.h"
#include <mc/world/attribute/SharedAttributes.h>
#include <memory>
#include <unordered_map>


namespace gmlib {

// This is the actor that is stored in the world database
// It can be a loaded actor or an unloaded actor
// You can cast it if it is loaded (dont use forced cast)
class UnloadedActor {
protected:
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    explicit UnloadedActor(ActorUniqueID const& uniqueId, int64_t storageKey);

    UnloadedActor(UnloadedActor&& other) noexcept;

    ~UnloadedActor();

public:
    static std::optional<UnloadedActor> getUnloadedActor(int64_t storageKey);

    // It also contains loaded actor
    static std::vector<UnloadedActor> getAllUnloadedActors();

    static std::unordered_map<ActorUniqueID, UnloadedActor> getAllUnloadedActorsMap();

    // callback: return true to continue
    static void foreachUnloadedActor(std::function<bool(UnloadedActor& actor)>&& func);

public:
    // The key storage in leveldb, it is unique
    int64_t getStorageKey() const;

    ActorUniqueID getUniqueId() const;

    ll::Expected<CompoundTag> getNbt() const;

    // If the actor is loaded, return the actor
    optional_ref<Actor> getActor() const;

    // Get the actor type name
    std::string getTypeName() const;

    // Get the actor position
    Vec3 getPosition() const;

    DimensionType getDimensionId() const;

    // If the actor is removed return false
    bool isValid() const;

public:
    // Remove a unloaded actor from the database.
    void remove();

    // Set the actor nbt in the database (it allows to set it even if the actor is unloaded)
    bool setNbt(CompoundTag const& nbt);
};

} // namespace gmlib
