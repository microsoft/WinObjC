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

#include "FontGenerator.h"

void FontGenerator::init(void* mem, FT_Face newFace, size_t newSize) {
    rep.reinit((unsigned char*)mem, 0, 0);
    init(newFace, newSize);
}

void FontGenerator::init(FT_Face newFace, size_t newSize) {
    face = newFace;
    faceSize = newSize;
}
