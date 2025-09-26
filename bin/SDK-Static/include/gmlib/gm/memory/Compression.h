#pragma once
#include <string>
#include "gmlib/gm/enum/CompressionLevel.h"
namespace gmlib::memory {

std::string compressBinary(std::string_view binaryData, CompressionLevel level = CompressionLevel::Default);

std::string
compressBinary(std::string_view binaryData, size_t bufferSize, CompressionLevel level = CompressionLevel::Default);

std::string decompressBinary(std::string_view compressedData);

} // namespace gmlib::memory