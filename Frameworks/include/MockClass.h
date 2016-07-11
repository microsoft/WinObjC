//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
//*****************************************************************************/
#pragma once


// Nil is a C++/CX object and __alignof is a Microsoft specific operator so they need to be redefined for Objective C
#ifdef __OBJC__
#define Nil Nil2
#define __alignof alignof
#endif

#include "ParameterTypes.h"
#include "Windows.h"
#include "WexTestClass.h"

#include <functional>
#include <wrl/implements.h>
#include <wrl/client.h>

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
This header includes a number of macros that can be used to create mock classes for use in unit testing. The macros
follow the format of MOCK_METHOD_n(functionName), where "n" is the number of parameters and "functionName" is the
name of a function in one of the interfaces that the mock class implements.

Internally these macros will implement the interface methods given as well as create a Set[functionName]
setter per implemented function so that test code can set a custom C++ lambda that will be executed in place of
the given interface function.

Note: There are two sets of macros; one set for regular C++, and one set for high level C++/CX (see next section).

This is all best explained with some sample code:

struct Foo
{
int a;
int b;
};

struct Bar
{
int a;
int b;
};

class ISession
{
public:
virtual void VoidNoArgs() = 0;
virtual HRESULT AddMessageChannelListener(const Foo& foo) const = 0;
virtual HRESULT RemoveMessageChannelListener(const Bar& bar, const Foo& foo) = 0;
virtual HRESULT SendOnMessageChannel(const wchar_t* psz1, int x, char w, long long xyz) = 0;
};

MOCK_CLASS(MockSessionWithLambdas, public ISession
{
public:
MOCK_METHOD_0(VoidNoArgs);
MOCK_CONST_METHOD_1(AddMessageChannelListener);
MOCK_METHOD_2(RemoveMessageChannelListener);
MOCK_METHOD_4(SendOnMessageChannel);

MockSessionWithLambdas()
{
// Initialize callbacks
SetVoidNoArgs([]() { });
SetAddMessageChannelListener([](const Foo& foo){ return E_NOTIMPL; });
SetRemoveMessageChannelListener([](const Bar& bar, const Foo& foo){ return E_NOTIMPL; });
SetSendOnMessageChannel([](const wchar_t* psz1, int x, char w, long long xyz){ return E_NOTIMPL; });
}
});

TEST_METHOD(InterfaceMockingSample)
{
MockSessionWithLambdas x;
HRESULT result = x.AddMessageChannelListener(Foo());

// In this example, result should now be "E_NOTIMPL" based on the default mock implementation of
// AddMessageChannelListener.

x.SetAddMessageChannelListenerCallback([](const Foo& foo)
{
ASSERT_EQ(32, foo.a); // Perform validation within the callback
return HRESULT_FROM_WIN32(ERROR_OUT_OF_PAPER);
});

result = x.AddMessageChannelListener(Foo());

// Now, result should be "HRESULT_FROM_WIN32(ERROR_OUT_OF_PAPER)" based on the lambda provided. In a real test
// the MockSessionWithLambdas would passed to other classes that rely on ISession objects. Then, as those other
// objects interact with the ISession interface, all of the provided lambdas will be executed, allowing
// fine-grained control of how the other objects behave.

ASSERT_EQ(HRESULT_FROM_WIN32(ERROR_OUT_OF_PAPER), result);
}
*/ /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// Class definition must be placed inside macro to mock in Objective C++
// Clang doesn't allow unqualified methods to be mocked so we need to attach the class name to it when mocking
// A namespace is created around the class to allow this to be used more than once
////////////////////////////////////////////////////////////////
#define MOCK_CLASS(CLASS_NAME, ...)                       \
    namespace BUILD_VARIABLE_NAME(CLASS_NAME, _PRIVATE) { \
        class CLASS_NAME;                                 \
        using MOCK_CLASS_NAME = CLASS_NAME;               \
        class CLASS_NAME : __VA_ARGS__;                   \
    };                                                    \
    using CLASS_NAME = BUILD_VARIABLE_NAME(CLASS_NAME, _PRIVATE)::CLASS_NAME;

////////////////////////////////////////////////////////////////
// Macros for mocking non-const methods in low level C++
////////////////////////////////////////////////////////////////

// Mock a zero-arg non-const method in low level C++
#define MOCK_METHOD_0(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 0, false)

// Mock a one-arg non-const methods in low level C++
#define MOCK_METHOD_1(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 1, false)

// Mock a two-arg non-const method in low level C++
#define MOCK_METHOD_2(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 2, false)

// Mock a three-arg non-const method in low level C++
#define MOCK_METHOD_3(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 3, false)

// Mock a four-arg non-const method in low level C++
#define MOCK_METHOD_4(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 4, false)

// Mock a five-arg non-const method in low level C++
#define MOCK_METHOD_5(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 5, false)

// Mock a six-arg non-const method in low level C++
#define MOCK_METHOD_6(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 6, false)

// Mock a seven-arg non-const method in low level C++
#define MOCK_METHOD_7(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 7, false)

// Mock an eight-arg non-const method in low level C++
#define MOCK_METHOD_8(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 8, false)

// Mock a nine-arg non-const method in low level C++
#define MOCK_METHOD_9(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 9, false)

// Mock a ten-arg non-const method in low level C++
#define MOCK_METHOD_10(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 10, false)

////////////////////////////////////////////////////////////////
// Macros for mocking const methods in low level C++
////////////////////////////////////////////////////////////////

// Mock a zero-arg const method in low level C++
#define MOCK_CONST_METHOD_0(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 0, true)

// Mock a one-arg const method in low level C++
#define MOCK_CONST_METHOD_1(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 1, true)

// Mock a two-arg const method in low level C++
#define MOCK_CONST_METHOD_2(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 2, true)

// Mock a three-arg const method in low level C++
#define MOCK_CONST_METHOD_3(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 3, true)

// Mock a four-arg const method in low level C++
#define MOCK_CONST_METHOD_4(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 4, true)

// Mock a five-arg const method in low level C++
#define MOCK_CONST_METHOD_5(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 5, true)

// Mock a six-arg const method in low level C++
#define MOCK_CONST_METHOD_6(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 6, true)

// Mock a seven-arg const method in low level C++
#define MOCK_CONST_METHOD_7(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 7, true)

// Mock an eight-arg const method in low level C++
#define MOCK_CONST_METHOD_8(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 8, true)

// Mock a nine-arg const method in low level C++
#define MOCK_CONST_METHOD_9(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 9, true)

// Mock a ten-arg const method in low level C++
#define MOCK_CONST_METHOD_10(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 10, true)

///////////////////////////////////////////////////////////////////
// Macros for mocking non-const __stdcall methods in low level C++
///////////////////////////////////////////////////////////////////

// Mock a zero-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_0(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 0, false, __stdcall)

// Mock a one-arg non-const methods in low level C++
#define MOCK_STDCALL_METHOD_1(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 1, false, __stdcall)

// Mock a two-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_2(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 2, false, __stdcall)

// Mock a three-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_3(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 3, false, __stdcall)

// Mock a four-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_4(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 4, false, __stdcall)

// Mock a five-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_5(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 5, false, __stdcall)

// Mock a six-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_6(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 6, false, __stdcall)

// Mock a seven-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_7(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 7, false, __stdcall)

// Mock an eight-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_8(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 8, false, __stdcall)

// Mock a nine-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_9(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 9, false, __stdcall)

// Mock a ten-arg non-const method in low level C++
#define MOCK_STDCALL_METHOD_10(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 10, false, __stdcall)

///////////////////////////////////////////////////////////////////
// Macros for mocking const __stdcall methods in low level C++
///////////////////////////////////////////////////////////////////

// Mock a zero-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_0(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 0, true, __stdcall)

// Mock a one-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_1(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 1, true, __stdcall)

// Mock a two-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_2(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 2, true, __stdcall)

// Mock a three-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_3(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 3, true, __stdcall)

// Mock a four-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_4(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 4, true, __stdcall)

// Mock a five-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_5(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 5, true, __stdcall)

// Mock a six-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_6(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 6, true, __stdcall)

// Mock a seven-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_7(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 7, true, __stdcall)

// Mock an eight-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_8(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 8, true, __stdcall)

// Mock a nine-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_9(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 9, true, __stdcall)

// Mock a ten-arg const method in low level C++
#define MOCK_CONST_STDCALL_METHOD_10(METHOD_NAME) BUILD_MOCK_METHOD_IMPL(METHOD_NAME, 10, true, __stdcall)

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
C++/CX usage is slightly different than it is for low level C++:

1. Due to an issue in the compiler, you must first call CX_MOCK_INTERFACE before any of the CX_MOCK* macros will compile.

CX_MOCK_INTERFACE(AnotherNamespace::ITestInterface);

2. You must specify the interface name in addition to the name of the method that you're stubbing out.

CX_MOCK_METHOD_0(ITestInterface, SomeMethod);

This is all best explained with some sample code:

namespace SomeNamespace
{
interface class ISession
{
public:
virtual void SomeMethod(int x);

property int SomeProperty
{
int get();
void set(int);
}
};
}

CX_MOCK_INTERFACE(SomeNamespace::ISession); // Necessary for CX_MOCK_METHOD_* calls to compile
ref class MockSessionWithLambdas : public SomeNamespace::ISession
{
public:
CX_MOCK_METHOD_1(SomeNamespace::ISession, SomeMethod);
CX_MOCK_PROPERTY(SomeNamespace::ISession, SomeProperty);

MockSessionWithLambdas()
{
// Initialize callbacks
SetSomeMethod([](int){ });
SetSomePropertyGetter([] () { return 0; });
SetSomePropertySetter([] (int) { });
}
};

TEST_METHOD(InterfaceMockingSample)
{
auto mockSession = ref new MockSessionWithLambdas();
int callCount = 0;
mockSession->SetSomeMethod([&](int x)
{
VERIFY_ARE_EQUAL(32, x); // Perform validation within the callback
++callCount;
});

mockSession->SomeMethod(32);

VERIFY_ARE_EQUAL(1, callCount);
}
*/ /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
// Macros for mocking C++/CX interface methods
// Be sure to call CX_MOCK_INTERFACE(YourInterface) first.
//////////////////////////////////////////////////////////////////////////////////////////////

// This macro must be called per-interface before any of the CX_MOCK_METHOD* calls will compile for it.
// Be sure to fully qualify your interface name; for example: ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult
#define CX_MOCK_INTERFACE(FULLY_QUALIFIED_INTERFACE_NAME) CX_MOCK_INTERFACE_DISPATCHER_IMPL(FULLY_QUALIFIED_INTERFACE_NAME, __cdecl)

////////////////////////////////////////////////////////////////
// Macros for mocking C++/CX interface methods
////////////////////////////////////////////////////////////////

// Mock a zero-arg method in high level C++/CX
#define CX_MOCK_METHOD_0(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 0, INTERFACE_CLASS, public)

// Mock a one-arg method in high level C++/CX
#define CX_MOCK_METHOD_1(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 1, INTERFACE_CLASS, public)

// Mock a two-arg method in high level C++/CX
#define CX_MOCK_METHOD_2(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 2, INTERFACE_CLASS, public)

// Mock a three-arg method in high level C++/CX
#define CX_MOCK_METHOD_3(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 3, INTERFACE_CLASS, public)

// Mock a four-arg method in high level C++/CX
#define CX_MOCK_METHOD_4(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 4, INTERFACE_CLASS, public)

// Mock a five-arg method in high level C++/CX
#define CX_MOCK_METHOD_5(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 5, INTERFACE_CLASS, public)

// Mock a six-arg method in high level C++/CX
#define CX_MOCK_METHOD_6(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 6, INTERFACE_CLASS, public)

// Mock a seven-arg method in high level C++/CX
#define CX_MOCK_METHOD_7(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 7, INTERFACE_CLASS, public)

// Mock an eight-arg method in high level C++/CX
#define CX_MOCK_METHOD_8(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 8, INTERFACE_CLASS, public)

// Mock a nine-arg method in high level C++/CX
#define CX_MOCK_METHOD_9(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 9, INTERFACE_CLASS, public)

// Mock a ten-arg method in high level C++/CX
#define CX_MOCK_METHOD_10(INTERFACE_NAME, METHOD_NAME) CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 10, INTERFACE_CLASS, public)

// Mock a read/write property getter/setter
#define CX_MOCK_PROPERTY(INTERFACE_NAME, PROPERTY_NAME) CX_BUILD_MOCK_PROPERTY_IMPL(INTERFACE_NAME, PROPERTY_NAME, INTERFACE_CLASS, public)

// Mock a readonly property getter
#define CX_MOCK_READONLY_PROPERTY(INTERFACE_NAME, PROPERTY_NAME) \
    CX_BUILD_MOCK_READONLY_PROPERTY_IMPL(INTERFACE_NAME, PROPERTY_NAME, INTERFACE_CLASS, public)

////////////////////////////////////////////////////////////////
// Macros for mocking public C++/CX abstract class methods
////////////////////////////////////////////////////////////////

// Mock a zero-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_0(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 0, ABSTRACT_CLASS, public)

// Mock a one-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_1(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 1, ABSTRACT_CLASS, public)

// Mock a two-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_2(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 2, ABSTRACT_CLASS, public)

// Mock a three-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_3(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 3, ABSTRACT_CLASS, public)

// Mock a four-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_4(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 4, ABSTRACT_CLASS, public)

// Mock a five-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_5(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 5, ABSTRACT_CLASS, public)

// Mock a six-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_6(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 6, ABSTRACT_CLASS, public)

// Mock a seven-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_7(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 7, ABSTRACT_CLASS, public)

// Mock an eight-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_8(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 8, ABSTRACT_CLASS, public)

// Mock a nine-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_9(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 9, ABSTRACT_CLASS, public)

// Mock a ten-arg public abstract class method in high level C++/CX
#define CX_MOCK_ABSTRACT_METHOD_10(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 10, ABSTRACT_CLASS, public)

// Mock a public abstract read/write property getter/setter
#define CX_MOCK_ABSTRACT_PROPERTY(INTERFACE_NAME, PROPERTY_NAME) \
    CX_BUILD_MOCK_PROPERTY_IMPL(INTERFACE_NAME, PROPERTY_NAME, ABSTRACT_CLASS, public)

// Mock a public abstract readonly property getter
#define CX_MOCK_ABSTRACT_READONLY_PROPERTY(INTERFACE_NAME, PROPERTY_NAME) \
    CX_BUILD_MOCK_READONLY_PROPERTY_IMPL(INTERFACE_NAME, PROPERTY_NAME, ABSTRACT_CLASS, public)

////////////////////////////////////////////////////////////////
// Macros for mocking internal C++/CX abstract class methods
////////////////////////////////////////////////////////////////

// Mock a zero-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_0(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 0, ABSTRACT_CLASS, internal)

// Mock a one-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_1(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 1, ABSTRACT_CLASS, internal)

// Mock a two-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_2(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 2, ABSTRACT_CLASS, internal)

// Mock a three-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_3(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 3, ABSTRACT_CLASS, internal)

// Mock a four-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_4(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 4, ABSTRACT_CLASS, internal)

// Mock a five-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_5(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 5, ABSTRACT_CLASS, internal)

// Mock a six-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_6(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 6, ABSTRACT_CLASS, internal)

// Mock a seven-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_7(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 7, ABSTRACT_CLASS, internal)

// Mock an eight-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_8(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 8, ABSTRACT_CLASS, internal)

// Mock a nine-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_9(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 9, ABSTRACT_CLASS, internal)

// Mock a ten-arg internal abstract class method in high level C++/CX
#define CX_MOCK_INTERNAL_ABSTRACT_METHOD_10(INTERFACE_NAME, METHOD_NAME) \
    CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, 10, ABSTRACT_CLASS, internal)

// Mock an internal abstract read/write property getter/setter
#define CX_MOCK_INTERNAL_ABSTRACT_PROPERTY(INTERFACE_NAME, PROPERTY_NAME) \
    CX_BUILD_MOCK_PROPERTY_IMPL(INTERFACE_NAME, PROPERTY_NAME, ABSTRACT_CLASS, internal)

// Mock an internal abstract readonly property getter
#define CX_MOCK_INTERNAL_ABSTRACT_READONLY_PROPERTY(INTERFACE_NAME, PROPERTY_NAME) \
    CX_BUILD_MOCK_READONLY_PROPERTY_IMPL(INTERFACE_NAME, PROPERTY_NAME, ABSTRACT_CLASS, internal)

//*********************************************************************************************************************
// DO NOT directly call any of the private helper macros/functions below.
//*********************************************************************************************************************

/////////////////////////////////////////////////////////////
// Validates that a callback has been set before invoking it.
/////////////////////////////////////////////////////////////
#if !defined CUSTOM_MOCK_CALLBACK_VALIDATOR
namespace Test {
namespace Mock {
template <typename TFunctor>
void ValidateCallback(const TFunctor& functor, const wchar_t* name) {
    WEX::TestExecution::SetVerifyOutput verifySettings(WEX::TestExecution::VerifyOutputSettings::LogOnlyFailures);
    VERIFY_IS_NOT_NULL(functor, WEX::Common::String().Format(L"The callback for %s has not been set!", name));
}
}
}
#endif

//*********************************************************************************************************************
// Internal/private low level C++ support
//*********************************************************************************************************************

////////////////////////////////////////////////////////////////////////////////////////////////////
// Macros used to build out the parameter types passed to the method and the contained std::function
////////////////////////////////////////////////////////////////////////////////////////////////////
#define MOCK_NAMED_ARGS_0(METHOD_NAME)

#define MOCK_NAMED_ARGS_1(METHOD_NAME) WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1

#define MOCK_NAMED_ARGS_2(METHOD_NAME)                                                   \
    WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter2 p2

#define MOCK_NAMED_ARGS_3(METHOD_NAME)                                                       \
    WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1,     \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter2 p2, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter3 p3

#define MOCK_NAMED_ARGS_4(METHOD_NAME)                                                       \
    WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1,     \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter2 p2, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter3 p3, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter4 p4

#define MOCK_NAMED_ARGS_5(METHOD_NAME)                                                       \
    WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1,     \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter2 p2, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter3 p3, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter4 p4, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter5 p5

#define MOCK_NAMED_ARGS_6(METHOD_NAME)                                                       \
    WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1,     \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter2 p2, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter3 p3, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter4 p4, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter5 p5, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter6 p6

#define MOCK_NAMED_ARGS_7(METHOD_NAME)                                                       \
    WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1,     \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter2 p2, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter3 p3, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter4 p4, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter5 p5, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter6 p6, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter7 p7

#define MOCK_NAMED_ARGS_8(METHOD_NAME)                                                       \
    WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1,     \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter2 p2, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter3 p3, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter4 p4, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter5 p5, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter6 p6, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter7 p7, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter8 p8

#define MOCK_NAMED_ARGS_9(METHOD_NAME)                                                       \
    WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1,     \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter2 p2, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter3 p3, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter4 p4, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter5 p5, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter6 p6, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter7 p7, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter8 p8, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter9 p9

#define MOCK_NAMED_ARGS_10(METHOD_NAME)                                                      \
    WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter1 p1,     \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter2 p2, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter3 p3, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter4 p4, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter5 p5, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter6 p6, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter7 p7, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter8 p8, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter9 p9, \
        WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Parameter10 p10

////////////////////////////////////////////////////
// Macros to build out function call parameter list
////////////////////////////////////////////////////
#define MOCK_CALL_ARGS_0
#define MOCK_CALL_ARGS_1 p1
#define MOCK_CALL_ARGS_2 p1, p2
#define MOCK_CALL_ARGS_3 p1, p2, p3
#define MOCK_CALL_ARGS_4 p1, p2, p3, p4
#define MOCK_CALL_ARGS_5 p1, p2, p3, p4, p5
#define MOCK_CALL_ARGS_6 p1, p2, p3, p4, p5, p6
#define MOCK_CALL_ARGS_7 p1, p2, p3, p4, p5, p6, p7
#define MOCK_CALL_ARGS_8 p1, p2, p3, p4, p5, p6, p7, p8
#define MOCK_CALL_ARGS_9 p1, p2, p3, p4, p5, p6, p7, p8, p9
#define MOCK_CALL_ARGS_10 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10

/////////////////////////////////////////////////////////////
// Internally used by MOCK_* macros; do not call directly.
/////////////////////////////////////////////////////////////
#define BUILD_MOCK_METHOD_IMPL(METHOD_NAME, PARAMETER_COUNT, IS_CONST, ...)                                                               \
private:                                                                                                                                  \
    std::function<WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::ReturnType(                                       \
        BUILD_VARIABLE_NAME(MOCK_NAMED_ARGS_, PARAMETER_COUNT)(METHOD_NAME))> BUILD_VARIABLE_NAME(m_, METHOD_NAME);                       \
                                                                                                                                          \
public:                                                                                                                                   \
    virtual WEX::Common::ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::ReturnType __VA_ARGS__ METHOD_NAME(                     \
        BUILD_VARIABLE_NAME(MOCK_NAMED_ARGS_, PARAMETER_COUNT)(METHOD_NAME)) BUILD_VARIABLE_NAME(MEMBER_PARAMETER_TYPES_CONST_, IS_CONST) \
        override {                                                                                                                        \
        Test::Mock::ValidateCallback(BUILD_VARIABLE_NAME(m_, METHOD_NAME), TAEF_WIDEN(TAEF_STRINGIZE(METHOD_NAME)));         \
        return BUILD_VARIABLE_NAME(m_, METHOD_NAME)(BUILD_VARIABLE_NAME(MOCK_CALL_ARGS_, PARAMETER_COUNT));                               \
    }                                                                                                                                     \
    void BUILD_VARIABLE_NAME(Set, METHOD_NAME)(const decltype(BUILD_VARIABLE_NAME(m_, METHOD_NAME))& callback) {                          \
        BUILD_VARIABLE_NAME(m_, METHOD_NAME) = callback;                                                                                  \
    }

//*********************************************************************************************************************
// Internal/private high level C++/CX support
//*********************************************************************************************************************

////////////////////////////////////////////////////////////////////////////////////////////////////
// Macros used to build out the parameter types passed to the custom ParameterTypes instantiations
// that are made in CX_MOCK_INTERFACE_IMPL for high-level C++/CX interface mocks.
////////////////////////////////////////////////////////////////////////////////////////////////////
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_0 template <typename TR>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_1 template <typename TR, typename T1>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_2 template <typename TR, typename T1, typename T2>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_3 template <typename TR, typename T1, typename T2, typename T3>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_4 template <typename TR, typename T1, typename T2, typename T3, typename T4>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_5 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_6 \
    template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_7 \
    template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_8 \
    template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_9 \
    template <typename TR,                   \
              typename T1,                   \
              typename T2,                   \
              typename T3,                   \
              typename T4,                   \
              typename T5,                   \
              typename T6,                   \
              typename T7,                   \
              typename T8,                   \
              typename T9>
#define CX_MEMBER_PARAMETER_TYPES_TEMPLATE_10 \
    template <typename TR,                    \
              typename T1,                    \
              typename T2,                    \
              typename T3,                    \
              typename T4,                    \
              typename T5,                    \
              typename T6,                    \
              typename T7,                    \
              typename T8,                    \
              typename T9,                    \
              typename T10>

////////////////////////////////////////////////////////////////////////
// Internally used by CX_MOCK_INTERFACE_ macro; do not call directly.
////////////////////////////////////////////////////////////////////////
#define CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, PARAMETER_COUNT, CALLING_CONVENTION)                                                      \
    BUILD_VARIABLE_NAME(CX_MEMBER_PARAMETER_TYPES_TEMPLATE_, PARAMETER_COUNT)                                                            \
    struct MockInterfaceCalled<TR (CALLING_CONVENTION INTERFACE_NAME::*)(BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMETER_COUNT))> { \
        static const bool result = true;                                                                                                 \
    };                                                                                                                                   \
    BUILD_VARIABLE_NAME(CX_MEMBER_PARAMETER_TYPES_TEMPLATE_, PARAMETER_COUNT)                                                            \
    struct WEX::Common::ParameterTypes<TR (CALLING_CONVENTION INTERFACE_NAME::*)(                                                        \
        BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMETER_COUNT))> {                                                                  \
        typedef TR ReturnType;                                                                                                           \
        typedef typename INTERFACE_NAME ClassType;                                                                                       \
        static const unsigned short ParameterCount = PARAMETER_COUNT;                                                                    \
        static const bool IsConstMethod = false;                                                                                         \
        typedef BUILD_VARIABLE_NAME(PARAMETER_TYPES_TYPELIST_, PARAMETER_COUNT) Parameters;                                              \
        typedef typename WEX::Common::TypeAt<Parameters, 0>::Result Parameter1;                                                          \
        typedef typename WEX::Common::TypeAt<Parameters, 1>::Result Parameter2;                                                          \
        typedef typename WEX::Common::TypeAt<Parameters, 2>::Result Parameter3;                                                          \
        typedef typename WEX::Common::TypeAt<Parameters, 3>::Result Parameter4;                                                          \
        typedef typename WEX::Common::TypeAt<Parameters, 4>::Result Parameter5;                                                          \
        typedef typename WEX::Common::TypeAt<Parameters, 5>::Result Parameter6;                                                          \
        typedef typename WEX::Common::TypeAt<Parameters, 6>::Result Parameter7;                                                          \
        typedef typename WEX::Common::TypeAt<Parameters, 7>::Result Parameter8;                                                          \
        typedef typename WEX::Common::TypeAt<Parameters, 8>::Result Parameter9;                                                          \
        typedef typename WEX::Common::TypeAt<Parameters, 9>::Result Parameter10;                                                         \
    };

/////////////////////////////////////////////////////////////////////
// Internally used by CX_MOCK_INTERFACE_ macro; do not call directly.
/////////////////////////////////////////////////////////////////////
#define CX_MOCK_INTERFACE_DISPATCHER_IMPL(INTERFACE_NAME, CALLING_CONVENTION) \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 0, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 1, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 2, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 3, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 4, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 5, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 6, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 7, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 8, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 9, CALLING_CONVENTION)             \
    CX_MOCK_INTERFACE_IMPL(INTERFACE_NAME, 10, CALLING_CONVENTION)

/////////////////////////////////////////////////////////////
// Internally used by CX_MOCK_* macros; do not call directly.
/////////////////////////////////////////////////////////////
template <typename TPrototype>
struct MockInterfaceCalled {
    static const bool result = false;
};

/////////////////////////////////////////////////////////////
// Builds out C++/CX interface method implementations
/////////////////////////////////////////////////////////////
#define MOCK_OVERRIDE_INTERFACE_CLASS
#define MOCK_OVERRIDE_ABSTRACT_CLASS override

#define CX_BUILD_MOCK_METHOD_IMPL(INTERFACE_NAME, METHOD_NAME, PARAMETER_COUNT, MOCK_TYPE, ACCESS)                                  \
    static_assert(MockInterfaceCalled<decltype(&INTERFACE_NAME::METHOD_NAME)>::result,                                              \
                  "You must add a single call to CX_MOCK_INTERFACE(" TAEF_STRINGIZE(                                                \
                      INTERFACE_NAME) ") before this CX_MOCK_METHOD_" TAEF_STRINGIZE(PARAMETER_COUNT) " call will compile.");       \
    typedef WEX::Common::ParameterTypes<decltype(&INTERFACE_NAME::METHOD_NAME)> BUILD_VARIABLE_NAME(METHOD_NAME, PARAMETER_TYPES);  \
    static_assert(PARAMETER_COUNT == BUILD_VARIABLE_NAME(METHOD_NAME, PARAMETER_TYPES)::ParameterCount,                             \
                  "Incorrect macro called for function; parameter count doesn't match!");                                           \
                                                                                                                                    \
private:                                                                                                                            \
    std::function<BUILD_VARIABLE_NAME(METHOD_NAME, PARAMETER_TYPES)::ReturnType(                                                    \
        BUILD_VARIABLE_NAME(MOCK_NAMED_ARGS_, PARAMETER_COUNT)(INTERFACE_NAME::METHOD_NAME))> BUILD_VARIABLE_NAME(m_, METHOD_NAME); \
    ACCESS:                                                                                                                         \
    virtual BUILD_VARIABLE_NAME(METHOD_NAME, PARAMETER_TYPES)::ReturnType METHOD_NAME(                                              \
        BUILD_VARIABLE_NAME(MOCK_NAMED_ARGS_, PARAMETER_COUNT)(INTERFACE_NAME::METHOD_NAME))                                        \
        BUILD_VARIABLE_NAME(MOCK_OVERRIDE_, MOCK_TYPE) {                                                                            \
        Test::Mock::ValidateCallback(BUILD_VARIABLE_NAME(m_, METHOD_NAME), TAEF_WIDEN(TAEF_STRINGIZE(METHOD_NAME)));   \
        return BUILD_VARIABLE_NAME(m_, METHOD_NAME)(BUILD_VARIABLE_NAME(MOCK_CALL_ARGS_, PARAMETER_COUNT));                         \
    }                                                                                                                               \
    internal:                                                                                                                       \
    void BUILD_VARIABLE_NAME(Set, METHOD_NAME)(const decltype(BUILD_VARIABLE_NAME(m_, METHOD_NAME))& callback) {                    \
        BUILD_VARIABLE_NAME(m_, METHOD_NAME) = callback;                                                                            \
    }

/////////////////////////////////////////////////////////////
// Builds out C++/CX read/write property implementations
/////////////////////////////////////////////////////////////
#define CX_BUILD_MOCK_PROPERTY_IMPL(INTERFACE_NAME, PROPERTY_NAME, MOCK_TYPE, ACCESS)                                         \
    static_assert(MockInterfaceCalled<decltype(&INTERFACE_NAME::PROPERTY_NAME::get)>::result,                                 \
                  "You must add a single call to CX_MOCK_INTERFACE(" TAEF_STRINGIZE(                                          \
                      INTERFACE_NAME) ") before this CX_MOCK_METHOD_" TAEF_STRINGIZE(PARAMETER_COUNT) " call will compile."); \
    typedef WEX::Common::ParameterTypes<decltype(&INTERFACE_NAME::PROPERTY_NAME::get)>                                        \
        BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES);                                        \
    static_assert(0 == BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES)::ParameterCount,         \
                  "Incorrect macro called for function; parameter count doesn't match!");                                     \
    static_assert(MockInterfaceCalled<decltype(&INTERFACE_NAME::PROPERTY_NAME::set)>::result,                                 \
                  "You must add a single call to CX_MOCK_INTERFACE(" TAEF_STRINGIZE(                                          \
                      INTERFACE_NAME) ") before this CX_MOCK_METHOD_" TAEF_STRINGIZE(PARAMETER_COUNT) " call will compile."); \
    typedef WEX::Common::ParameterTypes<decltype(&INTERFACE_NAME::PROPERTY_NAME::set)>                                        \
        BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, set), PARAMETER_TYPES);                                        \
    static_assert(1 == BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, set), PARAMETER_TYPES)::ParameterCount,         \
                  "Incorrect macro called for function; parameter count doesn't match!");                                     \
                                                                                                                              \
private:                                                                                                                      \
    std::function<BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES)::ReturnType()>                \
        BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get));                                                     \
    std::function<void(BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, set), PARAMETER_TYPES)::Parameter1 p1)>         \
        BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, set));                                                     \
    ACCESS:                                                                                                                   \
    property BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES)::ReturnType PROPERTY_NAME {        \
        virtual BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES)::ReturnType get()               \
            BUILD_VARIABLE_NAME(MOCK_OVERRIDE_, MOCK_TYPE) {                                                                  \
            Test::Mock::ValidateCallback(BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get)),       \
                                                      TAEF_WIDEN(TAEF_STRINGIZE(PROPERTY_NAME))L"::get");                     \
            return BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get))();                                        \
        }                                                                                                                     \
        virtual void set(BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, set), PARAMETER_TYPES)::Parameter1 p1)        \
            BUILD_VARIABLE_NAME(MOCK_OVERRIDE_, MOCK_TYPE) {                                                                  \
            Test::Mock::ValidateCallback(BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, set)),       \
                                                      TAEF_WIDEN(TAEF_STRINGIZE(PROPERTY_NAME))L"::set");                     \
            return BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, set))(p1);                                      \
        }                                                                                                                     \
    }                                                                                                                         \
    internal:                                                                                                                 \
    void BUILD_VARIABLE_NAME(Set, BUILD_VARIABLE_NAME(PROPERTY_NAME, Getter))(                                                \
        const decltype(BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get)))& callback) {                         \
        BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get)) = callback;                                          \
    }                                                                                                                         \
    void BUILD_VARIABLE_NAME(Set, BUILD_VARIABLE_NAME(PROPERTY_NAME, Setter))(                                                \
        const decltype(BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, set)))& callback) {                         \
        BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, set)) = callback;                                          \
    }

/////////////////////////////////////////////////////////////
// Builds out C++/CX readonly property implementations
/////////////////////////////////////////////////////////////
#define CX_BUILD_MOCK_READONLY_PROPERTY_IMPL(INTERFACE_NAME, PROPERTY_NAME, MOCK_TYPE, ACCESS)                                \
    static_assert(MockInterfaceCalled<decltype(&INTERFACE_NAME::PROPERTY_NAME::get)>::result,                                 \
                  "You must add a single call to CX_MOCK_INTERFACE(" TAEF_STRINGIZE(                                          \
                      INTERFACE_NAME) ") before this CX_MOCK_METHOD_" TAEF_STRINGIZE(PARAMETER_COUNT) " call will compile."); \
    typedef WEX::Common::ParameterTypes<decltype(&INTERFACE_NAME::PROPERTY_NAME::get)>                                        \
        BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES);                                        \
    static_assert(0 == BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES)::ParameterCount,         \
                  "Incorrect macro called for function; parameter count doesn't match!");                                     \
                                                                                                                              \
private:                                                                                                                      \
    std::function<BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES)::ReturnType()>                \
        BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get));                                                     \
    ACCESS:                                                                                                                   \
    property BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES)::ReturnType PROPERTY_NAME {        \
        virtual BUILD_VARIABLE_NAME(BUILD_VARIABLE_NAME(PROPERTY_NAME, get), PARAMETER_TYPES)::ReturnType get()               \
            BUILD_VARIABLE_NAME(MOCK_OVERRIDE_, MOCK_TYPE) {                                                                  \
            Test::Mock::ValidateCallback(BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get)),       \
                                                      TAEF_WIDEN(TAEF_STRINGIZE(PROPERTY_NAME))L"::get");                     \
            return BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get))();                                        \
        }                                                                                                                     \
    }                                                                                                                         \
    internal:                                                                                                                 \
    void BUILD_VARIABLE_NAME(Set, BUILD_VARIABLE_NAME(PROPERTY_NAME, Getter))(                                                \
        const decltype(BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get)))& callback) {                         \
        BUILD_VARIABLE_NAME(m_, BUILD_VARIABLE_NAME(PROPERTY_NAME, get)) = callback;                                          \
    }
