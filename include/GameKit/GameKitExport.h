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
#ifndef GAMEKIT_IMPEXP
#define GAMEKIT_IMPEXP __declspec(dllimport)
#endif

#ifndef GAMEKIT_EXPORT
#ifdef __cplusplus
#define GAMEKIT_EXPORT GAMEKIT_IMPEXP extern "C"
#define GAMEKIT_EXPORT_CLASS GAMEKIT_IMPEXP
#else
#define GAMEKIT_EXPORT GAMEKIT_IMPEXP extern
#define GAMEKIT_EXPORT_CLASS GAMEKIT_IMPEXP
#endif
#endif
