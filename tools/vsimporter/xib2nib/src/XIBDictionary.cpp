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

#include "XIBObjectTypes.h"

XIBDictionary::XIBDictionary(pugi::xml_node node) {
    ScanXIBNode(node);
}

XIBDictionary::XIBDictionary() {
    AddMember("EncodedWithXMLCoder", new XIBObjectBool(true));
}

void XIBDictionary::InitFromXIB(XIBObject* obj) {
    _keys = obj->FindMember("dict.sortedKeys");
    _values = obj->FindMember("dict.values");
}

XIBObject* XIBDictionary::ObjectForKey(char* keyName) {
    if (_keys) {
        size_t curIdx = 0;

        for (curIdx = 0; curIdx < _keys->_members.size(); curIdx++) {
            XIBMember* curKeyObj = _keys->_members[curIdx];
            if (curKeyObj->_obj->EqualToString(keyName)) {
                return _values->_members[curIdx]->_obj;
            }
        }
    } else {
        size_t curIdx = 0;

        for (curIdx = 0; curIdx < _members.size(); curIdx++) {
            XIBMember* curKeyObj = _members[curIdx];
            if (strcmp(curKeyObj->_name, keyName) == 0) {
                return curKeyObj->_obj;
            }
        }
    }

    return NULL;
}

void XIBDictionary::EmitObject(NIBWriter* writer) {
    if (!_className)
        _className = "NSDictionary";
    this->_outputClassName = _className;

    for (memberList::iterator cur = _members.begin(); cur != _members.end(); cur++) {
        XIBMember* pMember = (*cur);

        if (pMember->_name == NULL) {
            AddOutputMember(writer, "UINibEncoderEmptyKey", pMember->_obj);
        } else if (strcmp(pMember->_name, "EncodedWithXMLCoder") == 0) {
            AddOutputMember(writer, "NSInlinedValue", pMember->_obj);
        } else {
            AddOutputMember(writer, pMember->_name, pMember->_obj);
        }
    }
}

void XIBDictionary::AddObjectForKey(XIBObject* key, XIBObject* value) {
    AddMember(NULL, key);
    AddMember(NULL, value);
}
