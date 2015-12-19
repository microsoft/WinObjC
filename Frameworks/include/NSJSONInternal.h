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

typedef wchar_t WCHAR;

#include <COMIncludes.h>
#import <WRL/client.h>
#include <COMIncludes_End.h>

#import <UWP/WindowsDataJson.h>

//TODO: replace the below with RTObject implementation, which will cast safely, when available (VSO 5668328)
/*
* Returns the RTObject casted to the desired class. This is necessary because the WindowsDataJson projection library returns some objects
* that are stored as RTObject but actually contain WDJ types extending from RTObject.
*/
static inline id UWPObjectCast(Class desiredClass, RTObject* rtObject) {
    auto internalComPtr = (__bridge IInspectable*)[rtObject internalObject];
    auto newObject = (RTObject*)NSAllocateObject(desiredClass, 0, nil);
    [newObject setComObj : internalComPtr];
    return [newObject autorelease];
}

#ifdef __cplusplus
/*
* Returns the RTObject casted to the desired class. Templated implementation.
*/
template <typename TDesiredClass>
static id UWPObjectCast(RTObject* rtObject) {
    return UWPObjectCast([TDesiredClass class], rtObject);
}
#endif