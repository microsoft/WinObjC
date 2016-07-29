//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// Windows-only:
//      NSBooleanPredicate

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import "NSBooleanPredicate.h"

TEST(NSBooleanPredicate, NSBooleanPredicateYES) {
    NSBooleanPredicate* predicate = [[NSBooleanPredicate alloc] initWithValue:YES];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");
    ASSERT_TRUE_MSG([predicate value], "FAILED: predicate should be YES.");
    [predicate release];
}

TEST(NSBooleanPredicate, NSBooleanPredicateNO) {
    NSBooleanPredicate* predicate = [[NSBooleanPredicate alloc] initWithValue:NO];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");
    ASSERT_TRUE_MSG(![predicate value], "FAILED: predicate should be NO.");
    [predicate release];
}

TEST(NSBooleanPredicate, NSBooleanPredicate_ArchiveAndUnarchiveObject) {
    NSBooleanPredicate* predicate = [[NSBooleanPredicate alloc] initWithValue:NO];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");

    // archive the object
    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:predicate];
    ASSERT_TRUE_MSG(data != nil, "FAILED: archived data should be non-null!");

    NSPredicate* unArchivedPredicate = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_TRUE_MSG(unArchivedPredicate != nil, "FAILED: unArchivedPredicate should be non-null!");

    [predicate release];
}