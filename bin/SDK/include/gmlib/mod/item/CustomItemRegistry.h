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

protected:
    GMLIB_NDAPI CustomItemRegistry& _registerItem(std::function<std::unique_ptr<Item>()>&&);
};

} // namespace gmlib::mod

#define GMLIB_REGISTER_ITEM(ITEM_CLASS, ...)                                                                           \
    auto GMLIB_CUSTOM_ITEM_##ITEM_CLASS = [] {                                                                         \
        CustomItemRegistry::getInstance().registerItem<ITEM_CLASS>(__VA_ARGS__);                                       \
        return 0;                                                                                                      \
    }();