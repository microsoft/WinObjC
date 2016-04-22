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
#pragma once

#ifdef _ARM_

// winnt.h includes some ARM intrinsics that aren't supported in
// clang and cause front end compilation breaks. Because of this,
// change the MSC version to be less than what is needed to
// support that option.
#pragma push_macro("_MSC_FULL_VER")

#if (_MSC_FULL_VER >= 170040825)
#undef _MSC_FULL_VER
#define _MSC_FULL_VER 170040824
#endif

#include_next <winnt.h>

#pragma pop_macro("_MSC_FULL_VER")

#else // Not _ARM_

#include_next <winnt.h>

#endif