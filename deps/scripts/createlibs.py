import subprocess, sys

BUILD_MSBUILD_LIBS = False
VCVARSALL_PATH = '"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall.bat"'
MSBUILD_PATH = '"C:\\program files (x86)\\msbuild\\14.0\\bin\\msbuild.exe"'
THIRDPARTY_PATH = '..\\3rdparty\\'

LIBJPEG_PROJ = '..\\3rdparty\\libjpeg\\build\\libjpegWin10\\libjpeg.vcxproj'
LIBXML_PROJ = '..\\3rdparty\\libxml2legacy\\Win10\\libxml2.Win10.vcxproj'
PIXMAN_PROJ = '..\\3rdparty\\pixmanlegacy\\Win10\\pixmanlegacy.Windows10\\pixmanlegacy.Windows10.vcxproj'
OPENAL_PROJ = '..\\3rdparty\\openal-soft-winphone\\winrt.vs2015\\OpenAL\\OpenAL.vcxproj'
CASSOWARY_PROJ = '..\\3rdparty\\cassowary-0.60\\cassowary-0.60-Windows.vcxproj'
LIBOBJC_PROJ = '..\\3rdparty\\libobjc2\\msvc\\libobjc2.vcxproj'
LIBDISPATCH_PROJ = '..\\3rdparty\\libdispatch\\build\\libdispatch.vcxproj'

RELEASE_X86 = '/p:Configuration=Release;Platform=x86'
RELEASE_X64 = '/p:Configuration=Release;Platform=x64'
RELEASE_ARM = '/p:Configuration=Release;Platform=ARM'
DEBUG_X86 = '/p:Configuration=Debug;Platform=x86'
DEBUG_X64 = '/p:Configuration=Debug;Platform=x64'
DEBUG_ARM = '/p:Configuration=Debug;Platform=ARM'

def run():
    if BUILD_MSBUILD_LIBS == True:
        subprocess.call(MSBUILD_PATH + ' ' + LIBJPEG_PROJ + ' ' + RELEASE_X86)
        subprocess.call(MSBUILD_PATH + ' ' + LIBJPEG_PROJ + ' ' + RELEASE_X64)
        subprocess.call(MSBUILD_PATH + ' ' + LIBJPEG_PROJ + ' ' + RELEASE_ARM)

        subprocess.call(MSBUILD_PATH + ' ' + LIBXML_PROJ + ' ' + RELEASE_X86)
        subprocess.call(MSBUILD_PATH + ' ' + LIBXML_PROJ + ' ' + RELEASE_X64)
        subprocess.call(MSBUILD_PATH + ' ' + LIBXML_PROJ + ' ' + RELEASE_ARM)

        subprocess.call(MSBUILD_PATH + ' ' + PIXMAN_PROJ + ' ' + RELEASE_X86)
        subprocess.call(MSBUILD_PATH + ' ' + PIXMAN_PROJ + ' ' + RELEASE_X64)
        subprocess.call(MSBUILD_PATH + ' ' + PIXMAN_PROJ + ' ' + RELEASE_ARM)

    print "Building freetype2"
    subprocess.call("python freetype2.py")
    print "Building zlib"
    subprocess.call("python zlib.py")
    print "Building libpng"
    subprocess.call("python libpng.py")

    print "Building cairo"
    subprocess.call(VCVARSALL_PATH + ' x86 && cairo.bat x86')
    subprocess.call(VCVARSALL_PATH + ' x86_x64 && cairo.bat x64')
    subprocess.call(VCVARSALL_PATH + ' x86_arm && cairo.bat arm')

    print "Building openssl"
    # Need to update openssl submodule
    #subprocess.call(".\openssl.bat ARM x86 x64")
    
    if BUILD_MSBUILD_LIBS == True:
        subprocess.call(MSBUILD_PATH + ' ' + OPENAL_PROJ + ' ' + RELEASE_X86)
        subprocess.call(MSBUILD_PATH + ' ' + OPENAL_PROJ + ' ' + RELEASE_X64)
        subprocess.call(MSBUILD_PATH + ' ' + OPENAL_PROJ + ' ' + RELEASE_ARM)

        subprocess.call(MSBUILD_PATH + ' ' + CASSOWARY_PROJ + ' ' + RELEASE_X86)
        subprocess.call(MSBUILD_PATH + ' ' + CASSOWARY_PROJ + ' ' + RELEASE_ARM)
        subprocess.call(MSBUILD_PATH + ' ' + CASSOWARY_PROJ + ' ' + DEBUG_X86)
        subprocess.call(MSBUILD_PATH + ' ' + CASSOWARY_PROJ + ' ' + DEBUG_ARM)

        subprocess.call(MSBUILD_PATH + ' ' + LIBOBJC_PROJ + ' ' + RELEASE_X86)
        subprocess.call(MSBUILD_PATH + ' ' + LIBOBJC_PROJ + ' ' + RELEASE_ARM)
        subprocess.call(MSBUILD_PATH + ' ' + LIBOBJC_PROJ + ' ' + DEBUG_X86)
        subprocess.call(MSBUILD_PATH + ' ' + LIBOBJC_PROJ + ' ' + DEBUG_ARM)

        subprocess.call(MSBUILD_PATH + ' ' + LIBDISPATCH_PROJ + ' ' + RELEASE_X86)
        subprocess.call(MSBUILD_PATH + ' ' + LIBDISPATCH_PROJ + ' ' + RELEASE_ARM)
        subprocess.call(MSBUILD_PATH + ' ' + LIBDISPATCH_PROJ + ' ' + DEBUG_X86)
        subprocess.call(MSBUILD_PATH + ' ' + LIBDISPATCH_PROJ + ' ' + DEBUG_ARM)

if __name__ == "__main__":
    if len(sys.argv) > 1:
        if sys.argv[1] == '1' or sys.argv[1] == 'true' or sys.argv[1] == 'True':
            BUILD_MSBUILD_LIBS = True;
    run()