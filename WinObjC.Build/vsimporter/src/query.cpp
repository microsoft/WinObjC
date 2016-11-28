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

#include "query.h"

#include <limits>
#include <iostream>
#include <iterator>

#include "utils.h"
#include "sbassert.h"
#include "XCScheme.h"
#include "PBXTarget.h"
#include "XCBuildConfiguration.h"

bool queryBoolSelection(const String& queryMessage)
{
  String action;
  do {
    std::cout << queryMessage << " [Y,n]: ";
    
    getline(std::cin, action);
    action = strToLower(action);
    
    if (action.empty())
      action = "y";
  } while(action != "y" && action != "n");

  std::cout << std::endl;

  if (action == "y") {
    return true;
  } else { // "n"
    return false;
  }
}

static bool parseListSelection(const String& selection, size_t upperBound, std::set<size_t>& ret)
{
  // Tokenize the comma-separated list
  StringVec tokens;
  tokenize(selection, tokens, ",", "", "", "", "", false, false);

  ret.clear();
  for (const String& token : tokens) {
    String trimmedToken = trim(token);
    int num = -1;
    size_t sz;
    try {
      num = std::stoi(trimmedToken, &sz);
    } catch (...) {}

    // Make sure the whole token was parsed and the value is valid
    if (sz == trimmedToken.length() && num >= 0 && num <= upperBound) {
      ret.insert(num);
    } else {
      return false;
    }
  }

  return ret.size() > 0;
}

void queryListSelection(const StringVec& values, const String& queryMessage, const String& itemName, std::vector<size_t>& ret)
{
  std::set<size_t> selection;
  if (values.size() == 1) {
    selection.insert(1);
  } else if (values.size() > 1) {
    std::cout << queryMessage << std::endl;
    std::cout << "  0) " << strToUpper("all " + itemName + "s") << std::endl;
    for (int i = 0; i < values.size(); i++) {
      std::cout << "  " << i + 1 << ") " << values[i] << std::endl;
    }
    
    String input;
    do {
      std::cout << "Enter comma-separated list of " << itemName << "(s) to import: ";
      getline(cin, input);
    } while(!parseListSelection(input, values.size(), selection));
    std::cout << std::endl;
  }

  ret.clear();
  if (selection.find(0) != selection.end()) {
    for (size_t i = 0; i < values.size(); ++i) { ret.push_back(i); }
  } else {
    std::transform(selection.begin(),
                   selection.end(),
                   back_inserter(ret),
                   [](size_t n) { return n - 1; });
  }
}