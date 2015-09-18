#pragma once

@interface NSStream () {
@public
    unsigned _status;
    struct EbrFile *fp;
    idretain _data;
}
@end