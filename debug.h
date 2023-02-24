#ifndef DEBUG_H
#define DEBUG_H

// Debug ports
#define DEBUG_MESSAGE   1
#define DEBUG_MATRIX    1
#define DEBUG_VECTOR    0



#define PRINTF(DEBUG, A, ...) \
    if(DEBUG) \
        printf(A, ##__VA_ARGS__); \

#endif