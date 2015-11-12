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

@interface NSSocket : NSObject {
@public
    int _descriptor;
    id _sslHandler;
    BOOL _isConnected;
}
- (BOOL)operationWouldBlock;
- (int)write:(void*)buffer maxLength:(DWORD)length;
- (int)read:(void*)buffer maxLength:(DWORD)length;
- (int)descriptor;
- (void)setDescriptor:(int)descriptor;
- (int)hash;
- (BOOL)isEqual:(NSSocket*)other;
- (BOOL)hasBytesAvailable;
- (BOOL)setSSLProperties:(id)properties;
- (BOOL)isConnected;
- (id)initWithDescriptor:(int)descriptor;
- (id)initTCPStream;
- (id)errorForReturnValue:(int)returnValue;
- (id)setOperationWouldBlock:(BOOL)blocks;
- (id)initConnectedToSocket:(id*)otherX;
- (id)connectToHost:(id)host port:(int)portNumber immediate:(BOOL*)immediate;
- (id)close;
- (id)sslHandler;
+ (id)socketWithDescriptor:(int)descriptor;
@end
