# Welcome to the Windows Bridge for iOS Project
The Windows Bridge for iOS (also referred to as WinObjC) is a Microsoft open-source project that provides an Objective-C development environment for Visual Studio and support for iOS APIs. The bridge allows you to create Universal Windows Platform (UWP) apps that will run on many Windows devices by re-using your Objective-C code and iOS APIs alongside Windows 10 features like Cortana and Windows Notifications.

|                      |           Stable (master)                        |            Pre-release (develop)          |
| -------------------: | :----------------------------------------------: | :---------------------------------------: |
|           **Build**  |                  -                               |       ![VSTS][develop-build-badge]        |
|  **GitHub Release**  |[![Github Release][github-rel-badge]][github-rel] |               -                           |
|    **WinObjC.Tools** |     [![Tools][choco-badge]][choco]               |   [![Tools][choco-badge-pre]][choco]      |
| **WinObjC.Language** |[![Language][nuget-lang-badge]][nuget-lang]       |[![Language][nuget-lang-badge-pre]][nuget-lang]   |
|**WinObjC.Frameworks**|[![Frameworks][nuget-frmwrk-badge]][nuget-frmwrk] |[![Frameworks][nuget-frmwrk-badge-pre]][nuget-frmwrk]|

## Download and Installation
To use the bridge you'll need:
- **Windows 10**, build 10586 or higher. Validate your version number [here](http://windows.microsoft.com/en-US/windows/which-operating-system).
- **Visual Studio 2017** with Windows developer tools. Visual Studio 2017 Community is available for free [here](https://dev.windows.com/downloads). Select (at least) the following components during installation:
   1. Programming Languages -> Visual C++
   2. Universal Windows App Development Tools (all)

To get started with an existing Xcode Project, you will also need:
- **Chocolatey**, a package manager for windows. See how to install the latest version [here] (https://chocolatey.org/)
- **WinObjC.Tools**, the command line tools for WinObjC. Run the below command from **powershell** to get the latest version:
```
choco upgrade WinObjC.Tools
```
(more information about this command and its options can be found [here](https://chocolatey.org/docs/commands-upgrade))


## Advanced Installation for Contributors and Ninjas
If you want to build the bridge from source instead, you'll also need to install [Git LFS](https://git-lfs.github.com) before cloning the repo. For more detailed instructions, see the [Building From Source](https://github.com/Microsoft/WinObjC/wiki/Building-From-Source) wiki page.

If you're having trouble downloading & installing the bridge, see the [Known Issues](https://github.com/Microsoft/WinObjC#known-issues) section below and check our [FAQ](https://github.com/Microsoft/WinObjC/wiki/FAQ).

## Getting Started With the Bridge
### Importing your Xcode Project
When using the bridge, the first thing you'll want to do is generate a Visual Studio solution from your Xcode project:

1. Open Windows PowerShell (type **powershell** in the Start Menu to find it) and navigate to your Xcode project directory using the **cd** command. Note: use the directory containing your .workspace or .xcodeproj folder.

  ```
    C:\> cd C:\MyProject
  ```
2. Run the vsimporter tool. This will generate the Visual Studio Solution:

  ```
    C:\MyProject> vsimporter.exe
  ```
3. Open the generated Visual Studio solution with the command:

  ```
    C:\MyProject> MyProject.sln
  ```

For more detailed step by step instructions on how to import a project, see the [Quick Start Tutorial](https://github.com/Microsoft/WinObjC/wiki/Quick-Start-Tutorial) page of the wiki. For vsimporter options and known issues, check the [Using vsimporter](https://github.com/Microsoft/WinObjC/wiki/Using-vsimporter) wiki page.

### Analyzing your App
After importing your project, we strongly suggest using the [App Analysis Tool](https://developer.microsoft.com/en-us/windows/bridges/ios/app-analyzer-tool) to have a better understanding of the compatibility of your app with the bridge.

### Building & Running the Samples
A great way to learn more about the bridge and its features is building and running the samples of the SDK, which contain many code examples. We recommend starting with the **WOCCatalog** sample app, which demonstrates an assortment of iOS and XAML UI controls:

1. Clone the repo.
2. Navigate to the *samples/WOCCatalog* directory of the bridge SDK
3. Double-click on the **WOCCatalog-WinStore10.sln** solution to open it in Visual Studio
4. In Visual Studio, right-click on the **WOCCatalog (Universal Windows)** project
5. Select **Set as StartUp project**
6. Use **Ctrl-F5** to build and run the app

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

[develop-build-badge]:        https://img.shields.io/vso/build/winobjc/03960378-fe55-4577-a8cc-1a874f7cf008/109.svg?style=flat-square
[github-rel]:                 https://github.com/Microsoft/WinObjC/releases/latest
[github-rel-badge]:           https://img.shields.io/github/release/microsoft/winobjc.svg?style=flat-square
[choco]:                      https://chocolatey.org/packages/WinObjC.Tools
[choco-badge]:                https://img.shields.io/chocolatey/v/WinObjC.Tools.svg?style=flat-square                 
[choco-badge-pre]:            https://img.shields.io/chocolatey/vpre/WinObjC.Tools.svg?style=flat-square
[nuget-frmwrk]:               https://www.nuget.org/packages/WinObjC.Frameworks
[nuget-frmwrk-badge]:         https://img.shields.io/nuget/v/WinObjC.Frameworks.svg?style=flat-square
[nuget-frmwrk-badge-pre]:     https://img.shields.io/nuget/vpre/WinObjC.Frameworks.svg?style=flat-square
[nuget-lang]:                 https://www.nuget.org/packages/WinObjC.Language
[nuget-lang-badge]:           https://img.shields.io/nuget/v/WinObjC.Language.svg?style=flat-square
[nuget-lang-badge-pre]:       https://img.shields.io/nuget/vpre/WinObjC.Language.svg?style=flat-square
