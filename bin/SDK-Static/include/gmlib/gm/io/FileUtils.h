#pragma once
#include "gmlib/gm/enum/CompressionLevel.h"
#include <filesystem>
#include <ll/api/Expected.h>
#include <vector>

namespace gmlib::file_utils {

std::vector<std::string> getAllFileNameInDirectory(std::filesystem::path const& path);

std::vector<std::string> getAllFileFullNameInDirectory(std::filesystem::path const& path);

std::vector<std::filesystem::path> getAllFilePathInDirectory(std::filesystem::path const& path);

std::vector<std::filesystem::path> getAllFolderPathInDirectory(std::filesystem::path const& path);

std::vector<std::string> getAllFolderNameInDirectory(std::filesystem::path const& path);

ll::Expected<std::string> readFile(std::filesystem::path const& filePath, bool isBinary = false);

bool writeFile(std::filesystem::path const& filePath, std::string_view content, bool isBinary = false);

ll::Expected<std::string> readCompressedFile(std::filesystem::path const& filePath);

bool writeCompressedFile(
    std::filesystem::path const& filePath,
    std::string_view             content,
    CompressionLevel             level = CompressionLevel::Default
);

bool writeCompressedFile(
    std::filesystem::path const& filePath,
    std::string_view             content,
    size_t                       bufferSize,
    CompressionLevel             level = CompressionLevel::Default
);

bool compressFolder(
    std::filesystem::path const& folderPath,
    std::filesystem::path const& archivePath = {},
    bool                         includeSelf = false,
    bool                         replace     = false,
    CompressionLevel             level       = CompressionLevel::Default,
    std::string_view             password    = {}
);

bool decompressArchive(
    std::filesystem::path const& archivePath,
    std::filesystem::path const& outputPath = {},
    bool                         replace    = false,
    std::string_view             password   = {}
);

bool appendFileToArchive(
    std::filesystem::path const& filePath,
    std::filesystem::path const& archivePath,
    std::string_view             entryName
);

bool appendFolderToArchive(std::filesystem::path const& filePath, std::filesystem::path const& archivePath);

bool appendFileToArchiveFromMemory(
    std::string_view             fileContent,
    std::filesystem::path const& archivePath,
    std::string_view             entryName
);

ll::Expected<std::string> readFileFromArchive(
    std::filesystem::path const& archivePath,
    std::string_view             entryName,
    std::string_view             password = {}
);

} // namespace gmlib::file_utils
