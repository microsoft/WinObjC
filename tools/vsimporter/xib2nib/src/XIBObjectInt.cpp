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

#include "XIBObjectInt.h"

XIBObjectInt::XIBObjectInt(int val) {
    _val = val;
}

int XIBObjectInt::intValue() {
    return _val;
}

bool XIBObjectInt::NeedsSerialization() {
    return false;
}

void XIBObjectInt::WriteData(NIBWriter* writer) {
    unsigned int fullVal = (unsigned int)_val;

    if (fullVal <= 0xFF) {
        writer->WriteByte(NIBOBJ_INT8);
        writer->WriteBytes(&fullVal, 1);
    } else if (fullVal <= 0xFFFF) {
        writer->WriteByte(NIBOBJ_INT16);
        writer->WriteBytes(&fullVal, 2);
    } else {
        writer->WriteByte(NIBOBJ_INT32);
        writer->WriteBytes(&fullVal, 4);
    }
}

XIBObjectNumber::XIBObjectNumber(int num) {
    _val = num;
    _className = "NSNumber";
}

void XIBObjectNumber::EmitObject(NIBWriter* writer) {
    _outputClassName = "NSNumber";

    AddOutputMember(writer, "NS.intval", new XIBObjectInt(_val));
}
