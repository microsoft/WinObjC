//
// MainViewController.xaml.cpp
// Implementation of the MainViewController class.
//

#include "pch.h"
#include "MainViewController.xaml.h"
#include <windows.foundation.collections.h>
#include <string>

using namespace IslandwoodAutoGenNamespace;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

extern "C" void UIViewControllerFirePageEvent(void *pageController, const char *selector);

namespace IslandwoodAutoGenNamespace {
    ActionsList::ActionsList()
    {
        _defaultAction = ref new Action();
    }

    Windows::Foundation::Collections::IIterator<Action ^> ^ActionsList::First(void)
    {
        if (_builtActions == nullptr) {
            auto tmp = ref new Platform::Collections::VectorView<Action ^>(1, _defaultAction);
            return tmp->First();
        }
        return _builtActions->First();
    }

    unsigned int ActionsList::Size::get(void)
    {
        if (_builtActions == nullptr) {
            return 1;
        }

        return _builtActions->Size;
    }
    Action ^ActionsList::GetAt(unsigned int idx)
    {
        if (_builtActions == nullptr) {
            return _defaultAction;
        }
        return _builtActions->GetAt(idx);
    }
    bool ActionsList::IndexOf(Action ^Action, unsigned int *idx)
    {
        if (_builtActions == nullptr) {
            *idx = 0;
            if (Action == _defaultAction) {
                return true;
            }
            else {
                return false;
            }
        }
        return _builtActions->IndexOf(Action, idx);
    }
    unsigned int ActionsList::GetMany(unsigned int count, Platform::WriteOnlyArray<Action ^, 1> ^items)
    {
        if (_builtActions == nullptr) {
            auto tmp = ref new Platform::Collections::VectorView<Action ^>(1, _defaultAction);
            return tmp->GetMany(count, items);
        }
        return _builtActions->GetMany(count, items);
    }
    Windows::Foundation::Collections::IVectorView<Action ^> ^ActionsList::GetView(void)
    {
        if (_builtActions == nullptr) {
            auto tmp = ref new Platform::Collections::Vector<Action ^>(1, _defaultAction);
            return tmp->GetView();
        }
        return _builtActions->GetView();
    }
    void ActionsList::SetAt(unsigned int idx, Action ^item)
    {
        if (_builtActions == nullptr) {
            return;
        }
        _builtActions->SetAt(idx, item);
    }
    void ActionsList::InsertAt(unsigned int idx, Action ^item)
    {
        if (_builtActions == nullptr) {
            return;
        }
        _builtActions->InsertAt(idx, item);
    }
    void ActionsList::RemoveAt(unsigned int idx)
    {
        if (_builtActions == nullptr) {
            return;
        }
        _builtActions->RemoveAt(idx);
    }
    void ActionsList::Append(Action ^item)
    {
        if (_builtActions == nullptr) {
            return;
        }
        _builtActions->Append(item);
    }
    void ActionsList::RemoveAtEnd(void)
    {
        if (_builtActions == nullptr) {
            return;
        }
        _builtActions->RemoveAtEnd();
    }
    void ActionsList::Clear(void)
    {
        if (_builtActions == nullptr) {
            return;
        }
        _builtActions->Clear();
    }
    void ActionsList::ReplaceAll(const Platform::Array<Action ^, 1> ^ items)
    {
        if (_builtActions == nullptr) {
            return;
        }
        _builtActions->ReplaceAll(items);
    }

    static bool strPrefix(std::wstring& str, std::wstring& prefix) {
        if (str.size() < prefix.size()) return false;

        return std::equal(prefix.begin(), prefix.end(), str.begin());
    }

    /// <summary>
    /// Load the XAML page
    /// </summary>
    MainViewController::MainViewController() {
        //  Provide a default set of Actions in case any events fire during InitializeComponent()
        //  i.e. Slider.ValueChanged
        AllActions = ref new ActionsList();
        Actions = AllActions;

        InitializeComponent();

        //  Now that our ppage is loaded, we can iterate through all of the page resources 
        //  and construct the Actions list that can be dynamically bound and used to 
        //  fire events on our owning view controller
        AllActions->_builtActions = ref new Platform::Collections::Vector<Action ^>();
        for (auto curResource : this->Resources) {
            std::wstring curKey(static_cast<Platform::String ^>(curResource->Key)->Data());
            std::wstring curVal(static_cast<Platform::String ^>(curResource->Value)->Data());

            if (strPrefix(curKey, std::wstring(L"Action_")) ) {
                size_t idx = std::stoi(curKey.substr(7));
                while( idx >= Actions->Size ) {
                    Action ^newAction = ref new Action();

                    newAction->_parent = this;
                    Actions->Append(newAction);
                }

                Actions->GetAt(idx)->_selector = std::string(curVal.begin(), curVal.end());
            }
        }
    }

    void Action::FireEvent(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
    {
        //  If we have no parent or selector, we're an instance of the "no-op" Action,
        //  which is the default Action returned from an ActionsCollection.  
        if (_parent == nullptr || _selector.size() == 0) {
            return;
        }

        //  Pass our parent and selector off to ObjC-land, which will perform a lookup
        //  for our associated UIViewController and send the event
        UIViewControllerFirePageEvent((void *) _parent, _selector.data());
        return;
    }
}
