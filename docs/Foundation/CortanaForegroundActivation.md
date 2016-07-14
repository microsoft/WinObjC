#Windows Bridge for iOS

##[Cortana Foreground Activation]

###DEV DESIGN specification


##Owner
**Dev** AJ Ballway; alballw

##Overview
This document covers details on how Cortana will be integrated with apps built mainly in iOS code which also want to leverage Windows specific features to launch apps from Cortana.

###Feature Summary
Cortana is capable of activating an app in the foreground or interacting with it in the background.  Foreground activation can contain parameters for the app to handle, and be done by both Voice Command and Protocol.

###Document Terms
**Term**    Definition
**UWP** Universal Windows Platform
**VCD** Voice Command Definition - file used to define commands for Cortana integration
**Voice Command**   Activation of the app by giving some command to Cortana.  It can be written, it does not need to be an oral command.
**Protocol**    Activation of the app by clicking on a card while using Cortana.

###Requirements
When a command is given or a card is clicked, the app should be activated in the foreground with the parameters given to Cortana.

###Technology/Architecture Decisions
We will create new OnApplicationLaunchOptions as well as new delegate methods for Cortana.  These will need to be publicly documented for developer use.

##Design

###Architecture Overview

We will need to convert C++/CX Windows::Media::SpeechRecognition::SpeechRecognitionResult^ and Windows::Foundation::Uri^ to Objective C Projections WMSSpeechRecognitionResult\* and WFUri\* respectively by passing them as Iinspectable\* through C functions between the two languages.  Because Platform::String^ is not an IInspectable\*, we will need a branching path to handle the conversion from Platform::String^ as an HSTRING to NSString\* before joining the two  paths in _ApplicationMainStart.

###Language Decisions
We will use Objective-C projection as well as C++/CX wrappers as appropriate for functionality with WinObjC

##Detailed Design

The diagram below illustrates the code flow for activating an app via Cortana.


![Diagram of Activation path](./media/Cortana_Foreground_Activation.png)



Adding Cortana activation does not require any changes to the current flow of activation beyond splitting the path and rejoining after converting to Objective C projections, so the only changes will be additions of internal methods and enums to correctly call delegate methods, public constants and new delegate methods so developers will be able to respond to Cortana activation, and refactoring of the current activation path to handle Cortana activation objects VoiceCommandActivatedEventArgs and ProtocolActivatedEventArgs.

This will add:
* UIApplication.mm:
    * UIApplicationLaunchOptionsVoiceCommandKey
    * UIApplicationLaunchOptionsProtocolKey
    * _sendVoiceCommandReceivedEvent
    * _sendProtocolReceivedEvent
* UIApplicationMain.mm:
    * UIApplicationMainHandleVoiceCommandEvent
    * UIApplicationMainHandleProtocolEvent
* UIApplicationDelegate.h:
    * application:didReceiveVoiceCommand:
    * application:didReceiveProtocol:
* StarboardXaml.h:
    * ActivationTypeVoiceCommand
    * ActivationTypeProtocol

And these will need to be publicly documented for developers to use these features:
+ UIApplication.mm
    * UIApplicationLaunchOptionsVoiceCommandKey
    * UIApplicationLaunchOptionsProtocolKey
+ UIApplicationDelegate.h
    * didReceiveVoiceCommand:
    * didReceiveProtocol:



##Interfaces and Interactions

###Public APIs Added
UIApplicationDelegate.h:
*   application:didReceiveVoiceCommand:
*   application:didReceiveProtocol:


##Functional and Unit Testing

###Test Approach

We are using the functional test framework to test Cortana foreground activation.  We can create a test app shell which activates with given arguments, which we can use to test that all delegate methods are called and with the correct data.
