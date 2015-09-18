#pragma once

struct CAMediaTimingProperties
{
    BOOL _removedOnCompletion;
    double _beginTime, _duration, _timeOffset, _delay, _speed;
    BOOL _autoReverses;
    float _repeatCount;
    double _repeatDuration;
    __unsafe_unretained id _timingFunction;
    enum CAMediaFillMode _fillMode;
};

@interface CAAnimation () {
@public
    CAMediaTimingProperties _timingProperties;
    DisplayAnimation        *_runningAnimation, *_runningAnimation2;
    id                      _attachedLayer;
    idretaintype(NSString)  _keyName;
}
@end