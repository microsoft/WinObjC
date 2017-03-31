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

#ifndef __XIBOBJECT_INT
#define __XIBOBJECT_INT

#include "XIBObject.h"

class XIBObjectInt : public XIBObject {
private:
    int _val;

public:
    XIBObjectInt(int val);
    int intValue();
    virtual bool NeedsSerialization();
    void WriteData(NIBWriter* writer);
};

class XIBObjectDataWriter : public XIBObject {
public:
    void* _binVal;
    int _binLen;

    XIBObjectDataWriter(const void* bin, int len);
    bool NeedsSerialization();
    void WriteData(NIBWriter* writer);
};

class XIBObjectNumber : public XIBObject {
    int _val;

public:
    XIBObjectNumber(int val);
    void EmitObject(NIBWriter* writer);
};

#endif