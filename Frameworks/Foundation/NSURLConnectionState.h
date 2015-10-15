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

@interface NSURLConnectionState : NSObject {
@public
    BOOL _isRunning;
    id _error;
    idretain _wakeUp;
}
- (BOOL)isRunning;
/* annotate with type */ -(id)init;
/* annotate with type */ -(id)dealloc;
/* annotate with type */ -(id)receiveAllDataInMode : (id)mode;
/* annotate with type */ -(id)connection : (id)connection didReceiveData : (id)data;
/* annotate with type */ -(id)setError : (id)error;
/* annotate with type */ -(id)error;
/* annotate with type */ -(id)_doneWakeup;
/* annotate with type */ -(id)connection : (id)connection didFailWithError : (id)error;
/* annotate with type */ -(id)connectionDidFinishLoading : (id)connection;
@end
