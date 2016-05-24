// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//



#if DEPLOYMENT_RUNTIME_OBJC || os(Linux)
    import Foundation
    import XCTest
#else
    import SwiftFoundation
    import SwiftXCTest
#endif



class TestNSBundle : XCTestCase {
    
    static var allTests: [(String, TestNSBundle -> () throws -> Void)] {
        return [
            ("test_paths", test_paths),
            ("test_resources", test_resources),
            ("test_infoPlist", test_infoPlist),
            ("test_localizations", test_localizations),
            ("test_URLsForResourcesWithExtension", test_URLsForResourcesWithExtension),
        ]
    }
    
    func test_paths() {
        let bundle = NSBundle.mainBundle()
        
        // bundlePath
        XCTAssert(!bundle.bundlePath.isEmpty)
        XCTAssertEqual(bundle.bundleURL.path, bundle.bundlePath)
        let path = bundle.bundlePath
        
        // etc
        #if os(OSX)
        XCTAssertEqual("\(path)/Contents/Resources", bundle.resourcePath)
        XCTAssertEqual("\(path)/Contents/MacOS/TestFoundation", bundle.executablePath)
        XCTAssertEqual("\(path)/Contents/Frameworks", bundle.privateFrameworksPath)
        XCTAssertEqual("\(path)/Contents/SharedFrameworks", bundle.sharedFrameworksPath)
        XCTAssertEqual("\(path)/Contents/SharedSupport", bundle.sharedSupportPath)
        #endif
        
        XCTAssertNil(bundle.pathForAuxiliaryExecutable("no_such_file"))
        XCTAssertNil(bundle.appStoreReceiptURL)
    }
    
    func test_resources() {
        let bundle = NSBundle.mainBundle()
        
        // bad resources
        XCTAssertNil(bundle.URLForResource(nil, withExtension: nil, subdirectory: nil))
        XCTAssertNil(bundle.URLForResource("", withExtension: "", subdirectory: nil))
        XCTAssertNil(bundle.URLForResource("no_such_file", withExtension: nil, subdirectory: nil))
        
        // test file
        let testPlist = bundle.URLForResource("Test", withExtension: "plist")
        XCTAssertNotNil(testPlist)
        XCTAssertEqual("Test.plist", testPlist!.lastPathComponent)
        XCTAssert(NSFileManager.defaultManager().fileExists(atPath: testPlist!.path!))
        
        // aliases, paths
        XCTAssertEqual(testPlist!.path, bundle.URLForResource("Test", withExtension: "plist", subdirectory: nil)!.path)
        XCTAssertEqual(testPlist!.path, bundle.pathForResource("Test", ofType: "plist"))
        XCTAssertEqual(testPlist!.path, bundle.pathForResource("Test", ofType: "plist", inDirectory: nil))
    }
    
    func test_infoPlist() {
        let bundle = NSBundle.mainBundle()
        
        // bundleIdentifier
        XCTAssertEqual("org.swift.TestFoundation", bundle.bundleIdentifier)
        
        // infoDictionary
        let info = bundle.infoDictionary
        XCTAssertNotNil(info)
        XCTAssert("org.swift.TestFoundation" == info!["CFBundleIdentifier"] as! String)
        XCTAssert("TestFoundation" == info!["CFBundleName"] as! String)
        
        // localizedInfoDictionary
        XCTAssertNil(bundle.localizedInfoDictionary) // FIXME: Add a localized Info.plist for testing
    }
    
    func test_localizations() {
        let bundle = NSBundle.mainBundle()
        
        XCTAssertEqual(["en"], bundle.localizations)
        XCTAssertEqual(["en"], bundle.preferredLocalizations)
        XCTAssertEqual(["en"], NSBundle.preferredLocalizationsFromArray(["en", "pl", "es"]))
    }
    
    private let _bundleName = "MyBundle.bundle"
    private let _bundleResourceNames = ["hello.world", "goodbye.world", "swift.org"]
    private let _subDirectory = "Sources"
    private let _main = "main"
    private let _type = "swift"
    
    private func _setupPlayground() -> String? {
        // Make sure the directory is uniquely named
        let tempDir = "/tmp/TestFoundation_Playground_" + NSUUID().UUIDString + "/"
        
        do {
            try NSFileManager.defaultManager().createDirectory(atPath: tempDir, withIntermediateDirectories: false, attributes: nil)
            
            // Make a flat bundle in the playground
            let bundlePath = tempDir + _bundleName
            try NSFileManager.defaultManager().createDirectory(atPath: bundlePath, withIntermediateDirectories: false, attributes: nil)
            
            // Put some resources in the bundle
            for n in _bundleResourceNames {
                NSFileManager.defaultManager().createFile(atPath: bundlePath + "/" + n, contents: nil, attributes: nil)
            }
            // Add a resource into a subdirectory
            let subDirPath = bundlePath + "/" + _subDirectory
            try NSFileManager.defaultManager().createDirectory(atPath: subDirPath, withIntermediateDirectories: false, attributes: nil)
            NSFileManager.defaultManager().createFile(atPath: subDirPath + "/" + _main + "." + _type, contents: nil, attributes: nil)
        } catch _ {
            return nil
        }
        
        
        return tempDir
    }
    
    private func _cleanupPlayground(_ location: String) {
        do {
            try NSFileManager.defaultManager().removeItem(atPath: location)
        } catch _ {
            // Oh well
        }
    }

    func test_URLsForResourcesWithExtension() {
        guard let playground = _setupPlayground() else { XCTFail("Unable to create playground"); return }
        
        let bundle = NSBundle(path: playground + _bundleName)
        XCTAssertNotNil(bundle)
        
        let worldResources = bundle?.URLsForResourcesWithExtension("world", subdirectory: nil)
        XCTAssertNotNil(worldResources)
        XCTAssertEqual(worldResources?.count, 2)
        
        let path = bundle?.pathForResource(_main, ofType: _type, inDirectory: _subDirectory)
        XCTAssertNotNil(path)
        
        _cleanupPlayground(playground)
    }
}
