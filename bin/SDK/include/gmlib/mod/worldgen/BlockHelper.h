#include "gmlib/Macros.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/dimension/DimensionHeightRange.h"
class Block;
class BlockSource;
class LevelChunk;
namespace gmlib::mod {
class BlockHelper {
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_API explicit BlockHelper(BlockSource*);
    GMLIB_API explicit BlockHelper(LevelChunk*);
    GMLIB_API ~BlockHelper();

    GMLIB_API void         setBlock(const BlockPos& pos, const Block& block, uchar layer = 0, int updateFlags = 0);
    GMLIB_API const Block& getBlock(const BlockPos& pos, uchar layer = 0) const;

    GMLIB_API DimensionHeightRange getHeightRange() const;

    template <typename T, typename = std::enable_if_t<std::is_same_v<T, BlockSource> || std::is_same_v<T, LevelChunk>>>
    GMLIB_API T* get();
    template <typename T, typename = std::enable_if_t<std::is_same_v<T, BlockSource> || std::is_same_v<T, LevelChunk>>>
    GMLIB_API const T* get() const;
};
} // namespace gmlib::mod