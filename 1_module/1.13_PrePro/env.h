//
// Created by NandanRaj on 02-02-2026.
//

#pragma once  // Ensures this header is included only once per translation unit
// The compiler checks which environment macro is defined
// and assigns the corresponding API endpoint.
#define ENV_H
    #if defined(DEV)
        // Development environment (local machine)
        #define API_URL "http://localhost"
    #elif defined(TEST)
        // Testing / staging environment
        #define API_URL "http://test-server"
    #else
        // Production environment (default case)
        #define API_URL "http://prod-server"
    #endif