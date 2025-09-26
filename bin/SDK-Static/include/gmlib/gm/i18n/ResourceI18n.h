#pragma once
#include "gmlib/gm/i18n/base/McLang.h"
#include "ll/api/data/Version.h"
#include <memory>


namespace gmlib::i18n {

class ResourceI18n {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    ResourceI18n(
        std::filesystem::path const& directoryPath,
        std::string const&           pluginName,
        ushort                       versionMajor = 0,
        ushort                       versionMinor = 0,
        ushort                       versionPatch = 1
    );

    ResourceI18n() = delete;

    ~ResourceI18n();

public:
    void addLanguage(std::string const& identifier, std::string const& language);

    void addLanguage(std::string const& identifier, McLang const& language);

    void addLanguageFromPath(std::string const& identifier, std::filesystem::path const& path);

    void addLanguages(std::vector<std::pair<std::string, McLang>> const& languages);

    void addLanguages(std::vector<std::pair<std::string, std::string>> const& languages);

    void addLanguagesFromDirectory(std::filesystem::path const& path);

    void loadAllLanguages();
};

} // namespace gmlib::i18n