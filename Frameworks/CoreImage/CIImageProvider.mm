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
#import <CoreImage/CIImageProvider.h>

NSString* const kCIImageProviderTileSize = @"kCIImageProviderTileSize";
NSString* const kCIImageProviderUserInfo = @"kCIImageProviderUserInfo";

@implementation NSObject (CoreImage)

// clang-format off
// clang format doesn't approve of unlabeled parameters
/**
 @Status Stub
 @Notes
*/
- (void)provideImageData:(void*)data
             bytesPerRow:(size_t)rowbytes
                  origin:(size_t)x
                        :(size_t)y
                    size:(size_t)width
                        :(size_t)height
                userInfo:(id)info {
    UNIMPLEMENTED();
}
// clang-format on

@end
@implementation CIImage (CIImageProvider)
@end
