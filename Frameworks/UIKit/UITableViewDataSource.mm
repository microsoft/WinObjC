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
#include "UITableViewDataSource.h"

@implementation UITableViewDataSource : NSObject
- (id)initWithCoder:(NSCoder*)coder {
    _tableSections = [coder decodeObjectForKey:@"UITableSections"];
    return self;
}

- (void)dealloc {
    _tableSections = nil;
    [super dealloc];
}

- (unsigned)numberOfSections {
    return [_tableSections count];
}

- (UITableViewSection*)sectionForIndex:(unsigned)idx {
    return [_tableSections objectAtIndex:idx];
}

@end
