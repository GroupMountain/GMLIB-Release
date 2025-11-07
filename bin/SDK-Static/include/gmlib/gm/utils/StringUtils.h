#pragma once
#include <fmt/core.h>
#include <string>

namespace mce {
class Color;
}

namespace gmlib::string_utils {

bool isInteger(std::string const& str);

bool isFloat(std::string const& str);

bool isScientificNumber(std::string const& str);

bool isNumber(std::string const& str);

std::string trim(std::string const& str);

std::string floatToString(float value, int precision);

std::string doubleToString(double value, int precision);

// This api will automatically call ll::sys_utils::isStdoutSupportAnsi interface to determine if color is supported, if
// not, no color will be added.
std::string gradientText(std::string const& str, mce::Color const& start, mce::Color const& end);

template <typename... Args>
std::string
gradientText(fmt::format_string<Args...> fmt, mce::Color const& start, mce::Color const& end, Args&&... args) {
    return gradientText(fmt::vformat(fmt.get(), fmt::make_format_args(args...)), start, end);
}

std::string toCamelCase(std::string const& str);

} // namespace gmlib::string_utils