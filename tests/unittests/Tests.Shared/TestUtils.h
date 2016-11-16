//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Foundation/Foundation.h>
#import <functional>
#include <memory>

#define _CONCAT(x, y) x##y
#define CONCAT(x, y) _CONCAT(x, y)

#define _SCOPE_GUARD(STATEMENT) std::unique_ptr<void, std::function<void(void*)>> CONCAT(_closeScope_, __LINE__)((void*)0x1, STATEMENT)

void assertOrderedSetContent(NSOrderedSet* set, NSObject* first, ...);
NSString* getModulePath();
NSString* getPathToFile(NSString* fileName);
void createFileWithContentAndVerify(NSString* fileName, NSString* content);
void deleteFile(NSString* name);

#define SCOPE_CLOSE_HANDLE(fileHandle) \
    \
_SCOPE_GUARD([fileHandle](void*) { [fileHandle closeFile]; })

#define SCOPE_DELETE_FILE(fileName) _SCOPE_GUARD([fileName](void*) { deleteFile(fileName); })