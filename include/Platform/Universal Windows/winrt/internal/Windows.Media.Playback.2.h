// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Playback.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Media.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
#define WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
template <> struct __declspec(uuid("604d0c4c-91de-5c2a-935f-362f13eaf800")) __declspec(novtable) IReference<Windows::Foundation::TimeSpan> : impl_IReference<Windows::Foundation::TimeSpan> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_deeccfe9_6c01_576f_95f2_93515ae40ebf
#define WINRT_GENERIC_deeccfe9_6c01_576f_95f2_93515ae40ebf
template <> struct __declspec(uuid("deeccfe9-6c01-576f-95f2-93515ae40ebf")) __declspec(novtable) IIterable<Windows::Media::Playback::PlaybackMediaMarker> : impl_IIterable<Windows::Media::Playback::PlaybackMediaMarker> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f1a6a51e_d078_5c40_ba3f_348870ba5c87
#define WINRT_GENERIC_f1a6a51e_d078_5c40_ba3f_348870ba5c87
template <> struct __declspec(uuid("f1a6a51e-d078-5c40-ba3f-348870ba5c87")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_362c45a7_3a0a_5e27_99ce_cff6d1b770e1
#define WINRT_GENERIC_362c45a7_3a0a_5e27_99ce_cff6d1b770e1
template <> struct __declspec(uuid("362c45a7-3a0a-5e27-99ce-cff6d1b770e1")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerFailedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerFailedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_67a4f43c_c254_57f0_a39d_a475a342d21d
#define WINRT_GENERIC_67a4f43c_c254_57f0_a39d_a475a342d21d
template <> struct __declspec(uuid("67a4f43c-c254-57f0-a39d-a475a342d21d")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_ba51d31a_5688_5d4d_af42_122070b1eefa
#define WINRT_GENERIC_ba51d31a_5688_5d4d_af42_122070b1eefa
template <> struct __declspec(uuid("ba51d31a-5688-5d4d-af42-122070b1eefa")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerRateChangedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerRateChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_7c70f38d_2aa1_5522_a6d6_34b52b988ae7
#define WINRT_GENERIC_7c70f38d_2aa1_5522_a6d6_34b52b988ae7
template <> struct __declspec(uuid("7c70f38d-2aa1-5522-a6d6-34b52b988ae7")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_c296f3f9_1268_59a2_b7c3_2f588ed4a017
#define WINRT_GENERIC_c296f3f9_1268_59a2_b7c3_2f588ed4a017
template <> struct __declspec(uuid("c296f3f9-1268-59a2-b7c3-2f588ed4a017")) __declspec(novtable) IVectorView<Windows::Media::Playback::MediaBreak> : impl_IVectorView<Windows::Media::Playback::MediaBreak> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a6954c30_99dc_5f84_b482_7d0692c0277b
#define WINRT_GENERIC_a6954c30_99dc_5f84_b482_7d0692c0277b
template <> struct __declspec(uuid("a6954c30-99dc-5f84-b482-7d0692c0277b")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSeekedOverEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSeekedOverEventArgs> {};
#endif

#ifndef WINRT_GENERIC_4bf2cca1_cd9d_5d88_9e47_1881201bb72d
#define WINRT_GENERIC_4bf2cca1_cd9d_5d88_9e47_1881201bb72d
template <> struct __declspec(uuid("4bf2cca1-cd9d-5d88-9e47-1881201bb72d")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakStartedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakStartedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_04afafa9_d83a_5ccb_8cab_82c9d92a19ab
#define WINRT_GENERIC_04afafa9_d83a_5ccb_8cab_82c9d92a19ab
template <> struct __declspec(uuid("04afafa9-d83a-5ccb-8cab-82c9d92a19ab")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakEndedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakEndedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_c530fa5d_1a56_582a_a254_1b1ae17b8d2d
#define WINRT_GENERIC_c530fa5d_1a56_582a_a254_1b1ae17b8d2d
template <> struct __declspec(uuid("c530fa5d-1a56-582a-a254-1b1ae17b8d2d")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSkippedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSkippedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_078fc818_19f5_5b8a_ac82_25193bea56ee
#define WINRT_GENERIC_078fc818_19f5_5b8a_ac82_25193bea56ee
template <> struct __declspec(uuid("078fc818-19f5-5b8a-ac82-25193bea56ee")) __declspec(novtable) EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> : impl_EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_2675973a_eb2d_56a1_82a0_340b0ff041e6
#define WINRT_GENERIC_2675973a_eb2d_56a1_82a0_340b0ff041e6
template <> struct __declspec(uuid("2675973a-eb2d-56a1-82a0-340b0ff041e6")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_76d59f7c_edf3_5dde_9529_6f806bdb1fcb
#define WINRT_GENERIC_76d59f7c_edf3_5dde_9529_6f806bdb1fcb
template <> struct __declspec(uuid("76d59f7c-edf3-5dde-9529-6f806bdb1fcb")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_79eb2ad3_0781_5f64_b0cd_31e1145d109f
#define WINRT_GENERIC_79eb2ad3_0781_5f64_b0cd_31e1145d109f
template <> struct __declspec(uuid("79eb2ad3-0781-5f64-b0cd-31e1145d109f")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_ce41af40_93a6_52bf_9cad_4d5fffd10ee0
#define WINRT_GENERIC_ce41af40_93a6_52bf_9cad_4d5fffd10ee0
template <> struct __declspec(uuid("ce41af40-93a6-52bf-9cad-4d5fffd10ee0")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_25726db4_8913_5967_90eb_10f09f30dd33
#define WINRT_GENERIC_25726db4_8913_5967_90eb_10f09f30dd33
template <> struct __declspec(uuid("25726db4-8913-5967-90eb-10f09f30dd33")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_d7cd6ce3_516f_5b34_beaf_3ee90b622872
#define WINRT_GENERIC_d7cd6ce3_516f_5b34_beaf_3ee90b622872
template <> struct __declspec(uuid("d7cd6ce3-516f-5b34-beaf-3ee90b622872")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_3c37e026_8d0b_5d73_a650_9f18abbc353d
#define WINRT_GENERIC_3c37e026_8d0b_5d73_a650_9f18abbc353d
template <> struct __declspec(uuid("3c37e026-8d0b-5d73-a650-9f18abbc353d")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_6c972f91_f626_5799_ba86_5e941f0202c8
#define WINRT_GENERIC_6c972f91_f626_5799_ba86_5e941f0202c8
template <> struct __declspec(uuid("6c972f91-f626-5799-ba86-5e941f0202c8")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_824845b8_c5df_560b_a722_c15b25d4463a
#define WINRT_GENERIC_824845b8_c5df_560b_a722_c15b25d4463a
template <> struct __declspec(uuid("824845b8-c5df-560b-a722-c15b25d4463a")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_d863b1c4_7442_53c4_94d2_20d8973df585
#define WINRT_GENERIC_d863b1c4_7442_53c4_94d2_20d8973df585
template <> struct __declspec(uuid("d863b1c4-7442-53c4-94d2-20d8973df585")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_3f8a8ea1_ff9a_5613_9846_33799f6b8c8a
#define WINRT_GENERIC_3f8a8ea1_ff9a_5613_9846_33799f6b8c8a
template <> struct __declspec(uuid("3f8a8ea1-ff9a-5613-9846-33799f6b8c8a")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_0313ae7a_2803_5d45_b5a1_a0fc5cd55e7c
#define WINRT_GENERIC_0313ae7a_2803_5d45_b5a1_a0fc5cd55e7c
template <> struct __declspec(uuid("0313ae7a-2803-5d45-b5a1-a0fc5cd55e7c")) __declspec(novtable) IVectorView<Windows::Media::Core::TimedMetadataTrack> : impl_IVectorView<Windows::Media::Core::TimedMetadataTrack> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_2dd51918_4525_5be5_a6c1_409bc72863a6
#define WINRT_GENERIC_2dd51918_4525_5be5_a6c1_409bc72863a6
template <> struct __declspec(uuid("2dd51918-4525-5be5-a6c1-409bc72863a6")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e71ffa4a_14a7_5068_891c_6e717af8bf8d
#define WINRT_GENERIC_e71ffa4a_14a7_5068_891c_6e717af8bf8d
template <> struct __declspec(uuid("e71ffa4a-14a7-5068-891c-6e717af8bf8d")) __declspec(novtable) IVectorView<Windows::Media::Core::AudioTrack> : impl_IVectorView<Windows::Media::Core::AudioTrack> {};
#endif

#ifndef WINRT_GENERIC_b3be50a8_9856_5656_ab6d_cd58f9de0a4f
#define WINRT_GENERIC_b3be50a8_9856_5656_ab6d_cd58f9de0a4f
template <> struct __declspec(uuid("b3be50a8-9856-5656-ab6d-cd58f9de0a4f")) __declspec(novtable) IIterable<Windows::Media::Core::AudioTrack> : impl_IIterable<Windows::Media::Core::AudioTrack> {};
#endif

#ifndef WINRT_GENERIC_200c6224_0b43_54fb_995f_fd8688bf24de
#define WINRT_GENERIC_200c6224_0b43_54fb_995f_fd8688bf24de
template <> struct __declspec(uuid("200c6224-0b43-54fb-995f-fd8688bf24de")) __declspec(novtable) IVectorView<Windows::Media::Core::VideoTrack> : impl_IVectorView<Windows::Media::Core::VideoTrack> {};
#endif

#ifndef WINRT_GENERIC_84413442_a2e3_5e0f_936d_bc40b0fb2dcd
#define WINRT_GENERIC_84413442_a2e3_5e0f_936d_bc40b0fb2dcd
template <> struct __declspec(uuid("84413442-a2e3-5e0f-936d-bc40b0fb2dcd")) __declspec(novtable) IIterable<Windows::Media::Core::VideoTrack> : impl_IIterable<Windows::Media::Core::VideoTrack> {};
#endif

#ifndef WINRT_GENERIC_150a4454_03bb_5dd1_8153_6a600e851f71
#define WINRT_GENERIC_150a4454_03bb_5dd1_8153_6a600e851f71
template <> struct __declspec(uuid("150a4454-03bb-5dd1-8153-6a600e851f71")) __declspec(novtable) IIterable<Windows::Media::Core::TimedMetadataTrack> : impl_IIterable<Windows::Media::Core::TimedMetadataTrack> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3c57acbf_ca07_586a_8adb_8047dc9165a6
#define WINRT_GENERIC_3c57acbf_ca07_586a_8adb_8047dc9165a6
template <> struct __declspec(uuid("3c57acbf-ca07-586a-8adb-8047dc9165a6")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaBreakSchedule, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Media::Playback::MediaBreakSchedule, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_23319e7d_34b1_57b7_97e5_844948ba4719
#define WINRT_GENERIC_23319e7d_34b1_57b7_97e5_844948ba4719
template <> struct __declspec(uuid("23319e7d-34b1-57b7-97e5-844948ba4719")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemFailedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemFailedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_404c5f9d_250d_5f8c_9627_6b4105c32d09
#define WINRT_GENERIC_404c5f9d_250d_5f8c_9627_6b4105c32d09
template <> struct __declspec(uuid("404c5f9d-250d-5f8c-9627-6b4105c32d09")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_6732bbef_3311_5f83_9c9d_82a5cf3cd82a
#define WINRT_GENERIC_6732bbef_3311_5f83_9c9d_82a5cf3cd82a
template <> struct __declspec(uuid("6732bbef-3311-5f83-9c9d-82a5cf3cd82a")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fabf4843_39eb_5c3d_a12b_fca189b46e8e
#define WINRT_GENERIC_fabf4843_39eb_5c3d_a12b_fca189b46e8e
template <> struct __declspec(uuid("fabf4843-39eb-5c3d-a12b-fca189b46e8e")) __declspec(novtable) IObservableVector<Windows::Media::Playback::MediaPlaybackItem> : impl_IObservableVector<Windows::Media::Playback::MediaPlaybackItem> {};
#endif

#ifndef WINRT_GENERIC_b6a4c9fe_c73d_5eba_b5ab_6f8deaca30b9
#define WINRT_GENERIC_b6a4c9fe_c73d_5eba_b5ab_6f8deaca30b9
template <> struct __declspec(uuid("b6a4c9fe-c73d-5eba-b5ab-6f8deaca30b9")) __declspec(novtable) IVectorView<Windows::Media::Playback::MediaPlaybackItem> : impl_IVectorView<Windows::Media::Playback::MediaPlaybackItem> {};
#endif

#ifndef WINRT_GENERIC_8b8ab4a4_0253_56e9_a232_94e335aefa8f
#define WINRT_GENERIC_8b8ab4a4_0253_56e9_a232_94e335aefa8f
template <> struct __declspec(uuid("8b8ab4a4-0253-56e9-a232-94e335aefa8f")) __declspec(novtable) IIterable<Windows::Media::Playback::MediaPlaybackItem> : impl_IIterable<Windows::Media::Playback::MediaPlaybackItem> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_40213c85_bf23_5f78_b9c4_e03f3be2b41c
#define WINRT_GENERIC_40213c85_bf23_5f78_b9c4_e03f3be2b41c
template <> struct __declspec(uuid("40213c85-bf23-5f78-b9c4-e03f3be2b41c")) __declspec(novtable) TypedEventHandler<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> : impl_TypedEventHandler<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_28607d6b_daa4_5eef_9f81_cc08a8297182
#define WINRT_GENERIC_28607d6b_daa4_5eef_9f81_cc08a8297182
template <> struct __declspec(uuid("28607d6b-daa4-5eef-9f81-cc08a8297182")) __declspec(novtable) IIterator<Windows::Media::Playback::PlaybackMediaMarker> : impl_IIterator<Windows::Media::Playback::PlaybackMediaMarker> {};
#endif

#ifndef WINRT_GENERIC_9efd8746_f93c_524f_9f95_4b598acf8d25
#define WINRT_GENERIC_9efd8746_f93c_524f_9f95_4b598acf8d25
template <> struct __declspec(uuid("9efd8746-f93c-524f-9f95-4b598acf8d25")) __declspec(novtable) IIterator<Windows::Media::Playback::MediaBreak> : impl_IIterator<Windows::Media::Playback::MediaBreak> {};
#endif

#ifndef WINRT_GENERIC_04f000ec_c727_5dc0_9f7c_245c75c92f2f
#define WINRT_GENERIC_04f000ec_c727_5dc0_9f7c_245c75c92f2f
template <> struct __declspec(uuid("04f000ec-c727-5dc0-9f7c-245c75c92f2f")) __declspec(novtable) IIterable<Windows::Media::Playback::MediaBreak> : impl_IIterable<Windows::Media::Playback::MediaBreak> {};
#endif

#ifndef WINRT_GENERIC_859354e5_077b_5d53_b297_1a07b97f09c3
#define WINRT_GENERIC_859354e5_077b_5d53_b297_1a07b97f09c3
template <> struct __declspec(uuid("859354e5-077b-5d53-b297-1a07b97f09c3")) __declspec(novtable) IIterator<Windows::Media::Core::TimedMetadataTrack> : impl_IIterator<Windows::Media::Core::TimedMetadataTrack> {};
#endif

#ifndef WINRT_GENERIC_138064ef_8693_5303_8a75_eba494d06342
#define WINRT_GENERIC_138064ef_8693_5303_8a75_eba494d06342
template <> struct __declspec(uuid("138064ef-8693-5303-8a75-eba494d06342")) __declspec(novtable) IIterator<Windows::Media::Core::AudioTrack> : impl_IIterator<Windows::Media::Core::AudioTrack> {};
#endif

#ifndef WINRT_GENERIC_a7c8d22c_b59d_5d7a_8d70_67f898a0b877
#define WINRT_GENERIC_a7c8d22c_b59d_5d7a_8d70_67f898a0b877
template <> struct __declspec(uuid("a7c8d22c-b59d-5d7a-8d70-67f898a0b877")) __declspec(novtable) IIterator<Windows::Media::Core::VideoTrack> : impl_IIterator<Windows::Media::Core::VideoTrack> {};
#endif

#ifndef WINRT_GENERIC_891bddde_6bf3_5d1f_80ab_5a342a16a0bb
#define WINRT_GENERIC_891bddde_6bf3_5d1f_80ab_5a342a16a0bb
template <> struct __declspec(uuid("891bddde-6bf3-5d1f-80ab-5a342a16a0bb")) __declspec(novtable) VectorChangedEventHandler<Windows::Media::Playback::MediaPlaybackItem> : impl_VectorChangedEventHandler<Windows::Media::Playback::MediaPlaybackItem> {};
#endif

#ifndef WINRT_GENERIC_ab074059_8c08_53e7_9654_02d2598fff55
#define WINRT_GENERIC_ab074059_8c08_53e7_9654_02d2598fff55
template <> struct __declspec(uuid("ab074059-8c08-53e7-9654-02d2598fff55")) __declspec(novtable) IIterator<Windows::Media::Playback::MediaPlaybackItem> : impl_IIterator<Windows::Media::Playback::MediaPlaybackItem> {};
#endif

#ifndef WINRT_GENERIC_e1504f46_c4a6_5a29_8fc9_a934d12d7242
#define WINRT_GENERIC_e1504f46_c4a6_5a29_8fc9_a934d12d7242
template <> struct __declspec(uuid("e1504f46-c4a6-5a29-8fc9-a934d12d7242")) __declspec(novtable) IVector<Windows::Media::Playback::MediaPlaybackItem> : impl_IVector<Windows::Media::Playback::MediaPlaybackItem> {};
#endif


}

namespace Windows::Media::Playback {

struct IBackgroundMediaPlayerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IBackgroundMediaPlayerStatics>
{
    IBackgroundMediaPlayerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentMediaPlaybackItemChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentMediaPlaybackItemChangedEventArgs>
{
    ICurrentMediaPlaybackItemChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaBreak :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaBreak>
{
    IMediaBreak(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaBreakEndedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaBreakEndedEventArgs>
{
    IMediaBreakEndedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaBreakFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaBreakFactory>
{
    IMediaBreakFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaBreakManager :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaBreakManager>
{
    IMediaBreakManager(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaBreakSchedule :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaBreakSchedule>
{
    IMediaBreakSchedule(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaBreakSeekedOverEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaBreakSeekedOverEventArgs>
{
    IMediaBreakSeekedOverEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaBreakSkippedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaBreakSkippedEventArgs>
{
    IMediaBreakSkippedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaBreakStartedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaBreakStartedEventArgs>
{
    IMediaBreakStartedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct [[deprecated("Use MediaPlayer instead of MediaEngine. For more info, see MSDN.")]] IMediaEnginePlaybackSource :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaEnginePlaybackSource>
{
    IMediaEnginePlaybackSource(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaItemDisplayProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaItemDisplayProperties>
{
    IMediaItemDisplayProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManager :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManager>
{
    IMediaPlaybackCommandManager(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>
{
    IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerCommandBehavior :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerCommandBehavior>
{
    IMediaPlaybackCommandManagerCommandBehavior(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerFastForwardReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerFastForwardReceivedEventArgs>
{
    IMediaPlaybackCommandManagerFastForwardReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerNextReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerNextReceivedEventArgs>
{
    IMediaPlaybackCommandManagerNextReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerPauseReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerPauseReceivedEventArgs>
{
    IMediaPlaybackCommandManagerPauseReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerPlayReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerPlayReceivedEventArgs>
{
    IMediaPlaybackCommandManagerPlayReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerPositionReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerPositionReceivedEventArgs>
{
    IMediaPlaybackCommandManagerPositionReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerPreviousReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerPreviousReceivedEventArgs>
{
    IMediaPlaybackCommandManagerPreviousReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerRateReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerRateReceivedEventArgs>
{
    IMediaPlaybackCommandManagerRateReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerRewindReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerRewindReceivedEventArgs>
{
    IMediaPlaybackCommandManagerRewindReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackCommandManagerShuffleReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackCommandManagerShuffleReceivedEventArgs>
{
    IMediaPlaybackCommandManagerShuffleReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackItem :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackItem>,
    impl::require<IMediaPlaybackItem, Windows::Media::Playback::IMediaPlaybackSource>
{
    IMediaPlaybackItem(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackItem2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackItem2>,
    impl::require<IMediaPlaybackItem2, Windows::Media::Playback::IMediaPlaybackItem, Windows::Media::Playback::IMediaPlaybackSource>
{
    IMediaPlaybackItem2(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackItemError :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackItemError>
{
    IMediaPlaybackItemError(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackItemFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackItemFactory>
{
    IMediaPlaybackItemFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackItemFactory2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackItemFactory2>,
    impl::require<IMediaPlaybackItemFactory2, Windows::Media::Playback::IMediaPlaybackItemFactory>
{
    IMediaPlaybackItemFactory2(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackItemFailedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackItemFailedEventArgs>
{
    IMediaPlaybackItemFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackItemOpenedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackItemOpenedEventArgs>
{
    IMediaPlaybackItemOpenedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackItemStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackItemStatics>
{
    IMediaPlaybackItemStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackList :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackList>,
    impl::require<IMediaPlaybackList, Windows::Media::Playback::IMediaPlaybackSource>
{
    IMediaPlaybackList(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackList2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackList2>,
    impl::require<IMediaPlaybackList2, Windows::Media::Playback::IMediaPlaybackList, Windows::Media::Playback::IMediaPlaybackSource>
{
    IMediaPlaybackList2(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackSession :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackSession>
{
    IMediaPlaybackSession(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackSource :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackSource>
{
    IMediaPlaybackSource(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlaybackTimedMetadataTrackList :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlaybackTimedMetadataTrackList>
{
    IMediaPlaybackTimedMetadataTrackList(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayer :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayer>
{
    IMediaPlayer(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayer2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayer2>
{
    IMediaPlayer2(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayer3 :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayer3>
{
    IMediaPlayer3(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayer4 :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayer4>
{
    IMediaPlayer4(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayerDataReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayerDataReceivedEventArgs>
{
    IMediaPlayerDataReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayerEffects :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayerEffects>
{
    IMediaPlayerEffects(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayerEffects2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayerEffects2>
{
    IMediaPlayerEffects2(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayerFailedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayerFailedEventArgs>
{
    IMediaPlayerFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayerRateChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayerRateChangedEventArgs>
{
    IMediaPlayerRateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayerSource :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayerSource>
{
    IMediaPlayerSource(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayerSource2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayerSource2>
{
    IMediaPlayerSource2(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaPlayerSurface :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaPlayerSurface>
{
    IMediaPlayerSurface(std::nullptr_t = nullptr) noexcept {}
};

struct IPlaybackMediaMarker :
    Windows::Foundation::IInspectable,
    impl::consume<IPlaybackMediaMarker>
{
    IPlaybackMediaMarker(std::nullptr_t = nullptr) noexcept {}
};

struct IPlaybackMediaMarkerFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPlaybackMediaMarkerFactory>
{
    IPlaybackMediaMarkerFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPlaybackMediaMarkerReachedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPlaybackMediaMarkerReachedEventArgs>
{
    IPlaybackMediaMarkerReachedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPlaybackMediaMarkerSequence :
    Windows::Foundation::IInspectable,
    impl::consume<IPlaybackMediaMarkerSequence>,
    impl::require<IPlaybackMediaMarkerSequence, Windows::Foundation::Collections::IIterable<Windows::Media::Playback::PlaybackMediaMarker>>
{
    IPlaybackMediaMarkerSequence(std::nullptr_t = nullptr) noexcept {}
};

struct ITimedMetadataPresentationModeChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ITimedMetadataPresentationModeChangedEventArgs>
{
    ITimedMetadataPresentationModeChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
