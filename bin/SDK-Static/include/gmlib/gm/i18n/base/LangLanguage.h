#pragma once
#include "McLang.h"

namespace gmlib::i18n {

class LangLanguage : public McLang {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    virtual ~LangLanguage() override;

public:
    LangLanguage(std::filesystem::path const& filePath, std::string const& defaultLanguage);

    LangLanguage(std::filesystem::path const& filePath, McLang const& defaultLanguage);

    LangLanguage(
        std::filesystem::path const&                        filePath,
        std::unordered_map<std::string, std::string> const& defaultLanguage
    );

public:
    bool init();

    bool reload();

    bool save_file();
};

} // namespace gmlib::i18n