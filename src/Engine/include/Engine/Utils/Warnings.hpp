/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

// @formatter:off

#pragma once

#include "Platform.hpp"

#if defined(COMPILER_MSC)
#    define DISABLE_WARNING_PUSH __pragma(warning(push))
#    define DISABLE_WARNING_POP  __pragma(warning(pop))
#    define DISABLE_WARNING(num) __pragma(warning(disable : num))

#    define DISABLE_WARN_UNUSED DISABLE_WARNING(4100)
#    define DISABLE_WARN_USELESS_CAST

#elif defined(COMPILER_GCC)
#    define DO_PRAGMA(X)          _Pragma(#X)
#    define DISABLE_WARNING_PUSH  DO_PRAGMA(GCC diagnostic push)
#    define DISABLE_WARNING_POP   DO_PRAGMA(GCC diagnostic pop)
#    define DISABLE_WARNING(name) DO_PRAGMA(GCC diagnostic ignored #name)

#    define DISABLE_WARN_UNUSED       DISABLE_WARNING(-Wunused-parameter)
#    define DISABLE_WARN_USELESS_CAST DISABLE_WARNING(-Wuseless-cast)
#elif defined(COMPILER_CLANG)
#    define DO_PRAGMA(X)          _Pragma(#    X)
#    define DISABLE_WARNING_PUSH  DO_PRAGMA(clang diagnostic push)
#    define DISABLE_WARNING_POP   DO_PRAGMA(clang diagnostic pop)
#    define DISABLE_WARNING(name) DO_PRAGMA(clang diagnostic ignored #    name)

#    define DISABLE_WARN_UNUSED DISABLE_WARNING(-Wunused - parameter)
#    define DISABLE_WARN_USELESS_CAST
#endif

// @formatter:on
