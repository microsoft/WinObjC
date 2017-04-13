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

#include <wrl/client.h>
#include <Windows.Storage.streams.h>

// Issue #2506: The IBufferByteAccess declared in RoBuffer.h is not parsable by clang

#if __clang__
// STDMETHOD generates a warning when building for ARM
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wignored-attributes"
#endif

// clang-format off
struct __declspec(uuid("905a0fef-bc53-11df-8c49-001e4fc686da")) __declspec(novtable) IBufferByteAccess : public IUnknown
{
    // an IBuffer object is created by a client, and the buffer is provided by IBufferByteAccess::Buffer.
    STDMETHOD(Buffer)(_Outptr_result_buffer_(_Inexpressible_("size given by different API")) byte** value) = 0;
};
// clang-format on

#if __clang__
#pragma clang diagnostic pop
#endif

// Interop between WRL and ObjC is *incredibly* frustrating so define a helper function
// to help isolate the code as much as possible.
extern "C" HRESULT BufferFromRawData(ABI::Windows::Storage::Streams::IBuffer** buffer, unsigned char* data, unsigned int length);