# Contributing to WinObjC

There are many ways that you can contribute to the WinObjC project:

- File a bug/issue
- Verify fixes for bugs/issues
- Submit a bug fix or feature implementation
- Submit a feature request
- Submit additional tests
- Tell others about the WinObjC project
- Submit feedback on the project

## Code Conventions
Be sure to familiarize yourself with our [coding standards](Coding_Standards.md) before contributing code fixes.

## Automated Tests

### Running Tests

1. Build the entire solution (<root>\build\build.sln)

2. Run runall.bat under <Root>\WinObjC\tests\unittests

### Authoring UnitTests
1. The UnitTest project is in under build\UnitTests

2. Add test code under tests\unittests and include it into the UnitTest project

3. For more info on writing the tests, see [googletest samples](https://code.google.com/p/googletest/wiki/V1_7_Samples)

## Commit Guidance

Squash your change into 1 commit on top of the master branch.

For the commit message, follow the guide below:

```
The title is a ~50 character summary of the change.

After one blank line, add more detail about the change wrapped to ~80 
characters. If there is a github issue that is resolved by the change,
it can be added as below, with one blank line above it.

Fix #42
```

## Contribution License Agreement

You will need to sign a [Contribution License Agreement](https://cla.microsoft.com/) (CLA) before submitting your pull request. To complete the CLA, you will need to submit the request via the form and then electronically sign the CLA when you receive an email containing a link to the document.

This process needs to only be done once for any Microsoft open source project.

### Contributing to README and Wiki

You *do not* need to sign a Contribution License Agreement if you are just contributing to the README or the Wiki. However, by submitting a contribution to the README or the Wiki, you are contributing it under the [Creative Commons CC0 1.0 Universal Public Domain Dedication](http://creativecommons.org/publicdomain/zero/1.0/).

## Directory structure

- bin/ : Various prebuilt tools
- build/ : Projects/solutions to build the SDK
- deps/ : Open source dependencies
  - prebuilt/ : Prebuilt binaries for various architectures
- Frameworks/ : Implementation of iOS-style Frameworks
- include/ : SDK headers (including headers for iOS-style Frameworks)
  - Platform/ : Headers for Windows Objective-C bindings for various OS versions
- msvc/ : Visual Studio integration files
- samples/ : Assorted samples
- tools/ : Source code to tools

## Pull Request Flow

### Pre-request checklist

Please ensure the following before submitting a pull request for your changes:

- You have signed the [CLA](#contribution-license-agreement) and adhered to it.
- The entire solution (<root>\build\build.sln) builds with no errors for all flavors.
- The changed code follows our [code conventions](Coding_Standards.md).
- New tests have been added for all new features.
- All of the [automated tests](#automated-tests) pass with no failures.

### After submitting a request

What happens after a pull request is submitted?

- WinObjC team reviews the change, and checks for code convention or any other issues.
- WinObjC team verifies the change passes build and automated tests with no errors.

- If the above looks good, the pull request will be accepted, and the change will be merged into the master branch.  Otherwise, we will iterate over the changes with the contributor to work through any issues before accepting the pull request.