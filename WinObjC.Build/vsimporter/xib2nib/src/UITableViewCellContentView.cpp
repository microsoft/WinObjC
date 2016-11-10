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

#include "UITableViewCellContentView.h"

UITableViewCellContentView::UITableViewCellContentView()
{
}

void UITableViewCellContentView::InitFromXIB(XIBObject *obj)
{
    UIView::InitFromXIB(obj);

    obj->_outputClassName = "UITableViewCellContentView";
}

void UITableViewCellContentView::InitFromStory(XIBObject *obj)
{
    UIView::InitFromStory(obj);

    obj->_outputClassName = "UITableViewCellContentView";
}

void UITableViewCellContentView::Awaken()
{
    UIView::Awaken();
}

void UITableViewCellContentView::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    writer->_allUIObjects->AddMember(NULL, this);

    UIView::ConvertStaticMappings(writer, obj);
}

ObjectConverter *UITableViewCellContentView::Clone()
{
    return new UITableViewCellContentView();
}
