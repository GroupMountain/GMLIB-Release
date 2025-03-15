#pragma once
#include "gmlib/Macros.h"
#include <ll/api/memory/Memory.h>

namespace gmlib::memory {

#if defined(WIN32) || defined(_WIN32)

template <typename RetType = void, typename... Args>
using FunctionPtr = RetType (*)(Args...);

GMLIB_NDAPI ll::memory::FuncPtr getFunctionAddress(std::string const& funcName);

GMLIB_NDAPI ll::memory::FuncPtr getFunctionAddress(std::wstring const& dllName, std::string const& funcName);

template <typename RetType = void, typename... Args>
[[nodiscard]] inline ll::Expected<FunctionPtr<RetType, Args...>> getFunctionPtr(std::string const& funcName) {
    if (auto* funcPtr = getFunctionAddress(funcName)) {
        return reinterpret_cast<FunctionPtr<RetType, Args...>>(funcPtr);
    }
    return ll::makeStringError(fmt::format("Couldn't find function: {}", funcName));
}

template <typename RetType = void, typename... Args>
[[nodiscard]] inline ll::Expected<FunctionPtr<RetType, Args...>>
getFunctionPtr(std::wstring const& dllName, std::string const& funcName) {
    if (auto* funcPtr = getFunctionAddress(dllName, funcName)) {
        return reinterpret_cast<FunctionPtr<RetType, Args...>>(funcPtr);
    }
    return ll::makeStringError(fmt::format("Couldn't find function: {}", funcName));
}

template <typename RetType = void, typename... Args>
inline ll::Expected<RetType> callFunction(std::string const& funcName, Args... args) {
    if (auto funcPtr = getFunctionPtr<RetType, Args...>(funcName); funcPtr) {
        try {
            auto& func = *funcPtr;
            if constexpr (std::is_void<RetType>::value) {
                func(std::forward<Args>(args)...);
                return {};
            } else {
                return func(std::forward<Args>(args)...);
            }
        } catch (...) {
            return ll::makeExceptionError();
        }
    }
    return ll::makeStringError(fmt::format("Couldn't find function: {}", funcName));
}

template <typename RetType = void, typename... Args>
inline ll::Expected<RetType> callFunction(std::wstring const& dllName, std::string const& funcName, Args... args) {
    if (auto funcPtr = getFunctionPtr<RetType, Args...>(dllName, funcName); funcPtr) {
        try {
            auto& func = *funcPtr;
            if constexpr (std::is_void<RetType>::value) {
                func(std::forward<Args>(args)...);
                return {};
            } else {
                return func(std::forward<Args>(args)...);
            }
        } catch (...) {
            return ll::makeExceptionError();
        }
    }
    return ll::makeStringError(fmt::format("Couldn't find function: {}", funcName));
}

#else
// TODO: Linux
#endif

} // namespace gmlib::memory