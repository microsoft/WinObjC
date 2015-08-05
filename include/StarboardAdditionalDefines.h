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

#ifndef __STARBOARD_ADDITIONAL_DEFINES
#define __STARBOARD_ADDITIONAL_DEFINES

#define TARGET_IPHONE_SIMULATOR 1   //  Temporary for Cocos2D compat, for now

#ifndef M_PI
 #define M_PI        3.14159265358979323846264338327950288   /* pi */
#endif
#ifndef M_PI_2
 #define M_PI_2      1.57079632679489661923132169163975144   /* pi/2 */
#endif

#ifndef M_PI_4
 #define M_PI_4      0.785398163397448309615660845819875721  /* pi/4 */
#endif

enum {
    noErr = 0
};

typedef unsigned int uint;

#ifdef __cplusplus
extern "C" {
#endif

uint arc4random(void);
unsigned random(void);

#ifdef __cplusplus
}
#endif

#endif