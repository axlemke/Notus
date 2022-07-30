#pragma once

#include <string>
#include <stddef.h>

// dlls or static lib macros
#if defined(USE_STATIC_LIBS)
#define LIBRARY_EXPORT
#define LIBRARY_IMPORT
#else
#define LIBRARY_EXPORT __declspec(dllexport)
#define LIBRARY_IMPORT __declspec(dllimport)
#endif

