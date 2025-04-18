#pragma once
#include <filesystem>
#include <gmlib/Macros.h>
#include <gmlib/gm/enum/CompressionLevel.h>
#include <gmlib/gm/memory/MemoryArchive.h>
#include <ll/api/Expected.h>

namespace gmlib::zip_utils {

class Zipper {
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_NDAPI explicit Zipper(std::filesystem::path const& archivePath, bool append = false);

    GMLIB_API ~Zipper();

    GMLIB_NDAPI bool isOpen() const;

    GMLIB_API Zipper& setCompressionLevel(CompressionLevel level);

    GMLIB_API Zipper& setPassword(std::string_view password);

    GMLIB_API Zipper& setComment(std::string_view comment);

    GMLIB_API ll::Expected<void> addFile(std::filesystem::path const& filePath, std::string_view entryName = {});

    GMLIB_API ll::Expected<void> addDirctory(std::filesystem::path const& folderPath, bool includeSelf = false);

    GMLIB_API ll::Expected<void> addBinary(std::string_view binaryData, std::string_view entryName);
};

class Unzipper {
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    struct Entry {
        std::string mName;
        size_t      mCompressedSize;
        size_t      mUncompressedSize;
        bool        mIsRegularFile;
    };

    class Iterator {
    public:
        struct Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        GMLIB_API ~Iterator();

        GMLIB_NDAPI ll::Expected<std::string> dumpCurrentEntry() const;

        GMLIB_API ll::Expected<void> extractCurrentEntry(std::filesystem::path const& path) const;

        GMLIB_API ll::Expected<void> extractCurrentEntryTo(std::filesystem::path const& filePath) const;

        GMLIB_API Iterator& operator++();

        GMLIB_API const Entry& operator*() const;

        GMLIB_API bool operator!=(const Iterator&) const;
    };

public:
    GMLIB_NDAPI explicit Unzipper(std::filesystem::path const& path, std::string_view password = {});

    GMLIB_API ~Unzipper();

    GMLIB_API bool isOpen() const;

    GMLIB_NDAPI ll::Expected<std::string> readEntry(std::string_view entryName) const;

    GMLIB_NDAPI ll::Expected<void>
    writeEntry(std::string_view entryName, std::filesystem::path const& filePath, bool replace = false) const;

    GMLIB_NDAPI std::unordered_map<std::string, std::string>
                readEntries(std::vector<std::string> const& entriesName) const;

    GMLIB_API ll::Expected<void>
              extractEntry(std::string_view entryName, std::filesystem::path const& path, bool replace = false) const;

    GMLIB_API ll::Expected<void> extractEntries(
        std::vector<std::string> const& entriesName,
        std::filesystem::path const&    path,
        bool                            replace = false
    ) const;

    GMLIB_API ll::Expected<void> extractAll(std::filesystem::path const& path, bool replace = false) const;

    GMLIB_API ll::Expected<void> extractAll(
        std::filesystem::path const&        path,
        std::function<bool(Entry const&)>&& needExtract,
        bool                                replace = false
    ) const;

    GMLIB_NDAPI std::vector<Entry> getEntries() const;

    GMLIB_NDAPI std::vector<Entry> getFileEntries() const;

    GMLIB_NDAPI std::vector<Entry> getFolderEntries() const;

    GMLIB_NDAPI Iterator begin() const;

    GMLIB_NDAPI Iterator end() const;

    GMLIB_NDAPI bool contains(std::string_view entryName) const;
};

} // namespace gmlib::zip_utils
