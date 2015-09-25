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
#include "Foundation/NSString.h"
#include "Foundation/NSValue.h"
#include "Foundation/NSMethodSignature.h"

@implementation NSValue : NSObject
- (id)initWithCoder:(NSCoder*)coder {
    _valueType = (NSValueType)[coder decodeIntForKey:@"NSV.type"];
    unsigned size;
    void* data = (void*)[coder decodeBytesForKey:@"NSV.data" returnedLength:&size];
    assert(size != 0 && data != NULL);

    switch (_valueType) {
        case pointType:
            memcpy(&v.pointValue, data, sizeof(CGPoint));
            break;

        case sizeType:
            memcpy(&v.sizeValue, data, sizeof(CGSize));
            break;

        case rectType:
            memcpy(&v.rectValue, data, sizeof(CGRect));
            break;

        case transformType:
            memcpy(&v.transformValue, data, sizeof(CATransform3D));
            break;

        case pointerType:
            assert(0);
            break;

        case objcType:
            v.genericValue.copy = (void*)malloc(size);
            memcpy(v.genericValue.copy, data, size);
            v.genericValue.size = size;
            break;

        case nonRetainedObjectType:
            memcpy(&v.pointerValue, data, 4);
            break;

        default:
            assert(0);
    }

    return self;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeInt:_valueType forKey:@"NSV.type"];
    void* data = NULL;
    DWORD size = 0;

    switch (_valueType) {
        case pointType:
            data = &v.pointValue;
            size = sizeof(CGPoint);
            break;

        case sizeType:
            data = &v.sizeValue;
            size = sizeof(CGSize);
            break;

        case rectType:
            data = &v.rectValue;
            size = sizeof(CGRect);
            break;

        case transformType:
            data = &v.transformValue;
            size = sizeof(CATransform3D);
            break;

        case pointerType:
            assert(0);
            break;

        case objcType:
            data = v.genericValue.copy;
            size = v.genericValue.size;
            break;

        case nonRetainedObjectType:
            data = &v.pointerValue;
            size = 4;
            break;

        default:
            data = NULL;
            size = 0;
            assert(0);
            break;
    }
    [coder encodeBytes:(const uint8_t*)data length:size forKey:@"NSV.data"];
}

- (NSValue*)initWithCGPoint:(CGPoint)point {
    memcpy(&v.pointValue, &point, sizeof(CGPoint));
    _valueType = pointType;

    return self;
}

+ (NSValue*)valueWithCGPoint:(CGPoint)point {
    NSValue* ret = [self alloc];

    memcpy(&ret->v.pointValue, &point, sizeof(CGPoint));
    ret->_valueType = pointType;

    return [ret autorelease];
}

+ (NSValue*)valueWithUIOffset:(UIOffset)point {
    NSValue* ret = [self alloc];

    memcpy(&ret->v.pointValue, &point, sizeof(CGPoint));
    ret->_valueType = offsetType;

    return [ret autorelease];
}

- (NSValue*)initWithCGSize:(CGSize)size {
    memcpy(&v.sizeValue, &size, sizeof(CGSize));
    _valueType = sizeType;

    return self;
}

+ (NSValue*)valueWithCGSize:(CGSize)size {
    NSValue* ret = [self alloc];

    memcpy(&ret->v.sizeValue, &size, sizeof(CGSize));
    ret->_valueType = sizeType;

    return [ret autorelease];
}

- (NSValue*)initWithCGRect:(CGRect)rect {
    memcpy(&v.rectValue, &rect, sizeof(CGRect));
    _valueType = rectType;

    return self;
}

+ (NSValue*)valueWithCGRect:(CGRect)rect {
    NSValue* ret = [self alloc];

    memcpy(&ret->v.rectValue, &rect, sizeof(CGRect));
    ret->_valueType = rectType;

    return [ret autorelease];
}

+ (NSValue*)valueWithPointer:(void*)ptr {
    NSValue* ret = [self alloc];

    ret->v.pointerValue = ptr;
    ret->_valueType = pointerType;

    return [ret autorelease];
}

+ (NSValue*)valueWithNonretainedObject:(id)obj {
    NSValue* ret = [self alloc];

    ret->v.pointerValue = (void*)obj;
    ret->_valueType = nonRetainedObjectType;
    EbrDebugLog("Nonretained object: %s (0x%08x)\n", object_getClassName(obj), obj);

    return [ret autorelease];
}

+ (NSValue*)valueWithCATransform3DPtr:(CATransform3D*)pTransform {
    NSValue* ret = [self alloc];

    memcpy(&ret->v.transformValue, pTransform, sizeof(CATransform3D));
    ret->_valueType = transformType;

    return [ret autorelease];
}

+ (NSValue*)valueWithBytes:(void*)value objCType:(char*)objCType {
    if (strcmp(objCType, "{CGPoint=ff}") == 0) {
        return [self valueWithCGPoint:*((CGPoint*)value)];
    }

    NSValue* ret = [self alloc];

    ret->v.genericValue.pType = _strdup(objCType);
    int size = getArgumentSize(ret->v.genericValue.pType);
    ret->v.genericValue.size = size;

    ret->v.genericValue.copy = (void*)malloc(ret->v.genericValue.size);
    memcpy(ret->v.genericValue.copy, value, ret->v.genericValue.size);
    ret->_valueType = objcType;

    return [ret autorelease];
}

+ (NSValue*)value:(void*)value withObjCType:(char*)objCType {
    if (strcmp(objCType, "{CGPoint=ff}") == 0) {
        return [self valueWithCGPoint:*((CGPoint*)value)];
    }

    NSValue* ret = [self alloc];

    ret->v.genericValue.pType = _strdup(objCType);
    ret->v.genericValue.size = getArgumentSize(ret->v.genericValue.pType);
    ret->v.genericValue.copy = (void*)malloc(ret->v.genericValue.size);
    memcpy(ret->v.genericValue.copy, value, ret->v.genericValue.size);
    ret->_valueType = objcType;

    return [ret autorelease];
}

- (NSValue*)initWithCATransform3D:(CATransform3D)transform {
    memcpy(&v.transformValue, &transform, sizeof(CATransform3D));
    _valueType = transformType;

    return self;
}

+ (NSValue*)valueWithCATransform3D:(CATransform3D)transform {
    NSValue* ret = [self alloc];

    memcpy(&ret->v.transformValue, &transform, sizeof(CATransform3D));
    ret->_valueType = transformType;

    return [ret autorelease];
}

+ (NSValue*)valueWithCGAffineTransform:(CGAffineTransform)transform {
    NSValue* ret = [self alloc];

    memcpy(&ret->v.affineTransformValue, &transform, sizeof(CGAffineTransform));
    ret->_valueType = affineTransformType;

    return [ret autorelease];
}

- (CGPoint)CGPointValue {
    assert(_valueType == pointType);
    return v.pointValue;
}

- (CGSize)CGSizeValue {
    assert(_valueType == sizeType);
    return v.sizeValue;
}

- (CGRect)CGRectValue {
    assert(_valueType == rectType);
    return v.rectValue;
}

- (CATransform3D)CATransform3DValue {
    assert(_valueType == transformType);
    return *((CATransform3D*)&v.transformValue);
}

- (CGAffineTransform)CGAffineTransformValue {
    assert(_valueType == affineTransformType);
    return *((CGAffineTransform*)&v.affineTransformValue);
}

- (void*)pointerValue {
    if (_valueType != pointerType && _valueType != nonRetainedObjectType) {
        assert(0);
    }
    return v.pointerValue;
}

- (id)nonretainedObjectValue {
    assert(_valueType == nonRetainedObjectType);
    return (id)v.pointerValue;
}

- (void)getValue:(void*)dest {
    switch (_valueType) {
        case pointType:
            memcpy(dest, &v.pointValue, sizeof(CGPoint));
            break;

        case objcType:
            memcpy(dest, v.genericValue.copy, v.genericValue.size);
            break;

        case rectType:
            memcpy(dest, &v.rectValue, sizeof(CGRect));
            break;

        default:
            assert(0);
    }
}

- (BOOL)isEqualToValue:(NSValue*)toValue {
    if (![toValue isKindOfClass:[NSValue class]]) {
        return FALSE;
    }
    NSValue* otherValue = toValue;

    if (_valueType != otherValue->_valueType)
        return FALSE;

    switch (_valueType) {
        case pointType:
            if (memcmp(&v.pointValue, &otherValue->v.pointValue, sizeof(CGPoint)) != 0) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;

        case sizeType:
            if (memcmp(&v.sizeValue, &otherValue->v.sizeValue, sizeof(CGSize)) != 0) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;

        case rectType:
            if (memcmp(&v.rectValue, &otherValue->v.rectValue, sizeof(CGRect)) != 0) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;

        case transformType:
            if (memcmp(&v.transformValue, &otherValue->v.transformValue, sizeof(CATransform3D)) != 0) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;

        case affineTransformType:
            if (memcmp(&v.affineTransformValue, &otherValue->v.affineTransformValue, sizeof(CGAffineTransform)) != 0) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;

        case pointerType:
            return v.pointerValue == otherValue->v.pointerValue;

        case objcType:
            if (v.genericValue.size == otherValue->v.genericValue.size) {
                if (memcmp(v.genericValue.copy, otherValue->v.genericValue.copy, v.genericValue.size) == 0) {
                    return TRUE;
                }
            }
            return FALSE;

        case nonRetainedObjectType:
            return v.pointerValue == otherValue->v.pointerValue;

        default:
            assert(0);
    }

    return FALSE;
}

static unsigned hashBytes(void* bytes, int len) {
    unsigned ret = 0;
    char* cur = (char*)bytes;

    while (len--) {
        ret = (ret << 8) | (ret >> 24);
        ret ^= *cur;
        cur++;
    }

    return ret;
}

- (unsigned)hash {
    switch (_valueType) {
        case pointType:
            return hashBytes(&v.pointValue, sizeof(CGPoint));

        case sizeType:
            return hashBytes(&v.sizeValue, sizeof(CGSize));

        case rectType:
            return hashBytes(&v.rectValue, sizeof(CGRect));

        case transformType:
            return hashBytes(&v.transformValue, sizeof(CATransform3D));

        case affineTransformType:
            return hashBytes(&v.affineTransformValue, sizeof(CGAffineTransform));

        case pointerType:
        case nonRetainedObjectType:
            return (unsigned)v.pointerValue;

        case objcType:
            return hashBytes(v.genericValue.copy, v.genericValue.size);

        default:
            assert(0);
    }

    return 0;
}

- (NSObject*)copyWithZone:(NSZone*)zone {
    NSValue* ret = [NSValue alloc];
    ret->_valueType = _valueType;
    ret->v = v;

    return ret;
}

- (NSString*)description {
    char szDescription[1024];
    switch (_valueType) {
        case pointType:
            sprintf(szDescription, "{%f, %f}", v.pointValue.x, v.pointValue.y);
            return [NSString stringWithCString:szDescription];

        case sizeType:
            sprintf(szDescription, "{%f, %f}", v.sizeValue.width, v.sizeValue.height);
            return [NSString stringWithCString:szDescription];

        case rectType:
            sprintf(szDescription,
                    "{%f, %f} {%f, %f}}",
                    v.rectValue.origin.x,
                    v.rectValue.origin.y,
                    v.rectValue.size.width,
                    v.rectValue.size.height);
            return [NSString stringWithCString:szDescription];

        case transformType:
            sprintf(szDescription,
                    "{%f, %f %f, %f}, {%f, %f %f, %f}, {%f, %f %f, %f}, {%f, %f %f, %f}}",
                    v.transformValue.m11,
                    v.transformValue.m12,
                    v.transformValue.m13,
                    v.transformValue.m14,
                    v.transformValue.m21,
                    v.transformValue.m22,
                    v.transformValue.m23,
                    v.transformValue.m24,
                    v.transformValue.m31,
                    v.transformValue.m32,
                    v.transformValue.m33,
                    v.transformValue.m34,
                    v.transformValue.m41,
                    v.transformValue.m42,
                    v.transformValue.m43,
                    v.transformValue.m44);

            return [NSString stringWithCString:szDescription];

        default:
            assert(0);
    }

    return nil;
}

- (const char*)objCType {
    char* ret = NULL;

    switch (_valueType) {
        case pointType:
            ret = "{CGPoint=ff}";
            break;

        case objcType:
            ret = v.genericValue.pType;
            break;

        default:
            assert(0);
    }

    return ret;
}

- (void)dealloc {
    switch (_valueType) {
        case objcType:
            free(v.genericValue.copy);
            if (v.genericValue.pType) {
                free(v.genericValue.pType);
            }
            break;
    }
    [super dealloc];
}
@end
