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

#include "utils.h"
#include "sbassert.h"
#include "tokenizer.h"
#include "clangoptparser.h"

static String reduceLinkerToken(const String& token) {
    static const char* const _prefixes[] = { "-weak", "-reexport", "-lazy", "-upward" };
    static StringVec prefixes(_prefixes, _prefixes + sizeof(_prefixes) / sizeof(char*));

    StringVec::const_iterator pIt = prefixes.begin();
    for (; pIt != prefixes.end(); ++pIt) {
        size_t prefixLen = pIt->length();
        if (token.length() > prefixLen && strBeginsWith(token, *pIt) && (token[prefixLen] == '_' || token[prefixLen] == '-'))
            return "-" + token.substr(prefixLen + 1);
    }

    return token;
}

// "Expand" -Wl and -Xlinker tokens
// This is OK to do since we're interested in a small subset of flags.
// Preserving correctness is not important.
static void replaceWlArgs(const StringVec& inArgs, StringVec& outArgs) {
    for (auto arg : inArgs) {
        if (strBeginsWith(arg, "-Wl,")) {
            StringVec tokens;
            tokenize(arg, tokens, ",", "", "", "", "");
            outArgs.insert(outArgs.end(), tokens.begin() + 1, tokens.end());
        } else if (arg != "-Xlinker") {
            outArgs.push_back(arg);
        }
    }
}

void processLDFlags(const String& ldFlags, StringVec& libs) {
    // Tokenize flags
    StringVec ldFlagTokens;
    tokenize(ldFlags, ldFlagTokens, " \t", "", "\"'", "", "", true, false);

    // Expand -Wl, and -Xlinker tokens to make parsing easier
    StringVec ldFlagsFixed;
    replaceWlArgs(ldFlagTokens, ldFlagsFixed);

    String savedToken;
    for (auto opt : ldFlagsFixed) {
        if (savedToken.empty()) {
            opt = reduceLinkerToken(opt);
            if (opt == "-library" || opt == "-framework") {
                savedToken = opt;
            } else if (strBeginsWith(opt, "-l")) {
                String libName = strEndsWith(opt, ".o") ? opt.substr(2) : "lib" + opt.substr(2) + ".?";
                libs.push_back(libName);
            } else if (strEndsWith(opt, ".a") || strEndsWith(opt, ".dylib") || strEndsWith(opt, ".o")) {
                libs.push_back(opt);
            }
        } else {
            if (savedToken == "-library") {
                libs.push_back(opt);
            } else if (savedToken == "-framework") {
                std::string frameworkName = opt.substr(0, opt.find(',')) + ".framework";
                libs.push_back(frameworkName);
            }
            savedToken.clear();
        }
    }
}

static void reduceClangTokens(StringVec& otherFlagTokens) {
    String savedToken;
    auto tokensIt = otherFlagTokens.begin();
    while (tokensIt != otherFlagTokens.end()) {
        if (!savedToken.empty()) {
            *tokensIt = savedToken + *tokensIt;
            savedToken.clear();
        } else if (*tokensIt == "-I" || *tokensIt == "-iquote" || *tokensIt == "-F") {
            savedToken = *tokensIt;
            tokensIt = otherFlagTokens.erase(tokensIt);
            continue; // don't increment iterator
        }

        tokensIt++;
    }
}

static String makeRelativePath(const String& path, const String& oldProjDir, const String& newProjDir) {
    String absPath = joinPaths(oldProjDir, path);
    String relPath = getRelativePath(newProjDir, absPath);
    return winPath(relPath);
}

void processClangFlags(String& clangFlags, const String& absProjDirOld, const String& absProjDirNew) {
    // Tokenize the flags
    StringVec clangFlagTokens;
    tokenize(clangFlags, clangFlagTokens, " \t", "", "\"'", "", "", true, false);
    reduceClangTokens(clangFlagTokens);

    auto tokensIt = clangFlagTokens.begin();
    while (tokensIt != clangFlagTokens.end()) {
        if (strBeginsWith(*tokensIt, "-iquote")) {
            String newPath = makeRelativePath(tokensIt->substr(7), absProjDirOld, absProjDirNew);
            *tokensIt = "-iquote" + quoteIfNeeded(newPath);
        } else if (strBeginsWith(*tokensIt, "-I")) {
            String newPath = makeRelativePath(tokensIt->substr(2), absProjDirOld, absProjDirNew);
            *tokensIt = "-I" + quoteIfNeeded(newPath);
        } else if (strBeginsWith(*tokensIt, "-F")) {
            tokensIt = clangFlagTokens.erase(tokensIt);
            continue; // don't increment iterator
        } else {
            *tokensIt = quoteIfNeeded(*tokensIt);
        }

        tokensIt++;
    }

    clangFlags = joinStrings(clangFlagTokens, " ");
}