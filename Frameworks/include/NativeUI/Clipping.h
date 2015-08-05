//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#pragma once

// Clip code -- used to track each of the 4 possible sides of the clipping rect
// the quad can be off of.  It has some neat properties -- if you and all the clip codes
// together and it's nonzero, you know the quad can be discarded since all 4 points are
// off of one side.  If you or all the clip codes together, you know whether or not you need
// to clip at all.  If you xor one clip code against the next one in a tri fan, then
// you know which of the clipping boundary / boundaries has been crossed.

#define CC_OFF_TOP      0x8
#define CC_OFF_BOTTOM   0x4
#define CC_OFF_LEFT     0x2
#define CC_OFF_RIGHT    0x1

#define CC_NONE         0
#define CC_ALL          (CC_OFF_TOP | CC_OFF_BOTTOM | CC_OFF_LEFT | CC_OFF_RIGHT)

#define CLIP_EPSILON    0.0001f
//#define CLIP_EPSILON  0.000f
#define CLIP_LT(a, b)   ((a) < ((b) - CLIP_EPSILON))
#define CLIP_GT(a, b)   ((a) > ((b) + CLIP_EPSILON))


// This assumes a quad ordered as a tri strip.
inline bool QuadIsAxisAligned(const CAPoint3D *quad)
{
    return (((quad[0].x == quad[1].x) && (quad[0].y == quad[2].y)) ||
            ((quad[0].y == quad[1].y) && (quad[0].x == quad[2].x)));
}

inline int CalcClipCodes(const CGRect *clip, const CAPoint3D& p)
{
    int curCC = CC_NONE;

    if (CLIP_LT(p.y, clip->origin.y)) curCC |= CC_OFF_TOP;
    if (CLIP_GT(p.y, clip->origin.y + clip->size.height)) curCC |= CC_OFF_BOTTOM;
    if (CLIP_LT(p.x, clip->origin.x)) curCC |= CC_OFF_LEFT;
    if (CLIP_GT(p.x, clip->origin.x + clip->size.width)) curCC |= CC_OFF_RIGHT;
        
    return curCC;
}

// Returns # of vertices.  Assumes input is a quad in triangle strip order.  Returns
// clipped quad as a triangle fan.  If no clipping is needed, returns -1.
int QuadClip(const CGRect *clip, const int *clipCodes, int combinedClip,
             CAPoint3D *poly, CGPoint *tex);

