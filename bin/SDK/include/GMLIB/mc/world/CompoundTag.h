#pragma once
#include "gmlib/Macros.h"
#include <mc/nbt/CompoundTag.h>
#include <memory>

class DataLoadHelper;
class Actor;
class Player;
class BlockActor;
class ItemStack;
class Block;

namespace gmlib {

class GMCompoundTag : public CompoundTag {
public:
    GMCompoundTag() = default;

    GMCompoundTag(TagMap tags) : CompoundTag(tags) {}

    GMCompoundTag(CompoundTag const& tag) : CompoundTag(tag) {}

    GMCompoundTag(std::initializer_list<TagMap::value_type> tags) : CompoundTag(tags) {}

    GMCompoundTag(GMCompoundTag const&)            = default;
    GMCompoundTag& operator=(GMCompoundTag const&) = default;
    GMCompoundTag(GMCompoundTag&&)                 = default;
    GMCompoundTag& operator=(GMCompoundTag&&)      = default;

public:
    GMLIB_NDAPI static DataLoadHelper& getDataLoadHelper();

    GMLIB_NDAPI static std::unique_ptr<GMCompoundTag> get(const ::Actor& actor);

    GMLIB_NDAPI static std::unique_ptr<GMCompoundTag> get(const ::Player& player);

    GMLIB_NDAPI static std::unique_ptr<GMCompoundTag> get(const ::BlockActor& blockActor);

    GMLIB_NDAPI static std::unique_ptr<GMCompoundTag> get(const ::ItemStack& item);

    GMLIB_NDAPI static std::unique_ptr<GMCompoundTag> get(const ::Block& block);

    GMLIB_NDAPI static ll::Expected<GMCompoundTag>
    readFromFile(std::filesystem::path const& path, bool isBinary = true);

    GMLIB_API static bool saveToFile(std::filesystem::path const& path, const CompoundTag& nbt, bool isBinary = true);

    GMLIB_API static void
    writeNbtTags(CompoundTag& originNbt, const CompoundTag& dataNbt, const std::vector<std::string>& tags);

public:
    GMLIB_API bool set(Actor& actor) const;

    GMLIB_API bool set(Player& player) const;

    GMLIB_API void set(BlockActor& blockActor) const;

    GMLIB_API void set(ItemStack& item) const;

    GMLIB_API void set(Block& block) const;

public:
    GMLIB_NDAPI std::unique_ptr<GMCompoundTag> clone() const;
};

} // namespace gmlib