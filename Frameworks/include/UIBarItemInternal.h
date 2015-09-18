#pragma once

@interface UIBarItem () {
@public
    NSInteger _tag;
    idretaintype(UIImage) _image;
    BOOL _isDisabled, _enabled; // fixme
}
@end