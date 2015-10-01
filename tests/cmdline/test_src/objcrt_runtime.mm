#import <Foundation/Foundation.h>
#include <objc/runtime.h>
#include <exception>

//#pragma comment(linker, "/INCLUDE:Foundation.dll!_OBJC_CLASS_NSArray")

@interface TestCaseBaseIvars: NSObject {
	void *ptr;
}
@end
@implementation TestCaseBaseIvars
- (id)init {
	if((self = [super init]) != nil) {
		ptr = (void*)0x101010;
	} return self;
}
- (BOOL)validate {
	return ptr == (void*)0x101010;
}
@end

struct ClassTrailer {
	void *ptr2;
};

@interface TestCaseBase: NSObject
+ (void)setGlobal:(int)g;
+ (int)testcase3:(int)x;
- (int)testcase3:(int)x;
@end

static int _tcbGlobal;
@implementation TestCaseBase
+ (void)setGlobal:(int)g {
	_tcbGlobal = g;
}
@end

int tc3MetaImp(id, SEL, int) {
	return 100;
}
int tc3Imp(id, SEL, int) {
	return 200;
}

#if defined(ANSI_COLOR)
#define SGR_RED "\033[1;31m"
#define SGR_GREEN "\033[1;32m"
#define SGR_RESET "\033[0m"
#else
#define SGR_RED
#define SGR_GREEN
#define SGR_RESET
#endif

bool globalFailure = false;

void perform(const char *what, bool (^block)(), bool flipbit = false) {
	bool b = false;
	const char *xcp = NULL;
	try {
		b = block();
	} catch(std::exception &e) {
		xcp = strdup(e.what());
		b = false;
	} catch(...) {
		xcp = "unknown?";
		b = false;
	}
	printf(" - ");
	if(flipbit != b) {
		printf(SGR_GREEN "PASSED" SGR_RESET);
	} else {
		globalFailure = true;
		printf(SGR_RED "FAILED");
		if(xcp) {
			printf(" (" SGR_RESET "%s" SGR_RED ")", xcp);
		}
	}
	printf(": %s\n", what);
}

int main(int argc, char *argv[]) {
	[NSArray alloc]; // temp hack, work around Foundation.dll being ignored
	//printf("%s\n", [[[NSObject new] description] UTF8String]);
	printf("OBJCRT runtime subclassing test:\n");
	
	perform("PREREQ: NSObject exists", ^bool{
		return objc_getClass("NSObject") != Nil;
	});
	perform("can allocate a subclass", ^bool{
		Class k = objc_allocateClassPair(objc_getClass("NSObject"), "TESTCASE1", 0);
		if(!k) {
			return false;
		}
		return true;
	});
	perform("can allocate and register a subclass", ^bool{
		Class k = objc_allocateClassPair(objc_getClass("NSObject"), "TESTCASE2", 0);
		if(!k) {
			return false;
		}
		objc_registerClassPair(k);
		return true;
	});
	perform("cannot allocate a class pair for an existing class name", ^bool{
		Class k = objc_allocateClassPair(objc_getClass("NSObject"), "TESTCASE2", 0);
		return k == nil;
	});
	perform("can not look up a subclass that was only allocated", ^bool{
		Class k = nil;
		try {
			k = objc_getClass("TESTCASE1");
		} catch(...) {
		}
		return k == Nil;
	});
	perform("can look up a previously registered subclass", ^bool{
		Class k = objc_getClass("TESTCASE2");
		return k != Nil;
	});
	perform("can allocate a registered subclass", ^bool{
		Class k = objc_getClass("TESTCASE2");
		return k != Nil && [k alloc] != nil;
	});
	perform("can call NSObject methods on a previously registered subclass", ^bool{
		Class k = objc_getClass("TESTCASE2");
		if(!k) return false;
		id instance = [[k alloc] init];
		if(!instance) return false;
		return [instance description] != nil;
	});
	perform("can subclass a locally-defined class", ^bool{
		Class k = objc_allocateClassPair(objc_getClass("TestCaseBase"), "TESTCASE3", 0);
		objc_registerClassPair(k);
		return k != Nil;
	});
	perform("can call locally-defined class method and see results", ^bool{
		Class k = objc_getClass("TESTCASE3");
		[k setGlobal:10];
		return _tcbGlobal == 10;
	});
	perform("can add a class method to a class", ^bool{
		Class k = objc_getClass("TESTCASE3");
		return class_addMethod(object_getClass(k), @selector(testcase3:), (IMP)tc3MetaImp, "i@:");
	});
	perform("can add a instance method to a class", ^bool{
		Class k = objc_getClass("TESTCASE3");
		return class_addMethod(k, @selector(testcase3:), (IMP)tc3Imp, "i@:");
	});
	perform("can call a previously-added class method on a class", ^bool{
		Class k = objc_getClass("TESTCASE3");
		return [k testcase3:0] == 100;
	});
	perform("can call a previously-added instance method on a class", ^bool{
		Class k = objc_getClass("TESTCASE3");
		return [[k alloc] testcase3:0] == 200;
	});

	perform("can NOT call a method added on a subclass on its superclass", ^bool{
		[TestCaseBase testcase3:10];
		[[TestCaseBase alloc] testcase3:10];
		return false;
	}, true);

	perform("can subclass a runtime subclass", ^bool{
		Class k = objc_allocateClassPair(objc_getClass("TESTCASE3"), "TESTCASE4", 0);
		if(!k) return false;
		objc_registerClassPair(k);
		return true;
	});
	perform("can call a previously-added class method on that class", ^bool{
		Class k = objc_getClass("TESTCASE4");
		return [k testcase3:0] == 100;
	});
	perform("can call a previously-added instance method on that class", ^bool{
		Class k = objc_getClass("TESTCASE4");
		return [[k alloc] testcase3:0] == 200;
	});

	perform("can subclass with indexed ivars", ^bool{
		Class k = objc_allocateClassPair([TestCaseBaseIvars class], "TESTCASE5", sizeof(struct ClassTrailer));
		if(!k) return false;
		objc_registerClassPair(k);
		return true;
	});
	perform("can access indexed ivars", ^bool{
		Class k = objc_getClass("TESTCASE5");
		void *iiv = object_getIndexedIvars((id)k);
		if(!iiv) return false;
		if(iiv == k) return false;
		return true;
	});
	perform("indexed ivars do not damage instance", ^bool{
		Class k = objc_getClass("TESTCASE5");
		TestCaseBaseIvars *instance = objc_allocateObject(k, sizeof(ClassTrailer));
		instance = [instance init];

		ClassTrailer *iiv = (ClassTrailer*)object_getIndexedIvars((id)instance);
		if(!iiv) return false;
		if((void*)iiv == instance) return false;

		iiv->ptr2 = (void*)0x202020;
		return [instance validate];
	});
	return globalFailure ? 1 : 0;
}

