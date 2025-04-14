#pragma once
#include "gmlib/Macros.h"
#include <ll/api/base/StdInt.h>

namespace gmlib::system_utils {

struct RamData {
    ullong all;
    ullong canuse;
    ullong percent;
    ullong used;
    ullong bdsUsed;
};

GMLIB_NDAPI RamData getRam();

} // namespace gmlib::system_utils