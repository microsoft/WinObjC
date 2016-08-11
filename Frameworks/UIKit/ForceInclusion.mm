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
#include "UIKit/UIRuntimeEventConnection.h"
#include "UIButtonContent.h"
#include "UIImageNibPlaceholder.h"
#include "UIProxyObject.h"
#include "UIRuntimeOutletConnection.h"
#include "UIRuntimeOutletCollectionConnection.h"
#include "UITableViewCellContentView.h"
#include "UIClassSwapper.h"
#include "../QuartzCore/CATransaction.h"
#include "../Foundation/NSColor.h"

extern "C" void NSObjForceinclude();
void NSStringForceinclude();
void NSValueForceinclude();

// Make sure things are compiled in:
void ForceInclusion() {
    [UIRuntimeEventConnection class];
    [UIRuntimeOutletConnection class];
    [UIRuntimeOutletCollectionConnection class];
    [UITableViewCellContentView class];
    [UIClassSwapper class];
    [UIImageNibPlaceholder class];
    [UIButtonContent class];
    [UIPickerView class];
    [UIActionSheet class];
    [CATransaction class];
    [NSColor class];
    [UISwitch class];
    [UISlider class];
    [UIProxyObject class];
    NSStringForceinclude();
    NSValueForceinclude();
}
