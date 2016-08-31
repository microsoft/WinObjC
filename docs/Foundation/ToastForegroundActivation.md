
#Windows Bridge for iOS

##[Toast Foreground Activation]

###DEV DESIGN specification


##Owner
**Dev** AJ Ballway; alballw

##Overview
This document covers details on how Toast Notification Actions will be integrated with apps built mainly in iOS code which also want to leverage Windows Toast Notifications

###Feature Summary
Toast Foreground activation can contain parameters for the app to handle.

###Document Terms
**Term**    Definition
**Toast Action** A user interaction with a Toast Nofication, usually clicking on one or submitting input through one

###Requirements
When a Toast Action is received, the app should be activated in the foreground with any input given.

###Technology/Architecture Decisions
We will create new OnApplicationLaunchOptions as well as new delegate methods for Toast Actions.  These will need to be publicly documented for developer use.

##Design

###Architecture Overview

We will need to convert C++/CX Windows::Foundation::ValueSet^ and Platform::String^ to Objective C classes NSDictionary\* and NSString\* respectively by passing them as Iinspectable\* and HSTRING through C functions between the two languages.

###Language Decisions
We will use Objective-C projection as well as C++/CX wrappers as appropriate for functionality with WinObjC

##Detailed Design

The diagram below illustrates the code flow for activating an app via Toast Actions.


![Diagram of Activation path](./media/Toast_Foreground_Activation.png)



Adding Toast Action activation does not require any changes to the current flow of activation beyond splitting the path and rejoining after converting to Objective C projections, so the only changes will be additions of internal methods and enums to correctly call delegate methods, public constants and new delegate methods so developers will be able to respond to Toast Action activation, and refactoring of the current activation path to handle Toast Action activation objects ToastNotificationActivatedEventArgs.

This will add:
* UIApplication.mm:
    * UIApplicationLaunchOptionsToastActionKey
    * _sendToastActionReceivedEvent
* UIApplicationMain.mm:
    * UIApplicationMainHandleToastActionEvent
* UIApplicationDelegate.h:
    * application:didReceiveToastAction:
* StarboardXaml.h:
    * ActivationTypeToastActionToastAction

And these will need to be publicly documented for developers to use these features:
+ UIApplication.mm
    * UIApplicationLaunchOptionsToastActionKey
+ UIApplicationDelegate.h
    * application:didReceiveToastAction:



##Interfaces and Interactions

###Public APIs Added
UIApplicationDelegate.h:
*   application:didReceiveToastAction:


##Functional and Unit Testing

###Test Approach

We are using the functional test framework to test Toast Action foreground activation.  We can create a test app shell which activates with given arguments, which we can use to test that all delegate methods are called and with the correct data.
We will also be adding a test app to verify that the entire activation path is working properly.
