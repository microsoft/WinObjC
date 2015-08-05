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

#include "Starboard.h"
#include "NativeUI/Clipping.h"

#include <algorithm>
#include <string.h>

inline bool ClipLine(CAPoint3D *out, CGPoint *outUV, const CAPoint3D &p1, const CAPoint3D &p2,
              const CGPoint &uv1, const CGPoint &uv2, float val1, float val2, float dividePt)
{
    CAPoint3D dir = p2 - p1;
    CGPoint dirUV = uv2 - uv1;
    
    float magn = val2 - val1;
    float blendPt = dividePt - val1;
    
    if (fabsf(magn) < 0.00001f) { // If they're both too close pretend nothing bad happened.
        *out = p2;
        *outUV = uv2;
    } else {
        float blend = blendPt / magn;
        if (blend <= 0.f || blend > 1.f) return false;
        
        *out = p1 + blend * dir;
        *outUV = uv1 + dirUV * blend;
    }
    
    return true;
}

inline void GetBlendFactors(float &val1, float &val2, float &blendPt, int region,
                            const CAPoint3D &p1, const CAPoint3D &p2, const CGRect *clip)
{
    switch (region)
    {
        case 0: // CC_OFF_RIGHT
            val1 = p1.x;
            val2 = p2.x;
            blendPt = clip->origin.x + clip->size.width;
            break;
            
        case 1: // CC_OFF_LEFT
            val1 = p1.x;
            val2 = p2.x;
            blendPt = clip->origin.x;           
            break;
            
        case 2: // CC_OFF_BOTTOM
            val1 = p1.y;
            val2 = p2.y;
            blendPt = clip->origin.y + clip->size.height;
            break;
            
        case 3: // CC_OFF_TOP
            val1 = p1.y;
            val2 = p2.y;
            blendPt = clip->origin.y;           
            break;          
    }
}

int QuadClip(const CGRect *clip, const int *clipCodes, int combinedClip,
             CAPoint3D *poly, CGPoint *tex)
{
    static const int indicesAsFan[] = { 0, 1, 3, 2 };     // for converting the quad strip to a poly.

    CAPoint3D tempVerts[16];
    CGPoint tempUVs[16];
    int tempCC[16];
    CAPoint3D tempVerts2[16];
    CGPoint tempUVs2[16];
    int tempCC2[16];

    if (tex) {
        for (int i = 0; i < 4; i ++) {
            tempVerts[i] = poly[indicesAsFan[i]];
            tempUVs[i] = tex[indicesAsFan[i]];
            tempCC[i] = clipCodes[indicesAsFan[i]];
        }
    } else {
        for (int i = 0; i < 4; i ++) {
            tempVerts[i] = poly[indicesAsFan[i]];
            tempCC[i] = clipCodes[indicesAsFan[i]];
        }
    }
    
    int numIn = 4;
    CAPoint3D *curIn = tempVerts;
    CGPoint *curUVIn = tempUVs;
    int *curCC = tempCC;
    
    int numOut;
    CAPoint3D *out = tempVerts2;
    CGPoint *outUV = tempUVs2;
    int *outCC = tempCC2;

    // Clip once for each plane.
    for (int region = 0; region < 4; region ++) {
        int regShift = 1 << region;
        if (!(combinedClip & regShift)) continue;

        numOut = 0;     
        for (int i = 0, pi = numIn - 1; i < numIn; pi = i, i ++) {

            int prevOut = curCC[pi] & regShift;
            int curOut = curCC[i] & regShift;

            // both are off one clip region, trivial reject.
            if (prevOut && curOut) continue;
        
            // both are in clip region, trivial accept.
            if (!prevOut && !curOut) {
                out[numOut] = curIn[i];
                if (tex) outUV[numOut] = curUVIn[i];
                outCC[numOut] = curCC[i] & (~regShift);
                numOut ++;
                continue;
            }

            float prevVal, curVal, blendPt;
            GetBlendFactors(prevVal, curVal, blendPt, region, curIn[pi], curIn[i], clip);

            if (!curOut) {

                // Out -> in case.  
                bool res = ClipLine(out + numOut, outUV + numOut, curIn[pi], curIn[i],
                                    curUVIn[pi], curUVIn[i], prevVal, curVal, blendPt);
                if(res) {
                    outCC[numOut] = CalcClipCodes(clip, out[numOut]);
                    numOut ++;
                }

                out[numOut] = curIn[i];
                if (tex) outUV[numOut] = curUVIn[i];
                outCC[numOut] = curCC[i];
                numOut ++;              
            } else {

                // In -> Out case.
                bool res = ClipLine(out + numOut, outUV + numOut, curIn[pi], curIn[i],
                                    curUVIn[pi], curUVIn[i], prevVal, curVal, blendPt);
                if(res) {
                    outCC[numOut] = CalcClipCodes(clip, out[numOut]);
                    numOut ++;
                }
            }
        }

        std::swap(numIn, numOut);
        std::swap(curIn, out);
        std::swap(curUVIn, outUV);
        std::swap(curCC, outCC);
    }   
    
    if (numIn <= 2) return 0;

    memcpy(poly, curIn, numIn * sizeof(CAPoint3D));
    if (tex) memcpy(tex, curUVIn, numIn * sizeof(CGPoint));
    
    return numIn;
}
