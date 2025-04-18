#pragma once
#include <filesystem>
#include <gmlib/Macros.h>
#include <ll/api/Expected.h>
#include <ll/api/utils/SystemUtils.h>

namespace gmlib::memory {

class MemoryArchive {
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
    GMLIB_NDAPI explicit MemoryArchive(std::string_view memoryStream, std::string_view password = {});

    GMLIB_NDAPI ~MemoryArchive();

    GMLIB_NDAPI bool isOpen() const;

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

public:
    GMLIB_NDAPI static std::optional<MemoryArchive> fromResource(
        int                           resourceId,
        std::string_view              password = {},
        ll::utils::sys_utils::HandleT handle   = ll::sys_utils::getCurrentModuleHandle()
    );

    GMLIB_NDAPI static std::optional<MemoryArchive>
    fromDiskArchive(std::filesystem::path const& path, std::string_view password = {});
};

} // namespace gmlib::memory