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

#include <mach-o/dyld.h>

/**
@Status Caveat
@Notes Always returns zero
*/
extern "C" int32_t NSVersionOfRunTimeLibrary(const char* libraryName) {
    // Ideally the return value should match what is returned on the
    // reference platform that we're emulating
    return 0;
}

/**
@Status Caveat
@Notes Always returns zero
*/
extern "C" int32_t NSVersionOfLinkTimeLibrary(const char* libraryName) {
    return 0;
}
