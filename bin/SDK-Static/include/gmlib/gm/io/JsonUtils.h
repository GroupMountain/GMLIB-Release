#pragma once
#include <nlohmann/json.hpp>

namespace gmlib::json_utils {

nlohmann::ordered_json initOrderedJson(std::filesystem::path const& path, nlohmann::ordered_json const& defaultFile);

nlohmann::ordered_json initOrderedJson(std::filesystem::path const& path, std::string const& defaultFile);

nlohmann::json initJson(std::filesystem::path const& path, nlohmann::json const& defaultFile);

nlohmann::json initJson(std::filesystem::path const& path, std::string const& defaultFile);

void writeOrUpdateOrderedFile(std::filesystem::path const& path, nlohmann::ordered_json const& defaultFile);

void writeOrUpdateFile(std::filesystem::path const& path, nlohmann::json const& defaultFile);

void updateOrderedFile(std::filesystem::path const& path, nlohmann::ordered_json const& newFile);

void updateOrderedFile(std::filesystem::path const& path, std::string const& newFile);

void updateFile(std::filesystem::path const& path, nlohmann::json const& newFile);

void updateFile(std::filesystem::path const& path, std::string const& newFile);

nlohmann::ordered_json readFromOrderedFile(std::filesystem::path const& path);

nlohmann::json readFromFile(std::filesystem::path const& path);

bool writeOrderedFile(std::filesystem::path const& path, nlohmann::ordered_json const& json);

bool writeFile(std::filesystem::path const& path, nlohmann::json const& json);

template <typename T>
[[nodiscard]] inline std::optional<T>
getValue(nlohmann::ordered_json& json, std::vector<std::string> const& keyPath) try {
    if (keyPath.empty()) return std::nullopt;
    auto value = json;
    for (auto& key : keyPath) {
        if (!value.is_object() || !value.contains(key)) return std::nullopt;
        value = value[key];
    }
    return value.get<T>();
} catch (...) {
    return std::nullopt;
}

template <typename T>
[[nodiscard]] inline std::optional<T> getValue(nlohmann::json& json, std::vector<std::string> const& keyPath) try {
    if (keyPath.empty()) return std::nullopt;
    auto value = json;
    for (auto& key : keyPath) {
        if (!value.is_object() || !value.contains(key)) return std::nullopt;
        value = value[key];
    }
    return value.get<T>();
} catch (...) {
    return std::nullopt;
}

template <typename T>
[[nodiscard]] inline T
getValue(nlohmann::ordered_json& json, std::vector<std::string> const& keyPath, T defaultValue) try {
    std::optional<T> result = getValue<T>(json, keyPath);
    if (result.has_value()) return result.value();
    setValue<T>(json, keyPath, defaultValue);
    return defaultValue;
} catch (...) {
    setValue<T>(json, keyPath, defaultValue);
    return defaultValue;
}

template <typename T>
[[nodiscard]] inline T getValue(nlohmann::json& json, std::vector<std::string> const& keyPath, T defaultValue) try {
    std::optional<T> result = getValue<T>(json, keyPath);
    if (result.has_value()) return result.value();
    setValue<T>(json, keyPath, defaultValue);
    return defaultValue;
} catch (...) {
    setValue<T>(json, keyPath, defaultValue);
    return defaultValue;
}

template <typename T>
inline bool setValue(nlohmann::ordered_json& json, std::vector<std::string> const& keyPath, T data) try {
    if (keyPath.empty()) return false;
    nlohmann::ordered_json* jsonObj = &json;
    for (auto& key : keyPath) {
        if (jsonObj->is_null()) *jsonObj = nlohmann::ordered_json::object();
        jsonObj = &(*jsonObj)[key];
    }
    *jsonObj = data;
    return true;
} catch (...) {
    return false;
}

template <typename T>
inline bool setValue(nlohmann::json& json, std::vector<std::string> const& keyPath, T data) try {
    if (keyPath.empty()) return false;
    nlohmann::json* jsonObj = &json;
    for (auto& key : keyPath) {
        if (jsonObj->is_null()) *jsonObj = nlohmann::json::object();
        jsonObj = &(*jsonObj)[key];
    }
    *jsonObj = data;
    return true;
} catch (...) {
    return false;
}

template <typename T>
inline bool setValueAndSave(
    nlohmann::ordered_json&         json,
    std::string const&              filePath,
    std::vector<std::string> const& keyPath,
    T                               data
) {
    if (setValue<T>(json, keyPath, data)) {
        return writeOrderedFile(filePath, json);
    }
    return false;
}

template <typename T>
inline bool
setValueAndSave(nlohmann::json& json, std::string const& filePath, std::vector<std::string> const& keyPath, T data) {
    if (setValue<T>(json, keyPath, data)) {
        return writeFile(filePath, json);
    }
    return false;
}

bool deleteOrderedKey(nlohmann::ordered_json& json, std::vector<std::string> const& keyPath);

bool deleteKey(nlohmann::json& json, std::vector<std::string> const& keyPath);

bool deleteOrderedKeyAndSave(
    nlohmann::ordered_json&         json,
    std::string const&              filePath,
    std::vector<std::string> const& keyPath
);

bool deleteKeyAndSave(nlohmann::json& json, std::string const& filePath, std::vector<std::string> const& keyPath);

} // namespace gmlib::json_utils