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

//
// The header file defines a version string for WinMd files
//

#pragma once
#include <corhdr.h>

// This macro is shared by both midlrt and mdmerge. When the version number is bumped, we have to make sure
// the metadata formats used in the tools are matched.
#define WINMD_VERSION_1_2_STRING L"WindowsRuntime 1.2"
#define WINMD_VERSION_1_3_STRING L"WindowsRuntime 1.3"
#define WINMD_VERSION_1_4_STRING L"WindowsRuntime 1.4"

// Current one
#define WINMD_VERSION_STRING WINMD_VERSION_1_4_STRING

// This array contains all the winmd versions that are expected to be readable by
// our metadata tools. When WINMD_VERSION_STRING is modified, its old value should be added
// as an array member here. The ordering is assumed to be fixed in code that references this
// array, so please do not change the ordering of elements unless all referencing code is
// updated as well. (a global search for g_ExpectedWinMdVersionStrings should do it)
static const wchar_t* g_ExpectedWinMdVersionStrings[] = {
    WINMD_VERSION_1_2_STRING, WINMD_VERSION_1_3_STRING, WINMD_VERSION_1_4_STRING,
};

#define SHA1_HASH_ALGO 0x8004 // ECMA 335 II.23.1.1
const DWORD c_WinRTAssemblyFlags = afContentType_WindowsRuntime;