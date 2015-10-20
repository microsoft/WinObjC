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
/* annotate with type */ -(id)initWithDescriptor : (int)descriptor;
/* annotate with type */ -(id)initTCPStream;
/* annotate with type */ -(id)errorForReturnValue : (int)returnValue;
/* annotate with type */ -(id)setOperationWouldBlock : (BOOL)blocks;
/* annotate with type */ -(id)initConnectedToSocket : (id*)otherX;
/* annotate with type */ -(id)connectToHost : (id)host port : (int)portNumber immediate : (BOOL*)immediate;
/* annotate with type */ -(id)close;
/* annotate with type */ -(id)sslHandler;
/* annotate with type */ +(id)socketWithDescriptor : (int)descriptor;
@end
