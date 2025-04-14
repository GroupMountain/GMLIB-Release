#pragma once
#include "gmlib/Macros.h"
#include <filesystem>
#include <gmlib/gm/enum/CompressionLevel.h>
#include <ll/api/Expected.h>
#include <vector>

namespace gmlib::file_utils {

GMLIB_NDAPI std::vector<std::string> getAllFileNameInDirectory(std::filesystem::path const& path);

GMLIB_NDAPI std::vector<std::string> getAllFileFullNameInDirectory(std::filesystem::path const& path);

GMLIB_NDAPI std::vector<std::filesystem::path> getAllFilePathInDirectory(std::filesystem::path const& path);

GMLIB_NDAPI std::vector<std::filesystem::path> getAllFolderPathInDirectory(std::filesystem::path const& path);

GMLIB_NDAPI std::vector<std::string> getAllFolderNameInDirectory(std::filesystem::path const& path);

GMLIB_NDAPI ll::Expected<std::string> readFile(std::filesystem::path const& filePath, bool isBinary = false);

GMLIB_API bool writeFile(std::filesystem::path const& filePath, std::string_view content, bool isBinary = false);

GMLIB_NDAPI ll::Expected<std::string> readCompressedFile(std::filesystem::path const& filePath);

GMLIB_API bool writeCompressedFile(
    std::filesystem::path const& filePath,
    std::string_view             content,
    CompressionLevel             level = CompressionLevel::Default
);

GMLIB_API bool writeCompressedFile(
    std::filesystem::path const& filePath,
    std::string_view             content,
    size_t                       bufferSize,
    CompressionLevel             level = CompressionLevel::Default
);

GMLIB_API bool compressFolder(
    std::filesystem::path const& folderPath,
    std::filesystem::path const& archivePath = {},
    bool                         includeSelf = false,
    bool                         replace     = false,
    CompressionLevel             level       = CompressionLevel::Default,
    std::string_view             password    = {}
);

GMLIB_API bool decompressArchive(
    std::filesystem::path const& archivePath,
    std::filesystem::path const& outputPath = {},
    bool                         replace    = false,
    std::string_view             password   = {}
);

GMLIB_API bool appendFileToArchive(
    std::filesystem::path const& filePath,
    std::filesystem::path const& archivePath,
    std::string_view             entryName
);

GMLIB_API bool appendFolderToArchive(std::filesystem::path const& filePath, std::filesystem::path const& archivePath);

GMLIB_API bool appendFileToArchiveFromMemory(
    std::string_view             fileContent,
    std::filesystem::path const& archivePath,
    std::string_view             entryName
);

GMLIB_NDAPI ll::Expected<std::string> readFileFromArchive(
    std::filesystem::path const& archivePath,
    std::string_view             entryName,
    std::string_view             password = {}
);

} // namespace gmlib::file_utils
