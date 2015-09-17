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

#include <winobjc/winobjc.h>
#include "runtime.h"
#include <Windows.h>
#include <winstring.h>
#include <assert.h>
#include "winrt-interop.h"

extern "C" struct winrt_isa _NSConcreteGlobalBlock;

BOOL object_isWinRT(id obj)
{
    struct winrt_isa *isa = *((winrt_isa **) obj);

    /* [HACK: blamb] 
     * 
     * Global block are emitted by the compiler as const structs, which can't directly
     * address variables imported from DLLs.  The isa member of the emitted block
     * will point to the DLL import table, which is patched with the actual address
     * of the imported symbol.  The loader (afaik) can't/won't patch
     * the isa member when it gets resolved at load time.
     *
     * To get around this, we check to see if the isa of the Class of the object
     * points to _NSConcreteGlobalBlock.  If it does, we'll do the extra deref here 
     * to get the object of the class. 
     */

    if ( (Class) ((Class) isa)->isa == (Class) &_NSConcreteGlobalBlock ) {
        return false;
    }

    if ( isa->IW_IInspectable[1] != (void *) _winrt_inspect_AddRef) {
        return true;
    } else {
        return false;
    }
}

IMP object_getWinRTImp(id obj, const char *selName)
{
    //printf("Looking up %s\n", selName);
    return NULL;
}

namespace winobjc 
{
    const IID IID_IIWSendMsg = { 0xE7A2DBED, 0x6156, 0x463E,{ 0xAD, 0xDC, 0x01, 0x7D, 0x4D, 0xD4, 0x37, 0x26 } };
};

unsigned int __stdcall _winrt_inspect_QueryInterface(void *thisptr, void*riid, void **ppvObject)
{
    if ( memcmp(riid, &winobjc::IID_IIWSendMsg, sizeof(UUID)) == 0) {
        *ppvObject = (void *)(((uintptr_t)thisptr));
        return S_OK;
    }
    /*
    if ( memcmp(riid, &IID_IInspectable, sizeof(UUID)) == 0) {
        *ppvObject = (void *)(((uintptr_t)thisptr));
        return S_OK;
    }
    */
    *ppvObject = NULL;
    return E_NOINTERFACE;
}

unsigned int __stdcall _winrt_inspect_AddRef(void *thisptr)
{
    objc_retain_internal_ref((id) thisptr);
    return 1;
}

unsigned int __stdcall _winrt_inspect_Release(void *thisptr)
{
    objc_release_internal_ref((id) thisptr);
    return 1;
}

unsigned int __stdcall _winrt_inspect_GetIids(void *thisptr, unsigned long *iidCount, void **iids)
{
    *iidCount = 0;
    return 0;
}

unsigned int __stdcall _winrt_inspect_GetRuntimeClassName(void *thisptr, void**name)
{
    const char *objCName = class_getName(object_getClass((id) thisptr));

    int i, len = strlen(objCName);
    wchar_t wideObjCName[len + 1];
    for ( i = 0; i < len ; i ++ ) wideObjCName[i] = objCName[i];
    wideObjCName[i] = 0;

    WindowsCreateString(wideObjCName, len, (HSTRING *) name);

    return 0;
}

unsigned int __stdcall _winrt_inspect_GetTrustLevel(void *thisptr, int *TrustLevel)
{
    *TrustLevel = 0;
    return 0;
}

unsigned int __stdcall _winrt_iwmsgsend_MsgSend(void *thisptr, const char *selName, ...)
{
    SEL sel = sel_registerName(selName);
    [(id) thisptr performSelector: sel];
    return 0;
}

void winobjc::Id::Set(void *idPtr)
{
    void *oldPtr = _idPtr;
    _idPtr = idPtr;
    if ( _idPtr ) {
        unsigned int (__stdcall *_iw_AddRef)(void *) = (unsigned int (__stdcall *)(void *)) (*((void***) idPtr))[1];
        _iw_AddRef(idPtr);
    }
    if ( oldPtr ) {
        unsigned int (__stdcall *_iw_Release)(void *) = (unsigned int (__stdcall *)(void *)) (*((void***) oldPtr))[2];
        _iw_Release(oldPtr);
    }
}

winobjc::Id::Id()
{
    _idPtr = NULL;
}
winobjc::Id::Id(void *idPtr)
{
    _idPtr = NULL;
    Set(idPtr);
}
winobjc::Id::Id(Id &&copy)
{
    _idPtr = NULL;
    Set(copy._idPtr);
}
winobjc::Id::~Id()
{
    Set(NULL);
}

winobjc::Id& winobjc::Id::operator =(const Id &val)
{
    Set(val._idPtr);
    return *this;
}
