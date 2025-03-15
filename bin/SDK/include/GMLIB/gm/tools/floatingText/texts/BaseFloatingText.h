#pragma once
#include "gmlib/Macros.h"
#include <mc/_HeaderOutputPredefine.h>


class Vec3;

namespace gmlib::world::actor {
class GMPlayer;
}

namespace gmlib::tools {
class BaseFloatingText {

public:
    using GMPlayer = world::actor::GMPlayer;

protected:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    GMLIB_NDAPI
    BaseFloatingText(
        std::string const& text,
        Vec3 const&        position,
        DimensionType      dimensionId,
        bool               translatePlaceholderApi = false
    );

public:
    GMLIB_API virtual ~BaseFloatingText();

    GMLIB_NDAPI virtual bool isDynamic() const;

    GMLIB_API virtual void sendTo(GMPlayer& pl);

    GMLIB_API virtual void sendToClients();

    GMLIB_API virtual void update(GMPlayer& pl);

    GMLIB_API virtual void updateClients();

    GMLIB_API virtual void removeFrom(GMPlayer& pl);

    GMLIB_API virtual void removeFromClients();

    GMLIB_NDAPI virtual int getRuntimeID() const;

    GMLIB_NDAPI virtual std::string getText() const;

    GMLIB_NDAPI virtual Vec3 getPosition() const;

    GMLIB_NDAPI virtual DimensionType getDimensionId() const;

    GMLIB_NDAPI virtual bool shouldTranslatePlaceholderApi() const;

    GMLIB_API virtual void setText(std::string const& newText);

    GMLIB_API virtual void setPosition(Vec3 const& pos);

    GMLIB_API virtual void setDimensionId(DimensionType dimId);

    GMLIB_API virtual void setTranslatePlaceholderApi(bool value);
};
} // namespace gmlib::tools