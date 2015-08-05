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
#include "Foundation/NSURLResponse.h"

@implementation NSURLResponse : NSObject
    /* annotate with type */ -(id) initWithURL:(id)url MIMEType:(id)mimeType expectedContentLength:(int)expectedContentLength textEncodingName:(id)textEncodingName {
        _expectedContentLength = expectedContentLength;
        _url = url;
        _mimeType.attach([mimeType copy]);
        _textEncodingName.attach([textEncodingName copy]);

        return self;
    }

    /* annotate with type */ -(id) MIMEType {
        return _mimeType;
    }

    /* annotate with type */ -(id) textEncodingName {
        return _textEncodingName;
    }

    -(__int64) expectedContentLength {
        if ( _expectedContentLength == 0 ) {
            return -1;
        }

        return _expectedContentLength;
    }

    -(int) statusCode {
        return 401;
    }
    
    /* annotate with type */ -(id) URL {
        return _url;
    }

    -(void) dealloc {
        _url = nil;
        _mimeType = nil;
        _textEncodingName = nil;

        [super dealloc];
    }

    
@end

@implementation NSCachedURLResponse : NSObject
    
@end

