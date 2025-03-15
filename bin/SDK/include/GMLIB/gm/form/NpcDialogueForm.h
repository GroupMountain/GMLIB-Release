#pragma once
#include "gmlib/Macros.h"
#include "gmlib/gm/enum/FormEnums.h"
#include "mc/_HeaderOutputPredefine.h"

namespace gmlib::world::actor {
class GMPlayer;
}

namespace gmlib::form {

class NpcDialogueForm {
public:
    using GMPlayer = world::actor::GMPlayer;

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

    GMLIB_NDAPI NpcDialogueForm(NpcDialogueForm const& other);
    GMLIB_NDAPI NpcDialogueForm& operator=(NpcDialogueForm const& other);
    
    NpcDialogueForm(NpcDialogueForm&&)                 = delete;
    NpcDialogueForm& operator=(NpcDialogueForm&&)      = delete;

public:
    GMLIB_API NpcDialogueForm& setNpcName(std::string const& name);

    GMLIB_API NpcDialogueForm& setSceneName(std::string const& name);

    GMLIB_API NpcDialogueForm& setDialogue(std::string const& dialogue);

    GMLIB_API NpcDialogueForm& addButton(std::string const& name, std::function<void(GMPlayer& pl)> callback = {});

    GMLIB_API NpcDialogueForm& onPlayerClose(std::function<void(GMPlayer& pl)> callback);

    GMLIB_API NpcDialogueForm& addAction(
        std::string const&                name,
        std::function<void(GMPlayer& pl)> callback = {},
        NpcDialogueFormAction             type     = NpcDialogueFormAction::Button,
        std::vector<std::string> const&   commands = {}
    );

    GMLIB_API NpcDialogueForm& sendTo(GMPlayer& pl);
};

} // namespace gmlib::form