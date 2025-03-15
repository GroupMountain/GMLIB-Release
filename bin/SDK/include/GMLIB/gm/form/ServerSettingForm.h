#pragma once
#include "gmlib/Macros.h"
#include "gmlib/gm/enum/FormEnums.h"
#include <mc/_HeaderOutputPredefine.h>


namespace gmlib::world::actor {
class GMPlayer;
}

namespace gmlib::form {

class ServerSettingForm {
public:
    using GMPlayer = world::actor::GMPlayer;

public:
    GMLIB_NDAPI static int getDefaultPriority();

    GMLIB_NDAPI static bool hasTitle();

    GMLIB_NDAPI static std::string getTitle();

    GMLIB_API static bool setTitle(std::string const& title, bool forceModify = false);

    GMLIB_NDAPI static bool hasIcon();

    GMLIB_NDAPI static std::optional<std::string> getIconData();

    GMLIB_NDAPI static std::optional<IconType> getIconType();

    GMLIB_API static bool setIcon(std::string const& data, IconType type = IconType::Texture, bool forceModify = false);

    GMLIB_API static uint addLabel(
        std::string const&                    text,
        std::function<bool(GMPlayer& player)> playerDetector = [](GMPlayer&) -> bool { return true; },
        uint                                  priority       = getDefaultPriority()
    );

    GMLIB_API static uint addInput(
        std::string const&                                             text,
        std::string const&                                             placeholder = {},
        std::string const&                                             defaultVal  = {},
        std::function<void(GMPlayer& player, std::string const& data)> callback    = nullptr,
        std::function<bool(GMPlayer& player)> playerDetector = [](GMPlayer&) -> bool { return true; },
        uint                                  priority       = getDefaultPriority()
    );

    GMLIB_API static uint addToggle(
        std::string const&                               text,
        bool                                             defaultVal     = false,
        std::function<void(GMPlayer& player, bool data)> callback       = nullptr,
        std::function<bool(GMPlayer& player)>            playerDetector = [](GMPlayer&) -> bool { return true; },
        uint                                             priority       = getDefaultPriority()
    );

    GMLIB_API static uint addDropdown(
        std::string const&                                text,
        std::vector<std::string> const&                   options,
        size_t                                            defaultVal     = 0,
        std::function<void(GMPlayer& player, int64 data)> callback       = nullptr,
        std::function<bool(GMPlayer& player)>             playerDetector = [](GMPlayer&) -> bool { return true; },
        uint                                              priority       = getDefaultPriority()
    );

    GMLIB_API static uint addSlider(
        std::string const&                                 text,
        double                                             min,
        double                                             max,
        double                                             step           = 0.0,
        double                                             defaultVal     = 0.0,
        std::function<void(GMPlayer& player, double data)> callback       = nullptr,
        std::function<bool(GMPlayer& player)>              playerDetector = [](GMPlayer&) -> bool { return true; },
        uint                                               priority       = getDefaultPriority()
    );

    GMLIB_API static uint addStepSlider(
        std::string const&                                text,
        std::vector<std::string> const&                   steps,
        size_t                                            defaultVal     = 0,
        std::function<void(GMPlayer& player, int64 data)> callback       = nullptr,
        std::function<bool(GMPlayer& player)>             playerDetector = [](GMPlayer&) -> bool { return true; },
        uint                                              priority       = getDefaultPriority()
    );

    GMLIB_API static bool removeElement(uint id);
};

} // namespace gmlib::form