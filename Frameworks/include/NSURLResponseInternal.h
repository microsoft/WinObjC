#pragma once

@interface NSURLResponse () {
@public
    idretain _mimeType, _textEncodingName, _HTTPVersion, _url;
    int _expectedContentLength;
}
@end