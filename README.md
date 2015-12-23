**ANNOUNCEMENT:** With this week's release of the Windows Bridge for iOS, we're deprecating support for Windows 8.1 and Windows Phone 8.0/8.1 in the interest of shifting our attention to Windows 10 and the future.

# Welcome to the Windows Bridge for iOS project preview
The Windows Bridge for iOS (also referred to as WinObjC) is a Microsoft open-source project that provides an Objective-C development environment for Visual Studio and support for iOS APIs. The bridge allows you to create Universal Windows Apps (UWAs) that will run on any Windows 10 device using iOS APIs and Objective-C code.

The following sections will help you get started. For more information, check out:

1. [Our wiki](https://github.com/Microsoft/WinObjC/wiki)
2. [Our website on Windows Dev Center](https://dev.windows.com/bridges/ios)

If you'd like to support the project, please consider [submitting your app](https://dev.windows.com/en-us/bridges/ios/app-submission) to help us test our app analysis tool. You can read more about the effort and what we're working on [here](https://blogs.windows.com/buildingapps/2015/11/18/windows-bridge-for-ios-where-we-are-and-where-we-are-headed/).


## Where to get the bridge
Download the latest pre-built Windows Bridge for iOS SDK [here](https://github.com/Microsoft/WinObjC/releases/download/0.1.0.151222/winobjc.zip).


## Getting started with the bridge
To use the bridge, there are a few requirements. You need:
- Windows 10
- Visual Studio 2015 with Windows developer tools. Visual Studio 2015 Community is available for free [here](https://dev.windows.com/downloads). Select (at least) the following components during installation:

    1. Programming Languages -> Visual C++
    2. Universal Windows App Development Tools (all)

- Install  Windows 10 1511  standalone SDK (Updated on November 30th, 2015) from here (https://dev.windows.com/en-US/downloads/windows-10-sdk).  Note: this step is new and is not required if you already installed visual studio 2015 update 1.

The best way to get started with the bridge is to run one of the samples. We recommend starting with the **WOCCatalog** sample app, which demonstrates an assortment of iOS and XAML UI controls.

**NOTE:** The following instructions are for getting started using the ***pre-built SDK*** rather than building the SDK from source. If you're building the SDK from the source code, follow the instructions on the [wiki](https://github.com/Microsoft/WinObjC/wiki) instead. 

To run the sample:

1. Extract the SDK zip file to a local directory
2. Navigate to *winobjc/samples/WOCCatalog* in the extracted directory
3. Double-click on *WOCCatalog-WinStore10.sln* to open in VS2015
4. In VS2015 right-click on the WOCCatalog (Universal Windows) project
5. Select **Set as StartUp project**
6. Use **Ctrl-F5** to build and run the app

For guidance on importing your own Xcode project and other tips, see the [wiki](https://github.com/Microsoft/WinObjC/wiki)


## Contributions
See our [contribution guidance in the wiki](https://github.com/Microsoft/WinObjC/wiki/How-to-Contribute) for details on how to contribute to the project.


## What's still under development?
As this project is still under active development, there are many features that are not yet complete. You can check out [our roadmap in the wiki](https://github.com/Microsoft/WinObjC/wiki/Roadmap) for more information.


## Questions
If you have any questions, we're listening and will do our best to help. There are lots of ways you can get in touch or find out more:

1. [File an issue](https://github.com/Microsoft/WinObjC/issues/new) to let us know about bugs and missing or incomplete features and APIs you need.
2. Follow [@WindowsDev on Twitter](https://twitter.com/windowsdev) and interact with our team using the [#WinObjC hashtag](https://twitter.com/hashtag/WinObjC).
3. Go to http://stackoverflow.com/ and tag your questions with **WinObjC**.
4. You can also find answers to lots of common questions at our [wiki](https://github.com/Microsoft/WinObjC/wiki)
