//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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
//******************************************************************************
// Windows Internal Libraries (wil)
//! @file
//! Dependency-free straight c++ helpers, macros and type traits.
//! This file is always included implicitly by all wil headers.  It contains helpers that are broadly applicable without
//! requiring any dependencies.  Including this file naturally includes wistd_type_traits.h to supply functionality such
//! as `wistd::move()` to exception-free code.

#pragma once
#ifndef __cplusplus
#error This file is designed for C++ consumers only
#endif
#pragma warning(push)
#pragma warning(disable:4714)    // __forceinline not honored

// DO NOT add *any* further includes to this file -- there should be no dependencies from its usage
#include "wistd_type_traits.h"


// Some SAL remapping / decoration to better support Doxygen.  Macros that look like function calls can
// confuse Doxygen when they are used to decorate a function or variable.  We simplify some of these to
// basic macros without the function for common use cases.
//! @cond
#define _Success_return_ _Success_(return)
#define _Success_true_ _Success_(true)
#define __declspec_noinline_ __declspec(noinline)
#define __declspec_selectany_ __declspec(selectany)
//! @encdond

#if defined(_CPPUNWIND) && !defined(WIL_SUPPRESS_EXCEPTIONS)
//! This define is automatically set when exceptions are enabled within wil.
//! It is automatically defined when your code is compiled with exceptions enabled (via checking for the built-in
//! _CPPUNWIND flag) unless you explicitly define WIL_SUPPRESS_EXCEPTIONS ahead of including your first wil
//! header.  All exception-based WIL methods and classes are included behind:
//! ~~~~
//! #ifdef WIL_ENABLE_EXCEPTIONS
//! // code
//! #endif
//! ~~~~
//! This enables exception-free code to directly include WIL headers without worrying about exception-based
//! routines suddenly becoming available.
#define WIL_ENABLE_EXCEPTIONS
#endif

// block for documentation only
#if defined(WIL_DOXYGEN)
//! This define can be explicitly set to disable exception usage within wil.
//! Normally this define is never needed as the WIL_ENABLE_EXCEPTIONS macro is enabled automatically by looking
//! at _CPPUNWIND.  If your code compiles with exceptions enabled, but does not want to enable the exception-based
//! classes and methods from WIL, define this macro ahead of including the first WIL header.
#define WIL_SUPPRESS_EXCEPTIONS
#endif


//! @defgroup bitwise Bitwise Inspection and Manipulation
//! Bitwise helpers to improve readability and reduce the error rate of bitwise operations.
//! Several macros have been constructed to assist with bitwise inspection and manipulation.  These macros exist
//! for two primary purposes:
//!
//! 1. To improve the readability of bitwise comparisons and manipulation.
//!
//!    The macro names are the more concise, readable form of what's being done and do not require that any flags
//!    or variables be specified multiple times for the comparisons.
//!
//! 2. To reduce the error rate associated with bitwise operations.
//!
//!    The readability improvements naturally lend themselves to this by cutting down the number of concepts.
//!    Using `WI_IS_FLAG_SET(var, MyEnum::Flag)` rather than `((var & MyEnum::Flag) == MyEnum::Flag)` removes the comparison 
//!    operator and repetition in the flag value.
//!
//!    Additionally, these macros separate single flag operations (which tend to be the most common) from multi-flag 
//!    operations so that compile-time errors are generated for bitwise operations which are likely incorrect,
//!    such as:  `WI_IS_FLAG_SET(var, MyEnum::None)` or `WI_IS_FLAG_SET(var, MyEnum::ValidMask)`.
//! 
//! Note that the single flag helpers should be used when a compile-time constant single flag is being manipulated.  These
//! helpers provide compile-time errors on misuse and should be preferred over the multi-flag helpers.  The multi-flag helpers
//! should be used when multiple flags are being used simultaneously or when the flag values are not compile-time constants.
//!
//! Common example usage (manipulation of flag variables):
//! ~~~~
//! WI_SET_FLAG(m_flags, MyFlags::Foo);                                 // Set a single flag in the given variable
//! WI_SET_ALL_FLAGS(m_flags, MyFlags::Foo | MyFlags::Bar);             // Set one or more flags
//! WI_CLEAR_FLAG_IF(m_flags, MyFlags::Bar, isBarClosed);               // Conditionally clear a single flag based upon a bool
//! WI_CLEAR_ALL_FLAGS(m_flags, MyFlags::Foo | MyFlags::Bar);           // Clear one or more flags from the given variable
//! WI_TOGGLE_FLAG(m_flags, MyFlags::Foo);                              // Toggle (change to the opposite value) a single flag
//! WI_UPDATE_FLAG(m_flags, MyFlags::Bar, isBarClosed);                 // Sets or Clears a single flag from the given variable based upon a bool value
//! WI_UPDATE_FLAGS_IN_MASK(m_flags, flagsMask, newFlagValues);         // Sets or Clears the flags in flagsMask to the masked values from newFlagValues
//! ~~~~
//! Common example usage (inspection of flag variables):
//! ~~~~
//! if (WI_IS_FLAG_SET(m_flags, MyFlags::Foo))                          // Is a single flag set in the given variable?
//! if (WI_IS_ANY_FLAG_SET(m_flags, MyFlags::Foo | MyFlags::Bar))       // Is at least one flag from the given mask set?
//! if (WI_ARE_ALL_FLAGS_CLEAR(m_flags, MyFlags::Foo | MyFlags::Bar))   // Are all flags in the given list clear?
//! if (WI_IS_SINGLE_FLAG_SET(m_flags))                                 // Is *exactly* one flag set in the given variable?
//! ~~~~
//! @{

// block for documentation only
#ifdef WIL_DOXYGEN

//! Validates that exactly ONE bit is set in compile-time constant `flag` or a compilation error is produced.
#define WI_STATIC_ASSERT_SINGLE_BIT_SET(flag)

//! @name Bitwise modification macros
//! @{

//! Set multiple bitflags specified by `flags` in the variable `var`.
#define WI_SET_ALL_FLAGS(var, flags)
//! Set a single compile-time constant `flag` in the variable `var`.
#define WI_SET_FLAG(var, flag)
//! Conditionally sets a single compile-time constant `flag` in the variable `var` only if `condition` is true.
#define WI_SET_FLAG_IF(var, flag, condition)
//! Conditionally sets a single compile-time constant `flag` in the variable `var` only if `condition` is false.
#define WI_SET_FLAG_IF_FALSE(var, flag, condition)

//! Clear multiple bitflags specified by `flags` from the variable `var`.
#define WI_CLEAR_ALL_FLAGS(var, flags)
//! Clear a single compile-time constant `flag` from the variable `var`.
#define WI_CLEAR_FLAG(var, flag)
//! Conditionally clear a single compile-time constant `flag` in the variable `var` only if `condition` is true.
#define WI_CLEAR_FLAG_IF(var, flag, condition)
//! Conditionally clear a single compile-time constant `flag` in the variable `var` only if `condition` is false.
#define WI_CLEAR_FLAG_IF_FALSE(var, flag, condition)

//! Changes a single compile-time constant `flag` in the variable `var` to be set if `isFlagSet` is true or cleared if `isFlagSet` is false.
#define WI_UPDATE_FLAG(var, flag, isFlagSet)
//! Changes only the flags specified by `flagsMask` in the variable `var` to match the corresponding flags in `newFlags`.
#define WI_UPDATE_FLAGS_IN_MASK(var, flagsMask, newFlags)

//! Toggles (XOR the value) of multiple bitflags specified by `flags` in the variable `var`.
#define WI_TOGGLE_ALL_FLAGS(var, flags)
//! Toggles (XOR the value) of a single compile-time constant `flag` in the variable `var`.
#define WI_TOGGLE_FLAG(var, flag)
//! @}      // bitwise modification helpers

//! @name Bitwise inspection macros
//! @{

//! Evaluates as true if every bitflag specified in `flags` is set within `val`.
#define WI_ARE_ALL_FLAGS_SET(val, flags)
//! Evaluates as true if one or more bitflags specified in `flags` are set within `val`.
#define WI_IS_ANY_FLAG_SET(val, flags)
//! Evaluates as true if a single compile-time constant `flag` is set within `val`.
#define WI_IS_FLAG_SET(val, flag)

//! Evaluates as true if every bitflag specified in `flags` is clear within `val`.
#define WI_ARE_ALL_FLAGS_CLEAR(val, flags)
//! Evaluates as true if one or more bitflags specified in `flags` are clear within `val`.
#define WI_IS_ANY_FLAG_CLEAR(val, flags)
//! Evaluates as true if a single compile-time constant `flag` is clear within `val`.
#define WI_IS_FLAG_CLEAR(val, flag)

//! Evaluates as true if exactly one bit (any bit) is set within `val`.
#define WI_IS_SINGLE_FLAG_SET(val)
//! Evaluates as true if exactly one bit from within the specified `mask` is set within `val`.
#define WI_IS_SINGLE_FLAG_SET_IN_MASK(val, mask)
//! Evaluates as true if exactly one bit (any bit) is set within `val` or if there are no bits set within `val`.
#define WI_IS_CLEAR_OR_SINGLE_FLAG_SET(val)
//! Evaluates as true if exactly one bit from within the specified `mask` is set within `val` or if there are no bits from `mask` set within `val`.
#define WI_IS_CLEAR_OR_SINGLE_FLAG_SET_IN_MASK(val, mask)
//! @}

//! This define can be explicitly set to enable usage of PascalCase() macro names for bitwise operations.
//! Defining WIL_SUPPORT_BITOPERATION_PASCAL_NAMES ahead of including a WIL header will enable the PascalCase name variants
//! for all of the bitwise test and manipulation macros.  For example, when this define is set, you can use `SetFlag(var, flag)`
//! in addition to the standard WIL macro name `WI_SET_FLAG(var, flag)`.
//!
//! These names are not enabled by default given the likelihood of a macro name like 'SetFlag' conflicting with existing code.
//! Traditionally shell has enabled these fairly natural names through the cstock header, so they are provided as an option for teams 
//! to enable.
#define WIL_SUPPORT_BITOPERATION_PASCAL_NAMES

//! @name PascalNames for bitwise helper macros
//! These are not enabled by default (see @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES for more information).
//! @{

//! Alias for @ref WI_SET_ALL_FLAGS when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define SetAllFlags(var, flags)
//! Alias for @ref WI_SET_FLAG when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define SetFlag(var, flag)
//! Alias for @ref WI_SET_FLAG_IF when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define SetFlagIf(var, flag, condition)
//! Alias for @ref WI_SET_FLAG_IF_FALSE when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define SetFlagIfFalse(var, flag, condition)

//! Alias for @ref WI_CLEAR_ALL_FLAGS when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define ClearAllFlags(var, flags)
//! Alias for @ref WI_CLEAR_FLAG when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define ClearFlag(var, flag)
//! Alias for @ref WI_CLEAR_FLAG_IF when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define ClearFlagIf(var, flag, condition)
//! Alias for @ref WI_CLEAR_FLAG_IF_FALSE when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define ClearFlagIfFalse(var, flag, condition)

//! Alias for @ref WI_UPDATE_FLAG when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define UpdateFlag(var, flag, isFlagSet)
//! Alias for @ref WI_UPDATE_FLAGS_IN_MASK when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define UpdateFlagsInMask(var, flagsMask, newFlags)

//! Alias for @ref WI_TOGGLE_ALL_FLAGS when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define ToggleAllFlags(var, flags)
//! Alias for @ref WI_TOGGLE_FLAG when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define ToggleFlag(var, flag)

//! Alias for @ref WI_ARE_ALL_FLAGS_SET when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define AreAllFlagsSet(val, flags)
//! Alias for @ref WI_IS_ANY_FLAG_SET when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define IsAnyFlagSet(val, flags)
//! Alias for @ref WI_IS_FLAG_SET when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define IsFlagSet(val, flag)

//! Alias for @ref WI_ARE_ALL_FLAGS_CLEAR when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define AreAllFlagsClear(val, flags)
//! Alias for @ref WI_IS_ANY_FLAG_CLEAR when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define IsAnyFlagClear(val, flags)
//! Alias for @ref WI_IS_FLAG_CLEAR when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define IsFlagClear(val, flag)

//! Alias for @ref WI_IS_SINGLE_FLAG_SET when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define IsSingleFlagSet(val)
//! Alias for @ref WI_IS_SINGLE_FLAG_SET_IN_MASK when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define IsSingleFlagSetInMask(val, mask)
//! Alias for @ref WI_IS_CLEAR_OR_SINGLE_FLAG_SET when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define IsClearOrSingleFlagSet(val)
//! Alias for @ref WI_IS_CLEAR_OR_SINGLE_FLAG_SET_IN_MASK when @ref WIL_SUPPORT_BITOPERATION_PASCAL_NAMES is specified.
#define IsClearOrSingleFlagSetInMask(val, mask)
//! @}  // Alternate PascalNames for bitwise helpers

#else // WIL_DOXYGEN

#define WI_STATIC_ASSERT_SINGLE_BIT_SET(flag)               sizeof(wil::details::Single_Bit_Expected_Zero_Or_Multiple_Found<__WI_IS_SINGLE_FLAG_SET(flag) != 0>)

// Macros to manipulate flag bitmasks

#define WI_SET_ALL_FLAGS(var, flags)                        ((var) |= (flags))
#define WI_SET_FLAG(var, flag)                              (WI_STATIC_ASSERT_SINGLE_BIT_SET(flag), WI_SET_ALL_FLAGS(var, flag))
#define WI_SET_FLAG_IF(var, flag, condition)                 do { if (wil::verify_bool(condition)) { WI_SET_FLAG(var, flag); } } while (0, 0)
#define WI_SET_FLAG_IF_FALSE(var, flag, condition)           do { if (!(wil::verify_bool(condition))) { WI_SET_FLAG(var, flag); } } while (0, 0)

#define WI_CLEAR_ALL_FLAGS(var, flags)                      ((var) &= ~(flags))
#define WI_CLEAR_FLAG(var, flag)                            (WI_STATIC_ASSERT_SINGLE_BIT_SET(flag), WI_CLEAR_ALL_FLAGS(var, flag))
#define WI_CLEAR_FLAG_IF(var, flag, condition)               do { if (wil::verify_bool(condition)) { WI_CLEAR_FLAG(var, flag); } } while (0, 0)
#define WI_CLEAR_FLAG_IF_FALSE(var, flag, condition)         do { if (!(wil::verify_bool(condition))) { WI_CLEAR_FLAG(var, flag); } } while (0, 0)

#define WI_UPDATE_FLAG(var, flag, isFlagSet)                (wil::verify_bool(isFlagSet) ? WI_SET_FLAG(var, flag) : WI_CLEAR_FLAG(var, flag))
#define WI_UPDATE_FLAGS_IN_MASK(var, flagsMask, newFlags)   wil::details::UpdateFlagsInMaskHelper(var, flagsMask, newFlags)

#define WI_TOGGLE_FLAG(var, flag)                           (WI_STATIC_ASSERT_SINGLE_BIT_SET(flag), WI_TOGGLE_ALL_FLAGS(var, flag))
#define WI_TOGGLE_ALL_FLAGS(var, flags)                     ((var) ^= (flags))

// Macros to inspect flag bitmasks

#define WI_ARE_ALL_FLAGS_SET(val, flags)                    wil::details::AreAllFlagsSetHelper(val, flags)
#define WI_IS_ANY_FLAG_SET(val, flags)                      wil::details::IsAnyFlagSetHelper(val, flags)
#define WI_IS_FLAG_SET(val, flag)                           (WI_STATIC_ASSERT_SINGLE_BIT_SET(flag), WI_IS_ANY_FLAG_SET(val, flag))

#define WI_ARE_ALL_FLAGS_CLEAR(val, flags)                  wil::details::AreAllFlagsClearHelper(val, flags)
#define WI_IS_ANY_FLAG_CLEAR(val, flags)                    (!wil::details::AreAllFlagsSetHelper(val, flags))
#define WI_IS_FLAG_CLEAR(val, flag)                         (WI_STATIC_ASSERT_SINGLE_BIT_SET(flag), WI_ARE_ALL_FLAGS_CLEAR(val, flag))

#define WI_IS_SINGLE_FLAG_SET(val)                          wil::details::IsSingleFlagSetHelper(val)
#define WI_IS_SINGLE_FLAG_SET_IN_MASK(val, mask)            wil::details::IsSingleFlagSetHelper((val) & (mask))
#define WI_IS_CLEAR_OR_SINGLE_FLAG_SET(val)                 wil::details::IsClearOrSingleFlagSetHelper(val)
#define WI_IS_CLEAR_OR_SINGLE_FLAG_SET_IN_MASK(val, mask)   wil::details::IsClearOrSingleFlagSetHelper((val) & (mask))

#if defined(WIL_SUPPORT_BITOPERATION_PASCAL_NAMES) || defined(SUPPORT_BITOPERATION_PASCAL_NAMES)

#define SetAllFlags(var, flags)                             WI_SET_ALL_FLAGS(var, flags)
#define SetFlag(var, flag)                                  WI_SET_FLAG(var, flag)
#define SetFlagIf(var, flag, condition)                     WI_SET_FLAG_IF(var, flag, condition)
#define SetFlagIfFalse(var, flag, condition)                WI_SET_FLAG_IF_FALSE(var, flag, condition)
#define ClearAllFlags(var, flags)                           WI_CLEAR_ALL_FLAGS(var, flags)
#define ClearFlag(var, flag)                                WI_CLEAR_FLAG(var, flag)
#define ClearFlagIf(var, flag, condition)                   WI_CLEAR_FLAG_IF(var, flag, condition)
#define ClearFlagIfFalse(var, flag, condition)              WI_CLEAR_FLAG_IF_FALSE(var, flag, condition)
#define UpdateFlag(var, flag, isFlagSet)                    WI_UPDATE_FLAG(var, flag, isFlagSet)
#define UpdateFlagsInMask(var, flagsMask, newFlags)         WI_UPDATE_FLAGS_IN_MASK(var, flagsMask, newFlags)
#define ToggleAllFlags(var, flags)                          WI_TOGGLE_ALL_FLAGS(var, flags)
#define ToggleFlag(var, flag)                               WI_TOGGLE_FLAG(var, flag)
#define AreAllFlagsSet(val, flags)                          WI_ARE_ALL_FLAGS_SET(val, flags)
#define IsAnyFlagSet(val, flags)                            WI_IS_ANY_FLAG_SET(val, flags)
#define IsFlagSet(val, flag)                                WI_IS_FLAG_SET(val, flag)
#define AreAllFlagsClear(val, flags)                        WI_ARE_ALL_FLAGS_CLEAR(val, flags)
#define IsAnyFlagClear(val, flags)                          WI_IS_ANY_FLAG_CLEAR(val, flags)
#define IsFlagClear(val, flag)                              WI_IS_FLAG_CLEAR(val, flag)
#define IsSingleFlagSet (val)                               WI_IS_SINGLE_FLAG_SET(val)
#define IsSingleFlagSetInMask(val, mask)                    WI_IS_SINGLE_FLAG_SET_IN_MASK(val, mask)
#define IsClearOrSingleFlagSet(val)                         WI_IS_CLEAR_OR_SINGLE_FLAG_SET(val)
#define IsClearOrSingleFlagSetInMask(val, mask)             WI_IS_CLEAR_OR_SINGLE_FLAG_SET_IN_MASK(val, mask)

#endif // WIL_SUPPORT_BITOPERATION_PASCAL_NAMES
#endif // !WIL_DOXYGEN

//! @deprecated Will be removed in the future.
#define WI_SET_FLAG_IF_TRUE                                 WI_SET_FLAG_IF

//! @}  // end bitfields group


#if defined(WIL_DOXYGEN)
//! This macro provides a C++ header with a guaranteed initialization function.
//! Normally, were a global object's constructor used for this purpose, the optimizer/linker might throw
//! the object away if it's unreferenced (which throws away the side-effects that the initialization function
//! was trying to achieve).  Using this macro forces linker inclusion of a variable that's initialized by the
//! provided function to elide that optimization.
//!
//! This functionality is primarily provided as a building block for header-based libraries (such as WIL)
//! to be able to layer additional functionality into other libraries by their mere inclusion.  Alternative models
//! of initialization should be used whenever they are available.
//! ~~~~
//! #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
//! WI_HEADER_INITITALIZATION_FUNCTION(InitializeDesktopFamilyApis, []
//! {
//!     g_pfnGetModuleName              = GetCurrentModuleName;
//!     g_pfnFailFastInLoaderCallout    = FailFastInLoaderCallout;
//!     g_pfnRtlNtStatusToDosErrorNoTeb = RtlNtStatusToDosErrorNoTeb;
//!     return 1;
//! });
//! #endif
//! ~~~~
//! The above example is used within WIL to decide whether or not the library containing WIL is allowed to use
//! desktop APIs.  Building this functionality as #IFDEFs within functions would create ODR violations, whereas
//! doing it with global function pointers and header initialization allows a runtime determination.
#define WI_HEADER_INITITALIZATION_FUNCTION(name, fn)
#elif defined(_M_IX86)
#define WI_HEADER_INITITALIZATION_FUNCTION(name, fn) \
    extern "C" { __declspec(selectany) size_t g_header_init_ ## name = fn(); } \
    __pragma(comment(linker, "/INCLUDE:_g_header_init_" #name))
#elif defined(_M_IA64) || defined(_M_AMD64) || defined(_M_ARM) || defined(_M_ARM64)
#define WI_HEADER_INITITALIZATION_FUNCTION(name, fn) \
    extern "C" { __declspec(selectany) size_t g_header_init_ ## name = fn(); } \
    __pragma(comment(linker, "/INCLUDE:g_header_init_" #name))
#else
    #error linker pragma must include g_header_init variation
#endif


//! All Windows Internal Library classes and functions are located within the "wil" namespace.
//! The 'wil' namespace is an intentionally short name as the intent is for code to be able to reference
//! the namespace directly (example: `wil::srwlock lock;`) without a using statement.  Resist adding a using
//! statement for wil to avoid introducing potential name collisions between wil and other namespaces.
namespace wil
{
    //! @defgroup outparam Output Parameters
    //! Improve the conciseness of assigning values to optional output parameters.
    //! @{

    //! Assign a value-type to an optional output parameter.
    //! Functions may have optional output parameters that want to receive a value calculated
    //! as part of the function.  Using this routine allows removal of many `if (param != nullptr)` blocks when
    //! commonly dealing with out parameters in routines.
    //! ~~~~
    //! void PerformTask(_Out_opt_ TaskResult* pResult = nullptr)
    //! {
    //!     TaskResult result = TaskResult::None;
    //!     // calculate result
    //!     wil::AssignToOptParam(pResult, result);
    //! }
    //! ~~~~
    //! @param outParam The optional out-pointer
    //! @param val The value to set in `outParam` if the out-pointer is non-null
    template <typename T>
    inline void AssignToOptParam(_Out_opt_ T *outParam, T val)
    {
        if (outParam != nullptr)
        {
            *outParam = val;
        }
    }

    //! Assign nullptr to an optional output pointer parameter.
    //! Functions may have optional output pointer parameters that want to receive an object from
    //! a function.  Using this routine provides trivial best practice initialization of an optional pointer-based
    //! output parameter on routine entry and will typically be combined with use of @ref AssignToOptParam or 
    //! @ref DetachToOptParam on routine exit.
    //! ~~~~
    //! bool HasString(_Out_opt_ PCWSTR* outString = nullptr)
    //! {
    //!     wil::AssignNullToOptParam(outString);
    //!     wil::unique_cotaskmem_string str = GetStringInternal();
    //!     bool hasString = (str != nullptr);
    //!     wil::DetachToOptParam(outString, str);
    //!     return hasString;
    //! }
    //! ~~~~
    //! @param outParam The optional out-pointer
    //! @param val The value to set in `outParam` if the out-pointer is non-null
    template <typename T>
    inline void AssignNullToOptParam(_Out_opt_ T *outParam)
    {
        if (outParam != nullptr)
        {
            *outParam = nullptr;
        }
    }

    //! @}      // end output parameter helpers


    //! @cond
    namespace details
    {
        template <typename T>
        __forceinline bool verify_bool_helper(T const& t, wistd::true_type)
        {
            return static_cast<bool>(t);
        }

        template <typename T>
        __forceinline bool verify_bool_helper(T const& t, wistd::false_type)
        {
            static_assert((wistd::is_same<T, bool>::value), "Wrong Type: bool/BOOL/BOOLEAN/boolean expected");
        }

        template <>
        __forceinline bool verify_bool_helper<bool>(bool const& t, wistd::false_type)
        {
            return t;
        }

        template <>
        __forceinline bool verify_bool_helper<int>(int const& t, wistd::false_type)     // This supports BOOL
        {
            return (t != 0);
        }

        template <>
        __forceinline bool verify_bool_helper<unsigned char>(unsigned char const& t, wistd::false_type)     // This supports BOOLEAN and boolean
        {
            return !!t;
        }
    }
    //! @endcond


    //! @defgroup typesafety Type Validation
    //! Helpers to validate variable types to prevent accidental, but allowed type conversions.
    //! These helpers are most useful when building macros that accept a particular type.  Putting these functions around the types accepted
    //! prior to pushing that type through to a function (or using it within the macro) allows the macro to add an additional layer of type
    //! safety that would ordinarily be stripped away by C++ implicit conversions.  This system is extensively used in the error handling helper
    //! macros to validate the types given to various macro parameters.
    //! @{

    //! Verify that `val` can be evaluated as a logical bool.
    //! Other types will generate an intentional compilation error.  Allowed types for a logical bool are bool, BOOL,
    //! boolean, BOOLEAN, and classes with an explicit bool cast.
    //! @param val The logical bool expression
    //! @return A C++ bool representing the evaluation of `val`.
    template <typename T>
    __forceinline bool verify_bool(T const& val)
    {
        return details::verify_bool_helper(val, typename wistd::is_class<T>::type());
    }

    //! Verify that `val` is a Win32 BOOL value.
    //! Other types (including other logical bool expressions) will generate an intentional compilation error.  Note that this will
    //! accept any `int` value as long as that is the underlying typedef behind `BOOL`.
    //! @param val The Win32 BOOL returning expression
    //! @return A Win32 BOOL representing the evaluation of `val`.
    template <typename T>
    __forceinline int verify_BOOL(T const& val)
    {
        // Note: Written in terms of 'int' as BOOL is actually:  typedef int BOOL;
        static_assert((wistd::is_same<T, int>::value), "Wrong Type: BOOL expected");
        return val;
    }

    //! Verify that `hr` is an HRESULT value.
    //! Other types will generate an intentional compilation error.  Note that this will accept any `long` value as that is the
    //! underlying typedef behind HRESULT.
    //!
    //! Note that occasionally you might run into an HRESULT which is directly defined with a #define, such as:
    //! ~~~~
    //! #define UIA_E_NOTSUPPORTED   0x80040204  
    //! ~~~~
    //! Though this looks like an `HRESULT`, this is actually an `unsigned long` (the hex specification forces this).  When
    //! these are encountered and they are NOT in the public SDK (have not yet shipped to the public), then you should change
    //! their definition to match the manner in which `HRESULT` constants are defined in winerror.h:
    //! ~~~~
    //! #define E_NOTIMPL            _HRESULT_TYPEDEF_(0x80004001L)
    //! ~~~~
    //! When these are encountered in the public SDK, their type should not be changed and you should use a static_cast
    //! to use this value in a macro that utilizes `verify_hresult`, for example:
    //! ~~~~
    //! RETURN_HR_IF_FALSE(static_cast<HRESULT>(UIA_E_NOTSUPPORTED), (patternId == UIA_DragPatternId));
    //! ~~~~
    //! @param val The HRESULT returning expression
    //! @return An HRESULT representing the evaluation of `val`.
    template <typename T>
    _Post_satisfies_(return == hr)
    inline long verify_hresult(const T hr)
    {
        // Note: Written in terms of 'int' as HRESULT is actually:  typedef _Return_type_success_(return >= 0) long HRESULT
        static_assert(wistd::is_same<T, long>::value, "Wrong Type: HRESULT expected");
        return hr;
    }
    //! @}      // end type validation routines


    // Implementation details for macros and helper functions... do not use directly.
    //! @cond
    namespace details
    {
        // Use size-specific casts to avoid sign extending numbers -- avoid warning C4310: cast truncates constant value
        #define __WI_MAKE_UNSIGNED(val) \
            (__pragma(warning(push)) __pragma(warning(disable: 4310 4309)) (sizeof(val) == 1 ? static_cast<unsigned char>(val) : \
                                                                            sizeof(val) == 2 ? static_cast<unsigned short>(val) : \
                                                                            sizeof(val) == 4 ? static_cast<unsigned long>(val) :  \
                                                                            static_cast<unsigned long long>(val)) __pragma(warning(pop)))
        #define __WI_IS_UNSIGNED_SINGLE_FLAG_SET(val) ((val) && !((val) & ((val) - 1)))
        #define __WI_IS_SINGLE_FLAG_SET(val) __WI_IS_UNSIGNED_SINGLE_FLAG_SET(__WI_MAKE_UNSIGNED(val))

        template <bool fSingleStaticFlag>
        class Single_Bit_Expected_Zero_Or_Multiple_Found
        {
            // If you see an error here (something like):
            //      wicommon.h(228): error C2118: negative subscript
            //      helpersuts.cpp(91) : see reference to class template instantiation 'wil::details::Single_Bit_Expected_Zero_Or_Multiple_Found<fSingleStaticFlag>' being compiled
            // The cause is likely the incorrect use of a ZERO or MULTI-BIT mask from a macro that requires a single bit be 
            // set (examples: WI_IS_FLAG_SET, WI_SET_FLAG).
            // For non-static data, the corresponding multiple flag macros can be used (WI_ARE_ALL_FLAGS_SET, WI_SET_ALL_FLAGS, etc)
            char dummyArray[fSingleStaticFlag ? 1 : -1];
        };

        template <typename TVal, typename TFlags>
        __forceinline bool AreAllFlagsSetHelper(TVal val, TFlags flags)
        {
            return ((val & flags) == static_cast<decltype(val & flags)>(flags));
        }

        template <typename TVal>
        __forceinline bool IsSingleFlagSetHelper(TVal val)
        {
            return __WI_IS_SINGLE_FLAG_SET(val);
        }

        template <typename TVal>
        __forceinline bool IsClearOrSingleFlagSetHelper(TVal val)
        {
            return ((val == static_cast<wistd::remove_reference<TVal>::type>(0)) || IsSingleFlagSetHelper(val));
        }

        template <typename TVal, typename TFlags>
        __forceinline bool IsAnyFlagSetHelper(TVal val, TFlags flags)
        {
            return ((val & flags) != static_cast<decltype(val & flags)>(0));
        }
        
        template <typename TVal, typename TFlags>
        __forceinline bool AreAllFlagsClearHelper(TVal val, TFlags flags)
        {
            return ((val & flags) == static_cast<decltype(val & flags)>(0));
        }
        
        template <typename TVal, typename TMask, typename TFlags>
        __forceinline void UpdateFlagsInMaskHelper(_Inout_ TVal& val, TMask mask, TFlags flags)
        {
            val = static_cast<wistd::remove_reference<TVal>::type>((val & ~mask) | (flags & mask));
        }
        
    } // details

} // wil

#pragma warning(pop)
