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

#include "ObjectConverter.h"
#include "UIView.h"
#include "UIViewController.h"
#include "UIProxyObject.h"
#include "UIColor.h"
#include "UIButton.h"
#include "UIFont.h"
#include "UIRuntimeEventConnection.h"
#include "UIRuntimeOutletConnection.h"
#include "UIRuntimeOutletCollectionConnection.h"
#include "UICustomResource.h"
#include "UIWindow.h"
#include "UIScrollView.h"
#include "UITableView.h"
#include "UINavigationBar.h"
#include "UINavigationItem.h"
#include "UIBarButtonItem.h"
#include "UIImageView.h"
#include "UILabel.h"
#include "UIRuntimeAccessibilityConfiguration.h"
#include "UITableViewCell.h"
#include "UITextField.h"
#include "UITextView.h"
#include "UITabBarController.h"
#include "UINavigationController.h"
#include "UITabBarItem.h"
#include "UITabBar.h"
#include "UIToolbar.h"
#include "UIStoryboardSegue.h"
#include "UITableViewController.h"
#include "UIWebView.h"
#include "UISearchBar.h"
#include "UISearchDisplayController.h"
#include "UIActivityIndicatorView.h"
#include "UIPickerView.h"
#include "UIPageControl.h"
#include "UISwitch.h"
#include "UISegmentedControl.h"
#include "UIDatePicker.h"
#include "MKMapView.h"
#include "UISlider.h"
#include "NSLayoutConstraint.h"
#include "_UILayoutGuide.h"
#include <assert.h>

#define IS_CONVERTER(newinst, classnamevar, name, type) \
    if ( strcmp(classnamevar, name) == 0 ) { \
        newinst = new type(); \
    }
XIBObject *ObjectConverter::ConverterForObject(const char *className, pugi::xml_node node)
{
    XIBObject *ret = NULL;

    IS_CONVERTER(ret, className, "IBCocoaTouchEventConnection", UIRuntimeEventConnection)
    IS_CONVERTER(ret, className, "IBCocoaTouchOutletConnection", UIRuntimeOutletConnection)
    IS_CONVERTER(ret, className, "IBCocoaTouchOutletCollectionConnection", UIRuntimeOutletCollectionConnection)
    IS_CONVERTER(ret, className, "IBUICustomObject", ObjectConverterSwapper)
    IS_CONVERTER(ret, className, "IBProxyObject", UIProxyObject)
    IS_CONVERTER(ret, className, "IBUIView", UIView)
    IS_CONVERTER(ret, className, "IBUIViewController", UIViewController)
    IS_CONVERTER(ret, className, "NSColor", UIColor)
    IS_CONVERTER(ret, className, "IBUIFontDescription", UIFont)
    IS_CONVERTER(ret, className, "NSFont", UIFont)
    IS_CONVERTER(ret, className, "IBUIButton", UIButton)
    IS_CONVERTER(ret, className, "NSCustomResource", UICustomResource)
    IS_CONVERTER(ret, className, "NSImage", UICustomResource)
    IS_CONVERTER(ret, className, "IBUIWindow", UIWindow)
    IS_CONVERTER(ret, className, "IBUIScrollView", UIScrollView)
    IS_CONVERTER(ret, className, "IBUITableView", UITableView)
    IS_CONVERTER(ret, className, "IBUINavigationBar", UINavigationBar)
    IS_CONVERTER(ret, className, "IBUINavigationItem", UINavigationItem)
    IS_CONVERTER(ret, className, "IBUIBarButtonItem", UIBarButtonItem)
    IS_CONVERTER(ret, className, "IBUIImageView", UIImageView)
    IS_CONVERTER(ret, className, "IBUILabel", UILabel)
    IS_CONVERTER(ret, className, "IBUIAccessibilityConfiguration", UIRuntimeAccessibilityConfiguration)
    IS_CONVERTER(ret, className, "IBUITableViewCell", UITableViewCell)
    IS_CONVERTER(ret, className, "IBUITextField", UITextField)
    IS_CONVERTER(ret, className, "IBUITextView", UITextView)
    IS_CONVERTER(ret, className, "IBUIPickerView", UIPickerView)
    IS_CONVERTER(ret, className, "IBUIPageControl", UIPageControl)
    IS_CONVERTER(ret, className, "IBUIActivityIndicatorView", UIActivityIndicatorView)
    IS_CONVERTER(ret, className, "IBUISwitch", UISwitch)
    IS_CONVERTER(ret, className, "IBUIWebView", UIWebView)
    IS_CONVERTER(ret, className, "IBUITabBarController", UITabBarController)
    IS_CONVERTER(ret, className, "IBUINavigationController", UINavigationController)
    IS_CONVERTER(ret, className, "IBUITableViewController", UITableViewController)
    IS_CONVERTER(ret, className, "IBUITabBar", UITabBar)
    IS_CONVERTER(ret, className, "IBUITabBarItem", UITabBarItem)
    IS_CONVERTER(ret, className, "IBUIToolbar", UIToolbar)
    IS_CONVERTER(ret, className, "IBUISegmentedControl", UISegmentedControl)
    IS_CONVERTER(ret, className, "IBUIDatePicker", UIDatePicker)
    IS_CONVERTER(ret, className, "IBUISearchBar", UISearchBar)
    IS_CONVERTER(ret, className, "IBMKMapView", MKMapView)
    IS_CONVERTER(ret, className, "IBUISearchDisplayController", UISearchDisplayController)
    IS_CONVERTER(ret, className, "IBUISlider", UISlider)
    IS_CONVERTER(ret, className, "IBNSLayoutConstraint", NSLayoutConstraint)

    if ( ret == NULL ) {
        ret = new XIBObject();
    }

    ret->ScanXIBNode(node);

    return ret;
}

XIBObject *ObjectConverter::ConverterForStoryObject(const char *className, pugi::xml_node node)
{
    XIBObject *ret = NULL;

    IS_CONVERTER(ret, className, "objects", XIBArray)
    IS_CONVERTER(ret, className, "subviews", XIBArray)
    IS_CONVERTER(ret, className, "constraints", XIBArray)
    IS_CONVERTER(ret, className, "variation", XIBVariation)
    IS_CONVERTER(ret, className, "items", XIBArray)
    IS_CONVERTER(ret, className, "connections", XIBArray)
    IS_CONVERTER(ret, className, "string", XIBObjectString)
    IS_CONVERTER(ret, className, "viewController", UIViewController)
    IS_CONVERTER(ret, className, "placeholder", UIProxyObject)
    IS_CONVERTER(ret, className, "tabBarController", UITabBarController)
    IS_CONVERTER(ret, className, "navigationItem", UINavigationItem)
    IS_CONVERTER(ret, className, "navigationBar", UINavigationBar)
    IS_CONVERTER(ret, className, "navigationController", UINavigationController)
    IS_CONVERTER(ret, className, "tabBarItem", UITabBarItem)
    IS_CONVERTER(ret, className, "tabBar", UITabBar)
    IS_CONVERTER(ret, className, "view", UIView)
    IS_CONVERTER(ret, className, "scrollView", UIScrollView)
    IS_CONVERTER(ret, className, "label", UILabel)
    IS_CONVERTER(ret, className, "toolbar", UIToolbar)
    IS_CONVERTER(ret, className, "color", UIColor)
    IS_CONVERTER(ret, className, "barButtonItem", UIBarButtonItem)
    IS_CONVERTER(ret, className, "outlet", UIRuntimeOutletConnection)
    IS_CONVERTER(ret, className, "segue", UIStoryboardSegue)
    IS_CONVERTER(ret, className, "fontDescription", UIFont)
    IS_CONVERTER(ret, className, "tableViewController", UITableViewController)
    IS_CONVERTER(ret, className, "tableView", UITableView)
    IS_CONVERTER(ret, className, "textField", UITextField)
    IS_CONVERTER(ret, className, "textView", UITextView)
    IS_CONVERTER(ret, className, "button", UIButton)
    IS_CONVERTER(ret, className, "webView", UIWebView)
    IS_CONVERTER(ret, className, "searchBar", UISearchBar)
    IS_CONVERTER(ret, className, "searchDisplayController", UISearchDisplayController)
    IS_CONVERTER(ret, className, "activityIndicatorView", UIActivityIndicatorView)
    IS_CONVERTER(ret, className, "imageView", UIImageView)
    IS_CONVERTER(ret, className, "action", UIRuntimeEventConnection)
    IS_CONVERTER(ret, className, "switch", UISwitch)
    IS_CONVERTER(ret, className, "constraint", NSLayoutConstraint)
    IS_CONVERTER(ret, className, "layoutGuides", XIBVariation)
    IS_CONVERTER(ret, className, "viewControllerLayoutGuide", _UILayoutGuide)
    IS_CONVERTER(ret, className, "datePicker", UIDatePicker)
    IS_CONVERTER(ret, className, "slider", UISlider)

    if ( ret == NULL ) {
#ifdef _DEBUG
        printf("Unrecognized tag <%s>\n", className);
#endif
        ret = new XIBObject();
    }

    ret->ScanStoryObjects(node);

    return ret;
}

void ConvertOffset(struct _PropertyMapper *prop, NIBWriter *writer, XIBObject *propObj, XIBObject *obj)
{
    struct 
    {
        float x, y;
    } UIOffset;

    char szName[255];

    sprintf(szName, "IBUI%sOffset", prop->nibName);
    const char *pStr = obj->FindMember(szName)->stringValue();

    UIOffset.x = 0;
    UIOffset.y = 0;

    sscanf(pStr, "{%f, %f}", &UIOffset.x, &UIOffset.y);

    char *dataOut = (char *) malloc(sizeof(UIOffset) + 1);
    dataOut[0] = 6;
    memcpy(&dataOut[1], &UIOffset, sizeof(UIOffset));
    sprintf(szName, "UI%sOffset", prop->nibName);
    obj->AddOutputMember(writer, strdup(szName), new XIBObjectDataWriter(dataOut, sizeof(UIOffset) + 1));
}

void ObjectConverter::InitFromXIB(XIBObject *obj)
{
    _connections = NULL;
    _connectedObjects = NULL;
}
void ObjectConverter::InitFromStory(XIBObject *obj)
{
    _connections = (XIBArray *) FindMemberClass("connections");
}
void ObjectConverter::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
}
ObjectConverter *ObjectConverter::Clone()
{
    return this;
}

void ObjectConverter::Map(NIBWriter *writer, XIBObject *obj, PropertyMapper *properties, int numProperties)
{
    for ( size_t i = 0; i < obj->_members.size(); i ++ ) {
        XIBMember *cur = obj->_members[i];

        for ( int j = 0; j < numProperties; j ++ ) {
            if ( cur->_name && strcmp(cur->_name, properties[j].xibName) == 0 ) {
                if ( properties[j].ConvertProperty == NULL ) {
                    obj->AddOutputMember(writer, properties[j].nibName, cur->_obj);
                } else {
                    properties[j].ConvertProperty(&properties[j], writer, cur->_obj, obj);
                }
            }
        }
    }

}

void ObjectConverterSwapper::InitFromXIB(XIBObject *obj)
{
    _outputClassName = "UICustomObject";
    ObjectConverter::InitFromXIB(obj);
}

void ObjectConverterSwapper::InitFromStory(XIBObject *obj)
{
    _outputClassName = "UICustomObject";
    ObjectConverter::InitFromStory(obj);

    if ( getAttrib("customClass") ) {
        _swappedClassName = getAttrib("customClass");
    }
}

void ObjectConverterSwapper::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    if ( !_ignoreUIObject ) writer->_allUIObjects->AddMember(NULL, this);
    ObjectConverter::ConvertStaticMappings(writer, obj);

    if ( obj->_swappedClassName ) {
        obj->AddOutputMember(writer, "UIOriginalClassName", new XIBObjectString(obj->_outputClassName));
        obj->AddOutputMember(writer, "UIClassName", new XIBObjectString(obj->_swappedClassName));
        obj->_outputClassName = "UIClassSwapper";
    }

    //  Add outlets
    if ( _connectedObjects ) {
        for ( int i = 0; i < _connectedObjects->count(); i ++ ) {
            XIBObject *curObj = (UIRuntimeOutletConnection *) _connectedObjects->objectAtIndex(i);
            if ( strcmp(curObj->_outputClassName, "UIRuntimeOutletConnection") == 0 ) {
                UIRuntimeOutletConnection *cur = (UIRuntimeOutletConnection *) curObj;

                UIRuntimeOutletConnection *newOutlet = new UIRuntimeOutletConnection();
                newOutlet->_label = cur->_label;
                newOutlet->_source = cur->_source;
                newOutlet->_destination = cur->_destination;
                writer->_connections->AddMember(NULL, newOutlet);
                writer->AddOutputObject(newOutlet);
            } else if ( strcmp(curObj->_outputClassName, "UIRuntimeEventConnection") == 0 ) {
                UIRuntimeEventConnection *cur = (UIRuntimeEventConnection *) curObj;

                UIRuntimeEventConnection *newOutlet = new UIRuntimeEventConnection();
                newOutlet->_label = cur->_label;
                newOutlet->_source = cur->_source;
                newOutlet->_destination = cur->_destination;
                newOutlet->_eventMask = cur->_eventMask;
                writer->_connections->AddMember(NULL, newOutlet);
                writer->AddOutputObject(newOutlet);
            } else {
                assert(0);
            }
        }
    }
}
