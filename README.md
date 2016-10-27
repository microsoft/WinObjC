###Download the latest pre-built Windows Bridge for iOS SDK [here](https://aka.ms/winobjc_latest).

**Note on installing the bridge:** We use [Git LFS](https://git-lfs.github.com) to handle the large binaries included in the bridge. This does not affect using the [prebuilt releases found on our releases page](https://github.com/Microsoft/WinObjC/releases). If you build the bridge from source, please see the instructions found on our [Building From Source](https://github.com/Microsoft/WinObjC/wiki/Building-From-Source) wiki page.

**Do not use the Download ZIP option via the "Clone or download" button above.** You will not be able to build the bridge using the resulting .zip file. See ["I'm getting errors after downloading the bridge through the "Download ZIP" button on Github. What should I do?"](https://github.com/Microsoft/WinObjC/wiki/FAQ#im-getting-errors-after-downloading-the-bridge-through-the-download-zip-button-on-github-what-should-i-do) for more information.

# Welcome to the Windows Bridge for iOS project preview
The Windows Bridge for iOS (also referred to as WinObjC) is a Microsoft open-source project that provides an Objective-C development environment for Visual Studio and support for iOS APIs. The bridge allows you to create Universal Windows Platform (UWP) apps that will run on many Windows devices using iOS APIs and Objective-C code alongside Windows 10 features like Cortana and Live Tiles.


## Where to get the bridge
Download the latest pre-built Windows Bridge for iOS SDK [here](https://aka.ms/winobjc_latest).


## Resources
The following sections will help you get started. For more information, check out:

1. [Wiki](https://github.com/Microsoft/WinObjC/wiki), for documentation and tutorials
2. [Development Roadmap](https://github.com/Microsoft/WinObjC/wiki/Roadmap), detailing our highest priorities
3. [App Analysis Tool](https://developer.microsoft.com/en-us/windows/bridges/ios/app-analyzer-tool), to evaluate the compatibility of your app with the bridge
4. [Website on Windows Dev Center](https://dev.windows.com/bridges/ios), for evaluation virtual machines
5. [Quick Start Challenge](https://github.com/Microsoft/WinObjC/wiki/Quick-Start-Tutorial), for a quick hands-on introduction to the bridge
6. [The iOS Bridge Samples Repo](https://github.com/Microsoft/WinObjC-Samples), for project samples apps and code using the bridge

## Getting started with the bridge
To get started using the bridge to bring your iOS app to Windows, you'll need:
- Windows 10, build 10586 or higher. (Validate your version number [here](http://windows.microsoft.com/en-US/windows/which-operating-system)).
- Visual Studio 2015 with Windows developer tools. Visual Studio 2015 Community is available for free [here](https://dev.windows.com/downloads). Select (at least) the following components during installation:

    1. Programming Languages -> Visual C++
    2. Universal Windows App Development Tools (all)

- (Optional) Windows 10 1511 Standalone SDK (Updated on November 30th, 2015) from [here](https://dev.windows.com/en-US/downloads/windows-10-sdk).  Note: this step is new and is not required if you already installed Visual Studio 2015 Update 3.

The best way to get started with the bridge is to run one of the samples. We recommend starting with the **WOCCatalog** sample app, which demonstrates an assortment of iOS and XAML UI controls. It's also suggested to use the [App Analysis Tool](https://developer.microsoft.com/en-us/windows/bridges/ios/app-analyzer-tool) to evaluate your app compatibility with the bridge.  

**NOTE:** The following instructions are for getting started using the ***pre-built SDK*** rather than building the SDK from source. If you're building the SDK from the source code, follow the instructions on the [wiki](https://github.com/Microsoft/WinObjC/wiki/Building-From-Source) instead. 

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

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/). For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.


## Privacy
See [Microsoft's privacy statement](https://www.microsoft.com/en-us/privacystatement/default.aspx) for more information.


## What's still under development?
As this project is still under active development, there are many features that are not yet complete. You can check out [our roadmap in the wiki](https://github.com/Microsoft/WinObjC/wiki/Roadmap) for more information.


## Questions
If you have any questions, we're listening and will do our best to help. There are lots of ways you can get in touch or find out more:

1. [File an issue](https://github.com/Microsoft/WinObjC/issues/new) to let us know about bugs and missing or incomplete features and APIs you need.
2. Follow [@WindowsDev on Twitter](https://twitter.com/windowsdev) and interact with our team using the [#WinObjC hashtag](https://twitter.com/hashtag/WinObjC).
3. Go to http://stackoverflow.com/ and tag your questions with **WinObjC**.
4. You can also find answers to lots of common questions at our [wiki](https://github.com/Microsoft/WinObjC/wiki)
