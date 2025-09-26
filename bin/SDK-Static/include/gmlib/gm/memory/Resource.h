#pragma once
#include <filesystem>
#include <iostream>
#include <ll/api/utils/SystemUtils.h>
#include <optional>

namespace gmlib::memory {

ll::Expected<std::string>
readResource(int id, bool isBinary = false, ll::sys_utils::HandleT handle = ll::sys_utils::getCurrentModuleHandle());

ll::Expected<std::string>
readCompressedResource(int id, ll::sys_utils::HandleT handle = ll::sys_utils::getCurrentModuleHandle());

bool writeResource(
    int                          id,
    std::filesystem::path const& path,
    bool                         isBinary = false,
    ll::sys_utils::HandleT       handle   = ll::sys_utils::getCurrentModuleHandle()
);

} // namespace gmlib::memory