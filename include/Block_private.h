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

struct of_block_descriptor_t {
    unsigned long reserved;
    unsigned long size;
    void (*copy_helper)(void* dest, void* src);
    void (*dispose_helper)(void* src);
    const char* signature;
};
struct Block_basic {
    void* isa;
    int flags;
    int reserved;
    void (*Block_invoke)(void*, ...);
    struct of_block_descriptor_t* descriptor;
};

struct Block_layout {
    void* isa;
    int flags;
    int reserved;
    void (*invoke)(void*, ...);
    struct of_block_descriptor_t* descriptor;
};
