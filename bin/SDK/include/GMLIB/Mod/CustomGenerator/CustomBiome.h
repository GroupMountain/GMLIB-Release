#pragma once
#include "GMLIB/Macros.h"
#include "mc/world/level/biome/climate_utils/Parameter.h"

namespace GMLIB::Mod {

enum class BiomeType {
    Surface     = 0, // Surface Biome
    Underground = 1  // Underground Biome
};

struct BiomeData {
    BiomeType               mType;
    ClimateUtils::Parameter mTemperatureRange;
    ClimateUtils::Parameter mHumidityRange;
    ClimateUtils::Parameter mContinentalnessRange;
    ClimateUtils::Parameter mErosionRange;
    ClimateUtils::Parameter mWeirdnessRange;
    float                   mOffset;
};

class CustomBiome {
public:
    GMLIB_API static void registerBiomeClimates(std::string const& id, BiomeData data);

    GMLIB_API static void registerEmptyBiome(std::string const& id, BiomeData data);
};

} // namespace GMLIB::Mod