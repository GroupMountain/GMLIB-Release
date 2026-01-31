#pragma once
#include <concepts>
namespace gmlib {
template <std::integral Internal, typename Friend>
class FlagEnum {
    Internal mValue;
    constexpr explicit FlagEnum(Internal value) : mValue(value) {}

public:
    constexpr FlagEnum(const FlagEnum&)                   = default;
    constexpr FlagEnum(FlagEnum&&)                        = default;
    constexpr FlagEnum& operator=(const FlagEnum&)        = default;
    constexpr FlagEnum& operator=(FlagEnum&&)             = default;
    constexpr bool      operator==(const FlagEnum&) const = default;
    constexpr FlagEnum  operator|(const FlagEnum& other) const {
        return FlagEnum{static_cast<Internal>(mValue | other.mValue)};
    }
    constexpr FlagEnum& operator|=(const FlagEnum& other) {
        mValue |= other.mValue;
        return *this;
    }
    constexpr FlagEnum operator&(const FlagEnum& other) const {
        return FlagEnum{static_cast<Internal>(mValue & other.mValue)};
    }
    constexpr FlagEnum& operator&=(const FlagEnum& other) {
        mValue &= other.mValue;
        return *this;
    }
    constexpr explicit operator bool() const { return mValue; }
    friend Friend;
};
} // namespace gmlib