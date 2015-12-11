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

@implementation UIRuntimeOutletConnection : NSObject
- (instancetype)initWithCoder:(NSCoder*)coder {
    source = [coder decodeObjectForKey:@"UISource"];
    dest = [coder decodeObjectForKey:@"UIDestination"];
    label = [coder decodeObjectForKey:@"UILabel"];
    return self;
}

- (void)_makeConnection {
    const char* labelName = [label UTF8String];
    if (source != nil) {
        EbrDebugLog("Setting property on %s: %s\n", object_getClassName(source), labelName);
    } else {
        EbrDebugLog("Source = nil, can't set property %s\n", labelName);
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
    EbrDebugLog("Setting property on %s: %s\n", object_getClassName(source), setName);
    MSGSEND1(source, setName, dest);
    } else {
    assert(0);
    }
    }
    */
}

@end
