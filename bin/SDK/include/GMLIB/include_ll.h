#pragma once

#include "ll/api/base/Alias.h"
#include "ll/api/base/CompilerPredefine.h"
#include "ll/api/base/Concepts.h"
#include "ll/api/base/Containers.h"
#include "ll/api/base/FixedString.h"
#include "ll/api/base/Macro.h"
#include "ll/api/base/Meta.h"
#include "ll/api/base/SourceLocation.h"
#include "ll/api/base/StdInt.h"
#include "ll/api/base/ToString.h"
#include "ll/api/base/TypeTraits.h"
#include "ll/api/chrono/GameChrono.h"
#include "ll/api/command/Command.h"
#include "ll/api/command/CommandHandle.h"
#include "ll/api/command/CommandRegistrar.h"
#include "ll/api/command/EnumName.h"
#include "ll/api/command/Optional.h"
#include "ll/api/command/Overload.h"
#include "ll/api/command/OverloadData.h"
#include "ll/api/command/ParamTraits.h"
#include "ll/api/command/runtime/ParamKind.h"
#include "ll/api/command/runtime/RuntimeCommand.h"
#include "ll/api/command/runtime/RuntimeEnum.h"
#include "ll/api/command/runtime/RuntimeOverload.h"
#include "ll/api/command/SoftEnum.h"
#include "ll/api/Config.h"
#include "ll/api/coro/Collect.h"
#include "ll/api/coro/CoroPromise.h"
#include "ll/api/coro/CoroTask.h"
#include "ll/api/coro/CoroTaskWaiter.h"
#include "ll/api/coro/Executor.h"
#include "ll/api/coro/ForwardAwaiter.h"
#include "ll/api/coro/Generator.h"
#include "ll/api/coro/SleepWaiter.h"
#include "ll/api/coro/YieldAwaiter.h"
#include "ll/api/data/AnyFunction.h"
#include "ll/api/data/AnyObjBase.h"
#include "ll/api/data/CancellableCallback.h"
#include "ll/api/data/ConcurrentPriorityQueue.h"
#include "ll/api/data/DependencyGraph.h"
#include "ll/api/data/IndirectValue.h"
#include "ll/api/data/KeyValueDB.h"
#include "ll/api/data/TightPair.h"
#include "ll/api/data/TmWithMs.h"
#include "ll/api/data/Version.h"
#include "ll/api/event/Cancellable.h"
#include "ll/api/event/command/ExecuteCommandEvent.h"
#include "ll/api/event/DynamicListener.h"
#include "ll/api/event/Emitter.h"
#include "ll/api/event/EmitterBase.h"
#include "ll/api/event/entity/ActorEvent.h"
#include "ll/api/event/entity/ActorHurtEvent.h"
#include "ll/api/event/entity/MobDieEvent.h"
#include "ll/api/event/entity/MobEvent.h"
#include "ll/api/event/Event.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/event/EventId.h"
#include "ll/api/event/EventRefObjSerializer.h"
#include "ll/api/event/Listener.h"
#include "ll/api/event/ListenerBase.h"
#include "ll/api/event/MultiListener.h"
#include "ll/api/event/player/PlayerAddExperienceEvent.h"
#include "ll/api/event/player/PlayerAttackEvent.h"
#include "ll/api/event/player/PlayerClickEvent.h"
#include "ll/api/event/player/PlayerDieEvent.h"
#include "ll/api/event/player/PlayerEvent.h"
#include "ll/api/event/player/PlayerInteractBlockEvent.h"
#include "ll/api/event/player/PlayerJumpEvent.h"
#include "ll/api/event/player/PlayerPickUpItemEvent.h"
#include "ll/api/event/player/PlayerPlaceBlockEvent.h"
#include "ll/api/event/player/PlayerRespawnEvent.h"
#include "ll/api/event/player/PlayerUseItemEvent.h"
#include "ll/api/event/service/ServiceEvents.h"
#include "ll/api/event/world/BlockChangedEvent.h"
#include "ll/api/event/world/FireSpreadEvent.h"
#include "ll/api/event/world/LevelEvent.h"
#include "ll/api/event/world/LevelTickEvent.h"
#include "ll/api/event/world/SpawnMobEvent.h"
#include "ll/api/event/world/WorldEvent.h"
#include "ll/api/Expected.h"
#include "ll/api/Global.h"
#include "ll/api/i18n/I18n.h"
#include "ll/api/io/DefaultSink.h"
#include "ll/api/io/FileSink.h"
#include "ll/api/io/FileUtils.h"
#include "ll/api/io/Formatter.h"
#include "ll/api/io/FunctionStream.h"
#include "ll/api/io/Logger.h"
#include "ll/api/io/LoggerRegistry.h"
#include "ll/api/io/LogLevel.h"
#include "ll/api/io/LogMessage.h"
#include "ll/api/io/PatternFormatter.h"
#include "ll/api/io/Pipe.h"
#include "ll/api/io/Sink.h"
#include "ll/api/io/StdoutRedirector.h"
#include "ll/api/io/StreamRedirector.h"
#include "ll/api/memory/Closure.h"
#include "ll/api/memory/Hook.h"
#include "ll/api/memory/Memory.h"
#include "ll/api/memory/MemoryOperators.h"
#include "ll/api/memory/Signature.h"
#include "ll/api/memory/Symbol.h"
#include "ll/api/mod/Manifest.h"
#include "ll/api/mod/Mod.h"
#include "ll/api/mod/ModManager.h"
#include "ll/api/mod/ModManagerRegistry.h"
#include "ll/api/mod/NativeMod.h"
#include "ll/api/mod/RegisterHelper.h"
#include "ll/api/reflection/Deserialization.h"
#include "ll/api/reflection/Dispatcher.h"
#include "ll/api/reflection/Reflection.h"
#include "ll/api/reflection/Serialization.h"
#include "ll/api/reflection/SerializationError.h"
#include "ll/api/reflection/TypeName.h"
#include "ll/api/service/Bedrock.h"
#include "ll/api/service/GamingStatus.h"
#include "ll/api/service/Service.h"
#include "ll/api/service/ServiceId.h"
#include "ll/api/service/ServiceManager.h"
#include "ll/api/thread/GlobalThreadPauser.h"
#include "ll/api/thread/InplaceExecutor.h"
#include "ll/api/thread/InterruptableSleep.h"
#include "ll/api/thread/ServerThreadExecutor.h"
#include "ll/api/thread/ThreadName.h"
#include "ll/api/thread/ThreadPoolExecutor.h"
#include "ll/api/thread/TickSyncSleep.h"
#include "ll/api/utils/Base64Utils.h"
#include "ll/api/utils/ErrorUtils.h"
#include "ll/api/utils/FontUtils.h"
#include "ll/api/utils/HashUtils.h"
#include "ll/api/utils/RandomUtils.h"
#include "ll/api/utils/StacktraceUtils.h"
#include "ll/api/utils/StringUtils.h"
#include "ll/api/utils/SystemUtils.h"
#include "ll/api/Versions.h"
#include "ll/api/event/player/PlayerChangePermEvent.h"
#include "ll/api/event/player/PlayerChatEvent.h"
#include "ll/api/event/player/PlayerConnectEvent.h"
#include "ll/api/event/player/PlayerDestroyBlockEvent.h"
#include "ll/api/event/player/PlayerDisconnectEvent.h"
#include "ll/api/event/player/PlayerJoinEvent.h"
#include "ll/api/event/player/PlayerSneakEvent.h"
#include "ll/api/event/player/PlayerSprintEvent.h"
#include "ll/api/event/player/PlayerSwingEvent.h"
#include "ll/api/event/player/ServerPlayerEvent.h"
#include "ll/api/event/server/ServerStartedEvent.h"
#include "ll/api/event/server/ServerStoppingEvent.h"
#include "ll/api/form/CustomForm.h"
#include "ll/api/form/FormBase.h"
#include "ll/api/form/FormIdManager.h"
#include "ll/api/form/ModalForm.h"
#include "ll/api/form/SimpleForm.h"
#include "ll/api/service/PlayerInfo.h"
#include "ll/api/service/ServerInfo.h"
#include "ll/api/service/TargetedBedrock.h"