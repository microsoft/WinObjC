/*
 * This file was modified by the Microsoft Corporation in 2015 as follows:
 *    Template the function on the output container type.
 *    Escape characters are considered to be part of a quoted token.
 *    The output container is not cleared before tokenizing.
 *    Added quote_preserve argument (same behaviour as delimiters_preserve).
 *    Added saveQuotedEscapes and saveEmptyTokens arguments.
 */

/************************************************************************
The zlib/libpng License

Copyright (c) 2006 Joerg Wiedenmann

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from
the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
  you must not claim that you wrote the original software.
  If you use this software in a product, an acknowledgment
  in the product documentation would be appreciated but is
  not required.

2. Altered source versions must be plainly marked as such,
  and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.

***********************************************************************/

/********************************************************************
  created:  2006-01-28
  filename:   tokenizer.cpp
  author:   Jörg Wiedenmann

  purpose:  A tokenizer function which provides a very
        customizable way of breaking up strings.
*********************************************************************/

#pragma once

#include <string>
using namespace std;

// Function to break up a string into tokens
//
// Parameters:
//-----------
// str = the input string that will be tokenized
// result = the tokens for str
// delimiters = the delimiter characters
// delimiters preserve = same as above, but the delimiter characters
//    will be put into the result as a token
// quote = characters to protect the enclosed characters
// quote preserve = quotes that are added to the token
// esc = characters to protect a single character
//

template <typename T>
void tokenize(const string& str,
              T& result,
              const string& delimiters,
              const string& delimiters_preserve = "",
              const string& quote = "\"",
              const string& quote_preserve = "",
              const string& esc = "\\",
              bool saveQuotedEscapes = false,
              bool saveEmptyTokens = false);
