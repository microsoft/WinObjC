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
#include "UITableViewSection.h"

@implementation UITableViewSection : NSObject

- (id)initWithCoder:(NSCoder*)coder {
    _headerTitle = [coder decodeObjectForKey:@"UITableSectionHeaderTitle"];
    _rows = [coder decodeObjectForKey:@"UITableSectionRows"];
    return self;
}

- (unsigned)numberOfRows {
    return [_rows count];
}

- (NSString*)title {
    return _headerTitle;
}

- (void)dealloc {
    _headerTitle = nil;
    _rows = nil;
    [super dealloc];
}

- (UITableViewRow*)rowForIndex:(unsigned)idx {
    return [_rows objectAtIndex:idx];
}

@end
