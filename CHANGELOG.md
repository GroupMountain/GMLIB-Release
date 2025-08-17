# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

### Changed

### Fixed

## [1.4.3] - 2025-08-17

### Fixed

- Fixed https://github.com/GroupMountain/GMLIB-Release/issues/148 @Zhongzi8972
- Fixed https://github.com/GroupMountain/GMLIB-Release/issues/149 @Zhongzi8972
- Fixed Glacie API @KobeBryant114514

## [1.4.2] - 2025-08-06

### Added

- Added hot deletion of deteLevelChunck chunks @zimuya4153
- Added BlockHelper @killcerr
- Added ChestUI::getSlot https://github.com/GroupMountain/GMLIB-Release/issues/142 @Zhongzi8972
- Added support for pregeneration_pass @killcerr

### Changed

- Refactor CustomFeature @killcerr
- Optimized GMBinaryStream @zimuya4153

### Fixed

- Fixed crash when add invalid user cache @killcerr
- Fixed GMPlayer::setNbt didn't refresh player inventory @Zhongzi8972
- Fixed ChestUI::sendTo couldn't open another UI when there is a UI opened @Zhongzi8972
- Fixed https://github.com/GroupMountain/GMLIB-LegacyRemoteCallApi/issues/58 @Zhongzi8972
- Fixed https://github.com/GroupMountain/GMLIB-LegacyRemoteCallApi/issues/56 @Zhongzi8972
- Fixed https://github.com/GroupMountain/GMLIB-Release/issues/141 @Zhongzi8972
- Fixed OfflinePlayer::getAllOfflinePlayers bug in some exceptional case @Zhongzi8972



## [1.4.0] - 2025-07-16

### Changed

- Adapted to LeviLamina 1.4.0 and bds 1.21.93.1 @zimuya4153


## [1.3.1] - 2025-07-16

### Added

- Added get player version api for Player @KobeBryant114514
- Added timezone support and improve server time placeholders @zimuya4153
- Added new placeholders and deprecate player_ping @zimuya4153
- Added player_client_version placeholder @KobeBryant114514
- Added papi to i18n literals @KobeBryant114514
- Added some apis for EconomicsSystem @killcerr

### Changed

- Enhance BinaryStream @zimuya4153

### Fixed

- Fixed UserCache @killcerr
- Fixed refresh in Player::setNBT @Zhongzi8972


### [1.3.0] - 2025-06-14

### Added

- Added some new placeholders @zimuya4153

### Fixed

- Fixed GlacieAPI @KobeBryant114514
- Fixed Form API @zimuya4153

## [1.3.0-rc.1] - 2025-06-12

### Changed

- Adapt to LeviLamina 1.3.0 and bds 1.21.80.03 @zimuya4153

## [1.2.1] - 2025-06-14

### Fixed

- Fixed GlacieAPI @KobeBryant114514

## [1.2.0] - 2025-06-11

### Changed

- Enhanced Placeholder API with Temporary Variable Support @zimuya4153
- Enhance server_time placeholder with timezone support @zimuya4153
- Updated glacie api @KobeBryant114514
- Optimized function cache @KobeBryant114514

### Fixed
- Fixed `setClientSidebar` @n15421
- Fixed the data race of BinaryStream::send @KobeBryant114514

## [1.2.0-rc.1] - 2025-05-31

### Added
- Added CompostChance @KobeBryant114514
- Added ICustomToolItem @KobeBryant114514
- Added some macros for registing ServerSettingForm @KobeBryant114514
- Added static check in build script @killcerr
- Added ServerId and ActorUniqueId to UserCache @killcerr
- Added constructor for UserCache @killcerr

### Changed
- Adapt to 1.21.70 levilamina 1.2.0 @zimuya4153 @KobeBryant114514 @killcerr #n15421
- Renamed some methods in `CustomItemRegistr` @KobeBryant114514
- Refactor UserCache @killcerr
- Use QueryType in user cache @killcerr

### Fixed
- Fixed ABI broken in `CustomItemRegistry` @KobeBryant114514
- Removed useless macros @KobeBryant114514
- Removed GMScoreboard::getAllPlayers() @Zhongzi8972
- Fixed OfflinePlayer::forEachOfflinePlayer() @Zhongzi8972
- Fixed GMLevel::readLevelDat() and GMLevel::saveLevelDat() @zimuya4153

## [1.0.2] - 2025-05-07

### Added
- Added Custom Game Rules @KobeBryant114514
- Added Custom Feature Rules @killcerr
- Added new Glacie API @KobeBryant114514
- Added economy system @zimuya4153
- Added change vanilla items in CustomItemRegistry @KobeBryant114514

### Changed
- Optimized PlaceholderAPI @zimuya4153 @killcerr

### Fixed
- Fixed ServerSettingForm Callback @KobeBryant114514
- Fixed Chest UI bugs @Zhongzi8972
- Fixed include_all @KobeBryant114514
- Fixed OfflinePlayer @Zhongzi8972
- Fixed ModAPI macros @KobeBryant114514
- Fixed custom armor bugs @KobeBryant114514
- Fixed recipe bugs @KobeBryant114514
- Fixed GMPlayer::talkAs @KobeBryant114514
- Fixed I18n literals @KobeBryant114514

## [1.0.1] - 2025-04-18

### Added
- Added CustomItemRegistry @KobeBryant114514
- Added CustomCreativeItemRegistry @KobeBryant114514

### Changed


### Fixed
- Fixed CustomRecipeRegistry @KobeBryant114514

## [1.0.0] - 2025-04-14

### Added

- Added Auto I18n Fix @KobeBryant114514
- Added CompressionFile @KobeBryant114514
- Added function cache @KobeBryant114514
- Added Memory Compression @KobeBryant114514
- Added CustomRecipeRegistry @KobeBryant114514
- Added CustomFeature @killcerr
- Added config file @zimuya4153
- Added slice placeholder @zimuya4153
- Added preRelease and build parameters for placeholder @zimuya4153

### Changed

- Restructure directories @KobeBryant114514
- Optimize optional LegacyRemoteCall and LegacyMoney @KobeBryant114514
- Optimize PlaceholderAPI @zimuya4153
- Optimize ChestUI @Zhongzi8972
- Optimize registerDefaultPlaceholders code @zimuya4153

### Fixed

- Fixed UnloadedActor @KobeBryant114514
- Fixed OfflinePlayer [#128] @KobeBryant114514
- Fixed AddonsLoader @zimuya4153
- Fixed RemoteCallAPI import @KobeBryant114514
- Fixed GMScoreboard @Zhongzi8972
- Fixed compile error in ResouceI18n @Zhongzi8972
- Fixed NpcDialogueForm @KobeBryant114514
- Fixed GMLevel::setMaxPlayerCount method @KobeBryant114514
- Fixed GMPlayer::removeClientSidebar method @EpsilonZunsat

## [1.0.0-rc.3] - 2025-03-22

### Changed

- Added more detailed version information for manifest.json file @zimuya4153

### Added

- Added logo printing when enabling @zimuya4153
- Added gradientText API and gradient output @zimuya4153

### Fixeded

- Fixed ChestUI big chest showing error @Zhongzi8972
- Fixed MCI18n @Zhongzi8972
- Fixed GMCompoundTag::getDataLoadHelper and GMActor::setNbt @Zhongzi8972
- Fixed include_all.h @zimuya4153

## [1.0.0-rc.2] - 2025-03-20

### Changed

- Refactored FloatingText @KobeBryant114514
- Reorganized Actor.h and Player.h @Zhongzi8972
- Reorganized serveral headers @KobeBryant114514

### Added

- Added some language template @Kobebryant114514
- Added RemoteCallAPI and LegacyMoneyAPI @zimuya4153
- Added more separators for Placeholder @zimuya4153
- Added placeholders for player_llmoney and operation @zimuya4153
- Added Resouce Util @KobeBryant114514
- Added GlobalUsing.h @zimuya4153

### Fixeded

- Fixed serveral errors for PAPI @zimuya4153
- Fixed DynamicFloatingText @KobeBryant114514
- Fixed FloatingTextManager template compile error @Zhongzi8972
- Fixed ChestUI @Zhongzi8972
- Fixed Player::talk as method @zimuya4153
- Fixed file typo @zimuya4153

## [1.0.0-rc.1] - 2025-03-16

### Changed

- Completely refactor GMLIB [#122] @Zhongzi8972 @zimuya4153 @EpsilonZunsat @KobeBryant114514 @killcerr @n15421
- Adapt 1.21.60 levilamina 1.1.0 @Zhongzi8972
- Reorganized and rename all the files and namespace @Zhongzi8972
- Changed GMActor::setXXX to Actor::set @Zhongzi8972
- Changed GMCompoundTag::setXXX to CompoundTag::set @Zhongzi8972
- Removed WorldStorageAPI @Zhongzi8972
- Removed mod API @Zhongzi8972
- Removed Vallina Fix @Zhongzi8972
- Removed events @Zhongzi8972
- Removed functions about unloaded actor and player @Zhongzi8972
- Removed GMActor::getNextActorUniqueID @zimuya4153
- Removed GMActor::executeCommand @Zhongzi8972
- Removed GMLevel::getLevel @zimuya4153
- Removed GMLevel::setFakeSeed @Zhongzi8972
- Removed GMLevel::requireServerResourcePackAndAllowClientResourcePack @Zhongzi8972
- Removed GMLevel::trustAllSkins @Zhongzi8972
- Removed GMLevel::tryEnableEducationEdition @Zhongzi8972
- Removed GMLevel::setForceAchievementsEnabled @Zhongzi8972
- Removed GMLevel::tryRegisterAbilityCommand @Zhongzi8972
- Removed GMLevel::setFakeLevelName @Zhongzi8972
- Removed GMLevel::getWorldSpawn @Zhongzi8972
- Removed GMLevel::setWorldSpawn @Zhongzi8972
- Removed GMLIB::Version @Zhongzi8972

### Added

- Added Actor PAPI [#119] @zimuya4153
- Added annotationdocs for headers @Zhongzi8972
- Added UnloadedActor.h @Zhongzi8972
- Added OfflinePlayer.h @Zhongzi8972
- Added SystemUtil.h @zimuya4153
- Added Function.h @KobeBryant114514 @zimuya4153 @killcerr
- Added GlacieAPI.h @KobeBryant114514
- Added entries sort for PlayerListAPI @Zhongzi8972
- Added template for FloatingTextManager @Zhongzi8972
- Added GMLevel::deleteLevelChunk @KobeBryant114514 @Zhongzi8972
- Added GMBinaryStream::writeNetworkItemStackDescriptor @KobeBryant114514

### Fixeded

- Fixed GMLevel::getAverageTps @Zhongzi8972 @zimuya4153
- Fixed GMBinaryStream::writeActorLink @EpsilonZunsat
- Fixed I18n @Zhongzi8972
- Fixed GMLevel::fillBlocks @Zhongzi8972
- Fixed GMLevel::giveItem @Zhongzi8972

[#128]: https://github.com/GroupMountain/GMLIB-Release/issues/128
[#119]: https://github.com/GroupMountain/GMLIB-Release/issues/119
[#122]: https://github.com/GroupMountain/GMLIB-Release/issues/122


[Unreleased]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.3.1...HEAD
[1.3.1]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.3.0...1.3.1
[1.3.0]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.2.1...1.3.0
[1.2.1]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.3.0-rc.1...v1.2.1
[1.3.0-rc.1]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.2.0...v1.3.0-rc.1
[1.2.0]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.2.0-rc.1...v1.2.0
[1.2.0-rc.1]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.0.2...v1.2.0-rc.1
[1.0.2]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.0.1...v1.0.2
[1.0.1]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.0.0...v1.0.1
[1.0.0]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.0.0-rc.3...v1.0.0
[1.0.0-rc.1]: https://github.com/GroupMountain/GMLIB-Release/compare/v0.3.10...v1.0.0-rc.1
[1.0.0-rc.2]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.0.0-rc.1...v1.0.0-rc.2
[1.0.0-rc.3]: https://github.com/GroupMountain/GMLIB-Release/compare/v1.0.0-rc.2...v1.0.0-rc.3