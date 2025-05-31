#pragma once
#include <gmlib/mod/item/base/ICustomItem.h>

namespace gmlib::mod {

class ICustomToolItem : public ICustomItem {
public:
    GMLIB_NDAPI ICustomToolItem(std::string const& identifier);

    GMLIB_API virtual bool isSword() const;

    GMLIB_API virtual bool isAxe() const;

    GMLIB_API virtual bool isPickaxe() const;

    GMLIB_API virtual bool isShovel() const;

    GMLIB_API virtual bool isHoe() const;

    GMLIB_API bool isHandEquipped() const override;

    GMLIB_API uint8_t getItemMaxStackSize() const override;

    GMLIB_API bool canDestroyInCreative() const override;

    GMLIB_API CreativeItemCategory getCreativeCategory() const override;

    GMLIB_API std::string getCreativeGroup() const override;

    GMLIB_API Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override;

    GMLIB_API bool isDiggerItem() const override;

    GMLIB_API bool canDestroySpecial(Block const& block) const override;

    GMLIB_API void executeEvent(::ItemStackBase& item, ::std::string const& ev, ::RenderParams& rp) const override;

    GMLIB_API void _init() override;
};

} // namespace gmlib::mod
