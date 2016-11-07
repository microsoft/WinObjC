# Welcome to the Windows Bridge for iOS Project
The Windows Bridge for iOS (also referred to as WinObjC) is a Microsoft open-source project that provides an Objective-C development environment for Visual Studio and support for iOS APIs. The bridge allows you to create Universal Windows Platform (UWP) apps that will run on many Windows devices by re-using your Objective-C code and iOS APIs alongside Windows 10 features like Cortana and Live Tiles.

## Download and Installation
To use the bridge, you'll need:
- The latest pre-built Windows Bridge for iOS SDK, that you can download [here](https://aka.ms/winobjc_latest) (click on the **winobjc.zip** file under *Downloads* to start the download and extract it to the local directory of your choice when complete).
- **Windows 10**, build 10586 or higher (validate your version number [here](http://windows.microsoft.com/en-US/windows/which-operating-system)).
- **Visual Studio 2015 Update 3** with Windows developer tools. Visual Studio 2015 Community is available for free [here](https://dev.windows.com/downloads). Select (at least) the following components during installation:
   1. Programming Languages -> Visual C++
   2. Universal Windows App Development Tools (all)
   
If you want to build the bridge from source instead, you'll also need to install [Git LFS](https://git-lfs.github.com) before cloning the repo. For more detailed instructions, see the [Building From Source](https://github.com/Microsoft/WinObjC/wiki/Building-From-Source) wiki page.

If you're having trouble downloading & installing the bridge, see the [Known Issues](https://github.com/Microsoft/WinObjC#known-issues) section below and check our [FAQ](https://github.com/Microsoft/WinObjC/wiki/FAQ).

## Getting Started With the Bridge
### Importing your Xcode Project
When using the bridge, the first thing you'll want to do is generate a Visual Studio solution from your Xcode project:

1. Open the Windows Command Prompt (type **cmd** in the Start Menu to find it) and navigate to your Xcode project directory using the **cd** command. Note that you should go to the directory containing your project *.xcworkspace* or *.xcodeproj* folder: you shouldn't be inside those folders, but one level above them.

  ```
    cd C:\winobjc\samples\MyProject
  ```
2. Still from the Command Prompt, run the vsimporter tool from the *bin* directory of the bridge SDK you downloaded, which will generate the Visual Studio Solution:

  ```
    C:\winobjc\bin\vsimporter.exe
  ```
3. Open the generated Visual Studio solution with the command:

  ```
    MyProject.sln
  ```

For more detailed step by step instructions on how to import a project, see the [Quick Start Tutorial](https://github.com/Microsoft/WinObjC/wiki/Quick-Start-Tutorial) page of the wiki. For vsimporter options and known issues, check the [Using vsimporter](https://github.com/Microsoft/WinObjC/wiki/Using-vsimporter) wiki page.

### Configuring Visual Studio
Once your solution is opened in Visual Studio, you'll want to enable Objective-C syntax highlighting and debugging.

- Installing the Syntax Highlighting Extension
  - To enable Objective-C syntax highlighting in Visual Studio, navigate to the *bin* directory of the SDK and double click on **objc-syntax-highlighting.vsix** to launch the installer.
- Setup Objective-C Debugging
  - To setup Objective-C debugging in Visual Studio, follow the instructions on the [Debugging](https://github.com/Microsoft/WinObjC/wiki/Debugging) page of the wiki.
  
### Analyzing your App
After importing your project, we strongly suggest using the [App Analysis Tool](https://developer.microsoft.com/en-us/windows/bridges/ios/app-analyzer-tool) to have a better understanding of the compatibility of your app with the bridge.

### Building & Running the Samples
A great way to learn more about the bridge and its features is building and running the samples of the SDK, which contain many code examples. We recommend starting with the **WOCCatalog** sample app, which demonstrates an assortment of iOS and XAML UI controls:

1. Navigate to the *samples/WOCCatalog* directory of the bridge SDK
2. Double-click on the **WOCCatalog-WinStore10.sln** solution to open it in Visual Studio
3. In Visual Studio, right-click on the **WOCCatalog (Universal Windows)** project
4. Select **Set as StartUp project**
5. Use **Ctrl-F5** to build and run the app

For more detailed step by step instructions, see the [Quick Start Tutorial](https://github.com/Microsoft/WinObjC/wiki/Quick-Start-Tutorial) page of the wiki.

## Resources & Documentation
The following resources will help you get started. For more information, check out:

1. [Wiki](https://github.com/Microsoft/WinObjC/wiki), for documentation and tutorials
2. [Development Roadmap](https://github.com/Microsoft/WinObjC/wiki/Roadmap), detailing our highest priorities
3. [App Analysis Tool](https://developer.microsoft.com/en-us/windows/bridges/ios/app-analyzer-tool), to evaluate the compatibility of your app with the bridge
4. [Website on Windows Dev Center](https://dev.windows.com/bridges/ios), for evaluation virtual machines
5. [Quick Start Challenge](https://github.com/Microsoft/WinObjC/wiki/Quick-Start-Tutorial), for a quick hands-on introduction to the bridge
7. [FAQ](https://github.com/Microsoft/WinObjC/wiki/FAQ), with common questions and issues
8. [The iOS Bridge Samples Repo](https://github.com/Microsoft/WinObjC-Samples), for sample apps and code using the bridge

## Contributing
There are many ways to contribute to the Windows Bridge for iOS:
- [Submit bugs & issues](https://github.com/Microsoft/WinObjC/issues) and help us verify fixes as they are checked in.
- Review source code changes.
- Submit a bug fix or feature implementation via [pull request](https://github.com/Microsoft/WinObjC/pulls).
- Follow [@WindowsDev on Twitter](https://twitter.com/windowsdev) and join the discussion using the [#WinObjC hashtag](https://twitter.com/hashtag/WinObjC).
- Engage with other users and developers on [StackOverflow](http://stackoverflow.com/) and tag your questions with [WinObjC](http://stackoverflow.com/questions/tagged/winobjc).

See our [contribution guidance in the wiki](https://github.com/Microsoft/WinObjC/wiki/How-to-Contribute) for more details on how to contribute to the project.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/). For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

## Privacy
See [Microsoft's privacy statement](https://www.microsoft.com/en-us/privacystatement/default.aspx) for more information.

## Roadmap
For details on our planned features and future direction sort the list of issues by [milestone](https://github.com/Microsoft/WinObjC/milestones) and refer to our [roadmap](https://github.com/Microsoft/WinObjC/wiki/Roadmap).

## Known Issues
- **Do not use the Download ZIP option via the "Clone or download" button at the top of the page.** You will not be able to build the bridge using the resulting .zip file. See ["I'm getting errors after downloading the bridge through the "Download ZIP" button on Github. What should I do?"](https://github.com/Microsoft/WinObjC/wiki/FAQ#im-getting-errors-after-downloading-the-bridge-through-the-download-zip-button-on-github-what-should-i-do) for more information.
