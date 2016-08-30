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
//******************************************************************************
#pragma once

#include <COMIncludes.h>
#import <DWrite.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>

#import <Foundation/NSObject.h>
#import <vector>

struct _DWriteGlyphRunDetails {
    std::vector<float> _baselineOriginX;
    std::vector<float> _baselineOriginY;
    std::vector<DWRITE_GLYPH_RUN> _glyphRuns;
    std::vector<DWRITE_GLYPH_RUN_DESCRIPTION> _glyphRunDescriptions;
};

NSArray<NSString*>* _dwriteGetFamilyNames();
NSArray<_CTLine*>* _dwriteGetLines(_CTTypesetter* ts, CFRange range, CGRect frameSize);