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
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableArray.h"
#include "CoreGraphics/CGGeometry.h"
#include "UIGridLayoutInfo.h"
#include "UIGridLayoutSection.h"

@implementation UIGridLayoutInfo : NSObject
    /* annotate with type */ -(id) setHorizontal:(BOOL)horizontal {
        _horizontal = horizontal;
        return 0;
    }

    -(BOOL) horizontal {
        return _horizontal;
    }

    /* annotate with type */ -(id) setDimension:(float)dimension {
        _dimension = dimension;
        return 0;
    }

    -(float) dimension {
        return _dimension;
    }

    /* annotate with type */ -(id) setRowAlignmentOptions:(id)options {
        _rowAlignmentOptions = [options copy];
        return 0;
    }

    /* annotate with type */ -(id) init {
        _sections.attach([NSMutableArray new]);
        return self;
    }

    /* annotate with type */ -(id) sections {
        return _sections;
    }

    /* annotate with type */ -(id) addSection {
        id section = [UIGridLayoutSection new];
        [section setRowAlignmentOptions:(id) _rowAlignmentOptions];
        [section setLayoutInfo:self];
        [_sections addObject:section];
        [self invalidate:NO];
        return section;
    }

    /* annotate with type */ -(id) invalidate:(BOOL)arg {
        _isValid = NO;
        return 0;
    }

    /* annotate with type */ -(id) setContentSize:(CGSize)size {
        _contentSize = size;
        return 0;
    }

    -(CGSize) contentSize {
        return _contentSize;
    }

    
@end

