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

template <class T>
void queryListSelection(const std::vector<T*>& vec, const String& queryMessage, const String& itemName, std::vector<T*>& ret)
{
  sbAssert(!vec.empty());

  size_t selection = 0;
  if (vec.size() > 1) {
    std::cout << queryMessage << std::endl;
    
    std::cout << "  0) " << strToUpper("all " + itemName + "s") << std::endl;
    for (int i = 0; i < vec.size(); i++)
      std::cout << "  " << i+1 << ") " << vec[i]->getName() << std::endl;
    
    do {
      std::cout << "Choose the " << itemName << "(s) to export: ";
      std::cin >> selection;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.sync();
      }
    } while(selection > vec.size());
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
  }

  std::cout << std::endl;

  if (selection == 0) {
    ret.insert(ret.end(), vec.begin(), vec.end());
  } else {
    ret.push_back(vec[selection - 1]);
  }
}

// Explicit instantiation
template void queryListSelection<const XCScheme>(const std::vector<const XCScheme*>& vec, const String& queryMessage, const String& itemName, std::vector<const XCScheme*>& ret);
template void queryListSelection<const PBXTarget>(const std::vector<const PBXTarget*>& vec, const String& queryMessage, const String& itemName, std::vector<const PBXTarget*>& ret);
template void queryListSelection<const XCBuildConfiguration>(const std::vector<const XCBuildConfiguration*>& vec, const String& queryMessage, const String& itemName, std::vector<const XCBuildConfiguration*>& ret);
