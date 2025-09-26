#pragma once
#include "gmlib/Macros.h"
#include <mc/_HeaderOutputPredefine.h>
#include <unordered_map>


namespace gmlib {
class GMPlayer;
}

namespace gmlib::ui {

class ServerSettingFormManager {
public:
    enum class IconType : unsigned char {
        Texture = 0,
        Url     = 1,
    };

public:
    class Impl;
    std::unique_ptr<Impl> pImpl;
    ServerSettingFormManager();
    using ServerSettingFormCallback = std::function<
        void(GMPlayer& player, std::unordered_map<uint, std::variant<std::string, int64, double, bool>> const&)>;

public:
    GMLIB_NDAPI static ServerSettingFormManager& getInstance();

public:
    GMLIB_NDAPI uint getDefaultPriority();

    GMLIB_NDAPI bool hasTitle();

    GMLIB_NDAPI std::string getTitle(GMPlayer& player);

    GMLIB_API bool setTitle(std::string const& title, bool forceModify = false);

    GMLIB_API bool setTitle(std::function<std::string(GMPlayer& player)>&& title, bool forceModify = false);

    GMLIB_NDAPI bool hasIcon();

    GMLIB_NDAPI std::optional<std::string> getIconData();

    GMLIB_NDAPI std::optional<IconType> getIconType();

    GMLIB_API bool setIcon(std::string const& data, IconType type = IconType::Texture, bool forceModify = false);

    GMLIB_API uint addLabel(
        std::function<std::string(GMPlayer& player)>&& text,
        std::function<bool(GMPlayer& player)>&&        playerDetector = [](GMPlayer&) -> bool { return true; },
        uint priority = ServerSettingFormManager::getInstance().getDefaultPriority()
    );

    GMLIB_API uint addInput(
        std::function<std::string(GMPlayer& player)>&& text,
        std::function<std::string(GMPlayer& player)>&& placeholder = [](GMPlayer&) -> std::string { return {}; },
        std::function<std::string(GMPlayer& player)>&& defaultVal  = [](GMPlayer&) -> std::string { return {}; },
        std::function<void(GMPlayer& player, std::string const& data)>&& callback = {},
        std::function<bool(GMPlayer& player)>&& playerDetector = [](GMPlayer&) -> bool { return true; },
        uint                                    priority = ServerSettingFormManager::getInstance().getDefaultPriority()
    );

    GMLIB_API uint addToggle(
        std::function<std::string(GMPlayer& player)>&&     text,
        std::function<bool(GMPlayer& player)>&&            defaultVal     = [](GMPlayer&) -> bool { return false; },
        std::function<void(GMPlayer& player, bool data)>&& callback       = {},
        std::function<bool(GMPlayer& player)>&&            playerDetector = [](GMPlayer&) -> bool { return true; },
        uint priority = ServerSettingFormManager::getInstance().getDefaultPriority()
    );

    GMLIB_API uint addDropdown(
        std::function<std::string(GMPlayer& player)>&&              text,
        std::function<std::vector<std::string>(GMPlayer& player)>&& options,
        std::function<size_t(GMPlayer& player)>&&                   defaultVal = [](GMPlayer&) -> size_t { return 0; },
        std::function<void(GMPlayer& player, int64 data)>&&         callback   = {},
        std::function<bool(GMPlayer& player)>&& playerDetector                 = [](GMPlayer&) -> bool { return true; },
        uint                                    priority = ServerSettingFormManager::getInstance().getDefaultPriority()
    );

    GMLIB_API uint addSlider(
        std::function<std::string(GMPlayer& player)>&&       text,
        std::function<double(GMPlayer& player)>&&            min,
        std::function<double(GMPlayer& player)>&&            max,
        std::function<double(GMPlayer& player)>&&            step           = [](GMPlayer&) -> double { return 0.0; },
        std::function<double(GMPlayer& player)>&&            defaultVal     = [](GMPlayer&) -> double { return 0.0; },
        std::function<void(GMPlayer& player, double data)>&& callback       = {},
        std::function<bool(GMPlayer& player)>&&              playerDetector = [](GMPlayer&) -> bool { return true; },
        uint priority = ServerSettingFormManager::getInstance().getDefaultPriority()
    );

    GMLIB_API uint addStepSlider(
        std::function<std::string(GMPlayer& player)>&&              text,
        std::function<std::vector<std::string>(GMPlayer& player)>&& steps,
        std::function<size_t(GMPlayer& player)>&&                   defaultVal = [](GMPlayer&) -> size_t { return 0; },
        std::function<void(GMPlayer& player, int64 data)>&&         callback   = {},
        std::function<bool(GMPlayer& player)>&& playerDetector                 = [](GMPlayer&) -> bool { return true; },
        uint                                    priority = ServerSettingFormManager::getInstance().getDefaultPriority()
    );

    GMLIB_API uint addHeader(
        std::function<std::string(GMPlayer& player)>&& text,
        std::function<bool(GMPlayer& player)>&&        playerDetector = [](GMPlayer&) -> bool { return true; },
        uint priority = ServerSettingFormManager::getInstance().getDefaultPriority()
    );

    GMLIB_API uint addDivider(
        std::function<std::string(GMPlayer& player)>&& /*no effect*/ text = [](GMPlayer&) { return ""; },
        std::function<bool(GMPlayer& player)>&& playerDetector            = [](GMPlayer&) -> bool { return true; },
        uint                                    priority = ServerSettingFormManager::getInstance().getDefaultPriority()
    );

    GMLIB_API bool removeElement(uint id);

    GMLIB_API uint registerCallback(ServerSettingFormCallback&& callback);

    GMLIB_API bool unregisterCallback(uint callbackId);
};

} // namespace gmlib::ui

#define GMLIB_REGISTER_SERVER_SETTING_FORM(REGISTER_FROM_FUNC)                                                         \
    inline static auto GMLIB_SERVER_SETTING_FORM_##REGISTER_FROM_FUNC = [] {                                           \
        REGISTER_FROM_FUNC(::gmlib::ui::ServerSettingFormManager::getInstance());                                      \
        return 0;                                                                                                      \
    }();

#define GMLIB_REGISTER_SERVER_SETTING_FORMS(IDENTIFIER, REGISTER_FROM_FUNC)                                            \
    inline static auto GMLIB_SERVER_SETTING_FORM_##IDENTIFIER = [] {                                                   \
        REGISTER_FROM_FUNC(::gmlib::ui::ServerSettingFormManager::getInstance());                                      \
        return 0;                                                                                                      \
    }();