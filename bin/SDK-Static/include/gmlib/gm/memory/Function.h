#pragma once
#include <ll/api/memory/Memory.h>

namespace gmlib::memory {

template <typename RetType = void, typename... Args>
using FunctionPtr   = RetType (*)(Args...);
using ModuleHandleT = void*;

ll::memory::FuncPtr getFunctionAddress(std::string const& funcName);

ll::memory::FuncPtr getFunctionAddress(std::wstring const& modName, std::string const& funcName);

ll::memory::FuncPtr getFunctionAddress(ModuleHandleT modHandle, std::string const& funcName);

#define DETAIL_GMLIB_FUNCPTR_GET(...)                                                                                  \
    if (auto* funcPtr = getFunctionAddress(__VA_ARGS__)) {                                                             \
        return reinterpret_cast<FunctionPtr<RetType, Args...>>(funcPtr);                                               \
    }                                                                                                                  \
    return ll::makeStringError(fmt::format("Couldn't find function: {} in memory.", funcName))

template <typename RetType = void, typename... Args>
[[nodiscard]] inline ll::Expected<FunctionPtr<RetType, Args...>> getFunctionPtr(std::string const& funcName) {
    DETAIL_GMLIB_FUNCPTR_GET(funcName);
}

template <typename RetType = void, typename... Args>
[[nodiscard]] inline ll::Expected<FunctionPtr<RetType, Args...>>
getFunctionPtr(std::wstring const& modName, std::string const& funcName) {
    DETAIL_GMLIB_FUNCPTR_GET(modName, funcName);
}

template <typename RetType = void, typename... Args>
[[nodiscard]] inline ll::Expected<FunctionPtr<RetType, Args...>>
getFunctionPtr(ModuleHandleT modHandle, std::string const& funcName) {
    DETAIL_GMLIB_FUNCPTR_GET(modHandle, funcName);
}

#define DETAIL_GMLIB_FUNCTION_CALL(...)                                                                                \
    if (auto funcPtr = getFunctionPtr<RetType, Args...>(__VA_ARGS__); funcPtr) {                                       \
        try {                                                                                                          \
            auto& func = *funcPtr;                                                                                     \
            if constexpr (std::is_void<RetType>::value) {                                                              \
                func(std::forward<Args>(args)...);                                                                     \
                return {};                                                                                             \
            } else {                                                                                                   \
                return func(std::forward<Args>(args)...);                                                              \
            }                                                                                                          \
        } catch (...) {                                                                                                \
            return ll::makeExceptionError();                                                                           \
        }                                                                                                              \
    }                                                                                                                  \
    return ll::makeStringError(fmt::format("Couldn't find function: {} in memory.", funcName))

template <typename RetType = void, typename... Args>
inline ll::Expected<RetType> callFunction(std::string const& funcName, Args... args) {
    DETAIL_GMLIB_FUNCTION_CALL(funcName);
}

template <typename RetType = void, typename... Args>
inline ll::Expected<RetType> callFunction(std::wstring const& modName, std::string const& funcName, Args... args) {
    DETAIL_GMLIB_FUNCTION_CALL(modName, funcName);
}

template <typename RetType = void, typename... Args>
inline ll::Expected<RetType> callFunction(ModuleHandleT modHandle, std::string const& funcName, Args... args) {
    DETAIL_GMLIB_FUNCTION_CALL(modHandle, funcName);
}

} // namespace gmlib::memory