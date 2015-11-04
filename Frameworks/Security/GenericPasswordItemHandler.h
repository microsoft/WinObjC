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

#pragma once
#import "SecItemHandlerProtocol.h"

// This is really not cool and shouldn't be needed. The projections need to handle including standard windows headers
// or not rely windows types
using WCHAR = wchar_t;
#import <UWP/WindowsSecurityCredentials.h>

@interface GenericPasswordItemHandler : NSObject <SecItemHandler>

- (instancetype)init;
- (instancetype)initWithVault:(WSCPasswordVault*)vault;

- (OSStatus)update:(NSDictionary*)queryDictionary withAttributes:(NSDictionary*)attributesToUpdate;
- (OSStatus)add:(NSDictionary*)attributes withResult:(id*)result;
- (OSStatus)remove:(NSDictionary*)queryDictionary;
- (OSStatus)query:(NSDictionary*)queryDictionary withResult:(id*)result;

@end