#pragma once

@interface NSURLRequest () {
@public
    idretain _url;
    double _timeoutInterval;
    idretain _method;
    idretain _body;
    idretain _bodyStream;
    id _headerFields;
    bool _shouldHandleCookies;
    NSURLRequestCachePolicy _cachePolicy;
}
@end