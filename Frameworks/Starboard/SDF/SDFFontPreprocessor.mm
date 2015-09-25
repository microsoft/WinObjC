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

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <tchar.h>
#include <direct.h>

#include <algorithm>

#include "SDFFontPreprocessor.h"

#if USE_SDF_FONTS

#define FONT_GEN_SIZE 256
#define THRESHOLD 127

void SDFFontPreprocessor::init(FT_Face newFace, size_t newFontSize, float newSampleDist) {
    FontGenerator::init(newFace, newFontSize);
    sampleDist = newSampleDist;
}

void SDFFontPreprocessor::renderGlyph(int c) {
    src->renderGlyph(c);
    const CharMatrix& inChar = src->representation();

    int srcw = inChar.width();
    int srch = inChar.height();
    float scale = (float)size() / (float)src->size();
    float invScale = (float)src->size() / (float)size();
    int w = (int)(scale * srcw);
    int h = (int)(scale * srch);
    rep.resize(w, h);

    int sampleDistW = (int)(sampleDist * srcw);
    int sampleDistH = (int)(sampleDist * srch);

    float maxDistance = sqrtf((float)((sampleDistW * sampleDistW) + (sampleDistH * sampleDistH)));

    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            int srcx = (int)(invScale * x);
            int srcy = (int)(invScale * y);

            bool srcOn = inChar(srcx, srcy) > THRESHOLD;

            float minDist = 1.f;

            for (int xx = srcx - sampleDistW; xx < srcx + sampleDistW; xx++) {
                for (int yy = srcy - sampleDistH; yy < srcy + sampleDistH; yy++) {
                    // out of bounds == no good.
                    if ((xx < 0) || (yy < 0) || (xx >= srcw) || (yy >= srch))
                        continue;

                    bool curOn = inChar(xx, yy) > THRESHOLD;
                    if (srcOn == curOn)
                        continue;

                    float dist = sqrtf((float)((xx - srcx) * (xx - srcx) + (yy - srcy) * (yy - srcy)));
                    float distPercent = dist / maxDistance;

                    minDist = std::min(minDist, distPercent);
                }
            }

            if (srcOn) {
                rep(x, y) = (unsigned char)(THRESHOLD * minDist) + THRESHOLD;
            } else {
                rep(x, y) = (unsigned char)(THRESHOLD - (THRESHOLD * minDist));
            }
        }
    }
}

#endif
