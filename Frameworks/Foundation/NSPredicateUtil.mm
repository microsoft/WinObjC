//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <NSPredicateUtil.h>
#import <Foundation/NSLocale.h>

NSStringCompareOptions extractStringCompareOptions(NSComparisonPredicateOptions options) {
    // Note, NSNormalizedPredicateOption option supersedes NSCaseInsensitivePredicateOption and NSDiacriticInsensitivePredicateOption.
    NSStringCompareOptions stringOptions = 0;
    if (options & NSNormalizedPredicateOption) {
        return NSLiteralSearch;
    }

    if (options & NSDiacriticInsensitivePredicateOption) {
        stringOptions |= NSDiacriticInsensitiveSearch;
    }
    if (options & NSCaseInsensitiveSearch) {
        stringOptions |= NSCaseInsensitiveSearch;
    }

    return stringOptions;
}

NSLocale* extractLocale(NSComparisonPredicateOptions options) {
    if (options & NSLocaleSensitivePredicateOption) {
        return [NSLocale currentLocale];
    }

    // system locale
    return nil;
}