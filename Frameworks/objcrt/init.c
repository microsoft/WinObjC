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

#include "runtime.h"
#include "runtime-private.h"

int _objc_methtype;

OBJCRT_EXPORT void __objc_exec_class(struct objc_abi_module* module) {
    objc_global_mutex_lock();

    objc_register_all_selectors(module->symtab);
    objc_register_all_classes(module->symtab);
    objc_register_all_categories(module->symtab);
    objc_init_static_instances(module->symtab);

    objc_global_mutex_unlock();
}

void objc_exit(void) {
    objc_global_mutex_lock();

    objc_free_all_categories();
    objc_free_all_classes();
    objc_free_all_selectors();
    objc_sparsearray_cleanup();

    objc_global_mutex_unlock();
}
