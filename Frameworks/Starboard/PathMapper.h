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

//
// CPathMapper is a convenience class used to perform some basic path mapping.
//
// 1. construct with a path with either leading or backward slashes (converted internally to / by appendPath)
//      appendPath also mysteriously converts ~ to home.  This isn't quite helping anyone since there is no 'home' directory on windows.
//      we should simply drop this construct.
// 2. fixes up any relative paths
//      a) /src/../src ==> /src
//      b) /./src/winobjc/../ ==> /src
//      c) see fixPath tests in pathmappertests.mm for other supported scenarios (and bugs)
// 3. The fixed up relative path is passed to convert path
//      a) -> calls EbrGetRootMapping to replace special directories (ex: Documents, etc).  See pathmappertests.mm.
//      b) replaces / with \
//      c) removes any leading / introduced by fixPath
// 4. fixedPath is almost never used as real data, except in EbrOpenDir(), where its usage seems to be a bug.
//
// 5. mappedPath is the only real thing needed, so that is all we need to expose.
//
//

class CPathMapper {
public:
    const std::wstring& MappedPath() const {
        return mappedPath;
    }

    // constructor intentionally takes in char*, assumes UTF8 encoding.
    CPathMapper(const char* path);

    operator const wchar_t*() const {
        return mappedPath.c_str();
    }

    operator bool() const {
        return !mappedPath.empty();
    }

    static bool CreateDefaultPaths();

private:
    std::wstring mappedPath;
};
