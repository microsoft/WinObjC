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

#include <mutex>
#include <random>

namespace {

std::mutex s_rngGuard;
std::mt19937 s_rng;

}

extern "C" {

unsigned random() {
    std::lock_guard<std::mutex> lock(s_rngGuard);

    //  The expected range for random() is a value 0->0x7fffffff
    return (s_rng() >> 1);
}

void srandom(unsigned val) {
    std::lock_guard<std::mutex> lock(s_rngGuard);
    s_rng.seed(val);
}

}