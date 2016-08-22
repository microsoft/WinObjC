#pragma once

enum return_type {
	RETURN_TYPE_NONE,
	RETURN_TYPE_SINT8,
	RETURN_TYPE_UINT8,
	RETURN_TYPE_SINT16,
	RETURN_TYPE_UINT16,
	RETURN_TYPE_INT32, // Only one: no need to sign-extend
	RETURN_TYPE_INT64,
	RETURN_TYPE_POINTER,
	RETURN_TYPE_FLOAT,
	RETURN_TYPE_DOUBLE,
	RETURN_TYPE_STRUCT,
};

struct allocation_extent {
	void* location;
	size_t length;
};

#define NSINVOCATION_ALIGN(n, alignment) ((n + (alignment - 1)) & ~(alignment - 1))

#ifdef __OBJC__
#include <Foundation/NSMethodSignature.h>

// It is a _NSInvocationCallFrame's job to carve out allocation extents from a buffer.
class _NSInvocationCallFrame {
private:
	struct impl; // pImpl idiom
	impl* _impl;
public:
	_NSInvocationCallFrame(NSMethodSignature* methodTypeEncoding);
	~_NSInvocationCallFrame();

    void storeArgument(const void* value, unsigned int index);
    void loadArgument(void* value, unsigned int index) const;

	size_t getReturnLength() const;
	bool getRequiresStructReturn() const;

	void execute(void*, void*) const;

	static return_type returnTypeFromEncoding(const char* returnTypeEncoding);
	static size_t padFrameLength(size_t frameLength);
};

#endif
