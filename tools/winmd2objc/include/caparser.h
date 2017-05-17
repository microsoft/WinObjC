// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.
//
// File: caparser.h
//

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

class CustomAttributeParser {
public:
    CustomAttributeParser( // Constructor for CustomAttributeParser.
        const void* pvBlob, // Pointer to the CustomAttribute blob.
        ULONG cbBlob) // Size of the CustomAttribute blob.
        : m_pbCur(reinterpret_cast<const BYTE*>(pvBlob)),
          m_pbBlob(reinterpret_cast<const BYTE*>(pvBlob)),
          m_cbBlob(cbBlob) {
    }

private:
    signed __int8 GetI1() {
        signed __int8 tmp = *reinterpret_cast<const signed __int8*>(m_pbCur);
        m_pbCur += sizeof(signed __int8);
        return tmp;
    }
    unsigned __int8 GetU1() {
        unsigned __int8 tmp = *reinterpret_cast<const unsigned __int8*>(m_pbCur);
        m_pbCur += sizeof(unsigned __int8);
        return tmp;
    }

    signed __int16 GetI2() {
        signed __int16 tmp = *(__unaligned __int16*)(m_pbCur);
        m_pbCur += sizeof(signed __int16);
        return tmp;
    }
    unsigned __int16 GetU2() {
        unsigned __int16 tmp = *(__unaligned __int16*)(m_pbCur);
        m_pbCur += sizeof(unsigned __int16);
        return tmp;
    }

    signed __int32 GetI4() {
        signed __int32 tmp = *(__unaligned __int32*)(m_pbCur);
        m_pbCur += sizeof(signed __int32);
        return tmp;
    }
    unsigned __int32 GetU4() {
        unsigned __int32 tmp = *(__unaligned __int32*)(m_pbCur);
        m_pbCur += sizeof(unsigned __int32);
        return tmp;
    }

    signed __int64 GetI8() {
        signed __int64 tmp = *(__unaligned __int64*)(m_pbCur);
        m_pbCur += sizeof(signed __int64);
        return tmp;
    }
    unsigned __int64 GetU8() {
        unsigned __int64 tmp = *(__unaligned __int64*)(m_pbCur);
        m_pbCur += sizeof(unsigned __int64);
        return tmp;
    }

public:
    float GetR4() {
        __int32 tmp = *(__unaligned __int32*)(m_pbCur);
        m_pbCur += sizeof(float);
        return (float&)tmp;
    }

    double GetR8() {
        __int64 tmp = *(__unaligned __int64*)(m_pbCur);
        m_pbCur += sizeof(double);
        return (double&)tmp;
    }

private:
    unsigned __int16 GetProlog() {
        unsigned __int16 val;
        GetProlog(&val);
        return val;
    }

    LPCSTR GetString(ULONG* pcbString) {
        LPCSTR val;
        GetString(&val, pcbString);
        return val;
    }

public:
    void GetI1(signed __int8* pVal) {
        if (BytesLeft() < (int)sizeof(signed __int8))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetI1();
    }

    void GetTag(CorSerializationType* pVal) {
        signed __int8 tmp;
        GetI1(&tmp);
        *pVal = (CorSerializationType)((unsigned __int8)tmp);
    }

    void GetU1(unsigned __int8* pVal) {
        if (BytesLeft() < (int)sizeof(unsigned __int8))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetU1();
    }

    void GetI2(signed __int16* pVal) {
        if (BytesLeft() < (int)sizeof(signed __int16))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetI2();
    }
    void GetU2(unsigned __int16* pVal) {
        if (BytesLeft() < (int)sizeof(unsigned __int16))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetU2();
    }

    void GetI4(signed __int32* pVal) {
        if (BytesLeft() < (int)sizeof(signed __int32))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetI4();
    }
    void GetU4(unsigned __int32* pVal) {
        if (BytesLeft() < (int)sizeof(unsigned __int32))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetU4();
    }

    void GetI8(signed __int64* pVal) {
        if (BytesLeft() < (int)sizeof(signed __int64))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetI8();
    }
    void GetU8(unsigned __int64* pVal) {
        if (BytesLeft() < (int)sizeof(unsigned __int64))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetU8();
    }

    void GetR4(float* pVal) {
        if (BytesLeft() < (int)sizeof(float))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetR4();
    }
    void GetR8(double* pVal) {
        if (BytesLeft() < (int)sizeof(double))
            throw META_E_CA_INVALID_BLOB;
        *pVal = GetR8();
    }

    void GetBool(bool* pVal) {
        if (BytesLeft() < (int)sizeof(BYTE))
            throw META_E_CA_INVALID_BLOB;
        *pVal = (bool)(GetI1() != 0);
    }

    void GetProlog(unsigned __int16* pVal) {
        m_pbCur = m_pbBlob;

        if (BytesLeft() < (int)(sizeof(BYTE) * 2))
            throw META_E_CA_INVALID_BLOB;

        GetU2(pVal);
    }

    // Added for compatibility with anyone that may emit
    // blobs where the prolog is the only incorrect data.
    void SkipProlog() {
        unsigned __int16 val;
        GetProlog(&val);
    }

    void ValidateProlog() {
        unsigned __int16 val;
        GetProlog(&val);

        if (val != 0x0001)
            throw META_E_CA_INVALID_BLOB;
    }

    //
    // IMPORTANT: the returned string is typically not null-terminated.
    //
    // This can return any of three distinct valid results:
    //   - NULL string, indicated by *pszString==NULL, *pcbString==0
    //   - empty string, indicated by *pszString!=NULL, *pcbString==0
    //   - non-empty string, indicated by *pdzString!=NULL, *pcbString!=0
    //  If you expect non-null or non-empty strings in your usage scenario,
    //  call the GetNonNullString and GetNonEmptyString helpers below.
    //
    void GetString(LPCSTR* pszString, ULONG* pcbString) {
        if (BytesLeft() == 0) { // Need to check for NULL string sentinal (see below),
            // so need to have at least one byte to read.
            throw META_E_CA_INVALID_BLOB;
        }

        if (*m_pbCur == 0xFF) { // 0xFF indicates the NULL string, which is semantically
            // different than the empty string.
            *pszString = NULL;
            *pcbString = 0;
            m_pbCur++;
        }

        // Get the length, pointer to data following the length.
        GetData((BYTE const**)pszString, pcbString);
    }

    //
    // This can return any of two distinct valid results:
    //   - empty string, indicated by *pszString!=NULL, *pcbString==0
    //   - non-empty string, indicated by *pszString!=NULL, *pcbString!=0
    //  If you expect non-null or non-empty strings in your usage scenario,
    //  call the GetNonNullString and GetNonEmptyString helpers below.
    //
    void GetNonNullString(LPCSTR* pszString, ULONG* pcbString) {
        GetString(pszString, pcbString);
        if (*pszString == NULL) {
            throw META_E_CA_INVALID_BLOB;
        }
    }

    //
    // This function will only return success if the string is valid,
    // non-NULL and non-empty; i.e., *pszString!=NULL, *pcbString!=0
    //
    void GetNonEmptyString(LPCSTR* pszString, ULONG* pcbString) {
        GetNonNullString(pszString, pcbString);
        if (*pcbString == 0) {
            throw META_E_CA_INVALID_BLOB;
        }
    }

    // Parses a string into a nice, null-terminated wstring.
    std::wstring GetWString() {
        LPCSTR pStr = NULL;
        ULONG cbVal = 0;
        DWORD ret = 0;

        GetString(&pStr, &cbVal);
        if (pStr == NULL) {
            return nullptr;
        }
        if (cbVal == 0) {
            return L"";
        }

        ret = MultiByteToWideChar(CP_UTF8, 0, pStr, cbVal, nullptr, 0);
        std::shared_ptr<wchar_t> heapBuf(new wchar_t[ret + 1]);
        ret = MultiByteToWideChar(CP_UTF8, 0, pStr, cbVal, heapBuf.get(), ret);
        if (ret == 0) {
            throw GetLastError();
        }
        heapBuf.get()[ret] = 0;
        return heapBuf.get();
    }

    // IMPORTANT: do not use with string fetching - use GetString instead.
    void GetData(BYTE const** ppbData, ULONG* pcbData) {
        ULONG len;
        HRESULT hr = CorSigUncompressData((PCCOR_SIGNATURE)m_pbCur, BytesLeft(), pcbData, &len);
        if (FAILED(hr)) {
            throw hr;
        }
        m_pbCur += len;
        *ppbData = m_pbCur;
        // Move past the data we just recovered
        m_pbCur = *ppbData + *pcbData;
    }

    // IMPORTANT: do not use with string fetching - use GetString instead.
    void GetPackedValue(ULONG* pcbData) {
        ULONG len;
        HRESULT hr = CorSigUncompressData((PCCOR_SIGNATURE)m_pbCur, BytesLeft(), pcbData, &len);
        if (FAILED(hr)) {
            throw hr;
        }
    }

    void GetData(ULONG len, BYTE const** ppbData) {
        if (BytesLeft() < (int)len) {
            throw META_E_CA_INVALID_BLOB;
        }
        *ppbData = m_pbCur;
        // Move past the data we just recovered
        m_pbCur = *ppbData + len;
    }

    int BytesLeft() {
        return (int)(m_cbBlob - (m_pbCur - m_pbBlob));
    }

private:
    const BYTE* m_pbCur;
    const BYTE* m_pbBlob;
    ULONG m_cbBlob;
};
