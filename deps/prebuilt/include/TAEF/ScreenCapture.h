//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Public C++ ScreenCapture API.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Common.h"

#include <windows.h>

#pragma push_macro("SEALED")
#undef SEALED

#if _MSC_VER >= 1800
# define SEALED final
#elif _MSC_VER >= 1400
# define SEALED sealed
#elif defined(_MSC_VER)
# define SEALED
#else
# define SEALED final
#endif

namespace WEX { namespace Common
{
    /// <summary>
    /// The possible ImageFormats that a ScreenCapture can be saved in.
    /// </summary>
    namespace ImageFormats
    {
        enum Format
        {
            /// Uses a lossless format.
            Lossless = 0,

            /// Uses the HDPhoto format.
            HDPhoto,

            /// Uses the PNG format.
            PNG,

            /// Uses the BMP format.
            BMP,

            /// Uses the JPEG format.
            JPEG,

            /// Will use the lowest image format possible on this system (usually JPEG).
            LowQuality,

            /// \internal
            Unknown
        };
    }

    /// <summary>
    /// The possible settings for capturing the mouse cursor
    /// </summary>
    namespace ScreenCaptureOptions
    {
        enum Options
        {
            /// No options specified
            None = 0,

            /// Show the mouse cursor in the screen shot
            ShowMouseCursor = 1,

            /// \internal
            Unknown = 2
        };
    }

    class NoThrowString;

    /// <summary>
    /// Defines a class that provides the ability to save ScreenCaptures.
    /// </summary>
    class WEXCOMMON_API ScreenCapture SEALED
    {
    public:
        /// <summary>Takes a screen capture of all monitors and saves it to disk without the mouse cursor included, and defaults to ImageFormats::LowQuality.</summary>
        /// <param name="pszFilePath">The file to save to.</param>
        static HRESULT __stdcall Save(const wchar_t* pszFilePath);

        /// <summary>Takes a screen capture of all monitors and saves it to disk in the specified ImageFormats::Format; does not capture the mouse cursor in the screenshot.</summary>
        /// <param name="pszFilePath">The file to save to.</param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        static HRESULT __stdcall Save(const wchar_t* pszFilePath, ImageFormats::Format imageFormat);

        /// <summary>Takes a screen capture of all monitors and saves it to disk as ImageFormats::LowQuality; captures the mouse cursor in the screenshot if requested.</summary>
        /// <param name="pszFilePath">The file to save to.</param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(const wchar_t* pszFilePath, ScreenCaptureOptions::Options captureOptions);

        /// <summary>Takes a screen capture of all monitors and saves it to disk in the spedified ImageFormats::Format; captures the mouse cursor in the screenshot if requested.</summary>
        /// <param name="pszFilePath">The file to save to.</param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(const wchar_t* pszFilePath, ImageFormats::Format imageFormat, ScreenCaptureOptions::Options captureOptions);


        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk without the mouse cursor included, and defaults to ImageFormats::LowQuality.</summary>
        /// <param name="rect">A RECT that defines the region of the Desktop to save - in Desktop co-ordinates.</param>
        /// <param name="pszFilePath">The file to save to.</param>
        static HRESULT __stdcall Save(RECT rect, const wchar_t* pszFilePath);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk in the specified ImageFormats::Format; does not capture the mouse cursor in the screenshot.</summary>
        /// <param name="rect">A RECT that defines the region of the Desktop to save - in Desktop co-ordinates.</param>
        /// <param name="pszFilePath">The file to save to.</param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        static HRESULT __stdcall Save(RECT rect, const wchar_t* pszFilePath, ImageFormats::Format imageFormat);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk as ImageFormats::LowQuality; captures the mouse cursor in the screenshot if requested.</summary>
        /// <param name="rect">A RECT that defines the region of the Desktop to save - in Desktop co-ordinates.</param>
        /// <param name="pszFilePath">The file to save to.</param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(RECT rect, const wchar_t* pszFilePath, ScreenCaptureOptions::Options captureOptions);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk in the spedified ImageFormats::Format; captures the mouse cursor in the screenshot if requested.</summary>
        /// <param name="rect">A RECT that defines the region of the Desktop to save - in Desktop co-ordinates.</param>
        /// <param name="pszFilePath">The file to save to.</param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(RECT rect, const wchar_t* pszFilePath, ImageFormats::Format imageFormat, ScreenCaptureOptions::Options captureOptions);


        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk without the mouse cursor included, and defaults to ImageFormats::LowQuality.</summary>
        /// <param name="left"></param>
        /// <param name="top"></param>
        /// <param name="right"></param>
        /// <param name="bottom"></param>
        /// <param name="pszFilePath">The file to save to.</param>
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, const wchar_t* pszFilePath);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk in the specified ImageFormats::Format; does not capture the mouse cursor in the screenshot.</summary>
        /// <param name="left"></param>
        /// <param name="top"></param>
        /// <param name="right"></param>
        /// <param name="bottom"></param>
        /// <param name="pszFilePath">The file to save to.</param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, const wchar_t* pszFilePath,
                                      ImageFormats::Format imageFormat);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk as ImageFormats::LowQuality; captures the mouse cursor in the screenshot if requested.</summary>
        /// <param name="left"></param>
        /// <param name="top"></param>
        /// <param name="right"></param>
        /// <param name="bottom"></param>
        /// <param name="pszFilePath">The file to save to.</param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, const wchar_t* pszFilePath, ScreenCaptureOptions::Options captureOptions);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk in the spedified ImageFormats::Format; captures the mouse cursor in the screenshot if requested.</summary>
        /// <param name="left"></param>
        /// <param name="top"></param>
        /// <param name="right"></param>
        /// <param name="bottom"></param>
        /// <param name="pszFilePath">The file to save to.</param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, const wchar_t* pszFilePath, ImageFormats::Format imageFormat, ScreenCaptureOptions::Options captureOptions);


        /// <summary>Takes a screen capture of all monitors and saves it to disk without the mouse cursor included, and defaults to ImageFormats::LowQuality; also updates filePath if the file extension has been modified</summary>
        /// <param name="filePath"></param>
        static HRESULT __stdcall Save(NoThrowString& filePath);

        /// <summary>Takes a screen capture of all monitors and saves it to disk in the specified ImageFormats::Format; does not capture the mouse cursor in the screenshot; also updates filePath if the file extension has been modified</summary>
        /// <param name="filePath"></param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        static HRESULT __stdcall Save(NoThrowString& filePath, ImageFormats::Format imageFormat);

        /// <summary>Takes a screen capture of all monitors and saves it to disk as ImageFormats::LowQuality; captures the mouse cursor in the screenshot if requested; also updates filePath if the file extension has been modified</summary>
        /// <param name="filePath"></param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(NoThrowString& filePath, ScreenCaptureOptions::Options captureOptions);

        /// <summary>Takes a screen capture of all monitors and saves it to disk in the spedified ImageFormats::Format; captures the mouse cursor in the screenshot if requested; also updates filePath if the file extension has been modified</summary>
        /// <param name="filePath"></param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(NoThrowString& filePath, ImageFormats::Format imageFormat, ScreenCaptureOptions::Options captureOptions);


        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk without the mouse cursor included, and defaults to ImageFormats::LowQuality; also updates filePath if the file extension has been modified</summary>
        /// <param name="rect">A RECT that defines the region of the Desktop to save - in Desktop co-ordinates.</param>
        /// <param name="filePath"></param>
        static HRESULT __stdcall Save(RECT rect, NoThrowString& filePath);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk in the specified ImageFormats::Format; does not capture the mouse cursor in the screenshot; also updates filePath if the file extension has been modified</summary>
        /// <param name="rect">A RECT that defines the region of the Desktop to save - in Desktop co-ordinates.</param>
        /// <param name="filePath"></param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        static HRESULT __stdcall Save(RECT rect, NoThrowString& filePath, ImageFormats::Format imageFormat);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk as ImageFormats::LowQuality; captures the mouse cursor in the screenshot if requested; also updates filePath if the file extension has been modified</summary>
        /// <param name="rect">A RECT that defines the region of the Desktop to save - in Desktop co-ordinates.</param>
        /// <param name="filePath"></param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(RECT rect, NoThrowString& filePath, ScreenCaptureOptions::Options captureOptions);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk in the spedified ImageFormats::Format; captures the mouse cursor in the screenshot if requested; also updates filePath if the file extension has been modified</summary>
        /// <param name="rect">A RECT that defines the region of the Desktop to save - in Desktop co-ordinates.</param>
        /// <param name="filePath"></param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        /// <param name="imageFormat">The ImageFormats::Format to save as. Defaults to ImageFormats::LowQuality.</param>
        static HRESULT __stdcall Save(RECT rect, NoThrowString& filePath, ImageFormats::Format imageFormat, ScreenCaptureOptions::Options captureOptions);


        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk without the mouse cursor included, and defaults to ImageFormats::LowQuality; also updates filePath if the file extension has been modified</summary>
        /// <param name="left"></param>
        /// <param name="top"></param>
        /// <param name="right"></param>
        /// <param name="bottom"></param>
        /// <param name="filePath"></param>
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, NoThrowString& filePath);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk in the specified ImageFormats::Format; does not capture the mouse cursor in the screenshot; also updates filePath if the file extension has been modified</summary>
        /// <param name="left"></param>
        /// <param name="top"></param>
        /// <param name="right"></param>
        /// <param name="bottom"></param>
        /// <param name="filePath"></param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, NoThrowString& filePath, ImageFormats::Format imageFormat);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk as ImageFormats::LowQuality; captures the mouse cursor in the screenshot if requested; also updates filePath if the file extension has been modified</summary>
        /// <param name="left"></param>
        /// <param name="top"></param>
        /// <param name="right"></param>
        /// <param name="bottom"></param>
        /// <param name="filePath"></param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, NoThrowString& filePath, ScreenCaptureOptions::Options captureOptions);

        /// <summary>Takes a screen capture of a specific rectangle and saves it to disk in the spedified ImageFormats::Format; captures the mouse cursor in the screenshot if requested; also updates filePath if the file extension has been modified</summary>
        /// <param name="left"></param>
        /// <param name="top"></param>
        /// <param name="right"></param>
        /// <param name="bottom"></param>
        /// <param name="filePath"></param>
        /// <param name="imageFormat">The ImageFormats::Format to save as.</param>
        /// <param name="captureOptions">Whether or not to capture the mouse cursor in the screenshot.</param>
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, NoThrowString& filePath, ImageFormats::Format imageFormat, ScreenCaptureOptions::Options captureOptions);

        // wchar_t native type exports
        #ifdef WEXCOMMON_FULL_BUILD
        static HRESULT __stdcall Save(const __wchar_t* pszFilePath);        
        static HRESULT __stdcall Save(const __wchar_t* pszFilePath, ImageFormats::Format imageFormat);        
        static HRESULT __stdcall Save(const __wchar_t* pszFilePath, ScreenCaptureOptions::Options captureOptions);
        static HRESULT __stdcall Save(const __wchar_t* pszFilePath, ImageFormats::Format imageFormat, ScreenCaptureOptions::Options captureOptions);

        static HRESULT __stdcall Save(RECT rect, const __wchar_t* pszFilePath);
        static HRESULT __stdcall Save(RECT rect, const __wchar_t* pszFilePath, ImageFormats::Format imageFormat);
        static HRESULT __stdcall Save(RECT rect, const __wchar_t* pszFilePath, ScreenCaptureOptions::Options captureOptions);
        static HRESULT __stdcall Save(RECT rect, const __wchar_t* pszFilePath, ImageFormats::Format imageFormat, ScreenCaptureOptions::Options captureOptions);

        static HRESULT __stdcall Save(int left, int top, int right, int bottom, const __wchar_t* pszFilePath);
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, const __wchar_t* pszFilePath, ImageFormats::Format imageFormat);
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, const __wchar_t* pszFilePath, ScreenCaptureOptions::Options captureOptions);
        static HRESULT __stdcall Save(int left, int top, int right, int bottom, const __wchar_t* pszFilePath, ImageFormats::Format imageFormat, ScreenCaptureOptions::Options captureOptions);
        #endif

    private:
        ScreenCapture(); // Disallow construction of static class
        ~ScreenCapture(); // Disallow destruction of static class
        ScreenCapture(const ScreenCapture&); // non-implemented
        ScreenCapture& operator=(const ScreenCapture&); // non-implemented
    };

    inline ScreenCaptureOptions::Options& operator|=(ScreenCaptureOptions::Options& lhs, const ScreenCaptureOptions::Options& rhs)
    {
        lhs = static_cast<ScreenCaptureOptions::Options>((static_cast<int>(lhs) | static_cast<int>(rhs)));
        return lhs;
    }

    inline ScreenCaptureOptions::Options operator|(ScreenCaptureOptions::Options lhs, const ScreenCaptureOptions::Options& rhs)
    {
        return lhs |= rhs;
    }

    inline int operator&(ScreenCaptureOptions::Options lhs, const ScreenCaptureOptions::Options& rhs)
    {
        return (static_cast<int>(lhs) & static_cast<int>(rhs));
    }
} /* namespace Common */ } /* namespace WEX */

#pragma pop_macro("SEALED")
