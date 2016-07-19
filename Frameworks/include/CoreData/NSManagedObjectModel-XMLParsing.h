//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#import <CoreData/CoreData.h>
#import <Foundation/Foundation.h>
#import <Starboard/SmartTypes.h>

@protocol _NSCDXMLCoding <NSObject>
@required
- (instancetype)_initWithXMLElementName:(NSString*)entityName attributes:(NSDictionary<NSString*, NSString*>*)attributes;
- (bool)_insertChildElement:(id<_NSCDXMLCoding>)childElement;
- (void)_awakeFromXML;
@end

@interface NSManagedObjectModel () <_NSCDXMLCoding>
@end

@interface NSEntityDescription () <_NSCDXMLCoding>
@property (readwrite, assign) NSManagedObjectModel* managedObjectModel;
@property (retain) NSArray* uniquenessConstraints;
- (void)_resolveRelationships;
@end

@interface NSPropertyDescription () <_NSCDXMLCoding>
@property (readwrite, assign) NSEntityDescription* entity;
@property (readwrite, strong) NSArray<NSPredicate*>* validationPredicates;
@end

@interface NSAttributeDescription ()
@end

@interface NSRelationshipDescription ()
// internal, from XML
@property (nonatomic, readonly) NSString* _destinationEntityName;
@property (nonatomic, readonly) NSString* _inverseEntityName;
@property (nonatomic, readonly) NSString* _inverseRelationshipName;
@end

/* exposed as a test surface */
COREDATA_EXPORT NSManagedObjectModel* _NSManagedObjectModelFromXMLData(NSData* data, NSURL* sourceURL);

COREDATA_EXPORT NSManagedObjectModel* _NSManagedObjectModelFromXMLDataAtURL(NSURL* url);
