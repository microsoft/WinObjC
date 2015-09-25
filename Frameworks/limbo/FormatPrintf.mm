//******************************************************************************
//
// Copyright (c) 1987, 1990, 1993, 2005 Vrije Universiteit, Amsterdam, The Netherlands.
// Copyright (c) 2015 Microsoft Corporation.
//
// All rights reserved.
//
// Redistribution and use of the Amsterdam Compiler Kit in source and
// binary forms, with or without modification, are permitted provided
// that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above
//      copyright notice, this list of conditions and the following
//      disclaimer in the documentation and/or other materials provided
//      with the distribution.
//
//    * Neither the name of Vrije Universiteit nor the names of the
//      software authors or contributors may be used to endorse or
//      promote products derived from this software without specific
//      prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS, AUTHORS, AND
// CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL VRIJE UNIVERSITEIT OR ANY AUTHORS OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
// BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//******************************************************************************

#include "Starboard.h"

typedef struct PrintOutput {
    int type;
    int pos;
    int len;
    WORD* s;
} PrintOutput;

typedef WORD PrintType;
#define PrintEncodingType NSUTF16StringEncoding
#define UTF8CStrings

static WORD PrintNullString[7] = { '(', 'n', 'u', 'l', 'l', ')', 0 };
static char PrintNullStringC[7] = { '(', 'n', 'u', 'l', 'l', ')', 0 };

#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define EbrPtr(ap, t) va_arg(ap, t)
#define EbrVal(ap, t) va_arg(ap, t)
#define EbrLongDouble(ap, t) va_arg(ap, long double)
#define EbrDouble(ap, t) va_arg(ap, double)

static int PrintPutC(int c, PrintOutput* input) {
    if (input->s == NULL) {
        input->pos++;
        return c;
    }

    if (input->pos >= (input->len & 0x7FFFFFFF)) {
        return EOF;
    }

    int clippedLen = input->len & 0x3FFFFFFF;
    if (input->pos < clippedLen) {
        if (input->s) {
            input->s[input->pos] = c;
        }
    }
    input->pos++;

    return c;
}

#define FL_LJUST 0x0001 /* left-justify field */
#define FL_SIGN 0x0002 /* sign in signed conversions */
#define FL_SPACE 0x0004 /* space in signed conversions */
#define FL_ALT 0x0008 /* alternate form */
#define FL_ZEROFILL 0x0010 /* fill with zero's */
#define FL_SHORT 0x0020 /* optional h */
#define FL_LONG 0x0040 /* optional l */
#define FL_LONGDOUBLE 0x0080 /* optional L */
#define FL_WIDTHSPEC 0x0100 /* field width is specified */
#define FL_PRECSPEC 0x0200 /* precision is specified */
#define FL_SIGNEDCONV 0x0400 /* may contain a sign */
#define FL_NOASSIGN 0x0800 /* do not assign (in scanf) */
#define FL_NOMORE 0x1000 /* all flags collected */
#define FL_LONGLONG 0x2000 /* long long */

struct mantissa {
    unsigned long h_32;
    unsigned long l_32;
};

struct EXTEND {
    short sign;
    short exp;
    struct mantissa mantissa;
#define m1 mantissa.h_32
#define m2 mantissa.l_32
};

#define NDIGITS 128
#define NSIGNIFICANT 19

static struct EXTEND big_ten_powers[] = { /* representation of 10 ** (28*i) */
                                          { 0, 0, 0x80000000, 0 },
                                          { 0, 93, 0x813F3978, 0xF8940984 },
                                          { 0, 186, 0x82818F12, 0x81ED44A0 },
                                          { 0, 279, 0x83C7088E, 0x1AAB65DB },
                                          { 0, 372, 0x850FADC0, 0x9923329E },
                                          { 0, 465, 0x865B8692, 0x5B9BC5C2 },
                                          { 0, 558, 0x87AA9AFF, 0x79042287 },
                                          { 0, 651, 0x88FCF317, 0xF22241E2 },
                                          { 0, 744, 0x8A5296FF, 0xE33CC930 },
                                          { 0, 837, 0x8BAB8EEF, 0xB6409C1A },
                                          { 0, 930, 0x8D07E334, 0x55637EB3 },
                                          { 0, 1023, 0x8E679C2F, 0x5E44FF8F },
                                          { 0, 1116, 0x8FCAC257, 0x558EE4E6 },
                                          { 0, 1209, 0x91315E37, 0xDB165AA9 },
                                          { 0, 1302, 0x929B7871, 0xDE7F22B9 },
                                          { 0, 1395, 0x940919BB, 0xD4620B6D },
                                          { 0, 1488, 0x957A4AE1, 0xEBF7F3D4 },
                                          { 0, 1581, 0x96EF14C6, 0x454AA840 },
                                          { 0, 1674, 0x98678061, 0x27ECE4F5 },
                                          { 0, 1767, 0x99E396C1, 0x3A3ACFF2 }
};

static struct EXTEND r_big_ten_powers[] = { /* representation of 10 ** -(28*i) */
                                            { 0, 0, 0x80000000, 0 },
                                            { 0, -94, 0xFD87B5F2, 0x8300CA0E },
                                            { 0, -187, 0xFB158592, 0xBE068D2F },
                                            { 0, -280, 0xF8A95FCF, 0x88747D94 },
                                            { 0, -373, 0xF64335BC, 0xF065D37D },
                                            { 0, -466, 0xF3E2F893, 0xDEC3F126 },
                                            { 0, -559, 0xF18899B1, 0xBC3F8CA2 },
                                            { 0, -652, 0xEF340A98, 0x172AACE5 },
                                            { 0, -745, 0xECE53CEC, 0x4A314EBE },
                                            { 0, -838, 0xEA9C2277, 0x23EE8BCB },
                                            { 0, -931, 0xE858AD24, 0x8F5C22CA },
                                            { 0, -1024, 0xE61ACF03, 0x3D1A45DF },
                                            { 0, -1117, 0xE3E27A44, 0x4D8D98B8 },
                                            { 0, -1210, 0xE1AFA13A, 0xFBD14D6E },
                                            { 0, -1303, 0xDF82365C, 0x497B5454 },
                                            { 0, -1396, 0xDD5A2C3E, 0xAB3097CC },
                                            { 0, -1489, 0xDB377599, 0xB6074245 },
                                            { 0, -1582, 0xD91A0545, 0xCDB51186 },
                                            { 0, -1675, 0xD701CE3B, 0xD387BF48 },
                                            { 0, -1768, 0xD4EEC394, 0xD6258BF8 }
};

static struct EXTEND ten_powers[] = { /* representation of 10 ** i */
                                      { 0, 0, 0x80000000, 0 },           { 0, 3, 0xA0000000, 0 },
                                      { 0, 6, 0xC8000000, 0 },           { 0, 9, 0xFA000000, 0 },
                                      { 0, 13, 0x9C400000, 0 },          { 0, 16, 0xC3500000, 0 },
                                      { 0, 19, 0xF4240000, 0 },          { 0, 23, 0x98968000, 0 },
                                      { 0, 26, 0xBEBC2000, 0 },          { 0, 29, 0xEE6B2800, 0 },
                                      { 0, 33, 0x9502F900, 0 },          { 0, 36, 0xBA43B740, 0 },
                                      { 0, 39, 0xE8D4A510, 0 },          { 0, 43, 0x9184E72A, 0 },
                                      { 0, 46, 0xB5E620F4, 0x80000000 }, { 0, 49, 0xE35FA931, 0xA0000000 },
                                      { 0, 53, 0x8E1BC9BF, 0x04000000 }, { 0, 56, 0xB1A2BC2E, 0xC5000000 },
                                      { 0, 59, 0xDE0B6B3A, 0x76400000 }, { 0, 63, 0x8AC72304, 0x89E80000 },
                                      { 0, 66, 0xAD78EBC5, 0xAC620000 }, { 0, 69, 0xD8D726B7, 0x177A8000 },
                                      { 0, 73, 0x87867832, 0x6EAC9000 }, { 0, 76, 0xA968163F, 0x0A57B400 },
                                      { 0, 79, 0xD3C21BCE, 0xCCEDA100 }, { 0, 83, 0x84595161, 0x401484A0 },
                                      { 0, 86, 0xA56FA5B9, 0x9019A5C8 }, { 0, 89, 0xCECB8F27, 0xF4200F3A }
};

static struct EXTEND r_ten_powers[] = { /* representation of 10 ** -i */
                                        { 0, 0, 0x80000000, 0 },
                                        { 0, -4, 0xCCCCCCCC, 0xCCCCCCCD },
                                        { 0, -7, 0xA3D70A3D, 0x70A3D70A },
                                        { 0, -10, 0x83126E97, 0x8D4FDF3B },
                                        { 0, -14, 0xD1B71758, 0xE219652C },
                                        { 0, -17, 0xA7C5AC47, 0x1B478423 },
                                        { 0, -20, 0x8637BD05, 0xAF6C69B6 },
                                        { 0, -24, 0xD6BF94D5, 0xE57A42BC },
                                        { 0, -27, 0xABCC7711, 0x8461CEFD },
                                        { 0, -30, 0x89705F41, 0x36B4A597 },
                                        { 0, -34, 0xDBE6FECE, 0xBDEDD5BF },
                                        { 0, -37, 0xAFEBFF0B, 0xCB24AAFF },
                                        { 0, -40, 0x8CBCCC09, 0x6F5088CC },
                                        { 0, -44, 0xE12E1342, 0x4BB40E13 },
                                        { 0, -47, 0xB424DC35, 0x095CD80F },
                                        { 0, -50, 0x901D7CF7, 0x3AB0ACD9 },
                                        { 0, -54, 0xE69594BE, 0xC44DE15B },
                                        { 0, -57, 0xB877AA32, 0x36A4B449 },
                                        { 0, -60, 0x9392EE8E, 0x921D5D07 },
                                        { 0, -64, 0xEC1E4A7D, 0xB69561A5 },
                                        { 0, -67, 0xBCE50864, 0x92111AEB },
                                        { 0, -70, 0x971DA050, 0x74DA7BEF },
                                        { 0, -74, 0xF1C90080, 0xBAF72CB1 },
                                        { 0, -77, 0xC16D9A00, 0x95928A27 },
                                        { 0, -80, 0x9ABE14CD, 0x44753B53 },
                                        { 0, -84, 0xF79687AE, 0xD3EEC551 },
                                        { 0, -87, 0xC6120625, 0x76589DDB },
                                        { 0, -90, 0x9E74D1B7, 0x91E07E48 }
};

#define TP (int)(sizeof(ten_powers) / sizeof(ten_powers[0]))
#define BTP (int)(sizeof(big_ten_powers) / sizeof(big_ten_powers[0]))
#define MAX_EXP (TP * BTP - 1)

static void mul_ext(struct EXTEND* e1, struct EXTEND* e2, struct EXTEND* e3)
/* [<][>][^][v][top][bottom][index][help] */
{
    /*      Multiply the extended numbers e1 and e2, and put the
    result in e3.
    */
    register int i, j; /* loop control */
    unsigned short mp[4];
    unsigned short mc[4];
    unsigned short result[8]; /* result */

    register unsigned short* pres;

    /* first save the sign (XOR)                    */
    e3->sign = e1->sign ^ e2->sign;

    /* compute new exponent */
    e3->exp = e1->exp + e2->exp + 1;

    /* check for overflow/underflow ??? */

    /* 128 bit multiply of mantissas        */

    /* assign unknown long formats          */
    /* to known unsigned word formats       */
    mp[0] = e1->m1 >> 16;
    mp[1] = (unsigned short)e1->m1;
    mp[2] = e1->m2 >> 16;
    mp[3] = (unsigned short)e1->m2;
    mc[0] = e2->m1 >> 16;
    mc[1] = (unsigned short)e2->m1;
    mc[2] = e2->m2 >> 16;
    mc[3] = (unsigned short)e2->m2;
    for (i = 8; i--;) {
        result[i] = 0;
    }
    /*
    *      fill registers with their components
    */
    for (i = 4, pres = &result[4]; i--; pres--)
        if (mp[i]) {
            unsigned short k = 0;
            unsigned long mpi = mp[i];
            for (j = 4; j--;) {
                unsigned long tmp = (unsigned long)pres[j] + k;
                if (mc[j])
                    tmp += mpi * mc[j];
                pres[j] = (unsigned short)tmp;
                k = tmp >> 16;
            }
            pres[-1] = k;
        }

    if (!(result[0] & 0x8000)) {
        e3->exp--;
        for (i = 0; i <= 3; i++) {
            result[i] <<= 1;
            if (result[i + 1] & 0x8000)
                result[i] |= 1;
        }
        result[4] <<= 1;
    }
    /*
    *      combine the registers to a total
    */
    e3->m1 = ((unsigned long)(result[0]) << 16) + result[1];
    e3->m2 = ((unsigned long)(result[2]) << 16) + result[3];
    if (result[4] & 0x8000) {
        if (++e3->m2 == 0) {
            if (++e3->m1 == 0) {
                e3->m1 = 0x80000000;
                e3->exp++;
            }
        }
    }
}

static int b64_add(struct mantissa* e1, struct mantissa* e2)
/* [<][>][^][v][top][bottom][index][help] */
/*
* pointers to 64 bit 'registers'
*/
{
    register int overflow;
    int carry;

    /* add higher pair of 32 bits */
    overflow = ((unsigned long)0xFFFFFFFF - e1->h_32 < e2->h_32);
    e1->h_32 += e2->h_32;

    /* add lower pair of 32 bits */
    carry = ((unsigned long)0xFFFFFFFF - e1->l_32 < e2->l_32);
    e1->l_32 += e2->l_32;
    if ((carry) && (++e1->h_32 == 0))
        return (1); /* had a 64 bit overflow */
    else
        return (overflow); /* return status from higher add */
}

static void b64_sft(struct mantissa* e1, int n)
/* [<][>][^][v][top][bottom][index][help] */
{
    if (n > 0) {
        if (n > 63) {
            e1->l_32 = 0;
            e1->h_32 = 0;
            return;
        }
        if (n >= 32) {
            e1->l_32 = e1->h_32;
            e1->h_32 = 0;
            n -= 32;
        }
        if (n > 0) {
            e1->l_32 >>= n;
            if (e1->h_32 != 0) {
                e1->l_32 |= (e1->h_32 << (32 - n));
                e1->h_32 >>= n;
            }
        }
        return;
    }
    n = -n;
    if (n > 0) {
        if (n > 63) {
            e1->l_32 = 0;
            e1->h_32 = 0;
            return;
        }
        if (n >= 32) {
            e1->h_32 = e1->l_32;
            e1->l_32 = 0;
            n -= 32;
        }
        if (n > 0) {
            e1->h_32 <<= n;
            if (e1->l_32 != 0) {
                e1->h_32 |= (e1->l_32 >> (32 - n));
                e1->l_32 <<= n;
            }
        }
    }
}

static void add_ext(struct EXTEND* e1, struct EXTEND* e2, struct EXTEND* e3)
/* [<][>][^][v][top][bottom][index][help] */
{
    /*      Add two extended numbers e1 and e2, and put the result
    in e3
    */
    struct EXTEND ce2;
    int diff;

    if ((e2->m1 | e2->m2) == 0L) {
        *e3 = *e1;
        return;
    }
    if ((e1->m1 | e1->m2) == 0L) {
        *e3 = *e2;
        return;
    }
    ce2 = *e2;
    *e3 = *e1;
    e1 = &ce2;

    /* adjust mantissas to equal power */
    diff = e3->exp - e1->exp;
    if (diff < 0) {
        diff = -diff;
        e3->exp += diff;
        b64_sft(&(e3->mantissa), diff);
    } else if (diff > 0) {
        e1->exp += diff;
        b64_sft(&(e1->mantissa), diff);
    }
    if (e1->sign != e3->sign) {
        /* e3 + e1 = e3 - (-e1) */
        if (e1->m1 > e3->m1 || (e1->m1 == e3->m1 && e1->m2 > e3->m2)) {
            /*      abs(e1) > abs(e3) */
            if (e3->m2 > e1->m2) {
                e1->m1 -= 1; /* carry in */
            }
            e1->m1 -= e3->m1;
            e1->m2 -= e3->m2;
            *e3 = *e1;
        } else {
            if (e1->m2 > e3->m2)
                e3->m1 -= 1; /* carry in */
            e3->m1 -= e1->m1;
            e3->m2 -= e1->m2;
        }
    } else {
        if (b64_add(&e3->mantissa, &e1->mantissa)) { /* addition carry */
            b64_sft(&e3->mantissa, 1); /* shift mantissa one bit RIGHT */
            e3->m1 |= 0x80000000L; /* set max bit  */
            e3->exp++; /* increase the exponent */
        }
    }
    if ((e3->m2 | e3->m1) != 0L) {
        /* normalize */
        if (e3->m1 == 0L) {
            e3->m1 = e3->m2;
            e3->m2 = 0L;
            e3->exp -= 32;
        }
        if (!(e3->m1 & 0x80000000)) {
            unsigned long l = 0x40000000;
            int cnt = -1;

            while (!(l & e3->m1)) {
                l >>= 1;
                cnt--;
            }
            e3->exp += cnt;
            b64_sft(&(e3->mantissa), cnt);
        }
    }
}

static void ten_mult(struct EXTEND* e)
/* [<][>][^][v][top][bottom][index][help] */
{
    struct EXTEND e1 = *e;

    e1.exp++;
    e->exp += 3;
    add_ext(e, &e1, e);
}

static int cmp_ext(struct EXTEND* e1, struct EXTEND* e2)
/* [<][>][^][v][top][bottom][index][help] */
{
    struct EXTEND tmp;

    e2->sign = !e2->sign;
    add_ext(e1, e2, &tmp);
    e2->sign = !e2->sign;
    if (tmp.m1 == 0 && tmp.m2 == 0)
        return 0;
    if (tmp.sign)
        return -1;
    return 1;
}

static PrintType* _ext_str_cvt(struct EXTEND* e, int ndigit, int* decpt, int* sign, int ecvtflag)
/* [<][>][^][v][top][bottom][index][help] */
{
    /*      Like cvt(), but for extended precision */

    static PrintType buf[NDIGITS + 1];
    struct EXTEND m;
    register PrintType* p = buf;
    register PrintType* pe;
    int findex = 0;

    if (ndigit < 0)
        ndigit = 0;
    if (ndigit > NDIGITS)
        ndigit = NDIGITS;
    pe = &buf[ndigit];
    buf[0] = '\0';

    *sign = 0;
    if (e->sign) {
        *sign = 1;
        e->sign = 0;
    }

    *decpt = 0;
    if (e->m1 != 0) {
        register struct EXTEND* pp = &big_ten_powers[1];

        while (cmp_ext(e, pp) >= 0) {
            pp++;
            findex = pp - big_ten_powers;
            if (findex >= BTP)
                break;
        }
        pp--;
        findex = pp - big_ten_powers;
        mul_ext(e, &r_big_ten_powers[findex], e);
        *decpt += findex * TP;
        pp = &ten_powers[1];
        while (pp < &ten_powers[TP] && cmp_ext(e, pp) >= 0)
            pp++;
        pp--;
        findex = pp - ten_powers;
        *decpt += findex;

        if (cmp_ext(e, &ten_powers[0]) < 0) {
            pp = &r_big_ten_powers[1];
            while (cmp_ext(e, pp) < 0)
                pp++;
            pp--;
            findex = pp - r_big_ten_powers;
            mul_ext(e, &big_ten_powers[findex], e);
            *decpt -= findex * TP;
            /* here, value >= 10 ** -28 */
            ten_mult(e);
            (*decpt)--;
            pp = &r_ten_powers[0];
            while (cmp_ext(e, pp) < 0)
                pp++;
            findex = pp - r_ten_powers;
            mul_ext(e, &ten_powers[findex], e);
            *decpt -= findex;
            findex = 0;
        }
        (*decpt)++; /* because now value in [1.0, 10.0) */
    }
    if (!ecvtflag) {
        /* for fcvt() we need ndigit digits behind the dot */
        pe += *decpt;
        if (pe > &buf[NDIGITS])
            pe = &buf[NDIGITS];
    }
    m.exp = -62;
    m.sign = 0;
    m.m1 = 0xA0000000;
    m.m2 = 0;
    while (p <= pe) {
        struct EXTEND oneminm;

        if (p - pe > NSIGNIFICANT) {
            findex = 0;
            e->m1 = 0;
        }
        if (findex) {
            struct EXTEND tc, oldtc;
            int count = 0;

            oldtc.exp = 0;
            oldtc.sign = 0;
            oldtc.m1 = 0;
            oldtc.m2 = 0;
            tc = ten_powers[findex];
            while (cmp_ext(e, &tc) >= 0) {
                oldtc = tc;
                add_ext(&tc, &ten_powers[findex], &tc);
                count++;
            }
            *p++ = count + '0';
            oldtc.sign = 1;
            add_ext(e, &oldtc, e);
            findex--;
            continue;
        }
        if (e->m1) {
            m.sign = 1;
            add_ext(&ten_powers[0], &m, &oneminm);
            m.sign = 0;
            if (e->exp >= 0) {
                struct EXTEND x;

                x.m2 = 0;
                x.exp = e->exp;
                x.sign = 1;
                x.m1 = e->m1 >> (31 - e->exp);
                *p++ = ((PrintType)(x.m1) + '0');
                x.m1 = x.m1 << (31 - e->exp);
                add_ext(e, &x, e);
            } else
                *p++ = '0';
            /* Check that remainder is still significant */
            if (cmp_ext(&m, e) > 0 || cmp_ext(e, &oneminm) > 0) {
                if (e->m1 && e->exp >= -1)
                    *(p - 1) += 1;
                e->m1 = 0;
                continue;
            }
            ten_mult(&m);
            ten_mult(e);
        } else
            *p++ = '0';
    }
    if (pe >= buf) {
        p = pe;
        *p += 5; /* round of at the end */
        while (*p > '9') {
            *p = '0';
            if (p > buf)
                ++*--p;
            else {
                *p = '1';
                ++*decpt;
                if (!ecvtflag) {
                    /* maybe add another digit at the end,
                    because the point was shifted right
                    */
                    if (pe > buf)
                        *pe = '0';
                    pe++;
                }
            }
        }
        *pe = '\0';
    }
    return buf;
}

static void _dbl_ext_cvt(double value, struct EXTEND* e)
/* [<][>][^][v][top][bottom][index][help] */
{
    /*      Convert double to extended
    */
    int exponent;

    value = frexp(value, &exponent);
    e->sign = value < 0.0;
    if (e->sign)
        value = -value;
    e->exp = exponent - 1;
    value *= 4294967296.0;
    e->m1 = unsigned(value);
    value -= e->m1;
    value *= 4294967296.0;
    e->m2 = unsigned(value);
}

static PrintType* cvt(long double value, int ndigit, int* decpt, int* sign, int ecvtflag)
/* [<][>][^][v][top][bottom][index][help] */
{
    struct EXTEND e;

    _dbl_ext_cvt(value, &e);
    return _ext_str_cvt(&e, ndigit, decpt, sign, ecvtflag);
}

static PrintType* _ecvt(long double value, int ndigit, int* decpt, int* sign)
/* [<][>][^][v][top][bottom][index][help] */
{
    return cvt(value, ndigit, decpt, sign, 1);
}

static PrintType* _fcvt(long double value, int ndigit, int* decpt, int* sign)
/* [<][>][^][v][top][bottom][index][help] */
{
    return cvt(value, ndigit, decpt, sign, 0);
}

static PrintType* _pfloat(long double r, register PrintType* s, int n, int flags)
/* [<][>][^][v][top][bottom][index][help] */
{
    register PrintType* s1;
    int sign, dp;
    register int i;

    s1 = _fcvt(r, n, &dp, &sign);
    if (sign)
        *s++ = '-';
    else if (flags & FL_SIGN)
        *s++ = '+';
    else if (flags & FL_SPACE)
        *s++ = ' ';

    if (dp <= 0)
        *s++ = '0';
    for (i = dp; i > 0; i--)
        if (*s1)
            *s++ = *s1++;
        else
            *s++ = '0';
    if (((i = n) > 0) || (flags & FL_ALT))
        *s++ = '.';
    while (++dp <= 0) {
        if (--i < 0)
            break;
        *s++ = '0';
    }
    while (--i >= 0)
        if (*s1)
            *s++ = *s1++;
        else
            *s++ = '0';
    return s;
}

static PrintType* _pscien(long double r, register PrintType* s, int n, int flags)
/* [<][>][^][v][top][bottom][index][help] */
{
    int sign, dp;
    register PrintType* s1;

    s1 = _ecvt(r, n + 1, &dp, &sign);
    if (sign)
        *s++ = '-';
    else if (flags & FL_SIGN)
        *s++ = '+';
    else if (flags & FL_SPACE)
        *s++ = ' ';

    *s++ = *s1++;
    if ((n > 0) || (flags & FL_ALT))
        *s++ = '.';
    while (--n >= 0)
        if (*s1)
            *s++ = *s1++;
        else
            *s++ = '0';
    *s++ = 'e';
    if (r != 0)
        --dp;
    if (dp < 0) {
        *s++ = '-';
        dp = -dp;
    } else {
        *s++ = '+';
    }
    if (dp >= 100) {
        *s++ = '0' + (dp / 100);
        dp %= 100;
    }
    *s++ = '0' + (dp / 10);
    *s++ = '0' + (dp % 10);
    return s;
}

#define NDIGINEXP(exp) (((exp) >= 100 || (exp) <= -100) ? 3 : 2)
/* [<][>][^][v][top][bottom][index][help] */
#define LOW_EXP -4
#define USE_EXP(exp, ndigits) (((exp) < LOW_EXP + 1) || (exp >= ndigits + 1))
/* [<][>][^][v][top][bottom][index][help] */

static PrintType* _gcvt(long double value, int ndigit, PrintType* s, int flags)
/* [<][>][^][v][top][bottom][index][help] */
{
    int sign, dp;
    register PrintType *s1, *s2;
    register int i;
    register int nndigit = ndigit;

    s1 = _ecvt(value, ndigit, &dp, &sign);
    s2 = s;
    if (sign)
        *s2++ = '-';
    else if (flags & FL_SIGN)
        *s2++ = '+';
    else if (flags & FL_SPACE)
        *s2++ = ' ';

    if (!(flags & FL_ALT))
        for (i = nndigit - 1; i > 0 && s1[i] == '0'; i--)
            nndigit--;

    if (USE_EXP(dp, ndigit)) {
        /* Use E format */
        dp--;
        *s2++ = *s1++;
        if ((nndigit > 1) || (flags & FL_ALT))
            *s2++ = '.';
        while (--nndigit > 0)
            *s2++ = *s1++;
        *s2++ = 'e';
        if (dp < 0) {
            *s2++ = '-';
            dp = -dp;
        } else
            *s2++ = '+';
        s2 += NDIGINEXP(dp);
        *s2 = 0;
        for (i = NDIGINEXP(dp); i > 0; i--) {
            *--s2 = dp % 10 + '0';
            dp /= 10;
        }
        return s;
    }
    /* Use f format */
    if (dp <= 0) {
        if (*s1 != '0') {
            /* otherwise the whole number is 0 */
            *s2++ = '0';
            *s2++ = '.';
        }
        while (dp < 0) {
            dp++;
            *s2++ = '0';
        }
    }
    for (i = 1; i <= nndigit; i++) {
        *s2++ = *s1++;
        if (i == dp)
            *s2++ = '.';
    }
    if (i <= dp) {
        while (i++ <= dp)
            *s2++ = '0';
        *s2++ = '.';
    }
    if ((s2[-1] == '.') && !(flags & FL_ALT))
        s2--;
    *s2 = '\0';
    return s;
}

static int stringlen(const PrintType* str) {
    int ret = 0;

    while (*str++)
        ret++;

    return ret;
}

PrintType* _f_print(va_list* ap, int flags, PrintType* s, PrintType c, int precision)
/* [<][>][^][v][top][bottom][index][help] */
{
    register PrintType* old_s = s;
    long double ld_val;

    if (flags & FL_LONGDOUBLE)
        ld_val = EbrLongDouble(*ap, long double);
    else
        ld_val = (long double)EbrDouble(*ap, double);

    switch (c) {
        case 'f':
            s = _pfloat(ld_val, s, precision, flags);
            break;
        case 'e':
        case 'E':
            s = _pscien(ld_val, s, precision, flags);
            break;
        case 'g':
        case 'G':
            s = _gcvt(ld_val, precision, s, flags);
            s += stringlen(s);
            break;
    }
    if (c == 'E' || c == 'G') {
        while (*old_s && *old_s != 'e')
            old_s++;
        if (*old_s == 'e')
            *old_s = 'E';
    }
    return s;
}

PrintType* _i_compute(unsigned long long val, int base, PrintType* s, int nrdigits)
/* [<][>][^][v][top][bottom][index][help] */
{
    int c;

    c = val % base;
    val /= base;
    if (val || nrdigits > 1)
        s = _i_compute(val, base, s, nrdigits - 1);
    *s++ = (c > 9 ? c - 10 + 'a' : c + '0');
    return s;
}

/* gnum() is used to get the width and precision fields of a format. */
static const PrintType* gnum(register const PrintType* f, int* ip, va_list* app)
/* [<][>][^][v][top][bottom][index][help] */
{
    register int i, c;

    if (*f == '*') {
        *ip = EbrVal((*app), int);
        f++;
    } else {
        i = 0;
        while ((c = *f - '0') >= 0 && c <= 9) {
            i = i * 10 + c;
            f++;
        }
        *ip = i;
    }
    return f;
}

#if _EM_WSIZE == _EM_PSIZE
#define set_pointer(flags) /* nothing */
/* [<][>][^][v][top][bottom][index][help] */
#elif _EM_LSIZE == _EM_PSIZE
#define set_pointer(flags) (flags |= FL_LONG)
/* [<][>][^][v][top][bottom][index][help] */
#else
#error garbage pointer size
#define set_pointer(flags) /* compilation might continue */
/* [<][>][^][v][top][bottom][index][help] */
#endif

/* print an ordinal number */
static PrintType* o_print(va_list* ap, int flags, PrintType* s, PrintType c, int precision, int is_signed)
/* [<][>][^][v][top][bottom][index][help] */
{
    long long signed_val;
    unsigned long long unsigned_val;
    PrintType* old_s = s;
    int base;

    switch (flags & (FL_SHORT | FL_LONG)) {
        case FL_SHORT:
            if (is_signed) {
                signed_val = (short)EbrVal(*ap, int);
            } else {
                unsigned_val = (unsigned short)EbrVal(*ap, unsigned);
            }
            break;
        case FL_LONG:
            if (flags & FL_LONGLONG) {
                if (is_signed) {
                    *((unsigned long long*)&signed_val) = EbrVal(*ap, unsigned long);
                    *((unsigned long long*)&signed_val) |= ((unsigned long long)EbrVal(*ap, unsigned long)) << 32;
                } else {
                    *((unsigned long long*)&unsigned_val) = EbrVal(*ap, unsigned long);
                    *((unsigned long long*)&unsigned_val) |= ((unsigned long long)EbrVal(*ap, unsigned long)) << 32;
                }
            } else {
                if (is_signed) {
                    signed_val = EbrVal(*ap, long);
                } else {
                    unsigned_val = EbrVal(*ap, unsigned long);
                }
            }
            break;
        default:
            if (is_signed) {
                signed_val = EbrVal(*ap, int);
            } else {
                unsigned_val = EbrVal(*ap, unsigned int);
            }
            break;
    }

    if (is_signed) {
        if (signed_val < 0) {
            *s++ = '-';
            signed_val = -signed_val;
        } else if (flags & FL_SIGN)
            *s++ = '+';
        else if (flags & FL_SPACE)
            *s++ = ' ';
        unsigned_val = signed_val;
    }
    if ((flags & FL_ALT) && (c == 'o'))
        *s++ = '0';
    if (!unsigned_val) {
        if (!precision)
            return s;
    } else if (((flags & FL_ALT) && (c == 'x' || c == 'X')) || c == 'p') {
        *s++ = '0';
        *s++ = (c == 'X' ? 'X' : 'x');
    }

    switch (c) {
        case 'b':
            base = 2;
            break;
        case 'o':
            base = 8;
            break;
        case 'd':
        case 'i':
        case 'u':
            base = 10;
            break;
        case 'x':
        case 'X':
        case 'p':
            base = 16;
            break;
    }

    s = _i_compute(unsigned_val, base, s, precision);

    if (c == 'X')
        while (old_s != s) {
            *old_s = toupper(*old_s);
            old_s++;
        }

    return s;
}

int _doprnt(register const PrintType* fmt, va_list ap, PrintOutput* stream)
/* [<][>][^][v][top][bottom][index][help] */
{
    register PrintType* s;
    register int j;
    int i, c, width, precision, zfill, flags, between_fill;
    int nrchars = 0;
    const PrintType* oldfmt;
    PrintType *s1, buf[1025];
    char *cs = NULL, *cs1 = NULL;

    while (c = *fmt++) {
        if (c != '%') {
#ifdef CPM
            if (c == '\n') {
                if (PrintPutC('\r', stream) == EOF)
                    return nrchars ? -nrchars : -1;
                nrchars++;
            }
#endif
            if (PrintPutC(c, stream) == EOF)
                return nrchars ? -nrchars : -1;
            nrchars++;
            continue;
        }
        flags = 0;
        do {
            switch (*fmt) {
                case '-':
                    flags |= FL_LJUST;
                    break;
                case '+':
                    flags |= FL_SIGN;
                    break;
                case ' ':
                    flags |= FL_SPACE;
                    break;
                case '#':
                    flags |= FL_ALT;
                    break;
                case '0':
                    flags |= FL_ZEROFILL;
                    break;
                default:
                    flags |= FL_NOMORE;
                    continue;
            }
            fmt++;
        } while (!(flags & FL_NOMORE));

        oldfmt = fmt;
        fmt = gnum(fmt, &width, &ap);
        if (fmt != oldfmt)
            flags |= FL_WIDTHSPEC;

        if (*fmt == '.') {
            fmt++;
            oldfmt = fmt;
            fmt = gnum(fmt, &precision, &ap);
            if (precision >= 0)
                flags |= FL_PRECSPEC;
        }

        if ((flags & FL_WIDTHSPEC) && width < 0) {
            width = -width;
            flags |= FL_LJUST;
        }
        if (!(flags & FL_WIDTHSPEC))
            width = 0;

        if (flags & FL_SIGN)
            flags &= ~FL_SPACE;

        if (flags & FL_LJUST)
            flags &= ~FL_ZEROFILL;

        s = s1 = buf;

        switch (*fmt) {
            case 'h':
                flags |= FL_SHORT;
                fmt++;
                break;
            case 'l':
                flags |= FL_LONG;
                fmt++;
                break;
            case 'L':
                flags |= FL_LONGDOUBLE;
                fmt++;
                break;
            case 'z':
                fmt++;
                break; //  size_t specifier
        }

        if (*fmt == 'l') {
            flags |= FL_LONGLONG;
            fmt++;
        }

        switch (c = *fmt++) {
            default:
#ifdef CPM
                if (c == '\n') {
                    if (PrintPutC('\r', stream) == EOF)
                        return nrchars ? -nrchars : -1;
                    nrchars++;
                }
#endif
                if (PrintPutC(c, stream) == EOF)
                    return nrchars ? -nrchars : -1;
                nrchars++;
                continue;
            case 'n':
                if (flags & FL_SHORT)
                    *EbrPtr(ap, short*) = (short)nrchars;
                else if (flags & FL_LONG)
                    *EbrPtr(ap, long*) = (long)nrchars;
                else
                    *EbrPtr(ap, int*) = (int)nrchars;
                continue;
            case 's':
            case 'S':
#ifdef UTF8CStrings
                cs1 = EbrPtr(ap, char*);
                if (cs1 == NULL)
                    cs1 = PrintNullStringC; //"(null)";
                cs = cs1;
                while (precision || !(flags & FL_PRECSPEC)) {
                    if (*cs == '\0')
                        break;
                    cs++;
                    precision--;
                }
#else
                s1 = EbrPtr(ap, PrintType*);
                if (s1 == NULL)
                    s1 = PrintNullString; //"(null)";
                s = s1;
                while (precision || !(flags & FL_PRECSPEC)) {
                    if (*s == '\0')
                        break;
                    s++;
                    precision--;
                }
#endif
                break;
            case '@': {
                id ptr = EbrVal(ap, id);
                id str = [ptr description];

                s1 = (PrintType*)[str _quickStringUsingEncoding:PrintEncodingType];
                if (s1 == NULL)
                    s1 = PrintNullString; //"(null)";
                s = s1;
                while (precision || !(flags & FL_PRECSPEC)) {
                    if (*s == '\0')
                        break;
                    s++;
                    precision--;
                }
            } break;
            case 'p':
                set_pointer(flags);
            /* fallthrough */
            case 'b':
            case 'o':
            case 'u':
            case 'x':
            case 'X':
                if (!(flags & FL_PRECSPEC))
                    precision = 1;
                else if (c != 'p')
                    flags &= ~FL_ZEROFILL;
                s = o_print(&ap, flags, s, c, precision, 0);
                break;
            case 'd':
            case 'i':
                flags |= FL_SIGNEDCONV;
                if (!(flags & FL_PRECSPEC))
                    precision = 1;
                else
                    flags &= ~FL_ZEROFILL;
                s = o_print(&ap, flags, s, c, precision, 1);
                break;
            case 'c':
            case 'C':
                *s++ = EbrVal(ap, int);
                break;
#ifndef NOFLOAT
            case 'G':
            case 'g':
                if ((flags & FL_PRECSPEC) && (precision == 0))
                    precision = 1;
            case 'f':
            case 'E':
            case 'e':
                if (!(flags & FL_PRECSPEC))
                    precision = 6;

                if (precision >= sizeof(buf))
                    precision = sizeof(buf) - 1;

                flags |= FL_SIGNEDCONV;
                s = _f_print(&ap, flags, s, c, precision);
                break;
#endif /* NOFLOAT */
            case 'r':
                assert(0);
                /*
                ap = va_arg(ap, StackReader*);
                fmt = va_arg(ap, char *);
                */
                continue;
        }
        zfill = ' ';
        if (flags & FL_ZEROFILL)
            zfill = '0';
        j = s - s1;
        if (cs != NULL)
            j = cs - cs1;

        /* between_fill is true under the following conditions:
        * 1- the fill character is '0'
        * and
        * 2a- the number is of the form 0x... or 0X...
        * or
        * 2b- the number contains a sign or space
        */
        between_fill = 0;
        if ((flags & FL_ZEROFILL) &&
            (((c == 'x' || c == 'X') && (flags & FL_ALT)) || (c == 'p') ||
             ((flags & FL_SIGNEDCONV) &&
              ((cs1 ? *cs1 : *s1) == '+' || (cs1 ? *cs1 : *s1) == '-' || (cs1 ? *cs1 : *s1) == ' '))))
            between_fill++;

        if ((i = width - j) > 0)
            if (!(flags & FL_LJUST)) { /* right justify */
                nrchars += i;
                if (between_fill) {
                    if (flags & FL_SIGNEDCONV) {
                        j--;
                        nrchars++;
                        if (PrintPutC(cs1 ? *cs1++ : *s1++, stream) == EOF)
                            return nrchars ? -nrchars : -1;
                    } else {
                        j -= 2;
                        nrchars += 2;
                        if ((PrintPutC(cs1 ? *cs1++ : *s1++, stream) == EOF) ||
                            (PrintPutC(cs1 ? *cs1++ : *s1++, stream) == EOF))
                            return nrchars ? -nrchars : -1;
                    }
                }
                do {
                    if (PrintPutC(zfill, stream) == EOF)
                        return nrchars ? -nrchars : -1;
                } while (--i);
            }

        nrchars += j;
        while (--j >= 0) {
            if (PrintPutC(cs1 ? *cs1++ : *s1++, stream) == EOF)
                return nrchars ? -nrchars : -1;
        }

        cs = cs1 = NULL;

        if (i > 0)
            nrchars += i;
        while (--i >= 0)
            if (PrintPutC(zfill, stream) == EOF)
                return nrchars ? -nrchars : -1;
    }
    return nrchars;
}

int formatPrintfU(WORD* output, int maxLen, const WORD* format, va_list pReader) {
    PrintOutput s;
    s.s = output;
    s.len = maxLen;
    s.pos = 0;

    int ret = _doprnt(format, pReader, &s);
    PrintPutC(0, &s);

    return ret;
}
