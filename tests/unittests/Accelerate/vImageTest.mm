//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#include "gtest-api.h"
#import <Foundation/Foundation.h>
#import <Accelerate/Accelerate.h>
#import <CoreGraphics/CGImage.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#import "Starboard/SmartTypes.h"
#import "CALayerInternal.h"
#import "../UIKit/NullCompositor.h"

vImage_Buffer src, dest;
vImage_Error Error;
Pixel_8888 background = {10, 20, 30, 40};
uint8_t output[10][10][4];
uint8_t input[10][10][4] = {
    { {232, 19, 158, 38} , {175, 197, 114, 68} , {188, 109, 120, 80} , {102, 47, 102, 143} , {142, 79, 160, 52} , 
      {3, 124, 114, 32} , {70, 18, 189, 123} , {116, 190, 247, 56} , {17, 157, 230, 3} , {139, 79, 204, 66} },
    { {22, 167, 208, 141} , {155, 125, 158, 16} , {54, 157, 56, 53} , {118, 49, 163, 35} , {84, 116, 30, 193} , 
      {22, 211, 24, 89} , {251, 223, 42, 123} , {228, 43, 13, 211} , {160, 178, 15, 154} , {233, 126, 200, 14} },
    { {30, 19, 234, 106} , {32, 185, 15, 104} , {6, 228, 183, 173} , {125, 202, 177, 131} , {16, 162, 158, 159} , 
      {216, 57, 71, 143} , {122, 143, 112, 87} , {189, 144, 239, 236} , {95, 180, 30, 98} , {232, 214, 53, 197} },
    { {135, 82, 39, 148} , {205, 228, 83, 235} , {181, 162, 217, 40} , {97, 52, 67, 171} , {90, 217, 201, 56} , 
      {80, 186, 53, 12} , {76, 140, 215, 199} , {170, 121, 47, 13} , {0, 39, 144, 8} , {4, 80, 190, 216} },
    { {123, 146, 8, 155} , {183, 109, 225, 194} , {46, 19, 206, 189} , {163, 213, 34, 70} , {185, 39, 238, 87} , 
      {40, 232, 122, 39} , {47, 60, 46, 190} , {208, 250, 209, 173} , {145, 180, 180, 44} , {67, 206, 69, 192} },
    { {219, 115, 68, 101} , {87, 180, 76, 218} , {74, 187, 198, 37} , {140, 95, 122, 36} , {213, 172, 196, 195} , 
      {10, 203, 125, 126} , {72, 4, 64, 186} , {51, 121, 202, 80} , {29, 79, 245, 189} , {142, 75, 238, 239} },
    { {230, 205, 0, 231} , {63, 217, 101, 208} , {204, 96, 39, 128} , {123, 227, 126, 39} , {63, 206, 216, 199} , 
      {29, 190, 44, 165} , {79, 13, 19, 85} , {222, 165, 237, 0} , {185, 41, 44, 87} , {3, 84, 65, 15} },
    { {241, 167, 79, 177} , {239, 251, 223, 225} , {83, 209, 249, 214} , {228, 253, 167, 162} , {188, 197, 165, 141} , 
      {248, 19, 25, 206} , {75, 24, 140, 90} , {226, 173, 195, 138} , {227, 71, 248, 126} , {77, 196, 38, 144} },
    { {219, 12, 68, 56} , {220, 157, 193, 212} , {66, 158, 114, 63} , {132, 139, 48, 90} , {169, 245, 250, 162} , 
      {65, 70, 120, 156} , {112, 38, 180, 241} , {190, 117, 158, 74} , {158, 125, 174, 208} , {177, 30, 159, 130} },
    { {128, 72, 127, 148} , {214, 177, 72, 74} , {75, 93, 108, 33} , {138, 250, 173, 49} , {96, 170, 14, 237} , 
      {228, 28, 102, 130} , {30, 111, 160, 103} , {215, 250, 183, 203} , {203, 146, 10, 94} , {155, 184, 212, 184} }
    };

static void vImageInit(void) {
    src.data = input;
    src.height = 10;
    src.width = 10;
    src.rowBytes = src.width*4;

    dest.data = output;
    dest.width = 10;
    dest.height = 10;
    dest.rowBytes = dest.width*4;
}

TEST(Accelerate, BoxConvolve) {
    vImageInit();

    Error =  vImageBoxConvolve_ARGB8888(&src, &dest, NULL, 0, 0, 5, 5, NULL, kvImageCopyInPlace);
    uint8_t kvICiP_Expected [10][10][4] = {
    { {232, 19, 158, 38} , {175, 197, 114, 68} , {188, 109, 120, 80} , {102, 47, 102, 143} , {142, 79, 160, 52} , 
      {3, 124, 114, 32} , {70, 18, 189, 123} , {116, 190, 247, 56} , {17, 157, 230, 3} , {139, 79, 204, 66} },
    { {22, 167, 208, 141} , {155, 125, 158, 16} , {54, 157, 56, 53} , {118, 49, 163, 35} , {84, 116, 30, 193} , 
      {22, 211, 24, 89} , {251, 223, 42, 123} , {228, 43, 13, 211} , {160, 178, 15, 154} , {233, 126, 200, 14} },
    { {30, 19, 234, 106} , {32, 185, 15, 104} , {116, 125, 134, 113} , {108, 140, 124, 103} , {101, 130, 124, 107} , 
      {118, 133, 123, 113} , {111, 140, 125, 103} , {117, 143, 122, 109} , {95, 180, 30, 98} , {232, 214, 53, 197} },
    { {135, 82, 39, 148} , {205, 228, 83, 235} , {111, 137, 134, 122} , {105, 151, 128, 112} , {101, 141, 125, 113} , 
      {121, 138, 119, 122} , {112, 140, 121, 124} , {116, 140, 118, 130} , {0, 39, 144, 8} , {4, 80, 190, 216} },
    { {123, 146, 8, 155} , {183, 109, 225, 194} , {121, 151, 129, 136} , {107, 163, 132, 126} , {100, 140, 130, 118} , 
      {113, 145, 134, 115} , {105, 134, 138, 114} , {101, 128, 123, 121} , {145, 180, 180, 44} , {67, 206, 69, 192} },
    { {219, 115, 68, 101} , {87, 180, 76, 218} , {152, 162, 134, 146} , {130, 166, 141, 136} , {113, 137, 132, 122} , 
      {125, 143, 131, 114} , {118, 126, 145, 113} , {100, 118, 128, 118} , {29, 79, 245, 189} , {142, 75, 238, 239} },
    { {230, 205, 0, 231} , {63, 217, 101, 208} , {156, 161, 136, 144} , {130, 163, 145, 142} , {114, 132, 130, 132} , 
      {131, 139, 138, 125} , {129, 121, 154, 135} , {115, 111, 134, 133} , {185, 41, 44, 87} , {3, 84, 65, 15} },
    { {241, 167, 79, 177} , {239, 251, 223, 225} , {154, 170, 128, 137} , {136, 168, 131, 140} , {118, 136, 127, 131} , 
      {134, 139, 137, 132} , {135, 119, 141, 145} , {128, 102, 135, 136} , {227, 71, 248, 126} , {77, 196, 38, 144} },
    { {219, 12, 68, 56} , {220, 157, 193, 212} , {66, 158, 114, 63} , {132, 139, 48, 90} , {169, 245, 250, 162} , 
      {65, 70, 120, 156} , {112, 38, 180, 241} , {190, 117, 158, 74} , {158, 125, 174, 208} , {177, 30, 159, 130} },
    { {128, 72, 127, 148} , {214, 177, 72, 74} , {75, 93, 108, 33} , {138, 250, 173, 49} , {96, 170, 14, 237} , 
      {228, 28, 102, 130} , {30, 111, 160, 103} , {215, 250, 183, 203} , {203, 146, 10, 94} , {155, 184, 212, 184} }
    }; 

    uint8_t* res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<10; ++i) {
        for(int j = 0; j<10; ++j) {
            for(int k = 0; k<4; ++k) {
                ASSERT_NEAR_MSG(kvICiP_Expected[i][j][k], res[i*40 + j*4 + k], 2, 
                                "Flag :kvImageCopyInPlace\t Source and Destination of same size\0");
            }
        }
    }


    Error = vImageBoxConvolve_ARGB8888(&src, &dest, NULL, 0, 0, 5, 5, NULL, kvImageEdgeExtend);
    uint8_t kvIEE_Expected [10][10][4] ={
    { {143, 94, 154, 75} , {135, 100, 144, 84} , {126, 111, 134, 90} , {106, 126, 115, 89} , {101, 107, 123, 99} , 
      {107, 109, 139, 105} , {97, 126, 142, 92} , {111, 129, 150, 88} , {137, 126, 167, 91} , {149, 133, 173, 84} },
    { {132, 105, 143, 93} , {128, 108, 135, 99} , {121, 122, 132, 101} , {108, 138, 115, 94} , {102, 122, 126, 101} , 
      {110, 119, 129, 107} , {100, 132, 131, 93} , {111, 129, 137, 94} , {128, 124, 156, 104} , {134, 125, 160, 101} },
    { {114, 113, 133, 117} , {117, 118, 129, 115} , {116, 125, 134, 113} , {108, 140, 124, 103} , {101, 130, 124, 107} , 
      {118, 133, 123, 113} , {111, 140, 125, 103} , {117, 143, 122, 109} , {130, 139, 136, 124} , {134, 144, 140, 122} },
    { {104, 127, 124, 128} , {109, 130, 124, 120} , {111, 137, 134, 122} , {105, 151, 128, 112} , {101, 141, 125, 113} , 
      {121, 138, 119, 122} , {112, 140, 121, 124} , {116, 140, 118, 130} , {128, 132, 132, 148} , {132, 138, 143, 151} },
    { {132, 132, 96, 150} , {128, 141, 103, 138} , {121, 151, 129, 136} , {107, 163, 132, 126} , {100, 140, 130, 118} , 
      {113, 145, 134, 115} , {105, 134, 138, 114} , {101, 128, 123, 121} , {103, 120, 131, 136} , {106, 132, 137, 140} },
    { {168, 152, 88, 165} , {160, 157, 101, 152} , {152, 162, 134, 146} , {130, 166, 141, 136} , {113, 137, 132, 122} , 
      {125, 143, 131, 114} , {118, 126, 145, 113} , {100, 118, 128, 118} , {96, 111, 137, 129} , {94, 127, 142, 131} },
    { {174, 141, 92, 154} , {165, 152, 103, 141} , {156, 161, 136, 144} , {130, 163, 145, 142} , {114, 132, 130, 132} , 
      {131, 139, 138, 125} , {129, 121, 154, 135} , {115, 111, 134, 133} , {118, 106, 139, 134} , {122, 124, 144, 131} },
    { {177, 138, 96, 142} , {166, 153, 108, 129} , {154, 170, 128, 137} , {136, 168, 131, 140} , {118, 136, 127, 131} , 
      {134, 139, 137, 132} , {135, 119, 141, 145} , {128, 102, 135, 136} , {127, 105, 147, 133} , {135, 120, 153, 133} },
    { {172, 128, 99, 142} , {164, 152, 111, 127} , {151, 171, 121, 136} , {145, 163, 121, 137} , {120, 136, 121, 130} , 
      {143, 148, 134, 136} , {151, 124, 126, 144} , {149, 112, 127, 132} , {140, 125, 139, 127} , {150, 141, 140, 128} },
    { {160, 111, 116, 123} , {157, 141, 124, 112} , {150, 163, 122, 125} , {156, 154, 118, 128} , {123, 132, 125, 127} , 
      {150, 148, 134, 145} , {159, 128, 122, 154} , {162, 121, 138, 146} , {151, 145, 153, 149} , {168, 160, 154, 157} }
    };

    res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<10; ++i) {
        for(int j = 0; j<10; ++j) {
            for(int k = 0; k<4; ++k) {
                 ASSERT_NEAR_MSG(kvIEE_Expected[i][j][k], res[i*40 + j*4 + k], 2, 
                                 "Flag :kvImageEdgeExtend\t Source and Destination of same size\0");
            }
        }
    }


    Error = vImageBoxConvolve_ARGB8888(&src, &dest, NULL, 0, 0, 5, 5, NULL, kvImageTruncateKernel);
    uint8_t kvITC_Expected [10][10][4] = {
    { {99, 134, 138, 87} , {103, 125, 141, 91} , {99, 124, 136, 99} , {96, 137, 110, 98} , {101, 128, 113, 108} , 
      {120, 121, 123, 121} , {115, 135, 112, 117} , {140, 139, 119, 109} , {154, 141, 131, 114} , {157, 146, 137, 115} },
    { {118, 140, 132, 100} , {116, 127, 131, 105} , {109, 130, 132, 107} , {105, 145, 113, 99} , {102, 134, 123, 105} , 
      {116, 126, 121, 113} , {107, 136, 117, 102} , {121, 133, 122, 104} , {131, 130, 136, 113} , {132, 129, 134, 106} },
    { {118, 130, 135, 116} , {119, 126, 128, 115} , {116, 125, 134, 113} , {108, 140, 124, 103} , {101, 130, 124, 107} , 
      {118, 133, 123, 113} , {111, 140, 125, 103} , {117, 143, 122, 109} , {128, 139, 134, 120} , {134, 146, 138, 112} },
    { {103, 141, 132, 127} , {110, 136, 127, 118} , {111, 137, 134, 122} , {105, 151, 128, 112} , {101, 141, 125, 113} , 
      {121, 138, 119, 122} , {112, 140, 121, 124} , {116, 140, 118, 130} , {126, 130, 128, 142} , {130, 136, 138, 138} },
    { {121, 145, 113, 151} , {123, 148, 111, 136} , {121, 151, 129, 136} , {107, 163, 132, 126} , {100, 140, 130, 118} ,
      {113, 145, 134, 115} , {105, 134, 138, 114} , {101, 128, 123, 121} , {107, 117, 132, 127} , {116, 132, 146, 119} },
    { {154, 158, 121, 167} , {153, 161, 116, 149} , {152, 162, 134, 146} , {130, 166, 141, 136} , {113, 137, 132, 122} , 
      {125, 143, 131, 114} , {118, 126, 145, 113} , {100, 118, 128, 118} , {105, 106, 142, 121} , {117, 125, 157, 111} },
    { {153, 149, 123, 161} , {154, 158, 117, 140} , {156, 161, 136, 144} , {130, 163, 145, 142} , {114, 132, 130, 132} ,  
      {131, 139, 138, 125} , {129, 121, 154, 135} , {115, 111, 134, 133} , {125, 103, 146, 132} , {140, 128, 164, 123} },
    { {157, 153, 114, 142} , {156, 163, 118, 125} , {154, 170, 128, 137} , {136, 168, 131, 140} , {118, 136, 127, 131} , 
      {134, 139, 137, 132} , {135, 119, 141, 145} , {128, 102, 135, 136} , {131, 102, 149, 131} , {151, 124, 161, 127} },
    { {165, 151, 114, 147} , {163, 168, 118, 132} , {156, 175, 127, 142} , {144, 168, 127, 145} , {122, 137, 123, 135} , 
      {143, 144, 136, 134} , {150, 120, 134, 142} , {145, 104, 126, 129} , {146, 111, 139, 120} , {170, 132, 144, 117} },
    { {165, 144, 137, 134} , {165, 162, 135, 125} , {162, 170, 137, 136} , {159, 161, 135, 144} , {129, 134, 134, 138} , 
      {156, 139, 139, 145} , {162, 119, 142, 154} , {159, 105, 140, 148} , {154, 122, 155, 145} , {181, 144, 153, 145} }
    };

    res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<10; ++i) {
        for(int j = 0; j<10; ++j) {
            for(int k = 0; k<4; ++k) {
                 ASSERT_NEAR_MSG(kvITC_Expected[i][j][k], res[i*40 + j*4 + k], 2, 
                                 "Flag :kvImageTruncateKernel\t Source and Destination of same size\0");
            }
        }
    }


    Error = vImageBoxConvolve_ARGB8888(&src, &dest, NULL, 0, 0, 5, 5, background, kvImageBackgroundColorFill);
    uint8_t kvICBCF_Expected [10][10][4] = {
    { {42, 61, 69, 57} , {55, 71, 83, 64} , {63, 82, 93, 76} , {62, 90, 78, 75} , {65, 85, 80, 81} , 
      {76, 80, 86, 89} , {73, 89, 79, 86} , {88, 91, 83, 81} , {79, 78, 79, 76} , {63, 65, 68, 67} },
    { {62, 78, 79, 69} , {78, 88, 95, 82} , {90, 108, 112, 94} , {86, 120, 97, 87} , {84, 111, 104, 92} ,
      {95, 105, 103, 99} , {88, 113, 99, 90} , {99, 110, 103, 91} , {88, 90, 98, 87} , {69, 72, 80, 72} },
    { {75, 86, 93, 86} , {97, 105, 109, 100} , {116, 125, 134, 113} , {108, 140, 124, 103} , {101, 130, 124, 107} ,
      {118, 133, 123, 113} , {111, 140, 125, 103} , {117, 143, 122, 109} , {105, 115, 113, 104} , {84, 95, 95, 83} },
    { {66, 92, 91, 92} , {90, 113, 107, 102} , {111, 137, 134, 122} , {105, 151, 128, 112} , {101, 141, 125, 113} ,     
      {121, 138, 119, 122} , {112, 140, 121, 124} , {116, 140, 118, 130} , {103, 108, 108, 122} , {82, 89, 95, 99} },
    { {77, 95, 80, 107} , {101, 123, 95, 117} , {121, 151, 129, 136} , {107, 163, 132, 126} , {100, 140, 130, 118} , 
      {113, 145, 134, 115} , {105, 134, 138, 114} , {101, 128, 123, 121} , {88, 98, 112, 109} , {74, 87, 100, 87} },
    { {97, 103, 84, 116} , {125, 133, 99, 127} , {152, 162, 134, 146} , {130, 166, 141, 136} , {113, 137, 132, 122} , 
      {125, 143, 131, 114} , {118, 126, 145, 113} , {100, 118, 128, 118} , {86, 89, 119, 105} , {74, 83, 106, 83} },
    { {96, 97, 86, 112} , {125, 130, 100, 120} , {156, 161, 136, 144} , {130, 163, 145, 142} , {114, 132, 130, 132} , 
      {131, 139, 138, 125} , {129, 121, 154, 135} , {115, 111, 134, 133} , {102, 86, 122, 113} , {88, 85, 110, 90} },
    { {98, 100, 81, 101} , {127, 134, 100, 108} , {154, 170, 128, 137} , {136, 168, 131, 140} , {118, 136, 127, 131} , 
      {134, 139, 137, 132} , {135, 119, 141, 145} , {128, 102, 135, 136} , {107, 86, 125, 113} , {94, 82, 108, 92} },
    { {84, 83, 71, 92} , {108, 115, 86, 99} , {127, 144, 107, 122} , {117, 138, 108, 124} , {99, 113, 104, 116} , 
      {116, 119, 115, 115} , {122, 100, 113, 122} , {118, 87, 107, 111} , {97, 78, 100, 91} , {87, 74, 85, 77} },
    { {66, 65, 69, 74} , {85, 88, 80, 81} , {101, 110, 94, 98} , {100, 105, 93, 102} , {81, 88, 93, 99} , 
      {98, 91, 95, 103} , {101, 79, 97, 108} , {99, 71, 96, 105} , {79, 69, 90, 90} , {72, 64, 74, 78} }
    };

    res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<10; ++i) {
        for(int j = 0; j<10; ++j) {
            for(int k = 0; k<4; ++k) {
                 ASSERT_NEAR_MSG(kvICBCF_Expected[i][j][k], res[i*40 + j*4 + k], 2, 
                                 "Flag :kvImageBackgroundColorFill\t Source and Destination of same size\0");
            }
        }
    }


    dest.width = 6;
    dest.height = 6;
    dest.rowBytes = dest.width*4;

    Error = vImageBoxConvolve_ARGB8888(&src, &dest, NULL, 2, 2, 5, 5, NULL, kvImageCopyInPlace);
    uint8_t Copy[6][6][4] = {
    { {116, 125, 134, 113} , {108, 140, 124, 103} , {101, 130, 124, 107} , {118, 133, 123, 113} , {111, 140, 125, 103} , 
      {117, 143, 122, 109} },
    { {111, 137, 134, 122} , {105, 151, 128, 112} , {101, 141, 125, 113} , {121, 138, 119, 122} , {112, 140, 121, 124} , 
      {116, 140, 118, 130} },
    { {121, 151, 129, 136} , {107, 163, 132, 126} , {100, 140, 130, 118} , {113, 145, 134, 115} , {105, 134, 138, 114} ,
      {101, 128, 123, 121} },
    { {152, 162, 134, 146} , {130, 166, 141, 136} , {113, 137, 132, 122} , {125, 143, 131, 114} , {118, 126, 145, 113} ,
      {100, 118, 128, 118} },
    { {156, 161, 136, 144} , {130, 163, 145, 142} , {114, 132, 130, 132} , {131, 139, 138, 125} , {129, 121, 154, 135} , 
      {115, 111, 134, 133} },
    { {154, 170, 128, 137} , {136, 168, 131, 140} , {118, 136, 127, 131} , {134, 139, 137, 132} , {135, 119, 141, 145} ,
      {128, 102, 135, 136} }
    };
    
    res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<6; ++i) {
        for(int j = 0; j<6; ++j) {
            for(int k = 0; k<4; ++k) {
                ASSERT_NEAR_MSG(Copy[i][j][k], res[i*24 + j*4 + k], 2, "Flag :kvImageCopyInPlace\t FULL KERNEL\0");
            }
        }
    }


    Error = vImageBoxConvolve_ARGB8888(&src, &dest, NULL, 2, 2, 5, 5, NULL, kvImageEdgeExtend);
    uint8_t EE[6][6][4] = {
    { {116, 125, 134, 113} , {108, 140, 124, 103} , {101, 130, 124, 107} , {118, 133, 123, 113} , {111, 140, 125, 103} ,
      {117, 143, 122, 109} },
    { {111, 137, 134, 122} , {105, 151, 128, 112} , {101, 141, 125, 113} , {121, 138, 119, 122} , {112, 140, 121, 124} ,
      {116, 140, 118, 130} },
    { {121, 151, 129, 136} , {107, 163, 132, 126} , {100, 140, 130, 118} , {113, 145, 134, 115} , {105, 134, 138, 114} ,
      {101, 128, 123, 121} },
    { {152, 162, 134, 146} , {130, 166, 141, 136} , {113, 137, 132, 122} , {125, 143, 131, 114} , {118, 126, 145, 113} ,
      {100, 118, 128, 118} },
    { {156, 161, 136, 144} , {130, 163, 145, 142} , {114, 132, 130, 132} , {131, 139, 138, 125} , {129, 121, 154, 135} , 
      {115, 111, 134, 133} },
    { {154, 170, 128, 137} , {136, 168, 131, 140} , {118, 136, 127, 131} , {134, 139, 137, 132} , {135, 119, 141, 145} ,
      {128, 102, 135, 136} }
    };

    res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<6; ++i) {
        for(int j = 0; j<6; ++j) {
            for(int k = 0; k<4; ++k) {
                 ASSERT_NEAR_MSG(EE[i][j][k], res[i*24 + j*4 + k], 2, "Flag :kvImageEdgeExtend\t FULL KERNEL\0");
            }
        }
    }


    Error = vImageBoxConvolve_ARGB8888(&src, &dest, NULL, 2, 2, 5, 5, NULL, kvImageTruncateKernel);
    uint8_t TK[6][6][4] = {
    { {116, 125, 134, 113} , {108, 140, 124, 103} , {101, 130, 124, 107} , {118, 133, 123, 113} , {111, 140, 125, 103} ,
      {117, 143, 122, 109} },
    { {111, 137, 134, 122} , {105, 151, 128, 112} , {101, 141, 125, 113} , {121, 138, 119, 122} , {112, 140, 121, 124} ,
      {116, 140, 118, 130} },
    { {121, 151, 129, 136} , {107, 163, 132, 126} , {100, 140, 130, 118} , {113, 145, 134, 115} , {105, 134, 138, 114} ,
      {101, 128, 123, 121} },
    { {152, 162, 134, 146} , {130, 166, 141, 136} , {113, 137, 132, 122} , {125, 143, 131, 114} , {118, 126, 145, 113} ,
      {100, 118, 128, 118} },
    { {156, 161, 136, 144} , {130, 163, 145, 142} , {114, 132, 130, 132} , {131, 139, 138, 125} , {129, 121, 154, 135} ,
      {115, 111, 134, 133} },
    { {154, 170, 128, 137} , {136, 168, 131, 140} , {118, 136, 127, 131} , {134, 139, 137, 132} , {135, 119, 141, 145} ,
      {128, 102, 135, 136} }
    };

    res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<6; ++i) {
        for(int j = 0; j<6; ++j) {
            for(int k = 0; k<4; ++k) {
                 ASSERT_NEAR_MSG(TK[i][j][k], res[i*24 + j*4 + k], 2, "Flag :kvImageTruncateKernel\t FULL KERNEL\0");
            }
        }
    }


    Error = vImageBoxConvolve_ARGB8888(&src, &dest, NULL, 2, 2, 5, 5, background, kvImageBackgroundColorFill);
    uint8_t BCF[6][6][4] = {
    { {116, 125, 134, 113} , {108, 140, 124, 103} , {101, 130, 124, 107} , {118, 133, 123, 113} , {111, 140, 125, 103} , 
      {117, 143, 122, 109} },
    { {111, 137, 134, 122} , {105, 151, 128, 112} , {101, 141, 125, 113} , {121, 138, 119, 122} , {112, 140, 121, 124} , 
      {116, 140, 118, 130} },
    { {121, 151, 129, 136} , {107, 163, 132, 126} , {100, 140, 130, 118} , {113, 145, 134, 115} , {105, 134, 138, 114} , 
      {101, 128, 123, 121} },
    { {152, 162, 134, 146} , {130, 166, 141, 136} , {113, 137, 132, 122} , {125, 143, 131, 114} , {118, 126, 145, 113} ,
      {100, 118, 128, 118} },
    { {156, 161, 136, 144} , {130, 163, 145, 142} , {114, 132, 130, 132} , {131, 139, 138, 125} , {129, 121, 154, 135} , 
      {115, 111, 134, 133} },
    { {154, 170, 128, 137} , {136, 168, 131, 140} , {118, 136, 127, 131} , {134, 139, 137, 132} , {135, 119, 141, 145} ,
      {128, 102, 135, 136} }
    };

    res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<6; ++i) {
        for(int j = 0; j<6; ++j) {
            for(int k = 0; k<4; ++k) {
                ASSERT_NEAR_MSG(BCF[i][j][k], res[i*24 + j*4 + k], 2, "Flag :kvImageBackgroundColorFill\t FULL KERNEL\0");
            }
        }
    }

}

TEST(Accelerate, MatrixMultiply) {
    vImageInit();
        
    int16_t A[] = { 149, 124, 116, 114,
                    174, 190,  18, 191,
                     80, 128,  65,  44,
                      3,  70, 168, 188 };
    
    double meandivisor = 400;

    Error = vImageMatrixMultiply_ARGB8888(&src, &dest, A, meandivisor, NULL, NULL, 0);
    
    uint8_t matMultExpected [10][10][4] = {
    { {127, 138, 110, 110}, {174, 196, 107, 188}, {142, 162, 113, 156}, {80, 112, 108, 130}, {120, 142, 93, 120},
      {78, 102, 38, 88}, {73, 112, 103, 107}, {176, 215, 106, 177}, {121, 154, 51, 107}, {127, 157, 105, 131} },
    { {123, 177, 107, 175}, {144, 161, 83, 129}, {100, 119, 54, 121}, {98, 118, 78, 91}, {89, 125, 116, 173}, 
      {105, 130, 57, 151}, {200, 219, 141, 240}, {108, 132, 159, 186}, {141, 166, 122, 205}, {182, 199, 112, 155} },
    { {67, 112, 92, 93}, {96, 121, 64, 148}, {139, 199, 114, 212}, {171, 214, 129, 213}, {109, 160, 104, 174}, 
      {121, 142, 137, 164}, {131, 157, 97, 156}, {183, 245, 199, 255}, {120, 142, 82, 162}, {192, 225, 168, 255} },
    { {95, 119, 111, 151}, {194, 240, 182, 255}, {182, 210, 112, 172}, {73, 106, 113, 140}, {169, 205, 92, 178}, 
      {121, 132, 45, 123}, {134, 194, 147, 206}, {125, 127, 68, 118}, {46, 66, 29, 38}, {76, 138, 126, 162} },
    { {112, 137, 109, 179}, {162, 214, 176, 220}, {68, 122, 127, 134}, {161, 175, 92, 185}, {134, 167, 131, 138}, 
      {141, 168, 58, 154}, {54, 91, 104, 136}, {229, 255, 178, 255}, {169, 196, 98, 168}, {130, 174, 121, 215} },
    { {146, 162, 122, 172}, {128, 175, 137, 222}, {149, 182, 78, 150}, {118, 134, 80, 116}, {195, 245, 183, 255}, 
      {118, 162, 85, 173}, {43, 77, 110, 117}, {113, 152, 87, 132}, {96, 158, 131, 162}, {135, 198, 184, 215} },
    { {177, 209, 173, 255}, {140, 191, 132, 230}, {127, 144, 124, 168}, {170, 193, 83, 176}, {158, 221, 146, 234}, 
      {103, 142, 93, 181}, {40, 52, 62, 71}, {202, 223, 110, 168}, {96, 106, 99, 118}, {51, 64, 22, 55} },
    { {180, 210, 165, 240}, {245, 255, 211, 255}, {173, 242, 164, 251}, {230, 255, 173, 255}, {190, 229, 149, 232}, 
      {107, 130, 163, 179}, {67, 95, 83, 91}, {199, 239, 163, 233}, {166, 206, 162, 185}, {123, 154, 98, 187} },
    { {101, 105, 99, 102}, {190, 242, 191, 255}, {117, 143, 71, 136}, {120, 138, 90, 152}, {221, 255, 169, 255},
      {80, 119, 107, 138}, {96, 153, 165, 183}, {154, 178, 117, 162}, {150, 200, 167, 222}, {112, 143, 133, 143} },
    { {106, 140, 123, 154}, {172, 186, 113, 188}, {90, 108, 57, 93}, {195, 225, 100, 201}, {114, 156, 137, 221}, 
      {118, 139, 139, 151}, {92, 131, 83, 128}, {227, 255, 189, 255}, {142, 152, 107, 173}, {182, 235, 165, 242} }
    }; 

    uint8_t* res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<10; ++i) {
        for(int j = 0; j<10; ++j) {
            for(int k = 0; k<4; ++k) {
                ASSERT_NEAR_MSG(matMultExpected[i][j][k], res[i*40 + j*4 + k], 2, "vImageMatrixMultiply\0");
            }
        }
    }
    
    // Checking for cut off at 255
        
    int16_t B[] = { 192, 152,  16,  22,
                     95,  97, 149,  70,
                    186, 162,  21,  69,
                     58,  77, 187, 119 };
    
    Error = vImageMatrixMultiply_ARGB8888(&src, &dest, B, meandivisor/2, NULL, NULL, 0);
    
    uint8_t matMultExpected2 [10][10][4] = {
    { {255, 255, 85, 109}, {255, 255, 236, 168}, {255, 255, 184, 148}, {255, 238, 188, 148}, {255, 255, 136, 129}, 
      {177, 167, 135, 102}, {255, 255, 154, 152}, {255, 255, 229, 198}, {255, 255, 145, 138}, {255, 255, 153, 153} },
    { {255, 255, 255, 217}, {255, 255, 137, 125}, {194, 183, 177, 112}, {255, 255, 96, 107}, {220, 219, 255, 175}, 
      {169, 173, 245, 138}, {255, 255, 255, 193}, {255, 255, 249, 170}, {255, 255, 255, 177}, {255, 255, 147, 147} },
    { {255, 255, 140, 154}, {163, 166, 239, 135}, {255, 255, 255, 247}, {255, 255, 255, 223}, {255, 255, 255, 208}, 
      {255, 255, 201, 153}, {255, 255, 209, 154}, {255, 255, 255, 255}, {233, 222, 236, 142}, {255, 255, 255, 236} },
    { {248, 231, 214, 145}, {255, 255, 255, 255}, {255, 255, 195, 175}, {230, 219, 213, 154}, {255, 255, 242, 189}, 
      {218, 199, 162, 99}, {255, 255, 255, 250}, {255, 231, 121, 85}, {155, 139, 52, 68}, {255, 255, 255, 223} },
    { {240, 230, 255, 160}, {255, 255, 255, 251}, {255, 255, 216, 195}, {255, 255, 241, 146}, {255, 255, 150, 168}, 
      {255, 255, 225, 151}, {171, 175, 231, 155}, {255, 255, 255, 255}, {255, 255, 206, 167}, {255, 255, 255, 218} },
    { {255, 255, 205, 148}, {255, 255, 255, 229}, {255, 255, 201, 164}, {255, 255, 128, 112}, {255, 255, 255, 255}, 
      {255, 255, 255, 190}, {184, 180, 189, 142}, {255, 255, 190, 165}, {255, 255, 255, 228}, {255, 255, 255, 255} },
    { {255, 255, 255, 234}, {255, 255, 255, 241}, {255, 255, 212, 146}, {255, 255, 229, 160}, {255, 255, 255, 255}, 
      {207, 213, 255, 183}, {124, 114, 97, 70}, {255, 255, 166, 164}, {255, 230, 131, 102}, {108, 101, 84, 61} },
    { {255, 255, 255, 218}, {255, 255, 255, 255}, {255, 255, 255, 255}, {255, 255, 255, 255}, {255, 255, 255, 230}, 
      {255, 255, 229, 165}, {240, 217, 123, 118}, {255, 255, 255, 235}, {255, 255, 215, 210}, {244, 240, 255, 176} },
    { {255, 249, 86, 85}, {255, 255, 255, 255}, {255, 243, 194, 139}, {255, 241, 203, 133}, {255, 255, 255, 255}, 
      {252, 241, 216, 166}, {255, 255, 255, 231}, {255, 255, 188, 160}, {255, 255, 255, 245}, {255, 255, 175, 162} },
    { {255, 255, 216, 171}, {255, 255, 226, 154}, {226, 202, 117, 98}, {255, 255, 255, 192}, {255, 255, 255, 216},
      {255, 255, 171, 147}, {255, 246, 198, 159}, {255, 255, 255, 255}, {255, 255, 214, 133}, {255, 255, 255, 255} }
    };
    
    res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<10; ++i) {
        for(int j = 0; j<10; ++j) {
            for(int k = 0; k<4; ++k) {
                ASSERT_NEAR_MSG(matMultExpected2[i][j][k], res[i*40 + j*4 + k], 2, "vImageMatrixMultiply : 255 Cut-Off test\0");
            }
        }
    }
    
    
    // Checking for cut off at 0
        
    Error = vImageMatrixMultiply_ARGB8888(&src, &dest, B, -1 * meandivisor, NULL, NULL, 0);
    
    res = reinterpret_cast<uint8_t*>(dest.data);
    for(int i = 0; i<10; ++i) {
        for(int j = 0; j<10; ++j) {
            for(int k = 0; k<4; ++k) {
                ASSERT_NEAR_MSG(0, res[i*40 + j*4 + k], 2, "vImageMatrixMultiply : 255 Cut-Off test\0");
            }
        }
    }
}

static inline void vImageTestBufferFree(vImage_Buffer* buffer) {
    if (buffer->data) {
        free(buffer->data);
        buffer->data = nullptr;
    }
}

static void vImageTestFillBufferWithRandomData8(vImage_Buffer* buffer) {
    uint8_t* rowPtr = reinterpret_cast<uint8_t*>(buffer->data);

    for (uint32_t y = 0; y < buffer->height; y++) {
        for (uint32_t x = 0; x < buffer->width; x++) {
            rowPtr[x] = (uint8_t)((double)rand() / (RAND_MAX + 1) * (256));
        }

        rowPtr += buffer->rowBytes;
    }
}

static void vImageTestFillBufferWithRandomDataF(vImage_Buffer* buffer) {
    uint8_t* rowPtr = reinterpret_cast<uint8_t*>(buffer->data);
    float* rowPtrFloats;

    for (uint32_t y = 0; y < buffer->height; y++) {
        rowPtrFloats = reinterpret_cast<float*>(rowPtr);

        for (uint32_t x = 0; x < buffer->width; x++) {
            rowPtrFloats[x] = (float)((double)rand() / (RAND_MAX));
        }

        rowPtr += buffer->rowBytes;
    }
}

static bool vImageTestCompare8888Buffers(const vImage_Buffer* bufferA, const vImage_Buffer* bufferB) {
    const uint32_t width = static_cast<uint32_t>(bufferA->width);
    const uint32_t height = static_cast<uint32_t>(bufferA->height);
    uint8_t* rowPtrA = reinterpret_cast<uint8_t*>(bufferA->data);
    uint8_t* rowPtrB = reinterpret_cast<uint8_t*>(bufferB->data);
    uint32_t* rowPtrAUInts;
    uint32_t* rowPtrBUInts;

    bool buffersEqual = true;

    for (uint32_t y = 0; y < height; y++) {
        rowPtrAUInts = reinterpret_cast<uint32_t*>(rowPtrA);
        rowPtrBUInts = reinterpret_cast<uint32_t*>(rowPtrB);

        for (uint32_t x = 0; x < width; x++) {
            if (rowPtrAUInts[x] != rowPtrBUInts[x]) {
                LOG_INFO("vImageTestCompare8888Buffers: Buffer mismatch at <%d, %d>", x, y);
                buffersEqual = false;
                break;
            }
        }

        if (buffersEqual == false) {
            break;
        }

        rowPtrA += bufferA->rowBytes;
        rowPtrB += bufferB->rowBytes;
    }

    return buffersEqual;
}

static void vImageTestGetFormatFromCgImage(CGImageRef imageRef, vImage_CGImageFormat* format) {
    ASSERT_TRUE(format != nullptr);
    ASSERT_TRUE(imageRef != nullptr);

    format->bitmapInfo = CGImageGetBitmapInfo(imageRef);
    format->colorSpace = CGImageGetColorSpace(imageRef);
    format->bitsPerComponent = (uint32_t)CGImageGetBitsPerComponent(imageRef);

    const uint32_t alphaInfo = format->bitmapInfo & kCGBitmapAlphaInfoMask;
    const uint32_t byteOrder = format->bitmapInfo & kCGBitmapByteOrderMask;

    const uint32_t numColorComponents = (uint32_t)CGColorSpaceGetNumberOfComponents(format->colorSpace);
    const uint32_t numAlphaOrPaddingComponents = (kCGImageAlphaNone != alphaInfo) ? 1 : 0;

    format->bitsPerPixel = format->bitsPerComponent * (numColorComponents + numAlphaOrPaddingComponents);
    format->decode = NULL;
    format->version = 0;
    format->renderingIntent = (CGColorRenderingIntent)0;

    ASSERT_TRUE(format->bitsPerComponent == 8);
    ASSERT_TRUE(CGColorSpaceGetModel(format->colorSpace) == kCGColorSpaceModelRGB);
    ASSERT_TRUE((numColorComponents == 3) && (numAlphaOrPaddingComponents == 1));
    ASSERT_TRUE((byteOrder != kCGBitmapByteOrder16Little) && (byteOrder != kCGBitmapByteOrder16Big));
}

static void vImageTestSetAlphaAndUnpremultiply(CGImageRef imageRef, vImage_Buffer* imageBufferUnPremultiplied8888, uint8_t alphaVal) {
    vImage_CGImageFormat format;

    vImageTestGetFormatFromCgImage(imageRef, &format);

    int indexR, indexG, indexB, indexA;
    const uint32_t alphaInfo = format.bitmapInfo & kCGBitmapAlphaInfoMask;
    const uint32_t byteOrder = format.bitmapInfo & kCGBitmapByteOrderMask;

    // Use the byteorder and alpha info of the input image to get the byte index of each component
    // Note: vImage uses little endian notation for byte order as opposed to CoreGraphics which uses big endian or networkByte order
    // notation
    if (byteOrder == kCGBitmapByteOrder32Big) {
        // XBGR_le or BGRX_le
        if (alphaInfo == kCGImageAlphaLast || alphaInfo == kCGImageAlphaNoneSkipLast) {
            indexA = 0;
            indexB = 1;
            indexG = 2;
            indexR = 3;
        } else {
            indexB = 0;
            indexG = 1;
            indexR = 2;
            indexA = 3;
        }
    } else {
        // RGBX_le or XRGB_le
        if (alphaInfo == kCGImageAlphaLast || alphaInfo == kCGImageAlphaNoneSkipLast) {
            indexR = 0;
            indexG = 1;
            indexB = 2;
            indexA = 3;
        } else {
            indexA = 0;
            indexR = 1;
            indexG = 2;
            indexB = 3;
        }
    }

    vImage_Error result;
    vImage_Buffer imageBuffer8888;
    result = vImageBuffer_InitWithCGImage(&imageBuffer8888, &format, nil, imageRef, 0);

    ASSERT_TRUE(result == kvImageNoError);

    // Create plane buffers
    vImage_Buffer planeBuffer[4];

    result = vImageBuffer_Init(&planeBuffer[0], imageBuffer8888.height, imageBuffer8888.width, format.bitsPerComponent, 0);
    ASSERT_TRUE(result == kvImageNoError);
    result = vImageBuffer_Init(&planeBuffer[1], planeBuffer[0].height, planeBuffer[0].width, format.bitsPerComponent, 0);
    ASSERT_TRUE(result == kvImageNoError);
    result = vImageBuffer_Init(&planeBuffer[2], planeBuffer[0].height, planeBuffer[0].width, format.bitsPerComponent, 0);
    ASSERT_TRUE(result == kvImageNoError);
    result = vImageBuffer_Init(&planeBuffer[3], planeBuffer[0].height, planeBuffer[0].width, format.bitsPerComponent, 0);
    ASSERT_TRUE(result == kvImageNoError);

    // Note: Although the function calls for ARGB input, a different input format can be used if the output planes are swizzled
    if (indexA == 0) {
        if (indexR == 1) {
            // XRGB or ARGB
            result = vImageConvert_ARGB8888toPlanar8(&imageBuffer8888,
                                                     &planeBuffer[indexA],
                                                     &planeBuffer[indexR],
                                                     &planeBuffer[indexG],
                                                     &planeBuffer[indexB],
                                                     0);
        } else {
            // XBGR or ABGR
            result = vImageConvert_ARGB8888toPlanar8(&imageBuffer8888,
                                                     &planeBuffer[indexA],
                                                     &planeBuffer[indexB],
                                                     &planeBuffer[indexG],
                                                     &planeBuffer[indexR],
                                                     0);
        }
    } else if (indexA == 3) {
        if (indexR == 0) {
            // RGBX or RGBA
            result = vImageConvert_ARGB8888toPlanar8(&imageBuffer8888,
                                                     &planeBuffer[indexR],
                                                     &planeBuffer[indexG],
                                                     &planeBuffer[indexB],
                                                     &planeBuffer[indexA],
                                                     0);
        } else {
            // BGRX or BGRA
            result = vImageConvert_ARGB8888toPlanar8(&imageBuffer8888,
                                                     &planeBuffer[indexB],
                                                     &planeBuffer[indexG],
                                                     &planeBuffer[indexR],
                                                     &planeBuffer[indexA],
                                                     0);
        }
    }

    ASSERT_TRUE(result == kvImageNoError);

    const uint32_t height = (uint32_t)imageBuffer8888.height;
    const uint32_t rowPitch = (uint32_t)planeBuffer[indexA].rowBytes;
    uint8_t* colorData = (uint8_t*)(planeBuffer[indexA].data);

    // Set alpha value
    for (uint32_t i = 0; i < height; i++) {
        memset(colorData, alphaVal, rowPitch);
        colorData += rowPitch;
    }

    // Note: Although the function calls for ARGB input, a different input format can be used if the output planes are swizzled
    if (indexA == 0) {
        if (indexR == 1) {
            // XRGB or ARGB
            result = vImageConvert_Planar8toARGB8888(&planeBuffer[indexA],
                                                     &planeBuffer[indexR],
                                                     &planeBuffer[indexG],
                                                     &planeBuffer[indexB],
                                                     &imageBuffer8888,
                                                     0);
        } else {
            // XBGR or ABGR
            result = vImageConvert_Planar8toARGB8888(&planeBuffer[indexA],
                                                     &planeBuffer[indexB],
                                                     &planeBuffer[indexG],
                                                     &planeBuffer[indexR],
                                                     &imageBuffer8888,
                                                     0);
        }
    } else if (indexA == 3) {
        if (indexR == 0) {
            // RGBX or RGBA
            result = vImageConvert_Planar8toARGB8888(&planeBuffer[indexR],
                                                     &planeBuffer[indexG],
                                                     &planeBuffer[indexB],
                                                     &planeBuffer[indexA],
                                                     &imageBuffer8888,
                                                     0);
        } else {
            // BGRX or BGRA
            result = vImageConvert_Planar8toARGB8888(&planeBuffer[indexB],
                                                     &planeBuffer[indexG],
                                                     &planeBuffer[indexR],
                                                     &planeBuffer[indexA],
                                                     &imageBuffer8888,
                                                     0);
        }
    }

    result = vImageBuffer_Init(imageBufferUnPremultiplied8888, imageBuffer8888.height, imageBuffer8888.width, 32, kvImageNoFlags);
    ASSERT_TRUE(result == kvImageNoError);

    if (indexA == 3) {
        vImageUnpremultiplyData_RGBA8888(&imageBuffer8888, imageBufferUnPremultiplied8888, 0);
    } else {
        vImageUnpremultiplyData_ARGB8888(&imageBuffer8888, imageBufferUnPremultiplied8888, 0);
    }

    CGColorSpaceRelease(format.colorSpace);

    vImageTestBufferFree(&imageBuffer8888);
    vImageTestBufferFree(&planeBuffer[0]);
    vImageTestBufferFree(&planeBuffer[1]);
    vImageTestBufferFree(&planeBuffer[2]);
    vImageTestBufferFree(&planeBuffer[3]);
}

TEST(Accelerate, BufferInit) {
    const vImagePixelCount width = 10;
    const vImagePixelCount height = 10;
    const uint32_t bitsPerPixel = 32;
    const int32_t flags = kvImageNoFlags;
    int32_t alignment;

    vImage_Buffer buffer = {.data = nullptr, .height = 0xDEADBEEF, .width = 0xDEADBEEF, .rowBytes = 0xDEADBEEF };

    // GetBuffer create with noAllocate flag
    alignment = vImageBuffer_Init(&buffer, width, height, bitsPerPixel, kvImageNoAllocate);
    ASSERT_TRUE(alignment > 0);
    ASSERT_EQ(buffer.data, nullptr);

    // Buffer create (allocate)
    ASSERT_EQ(vImageBuffer_Init(&buffer, width, height, bitsPerPixel, flags), kvImageNoError);
    ASSERT_NE(buffer.data, nullptr);

    // Padding & Alignment applied
    ASSERT_GE(buffer.rowBytes, ((width * (bitsPerPixel >> 3) + alignment - 1) & ~(alignment - 1)));

    // Clean up
    vImageTestBufferFree(&buffer);

    // Invalid params
    ASSERT_EQ(vImageBuffer_Init(&buffer, width, height, bitsPerPixel, kvImageBackgroundColorFill), kvImageUnknownFlagsBit);
    ASSERT_EQ(buffer.data, nullptr);
}

TEST(Accelerate, Convert) {
    const vImagePixelCount width = 256;
    const vImagePixelCount height = 256;
    const int32_t flags = kvImageNoFlags;

    vImage_Buffer planar8Buffer = {.data = nullptr, .height = 0xDEADBEEF, .width = 0xDEADBEEF, .rowBytes = 0xDEADBEEF };
    vImage_Buffer planarFBuffer = {.data = nullptr, .height = 0xDEADBEEF, .width = 0xDEADBEEF, .rowBytes = 0xDEADBEEF };

    // Mismatched dimensions
    ASSERT_EQ(vImageBuffer_Init(&planar8Buffer, width, height, 8, flags), kvImageNoError);
    ASSERT_EQ(vImageBuffer_Init(&planarFBuffer, width - 1, height, 32, flags), kvImageNoError);
    ASSERT_EQ(vImageConvert_Planar8toPlanarF(&planar8Buffer, &planarFBuffer, 1.0f, 0.0f, kvImageNoFlags), kvImageBufferSizeMismatch);
    vImageTestBufferFree(&planar8Buffer);
    vImageTestBufferFree(&planarFBuffer);

    ASSERT_EQ(vImageBuffer_Init(&planar8Buffer, width, height - 1, 8, flags), kvImageNoError);
    ASSERT_EQ(vImageBuffer_Init(&planarFBuffer, width, height, 32, flags), kvImageNoError);
    ASSERT_EQ(vImageConvert_Planar8toPlanarF(&planar8Buffer, &planarFBuffer, 1.0f, 0.0f, kvImageNoFlags), kvImageBufferSizeMismatch);
    vImageTestBufferFree(&planar8Buffer);
    vImageTestBufferFree(&planarFBuffer);

    // Mismatched rowbytes from expected (done by switching float plane with byte plane)
    ASSERT_EQ(vImageBuffer_Init(&planar8Buffer, width, height, 8, flags), kvImageNoError);
    ASSERT_EQ(vImageBuffer_Init(&planarFBuffer, width, height, 32, flags), kvImageNoError);
    ASSERT_EQ(vImageConvert_Planar8toPlanarF(&planarFBuffer, &planar8Buffer, 1.0f, 0.0f, kvImageNoFlags), kvImageBufferSizeMismatch);
    vImageTestBufferFree(&planar8Buffer);
    vImageTestBufferFree(&planarFBuffer);

    // Clip checking
    ASSERT_EQ(vImageBuffer_Init(&planar8Buffer, width, height, 8, flags), kvImageNoError);
    ASSERT_EQ(vImageBuffer_Init(&planarFBuffer, width, height, 32, flags), kvImageNoError);
    vImageTestFillBufferWithRandomData8(&planar8Buffer);

    // Convert and clip planar8 to planarF with a range [0.5f, 1.0f]
    ASSERT_EQ(vImageConvert_Planar8toPlanarF(&planar8Buffer, &planarFBuffer, 1.0f, 0.5f, kvImageNoFlags), kvImageNoFlags);

    uint8_t* rowPtr = reinterpret_cast<uint8_t*>(planarFBuffer.data);
    float* rowPtrFloats;

    for (uint32_t y = 0; y < height; y++) {
        rowPtrFloats = reinterpret_cast<float*>(rowPtr);
        for (uint32_t x = 0; x < width; x++) {
            const float pixel = rowPtrFloats[x];
            ASSERT_TRUE(pixel >= 0.5f && pixel <= 1.0f);
        }

        rowPtr += planarFBuffer.rowBytes;
    }

    // Clamp float buffer with range [0.5 1.0f] to a range [0.0f 0.5f] and convert and saturate to uint8 effectively making all values 255
    ASSERT_EQ(vImageConvert_PlanarFtoPlanar8(&planarFBuffer, &planar8Buffer, 0.5f, 0.0f, kvImageNoFlags), kvImageNoFlags);

    rowPtr = reinterpret_cast<uint8_t*>(planar8Buffer.data);

    for (uint32_t y = 0; y < height; y++) {
        for (uint32_t x = 0; x < width; x++) {
            const uint8_t pixel = rowPtr[x];
            ASSERT_TRUE_MSG(pixel == 255, "vImageConvert: PlanarFtoPlanar8 pixel <%d, %d> not properly clamped to range below input", x, y);
        }

        rowPtr += planar8Buffer.rowBytes;
    }

    // Clamp float buffer with range [0.5 1.0f] to a range [1.5f 1.0f] and convert and saturate to uint8 effectively making all values 0
    ASSERT_EQ(vImageConvert_PlanarFtoPlanar8(&planarFBuffer, &planar8Buffer, 1.5f, 1.0f, kvImageNoFlags), kvImageNoFlags);

    rowPtr = reinterpret_cast<uint8_t*>(planar8Buffer.data);

    for (uint32_t y = 0; y < height; y++) {
        for (uint32_t x = 0; x < width; x++) {
            const uint8_t pixel = rowPtr[x];
            ASSERT_TRUE_MSG(pixel == 0, "vImageConvert: PlanarFtoPlanar8 pixel <%d, %d> not properly clamped to range above input", x, y);
        }

        rowPtr += planar8Buffer.rowBytes;
    }

    vImageTestBufferFree(&planar8Buffer);
    vImageTestBufferFree(&planarFBuffer);

    /// Planar8toRGB888
    vImage_Buffer rgbDest;
    vImage_Buffer planarGreen, planarBlue, planarRed;

    ASSERT_EQ(vImageBuffer_Init(&planarRed, width, height, 8, flags), kvImageNoError);
    ASSERT_EQ(vImageBuffer_Init(&planarGreen, width, height, 8, flags), kvImageNoError);
    ASSERT_EQ(vImageBuffer_Init(&planarBlue, width, height, 8, flags), kvImageNoError);
    ASSERT_EQ(vImageBuffer_Init(&rgbDest, width, height, 24, flags), kvImageNoError);

    // Set planarRed, planarGreen and planarBlue to 1, 2 and 3 respectively
    memset(planarRed.data, 1, planarRed.rowBytes * planarRed.height);
    memset(planarGreen.data, 2, planarGreen.rowBytes * planarGreen.height);
    memset(planarBlue.data, 3, planarBlue.rowBytes * planarBlue.height);

    ASSERT_EQ(vImageConvert_Planar8toRGB888(&planarRed, &planarGreen, &planarBlue, &rgbDest, kvImageNoFlags), kvImageNoError);

    const Pixel_888_s rgbPixelGolden = { 1, 2, 3 };
    rowPtr = reinterpret_cast<uint8_t*>(rgbDest.data);
    Pixel_888_s* rowPtrRgbPixels;

    for (uint32_t y = 0; y < height; y++) {
        rowPtrRgbPixels = reinterpret_cast<Pixel_888_s*>(rowPtr);
        for (uint32_t x = 0; x < width; x++) {
            Pixel_888_s pixel = rowPtrRgbPixels[x];
            ASSERT_TRUE(pixel.val[0] == rgbPixelGolden.val[0]);
            ASSERT_TRUE(pixel.val[1] == rgbPixelGolden.val[1]);
            ASSERT_TRUE(pixel.val[2] == rgbPixelGolden.val[2]);
        }

        rowPtr += rgbDest.rowBytes;
    }

    vImageTestBufferFree(&planarRed);
    vImageTestBufferFree(&planarGreen);
    vImageTestBufferFree(&planarBlue);
    vImageTestBufferFree(&rgbDest);
}

TEST(Accelerate, AlphaUnpremultiply) {
    SetCACompositor(new NullCompositor);

    char fullPath[_MAX_PATH];
    GetModuleFileNameA(NULL, fullPath, _MAX_PATH);
    char* executablePath = strrchr(fullPath, '\\');
    const char* relativePathToPhoto = "\\Photo2.jpg";
    strncpy(executablePath, relativePathToPhoto, strlen(relativePathToPhoto) + 1);
    UIImage* photo = [UIImage imageNamed:[NSString stringWithCString:fullPath]];

    vImage_Buffer unpremultipliedBufferSimd, unpremultipliedBufferNormal;
    const uint8_t alphaVal = 0x80;

    _vImageSetSimdOptmizationsState(false);
    vImageTestSetAlphaAndUnpremultiply(photo.CGImage, &unpremultipliedBufferNormal, alphaVal);

    _vImageSetSimdOptmizationsState(true);
    vImageTestSetAlphaAndUnpremultiply(photo.CGImage, &unpremultipliedBufferSimd, alphaVal);

    ASSERT_TRUE_MSG(vImageTestCompare8888Buffers(&unpremultipliedBufferSimd, &unpremultipliedBufferNormal),
                    "SIMD and non-SIMD output of AlphaUnpremultiply do not match");

    vImageTestBufferFree(&unpremultipliedBufferSimd);
    vImageTestBufferFree(&unpremultipliedBufferNormal);
}