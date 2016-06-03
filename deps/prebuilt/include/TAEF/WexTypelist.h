/*
* Copyright (c) Microsoft Corporation.  All Rights Reserved.
*
* TypeList: For building and manipulating a list of types.  See Functor for a use of TypeList.
*          
*/
#pragma once
#include "WexTypes.h"

#define TYPELIST_0() WEX::Common::TerminatorType
#define TYPELIST_1(T1) WEX::Common::TypeList<T1, TYPELIST_0()>
#define TYPELIST_2(T1, T2) WEX::Common::TypeList<T1, TYPELIST_1(T2)>
#define TYPELIST_3(T1, T2, T3) WEX::Common::TypeList<T1, TYPELIST_2(T2, T3)>
#define TYPELIST_4(T1, T2, T3, T4) WEX::Common::TypeList<T1, TYPELIST_3(T2, T3, T4)>
#define TYPELIST_5(T1, T2, T3, T4, T5) WEX::Common::TypeList<T1, TYPELIST_4(T2, T3, T4, T5)>
#define TYPELIST_6(T1, T2, T3, T4, T5, T6) WEX::Common::TypeList<T1, TYPELIST_5(T2, T3, T4, T5, T6)>
#define TYPELIST_7(T1, T2, T3, T4, T5, T6, T7) WEX::Common::TypeList<T1, TYPELIST_6(T2, T3, T4, T5, T6, T7)>
#define TYPELIST_8(T1, T2, T3, T4, T5, T6, T7, T8) WEX::Common::TypeList<T1, TYPELIST_7(T2, T3, T4, T5, T6, T7, T8)>
#define TYPELIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9) WEX::Common::TypeList<T1, TYPELIST_8(T2, T3, T4, T5, T6, T7, T8, T9)>
#define TYPELIST_10(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) WEX::Common::TypeList<T1, TYPELIST_9(T2, T3, T4, T5, T6, T7, T8, T9, T10)>
#define TYPELIST_11(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) WEX::Common::TypeList<T1, TYPELIST_10(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)>
#define TYPELIST_12(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) WEX::Common::TypeList<T1, TYPELIST_11(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)>
#define TYPELIST_13(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) WEX::Common::TypeList<T1, TYPELIST_12(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)>
#define TYPELIST_14(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) WEX::Common::TypeList<T1, TYPELIST_13(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14)>
#define TYPELIST_15(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) WEX::Common::TypeList<T1, TYPELIST_14(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15)>
#define TYPELIST_16(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) WEX::Common::TypeList<T1, TYPELIST_15(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16)>
#define TYPELIST_17(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17) WEX::Common::TypeList<T1, TYPELIST_16(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)>
#define TYPELIST_18(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18) WEX::Common::TypeList<T1, TYPELIST_17(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)>
#define TYPELIST_19(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19) WEX::Common::TypeList<T1, TYPELIST_18(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19)>
#define TYPELIST_20(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20) WEX::Common::TypeList<T1, TYPELIST_19(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20)>

namespace WEX { namespace Common
{
    template <typename T, typename U>
    struct TypeList
    {
        typedef T Head;
        typedef U Tail;
    };

    template <typename TList, typename T> 
    struct AppendToList;

    template <> 
    struct AppendToList<TYPELIST_0(), NullType>
    {
        typedef TYPELIST_0() Result;
    };

    template <typename T>
    struct AppendToList<TYPELIST_0(), T>
    {
        typedef TYPELIST_1(T) Result;
    };

    template <typename Head, typename Tail>
    struct AppendToList<TYPELIST_0(), TypeList<Head, Tail>>
    {
        typedef TypeList<Head, Tail> Result;
    };

    template <typename Head, typename Tail, typename T>
    struct AppendToList<TypeList<Head, Tail>, T>
    {
        typedef TypeList<Head, typename AppendToList<Tail, T>::Result> Result;
    };

    template <typename TList, unsigned int index, typename DefaultType = NullType>
    struct TypeAt
    {
        typedef DefaultType Result;
    };

    template <typename Head, typename Tail, typename DefaultType>
    struct TypeAt<TypeList<Head, Tail>, 0, DefaultType>
    {
        typedef Head Result;
    };

    template <typename Head, typename Tail, unsigned int i, typename DefaultType>
    struct TypeAt<TypeList<Head, Tail>, i, DefaultType>
    {
        typedef typename TypeAt<Tail, i - 1, DefaultType>::Result Result;
    };

    template <typename TList, unsigned int index> 
    struct TypeAtStrict;

    template <typename Head, typename Tail>
    struct TypeAtStrict<TypeList<Head, Tail>, 0>
    {
        typedef Head Result;
    };

    template <typename Head, typename Tail, unsigned int i>
    struct TypeAtStrict<TypeList<Head, Tail>, i>
    {
        typedef typename TypeAtStrict<Tail, i - 1>::Result Result;
    };

    template <typename TList> 
    struct TypeListLength;

    template <>
    struct TypeListLength<TYPELIST_0()>
    {
        static const int value = 0;
    };

    template <typename T, typename U>
    struct TypeListLength<TypeList<T, U>>
    {
        static const int value = (1 + TypeListLength<U>::value);
    };

    template <typename TList, typename T>
    struct Erase;

    template <typename T>
    struct Erase<TYPELIST_0(), T>
    {
        typedef TYPELIST_0() Result;
    };

    template <typename T, typename Tail>
    struct Erase<TypeList<T, Tail>, T>
    {
        typedef Tail Result;
    };

    template <typename Head, typename Tail, typename T>
    struct Erase<TypeList<Head, Tail>, T>
    {
        typedef TypeList<Head, typename Erase<Tail, T>::Result> Result;
    };

    template <typename TList, typename T>
    struct EraseAll;

    template <typename T>
    struct EraseAll<TYPELIST_0(), T>
    {
        typedef TYPELIST_0() Result;
    };

    template <typename T>
    struct EraseAll<TYPELIST_0()&, T>
    {
        typedef TYPELIST_0() Result; // At the end of the list, we still need a TerminatorType
    };

    template <typename T, typename Tail>
    struct EraseAll<TypeList<T, Tail>, T>
    {
        // Go all the way down the list removing the type
        typedef typename EraseAll<Tail, T>::Result Result;
    };

    template <typename Head, typename Tail, typename T>
    struct EraseAll<TypeList<Head, Tail>, T>
    {
        // Go all the way down the list removing the type
        typedef TypeList<Head, typename EraseAll<Tail, T>::Result> Result;
    };
} /* namespace Common */ } /* namespace WEX */