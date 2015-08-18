#ifndef PLATFORM__H
#define PLATFORM__H

#if defined( WIN32 ) || defined( WINOBJC )

#include "platform/windows/platform.h"

#else

#include "platform/darwin/platform.h"

#endif

#endif
