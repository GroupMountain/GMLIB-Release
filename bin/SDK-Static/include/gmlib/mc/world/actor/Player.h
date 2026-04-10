#pragma once
#include "gmlib/gm/enum/WeatherType.h"
#include "ll/api/data/Version.h"
#include "mc/network/packet/SetTitlePacket.h"
#include "mc/server/ServerPlayer.h"
#include "mc/world/actor/ai/util/BossBarColor.h"
#include "mc/world/actor/ai/util/BossBarOverlay.h"
#include "mc/world/level/chunk/SubChunk.h"
#include "mc/world/scores/ObjectiveSortOrder.h"

struct MCRESULT;
class FullPlayerInventoryWrapper;

namespace gmlib {
class GMPlayer : public ServerPlayer {
public:
    std::unique_ptr<CompoundTag> getNbt() const;

    std::string getIP() const;

    ushort getPort() const;

    int getAvgPing() const;

    int getLastPing() const;

    std::string getLanguageCode() const;

public:
    bool setNbt(CompoundTag& nbt);

    void setClientSidebar(
        std::string const&                              title,
        std::vector<std::pair<std::string, int>> const& data,
        ObjectiveSortOrder                              sortOrder = ObjectiveSortOrder::Ascending
    );
    void removeClientSidebar();

    void setAttributeMax(Attribute, float value);
    void setAttributeMin(Attribute, float value);
    void setAttributeCurrent(Attribute, float value);

    void setAttributeMax(std::string_view name, float value);
    void setAttributeMin(std::string_view name, float value);
    void setAttributeCurrent(std::string_view name, float value);

    // set the gamemode of the client
    // It won't affect the server-side gamemode
    void setClientGamemode(GameType gamemode);

    // Create a bossbar even if there is not a boss
    // return the bossbar id (fake actor auid)
    // this bossbarId is unique for each client
    int64_t createClientBossbar(
        std::string const& name,
        float              percentage = 1.00f,
        ::BossBarColor     color      = BossBarColor::Purple,
        ::BossBarOverlay   overlay    = BossBarOverlay::Progress
    );

    // can set a exist boss's bossbar with setting the bossbarId to the boss's auid
    void setClientBossbar(
        int64_t            bossbarId,
        std::string const& name,
        float              percentage = 1.00f,
        ::BossBarColor     color      = BossBarColor::Purple,
        ::BossBarOverlay   overlay    = BossBarOverlay::Progress
    );

    void removeClientBossbar(int64_t bossbarId);

    void updateClientBossbarPercentage(int64_t bossbarId, float percentage);

    void updateClientBossbarName(int64_t bossbarId, std::string const& name);

    void updateClientBossbarColor(int64_t bossbarId, ::BossBarColor color);

    void sendToast(std::string_view title, std::string_view message);

    void sendTitle(
        std::string_view          title,
        SetTitlePacket::TitleType type            = SetTitlePacket::TitleType::Title,
        int                       fadeInDuration  = 10,
        int                       remainDuration  = 70,
        int                       fadeOutDuration = 20
    );


    void setClientWeather(WeatherType weather);

    // Set the player's Freezing state (In powder_snow's state)
    // The percentage affect the player's client HUD
    void setFreezing(float percentage = 1.0f);

    void updateClientBlock(
        BlockPos const&      pos,
        Block const&         block,
        SubChunk::BlockLayer layer = SubChunk::BlockLayer::Standard
    );

    void updateClientBlockActor(BlockPos const& pos, CompoundTag const& nbt);


    MCRESULT executeCommand(std::string_view command);

    /*
        Notice:
        These functions about player's inventory will refresh player's inventory automatically
        So you don't need to call refreshInventory() after you call these functions
    */

    FullPlayerInventoryWrapper getFullPlayerInventoryWrapper();

    // If the item's stack size is larger than the max stack size, will split the item stack
    // return the number of items that have been given by groups of max stack size
    // (items.size() + the number of items that have been split)
    int giveItems(std::vector<ItemStack>& items, bool shouldAddWhenFull = true);

    // Return the refs of the items in player's inventory
    // Contains the inventory, armor, offhand

    /*
        @param comparator: a comparator that return true if the item is the same as the item in the inventory (can be
       nullptr. If so, requireExtraData should be false too)
        @param requireExtraData: If comparator exist, requireExtraData should be true. If requireExtraData is false, the
       comparator will be ignored
    */
    std::vector<optional_ref<ItemStack>> getItems(
        std::string_view                            name,
        brstd::function_ref<bool(const ItemStack&)> comparator,
        bool                                        requireExtraData = false
    );

    std::vector<optional_ref<ItemStack>> getItems(std::string_view name, int data);

    // Return the count of the items that have been cleared
    int clearItem(
        std::string_view                      name,
        std::function<bool(const ItemStack&)> comparator       = nullptr,
        bool                                  requireExtraData = false,
        int                                   clearCount       = INT_MAX
    );

    int clearItem(std::string_view name, int data, int clearCount = INT_MAX);

    void clearAllItems();

    bool isInStructureFeature(::HashedString& structure) const;

    ::HashedString getStructureFeature() const;

    std::string getStructureFeatureName() const;

    std::optional<BlockPos> locateNearestStructureFeature(::HashedString& structure, bool useNewChunksOnly = false);

    std::optional<BlockPos> locateNearestStructureFeature(std::string const& structure, bool useNewChunksOnly = false);

    void sendPacket(Packet& packet);

    void sendText(std::string_view message);

    void sendText(std::string const& message, std::vector<std::string> const& params);

    void talkAs(std::string_view message);

    int getNetworkProtocolVersion();

    ll::data::Version getClientVersion();

    bool isPreviewClient();

public:
    static optional_ref<GMPlayer> getServerPlayer(NetworkIdentifier const& source, ::SubClientId subId);
};
} // namespace gmlib