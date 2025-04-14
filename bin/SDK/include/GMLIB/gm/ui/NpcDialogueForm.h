#pragma once
#include "gmlib/Macros.h"
#include "mc/_HeaderOutputPredefine.h"

namespace gmlib {
class GMPlayer;
}

namespace gmlib::ui {

class NpcDialogueForm {
public:
    enum class ActionType : int {
        Button = 0, // Button Mode
        Close  = 1, // Open Command
        Open   = 2, // Close Command
    };

public:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_NDAPI explicit NpcDialogueForm(
        std::string const& npcName,
        std::string const& sceneName,
        std::string const& dialogue
    );

    GMLIB_NDAPI NpcDialogueForm();

    GMLIB_NDAPI NpcDialogueForm(NpcDialogueForm const&);

    GMLIB_NDAPI NpcDialogueForm& operator=(NpcDialogueForm const&);

public:
    GMLIB_API NpcDialogueForm& setNpcName(std::string const& name);

    GMLIB_API NpcDialogueForm& setSceneName(std::string const& name);

    GMLIB_API NpcDialogueForm& setDialogue(std::string const& dialogue);

    GMLIB_API NpcDialogueForm& addButton(std::string const& name, std::function<void(GMPlayer& pl)>&& callback = {});

    GMLIB_API NpcDialogueForm& onPlayerClose(std::function<void(GMPlayer& pl)>&& callback);

    GMLIB_API NpcDialogueForm& addAction(
        std::string const&                  name,
        std::function<void(GMPlayer& pl)>&& callback = {},
        ActionType                          type     = ActionType::Button,
        std::vector<std::string> const&     commands = {}
    );

    GMLIB_API NpcDialogueForm& sendTo(GMPlayer& pl);
};

} // namespace gmlib::ui