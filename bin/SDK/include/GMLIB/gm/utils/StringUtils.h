#pragma once
#include "gmlib/Macros.h"
#include <string>

namespace gmlib::utils::StringUtils {

GMLIB_NDAPI bool isInteger(std::string const& str);

GMLIB_NDAPI bool isFloat(std::string const& str);

GMLIB_NDAPI bool isNumber(std::string const& str);

GMLIB_NDAPI std::string trim(std::string const& str);

GMLIB_NDAPI std::string floatToString(float value, int precision);

GMLIB_NDAPI std::string doubleToString(double value, int precision);

} // namespace gmlib::utils::StringUtils