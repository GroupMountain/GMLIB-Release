#pragma once
#include "gmlib/Macros.h"
#include <mc/deps/core/utility/BinaryStream.h>
#include <mc/network/MinecraftPackets.h>

class CompoundTag;
class DataItem;
class Vec3;
class Vec2;
class SerializedAbilitiesData;
class SerializedSkin;
class NetworkItemStackDescriptor;
struct ActorLink;
namespace mce {
class UUID;
}
namespace gmlib::world::actor {
class GMPlayer;
}
namespace gmlib::world {
class GMCompoundTag;
}

namespace gmlib::network {

class GMBinaryStream : public BinaryStream {
public:
    using GMPlayer      = world::actor::GMPlayer;
    using GMCompoundTag = world::GMCompoundTag;

public:
    GMLIB_API void writePacketHeader(MinecraftPacketIds packetId, SubClientId subId = SubClientId::PrimaryClient);

    // Notice:
    // These sendTo func will translate the packet automatically by using the Glacie if Glacie is existed
    GMLIB_API void sendTo(
        GMPlayer&                player,
        NetworkPeer::Reliability reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility          compressible = Compressibility::Compressible
    );

    GMLIB_API void sendTo(
        ::NetworkIdentifier const& netId,
        NetworkPeer::Reliability   reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility            compressible = Compressibility::Compressible
    );

    GMLIB_API void sendToClients(
        NetworkPeer::Reliability reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility          compressible = Compressibility::Compressible
    );

    GMLIB_API void sendToDimension(
        DimensionType            dimId,
        NetworkPeer::Reliability reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility          compressible = Compressibility::Compressible
    );

    // translate the stream to the given version by using Glacie
    [[deprecated("will be deleted at bds 1.21.7x version")]] GMLIB_API void translate(int toVersion);

public:
    template <typename T>
    inline void writeType(T const& x) {
        serialize<T>::write(x, *this);
    }

    template <typename T>
    [[nodiscard]] inline Bedrock::Result<T> getType(T const& x) {
        return serialize<T>::read(x, *this);
    }

    GMLIB_NDAPI Bedrock::Result<std::string> getString();

    GMLIB_API void writeCompoundTag(GMCompoundTag const& data);

    GMLIB_API void writeDataItem(std::vector<std::unique_ptr<::DataItem>> const& data);

    GMLIB_API void writeVec3(::Vec3 const& data);

    GMLIB_API void writeVec2(::Vec2 const& data);

    GMLIB_API void writeBlockPos(::BlockPos const& data);

    GMLIB_API void writeAbilitiesData(::SerializedAbilitiesData const& data);

    GMLIB_API void writeSkin(::SerializedSkin const& data);

    GMLIB_API void writeActorLink(::ActorLink const& data);

    GMLIB_API void writeUuid(::mce::UUID const& data);

    GMLIB_API void writeNetworkItemStackDescriptor(::NetworkItemStackDescriptor const& nItem);

    // For adapt
    GMLIB_API void writeBool(bool value);

    GMLIB_API void writeByte(uchar value);

    GMLIB_API void writeUnsignedShort(ushort value);

    GMLIB_API void writeSignedShort(short value);

    GMLIB_API void writeUnsignedInt(uint value);

    GMLIB_API void writeSignedBigEndianInt(int value);

    GMLIB_API void writeSignedInt(int value);

    GMLIB_API void writeUnsignedInt64(uint64 value);

    GMLIB_API void writeSignedInt64(int64 value);

    GMLIB_API void writeUnsignedVarInt(uint uvalue);

    GMLIB_API void writeUnsignedVarInt64(uint64 uvalue);

    GMLIB_API void writeVarInt(int value);

    GMLIB_API void writeVarInt64(int64 value);

    GMLIB_API void writeDouble(double value);

    GMLIB_API void writeFloat(float value);

    GMLIB_API void writeNormalizedFloat(float value);

    GMLIB_API void writeString(::std::string_view value);

    GMLIB_API void writeUnsignedChar(uchar value);
};

} // namespace gmlib::network
