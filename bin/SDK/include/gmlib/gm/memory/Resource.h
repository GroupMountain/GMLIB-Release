#pragma once
#include <filesystem>
#include <gmlib/Macros.h>
#include <iostream>
#include <ll/api/utils/SystemUtils.h>
#include <optional>

namespace gmlib::memory {

GMLIB_NDAPI ll::Expected<std::string>
readResource(int id, bool isBinary = false, ll::sys_utils::HandleT handle = ll::sys_utils::getCurrentModuleHandle());

GMLIB_NDAPI ll::Expected<std::string>
            readCompressedResource(int id, ll::sys_utils::HandleT handle = ll::sys_utils::getCurrentModuleHandle());

GMLIB_API bool writeResource(
    int                          id,
    std::filesystem::path const& path,
    bool                         isBinary = false,
    ll::sys_utils::HandleT       handle   = ll::sys_utils::getCurrentModuleHandle()
);

} // namespace gmlib::memory