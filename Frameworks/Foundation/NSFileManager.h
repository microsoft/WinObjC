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

@interface NSFileManager : NSObject {
@public
}
- (unsigned)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(DWORD)maxCount;
- (void)dealloc;
- (BOOL)fileExistsAtPath:(id)pathAddr;
- (BOOL)isReadableFileAtPath:(id)pathAddr;
- (BOOL)isWritableFileAtPath:(id)pathAddr;
- (BOOL)fileExistsAtPath:(id)pathAddr isDirectory:(unsigned char*)isDirectory;
- (BOOL)createDirectoryAtPath:(id)pathAddr attributes:(DWORD)attrs;
- (BOOL)createDirectoryAtPath:(id)pathAddr withIntermediateDirectories:(BOOL)createIntermediates attributes:(id)attrs error:(id*)err;
- (BOOL)createDirectoryAtURL:(id)url withIntermediateDirectories:(BOOL)createIntermediates attributes:(id)attrs error:(id*)err;
- (BOOL)changeCurrentDirectoryPath:(id)pathAddr;
- (BOOL)setAttributes:(id)attribs ofItemAtPath:(id)pathAddr error:(id*)err;
- (BOOL)removeItemAtPath:(id)pathAddr error:(id*)errRet;
- (BOOL)removeItemAtURL:(id)urlAddr error:(id*)errRet;
- (BOOL)createFileAtPath:(id)pathAddr contents:(id)contents attributes:(id)attributes;
- (BOOL)copyItemAtPath:(id)srcPath toPath:(id)destPath error:(id*)error;
- (BOOL)moveItemAtPath:(id)srcPath toPath:(id)destPath error:(id*)error;
- (const char*)fileSystemRepresentationWithPath:(id)pathAddr;
- (BOOL)contentsEqualAtPath:(id)pathObj1 andPath:(id)pathObj2;
- (void)dealloc;
/* annotate with type */ -(id)initWithPath : (const char*)path shallow : (BOOL)shallow;
/* annotate with type */ -(id)enumeratorAtPath : (id)pathAddr;
/* annotate with type */ -(id)directoryContentsAtPath : (id)pathAddr;
/* annotate with type */ -(id)contentsAtPath : (id)pathAddr;
/* annotate with type */ -(id)contentsOfDirectoryAtPath : (id)pathAddr error : (id*)err;
/* annotate with type */ -(id)fileAttributesAtPath : (id)pathAddr traverseLink : (DWORD)traveseLinks;
/* annotate with type */ -(id)stringWithFileSystemRepresentation : (char*)path length : (int)length;
/* annotate with type */ -(id)displayNameAtPath : (id)path;
/* annotate with type */ -(id)attributesOfItemAtPath : (id)pathAddr error : (id*)error;
/* annotate with type */ -(id)fileSystemAttributesAtPath : (id)pathAddr;
/* annotate with type */ -(id)attributesOfFileSystemForPath : (id)pathAddr error : (id*)error;
/* annotate with type */ -(id)destinationOfSymbolicLinkAtPath : (id)path error : (id*)error;
/* annotate with type */ -(id)URLsForDirectory : (DWORD)directory inDomains : (DWORD)domains;
/* annotate with type */ -(id)URLForDirectory : (DWORD)directory inDomain : (DWORD)domains appropriateForURL
                                                                            : (id)forURL create : (BOOL)create error : (id*)error;
@end
