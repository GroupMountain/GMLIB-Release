#pragma once

namespace gmlib {

// The type control the PlayerList show ways
enum class PlayerListType : int {
    Top     = 0,
    Natural = 1,
    Bottom  = 2,
};

/*
    Example:
    _________________
    Top:

    FakeEntry1
    FakeEntry2
    ....
    Player1
    Player2
    ....
    __________________

    Natural type: Treat the fake entries as a real player showing player list:

    Player1
    Player2
    ....
    FakeEntry1
    FakeEntry2
    ....
    Player n-1
    player n
    _________________
    Bottom:

    Player1
    Player2
    ....
    FakeEntry1
    FakeEntry2
    ....

*/
} // namespace gmlib