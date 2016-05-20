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

typedef unsigned int mach_port_type_t;

#define MACH_PORT_NULL NULL

enum mach_port_type {
    MACH_PORT_RIGHT_SEND = 1,
    MACH_PORT_RIGHT_RECEIVE = 1 << 1,
    MACH_PORT_TYPE_PORT_RIGHTS = 1 << 2,
    MACH_PORT_TYPE_DEAD_NAME = 1 << 3,
    MACH_PORT_TYPE_SEND_RIGHTS = 1 << 4,
};