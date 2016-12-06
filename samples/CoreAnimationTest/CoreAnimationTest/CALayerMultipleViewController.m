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

#import "CALayerMultipleViewController.h"
#import "LayerTableViewCell.h"
#import "PropertyTableViewCell.h"
#import "SliderTableViewCell.h"
#import "StringTableViewCell.h"
#import "SwitchTableViewCell.h"
#import "CGPointTableViewCell.h"
#import "CGRectTableViewCell.h"
#import "ViewHeaderFooterView.h"

#define VC_WIDTH self.view.frame.size.width
#define VC_HEIGHT self.view.frame.size.height

#define HIDDEN_POS [_exposedProperties.allKeys indexOfObject:kHiddenProperty]
#define OPACITY_POS [_exposedProperties.allKeys indexOfObject:kOpacityProperty]
#define CONTENTS_GRAVITY_POS [_exposedProperties.allKeys indexOfObject:kContentsGravityProperty]
#define CONTENTS_POS [_exposedProperties.allKeys indexOfObject:kContentsProperty]
#define SHOULD_RASTERIZE_POS [_exposedProperties.allKeys indexOfObject:kShouldRasterizeProperty]
#define RASTERIZATION_SCALE_POS [_exposedProperties.allKeys indexOfObject:kRasterizationScaleProperty]
#define CONTENTS_SCALE_POS [_exposedProperties.allKeys indexOfObject:kContentsScaleProperty]
#define DOUBLE_SIDED_POS [_exposedProperties.allKeys indexOfObject:kDoubleSidedProperty]
#define GEOMETRY_FLIPPED_POS [_exposedProperties.allKeys indexOfObject:kGeometryFlippedProperty]
#define CORNER_RADIUS_POS [_exposedProperties.allKeys indexOfObject:kCornerRadiusProperty]
#define BORDER_WIDTH_POS [_exposedProperties.allKeys indexOfObject:kBorderWidthProperty]
#define MASKS_TO_BOUNDS_POS [_exposedProperties.allKeys indexOfObject:kMasksToBoundsProperty]

typedef NS_ENUM(NSInteger, TransformProperty) { PositionX = 0, PositionY, Rotation, Scaling, UseAffine };

@interface CALayerMultipleViewController ()

@property UITableView* leftMenu;
@property UITableView* rightMenu;
@property UIButton* toggleLeftMenuButton;
@property UIButton* toggleRightMenuButton;
@property UIButton* addViewButton;

@end

@implementation CALayerMultipleViewController {
    UIView* _stage; // Container for generated views
    UIView* _currentView; // Currently selected view
    CALayer* _currentLayer; // Currently selected layer
    NSLayoutConstraint* _leftMenuLeftConstraint;
    NSLayoutConstraint* _rightMenuRightConstraint;

    NSArray* _colors; // Colors to use for generated views
    NSDictionary* _images; // Images for setting contents of layers
    NSMutableDictionary* _transformSettings; // Cache transform mode, position and rotation of generated views
    NSDictionary* _exposedProperties; // Properties exposed to control in the UI and whether they are enabled
    NSArray* _contentsGravityOptionsArray; // Contents gravity option constants
}

// Cell Identifiers
static NSString* const kLayerCellIdentifier = @"LayerCell";
static NSString* const kSliderCellIdentifier = @"SliderCell";
static NSString* const kStringCellIdentifier = @"StringCell";
static NSString* const kSwitchCellIdentifier = @"SwitchCell";
static NSString* const kPickerCellIdentifier = @"PickerCell";
static NSString* const kCGPointCellIdentifier = @"CGPointCell";
static NSString* const kCGRectCellIdentifier = @"CGRectCell";

// Header identifiers
static NSString* const kViewHeaderViewIdentifier = @"ViewHeaderView";

// Position identifiers
static NSString* const kCenterYIdentifier = @"CenterY";
static NSString* const kCenterXIdentifier = @"CenterX";

// Property identifiers
static NSString* const kHiddenProperty = @"Hidden";
static NSString* const kOpacityProperty = @"Opacity";
static NSString* const kContentsGravityProperty = @"Contents gravity";
static NSString* const kContentsProperty = @"Contents";
static NSString* const kShouldRasterizeProperty = @"Should rasterize";
static NSString* const kRasterizationScaleProperty = @"Rasterization scale";
static NSString* const kContentsScaleProperty = @"Contents scale";
static NSString* const kDoubleSidedProperty = @"Double sided";
static NSString* const kGeometryFlippedProperty = @"Geometry flipped";
static NSString* const kCornerRadiusProperty = @"Corner radius";
static NSString* const kBorderWidthProperty = @"Border width";
static NSString* const kMasksToBoundsProperty = @"Masks to bounds";

// Constants
static NSInteger const kNumGeneratedViews = 3; // Number of views to initially generate
static NSInteger const kSublayersForNewViews = 2; // Number of sublayers to add for new views
static CGFloat const kLayerViewSize = 150.0f; // Size of new views
static CGFloat const kLayerViewOverlap = 0.333f; // Overlap of batch generated views, proportion
static CGFloat const kSublayerSpacing = 25.0f; // Spacing of generated sublayers, pixels
static CGFloat const kMenuMinWidth = 180.0f; // Min width for right and left menus
static CGFloat const kLayerCellHeight = 60.0f; // Height of cells in left menu
static CGFloat const kViewHeaderHeight = 96.0f; // Height of headers in left menu
static CGFloat const kPropertyHeaderHeight = 96.0f; // Height of headers in right menu
CGFloat const kPropertyCellHeight = 80.0f; // Height of cells in right menu
CGFloat const kPadding = 16.0f;

- (instancetype)init {
    if (self = [super init]) {
        self.automaticallyAdjustsScrollViewInsets = NO;
        self.edgesForExtendedLayout = UIRectEdgeNone;

        _transformSettings = [NSMutableDictionary new];
        _colors = @[
            [UIColor redColor],
            [UIColor orangeColor],
            [UIColor yellowColor],
            [UIColor greenColor],
            [UIColor cyanColor],
            [UIColor blueColor],
            [UIColor purpleColor],
            [UIColor magentaColor],
            [UIColor grayColor],
            [UIColor blackColor]
        ];

        _images = @{
            @"none" : [UIImage new],
            @"safe" : [UIImage imageNamed:@"safe.png"],
            @"stork" : [UIImage imageNamed:@"storkinayutthaya.png"],
            @"3x3" : [UIImage imageNamed:@"3x3grid.png"],
            @"star" : [UIImage imageNamed:@"star.png"]
        };

        _contentsGravityOptionsArray = @[
            kCAGravityResize,
            kCAGravityResizeAspect,
            kCAGravityResizeAspectFill,
            kCAGravityCenter,
            kCAGravityTop,
            kCAGravityBottom,
            kCAGravityLeft,
            kCAGravityRight,
            kCAGravityTopLeft,
            kCAGravityTopRight,
            kCAGravityBottomLeft,
            kCAGravityBottomRight
        ];

        // Properties to be exposed to the property inspector and whether they should be enabled or not
        _exposedProperties = @{
            kHiddenProperty : @(YES),
            kOpacityProperty : @(YES),
            kContentsGravityProperty : @(YES),
            kContentsProperty : @(YES),
            kShouldRasterizeProperty : @(YES),
            kRasterizationScaleProperty : @(YES),
            kContentsScaleProperty : @(YES),
            kDoubleSidedProperty : @(NO),
            kGeometryFlippedProperty : @(NO),
            kCornerRadiusProperty : @(NO),
            kBorderWidthProperty : @(NO),
            kMasksToBoundsProperty : @(NO)
        };
    }

    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];

    // Set up stage
    _stage = [[UIView alloc] initWithFrame:self.view.bounds];
    _stage.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:_stage];

    // Left menu - views
    self.leftMenu = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, VC_WIDTH / 5.0, VC_HEIGHT) style:UITableViewStylePlain];
    self.leftMenu.delegate = self;
    self.leftMenu.dataSource = self;
    self.leftMenu.alwaysBounceVertical = NO;
    self.leftMenu.backgroundColor = [UIColor whiteColor];
    self.leftMenu.layer.masksToBounds = NO;
    self.leftMenu.layer.shadowColor = [UIColor blackColor].CGColor;
    self.leftMenu.layer.shadowRadius = 0.5f;
    self.leftMenu.layer.shadowOffset = CGSizeMake(1.0f, 0.0f);
    self.leftMenu.layer.shadowOpacity = 0.2f;
    self.leftMenu.translatesAutoresizingMaskIntoConstraints = NO;
    [self.leftMenu registerClass:[LayerTableViewCell class] forCellReuseIdentifier:kLayerCellIdentifier];
    [self.leftMenu registerClass:[ViewHeaderFooterView class] forHeaderFooterViewReuseIdentifier:kViewHeaderViewIdentifier];
    [self.view addSubview:self.leftMenu];

    // Set up left menu toggle button
    self.toggleLeftMenuButton = [UIButton new];
    self.toggleLeftMenuButton.translatesAutoresizingMaskIntoConstraints = NO;
    [self.toggleLeftMenuButton setTitle:@"\u276e" forState:UIControlStateNormal];
    [self.toggleLeftMenuButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [self.toggleLeftMenuButton addTarget:self action:@selector(toggleLeftMenu) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.toggleLeftMenuButton];
    [self.toggleLeftMenuButton sizeToFit];

    // Set up add view button
    self.addViewButton = [UIButton new];
    self.addViewButton.translatesAutoresizingMaskIntoConstraints = NO;
    self.addViewButton.titleLabel.font = [UIFont boldSystemFontOfSize:[UIFont labelFontSize] * 1.5];
    [self.addViewButton setTitle:@"+" forState:UIControlStateNormal];
    [self.addViewButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [self.addViewButton addTarget:self action:@selector(addNewLayerView:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.addViewButton];
    [self.addViewButton sizeToFit];

    // Right menu - properties, position
    self.rightMenu = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, VC_WIDTH / 4.0, VC_HEIGHT) style:UITableViewStylePlain];
    self.rightMenu.delegate = self;
    self.rightMenu.dataSource = self;
    self.rightMenu.alwaysBounceVertical = NO;
    self.rightMenu.layer.masksToBounds = NO;
    self.rightMenu.layer.shadowColor = [UIColor blackColor].CGColor;
    self.rightMenu.layer.shadowRadius = 0.5f;
    self.rightMenu.layer.shadowOffset = CGSizeMake(-1.0f, 0.0f);
    self.rightMenu.layer.shadowOpacity = 0.2f;
    self.rightMenu.backgroundColor = [UIColor whiteColor];
    self.rightMenu.translatesAutoresizingMaskIntoConstraints = NO;
    self.rightMenu.allowsSelection = NO;
    [self.view addSubview:self.rightMenu];

    // Register cell classes to represent different properties
    [self.rightMenu registerClass:[SliderTableViewCell class] forCellReuseIdentifier:kSliderCellIdentifier];
    [self.rightMenu registerClass:[StringTableViewCell class] forCellReuseIdentifier:kStringCellIdentifier];
    [self.rightMenu registerClass:[SwitchTableViewCell class] forCellReuseIdentifier:kSwitchCellIdentifier];
    [self.rightMenu registerClass:[PickerViewTableViewCell class] forCellReuseIdentifier:kPickerCellIdentifier];
    [self.rightMenu registerClass:[CGPointTableViewCell class] forCellReuseIdentifier:kCGPointCellIdentifier];
    [self.rightMenu registerClass:[CGRectTableViewCell class] forCellReuseIdentifier:kCGRectCellIdentifier];

    // Set up right menu toggle button
    self.toggleRightMenuButton = [UIButton new];
    self.toggleRightMenuButton.translatesAutoresizingMaskIntoConstraints = NO;
    self.toggleRightMenuButton.alpha = 0;
    [self.toggleRightMenuButton setTitle:@"\u276e" forState:UIControlStateNormal];
    [self.toggleRightMenuButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [self.toggleRightMenuButton addTarget:self action:@selector(toggleRightMenu) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.toggleRightMenuButton];
    [self.toggleRightMenuButton sizeToFit];

    // Constraints
    [_stage.topAnchor constraintEqualToAnchor:self.view.topAnchor].active = YES;
    [_stage.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor].active = YES;
    [_stage.leftAnchor constraintEqualToAnchor:self.view.leftAnchor].active = YES;
    [_stage.rightAnchor constraintEqualToAnchor:self.view.rightAnchor].active = YES;

    [self.leftMenu.topAnchor constraintEqualToAnchor:self.view.topAnchor].active = YES;
    [self.leftMenu.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor].active = YES;
    NSLayoutConstraint* widthConstraint = [self.leftMenu.widthAnchor constraintEqualToAnchor:self.view.widthAnchor multiplier:0.2];
    widthConstraint.priority = UILayoutPriorityDefaultLow;
    widthConstraint.active = YES;
    NSLayoutConstraint* minWidthConstraint = [self.leftMenu.widthAnchor constraintGreaterThanOrEqualToConstant:kMenuMinWidth];
    minWidthConstraint.priority = UILayoutPriorityDefaultHigh;
    minWidthConstraint.active = YES;

    _leftMenuLeftConstraint = [self.leftMenu.leftAnchor constraintEqualToAnchor:self.view.leftAnchor];
    _leftMenuLeftConstraint.active = YES;

    [self.toggleLeftMenuButton.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor constant:-kPadding].active = YES;
    [self.toggleLeftMenuButton.leftAnchor constraintEqualToAnchor:self.leftMenu.rightAnchor constant:kPadding].active = YES;

    [self.addViewButton.bottomAnchor constraintEqualToAnchor:self.toggleLeftMenuButton.topAnchor constant:-kPadding / 2.0].active = YES;
    [self.addViewButton.leftAnchor constraintEqualToAnchor:self.leftMenu.rightAnchor constant:kPadding].active = YES;

    [self.rightMenu.topAnchor constraintEqualToAnchor:self.view.topAnchor].active = YES;
    [self.rightMenu.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor].active = YES;
    NSLayoutConstraint* rightWidthConstraint = [self.rightMenu.widthAnchor constraintEqualToAnchor:self.view.widthAnchor multiplier:0.2];
    rightWidthConstraint.priority = UILayoutPriorityDefaultLow;
    rightWidthConstraint.active = YES;
    NSLayoutConstraint* rightMinWidthConstraint = [self.rightMenu.widthAnchor constraintGreaterThanOrEqualToConstant:kMenuMinWidth];
    rightMinWidthConstraint.priority = UILayoutPriorityDefaultHigh;
    rightMinWidthConstraint.active = YES;
    [self.rightMenu layoutIfNeeded];
    _rightMenuRightConstraint =
        [self.rightMenu.rightAnchor constraintEqualToAnchor:self.view.rightAnchor constant:self.rightMenu.frame.size.width];
    _rightMenuRightConstraint.active = YES;

    [self.toggleRightMenuButton.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor constant:-kPadding].active = YES;
    [self.toggleRightMenuButton.rightAnchor constraintEqualToAnchor:self.rightMenu.leftAnchor constant:-kPadding].active = YES;

    // Generate initial views
    [self generateLayerViews:kNumGeneratedViews andReset:NO];
}

#pragma mark View and layer management

// Adds a layer to the view specified in the sender's tag
- (void)addLayer:(UIButton*)sender {
    UIView* view = [_stage.subviews objectAtIndex:sender.tag];
    CALayer* prevLayer = (view.layer.sublayers.count > 0) ? [view.layer.sublayers lastObject] : view.layer;
    UIColor* prevColor = [UIColor colorWithCGColor:prevLayer.backgroundColor];

    CALayer* newLayer = [CALayer new];
    newLayer.backgroundColor = ((UIColor*)[_colors objectAtIndex:([_colors indexOfObject:prevColor] + 1) % _colors.count]).CGColor;
    newLayer.frame = CGRectMake(0, (view.layer.sublayers.count + 1) * kSublayerSpacing, kLayerViewSize, kLayerViewSize);
    [view.layer addSublayer:newLayer];

    [self.leftMenu reloadData];
}

// Convenience method - adds a new view to top of the stack
- (void)addNewLayerView:(UIButton*)sender {
    [self generateLayerViews:1 andReset:NO];
}

// Generates the specified number of views and arranges them in the center of the stage
- (void)generateLayerViews:(NSInteger)numberOfViews andReset:(BOOL)reset {
    if (reset) {
        // Clear screen
        for (UIView* view in _stage.subviews) {
            [view removeFromSuperview];
        }

        [_transformSettings removeAllObjects];
    }

    // Build new views
    int colorIdx = 0;
    for (int i = 0; i < numberOfViews; i++) {
        UIView* view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kLayerViewSize, kLayerViewSize)];
        view.layer.backgroundColor = ((UIColor*)[_colors objectAtIndex:(colorIdx % _colors.count)]).CGColor;
        colorIdx++;
        view.translatesAutoresizingMaskIntoConstraints = NO;
        [_stage addSubview:view];

        // Add sublayers
        for (int n = 0; n < kSublayersForNewViews; n++) {
            CALayer* newLayer = [CALayer new];
            newLayer.backgroundColor = ((UIColor*)[_colors objectAtIndex:(colorIdx % _colors.count)]).CGColor;
            colorIdx++;
            newLayer.frame = CGRectMake(0, (n + 1) * kSublayerSpacing, kLayerViewSize, kLayerViewSize);
            [view.layer addSublayer:newLayer];
        }

        // Origin is offset from center based on total number of views to generate
        CGFloat offset = (-(kLayerViewOverlap * kLayerViewSize * numberOfViews) / 2.0f) + (i * kLayerViewOverlap * kLayerViewSize) +
                         (kLayerViewOverlap * kLayerViewSize) / 2.0f;
        [view.widthAnchor constraintEqualToConstant:kLayerViewSize].active = YES;
        [view.heightAnchor constraintEqualToConstant:kLayerViewSize].active = YES;
        [view.centerYAnchor constraintEqualToAnchor:_stage.centerYAnchor constant:offset / 3.0].active = YES;
        [view.centerXAnchor constraintEqualToAnchor:_stage.centerXAnchor constant:offset].active = YES;

        // Set initial cache for transform mode, x, y and rotation
        [_transformSettings setObject:@(YES) forKey:[self identifierForView:view andProperty:UseAffine]];
        [_transformSettings setObject:@(offset) forKey:[self identifierForView:view andProperty:PositionX]];
        [_transformSettings setObject:@(offset / 3.0) forKey:[self identifierForView:view andProperty:PositionY]];
        [_transformSettings setObject:@(0) forKey:[self identifierForView:view andProperty:Rotation]];
        [_transformSettings setObject:@(1.0f) forKey:[self identifierForView:view andProperty:Scaling]];
    }

    [self.leftMenu reloadData];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView*)tableView {
    if (tableView == self.leftMenu) {
        return _stage.subviews.count;
    } else if (tableView == self.rightMenu) {
        return 2; // Layer properties, Transform settings
    }

    return 0;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    if (tableView == self.leftMenu) {
        return ((UIView*)[_stage.subviews objectAtIndex:section]).layer.sublayers.count + 1;
    } else if (tableView == self.rightMenu && _currentView) {
        switch (section) {
            case 0:
                return _exposedProperties.count; // Layer properties
                break;

            case 1:
                return 8; // Transform settings
                break;

            default:
                break;
        }
    }

    return 0;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    if (tableView == self.leftMenu) {
        return kLayerCellHeight;
    } else if (tableView == self.rightMenu) {
        return kPropertyCellHeight;
    }

    return 0;
}

- (CGFloat)tableView:(UITableView*)tableView heightForHeaderInSection:(NSInteger)section {
    if (tableView == self.leftMenu) {
        return kViewHeaderHeight;
    } else if (tableView == self.rightMenu) {
        return kPropertyHeaderHeight;
    }

    return 0;
}

- (CGFloat)tableView:(UITableView*)tableView heightForFooterInSection:(NSInteger)section {
    if (tableView == self.leftMenu) {
        return kLayerCellHeight;
    }

    return 0;
}

- (UIView*)tableView:(UITableView*)tableView viewForFooterInSection:(NSInteger)section {
    if (tableView == _leftMenu) {
        UIView* footerView = [[UIView alloc]
            initWithFrame:CGRectMake(0, 0, tableView.frame.size.width, [self tableView:tableView heightForFooterInSection:section])];
        footerView.backgroundColor = [UIColor whiteColor];

        UIButton* addLayerButton = [UIButton new];
        [addLayerButton setTitle:@"+ Add layer" forState:UIControlStateNormal];
        [addLayerButton setTitleColor:[UIColor lightGrayColor] forState:UIControlStateNormal];
        addLayerButton.tag = section;
        addLayerButton.titleLabel.font = [UIFont systemFontOfSize:[UIFont labelFontSize]];
        addLayerButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
        addLayerButton.translatesAutoresizingMaskIntoConstraints = NO;
        [addLayerButton addTarget:self action:@selector(addLayer:) forControlEvents:UIControlEventTouchUpInside];
        [footerView addSubview:addLayerButton];

        NSDictionary* metrics = @{ @"pad" : @(kPadding) };
        NSDictionary* views = NSDictionaryOfVariableBindings(addLayerButton);
        [footerView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[addLayerButton]-pad-|"
                                                                           options:0
                                                                           metrics:metrics
                                                                             views:views]];
        [footerView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-pad-[addLayerButton]-pad-|"
                                                                           options:0
                                                                           metrics:metrics
                                                                             views:views]];
        return footerView;
    }

    return [UIView new];
}

- (UIView*)tableView:(UITableView*)tableView viewForHeaderInSection:(NSInteger)section {
    if (tableView == _rightMenu) {
        UIView* headerView = [[UIView alloc]
            initWithFrame:CGRectMake(0, 0, tableView.frame.size.width, [self tableView:tableView heightForHeaderInSection:section])];
        headerView.backgroundColor = [UIColor whiteColor];
        headerView.layer.shadowColor = [UIColor blackColor].CGColor;
        headerView.layer.shadowRadius = 0.5f;
        headerView.layer.shadowOffset = CGSizeMake(0.0, 1.0f);
        headerView.layer.shadowOpacity = 0.2f;

        UILabel* titleLabel = [UILabel new];
        titleLabel.font = [UIFont boldSystemFontOfSize:[UIFont smallSystemFontSize]];
        titleLabel.textColor = [UIColor darkTextColor];
        titleLabel.text = [self tableView:tableView titleForHeaderInSection:section];
        titleLabel.translatesAutoresizingMaskIntoConstraints = NO;

        [headerView addSubview:titleLabel];

        NSDictionary* metrics = @{ @"pad" : @(kPadding), @"height" : @(titleLabel.font.lineHeight) };
        NSDictionary* views = NSDictionaryOfVariableBindings(titleLabel);
        [headerView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[titleLabel]-pad-|"
                                                                           options:0
                                                                           metrics:metrics
                                                                             views:views]];
        [headerView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-(>=0)-[titleLabel(height)]-pad-|"
                                                                           options:0
                                                                           metrics:metrics
                                                                             views:views]];
        return headerView;
    } else if (tableView == _leftMenu) {
        ViewHeaderFooterView* headerView = [tableView dequeueReusableHeaderFooterViewWithIdentifier:kViewHeaderViewIdentifier];
        [headerView setUpWithView:_stage.subviews[section] andTitle:[NSString stringWithFormat:@"View %lu", section]];
        return headerView;
    }

    return nil;
}

- (NSString*)tableView:(UITableView*)tableView titleForHeaderInSection:(NSInteger)section {
    if (tableView == self.rightMenu) {
        switch (section) {
            case 0:
                return @"Layer Properties";
                break;

            case 1:
                return @"Transform Settings";
                break;

            default:
                break;
        }
    }

    return nil;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    if (tableView == self.leftMenu) {
        LayerTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kLayerCellIdentifier forIndexPath:indexPath];
        cell.delegate = self;
        UIView* view = _stage.subviews[indexPath.section];
        if (indexPath.row == 0) {
            [cell setUpWithLayer:view.layer andTitle:@"Layer" shouldShowUpButton:NO shouldShowDownButton:NO];
        } else {
            CALayer* layer = view.layer.sublayers[indexPath.row - 1];
            [cell setUpWithLayer:layer
                            andTitle:[NSString stringWithFormat:@"\u2937 Sublayer %lu", indexPath.row - 1]
                  shouldShowUpButton:(indexPath.row == 1) ? NO : YES
                shouldShowDownButton:(view.layer.sublayers.lastObject == layer) ? NO : YES];
        }

        return cell;
    } else if (tableView == self.rightMenu) {
        // Property controls
        if (indexPath.section == 0) {
            // Opacity
            if (indexPath.row == OPACITY_POS) {
                SliderTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSliderCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kOpacityProperty
                           minValue:-1.0f
                           maxValue:2.0f
                       currentValue:(_currentLayer) ? _currentLayer.opacity : 1.0f
                             target:self
                             action:@selector(opacityChanged:)];
                return cell;

            }

            // Contents gravity
            else if (indexPath.row == CONTENTS_GRAVITY_POS) {
                PickerViewTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kPickerCellIdentifier forIndexPath:indexPath];
                [cell setUpWithName:kContentsGravityProperty
                            options:_contentsGravityOptionsArray
                       currentIndex:(_currentLayer) ? [_contentsGravityOptionsArray indexOfObject:_currentLayer.contentsGravity] : 0
                           delegate:self];
                return cell;

            }

            // Contents
            else if (indexPath.row == CONTENTS_POS) {
                PickerViewTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kPickerCellIdentifier forIndexPath:indexPath];
                [cell setUpWithName:kContentsProperty options:_images.allKeys currentIndex:0 delegate:self];
                return cell;
            }

            // Hidden
            else if (indexPath.row == HIDDEN_POS) {
                SwitchTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSwitchCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kHiddenProperty
                              value:(_currentLayer) ? _currentLayer.hidden : NO
                             target:self
                             action:@selector(hiddenChanged:)];
                return cell;
            }

            // Should rasterize
            else if (indexPath.row == SHOULD_RASTERIZE_POS) {
                SwitchTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSwitchCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kShouldRasterizeProperty
                              value:(_currentLayer) ? _currentLayer.shouldRasterize : NO
                             target:self
                             action:@selector(shouldRasterizeChanged:)];
                return cell;
            }

            // Rasterization scale
            else if (indexPath.row == RASTERIZATION_SCALE_POS) {
                SliderTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSliderCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kRasterizationScaleProperty
                           minValue:0.0f
                           maxValue:10.0f
                       currentValue:(_currentLayer) ? _currentLayer.rasterizationScale : 1.0f
                             target:self
                             action:@selector(rasterizationScaleChanged:)];
                return cell;

            }

            // Contents scale
            else if (indexPath.row == CONTENTS_SCALE_POS) {
                SliderTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSliderCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kContentsScaleProperty
                           minValue:0.0f
                           maxValue:10.0f
                       currentValue:(_currentLayer) ? _currentLayer.contentsScale : 1.0f
                             target:self
                             action:@selector(contentsScaleChanged:)];
                return cell;

            }

            // Double sided
            else if (indexPath.row == DOUBLE_SIDED_POS) {
                SwitchTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSwitchCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kDoubleSidedProperty
                              value:(_currentLayer) ? _currentLayer.doubleSided : NO
                             target:self
                             action:@selector(doubleSidedChanged:)];
                return cell;
            }

            // Corner radius
            else if (indexPath.row == CORNER_RADIUS_POS) {
                SliderTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSliderCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kCornerRadiusProperty
                           minValue:0.0f
                           maxValue:kLayerViewSize / 2.0f
                       currentValue:(_currentLayer) ? _currentLayer.cornerRadius : 0.0f
                             target:self
                             action:@selector(cornerRadiusChanged:)];
                return cell;

            }

            // Border width
            else if (indexPath.row == BORDER_WIDTH_POS) {
                SliderTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSliderCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kBorderWidthProperty
                           minValue:0.0f
                           maxValue:kLayerViewSize / 2.0f
                       currentValue:(_currentLayer) ? _currentLayer.borderWidth : 0.0f
                             target:self
                             action:@selector(borderWidthChanged:)];
                return cell;

            }

            // Masks to bounds
            else if (indexPath.row == MASKS_TO_BOUNDS_POS) {
                SwitchTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSwitchCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kMasksToBoundsProperty
                              value:(_currentLayer) ? _currentLayer.masksToBounds : NO
                             target:self
                             action:@selector(masksToBoundsChanged:)];
                return cell;
            }

            // Geometry flipped
            else if (indexPath.row == GEOMETRY_FLIPPED_POS) {
                SwitchTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kSwitchCellIdentifier forIndexPath:indexPath];
                [cell setUpWithText:kGeometryFlippedProperty
                              value:(_currentLayer) ? _currentLayer.geometryFlipped : NO
                             target:self
                             action:@selector(geometryFlippedChanged:)];
                return cell;
            }
        }

        // Transform settings
        else if (indexPath.section == 1) {
            // Bounds
            if (indexPath.row == 0) {
                CGRectTableViewCell* rectCell = [tableView dequeueReusableCellWithIdentifier:kCGRectCellIdentifier forIndexPath:indexPath];

                [rectCell setUpWithText:@"Bounds"
                           currentValue:_currentLayer.bounds
                                 target:self
                                actionX:@selector(boundsXChanged:)
                                actionY:@selector(boundsYChanged:)
                            actionWidth:@selector(boundsWidthChanged:)
                           actionHeight:@selector(boundsHeightChanged:)];
                return rectCell;
            }

            // Position
            else if (indexPath.row == 1) {
                CGPointTableViewCell* pointCell =
                    [tableView dequeueReusableCellWithIdentifier:kCGPointCellIdentifier forIndexPath:indexPath];

                [pointCell setUpWithText:@"Position"
                            currentValue:_currentLayer.position
                                  target:self
                                 actionX:@selector(positionXChanged:)
                                 actionY:@selector(positionYChanged:)];
                return pointCell;
            }

            // Anchor point
            else if (indexPath.row == 2) {
                CGPointTableViewCell* pointCell =
                    [tableView dequeueReusableCellWithIdentifier:kCGPointCellIdentifier forIndexPath:indexPath];

                [pointCell setUpWithText:@"Anchor point"
                            currentValue:_currentLayer.anchorPoint
                                  target:self
                                 actionX:@selector(anchorPointXChanged:)
                                 actionY:@selector(anchorPointYChanged:)];
                return pointCell;
            }

            // Transform mode - affine vs 3D
            else if (indexPath.row == 3) {
                SwitchTableViewCell* switchCell =
                    [tableView dequeueReusableCellWithIdentifier:kSwitchCellIdentifier forIndexPath:indexPath];

                NSString* viewIdentifier = [self identifierForView:_currentView andProperty:UseAffine];
                [switchCell setUpWithText:@"Affine transform"
                                    value:((NSNumber*)[_transformSettings objectForKey:viewIdentifier]).boolValue
                                   target:self
                                   action:@selector(transformModeChanged:)];
                return switchCell;
            }

            // Rotation
            else if (indexPath.row == 4) {
                SliderTableViewCell* sliderCell =
                    [tableView dequeueReusableCellWithIdentifier:kSliderCellIdentifier forIndexPath:indexPath];

                NSString* viewIdentifier = [self identifierForView:_currentView andProperty:Rotation];
                [sliderCell setUpWithText:@"Rotation"
                                 minValue:0
                                 maxValue:360
                             currentValue:((NSNumber*)[_transformSettings objectForKey:viewIdentifier]).floatValue
                                   target:self
                                   action:@selector(rotationChanged:)];
                return sliderCell;
            }

            // Scaling
            else if (indexPath.row == 5) {
                SliderTableViewCell* sliderCell =
                    [tableView dequeueReusableCellWithIdentifier:kSliderCellIdentifier forIndexPath:indexPath];

                NSString* viewIdentifier = [self identifierForView:_currentView andProperty:Scaling];
                [sliderCell setUpWithText:@"Scaling"
                                 minValue:0
                                 maxValue:3
                             currentValue:((NSNumber*)[_transformSettings objectForKey:viewIdentifier]).floatValue
                                   target:self
                                   action:@selector(scalingChanged:)];
                return sliderCell;
            }

            // X offset
            else if (indexPath.row == 6) {
                SliderTableViewCell* sliderCell =
                    [tableView dequeueReusableCellWithIdentifier:kSliderCellIdentifier forIndexPath:indexPath];

                NSString* viewIdentifier = [self identifierForView:_currentView andProperty:PositionX];
                [sliderCell setUpWithText:@"X offset"
                                 minValue:-VC_WIDTH / 2.0
                                 maxValue:VC_WIDTH / 2.0
                             currentValue:((NSNumber*)[_transformSettings objectForKey:viewIdentifier]).floatValue
                                   target:self
                                   action:@selector(xOffsetChanged:)];
                return sliderCell;
            }

            // Y offset
            else if (indexPath.row == 7) {
                SliderTableViewCell* sliderCell =
                    [tableView dequeueReusableCellWithIdentifier:kSliderCellIdentifier forIndexPath:indexPath];

                NSString* viewIdentifier = [self identifierForView:_currentView andProperty:PositionY];
                [sliderCell setUpWithText:@"Y offset"
                                 minValue:-VC_HEIGHT / 2.0
                                 maxValue:VC_HEIGHT / 2.0
                             currentValue:((NSNumber*)[_transformSettings objectForKey:viewIdentifier]).floatValue
                                   target:self
                                   action:@selector(yOffsetChanged:)];
                return sliderCell;
            }
        }
    }

    return nil;
}

#pragma mark - Layer table view cell delegate

- (void)cellWithLayer:(CALayer*)layer shouldMove:(MoveDirection)direction {
    CALayer* superLayer = layer.superlayer;
    int idx = (int)[superLayer.sublayers indexOfObject:layer];
    [layer removeFromSuperlayer];
    [superLayer insertSublayer:layer atIndex:(direction == MoveUp) ? idx - 1 : idx + 1];
    [self.leftMenu reloadData];
}

#pragma mark - View layer property control handlers

- (void)opacityChanged:(UISlider*)sender {
    // TODO: Would we useful to also display the properties value in the cells label (e.g. cell.textLabel.text == @"Opacity: " +
    // layer.opacity)
    _currentLayer.opacity = sender.value;
}

- (void)cornerRadiusChanged:(UISlider*)sender {
    _currentLayer.cornerRadius = sender.value;
}

- (void)borderWidthChanged:(UISlider*)sender {
    _currentLayer.borderWidth = sender.value;
}

- (void)hiddenChanged:(UISwitch*)sender {
    _currentLayer.hidden = sender.on;
}

- (void)masksToBoundsChanged:(UISwitch*)sender {
    _currentLayer.masksToBounds = sender.on;
}

- (void)geometryFlippedChanged:(UISwitch*)sender {
    _currentLayer.geometryFlipped = sender.on;
}

- (void)doubleSidedChanged:(UISwitch*)sender {
    _currentLayer.doubleSided = sender.on;
}

- (void)shouldRasterizeChanged:(UISwitch*)sender {
    _currentLayer.shouldRasterize = sender.on;
}

- (void)rasterizationScaleChanged:(UISlider*)sender {
    _currentLayer.rasterizationScale = sender.value;
}

- (void)contentsScaleChanged:(UISlider*)sender {
    _currentLayer.contentsScale = sender.value;
}

#pragma mark - Picker view cell delegate

- (void)pickerViewWithName:(NSString*)name didChangeToIndex:(NSInteger)idx {
    if ([name isEqualToString:kContentsGravityProperty]) {
        _currentLayer.contentsGravity = _contentsGravityOptionsArray[idx];
    }

    else if ([name isEqualToString:kContentsProperty]) {
        NSArray* keys = [_images allKeys];
        NSString* keyedSubscript = keys[idx];
        _currentLayer.contents = (__bridge id)((UIImage*)(_images[keyedSubscript])).CGImage;
    }
}

#pragma mark - Menu toggles

- (void)toggleLeftMenu {
    [self.view layoutIfNeeded];
    [UIView animateWithDuration:0.2
                          delay:0
                        options:UIViewAnimationOptionCurveEaseOut
                     animations:^(void) {
                         BOOL closing = (_leftMenuLeftConstraint.constant == 0);

                         [self.view removeConstraint:_leftMenuLeftConstraint];
                         _leftMenuLeftConstraint.constant = (closing) ? -self.leftMenu.frame.size.width : 0;
                         [self.view addConstraint:_leftMenuLeftConstraint];

                         [self.toggleLeftMenuButton setTitle:(closing) ? @"\u276f" : @"\u276e" forState:UIControlStateNormal];
                         [self.view layoutIfNeeded];
                     }
                     completion:nil];
}

- (void)toggleRightMenu {
    [self.view layoutIfNeeded];
    [UIView animateWithDuration:0.2
                          delay:0
                        options:UIViewAnimationOptionCurveEaseOut
                     animations:^(void) {
                         BOOL closing = (_rightMenuRightConstraint.constant == 0);

                         [self.view removeConstraint:_rightMenuRightConstraint];
                         _rightMenuRightConstraint.constant = (closing) ? self.rightMenu.frame.size.width : 0;
                         [self.view addConstraint:_rightMenuRightConstraint];

                         [self.toggleRightMenuButton setTitle:(closing) ? @"\u276e" : @"\u276f" forState:UIControlStateNormal];
                         [self.view layoutIfNeeded];
                     }
                     completion:nil];
}

- (void)openRightMenu {
    if (_rightMenuRightConstraint.constant != 0) {
        [self toggleRightMenu];
        self.toggleRightMenuButton.alpha = 1.0f;
    }
}

- (void)toggleRearrangingViews:(UIButton*)sender {
    if (self.leftMenu.isEditing) {
        self.addViewButton.enabled = YES;
        self.addViewButton.layer.opacity = 1.0;
        self.toggleLeftMenuButton.enabled = YES;
        self.toggleLeftMenuButton.layer.opacity = 1.0;
        [self.leftMenu setEditing:NO animated:NO];
        [sender setTitle:@"\u2630" forState:UIControlStateNormal];
    } else {
        self.addViewButton.enabled = NO;
        self.addViewButton.layer.opacity = 0.25;
        self.toggleLeftMenuButton.enabled = NO;
        self.toggleLeftMenuButton.layer.opacity = 0.25;
        [self.leftMenu setEditing:YES animated:YES];
        [sender setTitle:@"\u2713" forState:UIControlStateNormal];
    }
}

#pragma mark - Transform handlers

- (NSString*)identifierForView:(UIView*)view andProperty:(TransformProperty)property {
    return [NSString stringWithFormat:@"%lu_%ld", [view hash], property];
}

- (void)boundsXChanged:(UITextField*)textField {
    CGRect bounds = CGRectMake([textField.text floatValue],
                               _currentLayer.bounds.origin.y,
                               _currentLayer.bounds.size.width,
                               _currentLayer.bounds.size.height);
    _currentLayer.bounds = bounds;
}

- (void)boundsYChanged:(UITextField*)textField {
    CGRect bounds = CGRectMake(_currentLayer.bounds.origin.x,
                               [textField.text floatValue],
                               _currentLayer.bounds.size.width,
                               _currentLayer.bounds.size.height);
    _currentLayer.bounds = bounds;
}

- (void)boundsWidthChanged:(UITextField*)textField {
    CGRect bounds = CGRectMake(_currentLayer.bounds.origin.x,
                               _currentLayer.bounds.origin.y,
                               [textField.text floatValue],
                               _currentLayer.bounds.size.height);
    _currentLayer.bounds = bounds;
}

- (void)boundsHeightChanged:(UITextField*)textField {
    CGRect bounds = CGRectMake(_currentLayer.bounds.origin.x,
                               _currentLayer.bounds.origin.y,
                               _currentLayer.bounds.size.width,
                               [textField.text floatValue]);
    _currentLayer.bounds = bounds;
}

- (void)positionXChanged:(UITextField*)textField {
    CGPoint position = CGPointMake([textField.text floatValue], _currentLayer.position.y);
    _currentLayer.position = position;
}

- (void)positionYChanged:(UITextField*)textField {
    CGPoint position = CGPointMake(_currentLayer.position.x, [textField.text floatValue]);
    _currentLayer.position = position;
}

- (void)anchorPointXChanged:(UITextField*)textField {
    CGPoint newAnchorPoint = CGPointMake([textField.text floatValue], _currentLayer.anchorPoint.y);
    _currentLayer.anchorPoint = newAnchorPoint;
}

- (void)anchorPointYChanged:(UITextField*)textField {
    CGPoint newAnchorPoint = CGPointMake(_currentLayer.anchorPoint.x, [textField.text floatValue]);
    _currentLayer.anchorPoint = newAnchorPoint;
}

- (void)transformModeChanged:(UISwitch*)sender {
    // Cache sender value
    [_transformSettings setObject:@(sender.on) forKey:[self identifierForView:_currentView andProperty:UseAffine]];

    NSLog(@"transform matrix:\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f",
          _currentLayer.transform.m11,
          _currentLayer.transform.m12,
          _currentLayer.transform.m13,
          _currentLayer.transform.m14,
          _currentLayer.transform.m21,
          _currentLayer.transform.m22,
          _currentLayer.transform.m23,
          _currentLayer.transform.m24,
          _currentLayer.transform.m31,
          _currentLayer.transform.m32,
          _currentLayer.transform.m33,
          _currentLayer.transform.m34,
          _currentLayer.transform.m41,
          _currentLayer.transform.m42,
          _currentLayer.transform.m43,
          _currentLayer.transform.m44);

    NSLog(@"affine matrix:\n%f %f %f\n%f %f %f",
          _currentLayer.affineTransform.a,
          _currentLayer.affineTransform.b,
          _currentLayer.affineTransform.tx,
          _currentLayer.affineTransform.c,
          _currentLayer.affineTransform.d,
          _currentLayer.affineTransform.ty);
}

- (void)rotationChanged:(UISlider*)sender {
    // Only the delta from the previous cached value should be used in the translation
    NSString* viewIdentifier = [self identifierForView:_currentView andProperty:Rotation];
    CGFloat diffRotation = ((NSNumber*)[_transformSettings objectForKey:viewIdentifier]).floatValue - sender.value;

    // Cache sender value
    [_transformSettings setObject:@(sender.value) forKey:[self identifierForView:_currentView andProperty:Rotation]];

    // Toggle between affine (2D) or 3D rotation on the z-axis
    BOOL useAffine = ((NSNumber*)[_transformSettings objectForKey:[self identifierForView:_currentView andProperty:UseAffine]]).boolValue;
    if (useAffine) {
        _currentLayer.affineTransform = CGAffineTransformRotate(_currentLayer.affineTransform, diffRotation / 180.0f * M_PI);
    } else {
        _currentLayer.transform = CATransform3DRotate(_currentLayer.transform, diffRotation / 180.0f * M_PI, 0.0f, 0.0f, 1.0f);
    }
}

- (void)scalingChanged:(UISlider*)sender {
    // Cache sender value
    [_transformSettings setObject:@(sender.value) forKey:[self identifierForView:_currentView andProperty:Scaling]];

    // Toggle between affine (2D) or 3D rotation on the z-axis
    BOOL useAffine = ((NSNumber*)[_transformSettings objectForKey:[self identifierForView:_currentView andProperty:UseAffine]]).boolValue;
    if (useAffine) {
        _currentLayer.affineTransform = CGAffineTransformMakeScale(sender.value, sender.value);
    } else {
        _currentLayer.transform = CATransform3DMakeScale(sender.value, sender.value, 1.0f);
    }
}

- (void)xOffsetChanged:(UISlider*)sender {
    // Only the delta from the previous cached value should be used in the translation
    NSString* viewIdentifier = [self identifierForView:_currentView andProperty:PositionX];
    CGFloat diffX = ((NSNumber*)[_transformSettings objectForKey:viewIdentifier]).floatValue - sender.value;

    // Cache sender value
    [_transformSettings setObject:@(sender.value) forKey:[self identifierForView:_currentView andProperty:PositionX]];

    // Toggle between affine (2D) or 3D translation on the x-axis
    BOOL useAffine = ((NSNumber*)[_transformSettings objectForKey:[self identifierForView:_currentView andProperty:UseAffine]]).boolValue;
    if (useAffine) {
        _currentLayer.affineTransform = CGAffineTransformTranslate(_currentLayer.affineTransform, diffX, 0.0f);
    } else {
        _currentLayer.transform = CATransform3DTranslate(_currentLayer.transform, diffX, 0.0f, 0.0f);
    }
}

- (void)yOffsetChanged:(UISlider*)sender {
    // Only the delta from the previous cached value should be used in the translation
    NSString* viewIdentifier = [self identifierForView:_currentView andProperty:PositionY];
    CGFloat diffY = ((NSNumber*)[_transformSettings objectForKey:viewIdentifier]).floatValue - sender.value;

    // Cache sender value
    [_transformSettings setObject:@(sender.value) forKey:[self identifierForView:_currentView andProperty:PositionY]];

    // Toggle between affine (2D) or 3D translation on the y-axis
    BOOL useAffine = ((NSNumber*)[_transformSettings objectForKey:[self identifierForView:_currentView andProperty:UseAffine]]).boolValue;
    if (useAffine) {
        _currentLayer.affineTransform = CGAffineTransformTranslate(_currentLayer.affineTransform, 0.0f, diffY);
    } else {
        _currentLayer.transform = CATransform3DTranslate(_currentLayer.transform, 0.0f, diffY, 0.0f);
    }
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    if (tableView == _leftMenu) {
        _currentView = _stage.subviews[indexPath.section];
        _currentLayer = (indexPath.row == 0) ? _currentView.layer : _currentView.layer.sublayers[indexPath.row - 1];
        [self.rightMenu reloadData];
        [self openRightMenu];
    }
}

@end
