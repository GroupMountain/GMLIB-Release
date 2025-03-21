#pragma once

// clang-format off
#define GMLIB_VERSION_MAJOR         1
#define GMLIB_VERSION_MINOR         0
#define GMLIB_VERSION_PATCH         0
#define GMLIB_VERSION_PRERELEASE "rc.3"
#define GMLIB_VERSION_COMMIT_SHA    b97c9e9
// clang-format on

#define GMLIB_WORKSPACE_FOLDER R"(D:\a\GMLIB\GMLIB\)"

#define GMLIB_VERSION_TO_STRING_INNER(ver) #ver
#define GMLIB_VERSION_TO_STRING(ver)       GMLIB_VERSION_TO_STRING_INNER(ver)

#ifdef GMLIB_VERSION_PRERELEASE
#define GMLIB_FILE_VERSION_FLAG VS_FF_DEBUG
#define GMLIB_FILE_VERSION_STRING                                                                                      \
    GMLIB_VERSION_TO_STRING(GMLIB_VERSION_MAJOR)                                                                       \
    "." GMLIB_VERSION_TO_STRING(GMLIB_VERSION_MINOR) "." GMLIB_VERSION_TO_STRING(GMLIB_VERSION_PATCH                   \
    ) "-" GMLIB_VERSION_PRERELEASE "+" GMLIB_VERSION_TO_STRING(GMLIB_VERSION_COMMIT_SHA)
#else
#define GMLIB_FILE_VERSION_FLAG 0x00000000L
#define GMLIB_FILE_VERSION_STRING                                                                                      \
    GMLIB_VERSION_TO_STRING(GMLIB_VERSION_MAJOR)                                                                       \
    "." GMLIB_VERSION_TO_STRING(GMLIB_VERSION_MINOR) "." GMLIB_VERSION_TO_STRING(GMLIB_VERSION_PATCH                   \
    ) "+" GMLIB_VERSION_TO_STRING(GMLIB_VERSION_COMMIT_SHA)
#endif
