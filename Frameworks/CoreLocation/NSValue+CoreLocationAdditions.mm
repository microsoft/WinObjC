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

#import <CoreLocation/NSValue+CoreLocationAdditions.h>

@implementation NSValue (CoreLocationAdditions)

- (id)initWithMKCoordinate:(CLLocationCoordinate2D)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CLLocationCoordinate2D)];
}

+ (NSValue*)valueWithMKCoordinate:(CLLocationCoordinate2D)value {
    return [[self alloc] initWithMKCoordinate:value];
}

- (CLLocationCoordinate2D)MKCoordinateValue {
    CLLocationCoordinate2D val;
    [self getValue:&val];
    return val;
}
@end

__attribute__((constructor)) static void _ForceTUInclusion() {
}