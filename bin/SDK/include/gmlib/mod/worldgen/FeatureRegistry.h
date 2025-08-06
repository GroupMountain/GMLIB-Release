#pragma once
#include <gmlib/mod/worldgen/ICustomFeature.h>
#include <ll/api/coro/Generator.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>


namespace gmlib::mod {
GMLIB_API void registerFeature(const std::string& identifier, std::unique_ptr<IFeature> feature);
GMLIB_API void registerFeatureRule(
    const std::string&                                                                         identifier,
    const std::vector<std::string>&                                                            passes,
    const std::string&                                                                         placeFeature,
    std::function<ll::coro::Generator<BlockPos>(const BlockHelper&, const BlockPos&, Random&)> rule
);
// register data driven feature and feature rule
GMLIB_API void registerFeature(const nlohmann::json& json);
GMLIB_API void registerFeatureRule(const nlohmann::json& json);
} // namespace gmlib::mod