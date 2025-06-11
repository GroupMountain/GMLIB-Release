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

namespace gmlib {

class GMPlayer;
class GMCompoundTag;

class GMBinaryStream : public BinaryStream {
public:
    GMLIB_API void writePacketHeader(MinecraftPacketIds packetId, SubClientId subId = SubClientId::PrimaryClient);
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

public:
    template <typename T>
    bool read(T* target, bool bigEndian = false);

    template <typename T>
    [[nodiscard]] inline Bedrock::Result<T> getType(T const& x) {
        return serialize<T>::read(x, *this);
    }
    GMLIB_API bool   getBool();
    GMLIB_API uchar  getByte();
    GMLIB_API double getDouble();
    GMLIB_API float  getFloat();
    GMLIB_API int    getSignedBigEndianInt();
    GMLIB_API int    getSignedInt();
    GMLIB_API int64  getSignedInt64();
    GMLIB_API short  getSignedShort();
    GMLIB_API std::string getString();
    GMLIB_API void        getString(std::string& outStringStream);
    GMLIB_API uchar       getUnsignedChar();
    GMLIB_API uint        getUnsignedInt();
    GMLIB_API uint64      getUnsignedInt64();
    GMLIB_API ushort      getUnsignedShort();
    GMLIB_API uint        getUnsignedVarInt();
    GMLIB_API uint64      getUnsignedVarInt64();
    GMLIB_API int         getVarInt();
    GMLIB_API int64       getVarInt64();

    template <typename T>
    inline void writeType(T const& x) {
        serialize<T>::write(x, *this);
    }
    GMLIB_API void writeCompoundTag(GMCompoundTag const& data);
    GMLIB_API void writeDataItem(std::vector<std::unique_ptr<::DataItem>> const& data);
    GMLIB_API void writeVec3(::Vec3 const& data);
    GMLIB_API void writeVec2(::Vec2 const& data);
    GMLIB_API void writeBlockPos(::BlockPos const& data);
    GMLIB_API void writeAbilitiesData(::SerializedAbilitiesData const& data);
    GMLIB_API void writeSkin(::SerializedSkin const& data);
    GMLIB_API void writeActorLink(::ActorLink const& data);
    GMLIB_API void writeUuid(::mce::UUID const& data);
    GMLIB_API void writeNetworkItemStackDescriptor(::NetworkItemStackDescriptor const& data);
    GMLIB_API void writeMoveActorAbsoluteData(::MoveActorAbsoluteData const& data);

    // Using GMBinaryStream::write##TYPE(value) to call the following functions
    // Example: GMBinaryStream::writeBool(true);
    // Example: GMBinaryStream::writeByte(0);
    // Example: GMBinaryStream::writeUnsignedShort(0);

#define GMBinaryStream_Write_Macro(TYPE, WRITE_TYPE)                                                                   \
    template <typename T>                                                                                              \
        requires(std::is_enum_v<T> || std::is_integral_v<T> || std::is_floating_point_v<T>)                            \
    inline constexpr void write##TYPE(T value) {                                                                       \
        BinaryStream::write##TYPE(static_cast<WRITE_TYPE>(value), nullptr, nullptr);                                   \
    }

    GMBinaryStream_Write_Macro(Bool, bool);
    GMBinaryStream_Write_Macro(Byte, uchar);
    GMBinaryStream_Write_Macro(UnsignedShort, ushort);
    GMBinaryStream_Write_Macro(SignedShort, short);
    GMBinaryStream_Write_Macro(UnsignedInt, uint);
    GMBinaryStream_Write_Macro(SignedBigEndianInt, int);
    GMBinaryStream_Write_Macro(SignedInt, int);
    GMBinaryStream_Write_Macro(UnsignedInt64, uint64);
    GMBinaryStream_Write_Macro(SignedInt64, int64);
    GMBinaryStream_Write_Macro(UnsignedVarInt, uint);
    GMBinaryStream_Write_Macro(UnsignedVarInt64, uint64);
    GMBinaryStream_Write_Macro(VarInt, int);
    GMBinaryStream_Write_Macro(VarInt64, int64);
    GMBinaryStream_Write_Macro(Double, double);
    GMBinaryStream_Write_Macro(Float, float);
    GMBinaryStream_Write_Macro(NormalizedFloat, float);
    template <typename T>
        requires(std ::is_enum_v<T> || std ::is_integral_v<T> || std ::is_floating_point_v<T>)
    inline constexpr void writeUnsignedChar(T value) {
        BinaryStream::writeByte(static_cast<uchar>(value), nullptr, nullptr);
    }

    template <ll::concepts::IsString T>
    inline void writeString(T value) {
        BinaryStream::writeString(std::string_view{value}, nullptr, nullptr);
    }

#undef GMBinaryStream_Write_Macro
};

} // namespace gmlib
