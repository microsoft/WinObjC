#import <Foundation/Foundation.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    printf("OBJCRT sanity test: ");
    
    NSObject *obj1 = [NSObject new];
    NSObject *obj2 = [NSObject new];

    if ( obj1 == obj2 ) {
        printf("FAILED: obj1 and obj2 should be distinct pointers!\n");
        return -1;
    }
    
    [obj1 release];
    [obj2 release];
    
    printf("PASSED\n");
    
    return 0;
}