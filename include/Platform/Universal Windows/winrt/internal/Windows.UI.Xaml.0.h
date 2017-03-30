// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml {

struct CornerRadius;
struct Duration;
struct Thickness;
struct GridLength;

}

namespace Windows::UI::Xaml {

using CornerRadius = ABI::Windows::UI::Xaml::CornerRadius;
using Duration = ABI::Windows::UI::Xaml::Duration;
using Thickness = ABI::Windows::UI::Xaml::Thickness;
using GridLength = ABI::Windows::UI::Xaml::GridLength;

}

namespace ABI::Windows::UI::Xaml {

struct ApplicationInitializationCallback;
struct BindingFailedEventHandler;
struct CreateDefaultValueCallback;
struct DependencyPropertyChangedCallback;
struct DependencyPropertyChangedEventHandler;
struct DragEventHandler;
struct EnteredBackgroundEventHandler;
struct ExceptionRoutedEventHandler;
struct IAdaptiveTrigger;
struct IAdaptiveTriggerFactory;
struct IAdaptiveTriggerStatics;
struct IApplication;
struct IApplication2;
struct IApplicationFactory;
struct IApplicationInitializationCallbackParams;
struct IApplicationOverrides;
struct IApplicationOverrides2;
struct IApplicationStatics;
struct IBindingFailedEventArgs;
struct ICornerRadiusHelper;
struct ICornerRadiusHelperStatics;
struct IDataContextChangedEventArgs;
struct IDataTemplate;
struct IDataTemplateExtension;
struct IDataTemplateFactory;
struct IDataTemplateKey;
struct IDataTemplateKeyFactory;
struct IDataTemplateStatics2;
struct IDebugSettings;
struct IDebugSettings2;
struct IDebugSettings3;
struct IDependencyObject;
struct IDependencyObject2;
struct IDependencyObjectCollectionFactory;
struct IDependencyObjectFactory;
struct IDependencyProperty;
struct IDependencyPropertyChangedEventArgs;
struct IDependencyPropertyStatics;
struct IDispatcherTimer;
struct IDispatcherTimerFactory;
struct IDragEventArgs;
struct IDragEventArgs2;
struct IDragEventArgs3;
struct IDragOperationDeferral;
struct IDragStartingEventArgs;
struct IDragStartingEventArgs2;
struct IDragUI;
struct IDragUIOverride;
struct IDropCompletedEventArgs;
struct IDurationHelper;
struct IDurationHelperStatics;
struct IElementSoundPlayer;
struct IElementSoundPlayerStatics;
struct IEventTrigger;
struct IExceptionRoutedEventArgs;
struct IExceptionRoutedEventArgsFactory;
struct IFrameworkElement;
struct IFrameworkElement2;
struct IFrameworkElement3;
struct IFrameworkElement4;
struct IFrameworkElementFactory;
struct IFrameworkElementOverrides;
struct IFrameworkElementOverrides2;
struct IFrameworkElementStatics;
struct IFrameworkElementStatics2;
struct IFrameworkElementStatics4;
struct IFrameworkTemplate;
struct IFrameworkTemplateFactory;
struct IFrameworkView;
struct IFrameworkViewSource;
struct IGridLengthHelper;
struct IGridLengthHelperStatics;
struct IMediaFailedRoutedEventArgs;
struct IPointHelper;
struct IPointHelperStatics;
struct IPropertyMetadata;
struct IPropertyMetadataFactory;
struct IPropertyMetadataStatics;
struct IPropertyPath;
struct IPropertyPathFactory;
struct IRectHelper;
struct IRectHelperStatics;
struct IResourceDictionary;
struct IResourceDictionaryFactory;
struct IRoutedEvent;
struct IRoutedEventArgs;
struct IRoutedEventArgsFactory;
struct ISetter;
struct ISetter2;
struct ISetterBase;
struct ISetterBaseCollection;
struct ISetterBaseFactory;
struct ISetterFactory;
struct ISizeChangedEventArgs;
struct ISizeHelper;
struct ISizeHelperStatics;
struct IStateTrigger;
struct IStateTriggerBase;
struct IStateTriggerBaseFactory;
struct IStateTriggerBaseProtected;
struct IStateTriggerStatics;
struct IStyle;
struct IStyleFactory;
struct ITargetPropertyPath;
struct ITargetPropertyPathFactory;
struct IThicknessHelper;
struct IThicknessHelperStatics;
struct ITriggerAction;
struct ITriggerActionFactory;
struct ITriggerBase;
struct ITriggerBaseFactory;
struct IUIElement;
struct IUIElement2;
struct IUIElement3;
struct IUIElement4;
struct IUIElementFactory;
struct IUIElementOverrides;
struct IUIElementStatics;
struct IUIElementStatics2;
struct IUIElementStatics3;
struct IUIElementStatics4;
struct IUnhandledExceptionEventArgs;
struct IVisualState;
struct IVisualState2;
struct IVisualStateChangedEventArgs;
struct IVisualStateGroup;
struct IVisualStateManager;
struct IVisualStateManagerFactory;
struct IVisualStateManagerOverrides;
struct IVisualStateManagerProtected;
struct IVisualStateManagerStatics;
struct IVisualTransition;
struct IVisualTransitionFactory;
struct IWindow;
struct IWindow2;
struct IWindowCreatedEventArgs;
struct IWindowStatics;
struct LeavingBackgroundEventHandler;
struct PropertyChangedCallback;
struct RoutedEventHandler;
struct SizeChangedEventHandler;
struct SuspendingEventHandler;
struct UnhandledExceptionEventHandler;
struct VisualStateChangedEventHandler;
struct WindowActivatedEventHandler;
struct WindowClosedEventHandler;
struct WindowSizeChangedEventHandler;
struct WindowVisibilityChangedEventHandler;
struct AdaptiveTrigger;
struct Application;
struct ApplicationInitializationCallbackParams;
struct BindingFailedEventArgs;
struct CornerRadiusHelper;
struct DataContextChangedEventArgs;
struct DataTemplate;
struct DataTemplateKey;
struct DebugSettings;
struct DependencyObject;
struct DependencyObjectCollection;
struct DependencyProperty;
struct DependencyPropertyChangedEventArgs;
struct DispatcherTimer;
struct DragEventArgs;
struct DragOperationDeferral;
struct DragStartingEventArgs;
struct DragUI;
struct DragUIOverride;
struct DropCompletedEventArgs;
struct DurationHelper;
struct ElementSoundPlayer;
struct EventTrigger;
struct ExceptionRoutedEventArgs;
struct FrameworkElement;
struct FrameworkTemplate;
struct FrameworkView;
struct FrameworkViewSource;
struct GridLengthHelper;
struct MediaFailedRoutedEventArgs;
struct PointHelper;
struct PropertyMetadata;
struct PropertyPath;
struct RectHelper;
struct ResourceDictionary;
struct RoutedEvent;
struct RoutedEventArgs;
struct Setter;
struct SetterBase;
struct SetterBaseCollection;
struct SizeChangedEventArgs;
struct SizeHelper;
struct StateTrigger;
struct StateTriggerBase;
struct Style;
struct TargetPropertyPath;
struct ThicknessHelper;
struct TriggerAction;
struct TriggerActionCollection;
struct TriggerBase;
struct TriggerCollection;
struct UIElement;
struct UnhandledExceptionEventArgs;
struct VisualState;
struct VisualStateChangedEventArgs;
struct VisualStateGroup;
struct VisualStateManager;
struct VisualTransition;
struct Window;
struct WindowCreatedEventArgs;

}

namespace Windows::UI::Xaml {

struct ApplicationInitializationCallback;
struct BindingFailedEventHandler;
struct CreateDefaultValueCallback;
struct DependencyPropertyChangedCallback;
struct DependencyPropertyChangedEventHandler;
struct DragEventHandler;
struct EnteredBackgroundEventHandler;
struct ExceptionRoutedEventHandler;
struct LeavingBackgroundEventHandler;
struct PropertyChangedCallback;
struct RoutedEventHandler;
struct SizeChangedEventHandler;
struct SuspendingEventHandler;
struct UnhandledExceptionEventHandler;
struct VisualStateChangedEventHandler;
struct WindowActivatedEventHandler;
struct WindowClosedEventHandler;
struct WindowSizeChangedEventHandler;
struct WindowVisibilityChangedEventHandler;
struct IAdaptiveTrigger;
struct IAdaptiveTriggerFactory;
struct IAdaptiveTriggerStatics;
struct IApplication;
struct IApplication2;
struct IApplicationFactory;
struct IApplicationInitializationCallbackParams;
struct IApplicationOverrides;
struct IApplicationOverrides2;
struct IApplicationStatics;
struct IBindingFailedEventArgs;
struct ICornerRadiusHelper;
struct ICornerRadiusHelperStatics;
struct IDataContextChangedEventArgs;
struct IDataTemplate;
struct IDataTemplateExtension;
struct IDataTemplateFactory;
struct IDataTemplateKey;
struct IDataTemplateKeyFactory;
struct IDataTemplateStatics2;
struct IDebugSettings;
struct IDebugSettings2;
struct IDebugSettings3;
struct IDependencyObject;
struct IDependencyObject2;
struct IDependencyObjectCollectionFactory;
struct IDependencyObjectFactory;
struct IDependencyProperty;
struct IDependencyPropertyChangedEventArgs;
struct IDependencyPropertyStatics;
struct IDispatcherTimer;
struct IDispatcherTimerFactory;
struct IDragEventArgs;
struct IDragEventArgs2;
struct IDragEventArgs3;
struct IDragOperationDeferral;
struct IDragStartingEventArgs;
struct IDragStartingEventArgs2;
struct IDragUI;
struct IDragUIOverride;
struct IDropCompletedEventArgs;
struct IDurationHelper;
struct IDurationHelperStatics;
struct IElementSoundPlayer;
struct IElementSoundPlayerStatics;
struct IEventTrigger;
struct IExceptionRoutedEventArgs;
struct IExceptionRoutedEventArgsFactory;
struct IFrameworkElement;
struct IFrameworkElement2;
struct IFrameworkElement3;
struct IFrameworkElement4;
struct IFrameworkElementFactory;
struct IFrameworkElementOverrides;
struct IFrameworkElementOverrides2;
struct IFrameworkElementStatics;
struct IFrameworkElementStatics2;
struct IFrameworkElementStatics4;
struct IFrameworkTemplate;
struct IFrameworkTemplateFactory;
struct IFrameworkView;
struct IFrameworkViewSource;
struct IGridLengthHelper;
struct IGridLengthHelperStatics;
struct IMediaFailedRoutedEventArgs;
struct IPointHelper;
struct IPointHelperStatics;
struct IPropertyMetadata;
struct IPropertyMetadataFactory;
struct IPropertyMetadataStatics;
struct IPropertyPath;
struct IPropertyPathFactory;
struct IRectHelper;
struct IRectHelperStatics;
struct IResourceDictionary;
struct IResourceDictionaryFactory;
struct IRoutedEvent;
struct IRoutedEventArgs;
struct IRoutedEventArgsFactory;
struct ISetter;
struct ISetter2;
struct ISetterBase;
struct ISetterBaseCollection;
struct ISetterBaseFactory;
struct ISetterFactory;
struct ISizeChangedEventArgs;
struct ISizeHelper;
struct ISizeHelperStatics;
struct IStateTrigger;
struct IStateTriggerBase;
struct IStateTriggerBaseFactory;
struct IStateTriggerBaseProtected;
struct IStateTriggerStatics;
struct IStyle;
struct IStyleFactory;
struct ITargetPropertyPath;
struct ITargetPropertyPathFactory;
struct IThicknessHelper;
struct IThicknessHelperStatics;
struct ITriggerAction;
struct ITriggerActionFactory;
struct ITriggerBase;
struct ITriggerBaseFactory;
struct IUIElement;
struct IUIElement2;
struct IUIElement3;
struct IUIElement4;
struct IUIElementFactory;
struct IUIElementOverrides;
struct IUIElementStatics;
struct IUIElementStatics2;
struct IUIElementStatics3;
struct IUIElementStatics4;
struct IUnhandledExceptionEventArgs;
struct IVisualState;
struct IVisualState2;
struct IVisualStateChangedEventArgs;
struct IVisualStateGroup;
struct IVisualStateManager;
struct IVisualStateManagerFactory;
struct IVisualStateManagerOverrides;
struct IVisualStateManagerProtected;
struct IVisualStateManagerStatics;
struct IVisualTransition;
struct IVisualTransitionFactory;
struct IWindow;
struct IWindow2;
struct IWindowCreatedEventArgs;
struct IWindowStatics;
struct AdaptiveTrigger;
struct Application;
struct ApplicationInitializationCallbackParams;
struct BindingFailedEventArgs;
struct CornerRadiusHelper;
struct DataContextChangedEventArgs;
struct DataTemplate;
struct DataTemplateKey;
struct DebugSettings;
struct DependencyObject;
struct DependencyObjectCollection;
struct DependencyProperty;
struct DependencyPropertyChangedEventArgs;
struct DispatcherTimer;
struct DragEventArgs;
struct DragOperationDeferral;
struct DragStartingEventArgs;
struct DragUI;
struct DragUIOverride;
struct DropCompletedEventArgs;
struct DurationHelper;
struct ElementSoundPlayer;
struct EventTrigger;
struct ExceptionRoutedEventArgs;
struct FrameworkElement;
struct FrameworkTemplate;
struct FrameworkView;
struct FrameworkViewSource;
struct GridLengthHelper;
struct MediaFailedRoutedEventArgs;
struct PointHelper;
struct PropertyMetadata;
struct PropertyPath;
struct RectHelper;
struct ResourceDictionary;
struct RoutedEvent;
struct RoutedEventArgs;
struct Setter;
struct SetterBase;
struct SetterBaseCollection;
struct SizeChangedEventArgs;
struct SizeHelper;
struct StateTrigger;
struct StateTriggerBase;
struct Style;
struct TargetPropertyPath;
struct ThicknessHelper;
struct TriggerAction;
struct TriggerActionCollection;
struct TriggerBase;
struct TriggerCollection;
struct UIElement;
struct UnhandledExceptionEventArgs;
struct VisualState;
struct VisualStateChangedEventArgs;
struct VisualStateGroup;
struct VisualStateManager;
struct VisualTransition;
struct Window;
struct WindowCreatedEventArgs;

}

namespace Windows::UI::Xaml {

template <typename T> struct impl_IAdaptiveTrigger;
template <typename T> struct impl_IAdaptiveTriggerFactory;
template <typename T> struct impl_IAdaptiveTriggerStatics;
template <typename T> struct impl_IApplication;
template <typename T> struct impl_IApplication2;
template <typename T> struct impl_IApplicationFactory;
template <typename T> struct impl_IApplicationInitializationCallbackParams;
template <typename T> struct impl_IApplicationOverrides;
template <typename T> struct impl_IApplicationOverrides2;
template <typename T> struct impl_IApplicationStatics;
template <typename T> struct impl_IBindingFailedEventArgs;
template <typename T> struct impl_ICornerRadiusHelper;
template <typename T> struct impl_ICornerRadiusHelperStatics;
template <typename T> struct impl_IDataContextChangedEventArgs;
template <typename T> struct impl_IDataTemplate;
template <typename T> struct impl_IDataTemplateExtension;
template <typename T> struct impl_IDataTemplateFactory;
template <typename T> struct impl_IDataTemplateKey;
template <typename T> struct impl_IDataTemplateKeyFactory;
template <typename T> struct impl_IDataTemplateStatics2;
template <typename T> struct impl_IDebugSettings;
template <typename T> struct impl_IDebugSettings2;
template <typename T> struct impl_IDebugSettings3;
template <typename T> struct impl_IDependencyObject;
template <typename T> struct impl_IDependencyObject2;
template <typename T> struct impl_IDependencyObjectCollectionFactory;
template <typename T> struct impl_IDependencyObjectFactory;
template <typename T> struct impl_IDependencyProperty;
template <typename T> struct impl_IDependencyPropertyChangedEventArgs;
template <typename T> struct impl_IDependencyPropertyStatics;
template <typename T> struct impl_IDispatcherTimer;
template <typename T> struct impl_IDispatcherTimerFactory;
template <typename T> struct impl_IDragEventArgs;
template <typename T> struct impl_IDragEventArgs2;
template <typename T> struct impl_IDragEventArgs3;
template <typename T> struct impl_IDragOperationDeferral;
template <typename T> struct impl_IDragStartingEventArgs;
template <typename T> struct impl_IDragStartingEventArgs2;
template <typename T> struct impl_IDragUI;
template <typename T> struct impl_IDragUIOverride;
template <typename T> struct impl_IDropCompletedEventArgs;
template <typename T> struct impl_IDurationHelper;
template <typename T> struct impl_IDurationHelperStatics;
template <typename T> struct impl_IElementSoundPlayer;
template <typename T> struct impl_IElementSoundPlayerStatics;
template <typename T> struct impl_IEventTrigger;
template <typename T> struct impl_IExceptionRoutedEventArgs;
template <typename T> struct impl_IExceptionRoutedEventArgsFactory;
template <typename T> struct impl_IFrameworkElement;
template <typename T> struct impl_IFrameworkElement2;
template <typename T> struct impl_IFrameworkElement3;
template <typename T> struct impl_IFrameworkElement4;
template <typename T> struct impl_IFrameworkElementFactory;
template <typename T> struct impl_IFrameworkElementOverrides;
template <typename T> struct impl_IFrameworkElementOverrides2;
template <typename T> struct impl_IFrameworkElementStatics;
template <typename T> struct impl_IFrameworkElementStatics2;
template <typename T> struct impl_IFrameworkElementStatics4;
template <typename T> struct impl_IFrameworkTemplate;
template <typename T> struct impl_IFrameworkTemplateFactory;
template <typename T> struct impl_IFrameworkView;
template <typename T> struct impl_IFrameworkViewSource;
template <typename T> struct impl_IGridLengthHelper;
template <typename T> struct impl_IGridLengthHelperStatics;
template <typename T> struct impl_IMediaFailedRoutedEventArgs;
template <typename T> struct impl_IPointHelper;
template <typename T> struct impl_IPointHelperStatics;
template <typename T> struct impl_IPropertyMetadata;
template <typename T> struct impl_IPropertyMetadataFactory;
template <typename T> struct impl_IPropertyMetadataStatics;
template <typename T> struct impl_IPropertyPath;
template <typename T> struct impl_IPropertyPathFactory;
template <typename T> struct impl_IRectHelper;
template <typename T> struct impl_IRectHelperStatics;
template <typename T> struct impl_IResourceDictionary;
template <typename T> struct impl_IResourceDictionaryFactory;
template <typename T> struct impl_IRoutedEvent;
template <typename T> struct impl_IRoutedEventArgs;
template <typename T> struct impl_IRoutedEventArgsFactory;
template <typename T> struct impl_ISetter;
template <typename T> struct impl_ISetter2;
template <typename T> struct impl_ISetterBase;
template <typename T> struct impl_ISetterBaseCollection;
template <typename T> struct impl_ISetterBaseFactory;
template <typename T> struct impl_ISetterFactory;
template <typename T> struct impl_ISizeChangedEventArgs;
template <typename T> struct impl_ISizeHelper;
template <typename T> struct impl_ISizeHelperStatics;
template <typename T> struct impl_IStateTrigger;
template <typename T> struct impl_IStateTriggerBase;
template <typename T> struct impl_IStateTriggerBaseFactory;
template <typename T> struct impl_IStateTriggerBaseProtected;
template <typename T> struct impl_IStateTriggerStatics;
template <typename T> struct impl_IStyle;
template <typename T> struct impl_IStyleFactory;
template <typename T> struct impl_ITargetPropertyPath;
template <typename T> struct impl_ITargetPropertyPathFactory;
template <typename T> struct impl_IThicknessHelper;
template <typename T> struct impl_IThicknessHelperStatics;
template <typename T> struct impl_ITriggerAction;
template <typename T> struct impl_ITriggerActionFactory;
template <typename T> struct impl_ITriggerBase;
template <typename T> struct impl_ITriggerBaseFactory;
template <typename T> struct impl_IUIElement;
template <typename T> struct impl_IUIElement2;
template <typename T> struct impl_IUIElement3;
template <typename T> struct impl_IUIElement4;
template <typename T> struct impl_IUIElementFactory;
template <typename T> struct impl_IUIElementOverrides;
template <typename T> struct impl_IUIElementStatics;
template <typename T> struct impl_IUIElementStatics2;
template <typename T> struct impl_IUIElementStatics3;
template <typename T> struct impl_IUIElementStatics4;
template <typename T> struct impl_IUnhandledExceptionEventArgs;
template <typename T> struct impl_IVisualState;
template <typename T> struct impl_IVisualState2;
template <typename T> struct impl_IVisualStateChangedEventArgs;
template <typename T> struct impl_IVisualStateGroup;
template <typename T> struct impl_IVisualStateManager;
template <typename T> struct impl_IVisualStateManagerFactory;
template <typename T> struct impl_IVisualStateManagerOverrides;
template <typename T> struct impl_IVisualStateManagerProtected;
template <typename T> struct impl_IVisualStateManagerStatics;
template <typename T> struct impl_IVisualTransition;
template <typename T> struct impl_IVisualTransitionFactory;
template <typename T> struct impl_IWindow;
template <typename T> struct impl_IWindow2;
template <typename T> struct impl_IWindowCreatedEventArgs;
template <typename T> struct impl_IWindowStatics;
template <typename T> struct impl_ApplicationInitializationCallback;
template <typename T> struct impl_BindingFailedEventHandler;
template <typename T> struct impl_CreateDefaultValueCallback;
template <typename T> struct impl_DependencyPropertyChangedCallback;
template <typename T> struct impl_DependencyPropertyChangedEventHandler;
template <typename T> struct impl_DragEventHandler;
template <typename T> struct impl_EnteredBackgroundEventHandler;
template <typename T> struct impl_ExceptionRoutedEventHandler;
template <typename T> struct impl_LeavingBackgroundEventHandler;
template <typename T> struct impl_PropertyChangedCallback;
template <typename T> struct impl_RoutedEventHandler;
template <typename T> struct impl_SizeChangedEventHandler;
template <typename T> struct impl_SuspendingEventHandler;
template <typename T> struct impl_UnhandledExceptionEventHandler;
template <typename T> struct impl_VisualStateChangedEventHandler;
template <typename T> struct impl_WindowActivatedEventHandler;
template <typename T> struct impl_WindowClosedEventHandler;
template <typename T> struct impl_WindowSizeChangedEventHandler;
template <typename T> struct impl_WindowVisibilityChangedEventHandler;

}

namespace Windows::UI::Xaml {

enum class ApplicationRequiresPointerMode
{
    Auto = 0,
    WhenRequested = 1,
};

enum class ApplicationTheme
{
    Light = 0,
    Dark = 1,
};

enum class AutomationTextAttributesEnum
{
    AnimationStyleAttribute = 40000,
    BackgroundColorAttribute = 40001,
    BulletStyleAttribute = 40002,
    CapStyleAttribute = 40003,
    CultureAttribute = 40004,
    FontNameAttribute = 40005,
    FontSizeAttribute = 40006,
    FontWeightAttribute = 40007,
    ForegroundColorAttribute = 40008,
    HorizontalTextAlignmentAttribute = 40009,
    IndentationFirstLineAttribute = 40010,
    IndentationLeadingAttribute = 40011,
    IndentationTrailingAttribute = 40012,
    IsHiddenAttribute = 40013,
    IsItalicAttribute = 40014,
    IsReadOnlyAttribute = 40015,
    IsSubscriptAttribute = 40016,
    IsSuperscriptAttribute = 40017,
    MarginBottomAttribute = 40018,
    MarginLeadingAttribute = 40019,
    MarginTopAttribute = 40020,
    MarginTrailingAttribute = 40021,
    OutlineStylesAttribute = 40022,
    OverlineColorAttribute = 40023,
    OverlineStyleAttribute = 40024,
    StrikethroughColorAttribute = 40025,
    StrikethroughStyleAttribute = 40026,
    TabsAttribute = 40027,
    TextFlowDirectionsAttribute = 40028,
    UnderlineColorAttribute = 40029,
    UnderlineStyleAttribute = 40030,
    AnnotationTypesAttribute = 40031,
    AnnotationObjectsAttribute = 40032,
    StyleNameAttribute = 40033,
    StyleIdAttribute = 40034,
    LinkAttribute = 40035,
    IsActiveAttribute = 40036,
    SelectionActiveEndAttribute = 40037,
    CaretPositionAttribute = 40038,
    CaretBidiModeAttribute = 40039,
};

enum class DurationType
{
    Automatic = 0,
    TimeSpan = 1,
    Forever = 2,
};

enum class ElementSoundKind
{
    Focus = 0,
    Invoke = 1,
    Show = 2,
    Hide = 3,
    MovePrevious = 4,
    MoveNext = 5,
    GoBack = 6,
};

enum class ElementSoundMode
{
    Default = 0,
    FocusOnly = 1,
    Off = 2,
};

enum class ElementSoundPlayerState
{
    Auto = 0,
    Off = 1,
    On = 2,
};

enum class ElementTheme
{
    Default = 0,
    Light = 1,
    Dark = 2,
};

enum class FlowDirection
{
    LeftToRight = 0,
    RightToLeft = 1,
};

enum class FocusState
{
    Unfocused = 0,
    Pointer = 1,
    Keyboard = 2,
    Programmatic = 3,
};

enum class FocusVisualKind
{
    DottedLine = 0,
    HighVisibility = 1,
};

enum class FontCapitals
{
    Normal = 0,
    AllSmallCaps = 1,
    SmallCaps = 2,
    AllPetiteCaps = 3,
    PetiteCaps = 4,
    Unicase = 5,
    Titling = 6,
};

enum class FontEastAsianLanguage
{
    Normal = 0,
    HojoKanji = 1,
    Jis04 = 2,
    Jis78 = 3,
    Jis83 = 4,
    Jis90 = 5,
    NlcKanji = 6,
    Simplified = 7,
    Traditional = 8,
    TraditionalNames = 9,
};

enum class FontEastAsianWidths
{
    Normal = 0,
    Full = 1,
    Half = 2,
    Proportional = 3,
    Quarter = 4,
    Third = 5,
};

enum class FontFraction
{
    Normal = 0,
    Stacked = 1,
    Slashed = 2,
};

enum class FontNumeralAlignment
{
    Normal = 0,
    Proportional = 1,
    Tabular = 2,
};

enum class FontNumeralStyle
{
    Normal = 0,
    Lining = 1,
    OldStyle = 2,
};

enum class FontVariants
{
    Normal = 0,
    Superscript = 1,
    Subscript = 2,
    Ordinal = 3,
    Inferior = 4,
    Ruby = 5,
};

enum class GridUnitType
{
    Auto = 0,
    Pixel = 1,
    Star = 2,
};

enum class HorizontalAlignment
{
    Left = 0,
    Center = 1,
    Right = 2,
    Stretch = 3,
};

enum class LineStackingStrategy
{
    MaxHeight = 0,
    BlockLineHeight = 1,
    BaselineToBaseline = 2,
};

enum class OpticalMarginAlignment
{
    None = 0,
    TrimSideBearings = 1,
};

enum class TextAlignment
{
    Center = 0,
    Left = 1,
    Right = 2,
    Justify = 3,
    DetectFromContent = 4,
};

enum class TextLineBounds
{
    Full = 0,
    TrimToCapHeight = 1,
    TrimToBaseline = 2,
    Tight = 3,
};

enum class TextReadingOrder
{
    Default [[deprecated("Consider using UseFlowDirection, which is an improved version of Default. For more info, see MSDN.")]] = 0,
    UseFlowDirection = 0,
    DetectFromContent = 1,
};

enum class TextTrimming
{
    None = 0,
    CharacterEllipsis = 1,
    WordEllipsis = 2,
    Clip = 3,
};

enum class TextWrapping
{
    NoWrap = 1,
    Wrap = 2,
    WrapWholeWords = 3,
};

enum class VerticalAlignment
{
    Top = 0,
    Center = 1,
    Bottom = 2,
    Stretch = 3,
};

enum class Visibility
{
    Visible = 0,
    Collapsed = 1,
};

}

}
