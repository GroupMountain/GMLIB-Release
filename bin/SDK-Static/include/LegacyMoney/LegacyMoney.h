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

ll::Expected<llong> LLMoney_Get(std::string const& xuid);

ll::Expected<bool> LLMoney_Set(std::string const& xuid, llong money);

ll::Expected<bool>
LLMoney_Trans(std::string const& from, std::string const& to, llong val, std::string const& note = "");

ll::Expected<bool> LLMoney_Add(std::string const& xuid, llong money);

ll::Expected<bool> LLMoney_Reduce(std::string const& xuid, llong money);

ll::Expected<std::string> LLMoney_GetHist(std::string const& xuid, int timediff = 24 * 60 * 60);

ll::Expected<void> LLMoney_ClearHist(int difftime = 0);

ll::Expected<void> LLMoney_ListenBeforeEvent(LLMoneyCallback callback);

ll::Expected<void> LLMoney_ListenAfterEvent(LLMoneyCallback callback);

ll::Expected<std::vector<std::pair<std::string, llong>>> LLMoney_Ranking(ushort num = 5);

} // namespace LegacyMoney