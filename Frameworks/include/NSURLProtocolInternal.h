
@interface NSURLProtocol () {
@public
    idretaintype(NSURLRequest) _request;
    id _cachedResponse;
    id _client;
}
@end