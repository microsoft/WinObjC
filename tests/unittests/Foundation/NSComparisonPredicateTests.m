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

#include <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(Foundation, NSComparisonPredicate_Init) {
    NSComparisonPredicate* comparsionPredicate = [[NSComparisonPredicate alloc] init];
    ASSERT_TRUE_MSG(comparsionPredicate != nil, "FAILED: comparsionPredicate should be non-null!");
    [comparsionPredicate release];
}

TEST(Foundation, NSComparisonPredicate_ArchiveAndUnarchiveObject) {
    NSComparisonPredicate* comparsionPredicate = [[NSComparisonPredicate alloc] init];
    ASSERT_TRUE_MSG(comparsionPredicate != nil, "FAILED: comparsionPredicate should be non-null!");

    // archive the object
    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:comparsionPredicate];
    ASSERT_TRUE_MSG(data != nil, "FAILED: archived data should be non-null!");
    // unarchive
    NSComparisonPredicate* unArchivedComparsionPredicate = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_TRUE_MSG(unArchivedComparsionPredicate != nil, "FAILED: unArchivedComparsionPredicate should be non-null!");

    [comparsionPredicate release];
}

TEST(Foundation, NSComparisonPredicate_copy) {
    NSComparisonPredicate* comparsionPredicate = [[NSComparisonPredicate alloc] init];
    ASSERT_TRUE_MSG(comparsionPredicate != nil, "FAILED: comparsionPredicate should be non-null!");

    NSComparisonPredicate* copyObj = [comparsionPredicate copy];
    ASSERT_TRUE_MSG(copyObj != nil, "FAILED: copyObj should be non-null!");

    ASSERT_OBJCEQ_MSG(comparsionPredicate, copyObj, "FAILED: objects do not match.");

    [copyObj release];
    [comparsionPredicate release];
}