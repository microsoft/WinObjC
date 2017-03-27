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

#ifndef _SPLITSTREAM_H_
#define _SPLITSTREAM_H_

#include <iostream>
#include <vector>

class SplitStream {
public:
    SplitStream() {
    }
    SplitStream(std::ostream& s) : m_ostreams(1, &s) {
    }
    void addStream(std::ostream& s) {
        m_ostreams.push_back(&s);
    }
    void clear() {
        m_ostreams.clear();
    }

    SplitStream& operator<<(std::ostream& (*sfun)(std::ostream&)) {
        for (OStreamVecIt it = m_ostreams.begin(); it != m_ostreams.end(); ++it)
            sfun(**it);
        return *this;
    }

    template <class T>
    inline SplitStream& operator<<(T val) {
        for (OStreamVecIt it = m_ostreams.begin(); it != m_ostreams.end(); ++it)
            **it << val;
        return *this;
    }

private:
    typedef std::vector<std::ostream*> OStreamVec;
    typedef OStreamVec::iterator OStreamVecIt;

    OStreamVec m_ostreams;
};

#endif /* _SPLITSTREAM_H_ */