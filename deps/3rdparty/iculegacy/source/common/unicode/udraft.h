/*
*******************************************************************************
*   Copyright (C) 2004-2011, International Business Machines
*   Corporation and others.  All Rights Reserved.
*******************************************************************************
*
*   file name:  udraft.h
*   encoding:   US-ASCII
*   tab size:   8 (not used)
*   indentation:4
*
*   Created by: genheaders.pl, a perl script written by Ram Viswanadha
*
*  Contains data for commenting out APIs.
*  Gets included by umachine.h
*
*  THIS FILE IS MACHINE-GENERATED, DON'T PLAY WITH IT IF YOU DON'T KNOW WHAT
*  YOU ARE DOING, OTHERWISE VERY BAD THINGS WILL HAPPEN!
*/

#ifndef UDRAFT_H
#define UDRAFT_H

#ifdef U_HIDE_DRAFT_API

#    if U_DISABLE_RENAMING
#        define StringPiece StringPiece_DRAFT_API_DO_NOT_USE
#        define ubidi_getBaseDirection ubidi_getBaseDirection_DRAFT_API_DO_NOT_USE
#        define ubidi_setContext ubidi_setContext_DRAFT_API_DO_NOT_USE
#        define ucal_getFieldDifference ucal_getFieldDifference_DRAFT_API_DO_NOT_USE
#        define ucal_openTimeZoneIDEnumeration ucal_openTimeZoneIDEnumeration_DRAFT_API_DO_NOT_USE
#        define ucnv_isFixedWidth ucnv_isFixedWidth_DRAFT_API_DO_NOT_USE
#        define ucol_getEquivalentReorderCodes ucol_getEquivalentReorderCodes_DRAFT_API_DO_NOT_USE
#        define ucol_getReorderCodes ucol_getReorderCodes_DRAFT_API_DO_NOT_USE
#        define ucol_setReorderCodes ucol_setReorderCodes_DRAFT_API_DO_NOT_USE
#        define ucurr_isAvailable ucurr_isAvailable_DRAFT_API_DO_NOT_USE
#        define uidna_close uidna_close_DRAFT_API_DO_NOT_USE
#        define uidna_openUTS46 uidna_openUTS46_DRAFT_API_DO_NOT_USE
#        define uloc_forLanguageTag uloc_forLanguageTag_DRAFT_API_DO_NOT_USE
#        define uloc_toLanguageTag uloc_toLanguageTag_DRAFT_API_DO_NOT_USE
#        define unorm2_getDecomposition unorm2_getDecomposition_DRAFT_API_DO_NOT_USE
#        define uregex_end64 uregex_end64_DRAFT_API_DO_NOT_USE
#        define uregex_find64 uregex_find64_DRAFT_API_DO_NOT_USE
#        define uregex_getFindProgressCallback uregex_getFindProgressCallback_DRAFT_API_DO_NOT_USE
#        define uregex_lookingAt64 uregex_lookingAt64_DRAFT_API_DO_NOT_USE
#        define uregex_matches64 uregex_matches64_DRAFT_API_DO_NOT_USE
#        define uregex_patternUText uregex_patternUText_DRAFT_API_DO_NOT_USE
#        define uregex_regionEnd64 uregex_regionEnd64_DRAFT_API_DO_NOT_USE
#        define uregex_regionStart64 uregex_regionStart64_DRAFT_API_DO_NOT_USE
#        define uregex_reset64 uregex_reset64_DRAFT_API_DO_NOT_USE
#        define uregex_setFindProgressCallback uregex_setFindProgressCallback_DRAFT_API_DO_NOT_USE
#        define uregex_setRegion64 uregex_setRegion64_DRAFT_API_DO_NOT_USE
#        define uregex_setRegionAndStart uregex_setRegionAndStart_DRAFT_API_DO_NOT_USE
#        define uregex_start64 uregex_start64_DRAFT_API_DO_NOT_USE
#        define uscript_getScriptExtensions uscript_getScriptExtensions_DRAFT_API_DO_NOT_USE
#        define uscript_hasScript uscript_hasScript_DRAFT_API_DO_NOT_USE
#    else
#        define StringPiece_48 StringPiece_DRAFT_API_DO_NOT_USE
#        define ubidi_getBaseDirection_48 ubidi_getBaseDirection_DRAFT_API_DO_NOT_USE
#        define ubidi_setContext_48 ubidi_setContext_DRAFT_API_DO_NOT_USE
#        define ucal_getFieldDifference_48 ucal_getFieldDifference_DRAFT_API_DO_NOT_USE
#        define ucal_openTimeZoneIDEnumeration_48 ucal_openTimeZoneIDEnumeration_DRAFT_API_DO_NOT_USE
#        define ucnv_isFixedWidth_48 ucnv_isFixedWidth_DRAFT_API_DO_NOT_USE
#        define ucol_getEquivalentReorderCodes_48 ucol_getEquivalentReorderCodes_DRAFT_API_DO_NOT_USE
#        define ucol_getReorderCodes_48 ucol_getReorderCodes_DRAFT_API_DO_NOT_USE
#        define ucol_setReorderCodes_48 ucol_setReorderCodes_DRAFT_API_DO_NOT_USE
#        define ucurr_isAvailable_48 ucurr_isAvailable_DRAFT_API_DO_NOT_USE
#        define uidna_close_48 uidna_close_DRAFT_API_DO_NOT_USE
#        define uidna_openUTS46_48 uidna_openUTS46_DRAFT_API_DO_NOT_USE
#        define uloc_forLanguageTag_48 uloc_forLanguageTag_DRAFT_API_DO_NOT_USE
#        define uloc_toLanguageTag_48 uloc_toLanguageTag_DRAFT_API_DO_NOT_USE
#        define unorm2_getDecomposition_48 unorm2_getDecomposition_DRAFT_API_DO_NOT_USE
#        define uregex_end64_48 uregex_end64_DRAFT_API_DO_NOT_USE
#        define uregex_find64_48 uregex_find64_DRAFT_API_DO_NOT_USE
#        define uregex_getFindProgressCallback_48 uregex_getFindProgressCallback_DRAFT_API_DO_NOT_USE
#        define uregex_lookingAt64_48 uregex_lookingAt64_DRAFT_API_DO_NOT_USE
#        define uregex_matches64_48 uregex_matches64_DRAFT_API_DO_NOT_USE
#        define uregex_patternUText_48 uregex_patternUText_DRAFT_API_DO_NOT_USE
#        define uregex_regionEnd64_48 uregex_regionEnd64_DRAFT_API_DO_NOT_USE
#        define uregex_regionStart64_48 uregex_regionStart64_DRAFT_API_DO_NOT_USE
#        define uregex_reset64_48 uregex_reset64_DRAFT_API_DO_NOT_USE
#        define uregex_setFindProgressCallback_48 uregex_setFindProgressCallback_DRAFT_API_DO_NOT_USE
#        define uregex_setRegion64_48 uregex_setRegion64_DRAFT_API_DO_NOT_USE
#        define uregex_setRegionAndStart_48 uregex_setRegionAndStart_DRAFT_API_DO_NOT_USE
#        define uregex_start64_48 uregex_start64_DRAFT_API_DO_NOT_USE
#        define uscript_getScriptExtensions_48 uscript_getScriptExtensions_DRAFT_API_DO_NOT_USE
#        define uscript_hasScript_48 uscript_hasScript_DRAFT_API_DO_NOT_USE
#    endif /* U_DISABLE_RENAMING */

#endif /* U_HIDE_DRAFT_API */
#endif /* UDRAFT_H */

