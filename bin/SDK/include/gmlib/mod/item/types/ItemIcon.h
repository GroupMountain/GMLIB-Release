#pragma once
#include <gmlib/Macros.h>
#include <iostream>
#include <unordered_map>

namespace gmlib::mod {

class ItemIcon {
public:
    std::unordered_map<std::string, std::string> mTextures;

public:
    GMLIB_NDAPI ItemIcon();
    GMLIB_NDAPI ItemIcon(const char* texture);
    GMLIB_NDAPI ItemIcon(std::string_view texture);

    GMLIB_API void add(std::string_view type, std::string_view texture);
};

} // namespace gmlib::mod
