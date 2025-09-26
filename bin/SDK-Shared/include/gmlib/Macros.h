#pragma once

#ifdef GMLIB_EXPORTS
#define GMLIB_API [[maybe_unused]] __declspec(dllexport)
#else
#define GMLIB_API [[maybe_unused]] __declspec(dllimport)
#endif

#define GMLIB_NDAPI [[nodiscard]] GMLIB_API

#define GMLIB_CAPI   extern "C" GMLIB_API
#define GMLIB_NDCAPI [[nodiscard]] GMLIB_CAPI