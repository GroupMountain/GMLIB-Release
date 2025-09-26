#pragma once
#include "McLang.h"
#include "nlohmann/json.hpp"

namespace gmlib::i18n {

class JsonLanguage : public McLang {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    ~JsonLanguage() override;

public:
    JsonLanguage(std::filesystem::path const& filePath, std::string const& defaultJson);

    JsonLanguage(std::filesystem::path const& filePath, nlohmann::json const& defaultJson);

    JsonLanguage(
        std::filesystem::path const&                        filePath,
        std::unordered_map<std::string, std::string> const& defaultLanguage
    );

    JsonLanguage(std::filesystem::path const& filePath, McLang const& defaultLanguage);

    JsonLanguage() = delete;


public:
    bool init();

    bool reload();

    bool save_file();
};

} // namespace gmlib::i18n