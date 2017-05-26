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

// WindowsStorageStreams_priv.h
// Forward decls for private object generation
#pragma once

// Can't create proxy instantiator for type: Can't marshal Windows.Foundation.IAsyncOperation`1<UInt32>

// Can't create proxy instantiator for type: Can't marshal Windows.Foundation.IAsyncOperation`1<UInt32>

#include "WindowsFoundation_priv.h"
#include "WindowsStorage_priv.h"
static ComPtr<ABI::Windows::Storage::Streams::IDataReaderFactory> WSSIDataReaderFactory_inst();
ComPtr<ABI::Windows::Storage::Streams::IDataReaderStatics> WSSIDataReaderStatics_inst();
static ComPtr<ABI::Windows::Storage::Streams::IDataWriterFactory> WSSIDataWriterFactory_inst();
ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamStatics> WSSIRandomAccessStreamStatics_inst();
static ComPtr<ABI::Windows::Storage::Streams::IBufferFactory> WSSIBufferFactory_inst();
ComPtr<ABI::Windows::Storage::Streams::IBufferStatics> WSSIBufferStatics_inst();
ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReferenceStatics> WSSIRandomAccessStreamReferenceStatics_inst();

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);

@class RTProxiedNSArray_C_UInt8;
