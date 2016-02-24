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

#import "AccelerateViewController.h"
#import "SingleImageViewController.h"

@implementation AccelerateViewController

int accelerateImageNumber = 1;
int valueRed = 100, valueGreen = 100, valueBlue = 100;
int convolveSize = 1;
NSArray *indexPathArray;
UIImage *img;
UIImageView *imv;
UISlider* redSlider;
UISlider* greenSlider;
UISlider* blueSlider;
UISlider* convolveSlider;
UILabel *rLabel, *gLabel, *bLabel, *boxLabel;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    redSlider = [[UISlider alloc] initWithFrame:CGRectMake(5.0, 12.0, 180.0, 8.0)];
    redSlider.backgroundColor = [UIColor clearColor];
    redSlider.minimumValue = 0.0;
    redSlider.maximumValue = 200.0;
    redSlider.continuous = YES;
    redSlider.value = 100.0;
    
    greenSlider = [[UISlider alloc] initWithFrame:CGRectMake(5.0, 12.0, 180.0, 8.0)];
    greenSlider.backgroundColor = [UIColor clearColor];
    greenSlider.minimumValue = 0.0;
    greenSlider.maximumValue = 200.0;
    greenSlider.continuous = YES;
    greenSlider.value = 100.0;
    
    blueSlider = [[UISlider alloc] initWithFrame:CGRectMake(5.0, 12.0, 180.0, 8.0)];
    blueSlider.backgroundColor = [UIColor clearColor];
    blueSlider.minimumValue = 0.0;
    blueSlider.maximumValue = 200.0;
    blueSlider.continuous = YES;
    blueSlider.value = 100.0;
    
    convolveSlider = [[UISlider alloc] initWithFrame:CGRectMake(5.0, 12.0, 180.0, 8.0)];
    convolveSlider.backgroundColor = [UIColor clearColor];
    convolveSlider.minimumValue = 1.0;
    convolveSlider.maximumValue = 99.0;
    convolveSlider.continuous = YES;
    convolveSlider.value = 1.0;
    
    [redSlider addTarget:self action:@selector(redChanged:) forControlEvents:UIControlEventValueChanged];
    [greenSlider addTarget:self action:@selector(greenChanged:) forControlEvents:UIControlEventValueChanged];
    [blueSlider addTarget:self action:@selector(blueChanged:) forControlEvents:UIControlEventValueChanged];
    [convolveSlider addTarget:self action:@selector(convolveChanged:) forControlEvents:UIControlEventValueChanged];
    
    rLabel = [[UILabel alloc] init];
    gLabel = [[UILabel alloc] init];
    bLabel = [[UILabel alloc] init];
    boxLabel = [[UILabel alloc] init];
    
    img = [UIImage imageNamed:[NSString stringWithFormat:@"photo%d.jpg", accelerateImageNumber]];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 8;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    if (indexPath.row == 1)
        return screenRect.size.height - 360;
    return 40;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }
    
    if (indexPath.row == 0) {
        // Title cell
        
        cell.textLabel.text = @"Accelerate Test";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 1) {
        // Image display box
        
        [imv removeFromSuperview];
        UIImage *transformImg = [self transformImage:img];
        imv = [[UIImageView alloc] initWithFrame:CGRectMake(3, 2, cell.bounds.size.width - 6.0f, cell.bounds.size.height - 4.0f)];
        imv.image = transformImg;
        
        [imv setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
        [cell addSubview:imv];
        
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 2) {
        // Red controls
        
        /*UIButton *rDown  = [UIButton buttonWithType:UIButtonTypeRoundedRect];
         rDown.frame = CGRectMake(cell.bounds.size.width - 70.0f, 5.0f, 30.0f, cell.bounds.size.height - 15.0f);
         rDown.layer.cornerRadius = 5.0f;
         rDown.backgroundColor = [UIColor lightGrayColor];
         [rDown setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
         [rDown setTitle:@"-" forState:UIControlStateNormal];
         [rDown setAutoresizingMask:UIViewAutoresizingFlexibleLeftMargin];
         
         UIButton *rUp  = [UIButton buttonWithType:UIButtonTypeRoundedRect];
         rUp.frame = CGRectMake(cell.bounds.size.width - 35.0f, 5.0f, 30.0f, cell.bounds.size.height - 15.0f);
         rUp.layer.cornerRadius = 5.0f;
         rUp.backgroundColor = [UIColor lightGrayColor];
         [rUp setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
         [rUp setTitle:@"+" forState:UIControlStateNormal];
         [rUp setAutoresizingMask:UIViewAutoresizingFlexibleLeftMargin];
         
         [cell addSubview:rDown];
         [cell addSubview:rUp];
         */
        
        //cell.textLabel.text = [NSString stringWithFormat:@"Red: %d%%", valueRed];
        cell.textLabel.text = [NSString stringWithFormat:@"Red"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        
        cell.accessoryView = redSlider;
        
        //[redSlider addTarget:self action:@selector(redChanged:) forControlEvents:UIControlEventValueChanged];
        
        //[rUp addTarget:self action:@selector(rUpPress) forControlEvents:UIControlEventTouchUpInside];
        //[rDown addTarget:self action:@selector(rDownPress) forControlEvents:UIControlEventTouchUpInside];
    } else if (indexPath.row == 3) {
        // Green controls
        
        cell.textLabel.text = [NSString stringWithFormat:@"Green"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        
        cell.accessoryView = greenSlider;
    } else if (indexPath.row == 4) {
        // Blue controls
        
        cell.textLabel.text = [NSString stringWithFormat:@"Blue"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        
        cell.accessoryView = blueSlider;
    } else if (indexPath.row == 5) {
        // Box convolve controls
        
        cell.textLabel.text = [NSString stringWithFormat:@"Blur"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        
        cell.accessoryView = convolveSlider;
    } else if (indexPath.row == 6) {
        // Labels
        
        [rLabel removeFromSuperview];
        [gLabel removeFromSuperview];
        [bLabel removeFromSuperview];
        [boxLabel removeFromSuperview];
        
        rLabel.text = [NSString stringWithFormat:@"R: %d%%", valueRed];
        gLabel.text = [NSString stringWithFormat:@"G: %d%%", valueGreen];
        bLabel.text = [NSString stringWithFormat:@"B: %d%%", valueBlue];
        boxLabel.text = [NSString stringWithFormat:@"Kernel Size: %d", convolveSize];
        
        rLabel.frame = CGRectMake(17.0f, 5.0f, 100.0f, cell.bounds.size.height - 5.0f);
        gLabel.frame = CGRectMake(92.0f, 5.0f, 100.0f, cell.bounds.size.height - 5.0f);
        bLabel.frame = CGRectMake(167.0f, 5.0f, 100.0f, cell.bounds.size.height - 5.0f);
        boxLabel.frame = CGRectMake(242.0f, 5.0f, 200.0f, cell.bounds.size.height - 5.0f);
        
        [rLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight];
        [gLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight];
        [bLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight];
        [boxLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight];
        
        [cell addSubview:rLabel];
        [cell addSubview:gLabel];
        [cell addSubview:bLabel];
        [cell addSubview:boxLabel];
        
    } else if (indexPath.row == 7) {
        // Image change
        
        UIButton *imageChange  = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        imageChange.frame = CGRectMake(10.0f, 5.0f, 120.0f, cell.bounds.size.height - 15.0f);
        imageChange.layer.cornerRadius = 5.0f;
        imageChange.backgroundColor = [UIColor lightGrayColor];
        [imageChange setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [imageChange setTitle:@"Next Image" forState:UIControlStateNormal];
        
        [cell addSubview:imageChange];
        
        [imageChange addTarget:self action:@selector(imageChangePress) forControlEvents:UIControlEventTouchUpInside];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    
    return cell;
}

-(void) redChanged:(UISlider *)slider {
    int oldValue = valueRed;
    valueRed = (int) slider.value;
    
    if (oldValue != valueRed) {
        indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:1 inSection:0]];
        [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
        
        indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:6 inSection:0]];
        [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
    }
}

-(void) blueChanged:(UISlider *)slider {
    int oldValue = valueBlue;
    valueBlue = (int) slider.value;
    
    if (oldValue != valueBlue) {
        indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:1 inSection:0]];
        [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
        
        indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:6 inSection:0]];
        [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
    }
}

-(void) greenChanged:(UISlider *)slider {
    int oldValue = valueGreen;
    valueGreen = (int) slider.value;
    
    if (oldValue != valueGreen) {
        indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:1 inSection:0]];
        [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
        
        indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:6 inSection:0]];
        [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
    }
}

-(void) convolveChanged:(UISlider *)slider {
    int oldValue = convolveSize;
    convolveSize = (int) slider.value;
    convolveSize += (convolveSize % 2) - 1;
    
    if (oldValue != convolveSize) {
        indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:1 inSection:0]];
        [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
        
        indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:6 inSection:0]];
        [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
    }
}


-(void) imageChangePress
{
    accelerateImageNumber++;
    if (accelerateImageNumber == 7)
        accelerateImageNumber = 1;
    
    img = [UIImage imageNamed:[NSString stringWithFormat:@"photo%d.jpg", accelerateImageNumber]];
    
    indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:1 inSection:0]];
    [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
    
    indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:6 inSection:0]];
    [self.tableView reloadRowsAtIndexPaths:indexPathArray withRowAnimation:UITableViewRowAnimationNone];
}

-(UIImage *)transformImage:(UIImage *)image {
    CGImageRef img = image.CGImage;
    
    vImage_Buffer inBuffer, midBuffer, outBuffer;
    vImage_Error error;
    void *pixelBuffer, *midPixelBuffer;
    
    //create vImage_Buffer with data from CGImageRef
    
    CGDataProviderRef inProvider = CGImageGetDataProvider(img);
    CFDataRef inBitmapData = CGDataProviderCopyData(inProvider);
    
    inBuffer.width = CGImageGetWidth(img);
    inBuffer.height = CGImageGetHeight(img);
    inBuffer.rowBytes = CGImageGetBytesPerRow(img);
    
    inBuffer.data = (void*)CFDataGetBytePtr(inBitmapData);
    
    //create vImage_Buffer for output
    
    midPixelBuffer = malloc(CGImageGetBytesPerRow(img) * CGImageGetHeight(img));
    pixelBuffer = malloc(CGImageGetBytesPerRow(img) * CGImageGetHeight(img));
    
    if(midPixelBuffer == NULL)
        NSLog(@"No midpixelbuffer");
    if(pixelBuffer == NULL)
        NSLog(@"No pixelbuffer");
    
    midBuffer.data = midPixelBuffer;
    midBuffer.width = CGImageGetWidth(img);
    midBuffer.height = CGImageGetHeight(img);
    midBuffer.rowBytes = CGImageGetBytesPerRow(img);
    
    outBuffer.data = pixelBuffer;
    outBuffer.width = CGImageGetWidth(img);
    outBuffer.height = CGImageGetHeight(img);
    outBuffer.rowBytes = CGImageGetBytesPerRow(img);
    
    int16_t A[] = { valueRed, 0, 0, 0,
        0, valueGreen, 0, 0,
        0, 0, valueBlue, 0,
        0, 0, 0, 0 };
    
    double meandivisor = 100;
    
    error = vImageMatrixMultiply_ARGB8888(&inBuffer, &midBuffer, A, meandivisor, NULL, NULL, 0);
    
    if (error) {
        NSLog(@"error from matrix multiply %ld", error);
    }
    
    Pixel_8888 background;
    background[0] = 0;
    background[1] = 0;
    background[2] = 0;
    background[3] = 0;
    
    //perform convolution
    error = vImageBoxConvolve_ARGB8888(&midBuffer, &outBuffer, NULL, 0, 0, convolveSize, convolveSize, background, kvImageEdgeExtend);
    
    if (error) {
        NSLog(@"error from convolution %ld", error);
    }
    
    //create CGImageRef from vImage_Buffer output
    //1 - CGBitmapContextCreateImage -
    
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    
    CGContextRef ctx = CGBitmapContextCreate(outBuffer.data,
                                             outBuffer.width,
                                             outBuffer.height,
                                             8,
                                             outBuffer.rowBytes,
                                             colorSpace,
                                             (CGBitmapInfo)kCGImageAlphaNoneSkipLast);
    CGImageRef imageRef = CGBitmapContextCreateImage (ctx);
    
    UIImage *returnImage = [UIImage imageWithCGImage:imageRef];
    
    //clean up
    CGContextRelease(ctx);
    CGColorSpaceRelease(colorSpace);
    free(midPixelBuffer);
    free(pixelBuffer);
    CFRelease(inBitmapData);
    CGImageRelease(imageRef);
    
    return returnImage;
    
}

@end

