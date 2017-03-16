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

#include "_UILayoutGuide.h"
#include "NSLayoutConstraint.h"
#include <assert.h>

_UILayoutGuide::_UILayoutGuide()
{
    _translatesAutoresizeToConstraints = false;
    _identifier = NULL;
    _attribute = NSLayoutAttributeNotAnAttribute;
}

void _UILayoutGuide::InitFromXIB(XIBObject *obj)
{
    // Not sure this exists for XIB
    UIView::InitFromXIB(obj);

    obj->_outputClassName = "_UILayoutGuide";
}

void _UILayoutGuide::InitFromStory(XIBObject *obj)
{
    UIView::InitFromStory(obj);

    const char *identifierType = getAttrib("type");
    if (identifierType) {
        if (strcmp(identifierType, "top") == 0) {
            _identifier = new XIBObjectString("_UIViewControllerTop");
            _attribute = NSLayoutAttributeTop;
        } else if (strcmp(identifierType, "bottom") == 0) {
            _identifier = new XIBObjectString("_UIViewControllerBottom");
            _attribute = NSLayoutAttributeBottom;
        } else {
            assert(0);
        }
    }

    obj->_outputClassName = "_UILayoutGuide";
}

void _UILayoutGuide::Awaken()
{
    UIView::Awaken();

    UIView *controllerView = (UIView*)_parent->_parent->FindMemberClass("view");

    if (!controllerView) {
        assert(0);
    }

    XIBArray *subviews = (XIBArray *)controllerView->_subviews;
    XIBArray *constraints = (XIBArray *)controllerView->_constraints;

    if (!subviews || !constraints) {
        assert(0);
    }

    NSLayoutConstraint* supportConstraintHeight = new NSLayoutConstraint();
    NSLayoutConstraint* supportConstraintPos = new NSLayoutConstraint();

    // Height
    supportConstraintHeight->_firstItem = this;
    supportConstraintHeight->_firstAttribute = NSLayoutAttributeHeight;
    supportConstraintHeight->_outputClassName = "_UILayoutSupportConstraint";

    // Edges
    supportConstraintPos->_firstItem = this;
    supportConstraintPos->_firstAttribute = _attribute;
    supportConstraintPos->_secondItem = controllerView;
    supportConstraintPos->_secondAttribute = _attribute;
    supportConstraintPos->_outputClassName = "_UILayoutSupportConstraint";

    // I think how this is supposed to work is as the nav/tab/status bar heights change, we update the height
    // of the top and bottom constraints. This appears to be just to get around the views not being sibblings.
    subviews->AddMember(NULL, this);
    constraints->AddMember(NULL, supportConstraintHeight);
    constraints->AddMember(NULL, supportConstraintPos);
}

void _UILayoutGuide::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    UIView::ConvertStaticMappings(writer, obj);
    // TODO: _UILayoutGuideConstraintsToRemove?
    if (_identifier) obj->AddOutputMember(writer, "_UILayoutGuideIdentifier", _identifier);
}
