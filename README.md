# Welcome to the Windows Bridge for iOS project preview

## What is WinObjC?
Windows Bridge for iOS (also referred to as **WinObjC**) is a Microsoft open source project that provides an Objective-C development environment for Visual Studio on Windows. In addition, WinObjC provides support for iOS API compatibility.

The following sections will help you get started, and you can view our [wiki](https://github.com/Microsoft/WinObjC/wiki) for more detailed information.

## Where to get it

Download the latest pre-built Windows Bridge for iOS SDK [here](https://github.com/Microsoft/WinObjC/releases/download/0.1.0.151112/winobjc.zip).

## Getting started with WinObjC
To use WinObjC, there are a few requirements. You need:
- Windows 10
- Visual Studio 2015 with Windows developer tools. Visual Studio 2015 Community is available for free [here](https://dev.windows.com/downloads). Select (at least) the following components during installation:

    1. Programming Languages -> Visual C++
    2. Universal Windows App Development Tools (all)
    3. Windows 8.1 and Windows Phone 8.0/8.1 Tools (all)

The best way to get started with WinObjC is to run one of the samples. We recommend starting with the **WOCCatalog** sample app, which demonstrates an assortment of iOS and XAML UI controls.

**NOTE:** The following instructions are for getting started using the ***pre-built SDK*** rather than building the sdk from source. If you're building the SDK from the source code, follow the instructions on the [wiki](https://github.com/Microsoft/WinObjC/wiki) instead. 

To run the sample:

1. Extract the SDK zip file to a local directory

2. Navigate to *winobjc/samples/WOCCatalog* in the extracted directory

3. Double-click on *WOCCatalog-WinStore10.sln* to open in VS2015

4. In VS2015 right-click on the WOCCatalog (Universal Windows) project

5. Select **Set as StartUp project**

6. Use **Ctrl-F5** to build and run the app


For guidance about importing your own Xcode project and other Windows Bridge for iOS SDK details, see the [wiki](https://github.com/Microsoft/WinObjC/wiki)

## Contributions

See our [contribution guidance](Contributing.md) for details on how to contribute to the WinObjC project.

## What's still under development?
As this project is still under active development, there are many features that are not yet complete:

1. x86 only today; ARM support coming soon
2. Compiler optimizations will not work and will likely crash clang, debug builds only for now
3. Autolayout
4. Storyboard support
5. MapKit
6. AssetsLibrary
7. AddressBook
8. Ads
9. Objective-C annotations
10. Media Capture and Playback

## Problems?
If you have any questions, we're listening and will do our best to help. Just go to http://stackoverflow.com/ and tag your questions with **WinObjC**. You can also get more information at our [wiki](https://github.com/Microsoft/WinObjC/wiki)
