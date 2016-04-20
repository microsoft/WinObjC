%{
    #include <Foundation/Foundation.h>
    #include "ExpressionHelpers.h"
    #include "rules.tab.h"

    extern void yyerror(yyscan_t scanner, nextArgument args, NSPredicate **predicate, const char *error);
%}

/* Reference: http://flex.sourceforge.net/manual/ */

%option case-insensitive
%option noyywrap
%option reentrant bison-bridge

/*Start exclusive  conditions*/
%X DOUBLE_QUOTE_STRING
%X SINGLE_QUOTE_STRING

%%

","                { return COMA; }
"$"                { return DOLLAR; }
"%"                { return PERCENT; }
"."                { return PERIOD; }
"**"               { return EXPONENT; }
"^"                { return EXPONENT; }
"*"                { return MULTIPLY; }
"/"                { return DIVIDE; }
"+"                { return PLUS; }
"-"                { return MINUS; }
":="               { return ASSIGN; }

"="                |
"=="               { return EQUAL; }

"!="               { return NOT_EQUAL; }
"<"                { return LESS_THAN; }
">"                { return GREATER_THAN; }
"<="               { return EQUAL_AND_LESS_THAN; }
">="               { return EQUAL_AND_GREATER_THAN; }

AND                |
"&&"               { return AND; }

OR                 |
"||"               { return OR; }

NOT                |
"!"                { return NOT; }

"["                { return LEFT_BRACKETS; }
"]"                { return RIGHT_BRACKETS; }
"{"                { return LEFT_CURLY_BRACES; }
"}"                { return RIGHT_CURLY_BRACES; }
"("                { return LEFT_PARENTHESIS; }
")"                { return RIGHT_PARENTHESIS; }

LAST               { return LAST; }
FIRST              { return FIRST; }
SIZE               { return SIZE; }
SELF               { return SELF; }
BEGINSWITH         { return BEGINS_WITH; }
ENDSWITH           { return ENDS_WITH; }
LIKE               { return LIKE; }
MATCHES            { return MATCHES; }
CONTAINS           { return CONTAINS; }
ANY                { return ANY; }
SOME               { return SOME; }
ALL                { return ALL; }
NONE               { return NONE; }
IN                 { return IN; }
BETWEEN            { return BETWEEN; }

NULL               |
NIL                { return NULL_FLAG; }

TRUE               |
YES                { return TRUE_FLAG; }

FALSE              |
NO                 { return FALSE_FLAG; }

/* Explanation for patterns used here can be found at: http://flex.sourceforge.net/manual/Patterns.html */

"@"                { yylval->string = @"@"; return AT; }

'                        { yylval->parserString = [NSMutableString string]; BEGIN(SINGLE_QUOTE_STRING); };
\"                       { yylval->parserString = [NSMutableString string]; BEGIN(DOUBLE_QUOTE_STRING); };


<SINGLE_QUOTE_STRING,DOUBLE_QUOTE_STRING>{
    <<EOF>>              { yyerror(yyscanner,NULL, NULL,"Invalid parser string."); }

    \\([0-7]{1,3})       { int c; sscanf_s(yytext + 1, "%o", &c); [yylval->parserString appendFormat:@"%c", c]; }
    \\x([[:XDIGIT:]]{2}) |
    \\u([[:XDIGIT:]]{4}) { int c; sscanf_s(yytext + 2, "%x", &c); [yylval->parserString appendFormat:@"%C", c]; }
    \\n                  { [yylval->parserString appendString:@"\n"]; }
    \\r                  { [yylval->parserString appendString:@"\r"]; }
    \\.                  { [yylval->parserString appendFormat:@"%c", yytext[1]]; }
    [^\\\"']+            { [yylval->parserString appendFormat:@"%s", yytext]; }
}

<SINGLE_QUOTE_STRING>'         |
<DOUBLE_QUOTE_STRING>\"        { yylval->string = yylval->parserString; BEGIN(INITIAL); return STRING; }

<SINGLE_QUOTE_STRING>\"       { [yylval->parserString appendString:@"\""]; }
<DOUBLE_QUOTE_STRING>'         { [yylval->parserString appendString:@"'"]; }

[[:DIGIT:]]+\.[[:DIGIT:]]* { double dd; sscanf_s(yytext, "%lf", &dd); yylval->number = [NSNumber numberWithDouble:dd]; return NUMBER; }
[[:DIGIT:]]+               { unsigned int d; sscanf_s(yytext, "%d", &d); yylval->number = [NSNumber numberWithUnsignedInt:d]; return NUMBER; }
0[xX][[:XDIGIT:]]+         { unsigned int d; sscanf_s(yytext, "%x", &d); yylval->number = [NSNumber numberWithUnsignedInt:d]; return NUMBER; }


[[:SPACE:]]+             { /*ignore spaces*/}

.               yyerror (yyscanner,NULL,NULL,"Unknown character.");

%%


extern void lexer_init(const char *parseString, yyscan_t *lexer, YY_BUFFER_STATE *state)
{
    if (yylex_init(lexer))
    {
        yyerror (yyscanner,NULL,NULL,"Unable to create NSPredicate lexer");
        return;
    }
    *state = yy_scan_string(parseString, *lexer);
}

extern void lexer_destroy(yyscan_t lexer, YY_BUFFER_STATE state)
{
    yy_delete_buffer(state, lexer);
    yylex_destroy(lexer);
}
