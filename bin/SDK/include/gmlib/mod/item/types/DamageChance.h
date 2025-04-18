#pragma once
#include <gmlib/Macros.h>
#include <stdint.h>

namespace gmlib::mod {

struct DamageChance {
    uint8_t mMin;
    uint8_t mMax;

    GMLIB_NDAPI DamageChance();

    GMLIB_NDAPI DamageChance(uint8_t min, uint8_t max);

    int random() const;
};

} // namespace gmlib::mod
