#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include <stdio.h>
#include <assert.h>
#include <dispatch/dispatch.h>
#include <crtdbg.h>

int ranAsyncBlock = 0;

int main(int argc, char *argv[])
{
    dispatch_async(dispatch_get_main_queue(), ^void() {
        assert([NSThread isMainThread]);
        ranAsyncBlock ++;
        printf("async1 method called\n");
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 1 * NSEC_PER_SEC), dispatch_get_main_queue(), ^void() {
            ranAsyncBlock ++;
            printf("async timer method called\n");
            dispatch_async(dispatch_get_main_queue(), ^void() {
                ranAsyncBlock ++;
                printf("async shutdown method called\n");
                UIShutdown();
            });
        });
    });
    
    UIApplicationMainLoop();
    if ( ranAsyncBlock == 3 ) {
        printf("Main queue was drained from main runloop\n");

        return 0;
    } else {
        printf("Main queue was NOT drained from main runloop\n");
    
        return 1;
    }
}