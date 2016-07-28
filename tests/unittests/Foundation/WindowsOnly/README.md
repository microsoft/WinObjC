Test files in this directory are compiled + run for Windows, only.
Be sure to add the .mm to the correct .vcxproj and filters (*.WindowsOnly.UnitTests.vcxproj, vcxproj.filters)

This directory is intended to contain, but is not limited to the following types of cross-platform-incompatible tests:

- Unit tests that test internal implementation details of objective-C APIs, that don't exist/are not public on OSX
- Tests involving Windows-only features, such as HRESULTs
- Tests involving WinObjC-only APIs, such as WinObjC_SetZombiesEnabled