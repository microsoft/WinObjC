using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.ComponentModel;
using System.Diagnostics;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Automation.Peers;
using Windows.UI.Xaml.Media.Animation;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using Windows.UI.Xaml.Shapes;
using Windows.UI.Xaml.Markup;
using System.Threading.Tasks;

using System.Runtime.InteropServices;

namespace XamlCompositorCS
{
    namespace Controls
    {
        [Bindable]
        public sealed class CALayerXamlAutomationPeer : FrameworkElementAutomationPeer
        {
            public CALayerXamlAutomationPeer(CALayerXaml owner) : base(owner) {
            }

            protected override string GetClassNameCore() {
                return "FakeClassName";
            }
                
            protected override AutomationControlType GetAutomationControlTypeCore() {
                return AutomationControlType.ScrollBar;
            }
        }
        
        [Bindable]
        public sealed class CALayerXaml : Panel, CacheableObject
        {
            internal static double screenScale = 1.0;
            static bool RoundInitialized = false;
            static double RoundPixelsPerPoint;
            static SolidColorBrush TransparentBrush = new SolidColorBrush(Colors.Transparent);

            FrameworkElement content;
            Rect contentsCenter = new Rect(0, 0, 1, 1);
            ContentGravity contentGravity = ContentGravity.Resize;

            private TranslateTransform InvOriginTransform;
            private RectangleGeometry ClipGeometry;

            internal bool originSet = false;
            internal Color backgroundColor;
            internal SolidColorBrush backgroundBrush = TransparentBrush;
            private Point _position;
            private Point _origin;
            private Size _size;
            private bool _createdTransforms = false;
            private Point _anchorPoint;
            private bool _masksToBounds;
            private bool _topMost = false;
            double _Opacity;
            bool _hidden = false;

            static private ObjectCache _LayerContentCache = new ObjectCache();

            public void Reset()
            {
                Children.Clear();
                InvalidateArrange();
                content = null;
                contentsCenter = new Rect(0, 0, 1, 1);
                contentGravity = ContentGravity.Resize;
                Clip = null;
                InvOriginTransform = new TranslateTransform();
                ClipGeometry = new RectangleGeometry();
                ClipGeometry.Transform = InvOriginTransform;
                RenderTransform = new TranslateTransform();
                _position = new Point(0, 0);
                _origin = new Point(0, 0);
                _size = new Size(0, 0);
                _hidden = false;
                originSet = false;
                _createdTransforms = false;
                LayerOpacity = 1.0;
                backgroundBrush = TransparentBrush;
                backgroundColor.R = 0;
                backgroundColor.G = 0;
                backgroundColor.B = 0;
                backgroundColor.A = 0;

                Set("anchorPoint", new Point(0.5, 0.5));
                _masksToBounds = false;

                this.Background = TransparentBrush;
            }

            public double CurrentWidth
            {
                get
                {
                    if (_createdTransforms)
                    {
                        return VisualWidth;
                    }
                    else
                    {
                        return _size.Width;
                    }
                }
            }
            public double CurrentHeight
            {
                get
                {
                    if (_createdTransforms)
                    {
                        return VisualHeight;
                    }
                    else
                    {
                        return _size.Height;
                    }
                }
            }

            static public CALayerXaml CreateLayer()
            {
                CacheableObject ret = _LayerContentCache.GetCachableObject();
                if (ret != null)
                {
                    return (CALayerXaml)ret;
                }

                return new CALayerXaml();
            }

            static public void DestroyLayer(CALayerXaml layer)
            {
                layer.DiscardContent();
                _LayerContentCache.PushCacheableObject(layer);
            }

            static public void ApplyMagnificationFactor(Canvas windowContainer, float scale, float rotation)
            {
                TransformGroup globalTransform = new TransformGroup();
                ScaleTransform windowScale = new ScaleTransform();
                RotateTransform orientation = new RotateTransform();

                windowScale.ScaleX = scale;
                windowScale.ScaleY = scale;
                windowScale.CenterX = windowContainer.Width / 2.0;
                windowScale.CenterY = windowContainer.Height / 2.0;

                globalTransform.Children.Add(windowScale);
                if (rotation != 0.0f)
                {
                    orientation.Angle = rotation;
                    orientation.CenterX = windowContainer.Width / 2.0;
                    orientation.CenterY = windowContainer.Height / 2.0;

                    globalTransform.Children.Add(orientation);
                }

                windowContainer.RenderTransform = globalTransform;
                screenScale = (double)scale;
            }

            static public double RoundCoordinate(Object coord)
            {

                if (!RoundInitialized)
                {
                    RoundInitialized = true;
                    RoundPixelsPerPoint = ((int)Windows.Graphics.Display.DisplayInformation.GetForCurrentView().ResolutionScale) / 100.0;
                }
                return Math.Floor((double)coord * screenScale * RoundPixelsPerPoint) / (screenScale * RoundPixelsPerPoint);
            }

            internal static void AddAnimation(String propertyName, UIElement target, Storyboard storyboard, DoubleAnimation copyProperties, Object fromValue, Object toValue, bool dependent = false)
            {
                DoubleAnimation posxAnim = new DoubleAnimation();
                if (toValue != null) posxAnim.To = (double)toValue;
                if (fromValue != null) posxAnim.From = (double)fromValue;
                posxAnim.Duration = copyProperties.Duration;
                posxAnim.RepeatBehavior = copyProperties.RepeatBehavior;
                posxAnim.AutoReverse = copyProperties.AutoReverse;
                posxAnim.EasingFunction = copyProperties.EasingFunction;
                posxAnim.EnableDependentAnimation = dependent;
                posxAnim.FillBehavior = copyProperties.FillBehavior;
                posxAnim.BeginTime = copyProperties.BeginTime;
                storyboard.Children.Add(posxAnim);

                Storyboard.SetTarget(posxAnim, target);
                Storyboard.SetTargetProperty(posxAnim, propertyName);
            }

            static Object GetAnimatedTransformIndex(UIElement element, int idx, DependencyProperty property)
            {
                TransformGroup grp = (TransformGroup)element.GetValue(UIElement.RenderTransformProperty);
                TransformCollection children = (TransformCollection)grp.GetValue(TransformGroup.ChildrenProperty);
                DependencyObject transform = (DependencyObject)children[idx];

                return transform.GetValue(property);
            }

            static Object GetGeneralTransformIndex(UIElement element, int idx, DependencyProperty property)
            {
                TransformGroup grp = (TransformGroup)element.GetValue(UIElement.RenderTransformProperty);
                TransformCollection children = (TransformCollection)grp.GetValue(TransformGroup.ChildrenProperty);
                TransformGroup transform = (TransformGroup)children[2];
                TransformCollection generalTransformChildren = (TransformCollection)transform.GetValue(TransformGroup.ChildrenProperty);
                DependencyObject innerTransform = (DependencyObject)generalTransformChildren[idx];

                return innerTransform.GetValue(property);
            }

            void AdjustContentOriginX(Storyboard storyboard, DoubleAnimation properties, Object fromValue, Object toValue)
            {
                if (content == null) return;
                if (storyboard != null)
                {
                    AddAnimation("(UIElement.RenderTransform).(TranslateTransform.X)", content, storyboard, properties, fromValue != null ? (Object)fromValue : null, toValue);
                } else {
                    ((TranslateTransform)content.RenderTransform).X = (double) toValue;
                }
                if (content is LayerContent) {
                    (content as LayerContent).AdjustContentOriginX(storyboard, properties, fromValue, toValue);
                }
            }
            void AdjustContentOriginY(Storyboard storyboard, DoubleAnimation properties, Object fromValue, Object toValue)
            {
                if (content == null) return;
                if (storyboard != null)
                {
                    AddAnimation("(UIElement.RenderTransform).(TranslateTransform.Y)", content, storyboard, properties, fromValue != null ? (Object)fromValue : null, toValue);
                }
                else
                {
                    ((TranslateTransform)content.RenderTransform).Y = (double)toValue;
                }
                if (content is LayerContent) {
                    (content as LayerContent).AdjustContentOriginY(storyboard, properties, fromValue, toValue);
                }
            }

            internal class AnimatableProperty
            {
                public delegate void ApplyAnimationFunction(CALayerXaml target, Storyboard storyboard, DoubleAnimation properties, Object fromValue, Object toValue);
                public delegate void ApplyTransformFunction(CALayerXaml target, Object toValue);
                public delegate Object GetCurrentValue(CALayerXaml target);

                public ApplyAnimationFunction Animate;
                public ApplyTransformFunction Set;
                public GetCurrentValue GetValue;
                public AnimatableProperty(ApplyAnimationFunction animFunction, ApplyTransformFunction setFunction, GetCurrentValue getValue)
                {
                    Animate = animFunction;
                    Set = setFunction;
                    GetValue = getValue;
                }
            }
            internal static Dictionary<String, AnimatableProperty> animatableProperties = new Dictionary<String, AnimatableProperty> 
        {
            {   
                "position.x", 
                    new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[3].(TranslateTransform.X)", target, storyboard, properties, from, to);
                        },
                        (target, toValue) =>
                        {
                            target._position.X = (double)toValue;
                            if (target._createdTransforms) { 
                                ((TranslateTransform)((TransformGroup)target.RenderTransform).Children[3]).X = (double)toValue;
                            }
                            else
                            {
                                target.CalcTransforms();
                            }
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return target._position.X;
                            return CALayerXaml.GetAnimatedTransformIndex(target, 3, TranslateTransform.XProperty);
                        }
                    )

            },
            {   
                "position.y", 
                    new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[3].(TranslateTransform.Y)", target, storyboard, properties, from, to);
                        },
                        (target, toValue) =>
                        {
                            target._position.Y = (double)toValue;
                            if (target._createdTransforms) { 
                                ((TranslateTransform)((TransformGroup)target.RenderTransform).Children[3]).Y = (double)toValue;
                            }
                            else
                            {
                                target.CalcTransforms();
                            }
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return target._position.Y;
                            return CALayerXaml.GetAnimatedTransformIndex(target, 3, TranslateTransform.YProperty);
                        }
                    )

            },
            {   
                "position", 
                    new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            animatableProperties["position.x"].Animate(target, storyboard, properties, from != null ? (Object)((Point)from).X : null, ((Point)to).X);
                            animatableProperties["position.y"].Animate(target, storyboard, properties, from != null ? (Object)((Point)from).Y : null, ((Point)to).Y);
                        },
                        (target, toValue) =>
                        {
                            animatableProperties["position.x"].Set(target, ((Point)toValue).X);
                            animatableProperties["position.y"].Set(target, ((Point)toValue).Y);
                        },
                        (target) => 
                        {
                            return new Point((double)target.Get("position.x"), (double)target.Get("position.y"));
                        }
                    )

            },
            {   
                "origin.x", 
                    new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            target.SetupBackground();
                            double targetFrom = from != null ? (double) from : 0.0f;
                            double targetTo = to != null ? (double)to : 0.0f;

                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[1].(TranslateTransform.X)", target, storyboard, properties,from != null ? (Object) (-targetFrom) : null, -targetTo);
                            if (target._masksToBounds) {
                                AddAnimation("(UIElement.Clip).(Transform).(TranslateTransform.X)", target, storyboard, properties, from != null ? (Object) targetFrom : null, targetTo);
                            }
                            target.AdjustContentOriginX(storyboard, properties, targetFrom, targetTo);
                        },
                        (target, toValue) =>
                        {
                            target.SetupBackground();
                            double targetValue = (double) toValue;

                            targetValue = RoundCoordinate(targetValue);
                            target._origin.X = targetValue;

                            if (target._createdTransforms)
                            {
                                ((TranslateTransform)((TransformGroup)target.RenderTransform).Children[1]).X = -targetValue;
                            }
                            else {
                                target.CalcTransforms();
                            }
                            if (target.Clip != null) ((TranslateTransform)target.Clip.Transform).X = targetValue;
                            target.AdjustContentOriginX(null, null, null, targetValue);
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return target._origin.X;
                            return (Object) (-((double) CALayerXaml.GetAnimatedTransformIndex(target, 1, TranslateTransform.XProperty)));
                        }
                    )
            },
            {   
                "origin.y", 
                    new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            target.SetupBackground();
                            double targetFrom = from != null ? (double) from : 0.0f;
                            double targetTo = to != null ? (double)to : 0.0f;

                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[1].(TranslateTransform.Y)", target, storyboard, properties, from != null ? (Object) (-targetFrom) : null, -targetTo);
                            if (target._masksToBounds) {
                                AddAnimation("(UIElement.Clip).(Transform).(TranslateTransform.Y)", target, storyboard, properties, from != null ? (Object)(targetFrom) : null, targetTo);
                            }
                            target.AdjustContentOriginY(storyboard, properties, targetFrom, targetTo);
                        },
                        (target, toValue) =>
                        {
                            target.SetupBackground();
                            double targetValue = (double) toValue;

                            targetValue = RoundCoordinate(targetValue);
                            target._origin.Y = targetValue;

                            if (target._createdTransforms) { 
                                ((TranslateTransform)((TransformGroup)target.RenderTransform).Children[1]).Y = -targetValue;
                            }
                            else
                            {
                                target.CalcTransforms();
                            }
                            if (target.Clip != null) ((TranslateTransform)target.Clip.Transform).Y = targetValue;
                            target.AdjustContentOriginY(null, null, null, targetValue);
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return target._origin.Y;
                            return (Object) (-((double) CALayerXaml.GetAnimatedTransformIndex(target, 1, TranslateTransform.YProperty)));
                        }
                    )
            },
            {   
                "origin", 
                    new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            animatableProperties["origin.x"].Animate(target, storyboard, properties, from != null ? (Object)((Point)from).X : null, ((Point)to).X);
                            animatableProperties["origin.y"].Animate(target, storyboard, properties, from != null ? (Object)((Point)from).Y : null, ((Point)to).Y);
                        },
                        (target, toValue) =>
                        {
                            animatableProperties["origin.x"].Set(target, ((Point)toValue).X);
                            animatableProperties["origin.y"].Set(target, ((Point)toValue).Y);
                        },
                        (target) =>
                        {
                            return new Point((double) target.Get("origin.x"), (double) target.Get("origin.y"));
                        }
                    )

            },
            {   "anchorPoint.x", 
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            Object fromVal = from != null ? (Object)(-target._size.Width * (double)from) : null;
                            double destVal = -target._size.Width * (double) to;

                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[0].(TranslateTransform.X)", target, storyboard, properties, fromVal, destVal);
                        },
                        (target, toValue) =>
                        {
                            target._anchorPoint.X = (double)toValue;
                            if (target._createdTransforms)
                            {
                                double destX = -target._size.Width * ((double)toValue);
                                ((TranslateTransform)((TransformGroup)target.RenderTransform).Children[0]).X = destX;
                            }
                            else
                            {
                                target.CalcTransforms();
                            }
                        },
                        (target) =>
                        {
                            return (Object) target._anchorPoint.X;
                        }
                    )
            },
            {   "anchorPoint.y", 
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            Object fromVal = from != null ? (Object)(-target._size.Height * (double)from) : null;
                            double destVal = -target._size.Height * (double) to;

                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[0].(TranslateTransform.Y)", target, storyboard, properties, fromVal, destVal);
                        },
                        (target, toValue) =>
                        {
                            target._anchorPoint.Y = (double)toValue;
                            if (target._createdTransforms) { 
                                double destY = -target._size.Height * ((double)toValue);
                                ((TranslateTransform) ((TransformGroup)target.RenderTransform).Children[0]).Y = destY;
                            }
                            else
                            {
                                target.CalcTransforms();
                            }
                        },
                        (target) =>
                        {
                            return (Object) target._anchorPoint.Y;
                        }
                    )
            },
            {   "anchorPoint", 
                    new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            animatableProperties["anchorPoint.x"].Animate(target, storyboard, properties, from != null ? (Object)((Point)from).X : null, ((Point)to).X);
                            animatableProperties["anchorPoint.y"].Animate(target, storyboard, properties, from != null ? (Object)((Point)from).Y : null, ((Point)to).Y);
                        },
                        (target, toValue) =>
                        {
                            animatableProperties["anchorPoint.x"].Set(target, ((Point)toValue).X);
                            animatableProperties["anchorPoint.y"].Set(target, ((Point)toValue).Y);
                        },
                        (target) => 
                        {
                            return new Point((double)target.Get("anchorPoint.x"), (double)target.Get("anchorPoint.y"));
                        }
                    )
            },
            {   "size.width",
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            if ( from != null ) if ( (double) from < 0.0 ) from = 0.0;
                            if (to != null) if ((double)to < 0.0) to = 0.0;

                            Object fromVal = from != null ? (Object)((-((double)from)) * target._anchorPoint.X) : null;
                            double dest = -((double) to) * target._anchorPoint.X;

                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[0].(TranslateTransform.X)", target, storyboard, properties, fromVal, dest);
                            AddAnimation("(CALayerXaml.VisualWidth)", target, storyboard, properties, from, to, true);
                        },
                        (target, toValue) =>
                        {
                            if (toValue != null) if ((double)toValue < 0) toValue = 0.0;
                            toValue = RoundCoordinate(toValue);

                            if (target._size.Width == (double) toValue) return;
                            target._size.Width = (double)toValue;
                            target.Width = (double)toValue;

                            if (target._createdTransforms) { 
                                double destX = -((double) toValue) * target._anchorPoint.X;
                                ((TranslateTransform)((TransformGroup)target.RenderTransform).Children[0]).X = destX;
                                target.VisualWidth = (double)toValue;
                            }
                            else
                            {
                                target.CalcTransforms();
                            }
                            target.InvalidateArrange();
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return target._size.Width;
                            return target.GetValue(CALayerXaml.VisualWidthProperty);
                        }
                    )
            },
            {   "size.height",
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            if ( from != null ) if ( (double) from < 0.0 ) from = 0.0;
                            if (to != null) if ((double)to < 0.0) to = 0.0;
                            Object fromVal = from != null ? (Object)((-((double)from)) * target._anchorPoint.Y) : null;
                            double dest = -((double) to) * target._anchorPoint.Y;

                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[0].(TranslateTransform.Y)", target, storyboard, properties, fromVal, dest);
                            AddAnimation("(CALayerXaml.VisualHeight)", target, storyboard, properties, from, to, true);
                        },
                        (target, toValue) =>
                        {
                            if (toValue != null) if ((double)toValue < 0) toValue = 0.0;
                            toValue = RoundCoordinate(toValue);
                            if (target._size.Height == (double)toValue) return;
                            target._size.Height = (double)toValue;
                            target.Height = (double)toValue;

                            if (target._createdTransforms) { 
                                double destY = -((double) toValue) * target._anchorPoint.Y;
                                ((TranslateTransform)((TransformGroup)target.RenderTransform).Children[0]).Y = destY;
                                target.VisualHeight = (double)toValue;
                            }
                            else
                            {
                                target.CalcTransforms();
                            }
                            target.InvalidateArrange();
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return target._size.Height;
                            return target.GetValue(CALayerXaml.VisualHeightProperty);
                        }
                    )
            },
            {   "size",
                new AnimatableProperty(
                    (target, storyboard, properties, from, to) => 
                    {
                        animatableProperties["size.width"].Animate(target, storyboard, properties, from != null ? (Object)((Size)from).Width : null, ((Size)to).Width);
                        animatableProperties["size.height"].Animate(target, storyboard, properties, from != null ? (Object)((Size)from).Height : null, ((Size)to).Height);
                    },
                    (target, toValue) =>
                    {
                        animatableProperties["size.width"].Set(target, ((Size)toValue).Width);
                        animatableProperties["size.height"].Set(target, ((Size)toValue).Height);
                    },
                    (target) => 
                    {
                        return new Size((double) target.Get("size.width"), (double) target.Get("size.height"));
                    }
                )
            },
            {
                "transform.rotation",
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[0].(RotateTransform.Angle)", target, storyboard, properties, from, to);
                        },
                        (target, toValue) =>
                        {
                            target.CreateTransforms();
                            ((RotateTransform) ((TransformGroup) ((TransformGroup)target.RenderTransform).Children[2]).Children[0]).Angle = (double) toValue;
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return 0.0;
                            return CALayerXaml.GetGeneralTransformIndex(target, 0, RotateTransform.AngleProperty);
                        }
                    )
            },
            {
                "transform.scale.x",
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[1].(ScaleTransform.ScaleX)", target, storyboard, properties, from, to);
                        },
                        (target, toValue) =>
                        {
                            target.CreateTransforms();
                            ((ScaleTransform)((TransformGroup)((TransformGroup)target.RenderTransform).Children[2]).Children[1]).ScaleX = (double)toValue;
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return 0.0;
                            return CALayerXaml.GetGeneralTransformIndex(target, 1, ScaleTransform.ScaleXProperty);
                        }
                    )
            },
            {
                "transform.scale.y",
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[1].(ScaleTransform.ScaleY)", target, storyboard, properties, from, to);
                        },
                        (target, toValue) =>
                        {
                            target.CreateTransforms();
                            ((ScaleTransform)((TransformGroup)((TransformGroup)target.RenderTransform).Children[2]).Children[1]).ScaleY = (double)toValue;
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return 0.0;
                            return CALayerXaml.GetGeneralTransformIndex(target, 1, ScaleTransform.ScaleYProperty);
                        }
                    )
            },
            {
                "transform.translation.x",
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[2].(TranslateTransform.X)", target, storyboard, properties, from, to);
                        },
                        (target, toValue) =>
                        {
                            target.CreateTransforms();
                            ((TranslateTransform)((TransformGroup)((TransformGroup)target.RenderTransform).Children[2]).Children[2]).X = (double)toValue;
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return 0.0;
                            return CALayerXaml.GetGeneralTransformIndex(target, 2, TranslateTransform.XProperty);
                        }
                    )
            },
            {
                "transform.translation.y",
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            target.CreateTransforms();
                            AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[2].(TranslateTransform.Y)", target, storyboard, properties, from, to);
                        },
                        (target, toValue) =>
                        {
                            target.CreateTransforms();
                            ((TranslateTransform)((TransformGroup)((TransformGroup)target.RenderTransform).Children[2]).Children[2]).Y = (double)toValue;
                        },
                        (target) =>
                        {
                            if (!target._createdTransforms) return 0.0;
                            return CALayerXaml.GetGeneralTransformIndex(target, 2, TranslateTransform.YProperty);
                        }
                    )
            },
            {
                "opacity",
                new AnimatableProperty(
                        (target, storyboard, properties, from, to) => 
                        {
                            AddAnimation("(UIElement.Opacity)", target, storyboard, properties, from, to);
                        },
                        (target, toValue) =>
                        {
                            target._Opacity = (double)toValue;
                            target.SetOpacity();
                        },
                        (target) =>
                        {
                            return target._Opacity;
                        }
                    )
            },
            {
                "gravity",
                new AnimatableProperty(
                        null,
                        (target, toValue) =>
                        {
                            target.SetContentGravity((ContentGravity)(int)toValue);
                        },
                        (target) =>
                        {
                            return (int) target.contentGravity;
                        }
                    )
            },
            {
                "masksToBounds",
                new AnimatableProperty(
                        null,
                        (target, toValue) =>
                        {
                            target._masksToBounds = (bool)toValue;
                            target.Clip = target._masksToBounds ? target.ClipGeometry : null;
                        },
                        (target) =>
                        {
                            return target._masksToBounds;
                        }
                    )
            }

        };

            void CalcTransforms()
            {
                if (!_createdTransforms)
                {
                    Point destTranslation;

                    destTranslation.X = -_size.Width * _anchorPoint.X;
                    destTranslation.Y = -_size.Height * _anchorPoint.Y;
                    destTranslation.X -= _origin.X;
                    destTranslation.Y -= _origin.Y;
                    destTranslation.X += _position.X;
                    destTranslation.Y += _position.Y;

                    ((TranslateTransform)RenderTransform).X = destTranslation.X;
                    ((TranslateTransform)RenderTransform).Y = destTranslation.Y;
                }
            }

            void CreateTransforms()
            {
                if (!_createdTransforms)
                {
                    TranslateTransform SizeAnchorTransform = new TranslateTransform();
                    SizeAnchorTransform.X = -_size.Width * _anchorPoint.X;
                    SizeAnchorTransform.Y = -_size.Height * _anchorPoint.Y;

                    TranslateTransform OriginTransform = new TranslateTransform();
                    OriginTransform.X = -_origin.X;
                    OriginTransform.Y = -_origin.Y;

                    TransformGroup ContentTransform = new TransformGroup();
                    ContentTransform.Children.Add(new RotateTransform());
                    ContentTransform.Children.Add(new ScaleTransform());
                    ContentTransform.Children.Add(new TranslateTransform());

                    TranslateTransform PositionTransform = new TranslateTransform();
                    PositionTransform.X = _position.X;
                    PositionTransform.Y = _position.Y;

                    TransformGroup LayerTransforms = new TransformGroup();
                    LayerTransforms.Children.Add(SizeAnchorTransform);
                    LayerTransforms.Children.Add(OriginTransform);
                    LayerTransforms.Children.Add(ContentTransform);
                    LayerTransforms.Children.Add(PositionTransform);
                    RenderTransform = LayerTransforms;

                    VisualWidth = _size.Width;
                    VisualHeight = _size.Height;
                    _createdTransforms = true;
                    if (_createdTransforms) CAXamlDebugCounters.IncCounter("CALayerXamlTransforms");
                }
            }

            public void Set(string propertyName, Object value)
            {
                animatableProperties[propertyName].Set(this, value);
            }

            public Object Get(string propertyName)
            {
                return animatableProperties[propertyName].GetValue(this);
            }

            void SetOpacity()
            {
                if (_hidden)
                {
                    this.Opacity = 0.0;
                }
                else
                {
                    this.Opacity = _Opacity;
                }
            }

            public double LayerOpacity
            {
                set
                {
                    _Opacity = value;
                    SetOpacity();
                }
                get
                {
                    return _Opacity;
                }
            }

            public bool hidden
            {
                set
                {
                    _hidden = value;
                    SetOpacity();
                }

                get
                {
                    return _hidden;
                }
            }

            /* Disable for now
            protected override AutomationPeer OnCreateAutomationPeer()
            {
                return new CALayerXamlAutomationPeer(this);
            }
            */

            public static void SizeChangedCallback(DependencyObject d, DependencyPropertyChangedEventArgs e)
            {
                ((CALayerXaml)d).InvalidateArrange();
            }

            private static readonly DependencyProperty _VisualWidthProperty =
                DependencyProperty.Register(
                    "VisualWidth", typeof(double),
                    typeof(CALayerXaml), new PropertyMetadata(0.0, SizeChangedCallback)
                );
            private static readonly DependencyProperty _VisualHeightProperty =
                DependencyProperty.Register(
                    "VisualHeight", typeof(double),
                    typeof(CALayerXaml), new PropertyMetadata(0.0, SizeChangedCallback)
                );

            public static DependencyProperty VisualWidthProperty
            {
                get
                {
                    return _VisualWidthProperty;
                }
            }

            public static DependencyProperty VisualHeightProperty
            {
                get
                {
                    return _VisualHeightProperty;
                }
            }

            public double VisualWidth
            {
                get { return (double)GetValue(VisualWidthProperty); }
                set { SetValue(VisualWidthProperty, value); }
            }
            public double VisualHeight
            {
                get { return (double)GetValue(VisualHeightProperty); }
                set { SetValue(VisualHeightProperty, value); }
            }

            public CALayerXaml()
            {
                CAXamlDebugCounters.IncCounter("CALayerXaml");
                InvOriginTransform = new TranslateTransform();
                ClipGeometry = new RectangleGeometry();
                ClipGeometry.Transform = InvOriginTransform;
                RenderTransform = new TranslateTransform();

                Set("anchorPoint", new Point(0.5, 0.5));
                LayerOpacity = 1.0;

                this.Background = TransparentBrush;
                this.PointerPressed += CALayerXaml_PointerPressed;
                this.PointerReleased += CALayerXaml_PointerReleased;
                this.PointerMoved += CALayerXaml_PointerMoved;
                this.PointerCanceled += CALayerXaml_PointerCanceled;
                this.IsHitTestVisible = true;
            }

            ~CALayerXaml()
            {
                CAXamlDebugCounters.DecCounter("CALayerXaml");
                if (_createdTransforms) CAXamlDebugCounters.DecCounter("CALayerXamlTransforms");
            }

            internal void CopyPropertiesFrom(CALayerXaml fromLayer)
            {
                Set("opacity", fromLayer.Get("opacity"));
                Set("position", fromLayer.Get("position"));
                Set("size", fromLayer.Get("size"));
                Set("anchorPoint", fromLayer.Get("anchorPoint"));
            }

            void CALayerXaml_PointerPressed(object sender, PointerRoutedEventArgs e)
            {
                CapturePointer(e.Pointer);
                CALayerInputHandler.HandleDownInput(this, e);
                e.Handled = true;
            }

            void CALayerXaml_PointerReleased(object sender, PointerRoutedEventArgs e)
            {
                CALayerInputHandler.HandleUpInput(this, e);
                e.Handled = true;
            }

            void CALayerXaml_PointerCanceled(object sender, PointerRoutedEventArgs e)
            {
                CALayerInputHandler.HandleUpInput(this, e);
                e.Handled = true;
            }

            void CALayerXaml_PointerMoved(object sender, PointerRoutedEventArgs e)
            {
                CALayerInputHandler.HandleMoveInput(this, e);
                e.Handled = true;
            }

            public void DiscardContent()
            {
                if (content != null)
                {
                    Children.Remove(content);
                    InvalidateArrange();

                    if (content is LayerContent)
                    {
                        LayerContent.DestroyLayerContent((LayerContent)content);
                    }
                    content = null;
                }
            }

            void SetContent(FrameworkElement element)
            {
                if (content == element) return;

                DiscardContent();

                content = element;
                if (element != null)
                {
                    content.RenderTransform = InvOriginTransform;
                    this.Children.Insert(0, content);
                    InvalidateArrange();
                }
            }

            LayerContent GetImageContent(bool create = false)
            {
                if (!(content is LayerContent))
                {
                    if (!create) return null;

                    LayerContent imageContent = LayerContent.CreateLayerContent();
                    imageContent.SetGravity(contentGravity);
                    imageContent.SetContentsCenter(contentsCenter);
                    imageContent.Background = backgroundBrush;
                    imageContent.AdjustContentOriginX(null, null, null, _origin.X);
                    imageContent.AdjustContentOriginY(null, null, null, _origin.Y);
                    this.Background = TransparentBrush;

                    SetContent(imageContent);
                }

                return (LayerContent)content;
            }

            public void SetContentGravity(ContentGravity gravity)
            {
                contentGravity = gravity;
                if (GetImageContent() != null)
                {
                    GetImageContent().SetGravity(gravity);
                }
            }

            public void SetContentsCenter(Rect rect)
            {
                contentsCenter = rect;
                if (GetImageContent() != null)
                {
                    GetImageContent().SetContentsCenter(contentsCenter);
                }
            }

            public void SetupBackground()
            {
                if (content == null)
                {
                    Rectangle rect;
                    rect = new Rectangle();
                    SetContent(rect);
                }

                if (content is Rectangle)
                {
                    (content as Rectangle).Fill = backgroundBrush;
                }
                else
                {
                    (content as Panel).Background = backgroundBrush;
                }
            }

            public void SetBackgroundColor(float r, float g, float b, float a)
            {
                backgroundColor.R = (byte)(r * 255.0);
                backgroundColor.G = (byte)(g * 255.0);
                backgroundColor.B = (byte)(b * 255.0);
                backgroundColor.A = (byte)(a * 255.0);
                if (backgroundColor.A == 0)
                {
                    backgroundBrush = TransparentBrush;
                }
                else
                {
                    backgroundBrush = new SolidColorBrush(backgroundColor);
                }

                SetupBackground();
            }

            public void SetTopMost()
            {
                _topMost = true;
                SetContent(null);
                this.Background = null;
            }

            public void setContentImage(ImageSource source, float width, float height, float scale)
            {
                if (source == null)
                {
                    if (content is LayerContent)
                    {
                        SetContent(null);
                        SetupBackground();
                    }
                }
                else
                {
                    LayerContent c = GetImageContent(true);
                    c.SetImageContent(source, (int) width, (int) height);
                    c.SetImageParams(width, height, scale);
                }
            }

            public void setContentElement(FrameworkElement elem, float width, float height, float scale)
            {
                if (elem == null)
                {
                    if (content is LayerContent)
                    {
                        SetContent(null);
                        SetupBackground();
                    }
                }
                else
                {
                    LayerContent c = GetImageContent(true);
                    c.SetGravity(ContentGravity.Left);
                    c.SetElementContent(elem);
                    c.SetImageParams(width, height, scale);
                }
            }

            protected override Size ArrangeOverride(Size finalSize)
            {
                double curWidth = CurrentWidth;
                double curHeight = CurrentHeight;
                if (ClipGeometry.Rect.Width != curWidth ||
                    ClipGeometry.Rect.Height != curHeight)
                {
                    ClipGeometry.Rect = new Rect(0, 0, curWidth, curHeight);
                }

                if (content != null)
                {
                    content.Width = curWidth;
                    content.Height = curHeight;
                    content.Arrange(new Rect(0, 0, curWidth, curHeight));
                }

                foreach (UIElement curChild in Children)
                {
                    if (curChild == content) continue;
                    CALayerXaml subLayer = curChild as CALayerXaml;
                    if (subLayer != null)
                    {
                        subLayer.Arrange(new Rect(0, 0, 1.0, 1.0));
                    }
                }
                Size ret;

                if (Parent is CALayerXaml)
                {
                    ret = new Size(1, 1);
                }
                else
                {
                    ret = new Size(curWidth, curHeight);
                }

                return ret;
            }

            protected override Size MeasureOverride(Size availableSize)
            {
                return _size;
            }
        }

        public delegate void AnimationMethod(Object sender);

        public sealed class EventedStoryboard
        {
            Storyboard _container = new Storyboard();
            AnimationMethod _Completed;
            AnimationMethod _Started;
            bool aborted = false;
            
            public EventedStoryboard()
            {
                // AppxManifest.xml appears to fail to enumerate runtimeclasses with accessors and no default constructor in the Win8.1 SDK.
                throw new InvalidOperationException("Do not use the default constructor; this is merely here as a bug fix.");
            }

            class Animation
            {
                internal string propertyName;
                internal Object toValue;
            }
            List<Animation> Animations = new List<Animation>();
            CALayerXaml AnimatedLayer;

            public AnimationMethod Completed
            {
                get
                {
                    return _Completed;
                }
                set
                {
                    _Completed = value;
                }
            }

            public AnimationMethod Started
            {
                get
                {
                    return _Started;
                }
                set
                {
                    _Started = value;
                }
            }
            public void Start()
            {
                _container.Begin();
            }

            public void Abort()
            {
                aborted = true;
                foreach (Animation curAnim in Animations)
                {
                    Object curValue = CALayerXaml.animatableProperties[curAnim.propertyName].GetValue(AnimatedLayer);
                    CALayerXaml.animatableProperties[curAnim.propertyName].Set(AnimatedLayer, curValue);
                }
            }

            internal void CreateFlip(CALayerXaml layer, bool flipRight, bool invert, bool removeFromParent)
            {
                if (layer.Projection == null)
                {
                    layer.Projection = new PlaneProjection();
                }

                DoubleAnimation rotateAnim = new DoubleAnimation();
                rotateAnim.Duration = _container.Duration;

                if (!invert)
                {
                    rotateAnim.From = 0.01;
                    if (!flipRight)
                    {
                        rotateAnim.To = 180;
                    }
                    else
                    {
                        rotateAnim.To = -180;
                    }
                }
                else
                {
                    if (!flipRight)
                    {
                        rotateAnim.From = 180;
                        rotateAnim.To = 360;
                    }
                    else
                    {
                        rotateAnim.From = -180;
                        rotateAnim.To = -360;
                    }
                }

                ((PlaneProjection)layer.Projection).CenterOfRotationX = layer.CurrentWidth / 2;
                ((PlaneProjection)layer.Projection).CenterOfRotationY = layer.CurrentHeight / 2;
                Storyboard.SetTargetProperty(rotateAnim, "(UIElement.Projection).(PlaneProjection.RotationY)");
                Storyboard.SetTarget(rotateAnim, layer);
                _container.Children.Add(rotateAnim);

                DoubleAnimation moveAnim = new DoubleAnimation();
                moveAnim.Duration = _container.Duration;
                moveAnim.From = 0.01;
                moveAnim.To = -160;
                moveAnim.SpeedRatio = 2.0;
                moveAnim.AutoReverse = true;

                Storyboard.SetTarget(moveAnim, layer);
                Storyboard.SetTargetProperty(moveAnim, "(UIElement.Projection).(PlaneProjection.GlobalOffsetZ)");
                _container.Children.Add(moveAnim);

                DoubleAnimation fade1 = new DoubleAnimation();
                Storyboard.SetTarget(fade1, layer);
                Storyboard.SetTargetProperty(fade1, "(UIElement.Opacity)");

                if (!invert)
                {
                    fade1.Duration = TimeSpan.FromSeconds(_container.Duration.TimeSpan.TotalSeconds / 2.0);
                    fade1.From = 1.0;
                    fade1.To = 0.5;
                    fade1.FillBehavior = FillBehavior.HoldEnd;
                }
                else
                {
                    fade1.Duration = TimeSpan.FromSeconds(_container.Duration.TimeSpan.TotalSeconds / 2.0);
                    fade1.BeginTime = TimeSpan.FromSeconds(_container.Duration.TimeSpan.TotalSeconds / 2.0);
                    fade1.From = 0.5;
                    fade1.To = 1.0;
                    fade1.FillBehavior = FillBehavior.HoldEnd;

                    fade1.Completed += (Object sender, Object args) =>
                    {
                        layer.Opacity = 1.0;
                    };
                }

                if (removeFromParent)
                {
                    fade1.Completed += (Object sender, Object args) =>
                    {
                        VisualTreeHelper.DisconnectChildrenRecursive(layer);
                        //CALayerXaml.DestroyLayer(layer);
                    };
                }

                _container.Children.Add(fade1);
            }

            internal void CreateWoosh(CALayerXaml layer, bool fromRight, bool invert, bool removeFromParent)
            {
                if (layer.Projection == null)
                {
                    layer.Projection = new PlaneProjection();
                }

                DoubleAnimation rotateAnim = new DoubleAnimation();
                rotateAnim.Duration = _container.Duration;
                rotateAnim.EasingFunction = new PowerEase();
                rotateAnim.EasingFunction.EasingMode = EasingMode.EaseOut;

                if (!invert)
                {
                    if (fromRight)
                    {
                        rotateAnim.From = layer.CurrentWidth;
                        rotateAnim.To = 0.01;
                    }
                    else
                    {
                        rotateAnim.From = 0.01;
                        rotateAnim.To = layer.CurrentWidth;
                    }
                }
                else
                {
                    if (fromRight)
                    {
                        rotateAnim.From = 0.01;
                        rotateAnim.To = -layer.CurrentWidth / 4;
                    }
                    else
                    {
                        rotateAnim.From = -layer.CurrentWidth / 4;
                        rotateAnim.To = 0.01;
                    }
                }

                Storyboard.SetTargetProperty(rotateAnim, "(UIElement.Projection).(PlaneProjection.LocalOffsetX)");
                Storyboard.SetTarget(rotateAnim, layer);

                if (removeFromParent)
                {
                    rotateAnim.Completed += (Object sender, Object args) =>
                    {
                        VisualTreeHelper.DisconnectChildrenRecursive(layer);
                        //CALayerXaml.DestroyLayer(layer);
                    };
                }

                _container.Children.Add(rotateAnim);
            }

            public IAsyncOperation<int> AddTransition(CALayerXaml layer, String type, String subtype)
            {
                return DoAddTransition(layer, type, subtype).AsAsyncOperation<int>();
            }

            async private Task<int> DoAddTransition(CALayerXaml layer, String type, String subtype)
            {
                RenderTargetBitmap copiedLayer = new RenderTargetBitmap();
                double scale = CALayerXaml.screenScale;
                await copiedLayer.RenderAsync(layer, (int)(layer.CurrentWidth * scale), 0);

                CALayerXaml newLayer = CALayerXaml.CreateLayer();
                newLayer.CopyPropertiesFrom(layer);
                int width = copiedLayer.PixelWidth;
                int height = copiedLayer.PixelHeight;

                newLayer.setContentImage(copiedLayer, (float)width, (float)height, (float)scale);
                newLayer.SetContentGravity(ContentGravity.ResizeAspectFill);

                if (type == "kCATransitionFlip")
                {
                    _container.Duration = new Duration(TimeSpan.FromSeconds(0.75));
                    Panel parent = (Panel)VisualTreeHelper.GetParent(layer);
                    int idx = parent.Children.IndexOf(layer);
                    parent.Children.Insert(idx + 1, newLayer);
                    parent.InvalidateArrange();
                    layer.Opacity = 0;

                    bool flipToLeft = true;
                    if (subtype != "kCATransitionFromLeft")
                    {
                        flipToLeft = false;
                    }

                    CreateFlip(newLayer, flipToLeft, false, true);
                    CreateFlip(layer, flipToLeft, true, false);
                }
                else
                {
                    _container.Duration = new Duration(TimeSpan.FromSeconds(0.5));
                    Panel parent = (Panel)VisualTreeHelper.GetParent(layer);
                    int idx = parent.Children.IndexOf(layer);

                    bool fromRight = true;
                    if (subtype == "kCATransitionFromLeft")
                    {
                        fromRight = false;
                    }

                    if (fromRight)
                    {
                        parent.Children.Insert(idx, newLayer);
                        parent.InvalidateArrange();
                        CreateWoosh(newLayer, fromRight, true, true);
                        CreateWoosh(layer, fromRight, false, false);
                    }
                    else
                    {
                        parent.Children.Insert(idx + 1, newLayer);
                        parent.InvalidateArrange();
                        CreateWoosh(newLayer, fromRight, false, true);
                        CreateWoosh(layer, fromRight, true, false);
                    }
                }

                return 0;
            }

            enum EasingFunction
            {
                EastInEaseIn,
                Linear
            }

            private EasingFunctionBase _AnimationEase;
            public EasingFunctionBase AnimationEase
            {
                set
                {
                    _AnimationEase = value;
                }
                get
                {
                    return _AnimationEase;
                }
            }

            public void Animate(CALayerXaml layer, String propertyName, Object from, Object to)
            {
                DoubleAnimation timeline = new DoubleAnimation();
                timeline.Duration = _container.Duration;
                timeline.EasingFunction = _AnimationEase;

                CALayerXaml.animatableProperties[propertyName].Animate(layer, _container, timeline, from, to);
            }

            public EventedStoryboard(double beginTime, double duration, bool autoReverse, float repeatCount, float repeatDuration, float speed, double timeOffset)
            {
                _container.BeginTime = TimeSpan.FromSeconds(beginTime);
                _container.Duration = TimeSpan.FromSeconds(duration);
                if (repeatCount != 0)
                {
                    _container.RepeatBehavior = new RepeatBehavior(repeatCount);
                }
                if (repeatDuration != 0)
                {
                    _container.RepeatBehavior = new RepeatBehavior(TimeSpan.FromSeconds(repeatDuration));
                }
                _container.SpeedRatio = speed;
                _container.AutoReverse = autoReverse;
                _container.FillBehavior = FillBehavior.HoldEnd;
                _container.Completed += (a, b) =>
                {
                    if (Completed != null) Completed(this);
                    _container.Stop();
                };
                TimeSpan span = _container.BeginTime.Value;
                Windows.System.Threading.ThreadPoolTimer beginTimer = Windows.System.Threading.ThreadPoolTimer.CreateTimer(
                    (handler) =>
                    {
                        _container.Dispatcher.RunAsync(
                            Windows.UI.Core.CoreDispatcherPriority.High,
                                () =>
                                {
                                    if (Started != null) Started(this);
                                });
                    }, _container.BeginTime.Value);
            }

            public Object GetStoryboard()
            {
                return _container;
            }
        }

        public interface CALayerXamlInputEvents
        {
            void PointerDown(float x, float y, uint id, ulong timestamp);
            void PointerUp(float x, float y, uint id, ulong timestamp);
            void PointerMoved(float x, float y, uint id, ulong timestamp);
            void KeyDown(uint key);
        }

        public sealed class CAXamlDebugCounters : Canvas
        {
            class Counter
            {
                public string name;
                public int count;
                public TextBlock textOutput;
                public bool _updating = false;
                public int idx;

                public void UpdateText()
                {
                    if (!_updating)
                    {
                        _updating = true;
                        CAXamlDebugCounters._singleton.Dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.Low, () =>
                                {
                                    if (textOutput == null)
                                    {
                                        textOutput = new TextBlock();
                                        textOutput.FontSize = 14;
                                        textOutput.Text = name;
                                        textOutput.SetValue(Canvas.LeftProperty, 0);
                                        textOutput.SetValue(Canvas.TopProperty, 30 + idx * 17.0);
                                        CAXamlDebugCounters._singleton.Children.Add(textOutput);
                                        CAXamlDebugCounters._singleton.InvalidateArrange();
                                        CAXamlDebugCounters._singleton.InvalidateMeasure();
                                    }
                                    _updating = false;
                                    textOutput.Text = String.Format("{0}: {1}", name, count);
                                });
                    }
                }
            }
            static internal CAXamlDebugCounters _singleton;

            Dictionary<String, Counter> _Counters = new Dictionary<string, Counter>();

            Counter GetCounter(string name)
            {
                Counter curCounter;

                if (!_Counters.ContainsKey(name))
                {
                    curCounter = new Counter();
                    curCounter.count = 0;
                    curCounter.name = name;
                    curCounter.idx = _Counters.Count;
                    _Counters[name] = curCounter;
                }
                else curCounter = _Counters[name];

                return curCounter;
            }

            static public void IncCounter(string name)
            {
                if (_singleton != null) _singleton.IncrementCounter(name);
            }

            static public void DecCounter(string name)
            {
                if (_singleton != null) _singleton.DecrementCounter(name);
            }

            public void IncrementCounter(string name)
            {
                Counter curCounter = GetCounter(name);

                curCounter.count++;
                curCounter.UpdateText();
            }

            public void DecrementCounter(string name)
            {
                Counter curCounter = GetCounter(name);

                curCounter.count--;
                curCounter.UpdateText();
            }

            public CAXamlDebugCounters()
            {
                //_singleton = this;
            }
        }

        public sealed class CALayerInputHandler
        {
            internal static UIElement rootPane;
            static CALayerXamlInputEvents InputEventHandler;
            static Control DummyFocus;

            static internal void HandleDownInput(CALayerXaml layer, PointerRoutedEventArgs e)
            {
                CALayerXaml rootLayer = layer;
                while (rootLayer.Parent is CALayerXaml)
                {
                    rootLayer = (rootLayer.Parent as CALayerXaml);
                }
                Windows.UI.Input.PointerPoint point = e.GetCurrentPoint(rootLayer);
                InputEventHandler.PointerDown((float)point.Position.X, (float)point.Position.Y, point.PointerId, point.Timestamp);

                if (DummyFocus == null) {
                    DummyFocus = new UserControl();
                    DummyFocus.Width = 0;
                    DummyFocus.Height = 0;
                    DummyFocus.IsTabStop = true;
                    ((Panel)rootLayer.Parent).Children.Add(DummyFocus);
                }
                DummyFocus.Focus(FocusState.Keyboard);
            }

            static internal void HandleUpInput(CALayerXaml layer, PointerRoutedEventArgs e)
            {
                CALayerXaml rootLayer = layer;
                while (rootLayer.Parent is CALayerXaml)
                {
                    rootLayer = (rootLayer.Parent as CALayerXaml);
                }
                Windows.UI.Input.PointerPoint point = e.GetCurrentPoint(rootLayer);
                InputEventHandler.PointerUp((float)point.Position.X, (float)point.Position.Y, point.PointerId, point.Timestamp);
            }

            static internal void HandleMoveInput(CALayerXaml layer, PointerRoutedEventArgs e)
            {
                CALayerXaml rootLayer = layer;
                while (rootLayer.Parent is CALayerXaml)
                {
                    rootLayer = (rootLayer.Parent as CALayerXaml);
                }
                Windows.UI.Input.PointerPoint point = e.GetCurrentPoint(rootLayer);
                InputEventHandler.PointerMoved((float)point.Position.X, (float)point.Position.Y, point.PointerId, point.Timestamp);
            }

            static public void SetInputHandler(CALayerXamlInputEvents handler)
            {
                InputEventHandler = handler;
                Window.Current.CoreWindow.CharacterReceived += CoreWindow_CharacterReceived;
            }

            static void CoreWindow_CharacterReceived(Windows.UI.Core.CoreWindow sender, Windows.UI.Core.CharacterReceivedEventArgs args)
            {
                InputEventHandler.KeyDown((uint)args.KeyCode);
            }
        }

        public interface CacheableObject
        {
            void Reset();
        }

        internal class ObjectCache
        {
            Queue<CacheableObject> _objects = new Queue<CacheableObject>();
            int _maxSize;

            public ObjectCache(int maxSize = 32)
            {
                _maxSize = maxSize;
            }

            public CacheableObject GetCachableObject()
            {
                if (_objects.Count == 0) return null;

                return _objects.Dequeue();
            }

            public void PushCacheableObject(CacheableObject obj)
            {
                obj.Reset();
                if (_objects.Count >= _maxSize) return;
                _objects.Enqueue(obj);
            }
        }

        public sealed class CATextLayerXaml : CacheableObject
        {
            public TextBlock TextBlock
            {
                get
                {
                    return _TextBlock;
                }
            }

            TextBlock _TextBlock = new TextBlock();

            public void Reset()
            {
                TextBlock.Text = "";
                TextBlock.Width = Double.NaN;
                TextBlock.Height = Double.NaN;
            }

            static private ObjectCache _TextLayerCache = new ObjectCache();
            static public CATextLayerXaml CreateTextLayer()
            {
                CacheableObject ret = _TextLayerCache.GetCachableObject();
                if (ret != null)
                {
                    return (CATextLayerXaml)ret;
                }

                return new CATextLayerXaml();
            }

            static public void DestroyTextLayer(CATextLayerXaml content)
            {
                _TextLayerCache.PushCacheableObject(content);
            }
        }

        public enum ContentGravity
        {
            Resize = 0,
            Center,
            Top,
            ResizeAspect,
            TopLeft,
            BottomLeft,
            Left,
            ResizeAspectFill,
            Bottom,
            TopRight,
            Right,
            BottomRight
        }

        public sealed class LayerContent : Panel, CacheableObject
        {
            private Image image;
            private FrameworkElement content;
            private Size imageSize;
            private Size contentSize = new Size(0, 0);
            private Rect contentsCenter = new Rect(0, 0, 1.0, 1.0);
            private ContentGravity gravity;
            private float scaleFactor;
            private Point origin = new Point();

            static private ObjectCache _LayerContentCache = new ObjectCache();

            public void Reset()
            {
                Children.Clear();
                image = null;
                content = null;
                imageSize = new Size(0, 0);
                contentSize = new Size(0, 0);
                contentsCenter = new Rect(0, 0, 1.0, 1.0);
                gravity = ContentGravity.Resize;
                scaleFactor = 1.0f;
                origin = new Point();
            }

            static public LayerContent CreateLayerContent()
            {
                CacheableObject ret = _LayerContentCache.GetCachableObject();
                if (ret != null)
                {
                    return (LayerContent)ret;
                }

                return new LayerContent();
            }

            static public void DestroyLayerContent(LayerContent content)
            {
                _LayerContentCache.PushCacheableObject(content);
            }

            public LayerContent()
            {
                gravity = ContentGravity.Resize;
                scaleFactor = 1.0f;

                CAXamlDebugCounters.IncCounter("LayerContent");
            }

            ~LayerContent()
            {
                CAXamlDebugCounters.DecCounter("LayerContent");
            }

            void ApplyContentsCenter()
            {
                if (image == null)
                {
                    return;
                }
                if (image.Source == null)
                {
                    return;
                }

                if (contentsCenter.X == 0.0 && contentsCenter.Y == 0.0 &&
                     contentsCenter.Width == 1.0 && contentsCenter.Height == 1.0)
                {
                    image.NineGrid = new Thickness(0, 0, 0, 0);
                }
                else
                {
                    int left = (int)(contentsCenter.X * imageSize.Width);
                    int top = (int)(contentsCenter.Y * imageSize.Height);
                    int right = ((int)imageSize.Width) - (left + ((int)(contentsCenter.Width * imageSize.Width)));
                    int bottom = ((int)imageSize.Height) - (top + ((int)(contentsCenter.Height * imageSize.Height)));

                    /*
                    left--;
                    top--;
                    right--;
                    bottom--;
                     */

                    image.NineGrid = new Thickness(left, top, right, bottom);
                }
            }

            Rect GetContentGravityRect(Size size)
            {
                double left = 0, top = 0, width = 0, height = 0;

                //  Top/bottom switched due to geometric origin
                switch (gravity)
                {
                    case ContentGravity.Center:
                        left = size.Width / 2 - contentSize.Width / 2;
                        top = size.Height / 2 - contentSize.Height / 2;
                        width = contentSize.Width;
                        height = contentSize.Height;
                        break;

                    case ContentGravity.Top:
                        left = size.Width / 2 - contentSize.Width / 2;
                        top = size.Height - contentSize.Height;
                        width = contentSize.Width;
                        height = contentSize.Height;
                        break;

                    case ContentGravity.Bottom:
                        left = size.Width / 2 - contentSize.Width / 2;
                        top = 0;
                        width = contentSize.Width;
                        height = contentSize.Height;
                        break;

                    case ContentGravity.Left:
                        left = 0;
                        top = size.Height / 2 - contentSize.Height / 2;
                        width = contentSize.Width;
                        height = contentSize.Height;
                        break;

                    case ContentGravity.Right:
                        left = size.Width - contentSize.Width;
                        top = size.Height / 2 - contentSize.Height / 2;
                        width = contentSize.Width;
                        height = contentSize.Height;
                        break;

                    case ContentGravity.TopLeft:
                        left = 0;
                        top = size.Height - contentSize.Height;
                        width = contentSize.Width;
                        height = contentSize.Height;
                        break;

                    case ContentGravity.TopRight:
                        left = size.Width - contentSize.Width;
                        top = size.Height - contentSize.Height;
                        width = contentSize.Width;
                        height = contentSize.Height;
                        break;

                    case ContentGravity.BottomLeft:
                        left = 0;
                        top = 0;
                        width = contentSize.Width;
                        height = contentSize.Height;
                        break;

                    case ContentGravity.BottomRight:
                        left = size.Width - contentSize.Width;
                        top = 0;
                        width = contentSize.Width;
                        height = contentSize.Height;
                        break;

                    case ContentGravity.Resize:
                        left = 0;
                        top = 0;
                        width = size.Width;
                        height = size.Height;
                        break;

                    case ContentGravity.ResizeAspect:
                        left = 0;
                        top = 0;
                        width = size.Width;
                        height = size.Height;
                        if ( image != null ) image.Stretch = Stretch.Uniform;
                        break;

                    case ContentGravity.ResizeAspectFill:
                        left = 0;
                        top = 0;
                        width = size.Width;
                        height = size.Height;
                        if (image != null) image.Stretch = Stretch.UniformToFill;
                        break;
                }

                return new Rect(left, top, width, height);
            }

            Image GetImage()
            {
                if (image == null)
                {
                    image = new Image();
                    image.Stretch = Stretch.Fill;
                    scaleFactor = 1.0f;
                }

                SetElementContent(image);
                return image;
            }

            public void SetContentsCenter(Rect rect)
            {
                contentsCenter = rect;
                ApplyContentsCenter();
            }

            public void SetGravity(ContentGravity imgGravity)
            {
                gravity = imgGravity;
                InvalidateArrange();
            }

            public void SetImageContent(ImageSource source, int width, int height)
            {
                if (source == null)
                {
                    SetElementContent(null);
                    return;
                }

                var imgContents = GetImage();

                if (source is BitmapSource)
                {
                    imageSize = new Size(width, height);
                }
                else
                {
                    imageSize = new Size(0, 0);
                }
                imgContents.Source = source;

                ApplyContentsCenter();
            }

            internal void AdjustContentOriginX(Storyboard storyboard, DoubleAnimation properties, Object fromValue, Object toValue)
            {
                if (toValue != null)
                {
                    toValue = -((double)toValue);
                    origin.X = (double)toValue;
                }
                if (image != null || content == null) return;
                InvalidateArrange();
            }

            internal void AdjustContentOriginY(Storyboard storyboard, DoubleAnimation properties, Object fromValue, Object toValue)
            {
                if (toValue != null)
                {
                    toValue = -((double)toValue);
                    origin.Y = (double)toValue;
                }
                if (image != null || content == null) return;
                InvalidateArrange();
            }

            public void SetElementContent(FrameworkElement source)
            {
                if (content == source) return;

                if (content != null)
                {
                    Children.Remove(content);
                    content = null;
                    image = null;
                }

                if (source != null)
                {
                    content = source;
                    Children.Add(content);
                    InvalidateArrange();

                    imageSize = new Size(0, 0);
                }
            }

            public void SetImageParams(float width, float height, float scale)
            {
                Size oldSize = contentSize;
                float oldScale = scale;

                contentSize = new Size(width / scale, height / scale);

                if (scaleFactor <= 0.0) scaleFactor = 1.0f;

                if (scaleFactor != scale)
                {
                    scaleFactor = scale;

                    if (image != null)
                    {
                        if (scaleFactor != 1.0f)
                        {
                            ScaleTransform trans = new ScaleTransform();
                            trans.ScaleX = 1.0 / scaleFactor;
                            trans.ScaleY = 1.0 / scaleFactor;
                            image.RenderTransform = trans;
                        }
                        else
                        {
                            image.RenderTransform = null;
                        }
                    }
                }

                if (oldScale != scaleFactor || oldSize != contentSize)
                {
                    InvalidateArrange();
                }
            }

            protected override Size ArrangeOverride(Size finalSize)
            {
                if (content != null)
                {
                    Rect newSize = GetContentGravityRect(finalSize);

                    if (image != null)
                    {
                        content.Width = newSize.Width * scaleFactor;
                        content.Height = newSize.Height * scaleFactor;
                    }
                    else
                    {
                        double contentWidth = newSize.Width - origin.X;
                        double contentHeight = newSize.Height - origin.Y;
                        if (contentWidth < 0.0) contentWidth = 0.0;
                        if (contentHeight < 0.0) contentHeight = 0.0;

                        content.Width = contentWidth;
                        content.Height = contentHeight;
                    }

                    content.Arrange(new Rect(newSize.Left + origin.X, newSize.Top + origin.Y, content.Width, content.Height));
                }

                return finalSize;
            }

            protected override Size MeasureOverride(Size availableSize)
            {
                return availableSize;
            }
        }
    }
}
