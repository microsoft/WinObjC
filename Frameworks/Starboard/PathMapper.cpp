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

#include "Starboard.h"
#include "ErrorHandling.h"
#include "StringHelpers.h"

#include <algorithm>
#include <list>

#include "Platform/EbrPlatform.h"
#include "PathMapper.h"

// utility function to tokenize string using delimiters
// d:\src/winobjc ==> d:, src, winobjc
// /src/winobjc ==> "", src, winobjc
// / ==> ""
// src ==> "src"

static const std::wstring c_currentDir(L".");
static const std::wstring c_UpDir(L"..");

static std::list<std::wstring> _TokenizeString(const std::wstring& str, const wchar_t* delims) {
    std::list<std::wstring> components;

    std::size_t start = 0; // start from 0
    std::size_t delimPos = str.find_first_of(delims);

    while (start != std::wstring::npos) {
        components.emplace_back(str.substr(start, delimPos - start));
        start = str.find_first_not_of(delims, delimPos);
        delimPos = str.find_first_of(delims, start);
    }
    return components;
}

// converts any ? to +, we may add more later if needed for compat

static void _EscapeIllegalPathCharacters(std::wstring& str) {
    std::size_t pos = str.find_first_of(L'?');
    while (pos != std::wstring::npos) {
        str[pos] = L'+';
        pos = str.find_first_of(L'?', pos + 1);
    }
}

// normalize relative path
// 1 remove any "." or "" components
// 2 remove any ".." and preceeding component
// 3 if components becomes empty, return "."

static void _NormalizeRelativePathComponents(std::list<std::wstring>& components) {
    for (auto it = components.begin(); it != components.end();) {
        if (*it == c_currentDir || it->empty()) {
            it = components.erase(it);
            continue;
        } else if (*it == c_UpDir) {
            // remove previous component if it exists
            if (it == components.begin()) {
                // error, no previous directory exists
                components.clear();
                break;
            }
            // we have to do this in case the last component is ..
            // erase the previous component first because erase returns the next item
            // which would be "..".
            it = components.erase(--it);
            it = components.erase(it);
        } else {
            ++it;
        }
    }

    if (components.empty()) {
        components.emplace_back(c_currentDir);
    }
}

// the first component could have special meaning, we map it here
static const std::wstring c_specialFolders[] = { L"Documents", L"cache", L"Library", L"AppSupport", L"tmp", L"shared" };

std::wstring _MapPathRoot(const std::wstring& root) {
    if (root == c_currentDir) {
        return root;
    } else if (root == L"~") {
        return std::wstring(L".\\home");
    }

    if (root.length() == 2 && iswalpha(root[0]) && root[1] == L':') {
        return root;
    }

    for (auto folder : c_specialFolders) {
        if (_wcsicmp(root.c_str(), folder.c_str()) == 0) {
            return IwGetWritableFolder() + std::wstring(L"\\") + folder;
        }
    }

    return std::wstring(L".\\") + root;
}

std::wstring _PathFromComponents(const std::list<std::wstring>& components) {
    std::wstring path = components.front();

    auto it = components.begin();

    std::for_each(++it, components.end(), [&path](const std::wstring& comp) {
        path += std::wstring(L"\\");
        path += comp;
    });
    _EscapeIllegalPathCharacters(path);
    return path;
}

CPathMapper::CPathMapper(const char* path) {
    // create default paths once
    static bool createDefaultPaths = CreateDefaultPaths();

    std::wstring wpath = Strings::NarrowToWide<std::wstring>(path);
    std::list<std::wstring> components = _TokenizeString(wpath, L"/\\");

    _NormalizeRelativePathComponents(components);
    components.front() = _MapPathRoot(components.front());
    mappedPath = _PathFromComponents(components);
}

bool CPathMapper::CreateDefaultPaths() {
    for (auto folder : c_specialFolders) {
        _wmkdir((IwGetWritableFolder() + std::wstring(L"\\") + folder).c_str());
    }
    // also create "Documents\\Library"
    _wmkdir((IwGetWritableFolder() + std::wstring(L"\\Documents\\Library")).c_str());

    return true;
}
