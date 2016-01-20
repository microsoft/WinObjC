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
#import <Security/SecPolicy.h>

/**
 @Status Stub
*/
CFTypeID SecPolicyGetTypeID() {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
CFDictionaryRef SecPolicyCopyProperties(SecPolicyRef policyRef) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Stub
*/
SecPolicyRef SecPolicyCreateBasicX509() {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Stub
*/
SecPolicyRef SecPolicyCreateSSL(Boolean server, CFStringRef hostname) {
    UNIMPLEMENTED();
    return nullptr;
}