//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

// Placeholder object for certain _NSCF classes' super class object,
//
// eg: _NSCFString
// In order to allow for _NSCFString to eventually have the correct class
// hierarchy ( NSObject --> NSString --> NSMutableString --> _NSCFString),
// its initial ivar layout *must* match its eventual layout.
// Because of this, a temporary "root" class is needed to take the place of
// NSObject (the only other class in the tree with an ivar). _NSCFTemporaryRootObject
// is that object and will be replaced at Foundation load time with NSMutableString
// to reseat _NSCFString correctly in the class tree.
//
__attribute__((objc_root_class)) @interface _NSCFTemporaryRootObject {
@public
    Class isa;
}

/* From NSObject */
- (void)doesNotRecognizeSelector:(SEL)selector;

@end