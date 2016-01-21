// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFPlugIn_Factory.h
	Copyright (c) 1999-2015, Apple Inc.  All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFPLUGIN_FACTORY__)
#define __COREFOUNDATION_CFPLUGIN_FACTORY__ 1

#include "CFBundle_Internal.h"

CF_EXTERN_C_BEGIN

typedef struct __CFPFactory *_CFPFactoryRef;

extern _CFPFactoryRef _CFPFactoryCreate(CFAllocatorRef allocator, CFUUIDRef factoryID, CFPlugInFactoryFunction func);
extern _CFPFactoryRef _CFPFactoryCreateByName(CFAllocatorRef allocator, CFUUIDRef factoryID, CFPlugInRef plugIn, CFStringRef funcName);

extern _CFPFactoryRef _CFPFactoryFind(CFUUIDRef factoryID, Boolean enabled);

extern CFUUIDRef _CFPFactoryCopyFactoryID(_CFPFactoryRef factory);
extern CFPlugInRef _CFPFactoryCopyPlugIn(_CFPFactoryRef factory);

extern void *_CFPFactoryCreateInstance(CFAllocatorRef allocator, _CFPFactoryRef factory, CFUUIDRef typeID);
extern void _CFPFactoryDisable(_CFPFactoryRef factory);

extern void _CFPFactoryFlushFunctionCache(_CFPFactoryRef factory);

extern void _CFPFactoryAddType(_CFPFactoryRef factory, CFUUIDRef typeID);
extern void _CFPFactoryRemoveType(_CFPFactoryRef factory, CFUUIDRef typeID);

extern Boolean _CFPFactorySupportsType(_CFPFactoryRef factory, CFUUIDRef typeID);
extern CFArrayRef _CFPFactoryFindCopyForType(CFUUIDRef typeID);

/* These methods are called by CFPlugInInstance when an instance is created or destroyed.  If a factory's instance count goes to 0 and the factory has been disabled, the factory is destroyed. */
extern void _CFPFactoryAddInstance(_CFPFactoryRef factory);
extern void _CFPFactoryRemoveInstance(_CFPFactoryRef factory);

CF_EXTERN_C_END

#endif /* ! __COREFOUNDATION_CFPLUGIN_FACTORY__ */

// clang-format on
