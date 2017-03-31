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

#include "UICustomResource.h"

void UICustomResource::InitFromXIB(XIBObject* obj) {
    ObjectConverter::InitFromXIB(obj);

    obj->_outputClassName = "UIImageNibPlaceholder";

    _imageName = obj->GetString("NSResourceName", "");
}

void UICustomResource::InitFromStory(XIBObject* obj) {
    ObjectConverter::InitFromStory(obj);

    obj->_outputClassName = "UIImageNibPlaceholder";
}

void UICustomResource::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    if (!_outputClassName)
        _outputClassName = "UIImageNibPlaceholder";

    ObjectConverter::ConvertStaticMappings(writer, obj);
    AddOutputMember(writer, "UIImageWidth", new XIBObjectFloat(1.0f));
    AddOutputMember(writer, "UIImageHeight", new XIBObjectFloat(1.0f));
    AddString(writer, "UIResourceName", _imageName);
}
