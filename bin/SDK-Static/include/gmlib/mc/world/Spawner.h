#pragma once
#include "mc/deps/core/utility/optional_ref.h"
#include "mc/world/actor/Actor.h"

namespace gmlib {

class GMSpawner {
public:
    static optional_ref<Actor>
    spawnEntity(Vec3 const& pos, DimensionType dimId, std::string_view name, optional_ref<Actor> owner = nullptr);

    static optional_ref<Mob> spawnMob(
        Vec3 const&         pos,
        DimensionType       dimId,
        std::string_view    name,
        optional_ref<Actor> owner        = nullptr,
        bool                naturalSpawn = false,
        bool                surface      = true,
        bool                fromSpawner  = false
    );

    static optional_ref<ItemActor>
    spawnItem(Vec3 const& pos, DimensionType dimId, ItemStack& item, optional_ref<Actor> owner = nullptr);

    static optional_ref<ItemActor> spawnItem(
        Vec3 const&         pos,
        int                 dimId,
        std::string_view    name,
        int                 count = 1,
        int                 aux   = 0,
        optional_ref<Actor> owner = nullptr
    );

    static optional_ref<Actor> spawnProjectile(Actor& owner, std::string_view name, float speed = 2, float offset = 3);
};

} // namespace gmlib