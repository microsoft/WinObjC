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

#include "unicode/ucnv.h"
#include "unicode/ucol.h"
#include "unicode/brkiter.h"
#include "unicode/uniset.h"
#include "unicode/usearch.h"
#include <unicode/regex.h>

void InitICU();
UConverter* getASCIIConverter();
UConverter* getUTF8Converter();
UConverter* getUTF32BEConverter();
UCollator* getDefaultLocaleCollator();
UStringSearch* getSearchForOptions(uint32_t options);
BreakIterator* getWordIterator();
UnicodeSet* lettersSet();
id regexCachedPattern(id pattern, int regexOptions);
