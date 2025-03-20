#pragma once
#include "gmlib/Macros.h"
#include "ll/api/utils/SystemUtils.h"
#include <filesystem>
#include <iostream>
#include <optional>

namespace gmlib::memory {

GMLIB_NDAPI std::optional<std::string>
readResource(int id, bool isBinary = false, ll::sys_utils::HandleT handle = ll::sys_utils::getCurrentModuleHandle());

GMLIB_API bool writeResource(
    int                          id,
    std::filesystem::path const& path,
    bool                         isBinary = false,
    ll::sys_utils::HandleT       handle   = ll::sys_utils::getCurrentModuleHandle()
);

} // namespace gmlib::memory