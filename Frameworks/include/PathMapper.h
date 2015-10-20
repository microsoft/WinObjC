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

class CPathMapper {
public:
    char mappedPath[4096];
    char fixedPath[4096];
    bool fixedValid, mappedValid;

    static char currentDir[4096];

    static void setCWD(const char* directory) {
        if (directory[0] != '/') {
            strcat_s(currentDir, directory);
        } else {
            strcpy_s(currentDir, directory);
        }
    }

    static void getCWD(char* directory) {
        strcpy_s(directory, 4095, currentDir);
    }

    char* FixedPath();
    char* MappedPath();

    CPathMapper(const char* path);
    operator const char*() {
        return mappedPath;
    }
};
