#include "FrameAllocator.h"
#include <cstdint>
#include <algorithm>
#include <objc/runtime.h>
#include <objc/encoding.h>

#include <Foundation/NSMethodSignature.h>

struct x86call {
	void* ebp;
	void* retp;
	void* ebx;
	return_type rettype;
	size_t retlen;
	void* retvalp;
	void* funp;
};

static return_type _getReturnType(const char* typeEncoding) {
	switch(typeEncoding[0]) {
		case 'c':
			return RETURN_TYPE_SINT8;
		case 's':
			return RETURN_TYPE_SINT16;
		case 'C':
			return RETURN_TYPE_UINT8;
		case 'S':
			return RETURN_TYPE_UINT16;
		case 'i':
		case 'l':
		case 'I':
		case 'L':
			return RETURN_TYPE_INT32;
		case 'q':
		case 'Q':
			return RETURN_TYPE_INT64;
		case '@': case '#': case '^': case ':': case '*':
			return RETURN_TYPE_POINTER;
		case '{':
			return RETURN_TYPE_STRUCT;
		case 'f':
			return RETURN_TYPE_FLOAT;
		case 'd':
			return RETURN_TYPE_DOUBLE;
		case 'v':
			return RETURN_TYPE_NONE;
	}
	return RETURN_TYPE_NONE;
}

struct _NSInvocationCallFrame::impl {
	impl(NSMethodSignature* methodSignature): _offset(0), _stret(false) {
		// This is memoized, so it should be fast.
		_length = methodSignature.frameLength;
		_returnType = _getReturnType([methodSignature methodReturnType]);

		_returnLength = methodSignature.methodReturnLength;
		
		if (_returnType == RETURN_TYPE_STRUCT && !(_returnLength <= 8 && _returnLength % 2 == 0)) {
			_stret = true;
			_length += sizeof(void*);
		} else {
			if (_returnType != RETURN_TYPE_STRUCT) {
				// Promote all non-stret return lengths to one machine word.
				_returnLength = std::max(sizeof(uintptr_t), _returnLength);
			}
		}

		_buffer = new uint8_t[2*_length];

		if (_stret) {
			_stretExtent = allocateArgument("*");
		}

	};

	allocation_extent allocateArgument(const char* objcTypeEncoding) {
		size_t nWords = std::max(1U, objc_aligned_size(objcTypeEncoding) / sizeof(uintptr_t));
		auto length = nWords * sizeof(uintptr_t);

		allocation_extent extent{_buffer + _offset, length};
		_offset += extent.length;
		return extent;
	}

	uint8_t* _buffer;
	off_t _offset;
	size_t _length;
	size_t _returnLength;
	return_type _returnType;

	bool _stret;
	allocation_extent _stretExtent;
};

_NSInvocationCallFrame::_NSInvocationCallFrame(NSMethodSignature* methodSignature):
	_impl(new _NSInvocationCallFrame::impl(methodSignature)) {
}

_NSInvocationCallFrame::~_NSInvocationCallFrame() {
	delete _impl;
}

allocation_extent _NSInvocationCallFrame::allocateArgument(const char* objcTypeEncoding) {
	return _impl->allocateArgument(objcTypeEncoding);
}

return_type _NSInvocationCallFrame::getReturnType() const {
	return _impl->_returnType;
}

size_t _NSInvocationCallFrame::getReturnLength() const {
	return _impl->_returnLength;
}

bool _NSInvocationCallFrame::getRequiresStructReturn() const {
	return _impl->_stret;
}

extern "C" __declspec(naked) void __fastcall _CallFrameInternal(struct x86call* call, void* stackBuffer);
void _NSInvocationCallFrame::execute(void* functionPointer, void* returnValuePointer) const {
	if (_impl->_stret) {
		// populate stret out if necessary.
		memcpy(_impl->_stretExtent.location, &returnValuePointer, _impl->_stretExtent.length);
	}

	auto frameLength = _impl->_offset;
	void* arena = alloca(frameLength + sizeof(struct x86call));
	x86call* call = (x86call*)(reinterpret_cast<uint8_t*>(arena) + frameLength);
	void* stack = reinterpret_cast<uint8_t*>(arena);
	memcpy(stack, _impl->_buffer, frameLength);
	*call = {0,0,0,_impl->_returnType,_impl->_returnLength,returnValuePointer,functionPointer};
	_CallFrameInternal(call, stack);
}

/* static */
return_type _NSInvocationCallFrame::returnTypeFromEncoding(const char* returnTypeEncoding) {
	return RETURN_TYPE_NONE;
}

/* static */
size_t _NSInvocationCallFrame::padFrameLength(size_t frameLength) {
	return frameLength;
}


/*
// This method takes the approach of assuming that every type must be aligned to max(wordsize, typesize)
size_t maximumArenaSizeForTypeEncoding(const char* typeEncoding) {
	size_t length = 0;
	// We don't care about the return type (first encoding) or official calculated frame length (first number)
	const char* ptr = typeEncoding;
	ptr = objc_skip_typespec(ptr);
	while (*ptr && isdigit(*ptr)) {
		ptr++;
	}
	while (*ptr) {
		const char *typeBegin = ptr;
		ptr = objc_skip_typespec(ptr);
	while (*ptr && isdigit(*ptr)) {
		ptr++;
	}
	}
}
*/
