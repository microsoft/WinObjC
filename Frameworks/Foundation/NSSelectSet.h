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

@interface NSSelectSet : NSObject {
@public
    id _readSet;
    id _writeSet;
    id _exceptionSet;
}
- (void)dealloc;
- (BOOL)isEmpty;
- (BOOL)containsObjectForRead:(id)object;
- (BOOL)containsObjectForWrite:(id)object;
- (BOOL)containsObjectForException:(id)object;
- (id)init;
- (id)addObjectForRead:(id)object;
- (id)addObjectForWrite:(id)object;
- (id)addObjectForException:(id)object;
- (id)waitForSelectWithOutputSet:(id*)outputSetX beforeDate:(id)beforeDate;
@end
