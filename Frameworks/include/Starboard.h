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

#ifndef __STARBOARD_H
#define __STARBOARD_H

// Interface should not be defined for Objective-C code
#ifdef interface
#undef interface
#endif

#ifndef IWPLATFORM_EXPORT
#define IWPLATFORM_EXPORT
#endif

#include "ErrorHandling.h"

extern "C" void dbg_printf(const char* fmt, ...);
#define EbrDebugLog(...) dbg_printf(__VA_ARGS__)
#define fatal_printf(...)
#define EbrShutdownAV()
#define idp(protocol) id<protocol>

// Placeholder for unimplemented logging and telemetry
#define UNIMPLEMENTED() \
    dbg_printf("*******Stub %s not implemented at %s:%d*******\r\n", __FUNCTION__, __FILE__, __LINE__);

#include <assert.h>
#include <stdio.h>
#ifdef __OBJC__
#include "UIKit/UIKit.h"
@class UIAppearanceSetter, UIRuntimeEventConnection;

static inline id m_assert(const char* file, int line) {
    printf("_m sent @ %s:%d\n", file, line);
    return nil;
}
static inline float m_assert_float() {
    printf("_m sent @ %s:%d\n", __FILE__, __LINE__);
    return nil;
}
#else
static inline unsigned int m_assert(const char* file, int line) {
    printf("_m sent @ %s:%d\n", file, line);
    return 0;
}
static inline float m_assert_float() {
    printf("_m sent @ %s:%d\n", __FILE__, __LINE__);
    return 0;
}
#endif
#define _m(...) m_assert(__FILE__, __LINE__)
#define _m_float(...) m_assert_float()
#define logPerf(...)

#ifdef __OBJC__
static const float kPi = 3.14159265358979323846f;
static const double kPi_d = 3.14159265358979323846;

#define IS_NEAR(val, comp, amt) (fabs((val) - (comp)) <= (amt))

class IWLazyClassLookup {
private:
    id _clsRef;
    const char* _clsName;

public:
    IWLazyClassLookup(const char* name) {
        _clsName = name;
    }

    operator id() {
        if (_clsRef == nil) {
            _clsRef = objc_getClass(_clsName);
            if (_clsRef == nil) {
                EbrDebugLog("Couldn't lazy lookup objc class %s\n", _clsName);
                assert(_clsRef);
            }
        }

        return _clsRef;
    }
};

template <typename T>
class IWLazyIvarLookup {
private:
    IWLazyClassLookup& _cls;
    const char* _ivarName;
    ptrdiff_t _offset;
    bool _initialized;

    ptrdiff_t offset(const void* obj) {
        if (!_initialized) {
            Ivar var = class_getInstanceVariable(_cls, _ivarName);
            if (!var) {
                EbrDebugLog("Couldn't lazy lookup offset of ivar %s\n", _ivarName);
                assert(var);
            }
            _offset = ivar_getOffset(var);
            _initialized = true;
        }

        return _offset;
    }

public:
    IWLazyIvarLookup(IWLazyClassLookup& cls, const char* name) : _cls(cls), _ivarName(name), _initialized(false), _offset(0) {
    }

    T& member(const void* obj) {
        void* ret = (((uint8_t*)obj) + offset(obj));

        return *((T*)ret);
    }
};
#else
typedef void* id;
#endif

#include "CACompositor.h"

typedef unsigned int EbrLock;

#define EBRLOCK_INITIALIZE 0xFAADEEEE
#define EBRLOCK_INITIALIZING 0xFAAAEEEE

IWPLATFORM_EXPORT void EbrLockInit(EbrLock* pLock);
IWPLATFORM_EXPORT void EbrLockDestroy(EbrLock pLock);
IWPLATFORM_EXPORT void EbrLockEnter(EbrLock& pLock);
IWPLATFORM_EXPORT bool EbrLockTryEnter(EbrLock& pLock);
IWPLATFORM_EXPORT void EbrLockLeave(EbrLock pLock);

enum surfaceFormat { _Color565, _ColorARGB, _ColorRGBA, _ColorRGB32, _ColorRGB32HE, _ColorGrayscale, _ColorRGB, _ColorA8, _ColorIndexed };

#ifdef __cplusplus
class EbrFile;
#endif

#define kGravityResize 0
#define kGravityCenter 1
#define kGravityTop 2
#define kGravityResizeAspect 3
#define kGravityTopLeft 4
#define kGravityBottomLeft 5
#define kGravityLeft 6
#define kGravityAspectFill 7
#define kGravityBottom 8
#define kGravityTopRight 9
#define kGravityRight 10
#define kGravityBottomRight 11

IWPLATFORM_EXPORT int EbrIncrement(int volatile* var);
IWPLATFORM_EXPORT int EbrDecrement(int volatile* var);
IWPLATFORM_EXPORT int EbrCompareExchange(int volatile* Destination, int Exchange, int Comperand);
IWPLATFORM_EXPORT void EbrSleep(__int64 nanoseconds);

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

enum EbrInputEventType {
    mouseDown = 0x01,
    mouseUp = 0x06,
    mouseMove = 0x02,

    rbuttonDown = 0x08,
    rbuttonUp = 0x09,

    keyPressed = 0x500
};

struct EbrInputEvent {
    int type;
    int subtype;
    int mouseEvent;
    float x, y;
    short int fingerCount;
    char numPoints;
    float velocityX, velocityY;
    double touchTime;
};

#ifdef __cplusplus
template <class T>
class EbrComPtr {
public:
    T* _val;

    EbrComPtr() {
        _val = NULL;
    }

    T* Get() {
        return _val;
    }

    T** ReleaseAndGetAddressOf() {
        Release();
        return &_val;
    }

    T** GetAddressOf() {
        return &_val;
    }

    void Release() {
        if (_val)
            _val->Release();
        _val = NULL;
    }

    template <typename U>
    unsigned int As(EbrComPtr<U>* p) const {
        return (unsigned int)_val->QueryInterface(__uuidof(U), (void**)p);
    }

    T* operator->() {
        return _val;
    }

    operator T*() {
        return _val;
    }

    EbrComPtr<T>& operator=(T* val) {
        if (val)
            val->AddRef();
        if (_val)
            _val->Release();

        _val = val;

        return *this;
    }
};
#endif

#define EbrMalloc malloc
#define EbrRealloc realloc
#define EbrFree free
#define EbrCalloc calloc
#define idt(type) type*

#ifdef __OBJC__
extern "C" BOOL object_isMethodFromClass(id dwObj, SEL pSel, const char* fromClass);
bool isOSTarget(NSString* versionStr);
#endif

typedef unsigned __int64 uint64_t;
typedef __int64 int64_t;
typedef unsigned long DWORD;
typedef void* HANDLE;
typedef unsigned char BYTE;
typedef unsigned short WORD;

#define USE_GLES2 1
#define U_STATIC_IMPLEMENTATION 1

#include "Platform/EbrPlatform.h"

struct CAPoint3D {
    float x, y, z;

    CAPoint3D() {
        x = 0;
        y = 0;
        z = 0;
    }

    CAPoint3D(const CAPoint3D& copy) {
        x = copy.x;
        y = copy.y;
        z = copy.z;
    }

    CAPoint3D(float init_x, float init_y, float init_z) {
        x = init_x;
        y = init_y;
        z = init_z;
    }

    CAPoint3D operator+(const CAPoint3D& v) const {
        return CAPoint3D(x + v.x, y + v.y, z + v.z);
    }

    CAPoint3D operator-(const CAPoint3D& v) const {
        return CAPoint3D(x - v.x, y - v.y, z - v.z);
    }

    float dot(const CAPoint3D& p2) const {
        return (x * p2.x) + (y * p2.y) + (z * p2.z);
    }
};

inline CAPoint3D operator*(const CAPoint3D& v, float f) {
    return CAPoint3D(v.x * f, v.y * f, v.z * f);
}

inline CAPoint3D operator*(float f, const CAPoint3D& v) {
    return CAPoint3D(v.x * f, v.y * f, v.z * f);
}

// These should eventually go:
// Being private for now is ok but not a great solution...

#ifdef __cplusplus
template <typename objtype>
class idretaint {
public:
    objtype* _val;

    idretaint() {
        _val = nil;
    }

    idretaint(id val) {
        _val = [val retain];
    }

    idretaint(const idretaint<objtype>& other) {
        _val = [other._val retain];
    }

    idretaint(idretaint<objtype>&& other) {
        _val = other._val;
        other._val = nil;
    }

    ~idretaint() {
        [_val release];
        _val = nil;
    }

    operator objtype*() {
        return _val;
    }

    operator const objtype*() const {
        return _val;
    }

    explicit operator bool() const {
        return _val != nil;
    }

    // attach assumes ownership of an already-owned object.
    void attach(id val) {
        id newVal = val;
        [_val release];
        _val = newVal;
    }

    idretaint<objtype>& operator=(id val) {
        if (_val == val)
            return *this;

        attach([val retain]);
        return *this;
    }

    idretaint<objtype>& operator=(const idretaint<objtype>& val) {
        return *this = val._val;
    }

    idretaint<objtype>& operator=(idretaint<objtype>&& other) {
        attach(other._val);
        other._val = nil;
        return *this;
    }

    template <typename K>
    bool operator!=(const K& other) const {
        return ((id)other) != (id)_val;
    }

    template <typename K>
    bool operator==(const K& other) const {
        return ((id)other) == (id)_val;
    }

    objtype* operator->() {
        return _val;
    }
};

template <typename objtype>
class idretainp {
public:
    objtype _val;

    idretainp() {
        _val = nil;
    }

    idretainp(id val) {
        _val = [val retain];
    }

    idretainp(const idretainp<objtype>&) = delete;

    ~idretainp() {
        [_val release];
        _val = nil;
    }

    operator objtype() {
        return _val;
    }

    operator const objtype() const {
        return _val;
    }

    void attach(id val) {
        id newVal = val;
        [_val release];
        _val = newVal;
    }

    idretainp<objtype>& operator=(id val) {
        if (_val == static_cast<__unsafe_unretained objtype>(val))
            return *this;

        id newVal = [val retain];
        [_val release];
        _val = newVal;

        return *this;
    }

    template <typename K>
    bool operator!=(const K& other) {
        return ((id)other) != (id)_val;
    }

    template <typename K>
    bool operator==(const K& other) {
        return ((id)other) == (id)_val;
    }

    template <typename... Args>
    auto operator()(Args... args) -> decltype(_val(args...)) {
        return _val(std::forward<Args>(args)...);
    }
};

template <typename K, typename T>
bool operator==(const K other, idretaint<T>& val) {
    return other == (id)val._val;
}

#ifdef __OBJC__
typedef idretaint<NSObject> idretain;
#endif

template <typename objtype>
class idtype {
public:
    objtype* _val;

    idtype() : _val(0) {
    }

    idtype(id val) {
        _val = val;
    }

    ~idtype() {
        _val = nil;
    }

    operator objtype*() {
        return _val;
    }

    idtype<objtype>& operator=(id val) {
        if (_val == val)
            return *this;

        _val = val;

        return *this;
    }

    objtype* operator->() {
        return _val;
    }
};

#define idretaintype(type) idretaint<type>
#define idretainproto(type) idretainp<id<type>>
#else
#define idretain __unsafe_unretained id
#define idretaintype(type) __unsafe_unretained id
#define idretainproto(type) id<type>
#endif

#endif // __STARBOARD_H
