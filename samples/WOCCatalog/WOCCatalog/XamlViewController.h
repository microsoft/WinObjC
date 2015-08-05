//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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
#ifdef WINOBJC

#import <UIKit/UIKit.h>
#import <UWP/WindowsUIXamlControls.h>

#ifdef __MAPSUPPORT
#import <UWP/WXCMaps.h>
#endif

@interface XamlViewController : UITableViewController
    @property(nonatomic) WXCMediaElement *mediaElement;
#ifdef __MAPSUPPORT
    @property(nonatomic) WUXCMMapControl *mapElement;
#endif
    @property(nonatomic) WXCButton *playPauseButton;
@end

#endif
