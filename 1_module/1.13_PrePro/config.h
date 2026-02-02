//
// Created by NandanRaj on 02-02-2026.
//

#ifndef CONFIG_H
#define CONFIG_H
// Purpose:
// This header defines the software VERSION and derives a human-readable
// version message at compile time using preprocessor directives.
//
//  Usage:
//  - VERSION can be provided by the compiler (e.g., -DVERSION=4)
//  - If not provided, a default VERSION value is used.
//Define the software default version

// If VERSION is not defined by the compiler or elsewhere,
// provide a safe default value.

#ifndef  VERSION
    #define VERSION 5
#endif
// Decide version message at compile time
#if VERSION>=3
    #define VERSION_MSG "Stable version"
#else
    #define VERSION_MSG "Beta version"
#endif
#endif//CONFIG_H