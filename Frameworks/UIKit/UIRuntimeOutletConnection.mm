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

#include "Starboard.h"
#include "UIRuntimeOutletConnection.h"
#include "LoggingNative.h"

static const wchar_t* TAG = L"UIRuntimeOutletConnection";

@implementation UIRuntimeOutletConnection
- (instancetype)initWithCoder:(NSCoder*)coder {
    source = [coder decodeObjectForKey:@"UISource"];
    dest = [coder decodeObjectForKey:@"UIDestination"];
    label = [coder decodeObjectForKey:@"UILabel"];
    return self;
}

- (void)_makeConnection {
    const char* labelName = [label UTF8String];
    if (source != nil) {
        TraceVerbose(TAG, L"Setting property on %hs: %hs", object_getClassName(source), labelName);
    } else {
        TraceVerbose(TAG, L"Source = nil, can't set property %hs", labelName);
    }

    [source setValue:dest forKey:label];

    /*
    char labelLowerName[255];
    strcpy_s(labelLowerName, sizeof(labelLowerName), labelName);
    labelLowerName[0] = toupper(labelLowerName[0]);
    char setName[255];
    sprintf_s(setName, sizeof(setName), "set%s:", labelLowerName);

    if ( !setProperty(source, labelName, dest) ) {
    if ( [source respondsToSelector:setName] ) {
    TraceVerbose(TAG, L"Setting property on %hs: %hs", object_getClassName(source), setName);
    MSGSEND1(source, setName, dest);
    } else {
    assert(0);
    }
    }
    */
}

@end
