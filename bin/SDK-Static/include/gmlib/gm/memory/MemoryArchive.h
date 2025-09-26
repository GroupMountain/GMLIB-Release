#pragma once
#include <filesystem>
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
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        ~Iterator();

        ll::Expected<std::string> dumpCurrentEntry() const;

        ll::Expected<void> extractCurrentEntry(std::filesystem::path const& path) const;

        ll::Expected<void> extractCurrentEntryTo(std::filesystem::path const& filePath) const;

        Iterator& operator++();

        const Entry& operator*() const;

        bool operator!=(const Iterator&) const;
    };

public:
    explicit MemoryArchive(std::string_view memoryStream, std::string_view password = {});

    ~MemoryArchive();

    bool isOpen() const;

    ll::Expected<std::string> readEntry(std::string_view entryName) const;

    ll::Expected<void>
    writeEntry(std::string_view entryName, std::filesystem::path const& filePath, bool replace = false) const;

    std::unordered_map<std::string, std::string> readEntries(std::vector<std::string> const& entriesName) const;

    ll::Expected<void>
    extractEntry(std::string_view entryName, std::filesystem::path const& path, bool replace = false) const;

    ll::Expected<void>
    extractEntries(std::vector<std::string> const& entriesName, std::filesystem::path const& path, bool replace = false)
        const;

    ll::Expected<void> extractAll(std::filesystem::path const& path, bool replace = false) const;

    ll::Expected<void>
    extractAll(std::filesystem::path const& path, std::function<bool(Entry const&)>&& needExtract, bool replace = false)
        const;

    std::vector<Entry> getEntries() const;

    std::vector<Entry> getFileEntries() const;

    std::vector<Entry> getFolderEntries() const;

    Iterator begin() const;

    Iterator end() const;

    bool contains(std::string_view entryName) const;

public:
    static std::optional<MemoryArchive> fromResource(
        int                           resourceId,
        std::string_view              password = {},
        ll::utils::sys_utils::HandleT handle   = ll::sys_utils::getCurrentModuleHandle()
    );

    static std::optional<MemoryArchive>
    fromDiskArchive(std::filesystem::path const& path, std::string_view password = {});
};

} // namespace gmlib::memory