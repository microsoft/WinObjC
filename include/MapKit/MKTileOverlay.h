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
#pragma once

#import <MapKit/MapKitExport.h>
#import <MapKit/MKOverlay.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSURL;
@class NSData;
@class NSError;

typedef struct {
    int x;
    int y;
    int z;
    CGFloat contentScaleFactor;
} MKTileOverlayPath;

MAPKIT_EXPORT_CLASS
@interface MKTileOverlay : NSObject <MKOverlay>
- (instancetype)initWithURLTemplate:(NSString*)URLTemplate STUB_METHOD;
@property CGSize tileSize STUB_PROPERTY;
@property (getter=isGeometryFlipped) BOOL geometryFlipped STUB_PROPERTY;
@property NSInteger minimumZ STUB_PROPERTY;
@property NSInteger maximumZ STUB_PROPERTY;
@property (nonatomic) BOOL canReplaceMapContent STUB_PROPERTY;
@property (readonly) NSString* URLTemplate STUB_PROPERTY;
- (NSURL*)URLForTilePath:(MKTileOverlayPath)path STUB_METHOD;
- (void)loadTileAtPath:(MKTileOverlayPath)path result:(void (^)(NSData*, NSError*))result STUB_METHOD;
@end
