#import <Foundation/Foundation.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    printf("Foundation sanity test: ");

    NSArray *arr1 = [NSArray arrayWithObject: @1];
    NSArray *arr2 = [NSArray arrayWithObject: @1];
    NSArray *arr3 = [NSArray arrayWithObject: @2];

    if ( ![arr1 isEqual: arr2] ) {
        printf("FAILED: arr1 and arr2 should be equal!\n");
        return -1;
    }
    if ( [arr1 isEqual: arr3] ) {
        printf("FAILED: arr1 and arr2 should not be equal!\n");
        return -1;
    }
    if ( ![arr1[0] isEqual: arr2[0]] ) {
        printf("FAILED: arr1[0] and arr2[0] should be equal!\n");
        return -1;
    }
    if ( [arr1[0] isEqual: arr3[0]] ) {
        printf("FAILED: arr1[0] and arr3[0] should not be equal!\n");
        return -1;
    }
    
    [arr1 release];
    [arr2 release];
    [arr3 release];
    
    printf("PASSED\n");
    
    return 0;
}