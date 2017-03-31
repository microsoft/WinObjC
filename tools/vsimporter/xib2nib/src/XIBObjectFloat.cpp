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

#include "XIBObjectFloat.h"

XIBObjectFloat::XIBObjectFloat(pugi::xml_node node) {
    _val = strtod(node.child_value(), NULL);
    _node = node;
}

XIBObjectFloat::XIBObjectFloat(float val) {
    _val = val;
}

float XIBObjectFloat::floatValue() {
    return _val;
}

bool XIBObjectFloat::NeedsSerialization() {
    return false;
}

void XIBObjectFloat::WriteData(NIBWriter* writer) {
    writer->WriteByte(NIBOBJ_FLOAT);
    writer->WriteBytes(&_val, 4);
}
