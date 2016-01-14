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

// clang-format off
// copied from "Robuffer.h" but fixed up the declaration to get it to compile. As it was, I got errors around calling __uuidof
// for an object without a guid. Curious, I know.
struct __declspec(uuid("905a0fef-bc53-11df-8c49-001e4fc686da")) __declspec(novtable) IBufferByteAccess : public IUnknown
{
    // an IBuffer object is created by a client, and the buffer is provided by IBufferByteAccess::Buffer.
    STDMETHOD(Buffer)(_Outptr_result_buffer_(_Inexpressible_("size given by different API")) byte** value) = 0;
};
// clang-format on

// Interop between WRL and ObjC is *incredibly* frustrating so define a helper function
// to help isolate the code as much as possible.
Microsoft::WRL::ComPtr<ABI::Windows::Storage::Streams::IBuffer> BufferFromRawData(unsigned char* data, unsigned int length);