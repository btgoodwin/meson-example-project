#pragma once

#include "config.h"

#if !defined(__EXAMPLE_LIB_INSIDE__) && !defined(EXAMPLE_LIB_COMPILATION)
#error "Only <example.h> can be included directly."
#endif

#ifndef EXAMPLE_LIB_EXPORT
#define EXAMPLE_LIB_EXPORT extern
#endif

#ifndef EXAMPLE_LIB_IMPORT
#define EXAMPLE_LIB_IMPORT
#endif

#ifdef EXAMPLE_LIB_COMPILATION
#define EXAMPLE_LIB_API EXAMPLE_LIB_EXPORT
#else
#define EXAMPLE_LIB_API EXAMPLE_LIB_IMPORT
#endif