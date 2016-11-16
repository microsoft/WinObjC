#if defined(__clang__) && !defined(__OBJC_RUNTIME_INTERNAL__)
#pragma clang system_header
#endif

/*
 * Blocks Runtime
 */

#include "Availability.h"
#ifdef __cplusplus
#define BLOCKS_EXPORT extern "C"
#else
#define BLOCKS_EXPORT extern 
#endif

BLOCKS_EXPORT void *_Block_copy(void *);
BLOCKS_EXPORT void _Block_release(void *);
BLOCKS_EXPORT const char *block_getType_np(void *b) OBJC_NONPORTABLE;

#define Block_copy(x) ((__typeof(x))_Block_copy((void *)(x)))
#define Block_release(x) _Block_release((void *)(x))
