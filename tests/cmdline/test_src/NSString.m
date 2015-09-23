#import <Foundation/Foundation.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    printf("NSString tests: ");

    // NSString  *PercentEncoding methods.

    NSString *decodedString = @"Space DoubleQuotes\"Hash#Percent%LessThan<GreaterThan>OpeningBracket[Backslash\\ClosingBracket]Caret^GraveAccent`OpeningBrace{VerticalBar|ClosingBrace}";
    NSString *encodedString = @"Space%20DoubleQuotes%22Hash%23Percent%25LessThan%3CGreaterThan%3EOpeningBracket%5BBackslash%5CClosingBracket%5DCaret%5EGraveAccent%60OpeningBrace%7BVerticalBar%7CClosingBrace%7D";

    NSString *testString = [decodedString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    if ( ![testString isEqualToString:encodedString] ) {
        printf("FAILED: [stringByAddingPercentEscapesUsingEncoding] testString and encodedString should be equal!\n");
        printf("testString: %s\n", [testString UTF8String]);
        return -1;
    }

    testString = [encodedString stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    if ( ![testString isEqualToString:decodedString] ) {
        printf("FAILED: [stringByReplacingPercentEscapesUsingEncoding] testString and decodedString should be equal!\n");
        printf("testString: %s\n", [testString UTF8String]);
        return -1;
    }

    testString = [encodedString stringByRemovingPercentEncoding];
    if ( ![testString isEqualToString:decodedString] ) {
        printf("FAILED: [stringByRemovingPercentEncoding] testString and decodedString should be equal!\n");
        printf("testString: %s\n", [testString UTF8String]);
        return -1;
    }

    printf("PASSED\n");

    return 0;
}
