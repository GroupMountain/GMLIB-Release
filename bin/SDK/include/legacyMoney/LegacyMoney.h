#include "gmlib/Macros.h"
#include <ll/api/Expected.h>
#include <ll/api/base/StdInt.h>
#include <string>
#include <vector>


namespace LegacyMoney {

enum class LLMoneyEvent {
    Set    = 0x0,
    Add    = 0x1,
    Reduce = 0x2,
    Trans  = 0x3,
};

typedef bool (*LLMoneyCallback)(LLMoneyEvent type, std::string from, std::string to, llong value);

GMLIB_API ll::Expected<llong> LLMoney_Get(std::string xuid);
GMLIB_API ll::Expected<bool> LLMoney_Set(std::string xuid, llong money);
GMLIB_API ll::Expected<bool> LLMoney_Trans(std::string from, std::string to, llong val, std::string const& note = "");
GMLIB_API ll::Expected<bool> LLMoney_Add(std::string xuid, llong money);
GMLIB_API ll::Expected<bool> LLMoney_Reduce(std::string xuid, llong money);

GMLIB_API ll::Expected<std::string> LLMoney_GetHist(std::string xuid, int timediff = 24 * 60 * 60);
GMLIB_API ll::Expected<void> LLMoney_ClearHist(int difftime = 0);

GMLIB_API ll::Expected<void> LLMoney_ListenBeforeEvent(LLMoneyCallback callback);
GMLIB_API ll::Expected<void> LLMoney_ListenAfterEvent(LLMoneyCallback callback);

GMLIB_API ll::Expected<std::vector<std::pair<std::string, llong>>> LLMoney_Ranking(ushort num = 5);
} // namespace LegacyMoney