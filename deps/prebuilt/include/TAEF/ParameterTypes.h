//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>
/// </summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once

#include "WexTypeList.h"

namespace WEX { namespace Common
{
    #ifndef BUILD_VARIABLE_NAME_INT
    #define BUILD_VARIABLE_NAME_INT(x, y) x##y
    #endif

    #ifndef BUILD_VARIABLE_NAME
    #define BUILD_VARIABLE_NAME(x, y) BUILD_VARIABLE_NAME_INT(x, y)
    #endif

    #define PARAMETER_TYPES_TEMPLATE_0 template <typename TR>
    #define PARAMETER_TYPES_TEMPLATE_1 template <typename TR, typename T1>
    #define PARAMETER_TYPES_TEMPLATE_2 template <typename TR, typename T1, typename T2>
    #define PARAMETER_TYPES_TEMPLATE_3 template <typename TR, typename T1, typename T2, typename T3>
    #define PARAMETER_TYPES_TEMPLATE_4 template <typename TR, typename T1, typename T2, typename T3, typename T4>
    #define PARAMETER_TYPES_TEMPLATE_5 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5>
    #define PARAMETER_TYPES_TEMPLATE_6 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    #define PARAMETER_TYPES_TEMPLATE_7 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    #define PARAMETER_TYPES_TEMPLATE_8 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    #define PARAMETER_TYPES_TEMPLATE_9 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    #define PARAMETER_TYPES_TEMPLATE_10 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
    #define PARAMETER_TYPES_TEMPLATE_11 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
    #define PARAMETER_TYPES_TEMPLATE_12 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    #define PARAMETER_TYPES_TEMPLATE_13 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
    #define PARAMETER_TYPES_TEMPLATE_14 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
    #define PARAMETER_TYPES_TEMPLATE_15 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
    #define PARAMETER_TYPES_TEMPLATE_16 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
    #define PARAMETER_TYPES_TEMPLATE_17 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
    #define PARAMETER_TYPES_TEMPLATE_18 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18>
    #define PARAMETER_TYPES_TEMPLATE_19 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19>
    #define PARAMETER_TYPES_TEMPLATE_20 template <typename TR, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>

    #define MEMBER_PARAMETER_TYPES_TEMPLATE_0 template <typename TR, typename TC>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_1 template <typename TR, typename TC, typename T1>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_2 template <typename TR, typename TC, typename T1, typename T2>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_3 template <typename TR, typename TC, typename T1, typename T2, typename T3>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_4 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_5 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_6 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_7 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_8 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_9 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_10 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_11 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_12 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_13 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_14 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_15 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_16 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_17 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_18 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_19 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19>
    #define MEMBER_PARAMETER_TYPES_TEMPLATE_20 template <typename TR, typename TC, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>

    #define PARAMETER_TYPES_ARGS_0 
    #define PARAMETER_TYPES_ARGS_1 T1
    #define PARAMETER_TYPES_ARGS_2 T1, T2
    #define PARAMETER_TYPES_ARGS_3 T1, T2, T3
    #define PARAMETER_TYPES_ARGS_4 T1, T2, T3, T4
    #define PARAMETER_TYPES_ARGS_5 T1, T2, T3, T4, T5
    #define PARAMETER_TYPES_ARGS_6 T1, T2, T3, T4, T5, T6
    #define PARAMETER_TYPES_ARGS_7 T1, T2, T3, T4, T5, T6, T7
    #define PARAMETER_TYPES_ARGS_8 T1, T2, T3, T4, T5, T6, T7, T8
    #define PARAMETER_TYPES_ARGS_9 T1, T2, T3, T4, T5, T6, T7, T8, T9
    #define PARAMETER_TYPES_ARGS_10 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10
    #define PARAMETER_TYPES_ARGS_11 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11
    #define PARAMETER_TYPES_ARGS_12 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12
    #define PARAMETER_TYPES_ARGS_13 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13
    #define PARAMETER_TYPES_ARGS_14 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14
    #define PARAMETER_TYPES_ARGS_15 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15
    #define PARAMETER_TYPES_ARGS_16 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16
    #define PARAMETER_TYPES_ARGS_17 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17
    #define PARAMETER_TYPES_ARGS_18 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18
    #define PARAMETER_TYPES_ARGS_19 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19
    #define PARAMETER_TYPES_ARGS_20 T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20

    #define MEMBER_PARAMETER_TYPES_ARGS_0 
    #define MEMBER_PARAMETER_TYPES_ARGS_1 , T1
    #define MEMBER_PARAMETER_TYPES_ARGS_2 , T1, T2
    #define MEMBER_PARAMETER_TYPES_ARGS_3 , T1, T2, T3
    #define MEMBER_PARAMETER_TYPES_ARGS_4 , T1, T2, T3, T4
    #define MEMBER_PARAMETER_TYPES_ARGS_5 , T1, T2, T3, T4, T5
    #define MEMBER_PARAMETER_TYPES_ARGS_6 , T1, T2, T3, T4, T5, T6
    #define MEMBER_PARAMETER_TYPES_ARGS_7 , T1, T2, T3, T4, T5, T6, T7
    #define MEMBER_PARAMETER_TYPES_ARGS_8 , T1, T2, T3, T4, T5, T6, T7, T8
    #define MEMBER_PARAMETER_TYPES_ARGS_9 , T1, T2, T3, T4, T5, T6, T7, T8, T9
    #define MEMBER_PARAMETER_TYPES_ARGS_10 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10
    #define MEMBER_PARAMETER_TYPES_ARGS_11 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11
    #define MEMBER_PARAMETER_TYPES_ARGS_12 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12
    #define MEMBER_PARAMETER_TYPES_ARGS_13 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13
    #define MEMBER_PARAMETER_TYPES_ARGS_14 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14
    #define MEMBER_PARAMETER_TYPES_ARGS_15 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15
    #define MEMBER_PARAMETER_TYPES_ARGS_16 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16
    #define MEMBER_PARAMETER_TYPES_ARGS_17 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17
    #define MEMBER_PARAMETER_TYPES_ARGS_18 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18
    #define MEMBER_PARAMETER_TYPES_ARGS_19 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19
    #define MEMBER_PARAMETER_TYPES_ARGS_20 , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20

    #define PARAMETER_TYPES_TYPELIST_0 TYPELIST_0()
    #define PARAMETER_TYPES_TYPELIST_1 TYPELIST_1(T1)
    #define PARAMETER_TYPES_TYPELIST_2 TYPELIST_2(T1, T2)
    #define PARAMETER_TYPES_TYPELIST_3 TYPELIST_3(T1, T2, T3)
    #define PARAMETER_TYPES_TYPELIST_4 TYPELIST_4(T1, T2, T3, T4)
    #define PARAMETER_TYPES_TYPELIST_5 TYPELIST_5(T1, T2, T3, T4, T5)
    #define PARAMETER_TYPES_TYPELIST_6 TYPELIST_6(T1, T2, T3, T4, T5, T6)
    #define PARAMETER_TYPES_TYPELIST_7 TYPELIST_7(T1, T2, T3, T4, T5, T6, T7)
    #define PARAMETER_TYPES_TYPELIST_8 TYPELIST_8(T1, T2, T3, T4, T5, T6, T7, T8)
    #define PARAMETER_TYPES_TYPELIST_9 TYPELIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9)
    #define PARAMETER_TYPES_TYPELIST_10 TYPELIST_10(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
    #define PARAMETER_TYPES_TYPELIST_11 TYPELIST_11(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)
    #define PARAMETER_TYPES_TYPELIST_12 TYPELIST_12(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)
    #define PARAMETER_TYPES_TYPELIST_13 TYPELIST_13(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)
    #define PARAMETER_TYPES_TYPELIST_14 TYPELIST_14(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14)
    #define PARAMETER_TYPES_TYPELIST_15 TYPELIST_15(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15)
    #define PARAMETER_TYPES_TYPELIST_16 TYPELIST_16(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16)
    #define PARAMETER_TYPES_TYPELIST_17 TYPELIST_17(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
    #define PARAMETER_TYPES_TYPELIST_18 TYPELIST_18(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
    #define PARAMETER_TYPES_TYPELIST_19 TYPELIST_19(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19)
    #define PARAMETER_TYPES_TYPELIST_20 TYPELIST_20(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20)

    #define PARAMETER_ARGS_0 
    #define PARAMETER_ARGS_1 p1
    #define PARAMETER_ARGS_2 p1, p2
    #define PARAMETER_ARGS_3 p1, p2, p3
    #define PARAMETER_ARGS_4 p1, p2, p3, p4
    #define PARAMETER_ARGS_5 p1, p2, p3, p4, p5
    #define PARAMETER_ARGS_6 p1, p2, p3, p4, p5, p6
    #define PARAMETER_ARGS_7 p1, p2, p3, p4, p5, p6, p7
    #define PARAMETER_ARGS_8 p1, p2, p3, p4, p5, p6, p7, p8
    #define PARAMETER_ARGS_9 p1, p2, p3, p4, p5, p6, p7, p8, p9
    #define PARAMETER_ARGS_10 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10
    #define PARAMETER_ARGS_11 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11
    #define PARAMETER_ARGS_12 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12
    #define PARAMETER_ARGS_13 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13
    #define PARAMETER_ARGS_14 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14
    #define PARAMETER_ARGS_15 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15
    #define PARAMETER_ARGS_16 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16
    #define PARAMETER_ARGS_17 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17
    #define PARAMETER_ARGS_18 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18
    #define PARAMETER_ARGS_19 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19
    #define PARAMETER_ARGS_20 p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20

    #define PARAMETER_NAMED_ARGS_0 
    #define PARAMETER_NAMED_ARGS_1 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1
    #define PARAMETER_NAMED_ARGS_2 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2
    #define PARAMETER_NAMED_ARGS_3 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3
    #define PARAMETER_NAMED_ARGS_4 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4
    #define PARAMETER_NAMED_ARGS_5 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5
    #define PARAMETER_NAMED_ARGS_6 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6
    #define PARAMETER_NAMED_ARGS_7 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7
    #define PARAMETER_NAMED_ARGS_8 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8
    #define PARAMETER_NAMED_ARGS_9 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9
    #define PARAMETER_NAMED_ARGS_10 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10
    #define PARAMETER_NAMED_ARGS_11 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11
    #define PARAMETER_NAMED_ARGS_12 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11, typename WEX::Common::ParameterTypes<TPrototype>::Parameter12 p12
    #define PARAMETER_NAMED_ARGS_13 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11, typename WEX::Common::ParameterTypes<TPrototype>::Parameter12 p12, typename WEX::Common::ParameterTypes<TPrototype>::Parameter13 p13
    #define PARAMETER_NAMED_ARGS_14 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11, typename WEX::Common::ParameterTypes<TPrototype>::Parameter12 p12, typename WEX::Common::ParameterTypes<TPrototype>::Parameter13 p13, typename WEX::Common::ParameterTypes<TPrototype>::Parameter14 p14
    #define PARAMETER_NAMED_ARGS_15 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11, typename WEX::Common::ParameterTypes<TPrototype>::Parameter12 p12, typename WEX::Common::ParameterTypes<TPrototype>::Parameter13 p13, typename WEX::Common::ParameterTypes<TPrototype>::Parameter14 p14, typename WEX::Common::ParameterTypes<TPrototype>::Parameter15 p15
    #define PARAMETER_NAMED_ARGS_16 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11, typename WEX::Common::ParameterTypes<TPrototype>::Parameter12 p12, typename WEX::Common::ParameterTypes<TPrototype>::Parameter13 p13, typename WEX::Common::ParameterTypes<TPrototype>::Parameter14 p14, typename WEX::Common::ParameterTypes<TPrototype>::Parameter15 p15, typename WEX::Common::ParameterTypes<TPrototype>::Parameter16 p16
    #define PARAMETER_NAMED_ARGS_17 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11, typename WEX::Common::ParameterTypes<TPrototype>::Parameter12 p12, typename WEX::Common::ParameterTypes<TPrototype>::Parameter13 p13, typename WEX::Common::ParameterTypes<TPrototype>::Parameter14 p14, typename WEX::Common::ParameterTypes<TPrototype>::Parameter15 p15, typename WEX::Common::ParameterTypes<TPrototype>::Parameter16 p16, typename WEX::Common::ParameterTypes<TPrototype>::Parameter17 p17
    #define PARAMETER_NAMED_ARGS_18 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11, typename WEX::Common::ParameterTypes<TPrototype>::Parameter12 p12, typename WEX::Common::ParameterTypes<TPrototype>::Parameter13 p13, typename WEX::Common::ParameterTypes<TPrototype>::Parameter14 p14, typename WEX::Common::ParameterTypes<TPrototype>::Parameter15 p15, typename WEX::Common::ParameterTypes<TPrototype>::Parameter16 p16, typename WEX::Common::ParameterTypes<TPrototype>::Parameter17 p17, typename WEX::Common::ParameterTypes<TPrototype>::Parameter18 p18
    #define PARAMETER_NAMED_ARGS_19 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11, typename WEX::Common::ParameterTypes<TPrototype>::Parameter12 p12, typename WEX::Common::ParameterTypes<TPrototype>::Parameter13 p13, typename WEX::Common::ParameterTypes<TPrototype>::Parameter14 p14, typename WEX::Common::ParameterTypes<TPrototype>::Parameter15 p15, typename WEX::Common::ParameterTypes<TPrototype>::Parameter16 p16, typename WEX::Common::ParameterTypes<TPrototype>::Parameter17 p17, typename WEX::Common::ParameterTypes<TPrototype>::Parameter18 p18, typename WEX::Common::ParameterTypes<TPrototype>::Parameter19 p19
    #define PARAMETER_NAMED_ARGS_20 typename WEX::Common::ParameterTypes<TPrototype>::Parameter1 p1, typename WEX::Common::ParameterTypes<TPrototype>::Parameter2 p2, typename WEX::Common::ParameterTypes<TPrototype>::Parameter3 p3, typename WEX::Common::ParameterTypes<TPrototype>::Parameter4 p4, typename WEX::Common::ParameterTypes<TPrototype>::Parameter5 p5, typename WEX::Common::ParameterTypes<TPrototype>::Parameter6 p6, typename WEX::Common::ParameterTypes<TPrototype>::Parameter7 p7, typename WEX::Common::ParameterTypes<TPrototype>::Parameter8 p8, typename WEX::Common::ParameterTypes<TPrototype>::Parameter9 p9, typename WEX::Common::ParameterTypes<TPrototype>::Parameter10 p10, typename WEX::Common::ParameterTypes<TPrototype>::Parameter11 p11, typename WEX::Common::ParameterTypes<TPrototype>::Parameter12 p12, typename WEX::Common::ParameterTypes<TPrototype>::Parameter13 p13, typename WEX::Common::ParameterTypes<TPrototype>::Parameter14 p14, typename WEX::Common::ParameterTypes<TPrototype>::Parameter15 p15, typename WEX::Common::ParameterTypes<TPrototype>::Parameter16 p16, typename WEX::Common::ParameterTypes<TPrototype>::Parameter17 p17, typename WEX::Common::ParameterTypes<TPrototype>::Parameter18 p18, typename WEX::Common::ParameterTypes<TPrototype>::Parameter19 p19, typename WEX::Common::ParameterTypes<TPrototype>::Parameter20 p20

    // The ParameterTypes struct maps a 'prototype'-style definition into a single type and TYPELIST. For example,
    //
    //    ParameterTypes<int (wchar_t*, float)>::ReturnType = int
    //    ParameterTypes<int (wchar_t*, float)>::Parameters = TYPELIST_2(wchar_t*, float)
    template <typename T>
    struct ParameterTypes;

    #define PARAMETER_TYPES(PARAMCOUNT, CC)                                                                                                       \
    BUILD_VARIABLE_NAME(PARAMETER_TYPES_TEMPLATE_, PARAMCOUNT)                                                                                    \
    struct ParameterTypes<TR CC (BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMCOUNT))>                                                         \
    {                                                                                                                                             \
        typedef TR ReturnType;                                                                                                                    \
        typedef BUILD_VARIABLE_NAME(PARAMETER_TYPES_TYPELIST_, PARAMCOUNT) Parameters;                                                            \
        static const unsigned short ParameterCount = TypeListLength<Parameters>::value;                                                           \
        typedef ParameterTypes<TR (BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMCOUNT))> RawPrototype; /*Without Calling Convention*/          \
        typedef typename TypeAt<Parameters, 0>::Result Parameter1;                                                                                \
        typedef typename TypeAt<Parameters, 1>::Result Parameter2;                                                                                \
        typedef typename TypeAt<Parameters, 2>::Result Parameter3;                                                                                \
        typedef typename TypeAt<Parameters, 3>::Result Parameter4;                                                                                \
        typedef typename TypeAt<Parameters, 4>::Result Parameter5;                                                                                \
        typedef typename TypeAt<Parameters, 5>::Result Parameter6;                                                                                \
        typedef typename TypeAt<Parameters, 6>::Result Parameter7;                                                                                \
        typedef typename TypeAt<Parameters, 7>::Result Parameter8;                                                                                \
        typedef typename TypeAt<Parameters, 8>::Result Parameter9;                                                                                \
        typedef typename TypeAt<Parameters, 9>::Result Parameter10;                                                                               \
        typedef typename TypeAt<Parameters, 10>::Result Parameter11;                                                                              \
        typedef typename TypeAt<Parameters, 11>::Result Parameter12;                                                                              \
        typedef typename TypeAt<Parameters, 12>::Result Parameter13;                                                                              \
        typedef typename TypeAt<Parameters, 13>::Result Parameter14;                                                                              \
        typedef typename TypeAt<Parameters, 14>::Result Parameter15;                                                                              \
        typedef typename TypeAt<Parameters, 15>::Result Parameter16;                                                                              \
        typedef typename TypeAt<Parameters, 16>::Result Parameter17;                                                                              \
        typedef typename TypeAt<Parameters, 17>::Result Parameter18;                                                                              \
        typedef typename TypeAt<Parameters, 18>::Result Parameter19;                                                                              \
        typedef typename TypeAt<Parameters, 19>::Result Parameter20;                                                                              \
    }

    #define MEMBER_PARAMETER_TYPES_CONST_false
    #define MEMBER_PARAMETER_TYPES_CONST_true const
    
    #define MEMBER_PARAMETER_TYPES_IMPL(PARAMCOUNT, CC, IS_CONST, ...)                                                                                                                     \
    BUILD_VARIABLE_NAME(MEMBER_PARAMETER_TYPES_TEMPLATE_, PARAMCOUNT)                                                                                                                      \
    struct ParameterTypes<TR (CC TC::*)(BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMCOUNT)) BUILD_VARIABLE_NAME(MEMBER_PARAMETER_TYPES_CONST_, IS_CONST) __VA_ARGS__>                  \
    {                                                                                                                                                                                      \
        typedef TR ReturnType;                                                                                                                                                             \
        typedef TC ClassType;                                                                                                                                                              \
        static const unsigned short ParameterCount = PARAMCOUNT;                                                                                                                           \
        static const bool IsConstMethod = IS_CONST;                                                                                                                                        \
        typedef BUILD_VARIABLE_NAME(PARAMETER_TYPES_TYPELIST_, PARAMCOUNT) Parameters;                                                                                                     \
        typedef ParameterTypes<TR (BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMCOUNT))> RawPrototype; /*Without Calling Convention*/                                                   \
        typedef TR (CC TC::*PrototypeWithoutThrowSpecifier)(BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMCOUNT)) BUILD_VARIABLE_NAME(MEMBER_PARAMETER_TYPES_CONST_, IS_CONST);          \
        typedef typename TypeAt<Parameters, 0>::Result Parameter1;                                                                                                                         \
        typedef typename TypeAt<Parameters, 1>::Result Parameter2;                                                                                                                         \
        typedef typename TypeAt<Parameters, 2>::Result Parameter3;                                                                                                                         \
        typedef typename TypeAt<Parameters, 3>::Result Parameter4;                                                                                                                         \
        typedef typename TypeAt<Parameters, 4>::Result Parameter5;                                                                                                                         \
        typedef typename TypeAt<Parameters, 5>::Result Parameter6;                                                                                                                         \
        typedef typename TypeAt<Parameters, 6>::Result Parameter7;                                                                                                                         \
        typedef typename TypeAt<Parameters, 7>::Result Parameter8;                                                                                                                         \
        typedef typename TypeAt<Parameters, 8>::Result Parameter9;                                                                                                                         \
        typedef typename TypeAt<Parameters, 9>::Result Parameter10;                                                                                                                        \
        typedef typename TypeAt<Parameters, 10>::Result Parameter11;                                                                                                                       \
        typedef typename TypeAt<Parameters, 11>::Result Parameter12;                                                                                                                       \
        typedef typename TypeAt<Parameters, 12>::Result Parameter13;                                                                                                                       \
        typedef typename TypeAt<Parameters, 13>::Result Parameter14;                                                                                                                       \
        typedef typename TypeAt<Parameters, 14>::Result Parameter15;                                                                                                                       \
        typedef typename TypeAt<Parameters, 15>::Result Parameter16;                                                                                                                       \
        typedef typename TypeAt<Parameters, 16>::Result Parameter17;                                                                                                                       \
        typedef typename TypeAt<Parameters, 17>::Result Parameter18;                                                                                                                       \
        typedef typename TypeAt<Parameters, 18>::Result Parameter19;                                                                                                                       \
        typedef typename TypeAt<Parameters, 19>::Result Parameter20;                                                                                                                       \
    }

#if _MSC_VER < 1700
    #define MEMBER_PARAMETER_TYPES(PARAMCOUNT, CC)                      \
        MEMBER_PARAMETER_TYPES_IMPL(PARAMCOUNT, CC, true);              \
        MEMBER_PARAMETER_TYPES_IMPL(PARAMCOUNT, CC, true, throw ());    \
        MEMBER_PARAMETER_TYPES_IMPL(PARAMCOUNT, CC, true, throw (...)); \
        MEMBER_PARAMETER_TYPES_IMPL(PARAMCOUNT, CC, false);             \
        MEMBER_PARAMETER_TYPES_IMPL(PARAMCOUNT, CC, false, throw ());   \
        MEMBER_PARAMETER_TYPES_IMPL(PARAMCOUNT, CC, false, throw (...));
#else
    #define MEMBER_PARAMETER_TYPES(PARAMCOUNT, CC)                      \
        MEMBER_PARAMETER_TYPES_IMPL(PARAMCOUNT, CC, true);              \
        MEMBER_PARAMETER_TYPES_IMPL(PARAMCOUNT, CC, false);
#endif

    // ReturnTypeAsMember
    template <typename TReturnType>
    class ReturnTypeAsMember
    {
    public:
        typedef TReturnType Type;
    };

    // Specialize for void, since it's invalid to have a void member variable
    template <>
    class ReturnTypeAsMember<void>
    {
    public:
        typedef NullType Type;
    };

    #if defined(_M_IX86)
        PARAMETER_TYPES(0, __stdcall);
        PARAMETER_TYPES(1, __stdcall);
        PARAMETER_TYPES(2, __stdcall);
        PARAMETER_TYPES(3, __stdcall);
        PARAMETER_TYPES(4, __stdcall);
        PARAMETER_TYPES(5, __stdcall);
        PARAMETER_TYPES(6, __stdcall);
        PARAMETER_TYPES(7, __stdcall);
        PARAMETER_TYPES(8, __stdcall);
        PARAMETER_TYPES(9, __stdcall);
        PARAMETER_TYPES(10, __stdcall);
        PARAMETER_TYPES(11, __stdcall);
        PARAMETER_TYPES(12, __stdcall);
        PARAMETER_TYPES(13, __stdcall);
        PARAMETER_TYPES(14, __stdcall);
        PARAMETER_TYPES(15, __stdcall);
        PARAMETER_TYPES(16, __stdcall);
        PARAMETER_TYPES(17, __stdcall);
        PARAMETER_TYPES(18, __stdcall);
        PARAMETER_TYPES(19, __stdcall);
        PARAMETER_TYPES(20, __stdcall);

        PARAMETER_TYPES(0, __cdecl);
        PARAMETER_TYPES(1, __cdecl);
        PARAMETER_TYPES(2, __cdecl);
        PARAMETER_TYPES(3, __cdecl);
        PARAMETER_TYPES(4, __cdecl);
        PARAMETER_TYPES(5, __cdecl);
        PARAMETER_TYPES(6, __cdecl);
        PARAMETER_TYPES(7, __cdecl);
        PARAMETER_TYPES(8, __cdecl);
        PARAMETER_TYPES(9, __cdecl);
        PARAMETER_TYPES(10, __cdecl);
        PARAMETER_TYPES(11, __cdecl);
        PARAMETER_TYPES(12, __cdecl);
        PARAMETER_TYPES(13, __cdecl);
        PARAMETER_TYPES(14, __cdecl);
        PARAMETER_TYPES(15, __cdecl);
        PARAMETER_TYPES(16, __cdecl);
        PARAMETER_TYPES(17, __cdecl);
        PARAMETER_TYPES(18, __cdecl);
        PARAMETER_TYPES(19, __cdecl);
        PARAMETER_TYPES(20, __cdecl);

        // When compiling under '/clr' '__fastcall' is an invalid calling convention, and is converted to '__stdcall'.
        // As a result, we can skip the __fastcall block entirely if '_MANAGED' is defined
#if !defined(_MANAGED)
        PARAMETER_TYPES(0, __fastcall);
        PARAMETER_TYPES(1, __fastcall);
        PARAMETER_TYPES(2, __fastcall);
        PARAMETER_TYPES(3, __fastcall);
        PARAMETER_TYPES(4, __fastcall);
        PARAMETER_TYPES(5, __fastcall);
        PARAMETER_TYPES(6, __fastcall);
        PARAMETER_TYPES(7, __fastcall);
        PARAMETER_TYPES(8, __fastcall);
        PARAMETER_TYPES(9, __fastcall);
        PARAMETER_TYPES(10, __fastcall);
        PARAMETER_TYPES(11, __fastcall);
        PARAMETER_TYPES(12, __fastcall);
        PARAMETER_TYPES(13, __fastcall);
        PARAMETER_TYPES(14, __fastcall);
        PARAMETER_TYPES(15, __fastcall);
        PARAMETER_TYPES(16, __fastcall);
        PARAMETER_TYPES(17, __fastcall);
        PARAMETER_TYPES(18, __fastcall);
        PARAMETER_TYPES(19, __fastcall);
        PARAMETER_TYPES(20, __fastcall);
#endif
        MEMBER_PARAMETER_TYPES(0, __thiscall);
        MEMBER_PARAMETER_TYPES(1, __thiscall);
        MEMBER_PARAMETER_TYPES(2, __thiscall);
        MEMBER_PARAMETER_TYPES(3, __thiscall);
        MEMBER_PARAMETER_TYPES(4, __thiscall);
        MEMBER_PARAMETER_TYPES(5, __thiscall);
        MEMBER_PARAMETER_TYPES(6, __thiscall);
        MEMBER_PARAMETER_TYPES(7, __thiscall);
        MEMBER_PARAMETER_TYPES(8, __thiscall);
        MEMBER_PARAMETER_TYPES(9, __thiscall);
        MEMBER_PARAMETER_TYPES(10, __thiscall);
        MEMBER_PARAMETER_TYPES(11, __thiscall);
        MEMBER_PARAMETER_TYPES(12, __thiscall);
        MEMBER_PARAMETER_TYPES(13, __thiscall);
        MEMBER_PARAMETER_TYPES(14, __thiscall);
        MEMBER_PARAMETER_TYPES(15, __thiscall);
        MEMBER_PARAMETER_TYPES(16, __thiscall);
        MEMBER_PARAMETER_TYPES(17, __thiscall);
        MEMBER_PARAMETER_TYPES(18, __thiscall);
        MEMBER_PARAMETER_TYPES(19, __thiscall);
        MEMBER_PARAMETER_TYPES(20, __thiscall);

        MEMBER_PARAMETER_TYPES(0, __stdcall);
        MEMBER_PARAMETER_TYPES(1, __stdcall);
        MEMBER_PARAMETER_TYPES(2, __stdcall);
        MEMBER_PARAMETER_TYPES(3, __stdcall);
        MEMBER_PARAMETER_TYPES(4, __stdcall);
        MEMBER_PARAMETER_TYPES(5, __stdcall);
        MEMBER_PARAMETER_TYPES(6, __stdcall);
        MEMBER_PARAMETER_TYPES(7, __stdcall);
        MEMBER_PARAMETER_TYPES(8, __stdcall);
        MEMBER_PARAMETER_TYPES(9, __stdcall);
        MEMBER_PARAMETER_TYPES(10, __stdcall);
        MEMBER_PARAMETER_TYPES(11, __stdcall);
        MEMBER_PARAMETER_TYPES(12, __stdcall);
        MEMBER_PARAMETER_TYPES(13, __stdcall);
        MEMBER_PARAMETER_TYPES(14, __stdcall);
        MEMBER_PARAMETER_TYPES(15, __stdcall);
        MEMBER_PARAMETER_TYPES(16, __stdcall);
        MEMBER_PARAMETER_TYPES(17, __stdcall);
        MEMBER_PARAMETER_TYPES(18, __stdcall);
        MEMBER_PARAMETER_TYPES(19, __stdcall);
        MEMBER_PARAMETER_TYPES(20, __stdcall);

    #else
        PARAMETER_TYPES(0, __stdcall);
        PARAMETER_TYPES(1, __stdcall);
        PARAMETER_TYPES(2, __stdcall);
        PARAMETER_TYPES(3, __stdcall);
        PARAMETER_TYPES(4, __stdcall);
        PARAMETER_TYPES(5, __stdcall);
        PARAMETER_TYPES(6, __stdcall);
        PARAMETER_TYPES(7, __stdcall);
        PARAMETER_TYPES(8, __stdcall);
        PARAMETER_TYPES(9, __stdcall);
        PARAMETER_TYPES(10, __stdcall);
        PARAMETER_TYPES(11, __stdcall);
        PARAMETER_TYPES(12, __stdcall);
        PARAMETER_TYPES(13, __stdcall);
        PARAMETER_TYPES(14, __stdcall);
        PARAMETER_TYPES(15, __stdcall);
        PARAMETER_TYPES(16, __stdcall);
        PARAMETER_TYPES(17, __stdcall);
        PARAMETER_TYPES(18, __stdcall);
        PARAMETER_TYPES(19, __stdcall);
        PARAMETER_TYPES(20, __stdcall);

        MEMBER_PARAMETER_TYPES(0, __thiscall);
        MEMBER_PARAMETER_TYPES(1, __thiscall);
        MEMBER_PARAMETER_TYPES(2, __thiscall);
        MEMBER_PARAMETER_TYPES(3, __thiscall);
        MEMBER_PARAMETER_TYPES(4, __thiscall);
        MEMBER_PARAMETER_TYPES(5, __thiscall);
        MEMBER_PARAMETER_TYPES(6, __thiscall);
        MEMBER_PARAMETER_TYPES(7, __thiscall);
        MEMBER_PARAMETER_TYPES(8, __thiscall);
        MEMBER_PARAMETER_TYPES(9, __thiscall);
        MEMBER_PARAMETER_TYPES(10, __thiscall);
        MEMBER_PARAMETER_TYPES(11, __thiscall);
        MEMBER_PARAMETER_TYPES(12, __thiscall);
        MEMBER_PARAMETER_TYPES(13, __thiscall);
        MEMBER_PARAMETER_TYPES(14, __thiscall);
        MEMBER_PARAMETER_TYPES(15, __thiscall);
        MEMBER_PARAMETER_TYPES(16, __thiscall);
        MEMBER_PARAMETER_TYPES(17, __thiscall);
        MEMBER_PARAMETER_TYPES(18, __thiscall);
        MEMBER_PARAMETER_TYPES(19, __thiscall);
        MEMBER_PARAMETER_TYPES(20, __thiscall);
    #endif

    // The TypeListTypes struct maps a return type and TYPELIST type into a 'prototype'-style definition. For example,
    //
    //    TypeListTypes<int, TYPELIST_2(wchar_t*, float)>::Prototype = int (wchar_t*, float)
    template <typename TReturnType, typename TTypeList>
    struct TypeListTypes;

    #define TYPELISTTYPES(PARAMCOUNT)                                                      \
    BUILD_VARIABLE_NAME(PARAMETER_TYPES_TEMPLATE_, PARAMCOUNT)                             \
    struct TypeListTypes<TR, BUILD_VARIABLE_NAME(PARAMETER_TYPES_TYPELIST_, PARAMCOUNT)>   \
    {                                                                                      \
        typedef TR Prototype(BUILD_VARIABLE_NAME(PARAMETER_TYPES_ARGS_, PARAMCOUNT));      \
    }

    TYPELISTTYPES(0);
    TYPELISTTYPES(1);
    TYPELISTTYPES(2);
    TYPELISTTYPES(3);
    TYPELISTTYPES(4);
    TYPELISTTYPES(5);
    TYPELISTTYPES(6);
    TYPELISTTYPES(7);
    TYPELISTTYPES(8);
    TYPELISTTYPES(9);
    TYPELISTTYPES(10);
    TYPELISTTYPES(11);
    TYPELISTTYPES(12);
    TYPELISTTYPES(13);
    TYPELISTTYPES(14);
    TYPELISTTYPES(15);
    TYPELISTTYPES(16);
    TYPELISTTYPES(17);
    TYPELISTTYPES(18);
    TYPELISTTYPES(19);
    TYPELISTTYPES(20);
} /* namespace Common */ } /* namespace WEX */
