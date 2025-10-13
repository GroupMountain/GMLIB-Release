#pragma once
#include "gmlib/Macros.h"
#include <mc/legacy/ActorUniqueID.h>
#include <mc/world/level/BlockPos.h>
#include <mc/world/level/ChunkPos.h>

namespace gmlib {

class TpsStatus {
private:
    struct Impl;
    std::unique_ptr<Impl> mImpl;
    TpsStatus();
    ~TpsStatus();

public:
    GMLIB_NDAPI static TpsStatus& getInstance();

    GMLIB_NDAPI ushort getLevelCurrentTps();
    GMLIB_NDAPI float  getLevelAverageTps();

    GMLIB_NDAPI ushort getDimensionCurrentTps(DimensionType dimid);
    GMLIB_NDAPI float  getDimensionAverageTps(DimensionType dimid);

    GMLIB_NDAPI ushort getChunkCurrentTps(DimensionType dimid, ChunkPos const& cp);
    GMLIB_NDAPI float  getChunkAverageTps(DimensionType dimid, ChunkPos const& cp);

    GMLIB_NDAPI ushort getChunkBlockCurrentTps(DimensionType dimid, ChunkPos const& cp);
    GMLIB_NDAPI float  getChunkBlockAverageTps(DimensionType dimid, ChunkPos const& cp);

    GMLIB_NDAPI ushort getChunkBlockEntityCurrentTps(DimensionType dimid, ChunkPos const& cp);
    GMLIB_NDAPI float  getChunkBlockEntityAverageTps(DimensionType dimid, ChunkPos const& cp);

    GMLIB_NDAPI ushort getBlockCurrentTps(DimensionType dimid, BlockPos const& pos);
    GMLIB_NDAPI float  getBlockAverageTps(DimensionType dimid, BlockPos const& pos);

    GMLIB_NDAPI ushort getBlockEntityCurrentTps(DimensionType dimid, BlockPos const& pos);
    GMLIB_NDAPI float  getBlockEntityAverageTps(DimensionType dimid, BlockPos const& pos);

    GMLIB_NDAPI ushort getEntityCurrentTps(ActorUniqueID const& uniqueId);
    GMLIB_NDAPI float  getEntityAverageTps(ActorUniqueID const& uniqueId);
};

} // namespace gmlib