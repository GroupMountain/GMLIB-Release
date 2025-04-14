#pragma once
#include <filesystem>
#include <gmlib/Macros.h>
#include <gmlib/gm/enum/CompressionLevel.h>

namespace gmlib::memory {

GMLIB_NDAPI std::string compressBinary(std::string_view binaryData, CompressionLevel level = CompressionLevel::Default);

GMLIB_NDAPI std::string
compressBinary(std::string_view binaryData, size_t bufferSize, CompressionLevel level = CompressionLevel::Default);

GMLIB_NDAPI std::string decompressBinary(std::string_view compressedData);

} // namespace gmlib::memory