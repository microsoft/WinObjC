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

#ifndef _CTTEXTTAB_H_
#define _CTTEXTTAB_H_

#import <StarboardExport.h>
#import <CoreText/CTParagraphStyle.h>
#import <CoreFoundation/CFDictionary.h>

typedef const struct __CTTextTab *CTTextTabRef;

SB_EXPORT CTTextTabRef CTTextTabCreate(CTTextAlignment alignment, double location, CFDictionaryRef options);

#endif /* _CTTEXTTAB_H_ */