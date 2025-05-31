#pragma once
#include <gmlib/mod/item/base/ICustomArmorItem.h>
#include <gmlib/mod/item/base/ICustomItem.h>

namespace gmlib::mod {

class CustomItemRegistry {
public:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    CustomItemRegistry();
    CustomItemRegistry& operator=(CustomItemRegistry const&) = delete;
    CustomItemRegistry(CustomItemRegistry const&)            = delete;

public:
    GMLIB_NDAPI static CustomItemRegistry& getInstance();

public:
    template <std::derived_from<Item> T, class... Args>
    CustomItemRegistry& registerItem(Args&&... args) {
        return _registerItem([... args = std::forward<Args>(args)]() -> std::unique_ptr<Item> {
            auto item = std::make_unique<T>(args...);
            if constexpr (requires { item->_init(); }) item->_init();
            return std::move(item);
        });
    }

    GMLIB_API void forEachItemInRegistry(std::function<bool(Item& item)>&& func);

    GMLIB_NDAPI ::WeakPtr<::Item> getItem(std::string_view name);

public:
    GMLIB_API bool setFireResistant(std::string_view itemName, bool value = true);

    GMLIB_API bool addTag(std::string_view itemName, std::string_view tag);

    GMLIB_API bool setIcon(std::string_view itemName, std::string_view icon);

    GMLIB_API bool setDisplayName(std::string_view itemName, std::string_view displayName);

    GMLIB_API bool setRepairItem(std::string_view itemName, std::string_view fixItem);

    GMLIB_NDAPI ::CompoundTag& getAndModifyVanillaNetworkTagInfo(std::string_view itemName);

public:
    GMLIB_NDAPI CustomItemRegistry& _modifyItem(std::function<void(CustomItemRegistry&)>&&);

    GMLIB_NDAPI CustomItemRegistry& _registerItem(std::function<std::unique_ptr<Item>()>&&);
};

} // namespace gmlib::mod

#define GMLIB_REGISTER_ITEM(ITEM_CLASS, ...)                                                                           \
    inline static auto GMLIB_CUSTOM_ITEM_##ITEM_CLASS = [] {                                                           \
        ::gmlib::mod::CustomItemRegistry::getInstance().registerItem<ITEM_CLASS>(__VA_ARGS__);                         \
        return 0;                                                                                                      \
    }();

#define GMLIB_REGISTER_ITEMS(IDENTIFIER, ITEM_CLASS, ...)                                                              \
    inline static auto GMLIB_CUSTOM_ITEM_##IDENTIFIER = [] {                                                           \
        ::gmlib::mod::CustomItemRegistry::getInstance().registerItem<ITEM_CLASS>(__VA_ARGS__);                         \
        return 0;                                                                                                      \
    }();