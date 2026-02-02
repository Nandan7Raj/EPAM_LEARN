//
// Created by NandanRaj on 01-02-2026.
//

#pragma once

#if defined(_WIN32)
    #define OS_NAME "Windows"
#elif defined(__linux__)
    #define OS_NAME "LINUX"
#elif defined(__APPLE__)
    #define OS_NAME "OSX"
#else
    #define OS_NAME "Unknown OS"
#endif