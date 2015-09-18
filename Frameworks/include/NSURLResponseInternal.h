#pragma once

@interface NSURLResponse () {
@public
    idretain _url, _mimeType, _textEncodingName;
    int _expectedContentLength;
}
@end