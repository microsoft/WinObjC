# Windows Bridge for iOS

## **DEV DESIGN SPECIFICATION: \[Foundation\] Update CoreFoundation**

### Feature Summary

In late November of 2015, Apple chose to open source the Swift language runtime under a permissible Apache license. It is currently hosted at [*https://github.com/Apple/*](https://github.com/Apple/). As a part of this open source project, Apple additionally open sourced a significant portion of the foundational libraries on which many Swift, and Objective-C, APIs depend. Chief among these libraries is CoreFoundation. This document describes the design, approach, and methodology for porting this code to the Windows Bridge for iOS.

### Technology/Architecture Decisions

CoreFoundation is a critical library that underpins a large chunk of the public APIs with which the Windows Bridge for iOS needs to be interoperable. In order to provide this interoperability, either the library needs to be written from scratch (the current implementation) or an existing open source version needs to be integrated into the project. This document discusses the latter approach.

### Design

####1.  Layout

In order to most easily integrate with the existing iOS bridge structure while also allowing easy merging with the Apple GitHub repository, the below source layout is used. This layout encompasses three main components: a "pristine" fork of the Apple repository, a "subtree" of the repository in the WinObjC repository, and a copy of public headers. In order to take new changes from the Apple repository, the fork is simply pulled like any regular git repo and after any rebasing / merging the results are simply copied over to the "subtree" in the WinObjC repo. Any modifications made by the team will be periodically copied back to the fork to lessen merge conflicts and provide the ability to contribute back to Apple's project if desired. In order to match the Windows Bridge for iOS source layout, a prebuild step copies the public headers from the "subtree" into the public includes folder. This overall approach allows relatively easy integration with Apple's repo while providing some isolation and adding no further complication to a dev's day to day operation. If frequent merges with Apple's repo become problematic, a formal "submodule" or similar solution could be investigated.

<img src="./media/image1.png" width="490" height="401" />

####2.  Modifications

Though Apple opened sourced CoreFoundation and it already includes many "Windows specific" code paths (likely used in iTunes etc), many modifications were made in order to build with the Windows Bridge for iOS. Because iTunes and other Apple software on Windows are traditional Win32 applications, the CoreFoundation code uses many Win32 calls that are disallowed from inside of an app container like reading environment variables, the registry, win32 file access, etc. Because of this, many modifications will need to be made to rewrite those portions using AppContainer approved APIs or other workarounds provided. Moreover, the Apple CoreFoundation library assumes the existence of many platform specific libraries (like icu, libdispatch, mach, libkern, etc) that the Windows Bridge for iOS either doesn't have or only has some portions of. In order to provide full functionality, these libraries need to be implemented or newer versions are needed.
In order to easily track all modifications needed to get CoreFoundation to build, a **WINOBJC** comment has been added along with the original code. Each instance will need to be investigated by an area expert to understand the impact and possible mitigations.

####3.  Bridging

A key component of the CoreFoundation module is the notion of “Toll Free Bridged” classes that interoperate with certain Foundation module counterparts. Below is a table of the status of bridged classes and a detailed design of the bridging process.

 Core Foundation Type | Foundation Class | Bridging Complete 
------------------------------|---------------------------|------------------
 CFArrayRef                   | NSArray                   | YES              
 CFAttributedStringRef        | NSAttributedString        | YES              
 CFCalendarRef                | NSCalendar                | YES              
 CFCharacterSetRef            | NSCharacterSet            | YES              
 CFDataRef                    | NSData                    | YES              
 CFDateRef                    | NSDate                    | YES              
 CFDictionaryRef              | NSDictionary              | YES              
 CFErrorRef                   | NSError                   | YES              
 CFLocaleRef                  | NSLocale                  | YES              
 CFMutableArrayRef            | NSMutableArray            | YES              
 CFMutableAttributedStringRef | NSMutableAttributedString | YES              
 CFMutableCharacterSetRef     | NSMutableCharacterSet     | YES              
 CFMutableDataRef             | NSMutableData             | YES              
 CFMutableDictionaryRef       | NSMutableDictionary       | YES              
 CFMutableSetRef              | NSMutableSet              | YES              
 CFMutableStringRef           | NSMutableString           | YES              
 CFNumberRef                  | NSNumber                  | YES              
 CFReadStreamRef              | NSInputStream             | **BACKLOG**           
 CFRunLoopTimerRef            | NSTimer                   | **BACKLOG**           
 CFSetRef                     | NSSet                     | YES              
 CFStringRef                  | NSString                  | YES              
 CFTimeZoneRef                | NSTimeZone                | **BACKLOG**           
 CFURLRef                     | NSURL                     | YES              
 CFWriteStreamRef             | NSOutputStream            | **BACKLOG**           

##### Overview - NSString Bridging Example

The below diagram shows the full class hierarchy for one of the most complicated Toll Free Bridged / Class Clustered Interfaces: NSString.

<img src="./media/image2.png" width="598" height="409" />

###### NSObject

Base or "Root" class in Objective-C. By convention, all classes should derive from NSObject. Has one ivar, **Class isa**, that allows for type introspection / correct method dispatch etc.

###### NSString

Abstract or Interface class. This class defines a few "abstract" or "primitive" methods (-length and -getCharacterAtIndex for NSString) that derived implementations **must implement.** Similar to interfaces in other languages, this class defines no ivars itself. All methods are implemented in terms of the primitive methods. Because of this, derived implementation are totally responsible for the "backing store" / "implementation details" of the class. Unlike other languages though, Objective-C has no formal concept of interfaces and thus derived classes failing to implement the "abstract"/"primitive" methods is only detectable at runtime (interface class will throw).

###### NSMutableString

Mutable counterpart to NSString. Adds additional primitive methods for mutability (e.g. -appendString).

###### NSStringPlaceholder

A "factory" singleton class responsible for returning initialized instances of \_NSCFString. Objective-C uses a two stage allocation and initialization (similar to COM/WRL's initialization pattern). CoreFoundation, however, uses a single Creation method that returns a fully formed object. Additionally, Objective-C uses a creation syntax for its bridged objects like: **\[\[NSString alloc\] initWithBytes: … \]**; This is roughly equivalent of expecting something like IFoo = new IFoo( … ); in a language like Java. Directly creating an instance of an interface logically can't happen like this. To get around this, placeholder or factory objects are used to perform the correct initialization and return a newly allocated implementation of that interface. This is conceptually similar to the well known 'factory pattern'. A full example of this class's use can be found in the below sequence diagrams.

###### NSMutableStringPlaceholder

The mutable counterpart to NSStringPlaceholder. Because only one CoreFoudation typeId exists for CFString (there is no real difference between a CFStringRef and CFMutableStringRef, they both point to the same class object), a second placeholder singleton is needed to perform the correct mutable initialization. A full example can be found below.

###### NSConstantString

Derived implementation of NSString used to handle the @"Hello World" syntax. @"…" is a special syntax that uses a compiler flag to instruct the compiler what class to stamp out for a constant string. This class has two ivars: c\_string and len. More information on the specifics of constant string use in libObjC2 and Clang can be found at: [*https://gcc.gnu.org/onlinedocs/gcc/Constant-string-objects.html*](https://gcc.gnu.org/onlinedocs/gcc/Constant-string-objects.html). For the purposes of this design document, NSConstantString can be thought of as any derived implementation of NSString, similar to what an app developer may choose to do.

###### \_NSTemporaryRootObject

Temporary root class that acts as a "duplicate" of NSObject in terms of layout. Because \_NSCFString lives in CoreFoundation.dll but logically should derive from classes in Foundation.dll, this temporary class is used until Foundation.dll is loaded and the hierarchy is reseated appropriately. A further discussion of why this is needed can be found in the description of \_NSCFString and the "Class Initialization" section of the detailed design.

###### \_NSCFString

Bridged implementation of NSMutableString. This class operates by casting its self pointer to a CFStringRef and calling the appropriate CF methods. Because of the fact that \_NSCFString is the "concrete" implementation for both NSString and NSMutableString, it must know about its mutability or the CFMethods must respond appropriately.

Additionally, due to the existence of static CFStrings (for example the version number) in CoreFoundation.dll and the need to have those static strings bridged, the class to which to bridge them must exist at CoreFoundation's static initialization time (see the "Class Initialization" section of the detailed design for more information on this process). Because of this, the bridged Objective-C class for NSString must live in CoreFoundation. This is **not** the case for many other bridged classes (no publicly accessible static instances in CF) and makes NSString significantly more complicated than most cases.

##### Bridging Detailed Design

At its heart, Toll Free bridging works via the identical layout of the "isa" field for both Foundation (Objective-C) and CoreFoundation classes. Namely, every CoreFoundation class shares the same base struct, \_\_CFRuntimeBase:
 
```objc++
typedef struct __CFRuntimeBase {
uintptr_t _cfisa;
uint8_t _cfinfo[4];

#if __LP64__
uint32_t _rc;
#endif

} CFRuntimeBase;
```

This means that any instance of a CF class will have an isa pointer at offset 0, identical to an Objective-C class. The only catch is getting this "isa" to match that of the correct Objective-C class so that it can masquerade as it at runtime (the "isa" field is used by the runtime to determine how to dispatch messages to objects).

###### Class Initialization

In order to correctly set the "isa" in a CFRuntime class, two steps are required, registering a bridge class and creating the class.
  
  1.  Registering the bridge class

  By calling **\_CFRuntimeBridgeTypeToClass** (usually from the +load of the Objective-C bridge counterpart), the CFTypeID is mapped to an Objective-C isa in a static table.

  2. Creating the Class

  When a runtime class is created via **\_CFRuntimeCreateInstance** (usually called internally from a public creation method), this static table is referenced and the isa of the instance is filled in. If no isa is registered, then the instance simply has a null isa (note that this is distinct from a nil isa). A class must be registered before the instance is created which creates some ordering issues with static instances of classes like CFStrings and CFNumbers. To handle this issue, the Objective-C bridge is moved to CoreFoundation so that it can be referred to at static initialization time.

Below are call/sequence diagrams illustrating how a bridge class is created.

<img src="./media/image3.png" width="636" height="354" />

###### Bridged Calls

 Bridged calls can occur in two directions: either calling a CoreFoundation function on an Objective-C object or calling Objective-C messages on a CoreFoundation object. In both instances the CoreFoundation method for that functionality is used and a few special macros are used to handle the appropriate behavior:
  
```objc++
#define CF_OBJC_FUNCDISPATCHV(type, ret, obj, ...) do { \
    if ( CF_IS_OBJC(type, obj) ) { \
        return (ret)CF_OBJC_CALLV(obj, ##__VA_ARGS__); \
    } \
} while (0)

#define CF_OBJC_CALLV(obj, ...) [(obj) __VA_ARGS__]
#define CF_IS_OBJC(typeID, obj) ( \
    (!obj) || \
    ((((CFRuntimeBase*)(obj))->_cfisa != 0) && \
    (((CFRuntimeBase*)(obj))->_cfisa != (uintptr_t)(&_OBJC_CLASS__NSCFString)) && \
    (__CFISAForTypeID(typeID) != ((CFRuntimeBase*)(obj))->_cfisa) && \
    (![(id)(((CFRuntimeBase*)(obj)))->_cfisa isSubclassOfClass:(Class)__CFISAForTypeID(typeID)])))
```


**CF\_OBJC\_FUNCDISPATCHV** - calls into Objective-c if the object being used is Objective-C. Otherwise it falls through into the CF mplementation

**CF\_OBJC\_CALLV** - simply calls Objective-C function.

**CF\_IS\_OBJC** - checks to see if an object is Objective-C or not. To do this it checks the bridged class "isa" for the typeID and lso makes a subclass check for KVO interoperability.

The \_OBJC\_CLASS\_\_NSCFString check is needed for static ordering issues between registering the string bridge class and using a static instance of it.

<img src="./media/image4.png" width="648" height="345" />

###### Memory Management

Because Bridged classes are actually allocated and initialized via CoreFoundation creation methods, core foundation is responsible for the memory management of those objects. The location of the reference count, for instance, does not match with that of an Objective-C class, only the "isa" field matches. To account for this, a bridged class like \_NSCF must override all memory management operations to use the CF equivalents like CFRetain, CFRelease, CFAutorelease (all of which are bridged functions that use similar methods above but with the typeID so they are slower).
