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

// Windows-only:
//      _NSConcretePointerFunctions

#import <Foundation/Foundation.h>
#import <TestFramework.h>
#import <NSPointerFunctionsConcrete.h>

TEST(NSPointerFunctions, CopyInternal) {
    NSPointerFunctions* functions =
        [NSPointerFunctions pointerFunctionsWithOptions:NSPointerFunctionsOpaqueMemory | NSPointerFunctionsIntegerPersonality];

    NSPointerFunctions* functionsCopy = [[functions copy] autorelease];

    _NSConcretePointerFunctions* functionsConcrete = reinterpret_cast<_NSConcretePointerFunctions*>(&*functions);
    _NSConcretePointerFunctions* functionsCopyConcrete = reinterpret_cast<_NSConcretePointerFunctions*>(&*functionsCopy);

    ASSERT_EQ(functionsConcrete.copyIn, functionsCopyConcrete.copyIn);
    ASSERT_EQ(functionsConcrete.weakMemory, functionsCopyConcrete.weakMemory);
    ASSERT_EQ(functionsConcrete.options, functionsCopyConcrete.options);
}