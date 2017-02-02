#//******************************************************************************
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

#pragma once
#include <string>
#include <vector>
#include <memory>

namespace benchmark {
using Microseconds = double;

class BenchmarkTestPublisher {
public:
    virtual void RegisterTestResults(const std::string& testName, const std::vector<Microseconds>& results) = 0;
    virtual void PublishTestResults() = 0;
};

class BenchmarkTestCreator {
public:
    static void CreatePublisher(int argc, char** argv);
    static std::shared_ptr<BenchmarkTestPublisher> GetPublisher();
};
}