#pragma once
#include "gmlib/Macros.h"
#include <filesystem>
#include <mc/deps/core/resource/PackType.h>

class ResourcePackRepository;

namespace gmlib::mod::AddonsLoader {

GMLIB_API void addCustomPackPath(std::filesystem::path const& path);

GMLIB_API void setCustomPackPath(::ResourcePackRepository& repo, std::filesystem::path const& path, PackType type);

} // namespace gmlib::mod::AddonsLoader