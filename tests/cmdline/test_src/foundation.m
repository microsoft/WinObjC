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
    
    //  Feb 14, 2012 12:00 GMT (leap year)
    NSDate *startDate = [NSDate dateWithTimeIntervalSince1970: 1329220800.0];    
    //  Apr 1, 2012 12:00 GMT
    NSDate *endDate = [NSDate dateWithTimeIntervalSince1970: 1333281600.0];
    
    NSTimeZone *curTZ = [NSTimeZone timeZoneWithName: @"America/Los_Angeles"];
    if ( [curTZ isDaylightSavingTimeForDate: startDate] != NO ||
         [curTZ isDaylightSavingTimeForDate: endDate] != YES ) {
        printf("FAILED: timezone daylight savings time failure: %d %d\n", 
            [curTZ isDaylightSavingTimeForDate: startDate],
            [curTZ isDaylightSavingTimeForDate: endDate]);
        return -1;
    }
    
    NSCalendar *curCal = [NSCalendar currentCalendar];
    [curCal setTimeZone: curTZ];
    
    NSDateComponents *component1 = [curCal components: NSSecondCalendarUnit | NSMinuteCalendarUnit |
                                                       NSHourCalendarUnit | NSDayCalendarUnit | 
                                                       NSMonthCalendarUnit | NSYearCalendarUnit
                                           fromDate: startDate];
    if ( component1.second != 0 ||
         component1.minute != 0 ||
         component1.hour != 4 ||
         component1.day != 14 ||
         component1.month != 2 ||
         component1.year != 2012 ) {
        printf("FAILED: component1 not accurate: %d %d %d %d %d %d\n", component1.second, component1.minute, component1.hour, component1.day, component1.month, component1.year);
        return -1;
    }
    
    NSDateComponents *comp1 = [curCal components: NSSecondCalendarUnit | NSMinuteCalendarUnit |
                                                  NSHourCalendarUnit | NSDayCalendarUnit | 
                                                  NSMonthCalendarUnit | NSYearCalendarUnit
                                           fromDate: startDate toDate: endDate options: 0];

    if ( comp1.second != 0 || 
         comp1.minute != 0 || 
         comp1.hour != 1 ||
         comp1.day != 18 ||
         comp1.month != 1 ||
         comp1.year != 0 ) {
        printf("FAILED: comp1 not accurate: %d %d %d %d %d %d\n", comp1.second, comp1.minute, comp1.hour, comp1.day, comp1.month, comp1.year);
        return -1;
    }
    
    NSDateComponents *comp2 = [curCal components: NSSecondCalendarUnit
                               fromDate: startDate toDate: endDate options: 0];
    if ( comp2.second != 4060800 ) {
        printf("FAILED: comp2 not accurate: %d\n", comp2.second);
        return -1;
    }
    
    printf("PASSED\n");
    
    return 0;
}