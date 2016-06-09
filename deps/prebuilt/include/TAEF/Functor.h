/*
* Copyright (c) Microsoft Corporation.  All Rights Reserved.
*
* Functor: A class for wrapping any function or class method; although it is not a full "closure".
*          This is due to the fact that it is still necessary to pass the function parameters at the time of invocation.
*          Full closures can be built on top of Functors.          
* Usage:
*
*       Functor<int (int, int)> addFunc(&AddFunction); // Create functor for a function
*       int result = addFunc(2, 3);                    // Call at any time
*
*       Functor<int (int, int)> addFunc(&MyMathClass::AddFunction); // Create functor for a static method
*       int result = addFunc(2, 3);                                 // Call at any time
*
*       MyMathClass myMathClass;
*       Functor<int (int, int)> addFunc(&myMathClass, &MyMathClass::AddFunction); // Create functor for an instance method
*       int result = addFunc(2, 3);                                               // Call at any time (as long as myMathClass is valid)
*/
#pragma once
#include "ParameterTypes.h"
#include "WexTypeList.h"
#include "WexAssert.h"

#pragma push_macro("Assert")
#undef Assert

namespace WEX { namespace Common
{
    template <typename TFunctorImpl>
    struct FunctorImplCompare
    {
        virtual bool operator==(const TFunctorImpl& other) const = 0;
        virtual bool IsMemberFunctor() const = 0;
    };

    template <typename TPrototype>
    class FunctorImpl;

    #define FUNCTOR_IMPL(PARAMCOUNT, CC)                                                                     \
    BUILD_VARIABLE_NAME(PARAMETER_TYPES_TEMPLATE_, PARAMCOUNT)                                               \
    class FunctorImpl<TR CC (BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMCOUNT))>:                       \
    public FunctorImplCompare<FunctorImpl<TR CC (BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMCOUNT))>>   \
    {                                                                                                        \
    public:                                                                                                  \
        virtual TR operator()(BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMCOUNT)) = 0;                   \
        virtual FunctorImpl* Clone() const = 0;                                                              \
        virtual ~FunctorImpl(){}                                                                             \
    }

    #if defined(_M_IX86)
        FUNCTOR_IMPL(0, __stdcall);
        FUNCTOR_IMPL(1, __stdcall);
        FUNCTOR_IMPL(2, __stdcall);
        FUNCTOR_IMPL(3, __stdcall);
        FUNCTOR_IMPL(4, __stdcall);
        FUNCTOR_IMPL(5, __stdcall);
        FUNCTOR_IMPL(6, __stdcall);
        FUNCTOR_IMPL(7, __stdcall);
        FUNCTOR_IMPL(8, __stdcall);
        FUNCTOR_IMPL(9, __stdcall);
        FUNCTOR_IMPL(10, __stdcall);
        FUNCTOR_IMPL(11, __stdcall);
        FUNCTOR_IMPL(12, __stdcall);
        FUNCTOR_IMPL(13, __stdcall);
        FUNCTOR_IMPL(14, __stdcall);
        FUNCTOR_IMPL(15, __stdcall);
        FUNCTOR_IMPL(16, __stdcall);
        FUNCTOR_IMPL(17, __stdcall);
        FUNCTOR_IMPL(18, __stdcall);
        FUNCTOR_IMPL(19, __stdcall);
        FUNCTOR_IMPL(20, __stdcall);

        FUNCTOR_IMPL(0, __cdecl);
        FUNCTOR_IMPL(1, __cdecl);
        FUNCTOR_IMPL(2, __cdecl);
        FUNCTOR_IMPL(3, __cdecl);
        FUNCTOR_IMPL(4, __cdecl);
        FUNCTOR_IMPL(5, __cdecl);
        FUNCTOR_IMPL(6, __cdecl);
        FUNCTOR_IMPL(7, __cdecl);
        FUNCTOR_IMPL(8, __cdecl);
        FUNCTOR_IMPL(9, __cdecl);
        FUNCTOR_IMPL(10, __cdecl);
        FUNCTOR_IMPL(11, __cdecl);
        FUNCTOR_IMPL(12, __cdecl);
        FUNCTOR_IMPL(13, __cdecl);
        FUNCTOR_IMPL(14, __cdecl);
        FUNCTOR_IMPL(15, __cdecl);
        FUNCTOR_IMPL(16, __cdecl);
        FUNCTOR_IMPL(17, __cdecl);
        FUNCTOR_IMPL(18, __cdecl);
        FUNCTOR_IMPL(19, __cdecl);
        FUNCTOR_IMPL(20, __cdecl);

        #if !defined _MANAGED
            FUNCTOR_IMPL(0, __fastcall);
            FUNCTOR_IMPL(1, __fastcall);
            FUNCTOR_IMPL(2, __fastcall);
            FUNCTOR_IMPL(3, __fastcall);
            FUNCTOR_IMPL(4, __fastcall);
            FUNCTOR_IMPL(5, __fastcall);
            FUNCTOR_IMPL(6, __fastcall);
            FUNCTOR_IMPL(7, __fastcall);
            FUNCTOR_IMPL(8, __fastcall);
            FUNCTOR_IMPL(9, __fastcall);
            FUNCTOR_IMPL(10, __fastcall);
            FUNCTOR_IMPL(11, __fastcall);
            FUNCTOR_IMPL(12, __fastcall);
            FUNCTOR_IMPL(13, __fastcall);
            FUNCTOR_IMPL(14, __fastcall);
            FUNCTOR_IMPL(15, __fastcall);
            FUNCTOR_IMPL(16, __fastcall);
            FUNCTOR_IMPL(17, __fastcall);
            FUNCTOR_IMPL(18, __fastcall);
            FUNCTOR_IMPL(19, __fastcall);
            FUNCTOR_IMPL(20, __fastcall);
        #endif
    #else
        FUNCTOR_IMPL(0, __stdcall);
        FUNCTOR_IMPL(1, __stdcall);
        FUNCTOR_IMPL(2, __stdcall);
        FUNCTOR_IMPL(3, __stdcall);
        FUNCTOR_IMPL(4, __stdcall);
        FUNCTOR_IMPL(5, __stdcall);
        FUNCTOR_IMPL(6, __stdcall);
        FUNCTOR_IMPL(7, __stdcall);
        FUNCTOR_IMPL(8, __stdcall);
        FUNCTOR_IMPL(9, __stdcall);
        FUNCTOR_IMPL(10, __stdcall);
        FUNCTOR_IMPL(11, __stdcall);
        FUNCTOR_IMPL(12, __stdcall);
        FUNCTOR_IMPL(13, __stdcall);
        FUNCTOR_IMPL(14, __stdcall);
        FUNCTOR_IMPL(15, __stdcall);
        FUNCTOR_IMPL(16, __stdcall);
        FUNCTOR_IMPL(17, __stdcall);
        FUNCTOR_IMPL(18, __stdcall);
        FUNCTOR_IMPL(19, __stdcall);
        FUNCTOR_IMPL(20, __stdcall);
    #endif

    template <typename TPrototype>
    class Functor
    {
    public:
        typedef FunctorImpl<TPrototype> Impl;
        typedef TPrototype Prototype;
        typedef typename ParameterTypes<TPrototype>::Parameters ParameterList;
        typedef typename ParameterTypes<TPrototype>::ReturnType ReturnType;
        typedef typename ParameterTypes<TPrototype>::Parameter1 Parameter1;
        typedef typename ParameterTypes<TPrototype>::Parameter2 Parameter2;
        typedef typename ParameterTypes<TPrototype>::Parameter3 Parameter3;
        typedef typename ParameterTypes<TPrototype>::Parameter4 Parameter4;
        typedef typename ParameterTypes<TPrototype>::Parameter5 Parameter5;
        typedef typename ParameterTypes<TPrototype>::Parameter6 Parameter6;
        typedef typename ParameterTypes<TPrototype>::Parameter7 Parameter7;
        typedef typename ParameterTypes<TPrototype>::Parameter8 Parameter8;
        typedef typename ParameterTypes<TPrototype>::Parameter9 Parameter9;
        typedef typename ParameterTypes<TPrototype>::Parameter10 Parameter10;
        typedef typename ParameterTypes<TPrototype>::Parameter11 Parameter11;
        typedef typename ParameterTypes<TPrototype>::Parameter12 Parameter12;
        typedef typename ParameterTypes<TPrototype>::Parameter13 Parameter13;
        typedef typename ParameterTypes<TPrototype>::Parameter14 Parameter14;
        typedef typename ParameterTypes<TPrototype>::Parameter15 Parameter15;
        typedef typename ParameterTypes<TPrototype>::Parameter16 Parameter16;
        typedef typename ParameterTypes<TPrototype>::Parameter17 Parameter17;
        typedef typename ParameterTypes<TPrototype>::Parameter18 Parameter18;
        typedef typename ParameterTypes<TPrototype>::Parameter19 Parameter19;
        typedef typename ParameterTypes<TPrototype>::Parameter20 Parameter20;

        Functor()
        : m_pImpl(NULL)
        {
        }

        explicit Functor(Impl* pImpl)
        : m_pImpl(pImpl)
        {
        }

        template <typename TFunctionObject>
        explicit Functor(const TFunctionObject& functionObject)
        {
            // Do we even have a function object?  It's possible, due to template inference, that we could end up with anything here -- most likely a function pointer 
            // to a function with a mismatched function signature.  So try to fail early to provide a decent error message to the user.
            COMPILE_TIME_CHECK_V2(__is_class(TFunctionObject) || (WEX::Common::AreSameType<Prototype, TFunctionObject>::value), 
                    "The function object specified does not have the expected function signature. Please recheck its signature", 
                    The_function_object_specified_does_not_have_the_expected_function_signature_Please_recheck_its_signature);

            // If a user tries to construct a Functor from another Functor, we should succeed if the signatures match 'close enough'; meaning if the types are compatible (int vs. int&, etc.)
            __if_exists(TFunctionObject::Parameter20)
            {
                m_pImpl = new FunctorHandler<Functor<Prototype>, TFunctionObject>(functionObject);
            }

            __if_not_exists(TFunctionObject::Parameter20)
            {
                // Copy the functor object into a WEX::Common::Functor class
                // Passing the member function pointer first to the ValidateFunctor function verifies that TFunctor is actually a functor,
                // that it contains a *single* operator() method to avoid ambiguity, and that it is of the expected function signature.
                m_pImpl = CopyFunctionObject(functionObject, ValidateFunctor(&TFunctionObject::operator()));
            }
        }

        template <typename TFunction>
        explicit Functor(TFunction* pFunction)
        : m_pImpl(new FunctorHandler<Functor, TFunction*>(pFunction))
        {
        }

        template <typename TObject, typename TPointerToMemberFunction>
        Functor(const TObject& object, TPointerToMemberFunction pMemberFunction)
        : m_pImpl(new MemberFunctorHandler<Functor, TObject, TPointerToMemberFunction>(object, pMemberFunction))
        {
        }

        Functor(const Functor& rhs)
        : m_pImpl(NULL)
        {
            if (rhs.IsValid())
            {
                m_pImpl = rhs.m_pImpl->Clone();
            }
        }

        Functor& operator=(const Functor& rhs)
        {
            // Clear out the existing functor
            Clear();

            // Copy the rhs functor if it's valid
            if (rhs.IsValid())
            {
                // Make a temp copy so we don't delete the pointer owned by rhs,
                // and transfer ownership
                Functor copy(rhs);
                m_pImpl = copy.m_pImpl;
                copy.m_pImpl = NULL;
            }

            return *this;
        }

        ~Functor()
        {
            Clear();
        }

        void Clear()
        {
            delete m_pImpl;
            m_pImpl = NULL;
        }

        #define FUNCTOR_METHOD(PARAMCOUNT)                                                                 \
        ReturnType operator()(BUILD_VARIABLE_NAME(PARAMETER_NAMED_ARGS_, PARAMCOUNT))                      \
        {                                                                                                  \
            return (*m_pImpl)(BUILD_VARIABLE_NAME(PARAMETER_ARGS_, PARAMCOUNT));                           \
        }

        FUNCTOR_METHOD(0)
        FUNCTOR_METHOD(1)
        FUNCTOR_METHOD(2)
        FUNCTOR_METHOD(3)
        FUNCTOR_METHOD(4)
        FUNCTOR_METHOD(5)
        FUNCTOR_METHOD(6)
        FUNCTOR_METHOD(7)
        FUNCTOR_METHOD(8)
        FUNCTOR_METHOD(9)
        FUNCTOR_METHOD(10)
        FUNCTOR_METHOD(11)
        FUNCTOR_METHOD(12)
        FUNCTOR_METHOD(13)
        FUNCTOR_METHOD(14)
        FUNCTOR_METHOD(15)
        FUNCTOR_METHOD(16)
        FUNCTOR_METHOD(17)
        FUNCTOR_METHOD(18)
        FUNCTOR_METHOD(19)
        FUNCTOR_METHOD(20)

        bool IsValid() const
        {
            return m_pImpl != NULL;
        }

        template <typename TPrototype2>
        bool operator==(const Functor<TPrototype2>& other) const
        {
            if (IsValid() && other.IsValid())
            {
                return (*m_pImpl == *other.m_pImpl);
            }

            return (!IsValid() && !other.IsValid());
        }

        template <typename TPrototype2>
        bool operator !=(const Functor<TPrototype2>& other) const
        {
            return !operator==(other);
        }

    private:
        template <typename TOtherPrototype>
        __declspec(noinline) static const TOtherPrototype& ValidateFunctor(const TOtherPrototype& t)
        {
            return t;
        }

        template <typename TObject, typename TMemberFunction>
        static FunctorImpl<TPrototype>* CopyFunctionObject(const TObject& object, TMemberFunction& memberFunction)
        {
            return new MemberFunctorHandler<Functor, TObject, TMemberFunction>(object, memberFunction);
        }

        Impl* m_pImpl;        
    };

    #define FUNCTOR_HANDLER_NAMED_ARGS_0 
    #define FUNCTOR_HANDLER_NAMED_ARGS_1 typename TParentFunctor::Parameter1 p1
    #define FUNCTOR_HANDLER_NAMED_ARGS_2 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2
    #define FUNCTOR_HANDLER_NAMED_ARGS_3 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3
    #define FUNCTOR_HANDLER_NAMED_ARGS_4 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4
    #define FUNCTOR_HANDLER_NAMED_ARGS_5 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5
    #define FUNCTOR_HANDLER_NAMED_ARGS_6 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6
    #define FUNCTOR_HANDLER_NAMED_ARGS_7 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7
    #define FUNCTOR_HANDLER_NAMED_ARGS_8 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8
    #define FUNCTOR_HANDLER_NAMED_ARGS_9 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9
    #define FUNCTOR_HANDLER_NAMED_ARGS_10 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10
    #define FUNCTOR_HANDLER_NAMED_ARGS_11 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11
    #define FUNCTOR_HANDLER_NAMED_ARGS_12 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11, typename TParentFunctor::Parameter12 p12
    #define FUNCTOR_HANDLER_NAMED_ARGS_13 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11, typename TParentFunctor::Parameter12 p12, typename TParentFunctor::Parameter13 p13
    #define FUNCTOR_HANDLER_NAMED_ARGS_14 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11, typename TParentFunctor::Parameter12 p12, typename TParentFunctor::Parameter13 p13, typename TParentFunctor::Parameter14 p14
    #define FUNCTOR_HANDLER_NAMED_ARGS_15 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11, typename TParentFunctor::Parameter12 p12, typename TParentFunctor::Parameter13 p13, typename TParentFunctor::Parameter14 p14, typename TParentFunctor::Parameter15 p15
    #define FUNCTOR_HANDLER_NAMED_ARGS_16 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11, typename TParentFunctor::Parameter12 p12, typename TParentFunctor::Parameter13 p13, typename TParentFunctor::Parameter14 p14, typename TParentFunctor::Parameter15 p15, typename TParentFunctor::Parameter16 p16
    #define FUNCTOR_HANDLER_NAMED_ARGS_17 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11, typename TParentFunctor::Parameter12 p12, typename TParentFunctor::Parameter13 p13, typename TParentFunctor::Parameter14 p14, typename TParentFunctor::Parameter15 p15, typename TParentFunctor::Parameter16 p16, typename TParentFunctor::Parameter17 p17
    #define FUNCTOR_HANDLER_NAMED_ARGS_18 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11, typename TParentFunctor::Parameter12 p12, typename TParentFunctor::Parameter13 p13, typename TParentFunctor::Parameter14 p14, typename TParentFunctor::Parameter15 p15, typename TParentFunctor::Parameter16 p16, typename TParentFunctor::Parameter17 p17, typename TParentFunctor::Parameter18 p18
    #define FUNCTOR_HANDLER_NAMED_ARGS_19 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11, typename TParentFunctor::Parameter12 p12, typename TParentFunctor::Parameter13 p13, typename TParentFunctor::Parameter14 p14, typename TParentFunctor::Parameter15 p15, typename TParentFunctor::Parameter16 p16, typename TParentFunctor::Parameter17 p17, typename TParentFunctor::Parameter18 p18, typename TParentFunctor::Parameter19 p19
    #define FUNCTOR_HANDLER_NAMED_ARGS_20 typename TParentFunctor::Parameter1 p1, typename TParentFunctor::Parameter2 p2, typename TParentFunctor::Parameter3 p3, typename TParentFunctor::Parameter4 p4, typename TParentFunctor::Parameter5 p5, typename TParentFunctor::Parameter6 p6, typename TParentFunctor::Parameter7 p7, typename TParentFunctor::Parameter8 p8, typename TParentFunctor::Parameter9 p9, typename TParentFunctor::Parameter10 p10, typename TParentFunctor::Parameter11 p11, typename TParentFunctor::Parameter12 p12, typename TParentFunctor::Parameter13 p13, typename TParentFunctor::Parameter14 p14, typename TParentFunctor::Parameter15 p15, typename TParentFunctor::Parameter16 p16, typename TParentFunctor::Parameter17 p17, typename TParentFunctor::Parameter18 p18, typename TParentFunctor::Parameter19 p19, typename TParentFunctor::Parameter20 p20

    template <typename TParentFunctor, typename TFunctor>
    class FunctorHandler : public FunctorImpl<typename TParentFunctor::Prototype>
    {
    public:
        explicit FunctorHandler(const TFunctor& functor) : m_functor(functor)
        {
        }

        FunctorHandler* Clone() const
        {
            return new FunctorHandler(*this);
        }

        #define FUNCTOR_HANDLER_METHOD(PARAMCOUNT)                                                                   \
        typename TParentFunctor::ReturnType operator()(BUILD_VARIABLE_NAME(FUNCTOR_HANDLER_NAMED_ARGS_, PARAMCOUNT)) \
        {                                                                                                            \
            return m_functor(BUILD_VARIABLE_NAME(PARAMETER_ARGS_, PARAMCOUNT));                                      \
        }

        FUNCTOR_HANDLER_METHOD(0)
        FUNCTOR_HANDLER_METHOD(1)
        FUNCTOR_HANDLER_METHOD(2)
        FUNCTOR_HANDLER_METHOD(3)
        FUNCTOR_HANDLER_METHOD(4)
        FUNCTOR_HANDLER_METHOD(5)
        FUNCTOR_HANDLER_METHOD(6)
        FUNCTOR_HANDLER_METHOD(7)
        FUNCTOR_HANDLER_METHOD(8)
        FUNCTOR_HANDLER_METHOD(9)
        FUNCTOR_HANDLER_METHOD(10)
        FUNCTOR_HANDLER_METHOD(11)
        FUNCTOR_HANDLER_METHOD(12)
        FUNCTOR_HANDLER_METHOD(13)
        FUNCTOR_HANDLER_METHOD(14)
        FUNCTOR_HANDLER_METHOD(15)
        FUNCTOR_HANDLER_METHOD(16)
        FUNCTOR_HANDLER_METHOD(17)
        FUNCTOR_HANDLER_METHOD(18)
        FUNCTOR_HANDLER_METHOD(19)
        FUNCTOR_HANDLER_METHOD(20)

        bool IsMemberFunctor() const
        {
            return false;
        }

        typedef FunctorImpl<typename TParentFunctor::Prototype> TFunctorImpl;
        bool operator==(const TFunctorImpl& other) const
        {
            if (!other.IsMemberFunctor())
            {
                const FunctorHandler* pOther = static_cast<const FunctorHandler*>(&other);
                if (m_functor == pOther->m_functor)
                {
                    return true;
                }
            }
            return false;
        }

    private:
        TFunctor m_functor;
    };

    template <typename TParentFunctor, typename TObject, typename TPointerToMemberFunction>
    class MemberFunctorHandler : public FunctorImpl<typename TParentFunctor::Prototype>
    {
    public:
        MemberFunctorHandler(const TObject& object, TPointerToMemberFunction pFunction)
        : m_object(object)
        , m_pMemberFunction(pFunction)
        {
            WEX_ASSERT(m_pMemberFunction, L"MemberFunctorHandler was constructed with a null TPointerToMemberFunction");
        }

        MemberFunctorHandler* Clone() const
        {
            return new MemberFunctorHandler(m_object, m_pMemberFunction);
        }

        #define MEMBER_FUNCTOR_HANDLER_METHOD(PARAMCOUNT)                                                                     \
        typename TParentFunctor::ReturnType operator()(BUILD_VARIABLE_NAME(FUNCTOR_HANDLER_NAMED_ARGS_, PARAMCOUNT))          \
        {                                                                                                                     \
            return (Dereference<TObject>::Value(m_object).*m_pMemberFunction)(BUILD_VARIABLE_NAME(PARAMETER_ARGS_, PARAMCOUNT)); \
        }

        MEMBER_FUNCTOR_HANDLER_METHOD(0)
        MEMBER_FUNCTOR_HANDLER_METHOD(1)
        MEMBER_FUNCTOR_HANDLER_METHOD(2)
        MEMBER_FUNCTOR_HANDLER_METHOD(3)
        MEMBER_FUNCTOR_HANDLER_METHOD(4)
        MEMBER_FUNCTOR_HANDLER_METHOD(5)
        MEMBER_FUNCTOR_HANDLER_METHOD(6)
        MEMBER_FUNCTOR_HANDLER_METHOD(7)
        MEMBER_FUNCTOR_HANDLER_METHOD(8)
        MEMBER_FUNCTOR_HANDLER_METHOD(9)
        MEMBER_FUNCTOR_HANDLER_METHOD(10)
        MEMBER_FUNCTOR_HANDLER_METHOD(11)
        MEMBER_FUNCTOR_HANDLER_METHOD(12)
        MEMBER_FUNCTOR_HANDLER_METHOD(13)
        MEMBER_FUNCTOR_HANDLER_METHOD(14)
        MEMBER_FUNCTOR_HANDLER_METHOD(15)
        MEMBER_FUNCTOR_HANDLER_METHOD(16)
        MEMBER_FUNCTOR_HANDLER_METHOD(17)
        MEMBER_FUNCTOR_HANDLER_METHOD(18)
        MEMBER_FUNCTOR_HANDLER_METHOD(19)
        MEMBER_FUNCTOR_HANDLER_METHOD(20)

        bool IsMemberFunctor() const
        {
            return true;
        }

        typedef FunctorImpl<typename TParentFunctor::Prototype> TFunctorImpl;
        bool operator==(const TFunctorImpl& other) const
        {
            if (other.IsMemberFunctor())
            {
                const MemberFunctorHandler* pOther = static_cast<const MemberFunctorHandler*>(&other);
                if (pOther->m_pMemberFunction == m_pMemberFunction)
                {
                    return Compare<TObject>::Value(pOther->m_object, m_object);
                }
            }
            return false;
        }

    private:
        MemberFunctorHandler(const MemberFunctorHandler&); // non-implemented
        MemberFunctorHandler& operator=(const MemberFunctorHandler&); // Not implemented

        template <typename T>
        struct Dereference
        {
        public:
            static T& Value(T& t)
            {
                return t;
            }
        };

        template <typename T>
        struct Dereference<T*>
        {
        public:
            static T& Value(T* t)
            {
                return *t;
            }
        };

        template <typename T>
        struct Compare
        {
        public:
            static bool Value(const T& t1, const T& t2)
            {
                __if_exists(T::operator==)
                {
                    return t1 == t2;
                }
                __if_not_exists(T::operator==)
                {
                    UNREFERENCED_PARAMETER(t1);
                    UNREFERENCED_PARAMETER(t2);
                    return false;
                }
            }
        };

        template <typename T>
        struct Compare<T*>
        {
        public:
            static bool Value(const T* pT1, const T* pT2)
            {
                return pT1 == pT2;
            }
        };

        TObject m_object;
        TPointerToMemberFunction m_pMemberFunction;
    };
} /* namespace Common */ } /* namespace WEX */

#pragma pop_macro("Assert")
