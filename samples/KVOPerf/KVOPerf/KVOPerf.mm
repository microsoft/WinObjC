#import <UIKit/UIKit.h>
#include <Windows.h>
#include <chrono>
#include <thread>

@class DataModelRoot, DataModelObjectA, DataModelObjectB;

@interface DataModelRoot : NSObject
@property (nonatomic, retain) DataModelObjectA* a;
@end

@interface DataModelObjectA : NSObject
@property (nonatomic, retain) DataModelObjectB* b;
@end

@interface DataModelObjectB : NSObject
@property (nonatomic, assign) double sliderValue;
@end

@implementation DataModelRoot
- (instancetype)init {
    if (self = [super init]) {
        _a = [DataModelObjectA new];
    }
    return self;
}
@end

@implementation DataModelObjectA
- (instancetype)init {
    if (self = [super init]) {
        _b = [DataModelObjectB new];
    }
    return self;
}
@end

@implementation DataModelObjectB
@end

@interface KVOKeyBinding : NSObject
+ (void)resetCounters;
+ (long)numberOfHits;
@property (nonatomic, retain) id source;
@property (nonatomic, retain) NSString* sourceKeyPath;
@property (nonatomic, retain) id destination;
@property (nonatomic, retain) NSString* destinationKeyPath;
@end

@implementation KVOKeyBinding
+ (instancetype)bindingWithSource:(id)source keyPath:(NSString*)sourceKeyPath destination:(id)destination keyPath:(NSString*)keyPath {
    return [[self alloc] initWithSource:source keyPath:sourceKeyPath destination:destination keyPath:keyPath];
}

- (instancetype)initWithSource:(id)source keyPath:(NSString*)sourceKeyPath destination:(id)destination keyPath:(NSString*)keyPath {
    if (self = [super init]) {
        _source = source;
        _sourceKeyPath = [sourceKeyPath copy];
        _destination = destination;
        _destinationKeyPath = [keyPath copy];

        [source addObserver:self
                 forKeyPath:_sourceKeyPath
                    options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionInitial
                    context:NULL];
    }
    return self;
}

static long _numberOfHits = 0;
+ (void)resetCounters {
    InterlockedAnd(&_numberOfHits, 0);
}

+ (long)numberOfHits {
    return _numberOfHits;
}

- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(NSObject*)object change:(NSDictionary*)change context:(void*)context {
    InterlockedIncrement(&_numberOfHits);
    if (object == _source && [keyPath isEqualToString:_sourceKeyPath]) {
        [_destination setValue:[change objectForKey:NSKeyValueChangeNewKey] forKeyPath:_destinationKeyPath];
    }
}

- (void)remove {
    [_source removeObserver:self forKeyPath:_sourceKeyPath];
}
@end

@interface KVOPerfViewController : UIViewController {
    DataModelRoot* _root1;
    DataModelRoot* _root2;

    NSMutableArray<KVOKeyBinding*>* _keyBindings;

    UILabel* _label; // output 1
    UIProgressView* _progressView; // output 2

    UIButton* _startButton;
    UITextField* _threadsField;
    UITextField* _lengthField;
    UITextField* _delayField;
    UITextView* _outputTextView;
    unsigned int _nfields;
}
@property (nonatomic, assign) double value;
@end

@implementation KVOPerfViewController
- (id)initWithNibName:(NSString*)nibName bundle:(NSBundle*)bundle {
    if (self = [super initWithNibName:nibName bundle:bundle]) {
        _root1 = [DataModelRoot new];
        _root2 = [DataModelRoot new];

        _keyBindings = [NSMutableArray new];
    }
    return self;
}

#define LEFT_PADDING 4.0
#define ROW_HEIGHT 44.0
#define ROW_PADDING 4.0

- (UITextField*)_addTextFieldWithTitle:(NSString*)title defaultValue:(NSString*)value {
    UILabel* label = [[UILabel alloc] initWithFrame:(CGRect){ LEFT_PADDING, (ROW_HEIGHT + ROW_PADDING) * _nfields, 128, ROW_HEIGHT }];
    label.text = title;
    label.textAlignment = NSTextAlignmentRight;
    UITextField* field =
        [[UITextField alloc] initWithFrame:(CGRect){ 128 + (2 * LEFT_PADDING), (ROW_HEIGHT + ROW_PADDING) * _nfields, 128, ROW_HEIGHT }];
    field.text = value;
    [self.view addSubview:label];
    [self.view addSubview:field];
    ++_nfields;
    return field;
}

- (void)viewDidLoad {
    _threadsField = [self _addTextFieldWithTitle:@"#threads" defaultValue:@"1"];
    _lengthField = [self _addTextFieldWithTitle:@"length (sec)" defaultValue:@"10"];
    _delayField = [self _addTextFieldWithTitle:@"delay (sec)" defaultValue:@"0"];

    _startButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [_startButton setTitle:@"Start" forState:UIControlStateNormal];
    _startButton.frame = (CGRect){ LEFT_PADDING, (ROW_HEIGHT + ROW_PADDING) * _nfields, (128 * 2) + LEFT_PADDING, ROW_HEIGHT };
    [_startButton addTarget:self action:@selector(_startTestButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    ++_nfields;
    [self.view addSubview:_startButton];

    _outputTextView = [[UITextView alloc]
        initWithFrame:(CGRect){ LEFT_PADDING, (ROW_HEIGHT + ROW_PADDING) * _nfields, (128 * 2) + LEFT_PADDING, 5 * ROW_HEIGHT }];
    _outputTextView.text = @"no test run";
    _outputTextView.userInteractionEnabled = NO;
    _outputTextView.font = [UIFont systemFontOfSize:10.];
    [self.view addSubview:_outputTextView];
    _nfields += 5;

    /*
    _label = [[UILabel alloc] initWithFrame:(CGRect){0, (44+2)*2, 512, 44}];
    _progressView = [[UIProgressView alloc] initWithFrame:(CGRect){0, (44+2)*3, 512, 44}];

    [self.view addSubview:_label];
    [self.view addSubview:_progressView];*/
}

- (void)viewDidAppear:(BOOL)animated {
    //[self beginTestWithStartDelay:1 length:10 numberOfThreads:0];
    //[self beginTestWithStartDelay:1 length:10 numberOfThreads:1];
}

- (void)_clear {
    void (^block)() = ^{
        @synchronized(self) {
            _outputTextView.text = @"";
        }
    };
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

- (void)_printOutput:(NSString*)format, ... {
    va_list ap;
    va_start(ap, format);
    NSString* newString = [[NSString alloc] initWithFormat:format arguments:ap];
    void (^block)() = ^{
        @synchronized(self) {
            _outputTextView.text = [_outputTextView.text stringByAppendingString:newString];
        }
    };
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
    va_end(ap);
}

- (void)_constructObservationModel {
    [_keyBindings makeObjectsPerformSelector:@selector(remove)];
    [_keyBindings removeAllObjects];
    // Added inside-out because bindings fire initial observation changes.
    //[self addBinding:[KVOKeyBinding bindingWithSource:_root2 keyPath:@"a.b.sliderValue" destination:_label keyPath:@"text"]];
    //[self addBinding:[KVOKeyBinding bindingWithSource:_root2 keyPath:@"a.b.sliderValue" destination:_progressView keyPath:@"progress"]];
    //[self addBinding:[KVOKeyBinding bindingWithSource:self keyPath:@"value" destination:_slider keyPath:@"value"]];

    [self addBinding:[KVOKeyBinding bindingWithSource:_root1 keyPath:@"a.b.sliderValue" destination:_root2 keyPath:@"a.b.sliderValue"]];
    [self addBinding:[KVOKeyBinding bindingWithSource:self keyPath:@"value" destination:_root1 keyPath:@"a.b.sliderValue"]];
}

- (void)_startTestButtonClicked:(id)sender {
    _startButton.enabled = NO;

    [self _clear];
    [self _printOutput:@"-- test running --"];

    NSInteger numberOfThreads = [_threadsField text].integerValue;
    NSInteger testLength = [_lengthField text].integerValue;
    NSInteger startDelay = [_delayField text].integerValue;

    [self _constructObservationModel];

    [self beginTestWithStartDelay:startDelay
                           length:testLength
                  numberOfThreads:numberOfThreads
                  completionBlock:^(long setterCalls, int kvoNotifications) {
                      [self _clear];
                      [self _printOutput:@"%lu KVO notifications; %lu setter calls\n", kvoNotifications, setterCalls];
                      if (setterCalls > 0) {
                          [self _printOutput:@"%lu notifications per setter call\n", kvoNotifications / setterCalls];
                          [self _printOutput:@"avg. setter call length: %f μs\n", ((double)(testLength)*1000000) / (double)(setterCalls)];
                      }
                      if (kvoNotifications > 0) {
                          [self _printOutput:@"avg. kvo notification length: %f μs\n",
                                             ((double)(testLength)*1000000) / (double)(kvoNotifications)];
                      }
                      _startButton.enabled = YES;
                  }];
}

- (void)beginTestWithStartDelay:(NSTimeInterval)startDelay
                         length:(NSTimeInterval)testLength
                numberOfThreads:(NSUInteger)numberOfThreads
                completionBlock:(void (^)(long setterCalls, int kvoNotifications))completionBlock {
    __block long setterCalls = 0;
    dispatch_group_t execGroup = dispatch_group_create();
    [KVOKeyBinding resetCounters];
    void (^setterBlock)(double value) = ^(double value) {
        self.value = value;
    };
    void (^offThreadPerfBlock)() = ^{
        std::this_thread::sleep_for(std::chrono::seconds((int)startDelay));
        auto now = std::chrono::high_resolution_clock::now();
        double value = 0.0;
        while (std::chrono::high_resolution_clock::now() - now < std::chrono::seconds((int)testLength)) {
            value += .0001;
            InterlockedIncrementNoFence(&setterCalls);
            dispatch_sync(dispatch_get_main_queue(), ^{
                setterBlock(value);
            });
        }
    };
    void (^onThreadPerfBlock)() = ^{
        std::this_thread::sleep_for(std::chrono::seconds((int)startDelay));
        auto now = std::chrono::high_resolution_clock::now();
        double value = 0.0;
        while (std::chrono::high_resolution_clock::now() - now < std::chrono::seconds((int)testLength)) {
            value += .0001;
            InterlockedIncrementNoFence(&setterCalls);
            setterBlock(value);
        }
    };
    if (numberOfThreads > 0) {
        for (int i = 0; i < numberOfThreads; ++i) {
            dispatch_group_async(execGroup, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), offThreadPerfBlock);
        }
    } else {
        dispatch_group_async(execGroup, dispatch_get_main_queue(), onThreadPerfBlock);
    }
    dispatch_group_notify(execGroup, dispatch_get_main_queue(), ^{
        completionBlock(setterCalls, [KVOKeyBinding numberOfHits]);
    });
}

- (void)addBinding:(KVOKeyBinding*)binding {
    [_keyBindings addObject:binding];
}
@end

@interface KVOPerfApp : NSObject {
    UIWindow* _mainWindow;
}
@end

@implementation KVOPerfApp
- (void)applicationDidFinishLaunching:(UIApplication*)app {
    _mainWindow = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    _mainWindow.rootViewController = [[KVOPerfViewController alloc] initWithNibName:nil bundle:nil];
    [_mainWindow makeKeyAndVisible];
}
@end

#ifdef WINOBJC
// Tell the WinObjC runtime how large to render the application
@implementation UIApplication (UIApplicationInitialStartupMode)
+ (void)setStartupDisplayMode:(WOCDisplayMode*)mode {
    mode.autoMagnification = TRUE;
    mode.sizeUIWindowToFit = TRUE;
    mode.fixedWidth = 0;
    mode.fixedHeight = 0;
    mode.magnification = 1.0;
}
@end
#endif
