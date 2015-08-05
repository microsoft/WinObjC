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

#include "miscutils.h"
#include <time.h>

String getTime()
{
  time_t rawtime;
  time(&rawtime);
  return ctime(&rawtime);
}

double getEpochTime()
{
  time_t now;
  time(&now);
  struct tm start = {0, 0, 0, 0, 0};
  return difftime(now, mktime(&start));
}

void removeDupes(StringVec& vec)
{
  StringSet found;
  StringVec ret;

  StringVec::const_iterator it = vec.begin();
  for (; it != vec.end(); it++) {
    if (found.insert(*it).second)
      ret.push_back(*it);
  }

  vec.assign(ret.begin(), ret.end());
}