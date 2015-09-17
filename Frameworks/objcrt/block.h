//******************************************************************************
//
// Copyright (c) 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015
//   Jonathan Schleifer <js@webkeks.org>. All rights reserved.
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

#include "UIKit/UIKit.h"

typedef struct of_block_literal_t {
    Class isa;
    int flags;
    int reserved;
    void (*invoke)(void *, ...);
    struct of_block_descriptor_t {
        unsigned long reserved;
        unsigned long size;
        void (*copy_helper)(void *dest, void *src);
        void (*dispose_helper)(void *src);
        const char *signature;
    } *descriptor;
} of_block_literal_t;

@interface NSBlock: NSObject
@end

@interface NSStackBlock: NSBlock
@end

@interface NSGlobalBlock: NSBlock
@end

@interface NSMallocBlock: NSBlock
@end

#ifdef __cplusplus
extern "C" {
#endif
extern OBJCRT_EXPORT void* _Block_copy(const void*);
extern OBJCRT_EXPORT void _Block_release(const void*);
#ifdef __cplusplus
}
#endif

#ifndef Block_copy
# define Block_copy(x) ((__typeof__(x))_Block_copy((const void*)(x)))
#endif
#ifndef Block_release
# define Block_release(x) _Block_release((const void*)(x))
#endif
