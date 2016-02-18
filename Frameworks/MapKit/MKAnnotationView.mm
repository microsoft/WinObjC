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

#import <StubReturn.h>
#import <MapKit/MKAnnotationView.h>

@implementation MKAnnotationView
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithAnnotation:(id<MKAnnotation>)annotation reuseIdentifier:(NSString*)reuseIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)prepareForReuse {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDragState:(MKAnnotationViewDragState)newDragState animated:(BOOL)animated {
    UNIMPLEMENTED();
}

@end
