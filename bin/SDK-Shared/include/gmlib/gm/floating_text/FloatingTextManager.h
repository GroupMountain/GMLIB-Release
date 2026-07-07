#pragma once
#include "base/DynamicFloatingText.h"
#include "base/FloatingText.h"
#include <ll/api/mod/NativeMod.h>
#include <memory>

namespace gmlib {

class FloatingTextManager {
public:
    class Impl;
    std::unique_ptr<Impl> pImpl;

private:
    FloatingTextManager();
    GMLIB_NDAPI bool _add(const std::shared_ptr<FloatingText>& floatingText, const std::weak_ptr<ll::mod::Mod>& mod);

public:
    GMLIB_NDAPI static FloatingTextManager& getInstance();

public:
    template <std::derived_from<FloatingText> T, typename... Args>
    std::weak_ptr<FloatingText> add(Args... args) {
        std::shared_ptr<T> text = std::make_shared<T>(std::forward<Args>(args)...);
        if (_add(text, ll::mod::NativeMod::current())) {
            return text;
        }
        return {};
    }

    GMLIB_API std::weak_ptr<StaticFloatingText> addStatic(
        std::string const&                 text,
        Vec3 const&                        position,
        DimensionType                      dimensionId,
        bool                               translatePlaceholderApi = false,
        const std::weak_ptr<ll::mod::Mod>& mod                     = ll::mod::NativeMod::current()
    );

    GMLIB_API std::weak_ptr<DynamicFloatingText> addDynamic(
        std::string const&                 text,
        Vec3 const&                        position,
        DimensionType                      dimensionId,
        uint                               seconds,
        bool                               translatePlaceholderApi = true,
        const std::weak_ptr<ll::mod::Mod>& mod                     = ll::mod::NativeMod::current()
    );

    GMLIB_API bool remove(
        const std::weak_ptr<FloatingText>& floatingText,
        const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current()
    );

    GMLIB_API bool remove(uint64 runtimeId, const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current());

    GMLIB_NDAPI std::weak_ptr<FloatingText>
                get(uint64 runtimeId, const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current());

    GMLIB_NDAPI std::vector<std::weak_ptr<FloatingText>>
                getAll(const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current());

    GMLIB_NDAPI std::vector<std::weak_ptr<FloatingText>>
                getAll(DimensionType dimId, const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current());

    GMLIB_API void removeAll(const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current());

    GMLIB_API void
    removeAll(DimensionType dimId, const std::weak_ptr<ll::mod::Mod>& mod = ll::mod::NativeMod::current());
};

} // namespace gmlib
