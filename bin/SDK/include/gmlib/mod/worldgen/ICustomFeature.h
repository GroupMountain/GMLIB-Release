#pragma once
#include <gmlib/Macros.h>
#include <mc/world/level/levelgen/feature/IFeature.h>
#include <optional>


class BlockPos;
class BlockSource;
class Random;
namespace gmlib::mod {
class ICustomFeature : public IFeature {
public:
    GMLIB_API ICustomFeature();
    GMLIB_API virtual ~ICustomFeature();
    GMLIB_API virtual ::std::optional<::BlockPos> place(::IFeature::PlacementContext const&) const;
    /*must be thread-safe*/
    virtual std::optional<BlockPos> place(BlockSource& source, const BlockPos& pos, Random& random) const = 0;
};
} // namespace gmlib::mod