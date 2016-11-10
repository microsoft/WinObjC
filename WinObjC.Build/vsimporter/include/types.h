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

#ifndef _TYPES_H_
#define _TYPES_H_

#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <sstream>

typedef std::ostream OStream;
typedef std::ofstream OFStream;
typedef std::string String;
typedef std::stringstream StringStream;
typedef std::list<String> StringList;
typedef std::vector<String> StringVec;
typedef std::pair<String, String> StringPair;
typedef std::list<StringPair> StringPairList;
typedef std::set<String> StringSet;
typedef std::map<String, String> StringMap;

typedef std::vector<bool> BoolVec;

using std::size_t;

#endif /* _TYPES_H_ */
