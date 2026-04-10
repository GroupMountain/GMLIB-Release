#pragma once
#include <mc/deps/nbt/CompoundTag.h>
#include <memory>
#include <utility>

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

    explicit GMCompoundTag(TagMap tags) : CompoundTag(std::move(tags)) {}

    explicit GMCompoundTag(CompoundTag const& tag) : CompoundTag(tag) {}
    explicit GMCompoundTag(CompoundTag&& tag) : CompoundTag(std::move(tag)) {}


    GMCompoundTag(std::initializer_list<TagMap::value_type> tags) : CompoundTag(tags) {}

    GMCompoundTag(GMCompoundTag const&)            = default;
    GMCompoundTag& operator=(GMCompoundTag const&) = default;
    GMCompoundTag(GMCompoundTag&&) noexcept        = default;
    GMCompoundTag& operator=(GMCompoundTag&&)      = default;

public:
    static DataLoadHelper& getDataLoadHelper();

    static std::unique_ptr<GMCompoundTag> get(const ::Actor& actor);

    static std::unique_ptr<GMCompoundTag> get(const ::Player& player);

    static std::unique_ptr<GMCompoundTag> get(const ::BlockActor& blockActor);

    static std::unique_ptr<GMCompoundTag> get(const ::ItemStack& item);

    static std::unique_ptr<GMCompoundTag> get(const ::Block& block);

    static ll::Expected<GMCompoundTag> readFromFile(std::filesystem::path const& path, bool isBinary = true);

    static bool saveToFile(std::filesystem::path const& path, const CompoundTag& nbt, bool isBinary = true);

    static void writeNbtTags(CompoundTag& originNbt, const CompoundTag& dataNbt, const std::vector<std::string>& tags);

public:
    bool set(Actor& actor) const;

    bool set(Player& player) const;

    void set(BlockActor& blockActor) const;

    void set(ItemStack& item) const;

    void set(Block& block) const;

public:
    std::unique_ptr<GMCompoundTag> clone() const;
};

} // namespace gmlib