// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Web.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Web {

struct WebError
{
    WebError() = delete;
    static Windows::Web::WebErrorStatus GetStatus(int32_t hresult);
};

}

}
