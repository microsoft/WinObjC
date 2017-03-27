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

#include "PlistFuncs.h"
#include "SBLog.h"
#include "PBXFile.h"
#include "PBXGroup.h"
#include "fileutils.h"

PBXFile::~PBXFile() {
}

PBXFile::PBXFile() : m_parent(NULL) {
}

void PBXFile::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXObject::initFromPlist(id, plist, pbxDoc);

    // Get path
    getStringForKey(plist, "path", m_path, VALUE_OPTIONAL, m_parseER);

    // Get name
    getStringForKey(plist, "name", m_name, VALUE_OPTIONAL, m_parseER);
    if (m_name.empty())
        m_name = sb_basename(m_path);

    // Get sourceTree
    getStringForKey(plist, "sourceTree", m_sourceTree, VALUE_REQUIRED, m_parseER);
}

const String& PBXFile::getFileType() const {
    static String unknownType("unknown");
    return unknownType;
}

String PBXFile::getFullPath() const {
    if (m_sourceTree == "<group>") {
        String parentPath("$(SOURCE_ROOT)");
        if (m_parent)
            parentPath = m_parent->getFullPath();

        if (m_path.empty())
            return parentPath;
        else
            return joinPaths(parentPath, m_path, false);
    } else if (m_sourceTree == "<absolute>") {
        return m_path;
    } else {
        return joinPaths("$(" + m_sourceTree + ")", m_path, false);
    }
}

String PBXFile::getVirtualPath() const {
    if (!m_parent)
        return "";

    String parentPath = m_parent->getVirtualPath();
    if (m_name.empty())
        return parentPath;
    else
        return joinPaths(parentPath, m_name);
}

String PBXFile::getFileType(const String& fileName) {
    // Get the lowercase extension
    std::string ext = sb_fextension(sb_basename(fileName));
    for (int i = 0; i < ext.length(); i++)
        ext[i] = tolower(ext[i]);

    if (ext == "c")
        return "sourcecode.c.c";
    else if (ext == "cpp" || ext == "cc" || ext == "cxx")
        return "sourcecode.cpp.cpp";
    else if (ext == "m")
        return "sourcecode.c.objc";
    else if (ext == "mm" || ext == "mxx")
        return "sourcecode.cpp.objcpp";
    else if (ext == "s")
        return "sourcecode.asm";
    else if (ext == "h" || ext == "pch")
        return "sourcecode.c.h";
    else if (ext == "hpp" || ext == "hh")
        return "sourcecode.cpp.h";
    else if (ext == "d")
        return "sourcecode.dtrace";
    else if (ext == "png")
        return "image.png";
    else if (ext == "tiff")
        return "image.tiff";
    else if (ext == "jpg" || ext == "jpeg")
        return "image.jpeg";
    else if (ext == "mp3")
        return "audio.mp3";
    else if (ext == "xib")
        return "file.xib";
    else if (ext == "nib" || ext == "nib~")
        return "file.xib";
    else if (ext == "plist" || ext == "dict")
        return "text.plist.xml";
    else if (ext == "strings")
        return "text.plist.strings";
    else if (ext == "storyboard")
        return "file.storyboard";
    else if (ext == "storyboardc")
        return "wrapper.storyboardc";
    else if (ext == "xcdatamodel")
        return "wrapper.xcdatamodel";
    else if (ext == "xcdatamodeld")
        return "wrapper.xcdatamodeld";
    else if (ext == "o" || ext == "obj")
        return "compiled.mach-o.objfile";
    else if (ext == "bundle")
        return "wrapper.plug-in";
    else if (ext == "xcassets")
        return "folder.assetcatalog";
    else if (ext == ".app")
        return "wrapper.application";
    else if (ext == ".a")
        return "archive.ar";
    else
        return "text";
}
