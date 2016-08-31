//
// MainViewController.xaml.h
// Declaration of the MainViewController class.
//

#pragma once

#include "MainViewController.g.h"

namespace IslandwoodAutoGenNamespace {
    ref class MainViewController;

    public ref class Action sealed {
    internal:
        std::string _selector;
        MainViewController ^_parent;

    public:
        void FireEvent(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    };

    //  We need to provide a custom IVector implementation, because events can be fired before 
    //  we get a chance to iterate through the page resources and build the Action list.
    //
    //  In the case that an event fires before the list has been built, we will always return
    //  the "_defaultAction" member to the caller, which will typically perform a no-op
    ref class ActionsList : Windows::Foundation::Collections::IVector<Action^>
    {
    internal:
        Platform::Collections::Vector<Action ^> ^_builtActions;
        Action ^_defaultAction;
        ActionsList();

    public:

        virtual Windows::Foundation::Collections::IIterator<Action ^> ^First(void);
        property unsigned int Size {
            virtual unsigned int get(void);
        }
        virtual Action ^GetAt(unsigned int);
        virtual bool IndexOf(Action ^, unsigned int *idx);
        virtual unsigned int GetMany(unsigned int count, Platform::WriteOnlyArray<Action ^, 1> ^items);
        virtual Windows::Foundation::Collections::IVectorView<Action ^> ^GetView(void);
        virtual void SetAt(unsigned int, Action ^);
        virtual void InsertAt(unsigned int, Action ^);
        virtual void RemoveAt(unsigned int);
        virtual void Append(Action ^);
        virtual void RemoveAtEnd(void);
        virtual void Clear(void);
        virtual void ReplaceAll(const Platform::Array<Action ^, 1> ^ items);
    };

    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public
    ref class MainViewController sealed {
    private:
        ActionsList ^AllActions;

    public:
        //  This is the bindable collection that can be referenced from XAML and used to fire events
        //  i.e. x:Bind Actions[0].FireEvent
        property Windows::Foundation::Collections::IVector<Action^> ^Actions;
        MainViewController();
    };
}
