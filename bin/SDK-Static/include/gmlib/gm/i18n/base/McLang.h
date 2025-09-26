#pragma once
#include <filesystem>
#include <nlohmann/json.hpp>
#include <optional>
#include <unordered_map>

namespace gmlib::i18n {

class McLang {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    McLang(std::unordered_map<std::string, std::string> const& data);

    McLang();

    McLang(const McLang&);
    McLang(McLang&&) noexcept;
    McLang& operator=(const McLang&);
    McLang& operator=(McLang&&) noexcept;

public:
    virtual ~McLang();

public:
    static McLang parse(std::string const& data);

    static McLang parse_file(std::filesystem::path const& filePath);

    static McLang from_json(std::string const& jsonString);

    static McLang from_json(nlohmann::json const& json);

public:
    std::optional<std::string> try_get(std::string const& key);

    std::string
    translate(std::string const& key, std::vector<std::string> const& param = {}, std::string const& data = "%0$s");

    std::string
    get(std::string const& key, std::vector<std::string> const& param = {}, std::string const& data = "%0$s");

    void set(std::string const& key, std::string const& value);

    bool erase(std::string const& key);

    void erase(std::vector<std::string> const& keys);

    bool has_value(std::string const& key);

    void merge_patch(McLang const& data);

    std::string dump();

    std::string to_json_string(int format = 4);

    nlohmann::json to_json();

    bool write_to_file(std::filesystem::path const& filePath);

    std::unordered_map<std::string, std::string>& getTranslationMap();
};

} // namespace gmlib::i18n