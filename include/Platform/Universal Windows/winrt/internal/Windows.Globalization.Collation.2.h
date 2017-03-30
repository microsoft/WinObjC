// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.Collation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f7cf5a4a_2b7a_5bc9_a0c4_9dce07ff61c9
#define WINRT_GENERIC_f7cf5a4a_2b7a_5bc9_a0c4_9dce07ff61c9
template <> struct __declspec(uuid("f7cf5a4a-2b7a-5bc9-a0c4-9dce07ff61c9")) __declspec(novtable) IVectorView<Windows::Globalization::Collation::CharacterGrouping> : impl_IVectorView<Windows::Globalization::Collation::CharacterGrouping> {};
#endif

#ifndef WINRT_GENERIC_82e3abf0_06e3_5609_ba39_c51eb2f5fae6
#define WINRT_GENERIC_82e3abf0_06e3_5609_ba39_c51eb2f5fae6
template <> struct __declspec(uuid("82e3abf0-06e3-5609-ba39-c51eb2f5fae6")) __declspec(novtable) IIterable<Windows::Globalization::Collation::CharacterGrouping> : impl_IIterable<Windows::Globalization::Collation::CharacterGrouping> {};
#endif

#ifndef WINRT_GENERIC_57e89bbc_9220_5df2_844b_ddfe6605db5f
#define WINRT_GENERIC_57e89bbc_9220_5df2_844b_ddfe6605db5f
template <> struct __declspec(uuid("57e89bbc-9220-5df2-844b-ddfe6605db5f")) __declspec(novtable) IIterator<Windows::Globalization::Collation::CharacterGrouping> : impl_IIterator<Windows::Globalization::Collation::CharacterGrouping> {};
#endif


}

namespace Windows::Globalization::Collation {

struct ICharacterGrouping :
    Windows::Foundation::IInspectable,
    impl::consume<ICharacterGrouping>
{
    ICharacterGrouping(std::nullptr_t = nullptr) noexcept {}
};

struct ICharacterGroupings :
    Windows::Foundation::IInspectable,
    impl::consume<ICharacterGroupings>,
    impl::require<ICharacterGroupings, Windows::Foundation::Collections::IIterable<Windows::Globalization::Collation::CharacterGrouping>, Windows::Foundation::Collections::IVectorView<Windows::Globalization::Collation::CharacterGrouping>>
{
    ICharacterGroupings(std::nullptr_t = nullptr) noexcept {}
};

}

}
