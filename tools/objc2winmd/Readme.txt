ObjC2Winmd tool is used to convert ObjC middleware to WinRT Components (.winmd and .dll).
The tools wraps the types from ObjC types in WinRT types and vice-versa.


###How to use the tool###
1. Use VSImporter (from WinObjC.Tools) to import your ObjC middleware to Islandwood.
2. Ensure that all public headers are explicitly marked "public":
   a. Open the generated .vcxproj file in an editor.
   b. Search for "<Keyword>IslandwoodProj</Keyword>"
      Add the following line right after it (without quotes) if not already there.
      "<ExportPublicHeaders>true</ExportPublicHeaders>"
   c. Individual headers can be marked as private.
      In the .vcxproj file search for the header name and add the tag <PublicHeader> with false value:
      <ClInclude Include="MyHeader.h">
        <PublicHeader>false</PublicHeader>
      </ClInclude>
3. Annotations in the public header files are sometimes required to ensure that the types are correctly marshalled.
   All annotations are added within doxygen-style comments.
   Following is a list of annotations that can be applied.
   \IgnoreDecl
      This is used to notify the tool that the type is ignored and no code should be generated for it.
      e.g.
      /**
      \IgnoreDecl
      */
      @interface UnnecessaryInterface
        ...
      @end
      
      The interface UnnecessaryInterface (and everything declared within it) will be ignored by the tool.
      
      To ignore a specific property or method add the annotation right above the declaration within doxygen-style comments.
      @interface PartiallyUnnecessaryInterface
        /**
        \IgnoreDecl
        */
        @property (nonatomic) bool notNeededProperty;
      @end
      
   \ReturnType
      This provides return type information to the tool when the type is ambiguous.
      e.g.
      /**
      \ReturnType:NSArray<int>
      */
      - (NSArray*) getAnArray;
      
      The return type is ambiguous as NSArray container type could hold any type, but WinRT is strongly typed and needs to know the contained types.
      
   \Parameter#n
      This provides parameter type information to the tool when the type is ambiguous.
      e.g.
      /**
        \ReturnType:NSArray<NSString*>
        \Parameter#1:NSDictionary<NSString*, NSString*>
        \Parameter#2:NSArray<NSString*>
      */
      + (NSArray*)objectWithProperties:(NSDictionary *)properties values:(NSArray*)val;
      
   \BlockParameter#n
      This provides block parameter type information to the tool when the type is ambiguous.
      e.g.
      /**
        \BlockParameter#2:NSString*
      */
      typedef void (^RequestHandler)(Connection *connection,
                                         id result,
                                         NSError *error);
      
   \PropertyIs
      This provides property type information to the tool.
      e.g.
      /**
        \PropertyIs:NSString*
      */
      @property (nonatomic) id Name;
      
   \AsyncMethod
      This notifies the tool that the method is an asynchronous method.
      e.g.
      /**
        \AsyncMethod
      */
      - (void)executeHandler:(RequestHandler)handler;
      
   \ApplicationDelegate
      The interface is an application delegate. A WinRT wrapper will be generated and the WinRT user
      is expected to implement the interface.
      e.g.
      /**
        \ApplicationDelegate
      */
      @interface SDKApplicationDelegate : NSObject
        ...
      @end
      
   \DelegateCallbackProtocol
      This notifies the tool that the ObjC protocol is a delegate. The generated wrapper interface is to be
      implemented by the user of the interface in Windows.
      /**
        \DelegateCallbackProtocol
      */
      @protocol FBSDKSharingDelegate <NSObject>
        ...
      @end
      
   \DelegateAllocator
      This notifies the tool that the method on the delegate callback protocol is an allocator.
      e.g.
      + (instancetype)sharedInstance;
       
   \DelegateInitializer
      This notifies the tool that the method on the delegate callback protocol is an initializer.
      e.g.
      + (instancetype)init;
      
   \DelegateAllocatorAndInitializer
      This notifies the tool that the method on the delegate callback protocol is both an allocator and and initializer.
      e.g.
      + (instancetype)getSharedInstance;
      
   \GeneratesNotification
      This notifies the tool that the middleware generates notification (NSNotification).
      This tag could go on any interface/type in  public header, but, it is recommended to put it on the interface whose type
      (properties or methods) generates the notification.
      e.g.
      \**
        \GeneratesNotification
      */
      @interface AccessTokens : NSObject
      - (void)methodGeneratesNotification;
      @end
      
   \PossibleTypes
      This notifies the tool that the ObjC type could be one of the many types defined after this annotation.
      e.g.
      /**
        \ReturnType:PossibleTypes:NSArray<[int | float]>:NSDictionary<[NSString* | int | float],[InterfaceType* | int | bool]>
      */
      - (id)getOneOfMultipleTypes;
      
      The return type from this method could be an array containing integers and/or floats or and NSDictionary whose key types
      are NSString or int or float and the value types are InterfaceType* or int or bool.
      
4. Rebuild the solution.
   Files will be generated for WinRT wrapper and placed under the project <Middleware Name>WinRT.vcxproj.
   The files will be built as part of the rebuild step, the output of which is a *.winmd and *.dll.