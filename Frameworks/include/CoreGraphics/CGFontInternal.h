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
//******************************************************************************
#pragma once

#import <CoreGraphics/CGFont.h>
#include <COMIncludes.h>
#import <DWrite_3.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>

COREGRAPHICS_EXPORT CGDataProviderRef _CGFontGetData(CGFontRef font);
bool _CGFontGetGlyphsForCharacters(CGFontRef font, const char* chars, size_t count, CGGlyph* glyphs);
HRESULT _CGFontGetDWriteFontFace(CGFontRef font, IDWriteFontFace** outFace);