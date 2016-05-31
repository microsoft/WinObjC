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

#include "UICollectionViewController.h"


UICollectionViewController::UICollectionViewController()
{
    _collectionView = NULL;

    // Default values as specified in Apple docs
    _clearSelectionOnViewWillAppear = true;
    _installStandardGestureForInteractiveMovement = true;

    // Difficult to determine the default value but from the documentation this seems like the right choice
    _useLayoutToLayoutNavigationTransitions = false;
}

void UICollectionViewController::InitFromXIB(XIBObject *obj)
{
    UIViewController::InitFromXIB(obj);

    // NOTE: Not implementing this portion - difficult to ascertain the pre-XCode5 XIB format.
    // The current mitigation is developers can upgrade their legacy XIB to storyboard format within XCode.

    _outputClassName = "UICollectionViewController";
}

void UICollectionViewController::InitFromStory(XIBObject *obj)
{
    UIViewController::InitFromStory(obj);

    _collectionView = (UICollectionView*)FindMemberAndHandle("view");

    const char* clearSelectionOnViewWillAppearAttribute = getAttrAndHandle("clearSelectionOnViewWillAppear");
    if (clearSelectionOnViewWillAppearAttribute && strcmp(clearSelectionOnViewWillAppearAttribute, "NO") == 0) {
        _clearSelectionOnViewWillAppear = false;
    }

    const char* installStandardGestureForInteractiveMovementAttribute = getAttrAndHandle("installStandardGestureForInteractiveMovement");
    if (installStandardGestureForInteractiveMovementAttribute && strcmp(installStandardGestureForInteractiveMovementAttribute, "NO") == 0) {
        _installStandardGestureForInteractiveMovement = false;
    }

    const char* useLayoutToLayoutNavigationTransitionsAttribute = getAttrAndHandle("useLayoutToLayoutNavigationTransitions");
    if (useLayoutToLayoutNavigationTransitionsAttribute && strcmp(useLayoutToLayoutNavigationTransitionsAttribute, "YES") == 0) {
        _useLayoutToLayoutNavigationTransitions = true;
    }

    _outputClassName = "UICollectionViewController";
}

void UICollectionViewController::Awaken()
{
    UIViewController::Awaken();
}

void UICollectionViewController::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    UIViewController::ConvertStaticMappings(writer, obj);

    AddOutputMember(writer, "UICollectionView", _collectionView);

    // NOTE: There is difficulty confirming these keys are correct - NIB files generated were not conclusive in confirming these 
    // keys under the unarchiver
    if (!_clearSelectionOnViewWillAppear) {
        AddBool(writer, "UIClearSelectionOnViewWillAppear", _clearSelectionOnViewWillAppear);
    }

    if (!_installStandardGestureForInteractiveMovement) {
        AddBool(writer, "UIInstallStandardGestureForInteractiveMovement", _installStandardGestureForInteractiveMovement);
    }

    if (_useLayoutToLayoutNavigationTransitions) {
        AddBool(writer, "UIUseLayoutToLayoutNavigationTransitions", _useLayoutToLayoutNavigationTransitions);
    }
}