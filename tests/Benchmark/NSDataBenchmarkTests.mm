//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <Starboard/SmartTypes.h>
#import "Benchmark.h"
#import <CppUtils.h>

class EncodeStringWithOptions : public ::benchmark::BenchmarkCaseBase {
    StrongId<NSMutableData> m_data;

public:
    EncodeStringWithOptions() 
        : m_data ([NSMutableData dataWithLength : 3 * 1024 * 1024]){
    }

    inline void Run() {
        NSString* str = [m_data base64EncodedStringWithOptions : NSDataBase64Encoding64CharacterLineLength];
    }

    void PostRun() {
    }

    size_t GetRunCount() const {
        return 10;
    }
};

BENCHMARK_F(NSData, EncodeStringWithOptions);

