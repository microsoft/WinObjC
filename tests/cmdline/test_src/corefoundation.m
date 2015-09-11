#import <CoreFoundation/CoreFoundation.h>
#import <mach/mach_time.h>
#include <stdio.h>
#include <assert.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    printf("CoreFoundation sanity test: ");
    
    uint64_t start = mach_absolute_time();
    Sleep(1500);
    uint64_t end = mach_absolute_time();
    struct mach_timebase_info elapsed;
    if ( mach_timebase_info(&elapsed) != KERN_SUCCESS ) {
        printf("FAILED: mach_timebase_info failed\n");
        return -1;
    }
    uint64_t elapsedNS = (end - start) * elapsed.numer / elapsed.denom;
    int64_t diff = elapsedNS - 1500000000LL;
    if ( diff < 0 ) diff = -diff;
    printf("mach_absolute_time jitter: %lldns ", diff);
    
    if ( diff > 20000000 ) {
        printf("FAILED: mach_absolute_time drift too high (%llu, %llu, %d, %d)\n", start, end, elapsed.numer, elapsed.denom);
        return -1;
    }
    
    printf("PASSED\n");

    return 0;
}