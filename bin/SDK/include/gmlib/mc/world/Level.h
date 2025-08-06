#pragma once
#include "gmlib/Macros.h"
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
    GMLIB_NDAPI static optional_ref<GMLevel> getInstance();

public:
    // Level Config API Begin

    /*
        These API are Level Config API
        They must be called in plugin::load()
        Don't call them in plugin::enable() and other places
    */

    GMLIB_API static void addExperimentsRequire(::AllExperiments experiment);

    // Level Config API End

public:
    GMLIB_NDAPI static ll::Expected<CompoundTag> readLevelDat();

    GMLIB_API static bool saveLevelDat(GMCompoundTag const& data);

public:
    GMLIB_NDAPI ::BlockSource& getBlockSource(DimensionType dimid);

    GMLIB_API ::MCRESULT executeCommand(
        std::string_view const& command,
        DimensionType           dimId     = 0,
        CommandPermissionLevel  permLevel = CommandPermissionLevel::Internal
    );

    GMLIB_API std::pair<bool, std::string> executeCommandEx(
        std::string_view const& command,
        DimensionType           dimId     = 0,
        CommandPermissionLevel  permLevel = CommandPermissionLevel::Internal
    );

    GMLIB_API std::string getLevelName();

    GMLIB_API void setLevelName(std::string const& newName);
    
    GMLIB_API bool getExperimentEnabled(AllExperiments experiment) const;

    GMLIB_API void setExperimentEnabled(AllExperiments experiment, bool enabled = true);

    GMLIB_API void setAndUpdateTime(int time);

    GMLIB_NDAPI WeatherType getWeather() const;

    // If use the first one , the lastTick will be random
    GMLIB_API void setWeather(WeatherType weather);
    GMLIB_API void setWeather(WeatherType weather, int lastTick);

    GMLIB_NDAPI std::optional<bool> getGameruleBool(std::string_view const& name) const;
    GMLIB_NDAPI std::optional<float> getGameruleFloat(std::string_view const& name) const;
    GMLIB_NDAPI std::optional<int> getGameruleInt(std::string_view const& name) const;

    GMLIB_NDAPI std::optional<bool> getGameruleBool(::GameRuleId id) const;
    GMLIB_NDAPI std::optional<float> getGameruleFloat(::GameRuleId id) const;
    GMLIB_NDAPI std::optional<int> getGameruleInt(::GameRuleId id) const;


    GMLIB_API bool setGamerule(std::string_view const& name, bool value);
    GMLIB_API bool setGamerule(std::string_view const& name, float value);
    GMLIB_API bool setGamerule(std::string_view const& name, int value);

    GMLIB_API bool setGamerule(::GameRuleId id, bool value);
    GMLIB_API bool setGamerule(::GameRuleId id, float value);
    GMLIB_API bool setGamerule(::GameRuleId id, int value);

    GMLIB_API void createExplosion(
        ::Vec3 const&         pos,
        DimensionType         dimensionId,
        float                 power,
        optional_ref<GMActor> source          = std::nullopt,
        bool                  breakBlocks     = true,
        bool                  causeFire       = false,
        bool                  allowUnderwater = false,
        float                 maxResistance   = 3.40282347e+38
    );

    GMLIB_NDAPI std::shared_ptr<LevelChunk> getOrLoadChunk(
        ::BlockPos const& blockPos,
        DimensionType     dimId,
        bool              readOnly                          = true,
        bool              forceImmediateReplacementDataLoad = false
    );

    GMLIB_NDAPI std::shared_ptr<LevelChunk> getOrLoadChunk(
        ::ChunkPos const& chunkPos,
        DimensionType     dimId,
        bool              readOnly                          = true,
        bool              forceImmediateReplacementDataLoad = false
    );

    GMLIB_NDAPI ::Block const& loadAndGetBlock(::BlockPos const& pos, DimensionType dimId);

    GMLIB_NDAPI ::Block const& getBlock(::BlockPos const& pos, DimensionType dimId);

    GMLIB_API bool setBlock(::BlockPos const& pos, DimensionType dimId, ::Block const& block);
    GMLIB_API bool setBlock(::BlockPos const& pos, DimensionType dimId, std::string_view const& name, short aux = 0);

    // return the number of blocks changed
    // If startpos and endpos
    GMLIB_API int fillBlocks(
        ::BlockPos const&     startpos,
        ::BlockPos const&     endpos,
        DimensionType         dimId,
        ::Block const&        block,
        FillMode              mode              = FillMode::Replace,
        optional_ref<GMActor> blockChangeSource = std::nullopt
    );

    GMLIB_API int fillBlocks(
        ::BlockPos const&       startpos,
        ::BlockPos const&       endpos,
        DimensionType           dimId,
        std::string_view const& name,
        ushort                  tileData          = 0,
        FillMode                mode              = FillMode::Replace,
        optional_ref<GMActor>   blockChangeSource = std::nullopt
    );

    GMLIB_API int fillBlocks(
        ::BlockPos const&     startpos,
        ::BlockPos const&     endpos,
        DimensionType         dimId,
        ::Block const&        oldBlock,
        ::Block const&        newBlock,
        optional_ref<GMActor> blockChangeSource = std::nullopt
    );

    GMLIB_API int fillBlocks(
        ::BlockPos const&       startpos,
        ::BlockPos const&       endpos,
        DimensionType           dimId,
        std::string_view const& oldName,
        ushort                  oldTileData,
        std::string_view const& newName,
        ushort                  newTileData,
        optional_ref<GMActor>   blockChangeSource = std::nullopt
    );

    GMLIB_NDAPI std::chrono::nanoseconds getServerTickTime();

    GMLIB_NDAPI float getServerMspt();

    GMLIB_NDAPI float getServerAverageTps();

    GMLIB_NDAPI float getServerCurrentTps();

    GMLIB_API void setFreezeTick(bool freeze = true);

    GMLIB_API bool isTickFreezed();

    GMLIB_API void setTickScale(float scale = 1.0f);

    GMLIB_API bool isInStructureFeature(::HashedString const& structure, ::BlockPos const& pos, DimensionType dimId);

    GMLIB_NDAPI ::HashedString getStructureFeature(::BlockPos const& pos, DimensionType dimId);

    GMLIB_NDAPI std::optional<::BlockPos> locateNearestStructureFeature(
        ::HashedString const& structure,
        ::BlockPos const&     pos,
        DimensionType         dimId,
        bool                  useNewChunksOnly = false
    );

    GMLIB_NDAPI ::DBStorage& getDBStorage();

    GMLIB_API void sendPacketRawToClients(::Packet const& packet);

    GMLIB_API void sendPacketRawToDimension(::Packet const& packet, DimensionType dimId);

    GMLIB_API void sendPacketRawTo(::Packet const& packet, GMPlayer& player);

    GMLIB_API void sendPacketRawTo(::Packet const& packet, ::NetworkIdentifier const& netId);

    GMLIB_API void broadcast(std::string_view const& message);

    GMLIB_API void broadcast(std::string_view const& message, std::vector<std::string> const& params);

    GMLIB_API void broadcastToast(std::string_view const& title, std::string_view const& message);

    GMLIB_API void
    broadcastTitle(std::string_view const& title, SetTitlePacket::TitleType type = SetTitlePacket::TitleType::Title);

    GMLIB_API void broadcastTitle(
        std::string_view          title,
        SetTitlePacket::TitleType type,
        int                       fadeInDuration,
        int                       remainDuration,
        int                       fadeOutDuration
    );

    GMLIB_NDAPI int getMaxPlayerCount() const;

    GMLIB_API int setMaxPlayerCount(int count, bool ignoreVanillaLimit = false);

    GMLIB_API void setServerMotd(std::string_view const& motd);

    GMLIB_API void deleteLevelChunk(::ChunkPos const& cp, DimensionType dimId, bool refresh = true);
};
} // namespace gmlib