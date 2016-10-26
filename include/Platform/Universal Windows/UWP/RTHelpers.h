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

#pragma once

#include <COMIncludes.h>
#include <windows.foundation.h>
#include <windows.foundation.collections.h>
#include <wrl/client.h>
#include <wrl/event.h>
#include <wrl/implements.h>
#include <wrl/wrappers/corewrappers.h>
#include <comutil.h>
#include <COMIncludes_End.h>

#include <stdint.h>
#include <utility>
#include <string>
#include <vector>
#include <type_traits>
#include <memory>

#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFString.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSNumber.h>

#include "Starboard.h"
#include <UWP/interopBase.h>

#if __has_feature(objc_arc)
#define AUTORELEASE(x)
#define RETAIN(x)
#define RELEASE(x)
#else
#define AUTORELEASE(x) [x autorelease]
#define RETAIN(x) [x retain]
#define RELEASE(x) [x release]
#endif

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::Foundation;

// Forward declaration to allow all adapter template definitions to stay together.
@class RTProxiedNSDictionaryKeyEnumerator;
@class RTProxiedObservableNSMutableArray;
@class RTProxiedObservableNSMutableDictionary;

#define _is_COM_Object(T)                                                     \
    (std::is_same<HSTRING, T>::value == false && std::is_pointer<T>::value && \
     std::is_class<typename std::remove_pointer<T>::type>::value &&           \
     std::is_base_of<IUnknown, typename std::remove_pointer<T>::type>::value)

// Dummy ObjC creator function.
// A place holder in the templated ToObjCConvertor function for basic types.
inline id dummyObjCCreator(IInspectable* obj) {
    assert(0);
    return nil;
}

// Dummy WRL convertor function
// A place holder in the templated ToWRLConvertor function for basic types.
inline ComPtr<IInspectable> dummyWRLCreator(id obj) {
    assert(0);
    return nullptr;
}

typedef id (*OBJCT_CreatorT)(IInspectable*);
typedef ComPtr<IInspectable> (*WRLT_CreatorT)(id);

#define LOGTYPE(T) typename ABI::Windows::Foundation::Internal::GetLogicalType<T>::type
#define ABITYPE(T) typename ABI::Windows::Foundation::Internal::GetAbiType<T>::type

#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))

@interface RTObject ()

// This is an internal utility used to do a dynamic_cast:
+ (instancetype)createWith:(IInspectable*)obj;
@end

struct ArrayAdapter {
#if defined(__cplusplus)
    virtual ComPtr<IInspectable> getInternalComObj() {
        return nullptr;
    };
#endif
    virtual NSUInteger count() = 0;
    virtual id objectAtIndex(NSUInteger index) = 0;
    virtual bool isCArray() = 0;
    virtual void* ptr() const = 0;
    virtual ~ArrayAdapter(){};
};

struct CArrayAdapter : ArrayAdapter {
    virtual void setCount(unsigned int size) = 0;
    virtual void setContainer(void* vec) = 0;
    virtual void setOwned(bool owned) = 0;
    virtual ~CArrayAdapter(){};
};

struct IterableArrayAdapter : ArrayAdapter {
    virtual id first() = 0;
    virtual id next() = 0;
    virtual ~IterableArrayAdapter(){};
};

struct MutableArrayAdapter : ArrayAdapter {
    virtual void appendObject(id obj) = 0;
    virtual void insertObjectAtIndex(id obj, unsigned int index) = 0;
    virtual void removeObjectAtIndex(NSUInteger index) = 0;
    virtual void replaceObjectAtIndexWithObject(NSUInteger index, id obj) = 0;
    virtual ~MutableArrayAdapter(){};
};

struct ObservableArrayAdapter : MutableArrayAdapter {
    virtual void registerSelf(RTProxiedObservableNSMutableArray* obj) = 0;
    virtual void unregisterSelf() = 0;
    virtual ~ObservableArrayAdapter(){};
};

template <typename WRLT, typename BaseTypeT>
struct CArrayAdapterObj : CArrayAdapter {
    BaseTypeT implObj;

    CArrayAdapterObj(unsigned int size, void* vec) {
        implObj._count = size;
        implObj._array = (WRLT*)vec;
        implObj._owned = true;
    }

    void setCount(unsigned int size) {
        implObj._count = size;
    }

    void setContainer(void* vec) {
        implObj._array = (WRLT*)vec;
    }

    void setOwned(bool owned) {
        implObj._owned = owned;
    }

    NSUInteger count() {
        return implObj.count(nullptr);
    }

    id objectAtIndex(NSUInteger index) {
        return implObj.get(nullptr, index);
    }

    bool isCArray() {
        return implObj.isCArray();
    };

    void* ptr() const {
        return implObj.ptr();
    }
};

template <typename WRLContainerT, typename BaseTypeT>
struct ArrayAdapterObj : ArrayAdapter {
    BaseTypeT implObj;
    ComPtr<IInspectable> comObj;

#if defined(__cplusplus)
    ComPtr<IInspectable> getInternalComObj() {
        return comObj;
    }
#endif

    ArrayAdapterObj(IInspectable* container) {
        comObj = container;
    }

    NSUInteger count() {
        return implObj.count(comObj);
    }

    id objectAtIndex(NSUInteger index) {
        return implObj.get(comObj, index);
    }

    bool isCArray() {
        return implObj.isCArray();
    };

    void* ptr() const {
        return implObj.ptr();
    }
};

template <typename WRLContainerT, typename BaseTypeT>
struct MutableArrayAdapterObj : MutableArrayAdapter {
    BaseTypeT implObj;
    ComPtr<IInspectable> comObj;

#if defined(__cplusplus)
    ComPtr<IInspectable> getInternalComObj() {
        return comObj;
    }
#endif

    MutableArrayAdapterObj(IInspectable* container) {
        comObj = container;
    }

    NSUInteger count() {
        return implObj.count(comObj);
    }

    id objectAtIndex(NSUInteger index) {
        return implObj.get(comObj, index);
    }

    bool isCArray() {
        return implObj.isCArray();
    };

    void* ptr() const {
        return implObj.ptr();
    }

    void appendObject(id obj) {
        implObj.append(comObj, obj);
    }

    void insertObjectAtIndex(id obj, unsigned int index) {
        implObj.insert(comObj, obj, index);
    }

    void removeObjectAtIndex(NSUInteger index) {
        implObj.erase(comObj, index);
    }

    void replaceObjectAtIndexWithObject(NSUInteger index, id obj) {
        implObj.set(comObj, obj, index);
    }
};

template <typename WRLContainerT, typename BaseTypeT>
struct IterableArrayAdapterObj : IterableArrayAdapter {
    BaseTypeT implObj;
    ComPtr<IInspectable> comObj;

#if defined(__cplusplus)
    ComPtr<IInspectable> getInternalComObj() {
        return comObj;
    }
#endif

    IterableArrayAdapterObj(IInspectable* container) {
        comObj = container;
    }

    NSUInteger count() {
        return implObj.count(comObj);
    }

    id objectAtIndex(NSUInteger index) {
        return implObj.get(comObj, index);
    }

    bool isCArray() {
        return implObj.isCArray();
    };

    void* ptr() const {
        return implObj.ptr();
    }

    id first() {
        return implObj.first(comObj);
    }

    id next() {
        return implObj.next(comObj);
    }
};

template <typename WRLContainerT, typename BaseTypeT>
struct ObservableArrayAdapterObj : ObservableArrayAdapter {
    BaseTypeT implObj;
    ComPtr<IInspectable> comObj;

#if defined(__cplusplus)
    ComPtr<IInspectable> getInternalComObj() {
        return comObj;
    }
#endif

    ObservableArrayAdapterObj(IInspectable* container) {
        comObj = container;
    }

    NSUInteger count() {
        return implObj.count(comObj);
    }

    id objectAtIndex(NSUInteger index) {
        return implObj.get(comObj, index);
    }

    bool isCArray() {
        return implObj.isCArray();
    };

    void* ptr() const {
        return implObj.ptr();
    }

    void insertObjectAtIndex(id obj, unsigned int index) {
        implObj.insert(comObj, obj, index);
    }

    void removeObjectAtIndex(NSUInteger index) {
        implObj.erase(comObj, index);
    }

    void appendObject(id obj) {
        implObj.append(comObj, obj);
    }

    void replaceObjectAtIndexWithObject(NSUInteger index, id obj) {
        implObj.set(comObj, obj, index);
    }

    void registerSelf(RTProxiedObservableNSMutableArray* obj) {
        implObj.registerSelf(comObj, obj);
    }

    void unregisterSelf() {
        implObj.unregisterSelf(comObj);
    }
};

struct DictionaryKeyEnumeratorAdapter {
    virtual void initWithMap(IInspectable* map) = 0;
    virtual id nextObject() = 0;
    virtual ~DictionaryKeyEnumeratorAdapter(){};
};

template <typename BaseTypeT>
struct DictionaryKeyEnumeratorAdapterObj : DictionaryKeyEnumeratorAdapter {
    BaseTypeT implObj;

    void initWithMap(IInspectable* map) {
        implObj.initWith(map);
    }

    id nextObject() {
        return implObj.nextObject();
    }
};

struct DictionaryAdapter {
#if defined(__cplusplus)
    virtual ComPtr<IInspectable> getInternalComObj() {
        return nullptr;
    };
#endif
    virtual id objectForKey(id key) = 0;
    virtual id keyEnumerator() = 0;
    virtual unsigned int count() = 0;
    virtual NSArray* allKeys() = 0;
    virtual NSArray* allKeysForObject(id obj) = 0;
    virtual NSArray* allValues() = 0;
    virtual ~DictionaryAdapter(){};
};

struct MutableDictionaryAdapter : DictionaryAdapter {
    virtual void setObject(id obj, id key) = 0;
    virtual void removeObjectForKey(id key) = 0;
    virtual void removeAllObjects() = 0;
    virtual void removeObjectsForKeys(NSArray* keys) = 0;
    virtual void addEntriesFromDictionary(NSDictionary* otherDict) = 0;
    virtual void addEntriesFromDictionaryNoReplace(NSDictionary* otherDict) = 0;
    virtual void setDictionary(NSDictionary* otherDict) = 0;
    virtual ~MutableDictionaryAdapter(){};
};

struct ObservableDictionaryAdapter : MutableDictionaryAdapter {
    virtual void registerSelf(RTProxiedObservableNSMutableDictionary* obj) = 0;
    virtual void unregisterSelf() = 0;
    virtual ~ObservableDictionaryAdapter(){};
};

template <typename WRLContainerT, typename KeyEnumeratorAdapterTypeT, typename BaseTypeT>
struct DictionaryAdapterObj : DictionaryAdapter {
    BaseTypeT implObj;
    ComPtr<IInspectable> comObj;
    RTProxiedNSDictionaryKeyEnumerator* indirectKeyEnumerator;

#if defined(__cplusplus)
    ComPtr<IInspectable> getInternalComObj() {
        return comObj;
    }
#endif

    DictionaryAdapterObj(IInspectable* container) {
        comObj = container;
        indirectKeyEnumerator =
            [[RTProxiedNSDictionaryKeyEnumerator alloc] initWithMap:comObj.Get()
                                                            adapter:std::move(std::make_unique<KeyEnumeratorAdapterTypeT>())];
    }

    id objectForKey(id key) {
        return implObj.get(comObj, key);
    }

    id keyEnumerator() {
        return AUTORELEASE(RETAIN(indirectKeyEnumerator));
    }

    unsigned int count() {
        return implObj.count(comObj);
    }

    NSArray* allKeys() {
        return implObj.allKeys(comObj);
    }

    NSArray* allKeysForObject(id obj) {
        return implObj.allKeysFor(comObj, obj);
    }

    NSArray* allValues() {
        return implObj.allValues(comObj);
    }

    ~DictionaryAdapterObj() {
        RELEASE(indirectKeyEnumerator);
    }
};

template <typename WRLContainerT, typename KeyEnumeratorAdapterTypeT, typename BaseTypeT>
struct MutableDictionaryAdapterObj : MutableDictionaryAdapter {
    BaseTypeT implObj;
    ComPtr<IInspectable> comObj;
    RTProxiedNSDictionaryKeyEnumerator* indirectKeyEnumerator;

#if defined(__cplusplus)
    ComPtr<IInspectable> getInternalComObj() {
        return comObj;
    }
#endif

    MutableDictionaryAdapterObj(IInspectable* container) {
        comObj = container;
        indirectKeyEnumerator =
            [[RTProxiedNSDictionaryKeyEnumerator alloc] initWithMap:comObj.Get()
                                                            adapter:std::move(std::make_unique<KeyEnumeratorAdapterTypeT>())];
    }

    id objectForKey(id key) {
        return implObj.get(comObj, key);
    }

    id keyEnumerator() {
        return AUTORELEASE(RETAIN(indirectKeyEnumerator));
    }

    unsigned int count() {
        return implObj.count(comObj);
    }

    NSArray* allKeys() {
        return implObj.allKeys(comObj);
    }

    NSArray* allKeysForObject(id obj) {
        return implObj.allKeysFor(comObj, obj);
    }

    NSArray* allValues() {
        return implObj.allValues(comObj);
    }

    void setObject(id obj, id key) {
        implObj.set(comObj, key, obj);
    }

    void removeObjectForKey(id key) {
        implObj.remove(comObj, key);
    }

    void removeAllObjects() {
        implObj.clear(comObj);
    }

    void removeObjectsForKeys(NSArray* keys) {
        implObj.removeObjs(comObj, keys);
    }

    void addEntriesFromDictionary(NSDictionary* otherDict) {
        implObj.addAll(comObj, otherDict);
    }

    void addEntriesFromDictionaryNoReplace(NSDictionary* otherDict) {
        implObj.addNew(comObj, otherDict);
    }

    void setDictionary(NSDictionary* otherDict) {
        implObj.clear(comObj);
        implObj.addAll(comObj, otherDict);
    }

    ~MutableDictionaryAdapterObj() {
        RELEASE(indirectKeyEnumerator);
    }
};

template <typename WRLContainerT, typename KeyEnumeratorAdapterTypeT, typename BaseTypeT>
struct ObservableDictionaryAdapterObj : ObservableDictionaryAdapter {
    BaseTypeT implObj;
    ComPtr<IInspectable> comObj;
    RTProxiedNSDictionaryKeyEnumerator* indirectKeyEnumerator;

#if defined(__cplusplus)
    ComPtr<IInspectable> getInternalComObj() {
        return comObj;
    }
#endif

    ObservableDictionaryAdapterObj(IInspectable* container) {
        comObj = container;
        indirectKeyEnumerator =
            [[RTProxiedNSDictionaryKeyEnumerator alloc] initWithMap:comObj.Get()
                                                            adapter:std::move(std::make_unique<KeyEnumeratorAdapterTypeT>())];
    }

    id objectForKey(id key) {
        return implObj.get(comObj, key);
    }

    id keyEnumerator() {
        return AUTORELEASE(RETAIN(indirectKeyEnumerator));
    }

    unsigned int count() {
        return implObj.count(comObj);
    }

    NSArray* allKeys() {
        return implObj.allKeys(comObj);
    }

    NSArray* allKeysForObject(id obj) {
        return implObj.allKeysFor(comObj, obj);
    }

    NSArray* allValues() {
        return implObj.allValues(comObj);
    }

    void setObject(id obj, id key) {
        implObj.set(comObj, key, obj);
    }

    void removeObjectForKey(id key) {
        implObj.remove(comObj, key);
    }

    void removeAllObjects() {
        implObj.clear(comObj);
    }

    void removeObjectsForKeys(NSArray* keys) {
        implObj.removeObjs(comObj, keys);
    }

    void addEntriesFromDictionary(NSDictionary* otherDict) {
        implObj.addAll(comObj, otherDict);
    }

    void addEntriesFromDictionaryNoReplace(NSDictionary* otherDict) {
        implObj.addNew(comObj, otherDict);
    }

    void setDictionary(NSDictionary* otherDict) {
        implObj.clear(comObj);
        implObj.addAll(comObj, otherDict);
    }

    void registerSelf(RTProxiedObservableNSMutableDictionary* obj) {
        implObj.registerSelf(comObj, obj);
    }

    void unregisterSelf() {
        implObj.unregisterSelf(comObj);
    }

    ~ObservableDictionaryAdapterObj() {
        RELEASE(indirectKeyEnumerator);
    }
};

struct KeyValuePairAdapter {
    virtual id key(ComPtr<IInspectable> comObj) = 0;
    virtual id value(ComPtr<IInspectable> comObj) = 0;
    virtual ~KeyValuePairAdapter(){};
};

template <typename BaseTypeT>
struct KeyValuePairAdapterObj : KeyValuePairAdapter {
    BaseTypeT implObj;

    id key(ComPtr<IInspectable> comObj) {
        return implObj.getKey(comObj);
    }

    id value(ComPtr<IInspectable> comObj) {
        return implObj.getValue(comObj);
    }
};

WINRT_EXPORT
@interface RTProxiedKeyValuePair : RTKeyValuePair {
    std::unique_ptr<KeyValuePairAdapter> adapter;
}

- (void)setAdapter:(std::unique_ptr<KeyValuePairAdapter>)keyValuePairAdapter;
- (id)key;
- (id)value;
@end

WINRT_EXPORT
@interface RTProxiedNSMutableDictionary : NSMutableDictionary {
    std::unique_ptr<MutableDictionaryAdapter> adapter;
}

#if defined(__cplusplus)
- (ComPtr<IInspectable>)getInternalComObj;
#endif
- (instancetype)initWithAdapter:(std::unique_ptr<MutableDictionaryAdapter>)dictionaryAdapter;
- (id)objectForKey:(id)key;
- (id)keyEnumerator;
- (unsigned int)count;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (void)setObject:(id)obj forKey:(id)key;
- (void)setObject:(id)obj forKeyedSubscript:(id)key;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keys;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDict;
- (void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
- (void)setDictionary:(NSDictionary*)otherDict;
@end

WINRT_EXPORT
@interface RTProxiedObservableNSMutableDictionary : NSMutableDictionary <RTObservableCollection> {
    std::unique_ptr<ObservableDictionaryAdapter> adapter;
}

#if defined(__cplusplus)
- (ComPtr<IInspectable>)getInternalComObj;
#endif
- (instancetype)initWithAdapter:(std::unique_ptr<ObservableDictionaryAdapter>)dictionaryAdapter;
- (id)objectForKey:(id)key;
- (id)keyEnumerator;
- (unsigned int)count;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (void)setObject:(id)obj forKey:(id)key;
- (void)setObject:(id)obj forKeyedSubscript:(id)key;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keys;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDict;
- (void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
- (void)setDictionary:(NSDictionary*)otherDict;
- (EventRegistrationToken)addObserver:(RTCollectionListener)receiver;
- (void)removeObserver:(EventRegistrationToken)receiverToken;
- (void)notify:(RTCollectionOperation)op atKey:(id)key;
@end

WINRT_EXPORT
@interface RTProxiedNSDictionary : NSDictionary {
    std::unique_ptr<DictionaryAdapter> adapter;
}

#if defined(__cplusplus)
- (ComPtr<IInspectable>)getInternalComObj;
#endif
- (instancetype)initWithAdapter:(std::unique_ptr<DictionaryAdapter>)dictionaryAdapter;
- (id)objectForKey:(id)key;
- (id)keyEnumerator;
- (unsigned int)count;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
@end

WINRT_EXPORT
@interface RTProxiedNSDictionaryKeyEnumerator : NSEnumerator {
    std::unique_ptr<DictionaryKeyEnumeratorAdapter> adapter;
}

- (id)initWithMap:(IInspectable*)map adapter:(std::unique_ptr<DictionaryKeyEnumeratorAdapter>)adapter;
- (id)nextObject;
@end

WINRT_EXPORT
@interface RTProxiedNSArray : NSArray {
    std::unique_ptr<ArrayAdapter> adapter;
}
#if defined(__cplusplus)
- (ComPtr<IInspectable>)getInternalComObj;
#endif
- (instancetype)initWithAdapter:(std::unique_ptr<ArrayAdapter>)arrayAdapter;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (BOOL)isCArray;
- (void*)ptr;
@end

WINRT_EXPORT
@interface RTProxiedNSArrayFull : RTProxiedNSArray
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;
@end

WINRT_EXPORT
@interface RTProxiedNSMutableArray : NSMutableArray {
    std::unique_ptr<MutableArrayAdapter> adapter;
}

#if defined(__cplusplus)
- (ComPtr<IInspectable>)getInternalComObj;
#endif
- (instancetype)initWithAdapter:(std::unique_ptr<MutableArrayAdapter>)arrayAdapter;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (BOOL)isCArray;
- (void*)ptr;
- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)addObject:(id)anObject;
- (void)removeLastObject;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
@end

WINRT_EXPORT
@interface RTProxiedObservableNSMutableArray : NSMutableArray <RTObservableCollection> {
    std::unique_ptr<ObservableArrayAdapter> adapter;
}

#if defined(__cplusplus)
- (ComPtr<IInspectable>)getInternalComObj;
#endif
- (instancetype)initWithAdapter:(std::unique_ptr<ObservableArrayAdapter>)arrayAdapter;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (BOOL)isCArray;
- (void*)ptr;
- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)addObject:(id)anObject;
- (void)removeLastObject;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (EventRegistrationToken)addObserver:(RTCollectionListener)receiver;
- (void)removeObserver:(EventRegistrationToken)receiverToken;
- (void)notify:(RTCollectionOperation)op at:(unsigned int)idx;
@end

WINRT_EXPORT
@interface RTProxiedNSMutableArrayFull : RTProxiedNSMutableArray
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;
@end

WINRT_EXPORT
@interface RTProxiedIterableNSArray : NSArray {
    std::unique_ptr<IterableArrayAdapter> adapter;
}

#if defined(__cplusplus)
- (ComPtr<IInspectable>)getInternalComObj;
#endif
- (instancetype)initWithAdapter:(std::unique_ptr<IterableArrayAdapter>)arrayAdapter;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (BOOL)isCArray;
- (void*)ptr;
- (id)first;
- (id)next;
@end

WINRT_EXPORT
@interface RTProxiedIterableNSArrayFull : RTProxiedIterableNSArray
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;
@end

template <typename I>
inline ComPtr<I> _getRtInterface(RTObject* o) {
    ComPtr<I> ret = nullptr;
    if (o) {
        THROW_NS_IF_FAILED(o.comObj.As(&ret));
    }
    return ret;
}

template <typename I>
inline ComPtr<I> _getInnerInterface(RTObject* o) {
    if ([o innerInterface] == nil)
        return _getRtInterface<I>(o);

    ComPtr<I> ret;
    THROW_NS_IF_FAILED([o innerInterface].As(&ret));
    return ret;
}

inline id _createRtProxy(Class cls, IInspectable* iface) {
    // Oddly, WinRT can hand us back NULL objects from successful function calls. Plumb these through as nil.
    if (!iface) {
        return nil;
    }

    RTObject* ret = [NSAllocateObject(cls, 0, 0) init];
    [ret setComObj:iface];
    return AUTORELEASE(ret);
}

template <typename I>
inline I* _createRtProxy(IInspectable* iface) {
    return _createRtProxy([I class], iface);
}

template <typename ClassTypeT, typename AdapterTypeT>
inline ClassTypeT* _createRtProxyWithAdapter(IInspectable* iface, std::unique_ptr<AdapterTypeT> adapter) {
    ClassTypeT* ret = (ClassTypeT*)_createRtProxy([ClassTypeT class], iface);
    [ret setAdapter:std::move(adapter)];
    return ret;
}

inline RTObject* _createBareRTObj(IInspectable* obj) {
    return _createRtProxy(objc_getClass("RTObject"), obj);
}

template <typename Ret, typename... Args>
ComPtr<Ret> OurMake(Args&&... args) {
    ComPtr<Ret> ret;
    ret.Attach(new Ret(std::forward<Args>(args)...));
    return ret;
}

//
// COM Helpers:
//

static std::wstring _stringFromHstring(HSTRING str) {
    if (WindowsIsStringEmpty(str))
        return std::wstring();

    unsigned len;
    auto buff = WindowsGetStringRawBuffer(str, &len);
    auto ret = std::wstring(buff, buff + len);
    WindowsDeleteString(str);
    return ret;
}

static NSString* hstrToNSStr(HSTRING str, bool free = false) {
    if (WindowsIsStringEmpty(str))
        return nil;

    unsigned len;
    auto buff = WindowsGetStringRawBuffer(str, &len);
    auto ret = [[NSString alloc] initWithBytes:buff length:len * 2 encoding:NSUnicodeStringEncoding];

    if (free)
        WindowsDeleteString(str);

    return AUTORELEASE(ret);
}

static HString nsStrToHstr(NSString* str) {
    HString ret;
    NSUInteger dataBytes = [str length];

    // Include size of the terminating '\0' character.
    std::vector<unichar> data(dataBytes + 1);

    [str getCharacters:&data[0]];

    // Add terminating NULL character.
    data[dataBytes] = L'\0';

    HRESULT hr = WindowsCreateString((LPWSTR)&data[0], dataBytes, ret.GetAddressOf());
    assert(SUCCEEDED(hr));

    return ret;
}

// For refcounting blocks captured by lambdas
template <typename Block>
struct BlockHolder {
    Block _block;
    BlockHolder& operator=(const BlockHolder<Block>&) = delete;

    BlockHolder(const BlockHolder<Block>& other) {
        _block = [other._block copy];
    }
    BlockHolder(const Block& b) {
        _block = [b copy];
    }
    ~BlockHolder() {
        RELEASE(_block);
    }

    operator bool() const {
        return _block != nil;
    }

    template <typename... Stuff>
    void operator()(Stuff... stuff) const {
        _block(std::forward<Stuff>(stuff)...);
    }
};

template <typename Block>
BlockHolder<Block> makeBlockHolder(Block b) {
    return BlockHolder<Block>(b);
}

#define GET_STR(obj, getter)              \
    _stringFromHstring([&]() -> HSTRING { \
        HSTRING o;                        \
        obj->getter(&o);                  \
        return o;                         \
    }());
#define GET_NSTR(obj, getter) \
    hstrToNSStr(              \
        [&]() -> HSTRING {    \
            HSTRING o;        \
            obj->getter(&o);  \
            return o;         \
        }(),                  \
        true);

template <typename Derived>
class RuntimeClassBase : public Derived {
public:
    virtual ~RuntimeClassBase() {
    }

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(_In_ REFIID id, _COM_Outptr_ void** ppv) override {
        if (nullptr == ppv)
            return E_POINTER;

        if (id == IID_IUnknown) {
            *ppv = this;
        } else if (id == __uuidof(Derived)) {
            *ppv = (Derived*)this;
        } else {
            *ppv = nullptr;
            return E_NOINTERFACE;
        }

        ((IUnknown*)(*ppv))->AddRef();

        return S_OK;
    }

    ULONG _ulRefs = 1;
    virtual ULONG STDMETHODCALLTYPE AddRef() override {
        return InterlockedIncrement(&_ulRefs);
    }

    virtual ULONG STDMETHODCALLTYPE Release() override {
        unsigned curr = InterlockedDecrement(&_ulRefs);
        if (curr == 0)
            delete this;

        return curr;
    }
};

// Needed for creating classes that implement IInspectable.
template <typename Derived>
class InspectableClassBase : public RuntimeClassBase<Derived> {
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(_In_ REFIID id, _COM_Outptr_ void** ppv) override {
        if (nullptr == ppv)
            return E_POINTER;

        if (id == IID_IUnknown) {
            *ppv = this;
        } else if (id == __uuidof(IInspectable)) {
            *ppv = this;
        } else if (id == __uuidof(Derived)) {
            *ppv = (Derived*)this;
        } else {
            *ppv = nullptr;
            return E_NOINTERFACE;
        }

        ((IUnknown*)(*ppv))->AddRef();

        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetIids(ULONG* iidCount, IID** iids) override {
        static IID resultIIDs[] = { IID_IUnknown, IID_IInspectable, __uuidof(Derived) };
        *iidCount = 3;
        *iids = resultIIDs;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetRuntimeClassName(HSTRING* out) override {
        return WindowsCreateString(L"InspectableClassBase", ::wcslen(L"InspectableClassBase"), out);
    }

    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
};

inline RTCollectionOperation ccToOperation(CollectionChange cc) {
    switch (cc) {
        case CollectionChange_ItemChanged:
            return COItemChanged;
        case CollectionChange_ItemInserted:
            return COItemInserted;
        case CollectionChange_ItemRemoved:
            return COItemRemoved;
        case CollectionChange_Reset:
            return COReset;
    }
    assert(!"unknown value");
    return COReset;
}

//
// Iterable helpers.
//

WINRT_EXPORT_FN
UINT32 SizeByEnumeration(id<NSFastEnumeration> obj); // slow way to get an enumeration size.

template <typename T>
inline id MakeObjCFromBasic(T val) {
    return [NSNumber numberWithUnsignedInt:(unsigned int)val];
}

template <typename T>
id _makeObjcFrom(T val) {
    static_assert(0, "type not supported!");
    return nil;
}
template <>
inline id _makeObjcFrom<bool>(bool val) {
    return [NSNumber numberWithBool:val ? TRUE : FALSE];
}
template <>
inline id _makeObjcFrom<int>(int val) {
    return [NSNumber numberWithInt:val];
}
template <>
inline id _makeObjcFrom<float>(float val) {
    return [NSNumber numberWithFloat:val];
}
template <>
inline id _makeObjcFrom<int8_t>(int8_t val) {
    return [NSNumber numberWithChar:val];
}
template <>
inline id _makeObjcFrom<uint8_t>(uint8_t val) {
    return [NSNumber numberWithUnsignedChar:val];
}
template <>
inline id _makeObjcFrom<uint16_t>(uint16_t val) {
    return [NSNumber numberWithUnsignedShort:val];
}
template <>
inline id _makeObjcFrom<WCHAR>(WCHAR val) {
    return [NSNumber numberWithUnsignedShort:val];
}
template <>
inline id _makeObjcFrom<unsigned>(unsigned val) {
    return [NSNumber numberWithUnsignedInt:val];
}
template <>
inline id _makeObjcFrom<short>(short val) {
    return [NSNumber numberWithShort:val];
}
template <>
inline id _makeObjcFrom<double>(double val) {
    return [NSNumber numberWithDouble:val];
}
template <>
inline id _makeObjcFrom<int64_t>(int64_t val) {
    return [NSNumber numberWithLongLong:val];
}
template <>
inline id _makeObjcFrom<uint64_t>(uint64_t val) {
    return [NSNumber numberWithUnsignedLongLong:val];
}
template <>
inline id _makeObjcFrom<HSTRING>(HSTRING val) {
    return hstrToNSStr(val);
}
template <>
inline id _makeObjcFrom<GUID>(GUID val) {
    return [WFGUID guidWithGUID:val];
}
template <>
inline id _makeObjcFrom<EventRegistrationToken>(EventRegistrationToken val) {
    return [NSNumber numberWithLong:val.value];
}

inline bool MakeWRLFromBoolean(NSNumber* val) {
    return val.boolValue;
}
inline unsigned char MakeWRLFromUInt8(NSNumber* val) {
    return val.unsignedCharValue;
}
inline unsigned short MakeWRLFromUInt16(NSNumber* val) {
    return val.unsignedShortValue;
}
inline unsigned short MakeWRLFromChar16(NSNumber* val) {
    return val.unsignedShortValue;
}
inline unsigned int MakeWRLFromUInt32(NSNumber* val) {
    return val.unsignedIntValue;
}
inline char MakeWRLFromInt8(NSNumber* val) {
    return val.charValue;
}
inline short MakeWRLFromInt16(NSNumber* val) {
    return val.shortValue;
}
inline int MakeWRLFromInt32(NSNumber* val) {
    return val.intValue;
}
inline float MakeWRLFromSingle(NSNumber* val) {
    return val.floatValue;
}
inline double MakeWRLFromDouble(NSNumber* val) {
    return val.doubleValue;
}
inline long MakeWRLFromInt64(NSNumber* val) {
    return val.longValue;
}
inline unsigned long MakeWRLFromUInt64(NSNumber* val) {
    return val.unsignedLongValue;
}
inline GUID MakeWRLFromGUID(WFGUID* val) {
    return val.guidValue;
}
inline HString MakeWRLFromString(NSString* val) {
    return nsStrToHstr(val);
}
inline EventRegistrationToken MakeWRLFromEventRegistrationToken(NSNumber* val) {
    return { val.longValue };
}

template <typename T>
inline T MakeWRLFromBasic(NSNumber* val) {
    return (T)val.unsignedIntValue;
}

// NOTE: these are based off the MakeWRLFrom* stuff above, we should maybe think about unifying these.
template <typename T>
inline T MakeWRLFrom(NSNumber* val) {
    static_assert(0, "type not supported!");
}
template <>
inline bool MakeWRLFrom<bool>(NSNumber* val) {
    return val.boolValue;
}
template <>
inline unsigned char MakeWRLFrom<unsigned char>(NSNumber* val) {
    return val.unsignedCharValue;
}
template <>
inline unsigned short MakeWRLFrom<unsigned short>(NSNumber* val) {
    return val.unsignedShortValue;
}
template <>
inline WCHAR MakeWRLFrom<WCHAR>(NSNumber* val) {
    return (WCHAR)val.unsignedShortValue;
}
template <>
inline unsigned int MakeWRLFrom<unsigned int>(NSNumber* val) {
    return val.unsignedIntValue;
}
template <>
inline char MakeWRLFrom<char>(NSNumber* val) {
    return val.charValue;
}
template <>
inline short MakeWRLFrom<short>(NSNumber* val) {
    return val.shortValue;
}
template <>
inline int MakeWRLFrom<int>(NSNumber* val) {
    return val.intValue;
}
template <>
inline float MakeWRLFrom<float>(NSNumber* val) {
    return val.floatValue;
}
template <>
inline double MakeWRLFrom<double>(NSNumber* val) {
    return val.doubleValue;
}
template <>
inline long MakeWRLFrom<long>(NSNumber* val) {
    return val.longValue;
}
template <>
inline unsigned long MakeWRLFrom<unsigned long>(NSNumber* val) {
    return val.unsignedLongValue;
}
template <>
inline int64_t MakeWRLFrom<int64_t>(NSNumber* val) {
    return val.longLongValue;
}
template <>
inline uint64_t MakeWRLFrom<uint64_t>(NSNumber* val) {
    return val.unsignedLongLongValue;
}

// Used for marshalling arrays/collections.
template <typename T, WRLT_CreatorT wrlTCreatorFunc = dummyWRLCreator>
struct ToWRLConvertor {
    // String convert.
    template <typename S = T>
    static typename std::enable_if<std::is_same<S, ABITYPE(S)>::value && std::is_same<S, HSTRING>::value, S>::type convert(NSObject* o) {
        if ([o isKindOfClass:[NSString class]]) {
            return nsStrToHstr((NSString*)o).Detach();
        } else if ([o isKindOfClass:[NSNumber class]]) {
            return nsStrToHstr([(NSNumber*)o stringValue]).Detach();
        }
        assert(!"Unsupported input object!");
        return NULL;
    }

    // Default convert
    template <typename N = T>
    static typename std::enable_if<!std::is_pointer<LOGTYPE(N)>::value && !std::is_same<LOGTYPE(N), HSTRING>::value &&
                                       !std::is_enum<LOGTYPE(N)>::value && !std::is_class<LOGTYPE(N)>::value,
                                   LOGTYPE(N)>::type
    convert(NSObject* o) {
        if ([o isKindOfClass:[NSNumber class]]) {
            return MakeWRLFrom<LOGTYPE(N)>((NSNumber*)o);
        } else {
            assert(!"This object type is not supported yet.");
        }
        return LOGTYPE(N)();
    }

    // Enum convert.
    template <typename N = T>
    static typename std::enable_if<std::is_same<N, ABITYPE(N)>::value && std::is_enum<N>::value, N>::type convert(NSObject* o) {
        if ([o isKindOfClass:[NSNumber class]]) {
            return (N)MakeWRLFrom<int>((NSNumber*)o);
        } else {
            assert(!"This object type is not supported yet.");
        }
        return N();
    }

    // Struct convert
    template <typename S = T>
    static typename std::enable_if<std::is_same<S, ABITYPE(S)>::value && !std::is_same<S, HSTRING>::value && std::is_class<S>::value &&
                                       std::is_pod<S>::value,
                                   S>::type
    convert(NSObject* o) {
        if ([o respondsToSelector:@selector(internalStruct)]) {
            return *((S*)[o internalStruct]);
        } else {
            assert(!"This object type does not appear to be a structure.");
        }
        return T();
    }

    template <typename I = T>
    static typename std::enable_if<wrlTCreatorFunc != dummyWRLCreator && !std::is_same<LOGTYPE(I), HSTRING>::value &&
                                       std::is_pointer<LOGTYPE(I)>::value &&
                                       std::is_class<typename std::remove_pointer<LOGTYPE(I)>::type>::value,
                                   ABITYPE(I)>::type
    convert(NSObject* o) {
        return static_cast<I>(wrlTCreatorFunc(o).Detach());
    }

    // Object pointer convert.  Only works if the object in question
    // was originally a proxy object.
    template <typename I = T>
    static typename std::enable_if<wrlTCreatorFunc == dummyWRLCreator && !std::is_same<LOGTYPE(I), HSTRING>::value &&
                                       std::is_pointer<LOGTYPE(I)>::value &&
                                       std::is_class<typename std::remove_pointer<LOGTYPE(I)>::type>::value,
                                   ABITYPE(I)>::type
    convert(NSObject* o) {
        ComPtr<typename std::remove_pointer<ABITYPE(I)>::type> res;

        if ([o isKindOfClass:[RTObject class]]) {
            THROW_NS_IF_FAILED(((RTObject*)o).comObj.As(&res));
            if (!res.Get()) {
                assert(!"Unexpected RT proxy object type.");
            } else {
                return res.Detach(); // don't do the Release(), bad things happen.
            }
        } else {
            assert(!"Cannot un-proxy this class.");
        }
        return nullptr;
    }
};

template <typename OBJCT, typename T, OBJCT_CreatorT objcTCreatorFunc = dummyObjCCreator>
struct ToObjcConvertor {
    // Default convert.
    template <typename N = T>
    static typename std::enable_if<std::is_same<N, ABITYPE(N)>::value && !std::is_enum<N>::value &&
                                       (std::is_same<N, HSTRING>::value || std::is_fundamental<N>::value),
                                   id>::type
    convert(const N& wrlv) {
        return _makeObjcFrom<N>(wrlv);
    }

    // Enums.  Gross.
    template <typename N = T>
    static typename std::enable_if<std::is_same<N, ABITYPE(N)>::value && std::is_enum<N>::value, id>::type convert(const N& wrlv) {
        return _makeObjcFrom<int>(static_cast<int>(wrlv));
    }

    // Struct convert.
    template <typename S = T>
    static typename std::enable_if<std::is_same<S, ABITYPE(S)>::value && !std::is_same<S, HSTRING>::value && !std::is_pointer<S>::value &&
                                       std::is_class<S>::value && std::is_pod<S>::value,
                                   id>::type
    convert(const S& wrlv) {
        return [OBJCT createWith:wrlv];
    }

    // Generate appropriately-typed proxies for WinRT objects.
    template <typename O = OBJCT, typename I = T>
    static typename std::enable_if<!std::is_same<LOGTYPE(I), HSTRING>::value && std::is_pointer<LOGTYPE(I)>::value &&
                                       std::is_class<typename std::remove_pointer<LOGTYPE(I)>::type>::value,
                                   id>::type
    convert(const ABITYPE(I) & wrlv) {
        id obj = AUTORELEASE([NSAllocateObject([O class], 0, 0) init]);
        if ([obj isKindOfClass:[RTObject class]]) {
            [obj setComObj:wrlv];
            return obj;
        }

        return objcTCreatorFunc(wrlv);
    }
};

// Key/Value support.
template <typename WRLK,
          typename WRLK_Template,
          typename WRLV,
          typename WRLV_Template,
          typename OBJCK,
          typename OBJCV,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator>
class RTKeyValuePairObj {
    typedef IKeyValuePair<WRLK_Template, WRLV_Template> KVP;

public:
    RTKeyValuePairObj() {
    }

    id getKey(ComPtr<IInspectable> obj) {
        ComPtr<KVP> kvp;
        THROW_NS_IF_FAILED(obj.As(&kvp));

        WRLK k;
        kvp->get_Key(&k);
        return ToObjcConvertor<OBJCK, WRLK, objcKCreatorFunc>::convert(k);
    }

    id getValue(ComPtr<IInspectable> obj) {
        ComPtr<KVP> kvp;
        THROW_NS_IF_FAILED(obj.As(&kvp));

        WRLV v;
        kvp->get_Value(&v);
        return ToObjcConvertor<OBJCV, WRLV, objcVCreatorFunc>::convert(v);
    }
};

template <typename OBJCT, typename T>
bool ConvertToCArray(id nsarray, UINT32* valueSize, T** values, bool* tempMemory) {
    if (nsarray == nil) {
        *values = NULL;
        *valueSize = 0;
        *tempMemory = false;
        return true;
    } else if ([nsarray isKindOfClass:[NSArray class]]) {
        NSArray* a = (NSArray*)nsarray;
        *valueSize = [a count];
        if ([a respondsToSelector:@selector(isCArray)] && [a isCArray]) {
            // Early out for things that are already C arrays.  Not type safe.
            *values = (T*)[a ptr];
            *tempMemory = false;
            return true;
        }
    } else if ([nsarray conformsToProtocol:@protocol(NSFastEnumeration)]) {
        // assume NSFastEnumeration conformity.
        *valueSize = SizeByEnumeration(nsarray);
    } else {
        assert("!Unsupported container type!");
        return false;
    }

    *tempMemory = true;
    T* out = (T*)CoTaskMemAlloc(*valueSize * sizeof(T));
    *values = out;
    int count = 0;

    for (NSObject* o in nsarray) {
        out[count++] = ToWRLConvertor<T>::convert(o);
    }
    return true;
}

template <typename T, typename Derived>
class ObjcIteratorProxyBase : public InspectableClassBase<Derived> {
private:
    id _items[16] = { 0 };

protected:
    StrongId<id> _proxiedObj;
    NSFastEnumerationState _state = { 0 };
    int _curCount = 0;
    bool _done = false;

    explicit inline ObjcIteratorProxyBase(id proxy) {
        _proxiedObj = proxy;
    }

    virtual ~ObjcIteratorProxyBase() {
        _proxiedObj = nil;
    }

    inline void doFillArray() {
        if (!_done) {
            _curCount = [_proxiedObj countByEnumeratingWithState:&_state objects:_items count:ARRAY_COUNT(_items)];
            if (_curCount == 0) {
                _done = true;
            }
        }
    }
};

template <typename T, WRLT_CreatorT wrlTCreatorFunc, typename Derived = IIterator<LOGTYPE(T)>>
class ObjcIteratorProxy : public ObjcIteratorProxyBase<T, Derived> {
    int _nextObjIdx = 0;

    inline void fillArray() {
        if (_nextObjIdx >= _curCount) {
            doFillArray();
            _nextObjIdx = 0;
        }
    }

public:
    explicit ObjcIteratorProxy(id proxy) : ObjcIteratorProxyBase<T, Derived>(proxy) {
    }

    virtual HRESULT STDMETHODCALLTYPE get_Current(ABITYPE(T) * current) override {
        fillArray();
        if (_done) {
            return E_FAIL;
        }

        *current = ToWRLConvertor<T, wrlTCreatorFunc>::convert(_state.itemsPtr[_nextObjIdx]);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE get_HasCurrent(boolean* hasCurrent) override {
        fillArray();
        *hasCurrent = !_done;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE MoveNext(boolean* hasCurrent) override {
        if (!_done) {
            _nextObjIdx++;
            fillArray();
        }
        *hasCurrent = !_done;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetMany(unsigned int capacity, ABITYPE(T) * items, unsigned int* actual) override {
        unsigned int count = 0;

        fillArray();
        while ((count < capacity) && (!_done)) {
            items[count] = ToWRLConvertor<T, wrlTCreatorFunc>::convert(_state.itemsPtr[_nextObjIdx]);
            _nextObjIdx++;
            count++;
            fillArray();
        }

        *actual = count;
        return S_OK;
    }
};

template <typename T, WRLT_CreatorT wrlTCreatorFunc, typename Derived = IIterable<LOGTYPE(T)>>
class ObjcIterableProxy : public InspectableClassBase<Derived> {
protected:
    StrongId<id> _proxiedObj;

public:
    explicit ObjcIterableProxy(id obj) {
        _proxiedObj = obj;
    }
    ~ObjcIterableProxy() {
        _proxiedObj = nil;
    }

    virtual HRESULT STDMETHODCALLTYPE First(IIterator<LOGTYPE(T)>** it) override {
        *it = new ObjcIteratorProxy<T, wrlTCreatorFunc>(_proxiedObj);
        return S_OK;
    }
};

template <typename OBJCT,
          typename T,
          OBJCT_CreatorT objcTCreatorFunc_Unused = dummyObjCCreator,
          WRLT_CreatorT wrlTCreatorFunc = dummyWRLCreator>
ComPtr<IInspectable> ConvertToIterable(id obj) {
    ComPtr<IIterable<LOGTYPE(T)>> ret;
    id _obj = obj;
    if (_obj == nil)
        _obj = [NSArray array];

#if defined(__cplusplus)
    if ([_obj respondsToSelector:@selector(getInternalComObj)]) {
        ComPtr<IInspectable> returnObj;
        returnObj.Attach([_obj getInternalComObj].Get());
        return returnObj;
    }
#endif

    if ([_obj conformsToProtocol:@protocol(NSFastEnumeration)]) {
        ret.Attach(new ObjcIterableProxy<T, wrlTCreatorFunc>(_obj));
    } else {
        assert(!"Cannot iterate over this object!");
    }
    return ret;
}

//
// Vector/vector view helpers.
//

// For NSArray-based objects.

template <typename OBJCT,
          typename T,
          OBJCT_CreatorT objcTCreatorFunc,
          WRLT_CreatorT wrlTCreatorFunc,
          typename Derived = IVectorView<LOGTYPE(T)>>
class ObjcVectorViewProxy : public InspectableClassBase<Derived> {
protected:
    StrongId<id> _proxiedObj;

public:
    explicit ObjcVectorViewProxy(id obj) {
        _proxiedObj = obj;
    }
    ~ObjcVectorViewProxy() {
        _proxiedObj = nil;
    }

    virtual HRESULT STDMETHODCALLTYPE get_Size(unsigned int* size) override {
        *size = [_proxiedObj count];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetAt(unsigned int index, ABITYPE(T) * item) override {
        if (_proxiedObj == nil)
            return E_FAIL;

        *item = ToWRLConvertor<T, wrlTCreatorFunc>::convert([_proxiedObj objectAtIndex:index]);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE IndexOf(ABITYPE(T) value, unsigned int* index, boolean* found) override {
        if (_proxiedObj == nil) {
            *found = false;
            return S_OK;
        }

        NSUInteger idx = [_proxiedObj indexOfObject:ToObjcConvertor<OBJCT, T, objcTCreatorFunc>::convert(value)];
        if (idx == NSNotFound) {
            *found = false;
        } else {
            *found = true;
            *index = idx;
        }
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetMany(unsigned int startIndex,
                                              unsigned int capacity,
                                              ABITYPE(T) * values,
                                              unsigned int* actual) override {
        unsigned int count = [_proxiedObj count];
        if (startIndex >= count) {
            *actual = 0;
            return S_OK;
        }

        unsigned int end = capacity < (count - startIndex) ? capacity : (count - startIndex);
        for (unsigned int i = 0; i < end; i++) {
            values[i] = ToWRLConvertor<T, wrlTCreatorFunc>::convert([_proxiedObj objectAtIndex:startIndex + i]);
        }
        *actual = end;
        return S_OK;
    }
};

template <typename OBJCT,
          typename T,
          OBJCT_CreatorT objcTCreatorFunc,
          WRLT_CreatorT wrlTCreatorFunc,
          typename Derived = IVector<LOGTYPE(T)>>
class ObjcVectorProxy : public ObjcVectorViewProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc, Derived> {
    bool mutableArray = false;

public:
    explicit ObjcVectorProxy(id obj) : ObjcVectorViewProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc, Derived>(obj) {
        if ([obj isKindOfClass:[NSMutableArray class]])
            mutableArray = true;
    }

    virtual HRESULT STDMETHODCALLTYPE GetView(IVectorView<LOGTYPE(T)>** view) override {
        *view = new ObjcVectorViewProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc, IVectorView<LOGTYPE(T)>>(_proxiedObj);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE SetAt(unsigned int index, ABITYPE(T) item) override {
        if (!mutableArray)
            return E_FAIL;

        [_proxiedObj replaceObjectAtIndex:index withObject:ToObjcConvertor<OBJCT, T, objcTCreatorFunc>::convert(item)];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE InsertAt(unsigned int index, ABITYPE(T) item) override {
        if (!mutableArray)
            return E_FAIL;

        [_proxiedObj insertObject:ToObjcConvertor<OBJCT, T, objcTCreatorFunc>::convert(item) atIndex:index];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE RemoveAt(unsigned int index) override {
        if (!mutableArray)
            return E_FAIL;

        [_proxiedObj removeObjectAtIndex:index];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE Append(ABITYPE(T) item) override {
        if (!mutableArray)
            return E_FAIL;

        [_proxiedObj addObject:ToObjcConvertor<OBJCT, T, objcTCreatorFunc>::convert(item)];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE RemoveAtEnd() override {
        if (!mutableArray)
            return E_FAIL;

        [_proxiedObj removeLastObject];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE Clear() override {
        if (!mutableArray)
            return E_FAIL;

        [_proxiedObj removeAllObjects];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE ReplaceAll(unsigned int count, ABITYPE(T) * value) override {
        if (!mutableArray)
            return E_FAIL;

        [_proxiedObj removeAllObjects];
        for (unsigned int i = 0; i < count; i++) {
            [_proxiedObj addObject:ToObjcConvertor<OBJCT, T, objcTCreatorFunc>::convert(value[i])];
        }

        return S_OK;
    }
};

// For stuff that implements only an iterator.  This will be painful and slow, but it'll work.

template <typename OBJCT,
          typename T,
          OBJCT_CreatorT objcTCreatorFunc,
          WRLT_CreatorT wrlTCreatorFunc,
          typename Derived = IVectorView<LOGTYPE(T)>>
class ObjcVectorByEnumViewProxy : public ObjcIteratorProxyBase<T, Derived> {
    unsigned int _enumSize = ~0;
    unsigned int _arrayStartIdx = ~0;

public:
    explicit ObjcVectorByEnumViewProxy(id obj) : ObjcIteratorProxyBase<T, Derived>(obj) {
    }
    ~ObjcVectorByEnumViewProxy() {
        _proxiedObj = nil;
    }

    virtual HRESULT STDMETHODCALLTYPE get_Size(unsigned int* size) override {
        if (_enumSize == ~0) {
            _enumSize = SizeByEnumeration(_proxiedObj);
        }
        *size = _enumSize;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetAt(unsigned int index, ABITYPE(T) * item) override {
        if (index < _arrayStartIdx) {
            _arrayStartIdx = 0;
            _curCount = 0;
            _state = { 0 };
            _done = false;
            doFillArray();
        }
        while (!_done) {
            if ((_arrayStartIdx <= index) && ((_arrayStartIdx + _curCount) > index)) {
                *item = ToWRLConvertor<T, wrlTCreatorFunc>::convert(_state.itemsPtr[index - _arrayStartIdx]);
                return S_OK;
            }
            _arrayStartIdx += _curCount;
            doFillArray();
        }
        return E_FAIL;
    }

    // Calling this is probably a bad idea.
    virtual HRESULT STDMETHODCALLTYPE IndexOf(ABITYPE(T) value, unsigned int* index, boolean* found) override {
        id convertedValue = ToObjcConvertor<OBJCT, T, objcTCreatorFunc>::convert(value);
        unsigned int objIdx = 0;
        for (id obj in _proxiedObj.get()) {
            if ([obj isEqual:convertedValue]) {
                *found = true;
                *index = objIdx;
                return S_OK;
            }
            objIdx++;
        }

        *found = false;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetMany(unsigned int startIndex,
                                              unsigned int capacity,
                                              ABITYPE(T) * values,
                                              unsigned int* actual) override {
        unsigned int idx = startIndex;
        unsigned int count = 0;
        for (; count < capacity; idx++, count++) {
            HRESULT r = GetAt(idx, &values[count]);
            if (FAILED(r))
                break;
        }
        *actual = count;
        return S_OK;
    }
};

template <typename OBJCT,
          typename T,
          OBJCT_CreatorT objcTCreatorFunc,
          WRLT_CreatorT wrlTCreatorFunc,
          typename Derived = IVector<LOGTYPE(T)>>
class ObjcVectorByEnumProxy : public ObjcVectorByEnumViewProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc, Derived> {
public:
    explicit ObjcVectorByEnumProxy(id obj) : ObjcVectorByEnumViewProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc, Derived>(obj) {
    }

    virtual HRESULT STDMETHODCALLTYPE GetView(IVectorView<LOGTYPE(T)>** view) override {
        *view = new ObjcVectorByEnumViewProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc, IVectorView<LOGTYPE(T)>>(_proxiedObj);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE SetAt(unsigned int index, ABITYPE(T) item) override {
        return E_FAIL;
    }
    virtual HRESULT STDMETHODCALLTYPE InsertAt(unsigned int index, ABITYPE(T) item) override {
        return E_FAIL;
    }
    virtual HRESULT STDMETHODCALLTYPE RemoveAt(unsigned int index) override {
        return E_FAIL;
    }
    virtual HRESULT STDMETHODCALLTYPE Append(ABITYPE(T) item) override {
        return E_FAIL;
    }
    virtual HRESULT STDMETHODCALLTYPE RemoveAtEnd() override {
        return E_FAIL;
    }
    virtual HRESULT STDMETHODCALLTYPE Clear() override {
        return E_FAIL;
    }
    virtual HRESULT STDMETHODCALLTYPE ReplaceAll(unsigned int count, ABITYPE(T) * value) override {
        return E_FAIL;
    }
};

template <typename OBJCT, typename T, OBJCT_CreatorT objcTCreatorFunc = dummyObjCCreator, WRLT_CreatorT wrlTCreatorFunc = dummyWRLCreator>
ComPtr<IInspectable> ConvertToVector(id obj) {
    ComPtr<IVector<LOGTYPE(T)>> ret;
    id _obj = obj;
    if (_obj == nil)
        _obj = [NSArray array];

#if defined(__cplusplus)
    if ([_obj respondsToSelector:@selector(getInternalComObj)]) {
        ComPtr<IInspectable> returnObj;
        returnObj.Attach([_obj getInternalComObj].Get());
        return returnObj;
    }
#endif

    if ([_obj isKindOfClass:[NSArray class]]) {
        ret.Attach(new ObjcVectorProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc>(_obj));
    } else if ([_obj conformsToProtocol:@protocol(NSFastEnumeration)]) {
        // Not a full-featured array, this should be read-only.
        ret.Attach(new ObjcVectorByEnumProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc>(_obj));
    }
    return ret;
}

template <typename OBJCT, typename T, OBJCT_CreatorT objcTCreatorFunc = dummyObjCCreator, WRLT_CreatorT wrlTCreatorFunc = dummyWRLCreator>
ComPtr<IInspectable> ConvertToVectorView(id obj) {
    ComPtr<IVectorView<LOGTYPE(T)>> ret;
    id _obj = obj;
    if (_obj == nil)
        _obj = [NSMutableArray array];

#if defined(__cplusplus)
    if ([_obj respondsToSelector:@selector(getInternalComObj)]) {
        ComPtr<IInspectable> returnObj;
        returnObj.Attach([_obj getInternalComObj].Get());
        return returnObj;
    }
#endif

    if ([_obj isKindOfClass:[NSArray class]]) {
        ret.Attach(new ObjcVectorViewProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc>(_obj));
    } else if ([_obj conformsToProtocol:@protocol(NSFastEnumeration)]) {
        ret.Attach(new ObjcVectorByEnumViewProxy<OBJCT, T, objcTCreatorFunc, wrlTCreatorFunc>(_obj));
    }
    return ret;
}

//
// Map/MapView helpers.
//

template <typename OBJCK,
          typename WRLK,
          typename OBJCV,
          typename WRLV,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator,
          typename Derived = IKeyValuePair<LOGTYPE(WRLK), LOGTYPE(WRLV)>>
class ObjcKVP : public InspectableClassBase<Derived> {
protected:
    StrongId<id> _key;
    StrongId<id> _value;

public:
    ObjcKVP(id k, id v) {
        _key = k;
        _value = v;
    }
    ~ObjcKVP() {
        _key = nil;
        _value = nil;
    }

    virtual HRESULT STDMETHODCALLTYPE get_Key(ABITYPE(WRLK) * key) override {
        *key = ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(_key.get());
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE get_Value(ABITYPE(WRLV) * value) override {
        *value = ToWRLConvertor<WRLV, wrlVCreatorFunc>::convert(_value.get());
        return S_OK;
    }
};

template <typename OBJCK,
          typename WRLK,
          typename OBJCV,
          typename WRLV,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator,
          typename Derived = IIterator<IKeyValuePair<LOGTYPE(WRLK), LOGTYPE(WRLV)>*>>
class ObjcDictionaryIterator : public InspectableClassBase<Derived> {
protected:
    typedef IKeyValuePair<LOGTYPE(WRLK), LOGTYPE(WRLV)> KVP;

    StrongId<NSDictionary> _dict;
    StrongId<NSEnumerator> _enum;
    StrongId<id> _curKey;

public:
    ObjcDictionaryIterator(id dict, NSEnumerator* e) {
        _dict = dict;
        _enum = e;
        _curKey = nil;
    }

    virtual HRESULT STDMETHODCALLTYPE get_Current(KVP** current) override {
        if (!_curKey) {
            _curKey = [_enum nextObject];
            if (!_curKey) {
                *current = nullptr;
                return E_FAIL;
            }
        }

        id val = [_dict objectForKey:_curKey];
        *current = new ObjcKVP<OBJCK, WRLK, OBJCV, WRLV, wrlKCreatorFunc, wrlVCreatorFunc>(_curKey, val);

        _curKey = nil;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE get_HasCurrent(_Out_ boolean* hasCurrent) override {
        if (_curKey != nil) {
            *hasCurrent = true;
            return S_OK;
        }

        _curKey = [_enum nextObject];
        *hasCurrent = (_curKey != nil);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE MoveNext(boolean* hasCurrent) override {
        _curKey = [_enum nextObject];
        *hasCurrent = (_curKey != nil);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetMany(unsigned int capacity, KVP** values, unsigned int* actual) override {
        boolean b = false;
        get_HasCurrent(&b);

        *actual = 0;
        while ((*actual < capacity) && (b == true)) {
            HRESULT r = get_Current(values + *actual);
            if (r != S_OK) {
                return r;
            }

            (*actual)++;

            MoveNext(&b);
        }
        return S_OK;
    }
};

// One of these is returned from a QI on the ObjcDictionaryProxyBase below.
template <typename OBJCK,
          typename WRLK,
          typename OBJCV,
          typename WRLV,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator,
          typename Derived = IIterable<IKeyValuePair<LOGTYPE(WRLK), LOGTYPE(WRLV)>*>>
class ObjcDictionaryIterable : public InspectableClassBase<Derived> {
protected:
    typedef IKeyValuePair<LOGTYPE(WRLK), LOGTYPE(WRLV)> KVP;

    StrongId<id> _proxiedObj;

public:
    explicit ObjcDictionaryIterable(id obj) {
        _proxiedObj = obj;
    }
    ~ObjcDictionaryIterable() {
        _proxiedObj = nil;
    }

    virtual HRESULT STDMETHODCALLTYPE First(IIterator<KVP*>** first) override {
        *first = new ObjcDictionaryIterator<OBJCK, WRLK, OBJCV, WRLV, wrlKCreatorFunc, wrlVCreatorFunc>(_proxiedObj.get(),
                                                                                                        [_proxiedObj keyEnumerator]);
        return S_OK;
    }
};

// Main dictionary proxy object.
template <typename OBJCK,
          typename WRLK,
          typename OBJCV,
          typename WRLV,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator,
          typename Derived = IMapView<LOGTYPE(WRLK), LOGTYPE(WRLV)>>
class ObjcDictionaryProxyBase : public InspectableClassBase<Derived> {
protected:
    typedef IKeyValuePair<LOGTYPE(WRLK), LOGTYPE(WRLV)> KVP;
    typedef IIterable<KVP*> WRL_Iter;

    StrongId<id> _proxiedObj;

public:
    explicit ObjcDictionaryProxyBase(id obj) {
        _proxiedObj = obj;
    }
    ~ObjcDictionaryProxyBase() {
        _proxiedObj = nil;
    }

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(_In_ REFIID id, _COM_Outptr_ void** ppv) override {
        HRESULT r = RuntimeClassBase::QueryInterface(id, ppv);
        if (SUCCEEDED(r))
            return r;

        if (id == __uuidof(WRL_Iter)) {
            *ppv = new ObjcDictionaryIterable<OBJCK, WRLK, OBJCV, WRLV, wrlKCreatorFunc, wrlVCreatorFunc>(_proxiedObj.get());
            return S_OK;
        }

        return E_NOINTERFACE;
    }

    virtual HRESULT STDMETHODCALLTYPE get_Size(unsigned int* size) override {
        *size = [_proxiedObj count];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE Lookup(ABITYPE(WRLK) key, ABITYPE(WRLV) * value) override {
        id k = ToObjcConvertor<OBJCK, WRLK, objcKCreatorFunc>::convert(key);
        id v = [_proxiedObj objectForKey:k];
        *value = ToWRLConvertor<WRLV, wrlVCreatorFunc>::convert(v);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE HasKey(ABITYPE(WRLK) key, boolean* found) override {
        id k = ToObjcConvertor<OBJCK, WRLK, objcKCreatorFunc>::convert(key);
        id v = [_proxiedObj objectForKey:k];
        *found = (v != nil);
        return S_OK;
    }
};

template <typename OBJCK,
          typename WRLK,
          typename OBJCV,
          typename WRLV,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator,
          typename Derived = IMapView<LOGTYPE(WRLK), LOGTYPE(WRLV)>>
class ObjcDictionaryProxy : public ObjcDictionaryProxyBase<OBJCK,
                                                           WRLK,
                                                           OBJCV,
                                                           WRLV,
                                                           objcKCreatorFunc,
                                                           objcVCreatorFunc,
                                                           wrlKCreatorFunc,
                                                           wrlVCreatorFunc,
                                                           Derived> {
public:
    explicit ObjcDictionaryProxy(id obj)
        : ObjcDictionaryProxyBase<OBJCK, WRLK, OBJCV, WRLV, objcKCreatorFunc, objcVCreatorFunc, wrlKCreatorFunc, wrlVCreatorFunc, Derived>(
              obj) {
    }

    virtual HRESULT STDMETHODCALLTYPE Split(IMapView<LOGTYPE(WRLK), LOGTYPE(WRLV)>** firstPartition,
                                            IMapView<LOGTYPE(WRLK), LOGTYPE(WRLV)>** secondPartition) override {
        return E_FAIL;
    }
};

template <typename OBJCK,
          typename WRLK,
          typename OBJCV,
          typename WRLV,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator,
          typename Derived = IMap<LOGTYPE(WRLK), LOGTYPE(WRLV)>>
class ObjcMutableDictionaryProxy : public ObjcDictionaryProxyBase<OBJCK,
                                                                  WRLK,
                                                                  OBJCV,
                                                                  WRLV,
                                                                  objcKCreatorFunc,
                                                                  objcVCreatorFunc,
                                                                  wrlKCreatorFunc,
                                                                  wrlVCreatorFunc,
                                                                  Derived> {
    bool _isMutable;

public:
    explicit ObjcMutableDictionaryProxy(id obj)
        : ObjcDictionaryProxyBase<OBJCK, WRLK, OBJCV, WRLV, objcKCreatorFunc, objcVCreatorFunc, wrlKCreatorFunc, wrlVCreatorFunc, Derived>(
              obj),
          _isMutable([obj isKindOfClass:[NSMutableDictionary class]]) {
    }

    virtual HRESULT STDMETHODCALLTYPE GetView(IMapView<LOGTYPE(WRLK), LOGTYPE(WRLV)>** view) override {
        *view = new ObjcDictionaryProxy<OBJCK, WRLK, OBJCV, WRLV, objcKCreatorFunc, objcVCreatorFunc, wrlKCreatorFunc, wrlVCreatorFunc>(
            _proxiedObj);
        return S_OK;
    }

    // write methods
    virtual HRESULT STDMETHODCALLTYPE Insert(ABITYPE(WRLK) key, ABITYPE(WRLV) value, boolean* replaced) override {
        if (!_isMutable)
            return E_FAIL;

        auto k = ToObjcConvertor<OBJCK, WRLK, objcKCreatorFunc>::convert(key);
        *replaced = ([_proxiedObj objectForKey:k] != nil);
        [_proxiedObj setObject:ToObjcConvertor<OBJCV, WRLV, objcVCreatorFunc>::convert(value) forKey:k];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE Remove(ABITYPE(WRLK) key) override {
        if (!_isMutable)
            return E_FAIL;

        [_proxiedObj removeObjectForKey:ToObjcConvertor<OBJCK, WRLK, objcKCreatorFunc>::convert(key)];
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE Clear() override {
        if (!_isMutable)
            return E_FAIL;

        [_proxiedObj removeAllObjects];
        return S_OK;
    }
};

template <typename OBJCK,
          typename WRLK,
          typename OBJCV,
          typename WRLV,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator>
ComPtr<IInspectable> ConvertToMapView(id obj) {
    ComPtr<IMapView<LOGTYPE(WRLK), LOGTYPE(WRLV)>> ret;
    id _obj = obj;
    if (_obj == nil)
        _obj = [NSDictionary dictionary];

#if defined(__cplusplus)
    if ([_obj respondsToSelector:@selector(getInternalComObj)]) {
        ComPtr<IInspectable> returnObj;
        returnObj.Attach([_obj getInternalComObj].Get());
        return returnObj;
    }
#endif

    if ([_obj isKindOfClass:[NSDictionary class]]) {
        ret.Attach(
            new ObjcDictionaryProxy<OBJCK, WRLK, OBJCV, WRLV, objcKCreatorFunc, objcVCreatorFunc, wrlKCreatorFunc, wrlVCreatorFunc>(_obj));
    }
    return ret;
}

template <typename OBJCK,
          typename WRLK,
          typename OBJCV,
          typename WRLV,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator>
ComPtr<IInspectable> ConvertToMap(id obj) {
    ComPtr<IMap<LOGTYPE(WRLK), LOGTYPE(WRLV)>> ret;
    id _obj = obj;
    if (_obj == nil)
        _obj = [NSMutableDictionary dictionary];
#if defined(__cplusplus)
    if ([_obj respondsToSelector:@selector(getInternalComObj)]) {
        ComPtr<IInspectable> returnObj;
        returnObj.Attach([_obj getInternalComObj].Get());
        return returnObj;
    }
#endif

    if ([_obj isKindOfClass:[NSDictionary class]]) {
        ret.Attach(
            new ObjcMutableDictionaryProxy<OBJCK, WRLK, OBJCV, WRLV, objcKCreatorFunc, objcVCreatorFunc, wrlKCreatorFunc, wrlVCreatorFunc>(
                _obj));
    }
    return ret;
}

//
// Nullable helpers.
//
// TODO: BK: OH GOD: boolean junk here: #ifdef DEF___FIReference_1_boolean_USE

template <typename OBJCT, typename WRLT>
struct MakeFromNullable {
    // Basic types.
    template <typename W = WRLT>
    static typename std::enable_if<!std::is_enum<LOGTYPE(W)>::value &&
                                       (std::is_fundamental<LOGTYPE(W)>::value || std::is_same<LOGTYPE(W), HSTRING>::value),
                                   id>::type
    convert(IReference<LOGTYPE(W)>* boxed) {
        if (!boxed)
            return nil;
        ABITYPE(W) val;
        boxed->get_Value(&val);
        return _makeObjcFrom<LOGTYPE(W)>(val);
    }

    // Enums.
    template <typename W = WRLT>
    static typename std::enable_if<std::is_enum<W>::value, id>::type convert(IReference<W>* boxed) {
        if (!boxed)
            return nil;
        W val;
        boxed->get_Value(&val);
        return _makeObjcFrom<int>((int)val);
    }

    // Structs.
    template <typename O = OBJCT, typename W = WRLT>
    static typename std::enable_if<std::is_same<W, ABITYPE(W)>::value && !std::is_same<W, HSTRING>::value && !std::is_pointer<W>::value &&
                                       std::is_class<W>::value && std::is_pod<W>::value,
                                   id>::type
    convert(IReference<W>* boxed) {
        if (!boxed)
            return nil;
        W val;
        boxed->get_Value(&val);
        return [O createWith:val];
    }

    // Generate appropriately-typed proxies for WinRT objects.
    template <typename O = OBJCT, typename W = WRLT>
    static typename std::enable_if<!std::is_same<LOGTYPE(W), HSTRING>::value && std::is_pointer<LOGTYPE(W)>::value &&
                                       std::is_class<typename std::remove_pointer<LOGTYPE(W)>::type>::value,
                                   id>::type
    convert(const ABITYPE(W) & wrlv) {
        if (!boxed)
            return nil;
        ABITYPE(W) val;
        boxed->get_Value(&val);
        return _createRtProxy<O>(val);
    }
};

template <typename T, bool = _is_COM_Object(T)>
class BoxedObj : public InspectableClassBase<IReference<LOGTYPE(T)>> {
    LOGTYPE(T) value;

public:
    explicit inline BoxedObj(const ABITYPE(T) & val) : value(val) {
    }

    virtual HRESULT STDMETHODCALLTYPE get_Value(ABITYPE(T) * v) override {
        *v = value;
        return S_OK;
    }
};

template <typename T>
class BoxedObj<T, true> : public InspectableClassBase<IReference<LOGTYPE(T)>> {
    ComPtr<typename std::remove_pointer<ABITYPE(T)>::type> value;

public:
    explicit inline BoxedObj(const ABITYPE(T) & val) {
        value.Attach(val);
    }

    virtual HRESULT STDMETHODCALLTYPE get_Value(ABITYPE(T) * v) override {
        return value.CopyTo(v);
    }
};

typedef void (^ErrorBlockType)(NSError*);

// Returns whether we hit an error or not:
template <typename AsyncType>
inline bool _handleAsyncErrorCode(AsyncType* async, BlockHolder<ErrorBlockType> errorBlock) {
    // The ErrorCode property is on the IAsyncInfo interface, so we need to QI:
    ComPtr<AsyncType> asyncPtr(async);
    ComPtr<IAsyncInfo> asyncInfo;
    FAIL_FAST_IF_FAILED(asyncPtr.As(&asyncInfo));

    HRESULT errorCode;
    HRESULT hr = asyncInfo->get_ErrorCode(&errorCode);

    if (errorBlock) {
        if (FAILED(hr)) {
            errorBlock([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
        } else if (FAILED(errorCode)) {
            errorBlock([NSError errorWithDomain:@"HRESULT" code:errorCode userInfo:nil]);
        }
    } else {
        // If we have no error block, at least try to communicate the error:
        if (FAILED(hr)) {
            LOG_HR(hr);
        } else if (FAILED(errorCode)) {
            LOG_HR(errorCode);
        }
    }

    return SUCCEEDED(hr) && SUCCEEDED(errorCode);
}

template <typename WRLT, WRLT_CreatorT wrlTCreatorFunc = dummyWRLCreator>
BoxedObj<WRLT>* BuildNullable(id val) {
    if (val == nil)
        return nullptr;
    return new BoxedObj<WRLT>(ToWRLConvertor<WRLT, wrlTCreatorFunc>::convert(val));
}

//
// For observable collections.
//
WINRT_EXPORT
@interface ListenerMgr : NSObject
- (id)init;
- (id)initWith:(id)owner;
- (void)setOwner:(id)owner;
- (EventRegistrationToken)addObserver:(RTCollectionListener)receiver;
- (void)removeObserver:(EventRegistrationToken)receiverToken;
- (void)notify:(RTCollectionOperation)op value:(id)val;
- (NSArray*)listeners;
@end

WINRT_EXPORT_FN
NSUInteger fastEnumArrayImpl(id self, NSFastEnumerationState* state, id* buffer, NSUInteger len);
WINRT_EXPORT_FN
NSUInteger fastEnumIteratorImpl(id self, NSFastEnumerationState* state, id* buffer, NSUInteger len);

//
// Array implementation templates.
//

template <typename WRLT, typename OBJCT, OBJCT_CreatorT objcTCreatorFunc = dummyObjCCreator>
class RTCArrayObj {
public:
    WRLT* _array = NULL;
    unsigned int _count = 0;
    bool _owned = false;

    inline ~RTCArrayObj() {
        if (_owned && _array) {
            CoTaskMemFree(_array);
            _array = NULL;
        }
    }

    inline unsigned int count(void*) const {
        return _count;
    }
    inline id get(void*, unsigned int idx) const {
        return ToObjcConvertor<OBJCT, WRLT, objcTCreatorFunc>::convert(_array[idx]);
    }

    inline bool isCArray() const {
        return true;
    }
    inline WRLT* ptr() const {
        return _array;
    }
};

template <typename WRLT,
          typename WRLContainerT,
          typename OBJCT,
          typename TemplateT,
          OBJCT_CreatorT objcTCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlTCreatorFunc_unused = dummyWRLCreator>
class RTArrayObj {
public:
    unsigned int count(const ComPtr<IInspectable> o) const {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));
        unsigned int res = 0;
        array->get_Size(&res);
        return res;
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T), id>::type get(const ComPtr<IInspectable> o, unsigned int idx) const {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));
        ComPtr<typename std::remove_pointer<WRLT>::type> val;
        array->GetAt(idx, val.GetAddressOf());
        return ToObjcConvertor<OBJCT, WRLT, objcTCreatorFunc>::convert(val.Get());
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T) == false, id>::type get(const ComPtr<IInspectable> o, unsigned int idx) const {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));
        WRLT val;
        array->GetAt(idx, &val);
        return ToObjcConvertor<OBJCT, WRLT, objcTCreatorFunc>::convert(val);
    }

    inline bool isCArray() const {
        return false;
    }
    inline WRLT* ptr() const {
        return NULL;
    }
};

template <typename WRLT,
          typename WRLContainerT,
          typename OBJCT,
          typename TemplateT,
          OBJCT_CreatorT objcTCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlTCreatorFunc = dummyWRLCreator>
class RTMutableArrayObj : public RTArrayObj<WRLT, WRLContainerT, OBJCT, TemplateT, objcTCreatorFunc, wrlTCreatorFunc> {
public:
    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T), void>::type set(const ComPtr<IInspectable> o, id obj, unsigned int idx) {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));
        ComPtr<typename std::remove_pointer<WRLT>::type> val;
        val.Attach(ToWRLConvertor<WRLT, wrlTCreatorFunc>::convert(obj));
        array->SetAt(idx, val.Get());
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T) == false, void>::type set(const ComPtr<IInspectable> o, id obj, unsigned int idx) {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));
        WRLT val = ToWRLConvertor<WRLT, wrlTCreatorFunc>::convert(obj);
        array->SetAt(idx, val);
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T), void>::type insert(const ComPtr<IInspectable> o, id obj, unsigned int idx) {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));

        ComPtr<typename std::remove_pointer<WRLT>::type> val;
        val.Attach(ToWRLConvertor<WRLT, wrlTCreatorFunc>::convert(obj));
        array->InsertAt(idx, val.Get());
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T) == false, void>::type insert(const ComPtr<IInspectable> o, id obj, unsigned int idx) {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));
        WRLT val = ToWRLConvertor<WRLT, wrlTCreatorFunc>::convert(obj);
        HRESULT hr = array->InsertAt(idx, val);
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T), void>::type append(const ComPtr<IInspectable> o, id obj) {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));

        ComPtr<typename std::remove_pointer<WRLT>::type> val;
        val.Attach(ToWRLConvertor<WRLT, wrlTCreatorFunc>::convert(obj));
        array->Append(val.Get());
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T) == false, void>::type append(const ComPtr<IInspectable> o, id obj) {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));
        WRLT val = ToWRLConvertor<WRLT, wrlTCreatorFunc>::convert(obj);
        HRESULT hr = array->Append(val);
    }

    void erase(const ComPtr<IInspectable> o, unsigned int idx) {
        ComPtr<WRLContainerT> array;
        THROW_NS_IF_FAILED(o.As(&array));
        array->RemoveAt(idx);
    }
};

template <typename WRLT,
          typename WRLContainerT,
          typename OBJCT,
          typename TemplateT,
          OBJCT_CreatorT objcTCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlTCreatorFunc = dummyWRLCreator>
class RTObservableArrayObj : public RTMutableArrayObj<WRLT, WRLContainerT, OBJCT, TemplateT, objcTCreatorFunc, wrlTCreatorFunc> {
private:
    class Handler : public RuntimeClassBase<VectorChangedEventHandler<TemplateT>> {
    public:
        StrongId<id> receiver;

        ~Handler() {
            receiver = nil;
        }

        virtual HRESULT STDMETHODCALLTYPE Invoke(IObservableVector<TemplateT>* sender, IVectorChangedEventArgs* e) override {
            CollectionChange cc;
            e->get_CollectionChange(&cc);
            RTCollectionOperation op = ccToOperation(cc);

            unsigned int idx;
            e->get_Index(&idx);

            [receiver notify:op at:idx];

            return S_OK;
        }
    };

    std::unique_ptr<Handler> _handler;
    EventRegistrationToken _regToken;

public:
    RTObservableArrayObj() {
        _handler = std::make_unique<Handler>();
    }
    ~RTObservableArrayObj() {
        _handler = nullptr;
    }

    void registerSelf(const ComPtr<IInspectable> o, id receiver) {
        ComPtr<IObservableVector<TemplateT>> vec;
        THROW_NS_IF_FAILED(o.As(&vec));

        _handler->receiver = receiver;
        HRESULT r = vec->add_VectorChanged(_handler.get(), &_regToken);
        assert(SUCCEEDED(r));
    }

    void unregisterSelf(const ComPtr<IInspectable> o) {
        ComPtr<IObservableVector<TemplateT>> vec;
        THROW_NS_IF_FAILED(o.As(&vec));

        HRESULT r = vec->remove_VectorChanged(_regToken);
        assert(SUCCEEDED(r));
    }
};

template <typename WRLT,
          typename WRLContainerT,
          typename OBJCT,
          typename TemplateT,
          OBJCT_CreatorT objcTCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlTCreatorFunc = dummyWRLCreator>
class RTObservableArrayObjFull : public RTObservableArrayObj<WRLT, WRLContainerT, OBJCT, TemplateT, objcTCreatorFunc, wrlTCreatorFunc> {
    StrongId<ListenerMgr> _mgr;

public:
    RTObservableArrayObjFull() : RTObservableArrayObj<WRLT, WRLContainerT, OBJCT, TemplateT, objcTCreatorFunc, wrlTCreatorFunc>() {
        _mgr.attach([[ListenerMgr alloc] init]);
    }

    ~RTObservableArrayObjFull() {
        _mgr = nil;
    }

    void setOwner(id owner){ [_mgr setOwner:owner] };
    inline StrongId<ListenerMgr> getMgr() const {
        return _mgr;
    }
};

// Turns an iterable object into an array.
// Will be slow if accessed poorly.
template <typename WRLT,
          typename WRLContainerT,
          typename OBJCT,
          typename TemplateT,
          OBJCT_CreatorT objcTCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlTCreatorFunc_unused = dummyWRLCreator>
class RTIterableObj {
    typedef IIterator<TemplateT> WRLIteratorT;
    ComPtr<WRLIteratorT> _iterator;
    unsigned int _lastIdx = ~0;
    unsigned int _count = ~0;

public:
    unsigned int count(const ComPtr<IInspectable> o) {
        if (_count == ~0) {
            ComPtr<WRLContainerT> iterable;
            THROW_NS_IF_FAILED(o.As(&iterable));

            boolean b;
            _count = 0;
            ComPtr<WRLIteratorT> it;
            iterable.Get()->First(&it);

            it.Get()->get_HasCurrent(&b);
            while (b) {
                _count++;
                it.Get()->MoveNext(&b);
            }
        }
        return _count;
    }

    id get(const ComPtr<IInspectable> o, unsigned int idx) {
        ComPtr<WRLContainerT> iterable;
        THROW_NS_IF_FAILED(o.As(&iterable));

        if (idx < _lastIdx) {
            _lastIdx = 0;
            iterable.Get()->First(&_iterator);
        }

        boolean b;
        _iterator.Get()->get_HasCurrent(&b);
        while (b && (_lastIdx < idx)) {
            _iterator.Get()->MoveNext(&b);
            _lastIdx++;
        }
        if (!b)
            return nil;

        WRLT res;
        _iterator.Get()->get_Current(&res);
        return ToObjcConvertor<OBJCT, WRLT, objcTCreatorFunc>::convert(res);
    }

    // These two functions are used to implement fast enumeration.
    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T), id>::type first(const ComPtr<IInspectable> o) {
        boolean b = false;
        ComPtr<WRLContainerT> iterable;
        THROW_NS_IF_FAILED(o.As(&iterable));

        _lastIdx = ~0;
        iterable.Get()->First(&_iterator);

        _iterator.Get()->get_HasCurrent(&b);
        if (!b)
            return nil;

        ComPtr<typename std::remove_pointer<WRLT>::type> val;
        _iterator.Get()->get_Current(val.GetAddressOf());
        return ToObjcConvertor<OBJCT, WRLT, objcTCreatorFunc>::convert(val.Get());
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T) == false, id>::type first(const ComPtr<IInspectable> o) {
        boolean b = false;
        ComPtr<WRLContainerT> iterable;
        THROW_NS_IF_FAILED(o.As(&iterable));

        _lastIdx = ~0;
        iterable.Get()->First(&_iterator);

        _iterator.Get()->get_HasCurrent(&b);
        if (!b)
            return nil;

        WRLT val;
        _iterator.Get()->get_Current(&val);
        return ToObjcConvertor<OBJCT, WRLT, objcTCreatorFunc>::convert(val);
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T), id>::type next(const ComPtr<IInspectable> o) {
        boolean b = false;

        _lastIdx = ~0;
        _iterator.Get()->MoveNext(&b);
        if (!b)
            return nil;

        ComPtr<typename std::remove_pointer<WRLT>::type> val;
        _iterator.Get()->get_Current(val.GetAddressOf());
        return ToObjcConvertor<OBJCT, WRLT, objcTCreatorFunc>::convert(val.Get());
    }

    template <typename T = WRLT>
    typename std::enable_if<_is_COM_Object(T) == false, id>::type next(const ComPtr<IInspectable> o) {
        boolean b = false;

        _lastIdx = ~0;
        _iterator.Get()->MoveNext(&b);
        if (!b)
            return nil;

        WRLT val;
        _iterator.Get()->get_Current(&val);
        return ToObjcConvertor<OBJCT, WRLT, objcTCreatorFunc>::convert(val);
    }

    inline bool isCArray() const {
        return false;
    }
    inline WRLT* ptr() const {
        return NULL;
    }
};

template <typename WRLK_Template, typename WRLK, typename OBJCK, typename WRLV_Template>
class RTMapViewKeyEnumerator {
    typedef IKeyValuePair<WRLK_Template, WRLV_Template> KVP;
    typedef IIterator<KVP*> Iterator;
    typedef IIterable<KVP*> Iterable;

    ComPtr<Iterator> _iter;
    ComPtr<Iterable> _iterable;

public:
    void initWith(IInspectable* mapview) {
        ComPtr<IInspectable> mv(mapview);
        THROW_NS_IF_FAILED(mv.As(&_iterable));
        _iterable->First(&_iter);
    }

    id nextObject() {
        boolean hasCurrent;
        _iter->get_HasCurrent(&hasCurrent);
        if (!hasCurrent)
            return nil;

        ComPtr<KVP> curPair;
        _iter->get_Current(&curPair);
        WRLK keyRaw;
        curPair->get_Key(&keyRaw);
        _iter->MoveNext(&hasCurrent);

        return ToObjcConvertor<OBJCK, WRLK>::convert(keyRaw);
    }
};

template <typename WRLK_Template,
          typename WRLK,
          typename WRLV_Template,
          typename WRLV,
          typename OBJCK,
          typename OBJCV,
          typename TEMPL,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator>
class RTMapViewObj {
protected:
    typedef IKeyValuePair<WRLK_Template, WRLV_Template> KVP;
    typedef IIterator<KVP*> Iterator;
    typedef IIterable<KVP*> Iterable;

public:
    RTMapViewObj() {
    }

    template <typename T = WRLK>
    typename std::enable_if<_is_COM_Object(T), id>::type get(ComPtr<IInspectable> obj, id key) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        ComPtr<typename std::remove_pointer<WRLK>::type> wrlKey;
        wrlKey.Attach(ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key));

        WRLV val;
        HRESULT r = winrtMap->Lookup(wrlKey.Get(), &val);
        assert(r == S_OK);

        return ToObjcConvertor<OBJCV, WRLV, objcVCreatorFunc>::convert(val);
    }

    template <typename T = WRLK>
    typename std::enable_if<_is_COM_Object(T) == false, id>::type get(ComPtr<IInspectable> obj, id key) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        WRLK wrlKey = ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key);
        WRLV val;
        HRESULT r = winrtMap->Lookup(wrlKey, &val);
        assert(r == S_OK);

        return ToObjcConvertor<OBJCV, WRLV, objcVCreatorFunc>::convert(val);
    }

    template <typename T = WRLK>
    typename std::enable_if<_is_COM_Object(T), bool>::type has(ComPtr<IInspectable> obj, id key) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        boolean res = false;
        ComPtr<typename std::remove_pointer<WRLK>::type> wrlKey;
        wrlKey.Attach(ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key));
        winrtMap->HasKey(wrlKey.Get(), &res);

        return res ? true : false;
    }

    template <typename T = WRLK>
    typename std::enable_if<_is_COM_Object(T) == false, bool>::type has(ComPtr<IInspectable> obj, id key) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        boolean res = false;
        WRLK wrlKey = ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key);
        winrtMap->HasKey(wrlKey, &res);

        return res ? true : false;
    }

    unsigned int count(ComPtr<IInspectable> obj) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        unsigned int val = 0;
        HRESULT hr = winrtMap->get_Size(&val);
        assert(hr == S_OK);
        return val;
    }

    id allKeys(ComPtr<IInspectable> obj) {
        NSMutableArray* res = [NSMutableArray array];
        ComPtr<Iterable> iterable;
        ComPtr<Iterator> iter;

        THROW_NS_IF_FAILED(obj.As(&iterable));
        iterable->First(&iter);
        boolean hasCurrent = false;
        for (iter->get_HasCurrent(&hasCurrent); hasCurrent; iter->MoveNext(&hasCurrent)) {
            ComPtr<KVP> curPair;
            iter->get_Current(&curPair);
            WRLK keyRaw;
            curPair->get_Key(&keyRaw);
            [res addObject:ToObjcConvertor<OBJCK, WRLK, objcKCreatorFunc>::convert(keyRaw)];
        }
        return res;
    }

    id allKeysFor(ComPtr<IInspectable> obj, id o) {
        NSMutableArray* res = [NSMutableArray array];
        ComPtr<Iterable> iterable;
        ComPtr<Iterator> iter;

        THROW_NS_IF_FAILED(obj.As(&iterable));
        iterable->First(&iter);
        boolean hasCurrent = false;
        for (iter->get_HasCurrent(&hasCurrent); hasCurrent; iter->MoveNext(&hasCurrent)) {
            ComPtr<KVP> curPair;
            iter->get_Current(&curPair);
            WRLV objRaw;
            curPair->get_Value(&objRaw);
            if ([o isEqual:ToObjcConvertor<OBJCV, WRLV, objcVCreatorFunc>::convert(objRaw)]) {
                WRLK keyRaw;
                curPair->get_Key(&keyRaw);
                [res addObject:ToObjcConvertor<OBJCK, WRLK, objcKCreatorFunc>::convert(keyRaw)];
            }
        }
        return res;
    }

    id allValues(ComPtr<IInspectable> obj) {
        NSMutableArray* res = [NSMutableArray array];
        ComPtr<Iterable> iterable;
        ComPtr<Iterator> iter;

        THROW_NS_IF_FAILED(obj.As(&iterable));
        iterable->First(&iter);
        boolean hasCurrent = false;
        for (iter->get_HasCurrent(&hasCurrent); hasCurrent; iter->MoveNext(&hasCurrent)) {
            ComPtr<KVP> curPair;
            iter->get_Current(&curPair);
            WRLV valueRaw;
            curPair->get_Value(&valueRaw);
            [res addObject:ToObjcConvertor<OBJCV, WRLV, objcVCreatorFunc>::convert(valueRaw)];
        }
        return res;
    }
};

template <typename WRLK_Template,
          typename WRLK,
          typename WRLV_Template,
          typename WRLV,
          typename OBJCK,
          typename OBJCV,
          typename TEMPL,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator>
class RTMapObj : public RTMapViewObj<WRLK_Template,
                                     WRLK,
                                     WRLV_Template,
                                     WRLV,
                                     OBJCK,
                                     OBJCV,
                                     TEMPL,
                                     objcKCreatorFunc,
                                     objcVCreatorFunc,
                                     wrlKCreatorFunc,
                                     wrlVCreatorFunc> {
public:
    RTMapObj()
        : RTMapViewObj<WRLK_Template,
                       WRLK,
                       WRLV_Template,
                       WRLV,
                       OBJCK,
                       OBJCV,
                       TEMPL,
                       objcKCreatorFunc,
                       objcVCreatorFunc,
                       wrlKCreatorFunc,
                       wrlVCreatorFunc>() {
    }

    template <typename T = WRLK, typename U = WRLV>
    typename std::enable_if<!(_is_COM_Object(T) || _is_COM_Object(U)), void>::type set(ComPtr<IInspectable> obj, id key, id o) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        boolean res;
        winrtMap->Insert(ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key), ToWRLConvertor<WRLV, wrlVCreatorFunc>::convert(o), &res);
    }

    template <typename T = WRLK, typename U = WRLV>
    typename std::enable_if<_is_COM_Object(T) && _is_COM_Object(U) == false, void>::type set(ComPtr<IInspectable> obj, id key, id o) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        boolean res;
        ComPtr<typename std::remove_pointer<WRLK>::type> _key;
        _key.Attach(ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key));
        winrtMap->Insert(_key.Get(), ToWRLConvertor<WRLV, wrlVCreatorFunc>::convert(o), &res);
    }

    template <typename T = WRLK, typename U = WRLV>
    typename std::enable_if<_is_COM_Object(T) == false && _is_COM_Object(U), void>::type set(ComPtr<IInspectable> obj, id key, id o) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        boolean res;
        ComPtr<typename std::remove_pointer<WRLV>::type> _value;
        _value.Attach(ToWRLConvertor<WRLV, wrlVCreatorFunc>::convert(o));
        winrtMap->Insert(ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key), _value.Get(), &res);
    }

    template <typename T = WRLK, typename U = WRLV>
    typename std::enable_if<_is_COM_Object(T) && _is_COM_Object(U), void>::type set(ComPtr<IInspectable> obj, id key, id o) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        boolean res;
        ComPtr<typename std::remove_pointer<WRLK>::type> _key;
        _key.Attach(ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key));
        ComPtr<typename std::remove_pointer<WRLV>::type> _value;
        _value.Attach(ToWRLConvertor<WRLV, wrlVCreatorFunc>::convert(o));
        winrtMap->Insert(_key.Get(), _value.Get(), &res);
    }

    template <typename T = WRLK>
    typename std::enable_if<_is_COM_Object(T), void>::type remove(ComPtr<IInspectable> obj, id key) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        if (this->has(obj, key)) {
            ComPtr<typename std::remove_pointer<WRLK>::type> _key;
            _key.Attach(ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key));
            winrtMap->Remove(_key.Get());
        }
    }

    template <typename T = WRLK>
    typename std::enable_if<_is_COM_Object(T) == false, void>::type remove(ComPtr<IInspectable> obj, id key) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        if (this->has(obj, key)) {
            winrtMap->Remove(ToWRLConvertor<WRLK, wrlKCreatorFunc>::convert(key));
        }
    }

    void clear(ComPtr<IInspectable> obj) {
        ComPtr<TEMPL> winrtMap;
        THROW_NS_IF_FAILED(obj.As(&winrtMap));

        winrtMap->Clear();
    }

    void removeObjs(ComPtr<IInspectable> obj, NSArray* keys) {
        for (id k in keys) {
            remove(obj, k);
        }
    }

    void addAll(ComPtr<IInspectable> obj, NSDictionary* d) {
        for (id k in [d allKeys]) {
            set(obj, k, [d objectForKey:k]);
        }
    }

    void addNew(ComPtr<IInspectable> obj, NSDictionary* d) {
        for (id k in [d allKeys]) {
            if (!this->has(obj, k))
                set(obj, k, [d objectForKey:k]);
        }
    }
};

template <typename WRLK_Template,
          typename WRLK,
          typename WRLV_Template,
          typename WRLV,
          typename OBJCK,
          typename OBJCV,
          typename TEMPL,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator>
class RTObservableMapObj : public RTMapObj<WRLK_Template,
                                           WRLK,
                                           WRLV_Template,
                                           WRLV,
                                           OBJCK,
                                           OBJCV,
                                           TEMPL,
                                           objcKCreatorFunc,
                                           objcVCreatorFunc,
                                           wrlKCreatorFunc,
                                           wrlVCreatorFunc> {
private:
    class Handler : public RuntimeClassBase<MapChangedEventHandler<WRLK, WRLV>> {
    public:
        StrongId<id> receiver;

        ~Handler() {
            receiver = nil;
        }

        virtual HRESULT STDMETHODCALLTYPE Invoke(IObservableMap<WRLK_Template, WRLV_Template>* sender,
                                                 IMapChangedEventArgs<WRLK_Template>* e) override {
            CollectionChange cc;
            e->get_CollectionChange(&cc);
            RTCollectionOperation op = ccToOperation(cc);

            WRLK kval;
            e->get_Key(&kval);
            id key = ToObjcConvertor<OBJCK, WRLK, objcKCreatorFunc>::convert(kval);

            [receiver notify:op atKey:key];

            return S_OK;
        }
    };

    std::unique_ptr<Handler> _handler;
    EventRegistrationToken _regToken;

public:
    RTObservableMapObj()
        : RTMapObj<WRLK_Template,
                   WRLK,
                   WRLV_Template,
                   WRLV,
                   OBJCK,
                   OBJCV,
                   TEMPL,
                   objcKCreatorFunc,
                   objcVCreatorFunc,
                   wrlKCreatorFunc,
                   wrlVCreatorFunc>() {
        _handler = std::make_unique<Handler>();
    }

    void registerSelf(ComPtr<IInspectable> obj, id receiver) {
        ComPtr<IObservableMap<LOGTYPE(WRLK), LOGTYPE(WRLV)>> map;
        THROW_NS_IF_FAILED(obj.As(&map));
        assert(map.Get());

        _handler->receiver = receiver;
        HRESULT r = map->add_MapChanged(_handler.get(), &_regToken);
        assert(SUCCEEDED(r));
    }

    void unregisterSelf(ComPtr<IInspectable> obj) {
        ComPtr<IObservableMap<LOGTYPE(WRLK), LOGTYPE(WRLV)>> map;
        THROW_NS_IF_FAILED(obj.As(&map));
        assert(map.Get());

        HRESULT r = map->remove_MapChanged(_regToken);
        assert(SUCCEEDED(r));
    }
};

template <typename WRLK_Template,
          typename WRLK,
          typename WRLV_Template,
          typename WRLV,
          typename OBJCK,
          typename OBJCV,
          typename TEMPL,
          OBJCT_CreatorT objcKCreatorFunc = dummyObjCCreator,
          OBJCT_CreatorT objcVCreatorFunc = dummyObjCCreator,
          WRLT_CreatorT wrlKCreatorFunc = dummyWRLCreator,
          WRLT_CreatorT wrlVCreatorFunc = dummyWRLCreator>
class RTObservableMapObjFull : public RTObservableMapObj<WRLK_Template,
                                                         WRLK,
                                                         WRLV_Template,
                                                         WRLV,
                                                         OBJCK,
                                                         OBJCV,
                                                         TEMPL,
                                                         objcKCreatorFunc,
                                                         objcVCreatorFunc,
                                                         wrlKCreatorFunc,
                                                         wrlVCreatorFunc> {
    StrongId<ListenerMgr> _mgr;

public:
    RTObservableMapObjFull()
        : RTObservableMapObj<WRLK_Template,
                             WRLK,
                             WRLV_Template,
                             WRLV,
                             OBJCK,
                             OBJCV,
                             TEMPL,
                             objcKCreatorFunc,
                             objcVCreatorFunc,
                             wrlKCreatorFunc,
                             wrlVCreatorFunc>() {
        _mgr.attach([[ListenerMgr alloc] init]);
    }
    ~RTObservableMapObjFull() {
        _mgr = nil;
    }

    void setOwner(id owner){ [_mgr setOwner:owner] };
    inline StrongId<ListenerMgr> getMgr() const {
        return _mgr;
    }
};

//
// Array macros
// TODO: BK: might be better to use the aggregate types instead of separate parameters for these things.
//

#define INTEROP_ADD_ARRAY_FASTENUM()                                                                                           \
    -(NSUInteger)countByEnumeratingWithState : (NSFastEnumerationState*)state objects : (id __unsafe_unretained[])buffer count \
                                                                                        : (NSUInteger)len {                    \
        return fastEnumArrayImpl(self, state, buffer, len);                                                                    \
    }

#define INTEROP_ADD_ITERABLE_FASTENUM()                                                                                        \
    -(NSUInteger)countByEnumeratingWithState : (NSFastEnumerationState*)state objects : (id __unsafe_unretained[])buffer count \
                                                                                        : (NSUInteger)len {                    \
        return fastEnumIteratorImpl(self, state, buffer, len);                                                                 \
    }

#define INTEROP_IMPL_VECBASE(refObj)     \
    -(unsigned int)count {               \
        return _array.count(refObj);     \
    }                                    \
    -(id)objectAtIndex : (unsigned)idx { \
        return _array.get(refObj, idx);  \
    }                                    \
    -(BOOL)isCArray {                    \
        return _array.isCArray();        \
    }                                    \
    -(void*)ptr {                        \
        return _array.ptr();             \
    }

#define INTEROP_IMPL_WRITABLE_VECBASE(refObj)                            \
    -(void)insertObject : (id)obj atIndex : (NSUInteger)idx {            \
        _array.insert(refObj, obj, idx);                                 \
    }                                                                    \
    -(void)removeObjectAtIndex : (NSUInteger)idx {                       \
        _array.erase(refObj, idx);                                       \
    }                                                                    \
    -(void)replaceObjectAtIndex : (NSUInteger)idx withObject : (id)obj { \
        _array.set(refObj, obj, idx);                                    \
    }

#define INTEROP_IMPL_CONTAINER(refObj, baseType, containerType, objcType, wrlType, templateType) INTEROP_IMPL_VECBASE(refObj)

#define INTEROP_IMPL_VECTOR(refObj, objcType, wrlType, templateType)                                          \
    INTEROP_IMPL_CONTAINER(refObj, RTMutableArrayObj, IVector<templateType>, objcType, wrlType, templateType) \
    INTEROP_IMPL_WRITABLE_VECBASE(refObj)

#define INTEROP_IMPL_OBSVECTOR_BASE(refObj, baseType, objcType, wrlType, templateType)               \
    INTEROP_IMPL_CONTAINER(refObj, baseType, IVector<templateType>, objcType, wrlType, templateType) \
    INTEROP_IMPL_WRITABLE_VECBASE(refObj)                                                            \
    -(void)registerSelf {                                                                            \
        _array.registerSelf(refObj, self);                                                           \
    }                                                                                                \
    -(void)unregisterSelf {                                                                          \
        _array.unregisterSelf(refObj);                                                               \
    }

#define INTEROP_IMPL_OBSVECTOR(refObj, objcType, wrlType, templateType) \
    INTEROP_IMPL_OBSVECTOR_BASE(refObj, RTObservableArrayObj, objcType, wrlType, templateType)

#define INTEROP_IMPL_VECTOR_FULL(refObj, objcType, wrlType, templateType) \
    INTEROP_IMPL_VECTOR(refObj, objcType, wrlType, templateType)          \
    INTEROP_ADD_ARRAY_FASTENUM()                                          \
    -(void)addObject : (id)obj {                                          \
        [self insertObject:obj atIndex:[self count]];                     \
    }                                                                     \
    -(void)removeLastObject {                                             \
        [self removeObjectAtIndex:[self count] - 1];                      \
    }

#define INTEROP_IMPL_OBSVECTOR_FULL(refObj, objcType, wrlType, templateType)                       \
    INTEROP_IMPL_OBSVECTOR_BASE(refObj, RTObservableArrayObjFull, objcType, wrlType, templateType) \
    INTEROP_ADD_ARRAY_FASTENUM()                                                                   \
    -(void)addObject : (id)obj {                                                                   \
        [self insertObject:obj atIndex:[self count]];                                              \
    }                                                                                              \
    -(void)removeLastObject {                                                                      \
        [self removeObjectAtIndex:[self count] - 1];                                               \
    }                                                                                              \
    -(EventRegistrationToken)addObserver : (RTCollectionListener)receiver {                        \
        return [_array.getMgr() addObserver:receiver];                                             \
    }                                                                                              \
    -(void)removeObserver : (EventRegistrationToken)receiverToken {                                \
        [_array.getMgr() removeObserver:receiverToken];                                            \
    }                                                                                              \
    -(void)notify : (RTCollectionOperation)op at : (unsigned int)idx {                             \
        [_array.getMgr() notify:op value:[NSNumber numberWithUnsignedInt:idx]];                    \
    }                                                                                              \
    -(id)init {                                                                                    \
        [super init];                                                                              \
        [_array.getMgr() setOwner:self];                                                           \
        return self;                                                                               \
    }

#define INTEROP_IMPL_VECTORVIEW(refObj, objcType, wrlType, templateType) \
    INTEROP_IMPL_CONTAINER(refObj, RTArrayObj, IVectorView<templateType>, objcType, wrlType, templateType)

#define INTEROP_IMPL_VECTORVIEW_FULL(refObj, objcType, wrlType, templateType) \
    INTEROP_IMPL_VECTORVIEW(refObj, objcType, wrlType, templateType)          \
    INTEROP_ADD_ARRAY_FASTENUM()

#define INTEROP_IMPL_C_ARRAY(refObj, objcType, wrlType, templateType)                \
    INTEROP_IMPL_VECBASE(refObj)                                                     \
                                                                                     \
    -(id)initWithSize : (unsigned int)size vec : (wrlType*)vec owned : (BOOL)owned { \
        _array._count = size;                                                        \
        _array._array = vec;                                                         \
        _array._owned = owned;                                                       \
        return self;                                                                 \
    }

#define INTEROP_IMPL_ITERABLE(refObj, objcType, wrlType, templateType)                                      \
    INTEROP_IMPL_CONTAINER(refObj, RTIterableObj, IIterable<templateType>, objcType, wrlType, templateType) \
                                                                                                            \
    -(id)first {                                                                                            \
        return _array.first(refObj);                                                                        \
    }                                                                                                       \
    -(id)next {                                                                                             \
        return _array.next(refObj);                                                                         \
    }

#define INTEROP_IMPL_ITERABLE_FULL(refObj, objcType, wrlType, templateType) \
    INTEROP_ADD_ITERABLE_FASTENUM()                                         \
    INTEROP_IMPL_ITERABLE(refObj, objcType, wrlType, templateType)

//
// Mapview macros.
//
#define INTEROP_IMPL_KEYENUM(className, WRLK, WRLKT, OBJCK, WRLV)  \
    @interface className                                           \
    ##_KeyEnumerator : NSEnumerator @end                           \
                                                                   \
                       @implementation className##_KeyEnumerator { \
        RTMapViewKeyEnumerator<WRLKT, WRLK, OBJCK, WRLV> _enum;    \
    }                                                              \
    -(id)initWithMapView : (IInspectable*)map {                    \
        _enum.initWith(map);                                       \
        return self;                                               \
    }                                                              \
    -(id)nextObject {                                              \
        return _enum.nextObject();                                 \
    }                                                              \
    @end

#define INTEROP_IMPL_INITWITH()             \
    -(id)initWithMap : (IInspectable*)map { \
        [super init];                       \
        [self setComObj:map];               \
        return self;                        \
    }

#define INTEROP_IMPL_MAP_COMMON(refType, refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV, templateType)                \
    -(id)objectForKey : (id)key {                                                                                                \
        return _map.get(refObj, key);                                                                                            \
    }                                                                                                                            \
    -(id)keyEnumerator {                                                                                                         \
        std::unique_ptr<DictionaryKeyEnumeratorAdapter> adapterObj =                                                             \
            std::make_unique<DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<WRLKT, WRLK, OBJCK, WRLVT>>>();            \
        return AUTORELEASE([[RTProxiedNSDictionaryKeyEnumerator alloc] initWithMap:refObj.Get() adapter:std::move(adapterObj)]); \
    }                                                                                                                            \
    -(unsigned int)count {                                                                                                       \
        return _map.count(refObj);                                                                                               \
    }                                                                                                                            \
    -(NSArray*)allKeys {                                                                                                         \
        return _map.allKeys(refObj);                                                                                             \
    }                                                                                                                            \
    -(NSArray*)allKeysForObject : (id)obj {                                                                                      \
        return _map.allKeysFor(refObj, obj);                                                                                     \
    }                                                                                                                            \
    -(NSArray*)allValues {                                                                                                       \
        return _map.allValues(refObj);                                                                                           \
    }

#define INTEROP_IMPL_MAPVIEW(refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV) \
    INTEROP_IMPL_MAP_COMMON(RTMapViewObj, refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV, IMapView)

#define INTEROP_IMPL_MAPVIEW_INITWITH(refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV)               \
    INTEROP_IMPL_MAP_COMMON(RTMapViewObj, refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV, IMapView) \
    INTEROP_IMPL_INITWITH()

#define INTEROP_IMPL_MAPBASE(refType, refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV, templateType) \
    INTEROP_IMPL_MAP_COMMON(refType, refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV, templateType)  \
    -(void)setObject : (id)obj forKey : (id)key {                                                              \
        _map.set(refObj, key, obj);                                                                            \
    }                                                                                                          \
    -(void)setObject : (id)obj forKeyedSubscript : (id)key {                                                   \
        _map.set(refObj, key, obj);                                                                            \
    }                                                                                                          \
    -(void)removeObjectForKey : (id)key {                                                                      \
        _map.remove(refObj, key);                                                                              \
    }                                                                                                          \
    -(void)removeAllObjects {                                                                                  \
        _map.clear(refObj);                                                                                    \
    }                                                                                                          \
    -(void)removeObjectsForKeys : (NSArray*)keys {                                                             \
        _map.removeObjs(refObj, keys);                                                                         \
    }                                                                                                          \
    -(void)addEntriesFromDictionary : (NSDictionary*)otherDict;                                                \
    { _map.addAll(refObj, otherDict); }                                                                        \
    -(void)addEntriesFromDictionaryNoReplace : (NSDictionary*)otherDict;                                       \
    { _map.addNew(refObj, otherDict); }                                                                        \
    -(void)setDictionary : (NSDictionary*)otherDict;                                                           \
    {                                                                                                          \
        _map.clear(refObj);                                                                                    \
        _map.addAll(refObj, otherDict);                                                                        \
    }

#define INTEROP_IMPL_MAP(refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV) \
    INTEROP_IMPL_MAPBASE(RTMapObj, refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV, IMap)

#define INTEROP_IMPL_MAP_INITWITH(refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV)        \
    INTEROP_IMPL_MAPBASE(RTMapObj, refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV, IMap) \
    INTEROP_IMPL_INITWITH()

#define INTEROP_IMPL_OBSMAP(refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV)                        \
    INTEROP_IMPL_MAPBASE(RTObservableMapObj, refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV, IMap) \
    INTEROP_IMPL_INITWITH()                                                                                   \
    -(void)registerSelf {                                                                                     \
        _map.registerSelf(refObj, self);                                                                      \
    }                                                                                                         \
    -(void)unregisterSelf {                                                                                   \
        _map.unregisterSelf(refObj);                                                                          \
    }

#define INTEROP_IMPL_OBSMAP_FULL(refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV)                       \
    INTEROP_IMPL_MAPBASE(RTObservableMapObjFull, refObj, className, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV, IMap) \
    -(void)registerSelf {                                                                                         \
        _map.registerSelf(refObj, self);                                                                          \
    }                                                                                                             \
    -(void)unregisterSelf {                                                                                       \
        _map.unregisterSelf(refObj);                                                                              \
    }                                                                                                             \
    -(EventRegistrationToken)addObserver : (RTCollectionListener)receiver {                                       \
        return [_map.getMgr() addObserver:receiver];                                                              \
    }                                                                                                             \
    -(void)removeObserver : (EventRegistrationToken)receiverToken {                                               \
        [_map.getMgr() removeObserver:receiverToken];                                                             \
    }                                                                                                             \
    -(void)notify : (RTCollectionOperation)op atKey : (id)key {                                                   \
        [_map.getMgr() notify:op value:key];                                                                      \
    }                                                                                                             \
    -(id)init {                                                                                                   \
        [super init];                                                                                             \
        [_map.getMgr() setOwner:self];                                                                            \
        return self;                                                                                              \
    }

#define INTEROP_IMPL_KVP(refObj, WRLK, WRLKT, WRLV, WRLVT, OBJCK, OBJCV) \
    -(id)key {                                                           \
        return kvp.getKey(refObj);                                       \
    }                                                                    \
    -(id)value {                                                         \
        return kvp.getValue(refObj);                                     \
    }

// Do not derive from this class, as there is no virtual destructor.
// This was done to maintain vtable parity with IReference<T> IInspectable type.
// Base class IInspectable gives us a valid vtable, to which we can append our methods.
// Note: we cannot inherit from InspectableClassBase<T>, as it expects the template
// type T to be IInspectable, unfortunately our event handlers are of type IUnknown.
template <typename T>
class RTProxiedEventHandler final : public IInspectable {
    ComPtr<T> _value;
    IID _iid;
    ULONG _ulRefs = 1;

public:
    // Factory not required as we are not truly a runtime class.
    RTProxiedEventHandler(T* val, IID id) : _value(val), _iid(id){};

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(_In_ REFIID id, _COM_Outptr_ void** ppv) override {
        if (nullptr == ppv) {
            return E_INVALIDARG;
        }

        if (id == IID_IUnknown || id == _iid) {
            *ppv = this;
        } else {
            *ppv = nullptr;
            return E_NOINTERFACE;
        }

        ((IUnknown*)(*ppv))->AddRef();

        return S_OK;
    }

    virtual ULONG STDMETHODCALLTYPE AddRef() override {
        return InterlockedIncrement(&_ulRefs);
    }

    virtual ULONG STDMETHODCALLTYPE Release() override {
        unsigned curr = InterlockedDecrement(&_ulRefs);
        if (curr == 0) {
            delete this;
        }

        return curr;
    }

    virtual HRESULT STDMETHODCALLTYPE GetIids(ULONG* iidCount, IID** iids) override {
        static IID resultIIDs[] = { IID_IUnknown, IID_IInspectable, __uuidof(T) };
        *iidCount = 3;
        *iids = resultIIDs;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetRuntimeClassName(HSTRING* out) override {
        return WindowsCreateString(L"RTProxiedEventHandler", ::wcslen(L"RTProxiedEventHandler"), out);
    }

    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE get_Value(T** val) {
        *val = _value.Get();
        return S_OK;
    }
};

#undef LOGTYPE
#undef ABITYPE
