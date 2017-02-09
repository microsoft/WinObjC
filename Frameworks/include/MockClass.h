//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#define BUILD_VARIABLE_NAME_INT(x, y) x##y
#define BUILD_VARIABLE_NAME(x, y) BUILD_VARIABLE_NAME_INT(x, y)

#define MEMBER_PARAMETER_TYPES_CONST_false
#define MEMBER_PARAMETER_TYPES_CONST_true const

#include "Windows.h"

#include <tuple>

// Copying these macros from WexTestClass.h, but not including
// it because it brings in dependencies on TAEF that we don't want
// in Unit Tests.

/// \internal
/// <summary> Wide string conversion helper </summary>
#ifndef TAEF_WIDEN_INT
#define TAEF_WIDEN_INT(x) L##x
#endif

/// \internal
/// <summary> Wide string version of "stringizing" operator </summary>
#ifndef TAEF_WIDEN
#define TAEF_WIDEN(x) TAEF_WIDEN_INT(x)
#endif

/// \internal
/// <summary>Wide string version of __FUNCTION__ macro </summary>
#ifndef TAEF__WFUNCTION__
#define TAEF__WFUNCTION__ TAEF_WIDEN(__FUNCTION__)
#endif

/// \internal
/// <summary>Stringize internal macro </summary>
#ifndef TAEF_STRINGIZE_INT
#define TAEF_STRINGIZE_INT(x) #x
#endif

/// \internal
/// <summary>Stringize macro </summary>
#ifndef TAEF_STRINGIZE
#define TAEF_STRINGIZE(x) TAEF_STRINGIZE_INT(x)
#endif

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

//*********************************************************************************************************************
// DO NOT directly call any of the private helper macros/functions below.
//*********************************************************************************************************************

/////////////////////////////////////////////////////////////
// Validates that a callback has been set before invoking it.
/////////////////////////////////////////////////////////////
#if !defined CUSTOM_MOCK_CALLBACK_VALIDATOR
namespace Test {
namespace Mock {
#if defined(ASSERT_TRUE_MSG)
template <typename TFunctor>
void ValidateCallback(const TFunctor& functor, const wchar_t* name) {
    ASSERT_TRUE_MSG(functor, "The callback for %S has not been set.", name);
}
#elif defined(VERIFY_IS_NOT_NULL)
template <typename TFunctor>
void ValidateCallback(const TFunctor& functor, const wchar_t* name) {
    WEX::TestExecution::SetVerifyOutput verifySettings(WEX::TestExecution::VerifyOutputSettings::LogOnlyFailures);
    VERIFY_IS_NOT_NULL(functor, WEX::Common::String().Format(L"The callback for %ls has not been set!", name));
}
#else
#error "Unknown Test Framework!"
#endif
}
}
#endif

//*********************************************************************************************************************
// Internal/private low level C++ support
//*********************************************************************************************************************
template <typename T>
struct ParameterTypes;

template <typename TReturn, typename TClass, typename... TArgs>
struct ParameterTypes<TReturn (TClass::*)(TArgs...)> {
    using ReturnType = TReturn;
    using ClassType = TClass;
    static constexpr auto ParameterCount = sizeof...(TArgs);

    template <size_t index>
    using Type = typename std::tuple_element<index - 1, std::tuple<TArgs...>>::type;

    using FunctorType = std::function<TReturn(TArgs...)>;
};

#ifndef _M_ARM

template <typename TReturn, typename TClass, typename... TArgs>
struct ParameterTypes<TReturn __stdcall (TClass::*)(TArgs...)> : ParameterTypes<TReturn (TClass::*)(TArgs...)> {};

template <typename TReturn, typename TClass, typename... TArgs>
struct ParameterTypes<TReturn __fastcall (TClass::*)(TArgs...)> : ParameterTypes<TReturn (TClass::*)(TArgs...)> {};

template <typename TReturn, typename TClass, typename... TArgs>
struct ParameterTypes<TReturn __cdecl (TClass::*)(TArgs...)> : ParameterTypes<TReturn (TClass::*)(TArgs...)> {};

template <typename TReturn, typename TClass, typename... TArgs>
struct ParameterTypes<TReturn __vectorcall (TClass::*)(TArgs...)> : ParameterTypes<TReturn (TClass::*)(TArgs...)> {};

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// Macros used to build out the parameter types passed to the method and the contained std::function
////////////////////////////////////////////////////////////////////////////////////////////////////
#define MOCK_NAMED_ARGS_0(METHOD_NAME)

#define MOCK_NAMED_ARGS_1(METHOD_NAME) ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1

#define MOCK_NAMED_ARGS_2(METHOD_NAME) \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1, ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<2> p2

#define MOCK_NAMED_ARGS_3(METHOD_NAME)                                       \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1,     \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<2> p2, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<3> p3

#define MOCK_NAMED_ARGS_4(METHOD_NAME)                                       \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1,     \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<2> p2, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<3> p3, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<4> p4

#define MOCK_NAMED_ARGS_5(METHOD_NAME)                                       \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1,     \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<2> p2, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<3> p3, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<4> p4, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<5> p5

#define MOCK_NAMED_ARGS_6(METHOD_NAME)                                       \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1,     \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<2> p2, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<3> p3, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<4> p4, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<5> p5, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<6> p6

#define MOCK_NAMED_ARGS_7(METHOD_NAME)                                       \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1,     \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<2> p2, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<3> p3, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<4> p4, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<5> p5, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<6> p6, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<7> p7

#define MOCK_NAMED_ARGS_8(METHOD_NAME)                                       \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1,     \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<2> p2, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<3> p3, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<4> p4, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<5> p5, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<6> p6, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<7> p7, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<8> p8

#define MOCK_NAMED_ARGS_9(METHOD_NAME)                                       \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1,     \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<2> p2, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<3> p3, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<4> p4, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<5> p5, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<6> p6, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<7> p7, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<8> p8, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<9> p9

#define MOCK_NAMED_ARGS_10(METHOD_NAME)                                      \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<1> p1,     \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<2> p2, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<3> p3, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<4> p4, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<5> p5, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<6> p6, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<7> p7, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<8> p8, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<9> p9, \
        ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::Type<10> p10

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
                                                                                                                                          \
private:                                                                                                                                  \
    ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::FunctorType BUILD_VARIABLE_NAME(m_, METHOD_NAME);                            \
                                                                                                                                          \
public:                                                                                                                                   \
    virtual ParameterTypes<decltype(&MOCK_CLASS_NAME::METHOD_NAME)>::ReturnType __VA_ARGS__ METHOD_NAME(                                  \
        BUILD_VARIABLE_NAME(MOCK_NAMED_ARGS_, PARAMETER_COUNT)(METHOD_NAME)) BUILD_VARIABLE_NAME(MEMBER_PARAMETER_TYPES_CONST_, IS_CONST) \
        override {                                                                                                                        \
        Test::Mock::ValidateCallback(BUILD_VARIABLE_NAME(m_, METHOD_NAME), TAEF_WIDEN(TAEF_STRINGIZE(METHOD_NAME)));                      \
        return BUILD_VARIABLE_NAME(m_, METHOD_NAME)(BUILD_VARIABLE_NAME(MOCK_CALL_ARGS_, PARAMETER_COUNT));                               \
    }                                                                                                                                     \
    void BUILD_VARIABLE_NAME(Set, METHOD_NAME)(const decltype(BUILD_VARIABLE_NAME(m_, METHOD_NAME))& callback) {                          \
        BUILD_VARIABLE_NAME(m_, METHOD_NAME) = callback;                                                                                  \
    }