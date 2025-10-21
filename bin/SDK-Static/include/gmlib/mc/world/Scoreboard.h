#pragma once
#include <mc/world/scores/IdentityDefinition.h>
#include <mc/world/scores/Scoreboard.h>
#include <mc/world/scores/ScoreboardId.h>

class ServerScoreboard;
struct ActorUniqueID;

namespace mce {
class UUID;
}

namespace gmlib {

class OfflinePlayer;
class GMActor;
class GMPlayer;

class GMScoreboard : public Scoreboard {
public:
    using Scoreboard::addObjective;
    using Scoreboard::removeObjective;
    using Scoreboard::resetPlayerScore;

public:
    static optional_ref<GMScoreboard> getInstance();

public:
    optional_ref<ServerScoreboard> getServerScoreboard();

    optional_ref<::Objective> addObjective(std::string const& name);

    optional_ref<::Objective> addObjective(std::string const& name, std::string const& displayName);

    bool removeObjective(std::string const& objective);

    ::ScoreboardId getPlayerScoreboardId(std::string const& serverId);

    ::ScoreboardId getPlayerScoreboardId(::mce::UUID const& uuid);

    std::optional<int> getScore(::Objective& objective, ::ScoreboardId const& scoreboardId);

    std::optional<int> getScore(std::string const& objective, std::string const& name);

    std::optional<int> getScore(std::string const& objective, GMPlayer& player);

    std::optional<int> getScore(std::string const& objective, GMActor& actor);

    std::optional<int> getScore(std::string const& objective, ::ActorUniqueID const& uniqueId, bool isPlayer = false);

    std::optional<int> getPlayerScore(std::string const& objective, std::string const& serverId);

    std::optional<int> getPlayerScore(std::string const& objective, ::mce::UUID const& uuid);

    std::optional<int> getPlayerScore(std::string const& objective, ::ActorUniqueID const& uniqueId);

    std::optional<int> getPlayerScore(std::string const& objective, GMPlayer& player);

    std::optional<int> setScore(
        ::Objective&           objective,
        ::ScoreboardId const&  scoreboardId,
        int                    value,
        PlayerScoreSetFunction action = PlayerScoreSetFunction::Set
    );

    std::optional<int> setScore(
        std::string const&     objective,
        std::string const&     name,
        int                    value,
        PlayerScoreSetFunction action = PlayerScoreSetFunction::Set
    );

    std::optional<int> setScore(
        std::string const&     objective,
        GMPlayer&              player,
        int                    value,
        PlayerScoreSetFunction action = PlayerScoreSetFunction::Set
    );

    std::optional<int> setScore(
        std::string const&     objective,
        GMActor&               acotr,
        int                    value,
        PlayerScoreSetFunction action = PlayerScoreSetFunction::Set
    );

    std::optional<int> setScore(
        std::string const&     objective,
        ::ActorUniqueID const& uniqueId,
        int                    value,
        PlayerScoreSetFunction action   = PlayerScoreSetFunction::Set,
        bool                   isPlayer = false
    );

    std::optional<int> setPlayerScore(
        std::string const&     objective,
        std::string const&     serverId,
        int                    value,
        PlayerScoreSetFunction action = PlayerScoreSetFunction::Set
    );

    std::optional<int> setPlayerScore(
        std::string const&     objective,
        ::mce::UUID const&     uuid,
        int                    value,
        PlayerScoreSetFunction action = PlayerScoreSetFunction::Set
    );

    std::optional<int> setPlayerScore(
        std::string const&     objective,
        ::ActorUniqueID const& uniqueId,
        int                    value,
        PlayerScoreSetFunction action = PlayerScoreSetFunction::Set
    );

    std::optional<int> setPlayerScore(
        std::string const&     objective,
        GMPlayer&              player,
        int                    value,
        PlayerScoreSetFunction action = PlayerScoreSetFunction::Set
    );

    bool resetScore(::Objective& objective, ::ScoreboardId const& scoreboardId);

    bool resetScore(std::string const& objective, std::string const& name);

    bool resetScore(std::string const& objective, GMPlayer& player);

    bool resetScore(std::string const& objective, GMActor& acotr);

    bool resetScore(std::string const& objective, ::ActorUniqueID const& uniqueId, bool isPlayer = false);

    bool resetPlayerScore(std::string const& objective, std::string const& serverId);

    bool resetPlayerScore(std::string const& objective, ::mce::UUID const& uuid);

    bool resetPlayerScore(std::string const& objective, ::ActorUniqueID const& uniqueId);

    bool resetPlayerScore(std::string const& objective, GMPlayer& player);

    bool resetScore(::ScoreboardId const& scoreboardId);

    bool resetScore(std::string const& name);

    bool resetScore(GMPlayer& player);

    bool resetScore(GMActor& acotr);

    bool resetScore(::ActorUniqueID const& uniqueId, bool isPlayer = false);

    bool resetPlayerScore(std::string const& serverId);

    bool resetPlayerScore(::mce::UUID const& uuid);

    bool resetPlayerScore(GMPlayer& player);

    bool resetPlayerScore(::ActorUniqueID const& uniqueId);

    std::vector<::ScoreboardId> getAllScoreboardIds();

    std::vector<::ScoreboardId> getObjectiveTrackedScoreboardIds(::Objective& objective);

    std::vector<::ScoreboardId> getAllScoreboardIds(IdentityDefinition::Type type);

    std::vector<::ScoreboardId> getObjectiveTrackedScoreboardIds(::Objective& objective, IdentityDefinition::Type type);

    std::vector<::ActorUniqueID> getAllPlayersActorUniqueID();

    std::vector<OfflinePlayer> getAllPlayers();

    std::vector<::ActorUniqueID> getAllEntities();

    std::vector<std::string> getAllFakePlayers();

    void setObjectiveDisplay(
        ::Objective&       objective,
        std::string const& displaySlot = "sidebar",
        ObjectiveSortOrder order       = ObjectiveSortOrder::Ascending
    );

    void setObjectiveDisplay(
        std::string const& objective,
        std::string const& displaySlot = "sidebar",
        ObjectiveSortOrder order       = ObjectiveSortOrder::Ascending
    );

    void clearObjectiveDisplay(std::string const& displaySlot);

    std::optional<std::string> getObjectiveDisplayName(std::string const& objective);

    bool setObjectiveDisplayName(std::string const& objective, std::string const& newName);

    ::ScoreboardId const& getOrCreateScoreboardId(::ActorUniqueID const& uniqueId);
    ::ScoreboardId const& getOrCreateScoreboardId(GMActor const& entity);

    ::ScoreboardId const& getOrCreateScoreboardId(std::string const& name);

    ::ScoreboardId const& getOrCreateScoreboardId(GMPlayer const& player);
    ::ScoreboardId const& getOrCreateScoreboardId(::PlayerScoreboardId const& id);

public:
    // missing func in 1.21.60
    ::ScoreboardId const& getScoreboardId(::ActorUniqueID const& uniqueId) const;
    ::ScoreboardId const& getScoreboardId(GMActor const& entity) const;

    ::ScoreboardId const& getScoreboardId(std::string const& name) const;

    ::ScoreboardId const& getScoreboardId(GMPlayer const& player) const;
    ::ScoreboardId const& getScoreboardId(::PlayerScoreboardId const& id) const;
};
} // namespace gmlib