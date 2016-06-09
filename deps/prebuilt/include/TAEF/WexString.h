//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>
/// Wex String classes.  Use the String class in exception-throwing environments,
/// and the NoThrowString class in non exception-throwing environments.  The NoThrowString
/// class is an exception-safe wrapper around the String class.
/// </summary>
/// <remarks>
/// When using the String class, you must be sure that you are handling WEX::Common::Exceptions around any
/// non-const member function calls.  
/// 
/// When using the NoThrowString class, you should call IsValid after every call to a non-const
/// member function in order to check that the string contents are still valid.  
/// You can also call GetLastHResult() for more information.
/// </remarks>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Common.h"
#include "WexTypes.h"

#include <stdarg.h>

#pragma push_macro("_In_opt_z_")
#pragma push_macro("_In_reads_or_z_")
#pragma push_macro("_In_reads_or_z_opt_")
#pragma push_macro("_In_z_")
#pragma push_macro("_Post_equal_to_")
#pragma push_macro("_Printf_format_string_")
#pragma push_macro("_Ret_writes_")

#if !defined(_In_opt_z_)
#define _In_opt_z_
#endif

#if !defined(_In_reads_or_z_)
#define _In_reads_or_z_(x)
#endif

#if !defined(_In_reads_or_z_opt_)
#define _In_reads_or_z_opt_(x)
#endif

#if !defined(_In_z_)
#define _In_z_
#endif

#if !defined(_Post_equal_to_)
#define _Post_equal_to_(x)
#endif

#if !defined(_Printf_format_string_)
#define _Printf_format_string_
#endif

#if !defined(_Ret_writes_)
#define _Ret_writes_(x)
#endif

/// \namespace WEX::Common
/// <summary>
/// The WEX::Common namespace contains fundamental declarations.
/// </summary>
namespace WEX { namespace Common
{
    class NoThrowString;

    /// <summary>
    /// Wex String classes.  Use the String class in exception-throwing environments,
    /// and the NoThrowString class in non exception-throwing environments.  The NoThrowString
    /// class is an exception-safe wrapper around the String class.
    /// </summary>
    class WEXCOMMON_API String
    {
    public:
        /// <summary>Constructs an empty String.</summary>
        String();

        /// <summary>Constructs a String with the same contents as the specified NoThrowString.</summary>
        /// <param name="str">The NoThrowString instance to copy the contents from.</param>
        String(const NoThrowString& str);

        /// <summary></summary>
        /// <param name="psz"> </param>
        String(_In_opt_z_ wchar_t* psz);

        /// <summary>Constructs a String object, and copies the requested number of characters from the specified wchar_t*</summary>
        /// <param name="psz"> </param>
        /// <param name="count"> </param>
        String(_In_reads_or_z_opt_(count) const wchar_t* psz, int count);

        /// <summary></summary>
        /// <param name="psz"> </param>
        String(_In_opt_z_ char* psz);

        /// <summary></summary>
        /// <param name="psz"> </param>
        String(_In_opt_z_ const wchar_t* psz);

        /// <summary></summary>
        /// <param name="psz"> </param>
        String(_In_opt_z_ const char* psz);

        /// <summary>Destroys the String free'ing all associated resources.</summary>
        ~String();

        /// <summary>Move constructor</summary>
        /// <param name="str"> </param>
        String(String&& str);

        // Copy constructor
        /// <summary> </summary>
        /// <param name="str"> </param>
        String(const String& str);

        // Assignment
        /// <summary>Move assignment operator from NoThrowString. If the NoThrowString is not valid, the String remains unchanged.</summary>
        /// <param name="strSrc"> </param>
        const String& operator =(NoThrowString&& strSrc);

        /// <summary></summary>
        /// <param name="strSrc"> </param>
        const String& operator =(String strSrc);

        /// <summary>Copy assignment operator from NoThrowString. If the NoThrowString is not valid, the String remains unchanged.</summary>
        /// <param name="strSrc"> </param>
        const String& operator =(const NoThrowString& strSrc);

        /// <summary></summary>
        /// <param name="ch"> </param>
        const String& operator =(wchar_t ch);

        /// <summary></summary>
        /// <param name="ch"> </param>
        const String& operator =(char ch);

        /// <summary></summary>
        /// <param name="psz"> </param>
        const String& operator =(_In_opt_z_ const wchar_t* psz);

        /// <summary></summary>
        /// <param name="psz"> </param>
        const String& operator =(_In_opt_z_ const char* psz);

        /// <summary></summary>
        /// <param name="psz"> </param>
        const String& operator =(_In_opt_z_ const unsigned char* psz); 

        // Appending (For concatenation, see outside of the class definition below)

        /// <summary></summary>
        /// <param name="str"> </param>
        const String& operator +=(const String& str);

        /// <summary></summary>
        /// <param name="ch"> </param>
        /// <param name="ch"> </param>
        const String& operator +=(wchar_t ch);

        /// <summary></summary>
        /// <param name="ch"> </param>
        const String& operator +=(char ch);

        /// <summary></summary>
        /// <param name="psz"> </param>
        const String& operator +=(_In_z_ const wchar_t* psz);

        // Conversion
        operator const wchar_t*() const;

        // Helper Methods
        /// <summary>Append a specified string to an existing String</summary>
        /// <param name="strSrc">The String to append.</param>
        /// <param name="strSrc"> </param>
        String& Append(const String& strSrc);

        /// <summary>Append a specified string to an existing String</summary>
        /// <param name="pszSrc"> </param>
        String& Append(_In_z_ const wchar_t* pszSrc);

        /// <summary>Append a given character to this string</summary>
        /// <param name="ch"> </param>
        String& Append(wchar_t ch);

        /// <summary>Append a given character to this string</summary>
        /// <param name="ch"> </param>
        String& Append(char ch);

        /// <summary>Appends formatted data to an existing string</summary>
        /// <param name="pszFormat"> </param>
        String& AppendFormat(_In_z_ _Printf_format_string_ const wchar_t* pszFormat, ...);

        /// <summary>Appends formatted data to an existing string</summary>
        /// <param name="pszFormat"> </param>
        /// <param name="args"> </param>
        String& AppendFormatV(_In_z_ _Printf_format_string_ const wchar_t* pszFormat, va_list args);

        /// <summary>Compares two strings (case sensitive)</summary>
        /// <param name="pszCompare"> </param>
        int Compare(_In_z_ const wchar_t* pszCompare) const;

        /// <summary>Compares two strings (case insensitive).</summary>
        /// <param name="pszCompare"> </param>
        int CompareNoCase(_In_z_ const wchar_t* pszCompare) const;

        /// <summary>Copies the requested number of characters from the specified wchar_t*.  Allocates more space if necessary.</summary>
        /// <param name="pszSrc"> </param>
        /// <param name="count"> </param>
        void Copy(_In_reads_or_z_(count) const wchar_t* pszSrc, int count);

        /// <summary>Deletes a character or characters from a string</summary>
        /// <param name="index"> </param>
        /// <param name="count"> </param>
        int Delete(int index, int count = 1);

        /// <summary>Empties the string</summary>
        void Empty();

        /// <summary>Searches the string for the first match of the specified character</summary>
        /// <param name="ch"> </param>
        /// <returns>The zero-based index of the first character in this String object that matches
        /// the requested character or -1 if the character is not found.</returns>
        int Find(wchar_t ch) const;

        /// <summary>Searches the string for the first match of the specified character</summary>
        /// <param name="ch"> </param>
        /// <param name="start"> </param>
        /// <returns>The zero-based index of the first character in this String object after the start
        /// offset that matches the requested character or -1 if the character is not found.</returns>
        int Find(wchar_t ch, int start) const;

        /// <summary>Searches the string for the first match of the specified substring</summary>
        /// <param name="pszSub"> </param>
        /// <returns>The zero-based index of the first substring in this String object that matches
        /// the requested substring or -1 if the substring is not found.</returns>
        int Find(_In_z_ const wchar_t* pszSub) const;

        /// <summary>Searches the string for the first match of the specified substring</summary>
        /// <param name="pszSub"> </param>
        /// <param name="start"> </param>
        /// <returns>The zero-based index of the first substring in this String object after the start
        /// offset that matches the requested substring or -1 if the substring is not found.</returns>
        int Find(_In_z_ const wchar_t* pszSub, int start) const;

        /// <summary>Formats the string as swprintf does</summary>
        /// <param name="pszFormat"> </param>
        String& Format(_In_z_ _Printf_format_string_ const wchar_t* pszFormat, ...);

        /// <summary>Formats the string as swprintf does</summary>
        /// <param name="pszFormat"> </param>
        /// <param name="args"> </param>
        String& FormatV(_In_z_ _Printf_format_string_ const wchar_t* pszFormat, va_list args);

        /// <summary>Frees any extra memory previously allocated by the string but no longer needed</summary>
        void FreeExtra();

        /// <summary>Returns the count of characters in the string</summary>
        int GetLength() const;

        /// <summary>Inserts a single character at the given index within the string</summary>
        /// <param name="index"> </param>
        /// <param name="ch"> </param>
        int Insert(int index, wchar_t ch);

        /// <summary>Inserts a substring at the given index within the string</summary>
        /// <param name="index"> </param>
        /// <param name="psz"> </param>
        int Insert(int index, _In_z_ const wchar_t* psz);

        /// <summary>Returns whether or not the string is empty</summary>
        bool IsEmpty() const;

        /// <summary>Returns a non-const pointer to the underlying string buffer.  If you write to the buffer using this pointer, be sure to call ReleaseBuffer when finished.</summary>
        unsigned short* GetBuffer();

        /// <summary>Returns a pointer to the internal character buffer for the String object, truncating or growing its length if necessary to exactly match the length specified in Length</summary>
        /// <param name="length"> </param>
        _Ret_writes_(length + 1) unsigned short* GetBufferSetLength(int length);

        /// <summary>Call this method to reallocate or free up the buffer of the string object, If you know that the string in the buffer is null terminated, you can omit the newLength argument. If your string is not null terminated, use newLength to specify its length. NOTE: The address returned by GetBuffer is invalid after the call to ReleaseBuffer </summary>
        /// <param name="newLength"> </param>
        void ReleaseBuffer(int newLength = -1);

        /// <summary>Extracts the first (leftmost) count characters from the string</summary>
        /// <param name="count"> </param>
        String Left(int count) const;

        /// <summary>Extracts a substring of length count characters, starting at position first </summary>
        /// <param name="first"> </param>
        /// <param name="count"> </param>
        String Mid(int first, int count) const;

        /// <summary>Extracts a substring of length count characters, starting at position first </summary>
        /// <param name="first"> </param>
        String Mid(int first) const;

        /// <summary>Removes instances of the specified character from the string</summary>
        /// <param name="removeChar"> </param>
        int Remove(wchar_t removeChar);

        /// <summary>Replaces all instances of one character with another</summary>
        /// <param name="oldChar"> </param>
        /// <param name="newChar"> </param>
        int Replace(wchar_t oldChar, wchar_t newChar);

        /// <summary>Replaces all instances of one substring with another</summary>
        /// <param name="pszOld"> </param>
        /// <param name="pszNew"> </param>
        int Replace(_In_z_ const wchar_t* pszOld, _In_z_ const wchar_t* pszNew);

        /// <summary>Reverses the order of characters in the string</summary>
        void Reverse();

        /// <summary>Searches for a character inside a larger string; starts at the end of the string</summary>
        /// <returns>The zero-based index of the last character in this String object that matches the requested character, or -1 if the character is not found.</returns>
        /// <param name="ch">The character to look for.</param>
        int ReverseFind(wchar_t ch) const;

        /// <summary>Extracts the last (rightmost) count characters from the string </summary>
        /// <param name="count"> </param>
        String Right(int count) const;

        /// <summary>Converts all the characters in this string to lower-case </summary>
        String& ToLower();

        /// <summary>Converts all the characters in this string to upper-case </summary>
        String& ToUpper();

        /// <summary>Trims all leading and trailing whitespace, new line, tab and space characters from the string</summary>
        void Trim();

        /// <summary>Trims all leading and trailing whitespace, new line, tab and space characters from the left portion of the string</summary>
        void TrimLeft();

        /// <summary>Trims all leading and trailing whitespace, new line, tab and space characters from the right portion of the string</summary>
        void TrimRight();

        /// <summary>Returns whether or not the specified const wchar_t* is null or an empty string</summary>
        /// <param name="psz">The const wchar_t* to check.</param>
        /// <returns> </returns>
        _Post_equal_to_(!psz || *psz == 0)
        static bool __stdcall IsNullOrEmpty(_In_opt_z_ const wchar_t* psz)
        {
            return !psz || *psz == L'\0';
        }

        // wchar_t native type exports
        #ifdef BUILD_WCHAR_T_EXPORTS
        operator const __wchar_t*() const;
        #endif

        #ifdef WEXCOMMON_FULL_BUILD
        String(_In_opt_z_ __wchar_t* psz);
        String(_In_reads_or_z_opt_(count) const __wchar_t* psz, int count);
        String(_In_opt_z_ const __wchar_t* psz);

        const String& operator =(__wchar_t ch);
        const String& operator =(_In_opt_z_ const __wchar_t* psz);

        const String& operator +=(__wchar_t ch);
        const String& operator +=(_In_z_ const __wchar_t* psz);

        String& Append(_In_z_ const __wchar_t* pszSrc);
        String& Append(__wchar_t ch);
        String& AppendFormat(_In_z_ _Printf_format_string_ const __wchar_t* pszFormat, ...);
        String& AppendFormatV(_In_z_ _Printf_format_string_ const __wchar_t* pszFormat, va_list args);
        int Compare(_In_z_ const __wchar_t* pszCompare) const;
        int CompareNoCase(_In_z_ const __wchar_t* pszCompare) const;
        void Copy(_In_reads_or_z_(count) const __wchar_t* pszSrc, int count);
        int Find(__wchar_t ch) const;
        int Find(__wchar_t ch, int start) const;
        int Find(_In_z_ const __wchar_t* pszSub) const;
        int Find(_In_z_ const __wchar_t* pszSub, int start) const;
        String& Format(_In_z_ _Printf_format_string_ const __wchar_t* pszFormat, ...);
        String& FormatV(_In_z_ _Printf_format_string_ const __wchar_t* pszFormat, va_list args);
        int Insert(int index, __wchar_t ch);
        int Insert(int index, _In_z_ const __wchar_t* psz);
        int Remove(__wchar_t removeChar);
        int Replace(__wchar_t oldChar, __wchar_t newChar);
        int Replace(_In_z_ const __wchar_t* pszOld, _In_z_ const __wchar_t* pszNew);
        int ReverseFind(__wchar_t ch) const;

        static bool __stdcall IsNullOrEmpty(const __wchar_t* psz)
        {
            return IsNullOrEmpty(reinterpret_cast<const unsigned short*>(psz));
        }
        #endif // WEXCOMMON_API

    private:
        friend WEXCOMMON_API int __stdcall GetBufferLength(const String& string);
        friend WEXCOMMON_API void __stdcall swap(String& str1, String& str2);

        void UpdateDebugPointer();

        struct StringImpl;
        StringImpl* m_pImpl;
        const wchar_t* m_psz;
    };

    /// <summary>A function that retrieves the length of the allocated buffer backing a String instance.</summary>
    /// <param name="string">The String to retrieve the buffer length of.</param>
    /// <returns>The length of the allocated buffer, in characters.</returns>
    WEXCOMMON_API int __stdcall GetBufferLength(const String& string);
    
    WEXCOMMON_API bool __stdcall operator==(const String& str1, const String& str2);

    WEXCOMMON_API bool __stdcall operator==(const String& str, _In_z_ const wchar_t* psz);
    
    WEXCOMMON_API bool __stdcall operator==(_In_z_ const wchar_t* psz, const String& str);
    
    WEXCOMMON_API bool __stdcall operator!=(const String& str1, const String& str2);

    WEXCOMMON_API bool __stdcall operator!=(const String& str, _In_z_ const wchar_t* psz);

    WEXCOMMON_API bool __stdcall operator!=(_In_z_ const wchar_t* psz, const String& str);
    
    WEXCOMMON_API bool __stdcall operator<(const String& str1, const String& str2);

    WEXCOMMON_API bool __stdcall operator<(const String& str, _In_z_ const wchar_t* psz);
    
    WEXCOMMON_API bool __stdcall operator<(_In_z_ const wchar_t* psz, const String& str);
    
    WEXCOMMON_API bool __stdcall operator>(const String& str1, const String& str2);

    WEXCOMMON_API bool __stdcall operator>(const String& str, _In_z_ const wchar_t* psz);

    WEXCOMMON_API bool __stdcall operator>(_In_z_ const wchar_t* psz, const String& str);
    
    WEXCOMMON_API bool __stdcall operator<=(const String& str1, const String& str2);

    WEXCOMMON_API bool __stdcall operator<=(const String& str, _In_z_ const wchar_t* psz);
    
    WEXCOMMON_API bool __stdcall operator<=(_In_z_ const wchar_t* psz, const String& str);
    
    WEXCOMMON_API bool __stdcall operator>=(const String& str1, const String& str2);
    
    WEXCOMMON_API bool __stdcall operator>=(const String& str, _In_z_ const wchar_t* psz);
    
    WEXCOMMON_API bool __stdcall operator>=(_In_z_ const wchar_t* psz, const String& str);

    // Concatenation
    /// <summary></summary>
    /// <param name="str1"> </param>
    /// <param name="str2"> </param>
    WEXCOMMON_API String __stdcall operator+(String str1, const String& str2);

    /// <summary></summary>
    /// <param name="str"> </param>
    /// <param name="ch"> </param>
    WEXCOMMON_API String __stdcall operator+(String str, wchar_t ch);

    /// <summary></summary>
    /// <param name="ch"> </param>
    /// <param name="str"> </param>
    WEXCOMMON_API String __stdcall operator+(wchar_t ch, const String& str);

    /// <summary></summary>
    /// <param name="str"> </param>
    /// <param name="ch"> </param>
    WEXCOMMON_API String __stdcall operator+(String str, char ch);

    /// <summary></summary>
    /// <param name="ch"> </param>
    /// <param name="str"> </param>
    WEXCOMMON_API String __stdcall operator+(char ch, const String& str);

    /// <summary></summary>
    /// <param name="str"> </param>
    /// <param name="lpsz"> </param>
    WEXCOMMON_API String __stdcall operator+(String str, _In_z_ const wchar_t* lpsz);

    /// <summary></summary>
    /// <param name="psz"> </param>
    /// <param name="str"> </param>
    WEXCOMMON_API String __stdcall operator+(_In_z_ const wchar_t* psz, const String& str);

    // wchar_t native type exports
    #ifdef WEXCOMMON_FULL_BUILD
    WEXCOMMON_API bool __stdcall operator==(const String& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator==(_In_z_ const __wchar_t* psz, const String& str);
    WEXCOMMON_API bool __stdcall operator!=(const String& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator!=(_In_z_ const __wchar_t* psz, const String& str);
    WEXCOMMON_API bool __stdcall operator<(const String& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator<(_In_z_ const __wchar_t* psz, const String& str);
    WEXCOMMON_API bool __stdcall operator>(const String& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator>(_In_z_ const __wchar_t* psz, const String& str);
    WEXCOMMON_API bool __stdcall operator<=(const String& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator<=(_In_z_ const __wchar_t* psz, const String& str);
    WEXCOMMON_API bool __stdcall operator>=(const String& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator>=(_In_z_ const __wchar_t* psz, const String& str);
    WEXCOMMON_API String __stdcall operator+(String str, __wchar_t ch);
    WEXCOMMON_API String __stdcall operator+(__wchar_t ch, const String& str);
    WEXCOMMON_API String __stdcall operator+(String str, _In_z_ const __wchar_t* lpsz);
    WEXCOMMON_API String __stdcall operator+(_In_z_ const __wchar_t* psz, const String& str);
    #endif

    WEXCOMMON_API void __stdcall swap(String& str1, String& str2);

    /// <summary>
    /// Wex String classes.  Use the String class in exception-throwing environments,
    /// and the NoThrowString class in non exception-throwing environments.  The NoThrowString
    /// class is an exception-safe wrapper around the String class.
    /// </summary>
    class WEXCOMMON_API NoThrowString
    {
    friend class String;
    public:
        NoThrowString();
        NoThrowString(const String& str);
        NoThrowString(_In_opt_z_ wchar_t* psz);
        NoThrowString(_In_reads_or_z_opt_(count) const wchar_t* psz, int count); // Constructs a NoThrowString object, and copies the requested number of characters from the specified wchar_t*
        NoThrowString(_In_opt_z_ char* psz);
        NoThrowString(_In_opt_z_ const wchar_t* psz);
        NoThrowString(_In_opt_z_ const char* psz);
        ~NoThrowString();

        // Move constructor
        NoThrowString(NoThrowString&& str);

        // Copy constructor
        NoThrowString(const NoThrowString& str);

        // Assignment
        const NoThrowString& operator =(NoThrowString strSrc);
        const NoThrowString& operator =(const String& strSrc);
        const NoThrowString& operator =(wchar_t ch);
        const NoThrowString& operator =(char ch);
        const NoThrowString& operator =(_In_opt_z_ const wchar_t* psz);
        const NoThrowString& operator =(_In_opt_z_ const char* psz);
        const NoThrowString& operator =(_In_opt_z_ const unsigned char* psz); 

        // Appending (For concatenation, see outside of the class definition below)
        const NoThrowString& operator +=(const NoThrowString& str);
        const NoThrowString& operator +=(wchar_t ch);
        const NoThrowString& operator +=(char ch);
        const NoThrowString& operator +=(_In_z_ const wchar_t* psz); 

        // Conversion
        operator const wchar_t*() const;

        // Helper Methods
        const wchar_t* ToCStrWithFallbackTo(_In_z_ const wchar_t* pszDefaultString) const;

        /// <summary>Append a specified string to an existing NoThrowString</summary>
        NoThrowString& Append(const NoThrowString& strSrc);

        /// <summary>Append a specified string to an existing NoThrowString</summary>
        NoThrowString& Append(_In_z_ const wchar_t* pszSrc);

        /// <summary>Append a given character to this string</summary>
        NoThrowString& Append(wchar_t ch);

        /// <summary>Append a given character to this string</summary>
        NoThrowString& Append(char ch);

        /// <summary>Appends formatted data to an existing string</summary>
        NoThrowString& AppendFormat(_In_z_ _Printf_format_string_ const wchar_t* pszFormat, ...);

        /// <summary>Appends formatted data to an existing string</summary>
        /// <param name="pszFormat"> </param>
        /// <param name="args"> </param>
        NoThrowString& AppendFormatV(_In_z_ _Printf_format_string_ const wchar_t* pszFormat, va_list args);

        /// <summary>Compares two strings (case sensitive)</summary>
        int Compare(_In_z_ const wchar_t* pszCompare) const;

        /// <summary>Compares two strings (case insensitive).</summary>
        int CompareNoCase(_In_z_ const wchar_t* pszCompare) const;

        /// <summary>Copies the requested number of characters from the specified wchar_t*.  Allocates more space if necessary.</summary>
        void Copy(_In_reads_or_z_(count) const wchar_t* pszSrc, int count);

        /// <summary>Deletes a character or characters from a string</summary>
        int Delete(int index, int count = 1);

        /// <summary>Empties the string</summary>
        void Empty();

        /// <summary>Searches the string for the first match of the specified character</summary>
        int Find(wchar_t ch) const;

        /// <summary>Searches the string for the first match of the specified character</summary>
        int Find(wchar_t ch, int start) const;

        /// <summary>Searches the string for the first match of the specified substring</summary>
        int Find(_In_z_ const wchar_t* pszSub) const;

        /// <summary>Searches the string for the first match of the specified substring</summary>
        int Find(_In_z_ const wchar_t* pszSub, int start) const;

        /// <summary>Formats the string as swprintf does</summary>
        NoThrowString& Format(_In_z_ _Printf_format_string_ const wchar_t* pszFormat, ...);

        /// <summary>Formats the string as swprintf does</summary>
        /// <param name="pszFormat"> </param>
        /// <param name="args"> </param>
        NoThrowString& FormatV(_In_z_ _Printf_format_string_ const wchar_t* pszFormat, va_list args);

        /// <summary>Frees any extra memory previously allocated by the string but no longer needed</summary>
        void FreeExtra();

        /// <summary>Returns the count of characters in the string</summary>
        int GetLength() const;

        /// <summary>Inserts a single character at the given index within the string</summary>
        int Insert(int index, wchar_t ch);

        /// <summary>Inserts a substring at the given index within the string</summary>
        int Insert(int index, _In_z_ const wchar_t* psz);

        /// <summary>Returns whether or not the string is empty</summary>
        bool IsEmpty() const;

        /// <summary>Returns a non-const pointer to the underlying string buffer.  If you write to the buffer using this pointer, be sure to call ReleaseBuffer when finished.</summary>
        unsigned short* GetBuffer();

        /// <summary>Returns a pointer to the internal character buffer for the NoThrowString object, truncating or growing its length if necessary to exactly match the length specified in Length</summary>
        _Ret_writes_(length + 1) unsigned short* GetBufferSetLength(int length);

        /// <summary>Call this method to reallocate or free up the buffer of the string object, If you know that the string in the buffer is null terminated, you can omit the newLength argument. If your string is not null terminated, use newLength to specify its length. NOTE: The address returned by GetBuffer is invalid after the call to ReleaseBuffer </summary>
        void ReleaseBuffer(int newLength = -1);

        /// <summary>Extracts the first (leftmost) count characters from the string</summary>
        NoThrowString Left(int count) const;

        /// <summary>Extracts a substring of length count characters, starting at position first </summary>
        NoThrowString Mid(int first, int count) const;

        /// <summary>Extracts a substring of length count characters, starting at position first </summary>
        NoThrowString Mid(int first) const;

        /// <summary>Removes instances of the specified character from the string</summary>
        int Remove(wchar_t removeChar);

        /// <summary>Replaces all instances of one character with another</summary>
        int Replace(wchar_t oldChar, wchar_t newChar);

        /// <summary>Replaces all instances of one substring with another</summary>
        int Replace(_In_z_ const wchar_t* pszOld, _In_z_ const wchar_t* pszNew);

        /// <summary>Reverses the order of characters in the string</summary>
        void Reverse();

        /// <summary>Searches for a character inside a larger string; starts at the end of the string</summary>
        int ReverseFind(wchar_t ch) const;

        /// <summary>Extracts the last (rightmost) count characters from the string </summary>
        NoThrowString Right(int count) const;

        /// <summary>Converts all the characters in this string to lower-case </summary>
        NoThrowString& ToLower();

        /// <summary>Converts all the characters in this string to upper-case </summary>
        NoThrowString& ToUpper();

        /// <summary>Trims all leading and trailing whitespace, new line, tab and space characters from the string</summary>
        void Trim();

        /// <summary>Trims all leading and trailing whitespace, new line, tab and space characters from the left portion of the string</summary>
        void TrimLeft();

        /// <summary>Trims all leading and trailing whitespace, new line, tab and space characters from the right portion of the string</summary>
        void TrimRight();

        /// <summary>Returns whether or not the string contents are still valid.  This method should be called after any non-const NoThrowString member functions are called in order to check for validity of string contents.</summary>
        bool IsValid() const;

        /// <summary>Returns the last error encountered by the NoThrowString class</summary>
        HRESULT GetLastHResult() const;

        // Returns whether or not the specified const wchar_t* is null or an empty string
        static bool __stdcall IsNullOrEmpty(const wchar_t* psz)
        {
            return !psz || !*psz || *psz == L'\0';
        }

        // WCHAR_T native type exports
        #ifdef BUILD_WCHAR_T_EXPORTS
        operator const __wchar_t*() const;
        #endif

        #ifdef WEXCOMMON_FULL_BUILD
        NoThrowString(_In_opt_z_ __wchar_t* psz);
        NoThrowString(_In_reads_or_z_opt_(count) const __wchar_t* psz, int count); // Constructs a String object, and copies the requested number of characters from the specified wchar_t*
        NoThrowString(_In_opt_z_ const __wchar_t* psz);

        const NoThrowString& operator =(__wchar_t ch);
        const NoThrowString& operator =(_In_opt_z_ const __wchar_t* psz);

        const NoThrowString& operator +=(__wchar_t ch);
        const NoThrowString& operator +=(_In_z_ const __wchar_t* psz);

        const __wchar_t* ToCStrWithFallbackTo(_In_z_ const __wchar_t* pszDefaultString) const;
        NoThrowString& Append(_In_z_ const __wchar_t* pszSrc);
        NoThrowString& Append(__wchar_t ch);
        NoThrowString& AppendFormat(_In_z_ _Printf_format_string_ const __wchar_t* pszFormat, ...);
        NoThrowString& AppendFormatV(_In_z_ _Printf_format_string_ const __wchar_t* pszFormat, va_list args);
        int Compare(_In_z_ const __wchar_t* pszCompare) const;
        int CompareNoCase(_In_z_ const __wchar_t* pszCompare) const;
        void Copy(_In_reads_or_z_(count) const __wchar_t* pszSrc, int count);
        int Find(__wchar_t ch) const;
        int Find(__wchar_t ch, int start) const;
        int Find(_In_z_ const __wchar_t* pszSub) const;
        int Find(_In_z_ const __wchar_t* pszSub, int start) const;
        NoThrowString& Format(_In_z_ _Printf_format_string_ const __wchar_t* pszFormat, ...);
        NoThrowString& FormatV(_In_z_ _Printf_format_string_ const __wchar_t* pszFormat, va_list args);
        int Insert(int index, __wchar_t ch);
        int Insert(int index, _In_z_ const __wchar_t* psz);
        int Remove(__wchar_t removeChar);
        int Replace(__wchar_t oldChar, __wchar_t newChar);
        int Replace(_In_z_ const __wchar_t* pszOld, _In_z_ const __wchar_t* pszNew);
        int ReverseFind(__wchar_t ch) const;

        static bool __stdcall IsNullOrEmpty(const __wchar_t* psz)
        {
            return IsNullOrEmpty(reinterpret_cast<const unsigned short*>(psz));
        }
        #endif // WEXCOMMON_API

    private:
        NoThrowString(HRESULT hr);
        String* m_pImpl;

        friend WEXCOMMON_API int __stdcall GetBufferLength(const NoThrowString& string);
        friend WEXCOMMON_API void __stdcall swap(NoThrowString& str1, NoThrowString& str2);
        void UpdateDebugPointer();

        HRESULT m_lastHr;
        const wchar_t* m_psz;
    };

    WEXCOMMON_API int __stdcall GetBufferLength(const NoThrowString& string);

    WEXCOMMON_API bool __stdcall operator==(const NoThrowString& str1, const NoThrowString& str2);

    WEXCOMMON_API bool __stdcall operator==(const NoThrowString& str, _In_z_ const wchar_t* psz);
    
    WEXCOMMON_API bool __stdcall operator==(_In_z_ const wchar_t* psz, const NoThrowString& str);
    
    WEXCOMMON_API bool __stdcall operator!=(const NoThrowString& str1, const NoThrowString& str2);

    WEXCOMMON_API bool __stdcall operator!=(const NoThrowString& str, _In_z_ const wchar_t* psz);

    WEXCOMMON_API bool __stdcall operator!=(_In_z_ const wchar_t* psz, const NoThrowString& str);
    
    WEXCOMMON_API bool __stdcall operator<(const NoThrowString& str1, const NoThrowString& str2);

    WEXCOMMON_API bool __stdcall operator<(const NoThrowString& str, _In_z_ const wchar_t* psz);
    
    WEXCOMMON_API bool __stdcall operator<(_In_z_ const wchar_t* psz, const NoThrowString& str);
    
    WEXCOMMON_API bool __stdcall operator>(const NoThrowString& str1, const NoThrowString& str2);

    WEXCOMMON_API bool __stdcall operator>(const NoThrowString& str, _In_z_ const wchar_t* psz);

    WEXCOMMON_API bool __stdcall operator>(_In_z_ const wchar_t* psz, const NoThrowString& str);
    
    WEXCOMMON_API bool __stdcall operator<=(const NoThrowString& str1, const NoThrowString& str2);

    WEXCOMMON_API bool __stdcall operator<=(const NoThrowString& str, _In_z_ const wchar_t* psz);
    
    WEXCOMMON_API bool __stdcall operator<=(_In_z_ const wchar_t* psz, const NoThrowString& str);
    
    WEXCOMMON_API bool __stdcall operator>=(const NoThrowString& str1, const NoThrowString& str2);
    
    WEXCOMMON_API bool __stdcall operator>=(const NoThrowString& str, _In_z_ const wchar_t* psz);
    
    WEXCOMMON_API bool __stdcall operator>=(_In_z_ const wchar_t* psz, const NoThrowString& str);


    // Concatenation
    /// <summary> </summary>
    /// <param name="str1"> </param>
    /// <param name="str2"> </param>
    WEXCOMMON_API NoThrowString __stdcall operator+(NoThrowString str1, const NoThrowString& str2);

    /// <summary> </summary>
    /// <param name="ch"> </param>
    WEXCOMMON_API NoThrowString __stdcall operator+(NoThrowString str, wchar_t ch);

    /// <summary> </summary>
    /// <param name="ch"> </param>
    /// <param name="str"> </param>
    WEXCOMMON_API NoThrowString __stdcall operator+(wchar_t ch, const NoThrowString& str);

    /// <summary> </summary>
    /// <param name="str"> </param>
    /// <param name="ch"> </param>
    WEXCOMMON_API NoThrowString __stdcall operator+(NoThrowString str, char ch);

    /// <summary> </summary>
    /// <param name="ch"> </param>
    /// <param name="str"> </param>
    WEXCOMMON_API NoThrowString __stdcall operator+(char ch, const NoThrowString& str);

    /// <summary> </summary>
    /// <param name="str"> </param>
    /// <param name="lpsz"> </param>
    WEXCOMMON_API NoThrowString __stdcall operator+(NoThrowString str, _In_z_ const wchar_t* lpsz);

    /// <summary> </summary>
    /// <param name="psz"> </param>
    /// <param name="str"> </param>
    WEXCOMMON_API NoThrowString __stdcall operator+(_In_z_ const wchar_t* psz, const NoThrowString& str);

    // wchar_t native type exports
    #ifdef WEXCOMMON_FULL_BUILD
    WEXCOMMON_API bool __stdcall operator==(const NoThrowString& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator==(_In_z_ const __wchar_t* psz, const NoThrowString& str);
    WEXCOMMON_API bool __stdcall operator!=(const NoThrowString& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator!=(_In_z_ const __wchar_t* psz, const NoThrowString& str);
    WEXCOMMON_API bool __stdcall operator<(const NoThrowString& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator<(_In_z_ const __wchar_t* psz, const NoThrowString& str);
    WEXCOMMON_API bool __stdcall operator>(const NoThrowString& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator>(_In_z_ const __wchar_t* psz, const NoThrowString& str);
    WEXCOMMON_API bool __stdcall operator<=(const NoThrowString& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator<=(_In_z_ const __wchar_t* psz, const NoThrowString& str);
    WEXCOMMON_API bool __stdcall operator>=(const NoThrowString& str, _In_z_ const __wchar_t* psz);
    WEXCOMMON_API bool __stdcall operator>=(_In_z_ const __wchar_t* psz, const NoThrowString& str);
    WEXCOMMON_API NoThrowString __stdcall operator+(NoThrowString str, __wchar_t ch);
    WEXCOMMON_API NoThrowString __stdcall operator+(__wchar_t ch, const NoThrowString& str);
    WEXCOMMON_API NoThrowString __stdcall operator+(NoThrowString str, _In_z_ const __wchar_t* lpsz);
    WEXCOMMON_API NoThrowString __stdcall operator+(_In_z_ const __wchar_t* psz, const NoThrowString& str);
    #endif

    WEXCOMMON_API void __stdcall swap(NoThrowString& str1, NoThrowString& str2);
} /* namespace Common */ } /* namespace WEX */

#pragma pop_macro("_In_opt_z_")
#pragma pop_macro("_In_reads_or_z_")
#pragma pop_macro("_In_reads_or_z_opt_")
#pragma pop_macro("_In_z_")
#pragma pop_macro("_Post_equal_to_")
#pragma pop_macro("_Printf_format_string_")
#pragma pop_macro("_Ret_writes_")
