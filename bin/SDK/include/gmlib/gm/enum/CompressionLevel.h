#pragma once

namespace gmlib {

enum class CompressionLevel : int {
    Default         = -1,
    NoCompression   = 0,
    BestSpeed       = 1,
    Low             = 2,
    MediumLow       = 3,
    Medium          = 4,
    MediumHigh      = 5,
    High            = 6,
    VeryHigh        = 7,
    Ultra           = 8,
    BestCompression = 9,
};

}