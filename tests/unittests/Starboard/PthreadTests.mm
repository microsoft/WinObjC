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

#include <TestFramework.h>
#include <pthread.h>

TEST(pthread, create_destroy) {
    ASSERT_NO_THROW(pthread_mutex_destroy(NULL));
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    ASSERT_NO_THROW(pthread_mutex_destroy(&mutex));
    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);
    ASSERT_NE((int)mutex, PTHREAD_MUTEX_INITIALIZER);
    ASSERT_NO_THROW(pthread_mutex_destroy(&mutex));
    ASSERT_EQ((int)mutex, PTHREAD_MUTEX_INITIALIZER);
}