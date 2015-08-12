#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <string.h>
#include "runtime.h"

typedef struct
{
    unsigned int flags;
    const char *type;
    int mdisp;
    int pdisp;
    int vdisp;
    int size;
    void *copyFunction;
} __ObjC_CatchableType;

typedef struct
{
    int count;
    __ObjC_CatchableType *types[0];
} __ObjC_CatchableTypeArray;

extern "C" __declspec(dllexport) void objc_exception_throw(void *exception)
{
    int typeCount = 0;

    //  Get count of all types in exception
    Class curType = object_getClass((id) exception);
    while (curType != nil) {
        typeCount++;

        curType = class_getSuperclass(curType);
    }

    typeCount++; //  For id

    __ObjC_CatchableTypeArray *exceptTypes = (__ObjC_CatchableTypeArray *)_alloca(sizeof(__ObjC_CatchableTypeArray) + sizeof(__ObjC_CatchableType *) * typeCount);

	//  Add exception type and all base types to throw information
    typeCount = 0;
    curType = object_getClass((id)exception);
    while (curType != nil) {
        exceptTypes->types[typeCount] = (__ObjC_CatchableType *)_alloca(sizeof(__ObjC_CatchableType));
        memset(exceptTypes->types[typeCount], 0, sizeof(__ObjC_CatchableType));
        exceptTypes->types[typeCount]->flags = 1;
        exceptTypes->types[typeCount]->mdisp = 0;
        exceptTypes->types[typeCount]->pdisp = -1;
        exceptTypes->types[typeCount]->vdisp = 0;
        exceptTypes->types[typeCount]->type = (const char *) alloca(32);
        memset((void *) exceptTypes->types[typeCount]->type, 0, 32);
        memcpy((char *)exceptTypes->types[typeCount]->type, class_getName(curType), strlen(class_getName(curType)));
        exceptTypes->types[typeCount]->size = 4;
        typeCount++;

        curType = class_getSuperclass(curType);
    }

    //  Add id
    exceptTypes->types[typeCount] = (__ObjC_CatchableType *)_alloca(sizeof(__ObjC_CatchableType));
    memset(exceptTypes->types[typeCount], 0, sizeof(__ObjC_CatchableType));
    exceptTypes->types[typeCount]->flags = 1;
    exceptTypes->types[typeCount]->mdisp = 0;
    exceptTypes->types[typeCount]->pdisp = -1;
    exceptTypes->types[typeCount]->vdisp = 0;
    exceptTypes->types[typeCount]->type = (const char *)alloca(32);
    memset((void *)exceptTypes->types[typeCount]->type, 0, 32);
    exceptTypes->types[typeCount]->size = 4;
    typeCount++;

    exceptTypes->count = typeCount;

    _ThrowInfo ti = 
    {
     0,
     NULL,
     NULL,
     (_CatchableTypeArray *) exceptTypes
    };

    _CxxThrowException(&exception, &ti);
}
