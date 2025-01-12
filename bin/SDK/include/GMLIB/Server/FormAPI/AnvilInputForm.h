#pragma once
#include "GMLIB/Macros.h"
#include <mc/deps/core/utility/optional_ref.h>
#include <mc/nbt/CompoundTag.h>
#include <mc/world/actor/player/Player.h>
#include <mc/world/item/ItemStack.h>

namespace GMLIB::Server::Form {

using AnvilInputFormCallback = std::function<void(Player&, std::string const&)>;
using AnvilCloseCallback     = std::function<void(Player&)>;

class AnvilInputForm {
public:
    ItemStack              mItem          = ItemStack::EMPTY_ITEM();
    AnvilInputFormCallback mCallback      = {};
    AnvilCloseCallback     mCloseCallback = {};

public:
    GMLIB_NDAPI explicit AnvilInputForm(std::string const& name, std::vector<std::string> lores = {});

    GMLIB_NDAPI explicit AnvilInputForm(ItemStack const& item);

    GMLIB_NDAPI AnvilInputForm();

public:
    GMLIB_API AnvilInputForm& setItem(ItemStack const& item);

    GMLIB_API AnvilInputForm& setItem(std::string const& name, std::vector<std::string> lores = {});

    GMLIB_API AnvilInputForm&
    sendTo(Player& pl, AnvilInputFormCallback callback, AnvilCloseCallback closeCallback = {});

public:
    GMLIB_API static bool                         close(Player& pl);
    GMLIB_API static optional_ref<AnvilInputForm> getPlayerForm(Player& pl);
};

} // namespace GMLIB::Server::Form