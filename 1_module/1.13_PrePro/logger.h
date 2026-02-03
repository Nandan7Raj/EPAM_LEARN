//
// Created by NandanRaj on 02-02-2026.
//

#pragma once  // Ensures this header is included only once
//If LOG_LEVEL is not provided by the compiler, default to INFO (3).
#ifndef LOG_LEVEL
    #define LOG_LEVEL 3
#endif

// The macro prints messages only if the provided 'level'
// is less than or equal to the configured LOG_LEVEL.
#if LOG_LEVEL>=4
    #define LOG(level,msg) \
    if(level<=LOG_LEVEL){\
    cout<<"[DEBUG] "<<msg<<endl;\
    }
#elif  LOG_LEVEL>=3
    #define LOG(level,msg) \
    if(level<=LOG_LEVEL){\
    cout<<"[INFO] "<<msg<<endl;\
}
#elif  LOG_LEVEL>=2
    #define LOG(level,msg) \
    if(level<=LOG_LEVEL){\
    cout<<"[WARN] "<<msg<<endl;\
}
#else
    #define LOG(level,msg) \
    if(level<=LOG_LEVEL){\
    cout<<"[DEBUG] "<<msg<<endl;\
}
#endif


