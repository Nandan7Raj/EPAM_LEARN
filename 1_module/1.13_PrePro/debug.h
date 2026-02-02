//
// Created by NandanRaj on 02-02-2026.
//
#pragma once
#include<iostream>
// In DEBUG mode: print message with file, line, and function context.
// In non-DEBUG mode: expand to a no-op (no output, no overhead).
#ifdef DEBUG
    #define DEBUG_PRINT(x) \
    do {\
        std::cout<<"[DEBUG] : "<<__FILE__<<" : "<<__LINE__<<": "<<x<<std::endl;\
        std::cout<<"-------------";\
    }while (0)
#else
    #define DEBUG_PRINT(x)\
     do {\
     }while (0)
#endif