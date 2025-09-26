#pragma once
#include <ll/api/base/StdInt.h>

namespace gmlib::system_utils {

struct RamData {
    ullong all;
    ullong canuse;
    ullong percent;
    ullong used;
    ullong bdsUsed;
};

RamData getRam();

} // namespace gmlib::system_utils