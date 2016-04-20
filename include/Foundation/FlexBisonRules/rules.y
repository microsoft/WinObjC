%{
    #include <Foundation/Foundation.h>
    #include "ExpressionHelpers.h"

    typedef void* yyscan_t;
    typedef void* YY_BUFFER_STATE;

    extern void lexer_init(const char *parseString, yyscan_t *lexer, YY_BUFFER_STATE *state);
    extern void lexer_destroy(yyscan_t lexer, YY_BUFFER_STATE state);

    typedef NSExpression* (^ nextArgument)(NSString* type);
    extern int yyparse(yyscan_t lexer, nextArgument nextArg, NSPredicate **predicate);

    void yyerror(yyscan_t scanner, nextArgument nextArg, NSPredicate** predicate, const char *error);

    NSPredicate *_parsePredicateFormatString(NSString *format, nextArgument nextArg);
    #pragma clang-format off
%}

%define api.pure full
%lex-param { void* scanner}
%parse-param { void*  scanner}
%parse-param { nextArgument nextArg }
%parse-param { NSPredicate **predicate }
%start predicate_main


%union {
    NSPredicate *predicate;
    //When NSDecimalNumber is ready, scanner also needs changes.
    //NSDecimalNumber *number;
    NSNumber *number;
    NSString* string;
    NSMutableArray *array;
    NSExpression *expression;

    struct {
        NSPredicateOperatorType type;
        NSComparisonPredicateOptions options;
    } operatorR;

    struct {
        NSExpression *lhs;
        NSExpression *rhs;
        NSPredicateOperatorType type;
        NSComparisonPredicateOptions options;
    } comparisonS;

    NSMutableString *parserString;
    NSPredicateOperatorType operatorType;
}

%type <predicate> NS_Predicate
%type <predicate> NS_CompoundPredicate
%type <predicate> NS_ComparisonPredicate

%type <comparisonS> Simple_Expression_Comparsion

%type <expression> Expression
%type <expression> Keypath_Expression
%type <expression> Binary_Expression
%type <expression> Assignment_Expression
%type <expression> Value_Expression
%type <expression> Function_Expression
%type <expression> Predicate_Argument
%type <expression> Format_Argument

%type <operatorR> Operator
%type <operatorR> Operator_With_Options

%type <operatorType> Operator_Type
%type <string> Predicate_Variable
%type <array> Expression_List

%token <string> AT // @

%token <number> NUMBER

%token <string> STRING

%token <string> IDENTIFIER

%token LEFT_PARENTHESIS // (
%token RIGHT_PARENTHESIS // )
%token LEFT_CURLY_BRACES // {
%token RIGHT_CURLY_BRACES // }

%token LEFT_BRACKETS // [
%token RIGHT_BRACKETS // ]

%nonassoc EQUAL // =
%nonassoc NOT_EQUAL // !=
%nonassoc LESS_THAN // <
%nonassoc GREATER_THAN // >
%nonassoc EQUAL_AND_LESS_THAN // <=
%nonassoc EQUAL_AND_GREATER_THAN //>=

%left AND
%left OR
%left NOT

%left PERIOD

%left PLUS MINUS
%left MULTIPLY DIVIDE
%left EXPONENT
%right ASSIGN

%token TRUE_FLAG
%token TRUE_PREDICATE
%token FALSE_FLAG
%token FALSE_PREDICATE

%token LAST
%token FIRST
%token SIZE
%token SELF
%token COMA
%token DOLLAR
%token PERCENT
%token BETWEEN
%token CONTAINS
%token LIKE
%token MATCHES
%token BEGINS_WITH
%token ENDS_WITH
%token IN
%token NULL_FLAG
%token ANY
%token SOME
%token NONE




%%

predicate_main:
  NS_Predicate { *predicate = $1; };

NS_Predicate:
    NS_ComparisonPredicate {$$ = $1;} | NS_CompoundPredicate {$$ = $1;}

    | LEFT_PARENTHESIS NS_Predicate RIGHT_PARENTHESIS {$$ = $2;}

    |TRUE_PREDICATE { $$ = [NSPredicate predicateWithValue:YES]; } | FALSE_PREDICATE {$$ = [NSPredicate predicateWithValue:NO];}


NS_CompoundPredicate:
    NS_Predicate AND NS_Predicate {$$ = [NSCompoundPredicate andPredicateWithSubpredicates:[NSArray arrayWithObjects:$1, $3, nil]];}
    | NS_Predicate OR NS_Predicate {$$ = [NSCompoundPredicate orPredicateWithSubpredicates:[NSArray arrayWithObjects:$1, $3, nil]];}
    | NOT NS_Predicate {$$ = [ NSCompoundPredicate notPredicateWithSubpredicate:$2];}

NS_ComparisonPredicate:
    Simple_Expression_Comparsion  {$$ = [NSComparisonPredicate predicateWithLeftExpression:$1.lhs rightExpression:$1.rhs modifier:NSDirectPredicateModifier type:$1.type options:$1.options]; }
    
    | ALL Simple_Expression_Comparsion  { $$ = [NSComparisonPredicate predicateWithLeftExpression:$2.lhs rightExpression:$2.rhs modifier:NSAllPredicateModifier type:$2.type options:$2.options]; }
    
    //The opposite of ANY Comparsion
    | NONE Simple_Expression_Comparsion  {$$ = [NSCompoundPredicate notPredicateWithSubpredicate:[NSComparisonPredicate predicateWithLeftExpression:$2.lhs rightExpression:$2.rhs modifier:NSAnyPredicateModifier type:$2.type options:$2.options]];}
    
    | SOME Simple_Expression_Comparsion  { $$ = [NSComparisonPredicate predicateWithLeftExpression:$2.lhs rightExpression:$2.rhs modifier:NSAnyPredicateModifier type:$2.type options:$2.options]; }
    | ANY Simple_Expression_Comparsion  { $$ = [NSComparisonPredicate predicateWithLeftExpression:$2.lhs rightExpression:$2.rhs modifier:NSAnyPredicateModifier type:$2.type options:$2.options]; }


Operator:
  BETWEEN             { $$.type = NSBetweenPredicateOperatorType; $$.options = 0; }
| Operator_With_Options { $$ = $1; }

Operator_With_Options:
  Operator_Type                            { $$.type = $1; $$.options = 0; }
| Operator_Type LEFT_BRACKETS IDENTIFIER RIGHT_BRACKETS { $$.type = $1; $$.options = [NSComparisonPredicate extractOptions:$3]; }


Operator_Type:
    EQUAL                 { $$ = NSEqualToPredicateOperatorType; }
    | NOT_EQUAL             { $$ = NSNotEqualToPredicateOperatorType; }
    | LESS_THAN             { $$ = NSLessThanPredicateOperatorType; }
    | GREATER_THAN          { $$ = NSGreaterThanPredicateOperatorType; }
    | EQUAL_AND_LESS_THAN    { $$ = NSLessThanOrEqualToPredicateOperatorType; }
    | EQUAL_AND_GREATER_THAN { $$ = NSGreaterThanOrEqualToPredicateOperatorType; }
    | CONTAINS              { $$ = NSContainsPredicateOperatorType; }
    | IN                    { $$ = NSInPredicateOperatorType; }
    | BEGINS_WITH           { $$ = NSBeginsWithPredicateOperatorType; }
    | ENDS_WITH             { $$ = NSEndsWithPredicateOperatorType; }
    | LIKE                  { $$ = NSLikePredicateOperatorType; }
    | MATCHES               { $$ = NSMatchesPredicateOperatorType; }


Expression:
    LEFT_PARENTHESIS Expression RIGHT_PARENTHESIS {$$ = $2;}

    | Binary_Expression {$$ = $1;}

    | Function_Expression  {$$ = $1;}  

    | Assignment_Expression {$$ = $1;}

    | Keypath_Expression {$$ = $1;}

    | Value_Expression {$$ = $1;}

Simple_Expression_Comparsion:
    Expression Operator Expression {$$.lhs = $1; $$.rhs = $3;  $$.options = $2.options; $$.type = $2.type;}

Binary_Expression:
    //Call into NSExpressionDefaultFunctions for each method
        MINUS Expression {$$ = [NSExpression expressionForFunction:@"multiply:second:" arguments:[NSArray arrayWithObjects:[NSExpression expressionForConstantValue:[NSNumber numberWithInt:-1]],$2,nil]];}
        | Expression PLUS Expression {$$ = [NSExpression expressionForFunction:@"plus:second:" arguments:[NSArray arrayWithObjects:$1,$3,nil]];}
        | Expression MINUS Expression {$$ = [NSExpression expressionForFunction:@"minus:second:" arguments:[NSArray arrayWithObjects:$1,$3,nil]];}
        | Expression MULTIPLY Expression {$$ = [NSExpression expressionForFunction:@"multiply:second:" arguments:[NSArray arrayWithObjects:$1,$3,nil]];}
        | Expression DIVIDE Expression {$$ = [NSExpression expressionForFunction:@"divideBy:second:" arguments:[NSArray arrayWithObjects:$1,$3,nil]];}
        | Expression EXPONENT Expression {$$ = [NSExpression expressionForFunction:@"exp:to:" arguments:[NSArray arrayWithObjects:$1,$3,nil]];}

Function_Expression:
    IDENTIFIER LEFT_PARENTHESIS Expression_List RIGHT_PARENTHESIS {$$ = [NSExpression expressionForFunction:$1 arguments:$3]; }

    | IDENTIFIER LEFT_PARENTHESIS RIGHT_PARENTHESIS {$$ = [NSExpression expressionForFunction:$1 arguments:nil]; }

Expression_List:
  Expression                      { $$ = [NSMutableArray arrayWithObject:$1]; }
| Expression_List COMA Expression { [$1 addObject:$3]; $$ = $1; }

//literal_aggregate not supported yet.
Value_Expression:
    NUMBER {$$ = [NSExpression expressionForConstantValue:$1];};
    | NULL_FLAG {$$ = [NSExpression expressionForConstantValue:[NSNull null]];}
    | TRUE_FLAG {$$ = [NSExpression expressionForConstantValueTrue];}
    | FALSE_FLAG {$$ = [NSExpression expressionForConstantValueFalse];}
    | SELF {$$ = [NSExpression expressionForEvaluatedObject];}
    | STRING {$$ = [NSExpression expressionForConstantValue:$1];}
    | Predicate_Variable {$$ = [NSExpression expressionForVariable:$1];}
    | Predicate_Argument {$$ = $1;}

Predicate_Variable:
    DOLLAR IDENTIFIER {$$ = $2;}

Predicate_Argument:
    PERCENT Format_Argument {$$ = $2;}

Format_Argument:
    AT {$$ = nextArg($1); }
    | IDENTIFIER {$$ = nextArg($1);}

Assignment_Expression:
    Predicate_Variable ASSIGN Expression {$$ = [[[NSExpressionVariable alloc] initWithVariableName:$1 expression:$3] autorelease]; }

Keypath_Expression:
  IDENTIFIER                   { $$ = [NSExpression expressionForKeyPath:$1]; }
| AT IDENTIFIER                { $$ = [NSExpression expressionForKeyPath:[$1 stringByAppendingString:$2]]; }
| Expression PERIOD Expression { $$ = [NSExpression expressionforKeyValueAccess:$3 leftExpression:$1]; }

%% 

void yyerror(yyscan_t scanner, nextArgument nextArg, NSPredicate **predicate, const char *error)
{
    [NSException raise:NSInvalidArgumentException format:@"%s", error];
}




static  NSPredicate *_parsePredicateFormatString(NSString *format, nextArgument nextArg)
{
    const char *formatBytes = [format UTF8String];

    yyscan_t lexer;
    YY_BUFFER_STATE state;
    //Need to call into lexer for init.
    lexer_init(formatBytes, &lexer, &state);

    NSPredicate *predicate = nil;
    yyparse(lexer, nextArg,&predicate);

    lexer_destroy(lexer, state);

    return predicate;
}