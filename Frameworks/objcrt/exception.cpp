#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <malloc.h>
#include <string>
#include "runtime.h"

typedef struct {
    unsigned int flags;
    const char* type;
    int mdisp;
    int pdisp;
    int vdisp;
    int size;
    void* copyFunction;
} __ObjC_CatchableType;

typedef struct {
    int count;
    __ObjC_CatchableType* types[0];
} __ObjC_CatchableTypeArray;

extern "C" __declspec(dllexport) void objc_exception_throw(void* exception) {
    int typeCount = 0;

    //  Get count of all types in exception
    Class curType = object_getClass((id)exception);
    while (curType != nil) {
        typeCount++;

        curType = class_getSuperclass(curType);
    }

    typeCount++; //  For id

    __ObjC_CatchableTypeArray* exceptTypes =
        (__ObjC_CatchableTypeArray*)_alloca(sizeof(__ObjC_CatchableTypeArray) + sizeof(__ObjC_CatchableType*) * typeCount);

    //  Add exception type and all base types to throw information
    typeCount = 0;
    curType = object_getClass((id)exception);
    while (curType != nil) {
        exceptTypes->types[typeCount] = (__ObjC_CatchableType*)_alloca(sizeof(__ObjC_CatchableType));
        memset(exceptTypes->types[typeCount], 0, sizeof(__ObjC_CatchableType));
        exceptTypes->types[typeCount]->flags = 1;
        exceptTypes->types[typeCount]->mdisp = 0;
        exceptTypes->types[typeCount]->pdisp = -1;
        exceptTypes->types[typeCount]->vdisp = 0;
        exceptTypes->types[typeCount]->type = (const char*)alloca(32);
        memset((void*)exceptTypes->types[typeCount]->type, 0, 32);
        memcpy((char*)exceptTypes->types[typeCount]->type, class_getName(curType), strlen(class_getName(curType)));
        exceptTypes->types[typeCount]->size = 4;
        typeCount++;

        curType = class_getSuperclass(curType);
    }

    //  Add id
    exceptTypes->types[typeCount] = (__ObjC_CatchableType*)_alloca(sizeof(__ObjC_CatchableType));
    memset(exceptTypes->types[typeCount], 0, sizeof(__ObjC_CatchableType));
    exceptTypes->types[typeCount]->flags = 1;
    exceptTypes->types[typeCount]->mdisp = 0;
    exceptTypes->types[typeCount]->pdisp = -1;
    exceptTypes->types[typeCount]->vdisp = 0;
    exceptTypes->types[typeCount]->type = (const char*)alloca(32);
    memset((void*)exceptTypes->types[typeCount]->type, 0, 32);
    exceptTypes->types[typeCount]->size = 4;
    typeCount++;

    exceptTypes->count = typeCount;

    _ThrowInfo ti = { 0, NULL, NULL, (_CatchableTypeArray*)exceptTypes };

    _CxxThrowException(&exception, &ti);
}

static void formatExceptionMessage(std::string& str, const char* format, va_list va) {
    int len = _vscprintf(format, va);

    if (len > 0) {
        str.resize(len + 1);

        _vsnprintf_s(&str[0], str.size(), str.size(), format, va);
    }
}

extern "C" void objc_RaiseNotImplementedException(const char* format, ...) {
    va_list va;

    va_start(va, format);
    std::string errorMsg;
    formatExceptionMessage(errorMsg, format, va);
    va_end(va);

    std::wstring wstr(errorMsg.begin(), errorMsg.end());

    throw ref new Platform::NotImplementedException(ref new Platform::String(wstr.data()));
}

extern "C" void objc_RaiseGeneralFailureException(const char* format, ...) {
    va_list va;

    va_start(va, format);
    std::string errorMsg;
    formatExceptionMessage(errorMsg, format, va);
    va_end(va);

    std::wstring wstr(errorMsg.begin(), errorMsg.end());

    throw ref new Platform::FailureException(ref new Platform::String(wstr.data()));
}
