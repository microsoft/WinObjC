/*
 * This file was modified by the Microsoft Corporation in 2015 as follows:
 *    Changed function to used chars instead of TCHARs
 *
 * ORIGIN: http://www.codeproject.com/Articles/188256/A-Simple-Wildcard-Matching-Function
 * LICENSE: http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef _WILDCARDMATCH_H_
#define _WILDCARDMATCH_H_

bool WildcardMatch(const char* pszString, const char* pszMatch);

#endif /* _WILDCARDMATCH_H_ */
