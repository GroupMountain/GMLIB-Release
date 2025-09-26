#pragma once
#include "gmlib/gm/enum/FillMode.h"
#include "gmlib/gm/enum/WeatherType.h"
#include <ll/api/Expected.h>
#include <mc/network/packet/SetTitlePacket.h>
#include <mc/server/commands/CommandPermissionLevel.h>
#include <mc/world/level/Level.h>
#include <mc/world/level/storage/AllExperiments.h>

struct MCRESULT;
struct GameRuleId;
class DBStorage;
class Packet;

namespace gmlib {

class GMCompoundTag;
class GMActor;
class GMPlayer;
class GMBinaryStream;
class I18nAPI;

class GMLevel : public Level {
public:
    static optional_ref<GMLevel> getInstance();

public:
    static ll::Expected<CompoundTag> readLevelDat();

    static bool saveLevelDat(GMCompoundTag const& data);

public:
    ::BlockSource& getBlockSource(DimensionType dimid);

    ::MCRESULT executeCommand(
        std::string_view const& command,
        DimensionType           dimId     = 0,
        CommandPermissionLevel  permLevel = CommandPermissionLevel::Internal
    );

    std::pair<bool, std::string> executeCommandEx(
        std::string_view const& command,
        DimensionType           dimId     = 0,
        CommandPermissionLevel  permLevel = CommandPermissionLevel::Internal
    );

    std::string getLevelName();

    void setLevelName(std::string const& newName);

    bool getExperimentEnabled(AllExperiments experiment) const;

    void setExperimentEnabled(AllExperiments experiment, bool enabled = true);

    void setAndUpdateTime(int time);

    WeatherType getWeather() const;

    // If use the first one , the lastTick will be random
    void setWeather(WeatherType weather);
    void setWeather(WeatherType weather, int lastTick);

    std::optional<bool>  getGameruleBool(std::string_view const& name) const;
    std::optional<float> getGameruleFloat(std::string_view const& name) const;
    std::optional<int>   getGameruleInt(std::string_view const& name) const;

    std::optional<bool>  getGameruleBool(::GameRuleId id) const;
    std::optional<float> getGameruleFloat(::GameRuleId id) const;
    std::optional<int>   getGameruleInt(::GameRuleId id) const;


    bool setGamerule(std::string_view const& name, bool value);
    bool setGamerule(std::string_view const& name, float value);
    bool setGamerule(std::string_view const& name, int value);

    bool setGamerule(::GameRuleId id, bool value);
    bool setGamerule(::GameRuleId id, float value);
    bool setGamerule(::GameRuleId id, int value);

    void createExplosion(
        ::Vec3 const&         pos,
        DimensionType         dimensionId,
        float                 power,
        optional_ref<GMActor> source          = std::nullopt,
        bool                  breakBlocks     = true,
        bool                  causeFire       = false,
        bool                  allowUnderwater = false,
        float                 maxResistance   = 3.40282347e+38
    );

    std::shared_ptr<LevelChunk> getOrLoadChunk(
        ::BlockPos const& blockPos,
        DimensionType     dimId,
        bool              readOnly                          = true,
        bool              forceImmediateReplacementDataLoad = false
    );

    std::shared_ptr<LevelChunk> getOrLoadChunk(
        ::ChunkPos const& chunkPos,
        DimensionType     dimId,
        bool              readOnly                          = true,
        bool              forceImmediateReplacementDataLoad = false
    );

    ::Block const& loadAndGetBlock(::BlockPos const& pos, DimensionType dimId);

    ::Block const& getBlock(::BlockPos const& pos, DimensionType dimId);

    bool setBlock(::BlockPos const& pos, DimensionType dimId, ::Block const& block);
    bool setBlock(::BlockPos const& pos, DimensionType dimId, std::string_view const& name, short aux = 0);

    // return the number of blocks changed
    // If startpos and endpos
    int fillBlocks(
        ::BlockPos const&     startpos,
        ::BlockPos const&     endpos,
        DimensionType         dimId,
        ::Block const&        block,
        FillMode              mode              = FillMode::Replace,
        optional_ref<GMActor> blockChangeSource = std::nullopt
    );

    int fillBlocks(
        ::BlockPos const&       startpos,
        ::BlockPos const&       endpos,
        DimensionType           dimId,
        std::string_view const& name,
        ushort                  tileData          = 0,
        FillMode                mode              = FillMode::Replace,
        optional_ref<GMActor>   blockChangeSource = std::nullopt
    );

    int fillBlocks(
        ::BlockPos const&     startpos,
        ::BlockPos const&     endpos,
        DimensionType         dimId,
        ::Block const&        oldBlock,
        ::Block const&        newBlock,
        optional_ref<GMActor> blockChangeSource = std::nullopt
    );

    int fillBlocks(
        ::BlockPos const&       startpos,
        ::BlockPos const&       endpos,
        DimensionType           dimId,
        std::string_view const& oldName,
        ushort                  oldTileData,
        std::string_view const& newName,
        ushort                  newTileData,
        optional_ref<GMActor>   blockChangeSource = std::nullopt
    );

    std::chrono::nanoseconds getServerTickTime();

    float getServerMspt();

    float getServerCurrentTps();

    void setFreezeTick(bool freeze = true);

    bool isTickFreezed();

    void setTickScale(float scale = 1.0f);

    bool isInStructureFeature(::HashedString const& structure, ::BlockPos const& pos, DimensionType dimId);

    ::HashedString getStructureFeature(::BlockPos const& pos, DimensionType dimId);

    std::optional<::BlockPos> locateNearestStructureFeature(
        ::HashedString const& structure,
        ::BlockPos const&     pos,
        DimensionType         dimId,
        bool                  useNewChunksOnly = false
    );

    ::DBStorage& getDBStorage();

    void sendPacketRawToClients(::Packet const& packet);

    void sendPacketRawToDimension(::Packet const& packet, DimensionType dimId);

    void sendPacketRawTo(::Packet const& packet, GMPlayer& player);

    void sendPacketRawTo(::Packet const& packet, ::NetworkIdentifier const& netId);

    void broadcast(std::string_view const& message);

    void broadcast(std::string_view const& message, std::vector<std::string> const& params);

    void broadcastToast(std::string_view const& title, std::string_view const& message);

    void
    broadcastTitle(std::string_view const& title, SetTitlePacket::TitleType type = SetTitlePacket::TitleType::Title);

    void broadcastTitle(
        std::string_view          title,
        SetTitlePacket::TitleType type,
        int                       fadeInDuration,
        int                       remainDuration,
        int                       fadeOutDuration
    );

    int getMaxPlayerCount() const;

    int setMaxPlayerCount(int count, bool ignoreVanillaLimit = false);

    void setServerMotd(std::string_view const& motd);

    void deleteLevelChunk(::ChunkPos const& cp, DimensionType dimId, bool refresh = true);
};
} // namespace gmlib