# WinObjC Unit Tests on OSX

As a measure to help ensure the accuracy of the WinObjC platform, we are beginning to support building and running WinObjC unit tests on OSX devices. By verifying our tests against the reference platform, we hope to reduce errors in test writing and incorrect assumptions about Objective-C APIs. Foundation.UnitTests are currently supported, with other test modules expected to follow suit.

It is recommended that edits to unit tests be verified on an OSX machine, if the developer has access to one. A list of current known failures is provided at the bottom.

#### Sharing your Windows enlistment with an OSX machine

While it's possible to checkout a separate git enlistment on an OSX machine and build WinObjC tests, it's recommended that developers maintain just one enlistment and share it out to an OSX machine instead. Below are some example steps for setting up a shared enlistment/ssh workflow, assuming your machines are on the same network.

1. Windows machine - share your Windows WinObjC enlistment with yourself:

    1. Right-click your enlistment root > Share with > Specific people...
    2. Select your own account, then click 'Share'.
    3. You should receive an address for the shared folder.

2. OSX machine - mount the shared volume:

    1. Open Finder.
    2. Press Command+K (Go > Connect to Server).
    3. Type in the address generated in 1.3, then press Connect. (You may wish to press + to save the address as a favorite)
    4. Finder may regenerate the address with a URI scheme such as smb://. If so, press Connect again. (You may need to adjust the number of slashes)
    5. Finder should open your shared folder.

3. OSX machine - enable remote login:
    
    1. Open System Preferences > Sharing.
    2. Click the checkbox next to Remote Login
    3. The right side should say something like: 
        * Remote Login: On 
        * To log in to this computer remotely, type "ssh address@address.com"
    4. Make note of the address.
    
4. Windows machine - install PuTTY and ssh into your OSX machine:

    1. Install PuTTY from http://www.putty.org/
    2. Using the address from 3.4 - run "putty address@address.com"
    3. Type in your password.

#### Building & Running Foundation Unit Tests

1. In a shell, cd to \<enlistment root\>/tests/unittests/Foundation
    * If your enlistment is shared from another machine, such as in the recommended steps above, your enlistment root will be in /Volumes/ (eg: /Volumes/WinObjC/)
2. Run 'make Foundation.UnitTests.exe' - this creates Foundation.UnitTests.exe in your current directory
3. The makefile will print an output location for Foundation.UnitTests.exe, eg: 
    * Done, please run from /Volumes/WinObjC/build/Tests/UnitTests/Foundation/OSX/Foundation.UnitTests.exe

4. Run '/Volumes/WinObjC/build/Tests/UnitTests/Foundation/OSX/Foundation.UnitTests.exe', or your equivalent address - 
    * --gtest_filter and similar options are available

#### Current known failures:


    * [==========] 833 tests from 74 test cases ran. (58373 ms total)
    * [  PASSED  ] 707 tests.
    * [  FAILED  ] 126 tests, listed below:
    * [  FAILED  ] Archival.NSKeyedUnarchiver_Secure
    * [  FAILED  ] KVO.DerivedKeyOnSubpath1
    * [  FAILED  ] KVO.RemoveWithoutContext
    * [  FAILED  ] Foundation.NSCompoundPredicate_copy
    * [  FAILED  ] NSArray.Description
    * [  FAILED  ] NSArray.BinarySearchInsertionIndex
    * [  FAILED  ] NSArray.BinarySearch
    * [  FAILED  ] NSArray.BinarySearchFringeCases
    * [  FAILED  ] NSAttributedString.CoalesceOverlapAfter
    * [  FAILED  ] NSAttributedString.CoalesceAdjacentAfter
    * [  FAILED  ] NSAttributedString.CoalesceOverlapBefore
    * [  FAILED  ] NSAttributedString.CoalesceAdjacentBefore
    * [  FAILED  ] NSAttributedString.CoalesceComplex
    * [  FAILED  ] NSAttributedString.OverwriteAfter
    * [  FAILED  ] NSAttributedString.OverwriteBefore
    * [  FAILED  ] NSAttributedString.EnumerateAttribute
    * [  FAILED  ] NSAttributedString.EnumerateAttributes
    * [  FAILED  ] NSBundle.ClassNamed
    * [  FAILED  ] NSBundle.Resources
    * [  FAILED  ] NSBundle.InfoPlist
    * [  FAILED  ] NSBundle.Localizations
    * [  FAILED  ] NSCache.DiscardableContent_DiscardButKeepOnEvict
    * [  FAILED  ] NSCalendar.GetDates
    * [  FAILED  ] NSCalendar.CompareDates
    * [  FAILED  ] NSCalendar.PreserveSmallerUnitsMatching
    * [  FAILED  ] NSCalendar.weekOfUnitMatching
    * [  FAILED  ] NSCalendar.NSRangeValidation
    * [  FAILED  ] NSCharacterSet.Polymorphic_Creators
    * [  FAILED  ] NSCharacterSet.Mutables
    * [  FAILED  ] NSComparisonPredicate.NSAnyPredicateModifier
    * [  FAILED  ] NSComparisonPredicate.NSAllPredicateModifier
    * [  FAILED  ] NSComparisonPredicate.NSAllPredicateModifier2
    * [  FAILED  ] NSComparisonPredicate.NSContainsPredicateOperatorType
    * [  FAILED  ] NSComparisonPredicate.ArchiveAndUnarchiveObject
    * [  FAILED  ] NSComparisonPredicate.copy
    * [  FAILED  ] NSCompoundPredicate.ArchiveAndUnarchiveObject
    * [  FAILED  ] NSData.Base64DecodeWithOptions
    * [  FAILED  ] NSData.WriteToURL
    * [  FAILED  ] NSData.WriteToURLOptions
    * [  FAILED  ] NSData.LongDebugDescription
    * [  FAILED  ] NSData.EdgeDebugDescription
    * [  FAILED  ] NSData.EdgeNoCopyDescription
    * [  FAILED  ] NSFileHandle.Init
    * [  FAILED  ] NSFileHandle.ReadFile
    * [  FAILED  ] NSFileHandle.UpdateAndSeeks
    * [  FAILED  ] NSFileHandle.Offsets
    * [  FAILED  ] NSFileHandle.WriteToNonExistentFileAndRead
    * [  FAILED  ] NSFileHandle.TruncateFileAtOffset
    * [  FAILED  ] NSFileHandle.ReadDataOfLength
    * [  FAILED  ] NSFileHandle.UpdatingURL
    * [  FAILED  ] NSFileHandle.ReadingFromURL
    * [  FAILED  ] NSFileHandle.WritingAtPath
    * [  FAILED  ] NSFileManager.GetAttributes
    * [  FAILED  ] NSFileManager.EnumateDirectoryUsingURL
    * [  FAILED  ] NSIndexSet.shiftIndexes
    * [  FAILED  ] NSInvocation.ArgumentLimit
    * [  FAILED  ] NSJSON.JSONObjectWithDataTests
    * [  FAILED  ] NSKeyValueCoding.AggerateFunctionUnionOfObjectsSet
    * [  FAILED  ] NSKeyValueCoding.AggerateFunctionSumDict
    * [  FAILED  ] NSKeyValueCoding.AggerateFunctionMaxDict
    * [  FAILED  ] NSKeyValueCoding.AggerateFunctionMinDict
    * [  FAILED  ] NSKeyValueCoding.AggerateFunctionAvgDict
    * [  FAILED  ] NSKeyValueCoding.AggerateFunctionDistinctUnionOfObjectsDict
    * [  FAILED  ] NSKeyValueCoding.AggerateFunctionNullLeafArray
    * [  FAILED  ] NSKeyValueCoding.AggerateFunctionNullLeafSet
    * [  FAILED  ] NSMapTable.WeakValue
    * [  FAILED  ] NSMapTable.WeakKey
    * [  FAILED  ] NSMapTable.MultipleWeakKey
    * [  FAILED  ] NSMapTable.WeakChain
    * [  FAILED  ] NSMapTable.WeakWeak
    * [  FAILED  ] NSMapTable.SameKey
    * [  FAILED  ] NSMapTable.Enumerators
    * [  FAILED  ] NSMapTable.Copy
    * [  FAILED  ] NSNumber.Derived_CFNumberGetValue
    * [  FAILED  ] NSObject.KVCArrayMutableAdapters
    * [  FAILED  ] NSPointerArray.Subclassing
    * [  FAILED  ] NSPointerArray.Equality
    * [  FAILED  ] NSPointerArray.RemovePointer
    * [  FAILED  ] NSPointerArray.Weak
    * [  FAILED  ] NSPointerArray.Encoder
    * [  FAILED  ] NSPointerFunctions.OpaquePersonality
    * [  FAILED  ] NSPointerFunctions.InvalidConfig
    * [  FAILED  ] NSPredicate.copy
    * [  FAILED  ] NSPredicate.Matches
    * [  FAILED  ] NSPredicate.Like
    * [  FAILED  ] NSProgress.IsIndeterminate
    * [  FAILED  ] NSProgress.ChainImplicit
    * [  FAILED  ] NSProgress.SingleParentEvenAcrossThreads
    * [  FAILED  ] NSProgress.CancelPauseResume
    * [  FAILED  ] NSProgress.LocalizedDescription
    * [  FAILED  ] NSRange.NSRangeTests
    * [  FAILED  ] NSRegularExpression.NSMatchingOptionsTest
    * [  FAILED  ] NSSet.ObjectsPassingTest
    * [  FAILED  ] NSString.NSStringTests
    * [  FAILED  ] NSString.IntegerValue
    * [  FAILED  ] NSString.IntValue
    * [  FAILED  ] NSString.FromContentsOfURL
    * [  FAILED  ] NSString.FromContentOfFile
    * [  FAILED  ] NSString.StringByResolvingSymlinksInPath
    * [  FAILED  ] NSThread.Priority
    * [  FAILED  ] NSTimeZone.SystemTimeZoneTests
    * [  FAILED  ] NSTimer.Init
    * [  FAILED  ] NSURLCache.StorageAndRetrieval
    * [  FAILED  ] NSURLCache.Eviction
    * [  FAILED  ] NSURLCache.Promotion
    * [  FAILED  ] NSURLCredential.credentialWithIdentity
    * [  FAILED  ] NSURLCredential.credentialForTrust
    * [  FAILED  ] NSURLRequest.HeaderFields
    * [  FAILED  ] NSURLSessionConfiguration.initValues
    * [  FAILED  ] NSURLSessionConfiguration.defaultSessionConfiguration
    * [  FAILED  ] NSURLSessionConfiguration.backgroundSessionConfigurationWithIdentifier
    * [  FAILED  ] NSURL.CheckResourceIsReachable
    * [  FAILED  ] NSURL.FileURLWithPath_relativeToURL
    * [  FAILED  ] NSURL.URLStrings
    * [  FAILED  ] NSURL.URLByResolvingSymlinksInPath
    * [  FAILED  ] NSURL.String
    * [  FAILED  ] NSValue.arbitraryStructCanBeSerializedAndDeserialized
    * [  FAILED  ] NSPropertyList.Decode
    * [  FAILED  ] NSPropertyList.DecodeMutable
    * [  FAILED  ] NSURLResponse.canBeArchived
    * [  FAILED  ] NSHTTPURLResponse.SuggestedFilename_3
    * [  FAILED  ] NSHTTPURLResponse.SuggestedFilename_4
    * [  FAILED  ] NSHTTPURLResponse.canBeArchived
    * [  FAILED  ] NSString/StringsFormatPropertyList.CanDeserialize/0, where GetParam() = L"\xFEFFkey1=value1;\n\"key2\"=\"value2\";"
    * [  FAILED  ] NSString/StringsFormatPropertyList.CanDeserialize/1, where GetParam() = L"key1=value1;\n\"key2\"=\"value2\";"
    * [  FAILED  ] NSString/ComparisonTests.PrefixSuffix/8, where GetParam() = (, , '\x1' (1), '\0', '\x1' (1), '\x1' (1), '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0')

    * 126 FAILED TESTS
    *   YOU HAVE 9 DISABLED TESTS
