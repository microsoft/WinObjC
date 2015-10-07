#ifndef _CTFRAME_H_
#define _CTFRAME_H_

#import <CoreFoundation/CFBase.h>
#import <CoreText/CoreTextExport.h>
#import <CoreGraphics/CGContext.h>

ENABLE_IMPLICIT_BRIDGING

typedef struct __CTFrame *CTFrameRef;

CORETEXT_EXPORT CFArrayRef CTFrameGetLines(CTFrameRef frame);
CORETEXT_EXPORT void CTFrameGetLineOrigins(CTFrameRef frame, CFRange range, CGPoint origins[]);
CORETEXT_EXPORT void CTFrameDraw(CTFrameRef frame, CGContextRef context);

DISABLE_IMPLICIT_BRIDGING

#endif // _CTFRAME_H_