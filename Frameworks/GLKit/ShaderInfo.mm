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

#import <Starboard.h>
#include "ShaderInfo.h"

void ShaderMaterial::addvar(const string& var, float* data, int size)
{
    assert((size & 3) == 0);
    assert(vars.find(var) == vars.end());
    
    VarInfo v;
    v.loc = values.size();
    v.size = size / 4;

    for(int i = 0; i < size; i ++) {
        values.push_back(data[i]);
    }
    vars[var] = v;
}

void ShaderMaterial::addtex(const string& var, GLuint name)
{
    assert(vars.find(var) == vars.end());

    VarInfo v;
    v.texture = true;
    v.loc = name;
    v.size = 0;

    vars[var] = v;
}
