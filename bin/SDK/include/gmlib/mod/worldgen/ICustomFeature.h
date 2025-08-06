#pragma once
#include "gmlib/Macros.h"
#include "gmlib/mod/worldgen/BlockHelper.h"
#include <mc/world/level/levelgen/feature/IFeature.h>
#include <optional>


class BlockPos;
class BlockSource;
class Random;
class LevelChunk;
namespace gmlib::mod {
class ICustomFeature : public IFeature {
public:
    GMLIB_API ICustomFeature();
    GMLIB_API virtual ~ICustomFeature();
    GMLIB_API virtual ::std::optional<::BlockPos> place(::IFeature::PlacementContext const&) const;
    /*must be thread-safe*/
    GMLIB_API virtual std::optional<BlockPos>
    place(BlockHelper& sourceOrChunk, const BlockPos& pos, Random& random) const = 0;
};
} // namespace gmlib::mod