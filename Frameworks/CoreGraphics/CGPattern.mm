//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) Microsoft. All rights reserved.
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

#import <StubReturn.h>
#import <Starboard.h>
#import <CFCppBase.h>
#import <CoreGraphics/CGBitmapContext.h>
#import "CGPatternInternal.h"
#import "CGContextInternal.h"

struct __CGPattern : CoreFoundation::CppBase<__CGPattern> {
    __CGPattern(CGImageRef image) : _simpleImage(image), _transformMatrix(CGAffineTransformIdentity) {
    }

    __CGPattern(void* info,
                CGRect bounds,
                CGAffineTransform matrix,
                CGFloat xStep,
                CGFloat yStep,
                CGPatternTiling tiling,
                bool isColored,
                const CGPatternCallbacks* callbacks)
        : _info(info),
          _bounds(bounds),
          _transformMatrix(matrix),
          _xStep(xStep),
          _yStep(yStep),
          _tiling(tiling),
          _isColored(isColored),
          _callbacks(*callbacks) {
    }

    ~__CGPattern() {
        if (_callbacks.releaseInfo) {
            _callbacks.releaseInfo(_info);
        }
    }

    inline const CGRect Bounds() const {
        return _bounds;
    }

    inline void IssuePatternCallback(CGContextRef context) const {
        _callbacks.drawPattern(_info, context);
    }

    inline CGAffineTransform GetTransformMatrix() const {
        return _transformMatrix;
    }

    inline CGRect FinalPatternSize() const {
        return { CGPointZero, { _xStep, _yStep } };
    }

    inline bool Colored() const {
        return _isColored;
    }

private:
    woc::StrongCF<CGImageRef> _generatedImage;
    woc::StrongCF<CGImageRef> _simpleImage;
    void* _info;
    CGRect _bounds;
    CGAffineTransform _transformMatrix;
    CGFloat _xStep;
    CGFloat _yStep;
    CGPatternTiling _tiling;
    bool _isColored;
    CGPatternCallbacks _callbacks;
};

/**
 @Status Interoperable
 */
CGPatternRef CGPatternCreate(void* info,
                             CGRect bounds,
                             CGAffineTransform matrix,
                             CGFloat xStep,
                             CGFloat yStep,
                             CGPatternTiling tiling,
                             bool isColored,
                             const CGPatternCallbacks* callbacks) {
    RETURN_NULL_IF(!callbacks);
    return __CGPattern::CreateInstance(kCFAllocatorDefault, info, bounds, matrix, xStep, yStep, tiling, isColored, callbacks);
}

/**
 @Status Interoperable
 */
CGPatternRef CGPatternRetain(CGPatternRef pattern) {
    RETURN_NULL_IF(!pattern);
    CFRetain(static_cast<CFTypeRef>(pattern));
    return pattern;
}

/**
 @Status Interoperable
*/
void CGPatternRelease(CGPatternRef pattern) {
    RETURN_IF(!pattern);
    CFRelease(static_cast<CFTypeRef>(pattern));
}

CGPatternRef _CGPatternCreateFromImage(CGImageRef img) {
    return __CGPattern::CreateInstance(kCFAllocatorDefault, img);
}

/**
 @Status Interoperable
*/
CFTypeID CGPatternGetTypeID() {
    return __CGPattern::GetTypeID();
}

CGRect _CGPatternGetBounds(CGPatternRef pattern) {
    RETURN_RESULT_IF_NULL(pattern, CGRectNull);
    return pattern->Bounds();
}

void _CGPatternIssueCallBack(CGContextRef context, CGPatternRef pattern) {
    FAIL_FAST_IF_NULL(context);
    FAIL_FAST_IF_NULL(pattern);
    pattern->IssuePatternCallback(context);
}

CGAffineTransform _CGPatternGetTransformation(CGPatternRef pattern) {
    RETURN_RESULT_IF_NULL(pattern, CGAffineTransformIdentity);
    return pattern->GetTransformMatrix();
}

CGRect _CGPatternGetFinalPatternSize(CGPatternRef pattern) {
    RETURN_RESULT_IF_NULL(pattern, CGRectNull);
    return pattern->FinalPatternSize();
}

bool _CGPatternIsColored(CGPatternRef pattern) {
    return pattern->Colored();
}