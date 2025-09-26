#pragma once
#include "gmlib/gm/enum/CompressionLevel.h"
#include "gmlib/gm/memory/MemoryArchive.h"
#include <filesystem>
#include <ll/api/Expected.h>

namespace gmlib::zip_utils {

class Zipper {
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    explicit Zipper(std::filesystem::path const& archivePath, bool append = false);

    ~Zipper();

    bool isOpen() const;

    Zipper& setCompressionLevel(CompressionLevel level);

    Zipper& setPassword(std::string_view password);

    Zipper& setComment(std::string_view comment);

    ll::Expected<void> addFile(std::filesystem::path const& filePath, std::string_view entryName = {});

    ll::Expected<void> addDirctory(std::filesystem::path const& folderPath, bool includeSelf = false);

    ll::Expected<void> addBinary(std::string_view binaryData, std::string_view entryName);
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
        ~Iterator();

        ll::Expected<std::string> dumpCurrentEntry() const;

        ll::Expected<void> extractCurrentEntry(std::filesystem::path const& path) const;

        ll::Expected<void> extractCurrentEntryTo(std::filesystem::path const& filePath) const;

        Iterator& operator++();

        const Entry& operator*() const;

        bool operator!=(const Iterator&) const;
    };

public:
    explicit Unzipper(std::filesystem::path const& path, std::string_view password = {});

    ~Unzipper();

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
};

} // namespace gmlib::zip_utils
