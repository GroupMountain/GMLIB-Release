#pragma once
#include <mc/common/SubClientId.h>
#include <mc/deps/core/utility/BinaryStream.h>
#include <mc/network/Compressibility.h>
#include <mc/network/MinecraftPacketIds.h>
#include <mc/network/NetworkIdentifier.h>
#include <mc/network/NetworkPeer.h>

class CompoundTag;
class DataItem;
class Vec3;
class Vec2;
class SerializedAbilitiesData;
class NetworkConnection;
class SerializedSkin;
class NetworkPeer;
class NetworkItemStackDescriptor;
struct NetworkIdentifierWithSubId;
class EntityContext;
class Packet;
class Player;
struct ActorLink;
namespace mce {
class UUID;
}

namespace gmlib {

class GMPlayer;
class GMCompoundTag;

class GMBinaryStream : public BinaryStream {
public:
    using BinaryStream::BinaryStream;
    GMBinaryStream(GMBinaryStream const&);
    explicit GMBinaryStream(Packet const& packet);
    // When allowModify is false, it will copy itself and then execute toPacket
    std::shared_ptr<Packet> toPacket(bool allowModify = true);
    std::shared_ptr<Packet> toPacket() const;
    template <std::derived_from<Packet> T>
    [[nodiscard]] constexpr inline std::shared_ptr<T> toPacket(bool allowModify = true) {
        return std::static_pointer_cast<T>(toPacket(allowModify));
    }
    template <std::derived_from<Packet> T>
    [[nodiscard]] constexpr inline std::shared_ptr<T> toPacket() const {
        return std::static_pointer_cast<T>(toPacket());
    }

public:
    void writePacketHeader(MinecraftPacketIds packetId, SubClientId subId = SubClientId::PrimaryClient);
    void sendTo(
        ::Player&                player,
        NetworkPeer::Reliability reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility          compressible = Compressibility::Compressible
    );
    void sendTo(
        ::NetworkIdentifier const& netId,
        NetworkPeer::Reliability   reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility            compressible = Compressibility::Compressible
    );
    void sendTo(
        ::NetworkIdentifierWithSubId const& identifierWithSubId,
        NetworkPeer::Reliability            reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility                     compressible = Compressibility::Compressible
    );
    void sendTo(
        ::NetworkConnection&     connection,
        NetworkPeer::Reliability reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility          compressible = Compressibility::Compressible
    );
    void sendTo(
        ::NetworkPeer&           peer,
        NetworkPeer::Reliability reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility          compressible = Compressibility::Compressible
    );
    void sendToClients(
        NetworkPeer::Reliability reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility          compressible = Compressibility::Compressible
    );
    void sendToClients(
        std::function<bool(GMPlayer&)> filter,
        NetworkPeer::Reliability       reliability  = NetworkPeer::Reliability::ReliableOrdered,
        Compressibility                compressible = Compressibility::Compressible
    );
    void sendToDimension(
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
    bool        getBool();
    uchar       getByte();
    double      getDouble();
    float       getFloat();
    int         getSignedBigEndianInt();
    int         getSignedInt();
    int64       getSignedInt64();
    short       getSignedShort();
    std::string getString();
    void        getString(std::string& outStringStream);
    uchar       getUnsignedChar();
    uint        getUnsignedInt();
    uint64      getUnsignedInt64();
    ushort      getUnsignedShort();
    uint        getUnsignedVarInt();
    uint64      getUnsignedVarInt64();
    int         getVarInt();
    int64       getVarInt64();

    template <typename T>
    inline void writeType(T const& x) {
        serialize<T>::write(x, *this);
    }
    void writeCompoundTag(GMCompoundTag const& data);
    void writeDataItem(std::vector<std::unique_ptr<::DataItem>> const& data);
    void writeVec3(::Vec3 const& data);
    void writeVec2(::Vec2 const& data);
    void writeBlockPos(::BlockPos const& data);
    void writeAbilitiesData(::SerializedAbilitiesData const& data);
    void writeSkin(::SerializedSkin const& data);
    void writeActorLink(::ActorLink const& data);
    void writeUuid(::mce::UUID const& data);
    void writeNetworkItemStackDescriptor(::NetworkItemStackDescriptor const& data);
    void writeMoveActorAbsoluteData(::MoveActorAbsoluteData const& data);

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
