# WinObjC Coding Conventions

## 1 Overview

*\[This document reuses content from a number of sources. Implicit thanks to the otherwise uncredited original authors and contributors.\]*

The WinObjC engineering team values consistency and clarity as a way to promote correctness, quality, and maintainability of our codebase. To that end, this document lays out foundational standards for writing Objective C and C++ code in our project.

The Objective C guidance in this document is meant to augment existing industry guidance, so please read through [Apple's Coding Guidelines for Cocoa](https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/CodingGuidelines/CodingGuidelines.html#//apple_ref/doc/uid/10000146-SW1) before digesting the rest of the standards outlined below.

Not everyone will agree with all the conventions described herein, but the existence of this standard settles religious arguments before they begin. Failing to cater to everyone's favorite style may seem freedom-limiting, but is on the contrary a path to a robust codebase that we are all proud of.

This document is organized with a set of "best practices" bullet points in each top-level section, followed by subsections containing additional details, examples, and guidance.

**If you read only this overview, plus the top-level sections, you will have a pretty good idea of how to write code that follows WinObjC team conventions.**

### 1.1 Objectives

Produce high quality, self-documenting code - code that is primarily for the reader, not the writer.

Write code that benefits from the dynamic nature of Objective C, while also leveraging the richness provided by modern C++ where practical.

Use the STL and RAII patterns; be purposeful with exception-handling and usage.

Continually move the needle forward so that we're always improving our codebase.

### 1.2    Applicability

The conventions in this document apply to all new Objective C and C++ code written in this group. "New code" also encompasses existing code that you are modifying. Adherence is valued above consistency with surrounding code, at all levels of granularity.

Large bodies of existing code should be brought into conformance as the code is modified (this is essentially our team's starting point). However, any publicly-facing portions (interfaces, inter-module constructs, etc.) should be brought into line as soon as possible, so that a ripple effect from them doesn't infect other code and force our new code into non-compliance.

Cutting and pasting, or copying files from an existing codebase into our projects must first be updated to reflect the conventions required by this document.

These conventions apply to non-production code (i.e., unit tests, tools) just as they do for production code.

### 1.3    Enforcement

Adherence to the conventions in this document is currently only enforceable via code review. Please take active part in code reviews in order to help encourage and maintain a consistent codebase.

**Note:** Efforts will likely be made to enforce as many style standards as possible at commit or build time (by leveraging tools such as clang-format, clang-tidy, etc.), but all WinObjC contributors should be aware of the expectations around code quality and consistency.

## 2 Code Format

This section describes code layout and formatting requirements.

-   No hard tabs; use spaces with a tabstop of 4 characters.

-   Lines must not exceed 140 characters.

-   All code files must contain the Microsoft copyright/MIT license banner.

-   [Bracing style](#2.1.6-bracing-style) is most similar to the [Stroustrup variant of the K&R style](https://en.wikipedia.org/wiki/Indent_style#Variant:_Stroustrup).
    
-   Each variable declaration should go on its own line (**no comma-delineated variable declarations**).

-   Braces are mandatory even when the compiler would not require them (**no single-line conditionals**).

-   Parenthesis are highly encouraged to group conditionals even where the compiler would not require them.

-   Use "" and &lt;&gt; correctly in \#include and \#import directives.

-   Each class, interface, struct, and function must be commented with adequate descriptions.

-   The 'auto' keyword is encouraged [under specific conditions](#2.1.9-auto-keyword).

-   Prefer C++ language types over Win32 SHOUTY types.

-   Use the override keyword and omit the virtual keyword when doing so

-   Use nullptr rather than NULL.

-   Use '\\0' rather than 0 for C string null terminators.

-   No space between a typename and any associated pointer, hat, or reference symbols.

-   Prefer to put code into .cpp/.mm files when possible.

-   Leverage namespaces (for C++) and standard namespace-style prefixes (for Objective C) to group portions of related code.

-   Use C++ casts rather than C casts for better type safety.

-   Prefer const values over \#define constants for better type safety.

-   Use macros with discretion.

Beyond the above, certain additional formatting requirements are described by example in the sections that below. There are also examples with additional discussion and clarification for some of the above requirements.

### 2.1    Additional Examples and Requirements

#### 2.1.1 Breaking Parameters for Function Calls

When calling a function with many parameters that won't all fit on a single line, split up the parameters one per line.

This makes the code more legible, and also provides the author a rare opportunity to comment on the individual parameters (if needed) to make the function call even easier to decipher. Note: If choosing to comment on such parameters, be concise.

```Objective-C++
// Correct
// Note: closing paren is on same line
HRESULT magicFunction(unsigned long parameter1,
                      unsigned long parameter2,
                      void* buffer,
                      BOOL* weirdOutParam);

// Correct - if any params are on a separate line, all must be
retValue = createFile("file.txt",
                      GENERIC_READ,
                      FILE_SHARE_READ,
                      nullptr, // Security Descriptor
                      OPEN_EXISTING,
                      FILE_FLAG_OVERLAPPED,
                      nullptr); // Open template

// Incorrect - too many params on one line (if exceeds our per-line character limit)
HRESULT magicFunction(unsigned long parameter, unsigned long parameter2, void* buffer, BOOL* weirdOutParam);

// Incorrect - all params are not on separate lines
retVal = createFile("file.txt", GENERIC_READ, FILE_SHARE_READ, nullptr, 
    OPEN_EXISTING, FILE_FLAG_OVERLAPPED, nullptr);
```

#### 2.1.2    Line Folding

If a statement fits in a single line, then it should use a single line. For example,

```Objective-C++
result = Function(param1, param2, param3);
result = a + b + c;
if ((a > b) && (c != d)) {
}
```

If a statement doesn't fit in a single line, the statement should be folded as follows.

```Objective-C++
result = Function(
    param1,
    param2,
    param3);

// Note how the operator remains on the previous line to set up the "there's more" expectation
result =
    a +
    b +
    c;

if ((a > c) &&
    (c != d)) {
}

// Also acceptable
result = a
    + b
    + c;

if ((a > c) &&
    (c != d)) {
}
```

#### 2.1.3    Spacing

When splitting up parameters for function calls, expressions within a for-loop, or similar patterns, you must use spaces between the expressions/parameters.

Spaces improve readability by decreasing code density. Here are some guidelines for the use of spaces within code:

-   ***Do not*** use spaces between a function name and its parenthesis.

```Objective-C++
createFoo() // Correct

createFoo () // Incorrect
```

-   ***Do*** use a single space after a comma between function and control flow statement arguments.

```Objective-C++
method(myChar, 0, 1) // Correct

for (int i = 0; i &lt; 10; i++) { // Correct

}

method(myChar,0,1) // Incorrect

for (int i=0;i&lt;10;i++) { // Incorrect - needs spaces around "=", "&lt;", and after ";"
}
```

-   ***Do not*** use a space after the open parenthesis of a function, or before its closing parenthesis.

```Objective-C++
createFoo(myChar, 0, 1) // Correct

createFoo( myChar, 0, 1 ) // Incorrect
```

-   ***Do not*** use spaces inside of brackets.

```Objective-C++
x = dataArray\[index\]; // Correct

x = dataArray\[ index \]; // Incorrect
```

-   ***Do*** use a single space before flow control statements

```Objective-C++
while (x == y) { // Correct

while(x == y) { // Incorrect
```

-   ***Do*** use a single space before and after comparison operators

```Objective-C++
if (x == y) { // Correct

if (x==y) { // Incorrect

for (int i=0; i&lt;10; i++) { // Incorrect - needs space around "=" and "&lt;"
}

for (int i = 0; i &lt; 10; i ++) { // Incorrect - no space between 'i' and '++'
}
```

#### 2.1.4    Use Plenty of Empty Lines to Improve Code Readability

Make liberal use of empty lines to separate code, member variables, etc. to aid in readability.

Beyond this general guideline, **certain specifics are preferred**:

-   A closing brace should be followed by a blank line, unless the next line itself is a right curly brace.

-   A single-line C comment (or block of such comments) should be preceded by a blank line, a line with an opening brace, or class access modifier.

-   Class access modifiers should be preceded by a new line, or an opening brace.

Without the use of empty lines, it is often harder to glance at code and see its useful elements. Some examples hopefully will demonstrate:

```Objective-C++
// Incorrect - missing empty lines before single-line comments; code "too dense" in general
class Template {
    // This is a comment
    unsigned long _member1;
    // This is another comment...
    // ...and the second line of the comment
    unsigned long _member2;
    // Static members
    static unsigned long s_static;
public:
    // Methods
    void function(int param);
};

// Correct
class Template {
    // This is a comment
    unsigned long _member1;

    // This is another comment...
    // ...and the second line of the comment
    unsigned long _member2;

    // Static members
    static unsigned long s_static;

public: 
    // Methods
    void function(int param);
};

// Incorrect - missing empty lines after braces
HRESULT myFunc(int i, int j) {
    switch (i) {
    case 0:
        if (j == 0) {
            doSomethingElse(i, j);
        }                // Empty line required following this one.
        break;
    }

    if (i == 5) {
    }                    // Empty line required following this one.
    return S_OK;
}

// Correct
HRESULT myFunc(int i, int j) {
    switch (i) {
    case 0:
        if (j == 0) {
            doSomethingElse(i, j);
        }

        break;
    }

    if (i == 5) {
    }

    return S_OK;
}
```

#### 2.1.5    Copyright/Licensing Banner


All first-party and modified third-party code files must contain *at least* the below Microsoft copyright/MIT license banner. If *additional* attribution is applicable, be sure to include that as well.

**Note:** Our codebase is comprised of code from various third-parties which usually already include a banner. **Do Not** replace any such banners with the header below, but **Do Add** the Microsoft copyright to the banner if a modification is made to the file.

```Objective-C++
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
```

#### 2.1.6 Bracing Style

Our bracing style is most similar to the [Stroustrup variant of the K&R style](https://en.wikipedia.org/wiki/Indent_style#Variant:_Stroustrup). Open-braces go on the same line as the statement control statement, class name, function name, etc. However, the closing brace always goes on its own line, unless it's 'cuddled' against an else statement.

```Objective-C++
if (a == b) { // Correct
   ...
}

if (a == b)  // Incorrect - opening brace goes on the same line as the control statement
{
   ...
}


if (a == b) { ... } // Incorrect - code and closing braces go on their own lines

if (a == b) { 
   ...
} else if (b < a) { // Correct else placement
   ...
}

if (a == b) { 
   ...
} 
else if (b < a) { // Incorrect - else should be 'cuddled' on the previous line
   ...
}

```

#### 2.1.7    Always Use Braces Around Bodies

***Always uses braces to indicate the scope of a given body of code***. This prevents easily avoidable bugs such as the infamous "goto fail" SSL security flaw.

```Objective-C++
if (a == b) { // Correct
    C();
}

if (a == b) // Incorrect - missing braces
    C();

if (a == b) C(); // Incorrect - missing braces
```

Also, ***always brace around case clauses that introduce variables***. This prevents confusing scenarios where variables may not be initialized while looking like they are.

```Objective-C++
switch (val) {
    case c_abc:
        handleAnAbc(); // Correct, no variables introduced
        break;

    case c_def: {
        int someState = doComplicatedTechnology(); // Correct, introduced variables are brace-enclosed
        break;
    }
}

switch (val) {
    case c_def:
        int someState = doComplicatedTechnology(); // Incorrect, introduced variables are brace-enclosed
        break;

    case c_abc:
        return someState; // Incorrect, jumping over initialization!
}
```

#### 2.1.8    Add Parenthesis around Binary Expressions

Parenthesis **should be** used where ambiguity may otherwise exist for the reader, and to also make complex statements easier to visually parse.

```Objective-C++
int foo;
IBar* bar;
ULONG zot;
BOOL moop;
std::string message;

// Correct
if ((foo > 10) && moop && !bar && ((zot & 0x8) == 0x8) && (message == "ponies")) {
    // ...
}

bool isValid = ((foo > 10) && moop && !bar && ((zot & 0x8) == 0x8) && (message == "ponies"));

// Incorrect (well, correct code, but incorrect style)
// Surround "foo > 10", "message == ponies", etc.
if (foo > 10 && !bar && (zot & 0x8) == 0x8 && message == "ponies") {
    // ...
}

bool isValid = foo > 10 && !bar && (zot & 0x8) == 0x8 && message == "ponies";
```

#### 2.1.9 auto Keyword

Use the auto keyword when the type on the lefthand side of an assignment is redundant, because the type is *also* clearly specified on the righthand side.

Use of auto is also encouraged where it genuinely improves code readability (for STL iterators, etc.), or where absolutely required because code would not compile without it (if a type is not explicitly expressible by the programmer, for example).

Enforcement must err on the side of excluding the use of auto - under-use is deemed better than over-use.

```Objective-C++
// Not allowed - the type of the variable is not clear
auto count = 7;
auto name = "name";
auto model = foo.getTheModel();

// Correct
int count = 7;
const char* name = "name";

auto model = std::make_shared<Model>();

auto message = ref new Platform::String("The message");

auto foo = reinterpret_cast<Foo*>(bar);

// OK -- the alternative is just too painful
// for (const std::pair<std::wsstring, std::vector<std::pair<int, std::shared_ptr<Foo>>>>::iterator &mapEntry : map)

std::unordered_map<std::wsstring, std::vector<std::pair<int, std::shared_ptr<Foo>>>> map;
for (auto& mapEntry : map) {
   // ...
}

// OK -- type is not expressable
auto lambda = []() -> void {};
```

#### 2.1.10    init and dealloc

**init** methods should be placed at the top of the implementation, directly after the @synthesize and @dynamic statements. **dealloc** should be placed directly below the init methods of any class. In files with ARC disabled, **dealloc** *must* call **super**'s dealloc at the end of its implementation.

Init methods should be structured as follows:

```Objective-C++
- (instancetype)init {
    if (self = [super init]) { // Or call the designated initializer
        // Perform class-specific init
    }

    return self;
}
```

See [Apple's initialization documentation](https://developer.apple.com/library/ios/documentation/General/Conceptual/CocoaEncyclopedia/Initialization/Initialization.html) for more info.


#### 2.1.11    Objective C ARC Variable Qualifiers

ARC variable qualifiers (__strong, __weak, __unsafe_unretained, __autoreleasing) should be placed before the variable name.

```Objective-C++
NSString* __weak name;
```

#### 2.1.12    Use "" and &lt;&gt; correctly in #include and #import directives

For readability purposes, use "header.h" when referring to a header which is local to the project of the includer. Use &lt;header.h&gt; when referring to a header which is not local to project of the includer. 

#### 2.1.13    Avoid Comma Delimited Variable Declarations

Avoid declaring more than one variable name after a given type, as that conflicts with our [variable initialization guidance](#4.1.3-variable-declarations-and-assignment).

```Objective-C++
// Incorrect
MyType* type1, type2;

// Correct
MyType* type1;
MyType type2;
```

#### 2.1.14    Grouped Declarations

When declaring a set of variables, the members of a class, or any other sequence of defined objects, **avoid vertically aligning the *names* of the variables**. The quick reader should not need to scan horizontally to find the name of the local whose type is "int":

```Objective-C++
// Incorrect - too many spaces between the type and the instance name
int                    local1;
HANDLE                 localHandle2;
ReallyLongTypeNameHere local3;

struct Zoom
{
    int                 size;
    HANDLE              fileTarget;
};

// Correct
int local1;
HANDLE localHandle2;
ReallyLongTypeNameHere local3;

struct Zoom
{
    int size;
    HANDLE fileTarget;
};
```

#### 2.1.15    Comments Format

Every class, struct, interface, method, and function declaration **should be** commented - including private and protected ones.

**Exemptions:** Constructors, destructors, initializers, uninitializers (dealloc, etc.), and any descriptively-named methods which wouldn't benefit from additional commenting are all exempt from this guidance.

At a minimum, add method/function comments to their *declarations*, but additional commenting can be added to their *definitions* as needed (comments on method implementations are not mandatory, but can be provided). Do not replicate method comments on overrides; for example comment the method declaration in an interface, but avoid re-commenting the same methods again in method override declarations in classes which implement the interface.

Class comment example:

```Objective-C++
// Include class description here. It should briefly describe the purpose of this class
// over one or more lines.
```

Method comment example:

```Objective-C++
// Include method description here. It should briefly describe the purpose of this method
// and optionally mention the return value an any interesting error handling characteristics.
```

Avoid duplicating comments from interfaces or base classes in the implementation of child classes:

```Objective-C++
struct IFoo {
   // Call to create and cook a waffle.
   virtual std::unique_ptr<Waffle> generateWaffle() = 0;
};

class Foo : public IFoo {
   // Call to create and cook a waffle. ? Incorrect, this duplicative comment is a maintanance liability
   std::unique_ptr<Waffle> generateWaffle() override;

   // IFoo::generateWaffle
   std::unique_ptr<Waffle> generateWaffle() override; // Correct - dedicated section for the IFoo implementation
};
```

Implementation details are commented inside the actual implementation using regular C++ style comments.

**Avoid** adding comments *next to* code on the same line - instead, prefer to place comments on the previous line (with the exception of [documenting large function calls](#2.1.1-breaking-parameters-for-function-calls)).

If there are general comments that apply to a method implementation, they can go above the implementation:

```Objective-C++
Foo.h:

// No need to comment here, as it's pretty obvious what this method does.
// However, it may be desirable to comment initialization specifics in some cases.
void initialize();

Foo.cpp:

// This block is optional, but extra comments here are ok as long as they're not identical to the 
// comments in the method declaration.
void initialize() {
  // Implementation detail
  doSomething();

  // Another implementation detail
  doSomethingElse();
}
```

#### 2.1.16    Prefer standard C++ types over Win32 typedefs
Use C++ types; avoid using 'shouty' Win32 types. Interop concerns, however, can override this guideline.

```Objective-C++
// Correct
int fooValue;
unsigned long long barThing;
size_t count;
void foo(int x);
bool flag;

// Incorrect - prefer C++ types
ULONG barThing;
SIZE_T count;
DWORD thing;
QWORD otherThing;
TCHAR character;
LPWSTR wideStr;
```

#### 2.1.17    No space between a type name and any associated pointer, hat, or reference symbols

```Objective-C++
// Correct
int** outCount;
Foo^ foo;
MyStruct& s;
MyStruct& DoSomething(Foo^ foo);
std::vector<Foo^> m_vector;

// Incorrect
int **outCount;
int * count;
Foo ^ foo;
Foo ^foo;
MyStruct &s;
MyStruct & s;
MyStruct &doSomething(Foo ^foo);
std::vector<Foo ^> m_vector;
```

#### 2.1.18    Namespace declarations

Nested namespace declarations should each get their own line, and should not create additional levels of indentation.

```Objective-C++
// Correct
namespace A
{
namespace B
{
namespace C
{

class Foo {
    ...
}

}
}
}

// Incorrect
namespace A {
    namespace B {
        namespace C {
            class Foo {
                ...
            }
        }
    }
}

// Incorrect
namespace A { namespace B { namespace C {

class Foo {
    ...
}

}}}
```

#### 2.1.19    Casting

Use C++ casts rather than C casts in all cases. C++ casts are more explicit, give finer-grained control, and express the intent of the code more clearly. There are three types of C++ casts we should be using:

1.  static\_cast handles related types such as one pointer to another in the same hierarchy.

2.  reinterpret\_cast handles conversion between unrelated types.

3.  const\_cast is used to cast away the 'const'ness of an object.

    **Note:** Don't use 'const\_cast' unless absolutely necessary; having to use 'const\_cast' *typically* means that an API is not using 'const' appropriately. However, the Win32 API doesn't always use 'const' for passing parameters, so it may be necessary to use const\_cast when using the Win32 API.

    **Note:** 'const\_cast' doesn't apply to Objective C objects, as there's no such thing as a 'const NSObject\*', etc.

*Further reading:*

-   *Sutter, H. (2005). - C++ Coding Standards* - "Item 94: Avoid casting away const."

-   *Sutter, H. (2005). - C++ Coding Standards* - "Item 95: Don't use C-style casts."

#### 2.1.20    Prefer const values over #define constants for better type safety

Define named constant values as 'const' values rather than via macros when possible, to provide the added benefit of type safety.

Also consider leveraging enum classes for grouped constant values.

```Objective-C++
// Correct
const int c_defaultIndex = 3;

// Incorrect
#define DEFAULT_INDEX 3
```

*Further reading:*

-   *Sutter, H. (2005). - C++ Coding Standards* - "Item 15: Use const proactively."

#### 2.1.21    Use macros with discretion
Use macros only when they are absolutely necessary. Most functionality that is typically achieved through macros can be implemented through other C++ constructs (using constants, enums, inline functions, or templates) which will yield clearer, more resilient, more debuggable code.

## 3 Naming Conventions

This section covers variable names, function names, type names, etc.

-   Objective C code should follow [Apple's naming guidelines](https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/CodingGuidelines/Articles/NamingBasics.html) in addition to the applicable guidance listed in this document.

-   Class and namespace names are based on PascalCasing.

-   Function and variable names are based on camelCasing.

-   Non-public function and variable names must start with an underscore.

-   Avoid using abbreviations.

-   Only simple loop counter variables may be single letters.

-   Hungarian notation is prohibited.

-   Class names must not have a C prefix or have "Class" in them.

-   Interface names must start with I and not have "Interface" in them.

-   Avoid typedefs and aliases for simple types (where not required for interop with Objective C clients).

-   SHOUTY\_NAMES are only allowed (and required) for preprocessor macros.

The sections that follow provide examples and additional discussion.

### 3.1 Variable Naming
***Hungarian is not allowed.*** The light prefixing convention described in this section for certain variable types is not Hungarian, despite superficial similarities.

#### 3.1.1    Abbreviations should be avoided

Code should be clear *and* concise, but clarity should not suffer. Some abbreviations may be well-known to you, but a new developer to the team or technology may not easily recognize them. It's best to avoid abbreviations when possible.

See the [Apple docs](https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/CodingGuidelines/Articles/NamingBasics.html) for further guidance on proper Objective C naming guidelines.

```Objective-C++
// Correct
int id; // Common abbreviation for 'identifier'
const char* name;
int current;
timespec time;
NSTimeInterval date;
char* params;

// OK - although more descriptive names are preferred
int curVal; // Ok; common abbreviation for 'current value'
int ret; // Ok; common abbreviation for 'return value'
Foo* obj; // Ok; common abbreviation for 'object'

// Incorrect
int val;
const char* str;
int cur;
timespec t;
NSTimeInterval d;
```

#### 3.1.2    Out parameters
For out parameters, **do** prefix your variable names with 'out' to help clarify the parameter's usage.

#### 3.1.3    Pointers
**Do not** use 'p' as a prefix for pointer types, as that doesn't work well with smart pointers, C++/CX hats, or Objective C pointers which don't historically use the 'p' prefix.

#### 3.1.4    Raw strings are not treated specially
No further prefixes are used for raw strings (no 'sz', 'psz', etc.)

### 3.2    Member Naming

#### 3.2.1    Class members
**Use the "\_" prefix** on all data members of Objective C and C++ classes. This is consistent with Objective C instance variables that are synthesized automatically by the compiler.

If the compiler can synthesize your Objective C variable automatically, then let it.

**Use the "\_" prefix** on *private and protected* methods of C++ and Objective C classes.

```Objective-C++
class Foo {
public:
    void doFoo();

private:
    int _count;
    wstring _name;

    void _moop();
    int _zeem();
};
```

#### 3.2.2    Structs vs Classes
If you need behaviors beyond simple initialization of fields in a constructor, use a class.

No prefix is allowed on fields in a structure.

```Objective-C++
struct Foo {
    size_t size;
    int count;
    const char* name;
};
```

### 3.3    Use Proper Casing for Variable, Method, and Type Names
**Do use PascalCasing for types and namespaces**. This pattern capitalizes the first letter of each logical word in a name. Do not add underscores between word-pieces in a name.

**Do use camelCasing for functions and variables (parameters, local variables, etc.).** This pattern capitalizes the first letter of each logical word in a variable name, except the first. Note that this means that single-word names are lower-case, and that prefixed variables (s\_, c\_, etc.) have the pattern s\_camelCase.

**Do not** confuse words with syllables. UndoOperation makes sense as function name; UnDoOperation does not.

### 3.4    Only Counters May Be Single Letters
Such as:

```Objective-C++
for (int i = 0; i < 10; i++) {
}
```

### 3.5    Static/Global Variables use the "s_" prefix
Static and global variables name must start with "s\_". The remainder of the variable follows the standard camelCasing rules. This helps flag the variable as static (not thread safe, singleton, etc.).

### 3.6    Constants use the "c_" prefix
Use "c\_" for constants (e.g. variables with "static const" C++ qualifier). The remainder of the variable follows the standard camelCasing rules. Exceptions will be made for interop.

There is no need to combine "c\_" with other prefixes ("sc", etc).

### 3.7 Aggregate Type Naming
Consistency within a single directory or source file is important.

-   Class names must not start with the "C" prefix.

-   Use "struct Foo{};" instead of "typedef struct FOO {} Foo;" where not required for interop with Objective C clients.

-   Interfaces (like COM, or C++ types that have only "virtual Foo() = 0" members) *must* start with the "I" prefix. ("IBar" is valid, "Bar" is not)

-   Creating new SHOUTY\_TYPE\_NAMES is prohibited; ALL\_CAPS is reserved for macros.

-   Do not include "Class" or "Interface" in names - "Bar" instead of "BarClass", "IFoo" not "IFooInterface"

### 3.8    Avoid typedefs and aliases When Possible
Overuse of typedefs and aliases can easily lead to confusing code. However, function types are usually exempt from this guidance.

```Objective-C++
// correct
std::vector<id> _ids;
...
std::vector<id>& getIds();

using MyCallback = void (*)(int, const std::string&); // Ok, as MyCallback is much nicer to use
virtual void subscribe(const MyCallback& callback);

// incorrect
using IdContainer = std::vector<id>;
IdContainer _ids;
...
IdContainer& getIds();
```

### 3.9    Macro Naming
Macro names should be all capitalized, with underscores between words.

```Objective-C++
// correct
#define THROW_IF_FAILED(operation)

// incorrect
#define ThrowIfFailed(operation) - should be all caps
#define THROWIFFAILED(operation) - missing underscores
```

## 4 Code Design
Objective C code should follow [Apple's coding guidelines](https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/Conventions/Conventions.html) in addition to the applicable guidance listed in this document.

-   All code should compile for Objective C++ or C++.

-   Always use 'self.' when accessing your own public Objective C properties.

-   Declare variables as locally as possible.

-   Initialize variables when they are declared, and on a single line where possible*.*

-   Prefer C++ references over raw pointers when ownership is not required.

-   Prefer smart pointers over raw pointers in *nearly* all other cases.

-   Avoid accepting non-const C++ references as arguments to public methods.

-   Do not invent your own containers, locks, etc. where the STL or Foundation types will suffice.

-   Use enum classes (aka scoped enums) instead of unscoped enums.

-   Use range-based for loops when possible. This includes ObjC's enumerator loops.

-   Avoid the use of gotos; use RAII constructs instead.

-   Prefer deleted functions to private undefined ones.

-   Prefer alias declarations to typedefs.

### 4.1    Additional Details

#### 4.1.1    Defining Objective C Properties
Use Objective C property definitions rather than raw instance variables for public fields. Do not expose ivars publicly.  Private ivars should be declared in the implementation file or an internal header for the extension class, when used across classes.

```Objective-C++
// Correct
@interface MyObject: NSObject

@property (nonatomic) NSString* name;

@end

// Incorrect
@interface MyObject: NSObject {
    NSString* name;
}
```

#### 4.1.2    Accessing Objective C Properties
**Use** direct access to instance variables under the following circumstances:

-   Within initializer methods (init, etc.) and delloc methods.

-   From within custom property setters and getters.

-   When the public property type differs from the type of the actual backing variable, and access to the backing variable's functionality is necessary. For example, a class may expose a public NSArray property, yet still wish to modify its contents internally. In such cases, the class will need to store an NSMutableArray variable internally, and access it directly when any array modifications are necessary.

-   For any private or otherwise internal state.

See more information in [Apple's documentation](https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/MemoryMgmt/Articles/mmPractical.html#//apple_ref/doc/uid/TP40004447-SW6).

**Always use** 'self.' when accessing your own public properties. Certain properties will be externally observed, expecting callbacks on state change.

#### 4.1.3 Variable Declarations and Assignment
**Do** declare variables as locally as possible. This makes the code much easier to read, and also reduces the chance of coding errors.

**Prefer to** initialize variables when they are declared, and on a single line (where the language allows it)*.*

*Further reading*:

-   *Sutter, H. (2005). - C++ Coding Standards* - "Item 18: Declare variables as locally as possible."
-   *Sutter, H. (2005). - C++ Coding Standards* - "Item 19: Always initialize variables."

#### 4.1.4    Prefer C++ references over raw pointers when ownership acquisition is not required
Lifetime ownership is rarely clear when passing around raw pointers; using a C++ reference is much more clear.

```Objective-C++
class Node {
private:
    Node& _parent; // Correct - _parent ownership is clearly handled elsewhere.
    INode& _root; // Correct - _root ownership is clearly handled elsewhere, even for interface types.
}

class Node {
private:
    Node* _parent; // Incorrect - _parent ownership is not clear; do I need to free it in my dtor?
    INode* _root; // Incorrect - _root ownership is not clear; do I need to free it in my dtor?
}
```

#### 4.1.5    Prefer smart pointers over raw pointers in nearly all cases
Passing raw pointers between objects makes it unclear who is responsible for freeing the pointer. Modern code dictates that smart pointers should be used instead of raw pointers in nearly all cases, leading to safer and more clear code. See the [RAII](#4.2-raii) section for more details.

**Note:** Special cases to this rule do still exist, but such cases are usually self-contained within a given class implementation/compilation unit. For example, a .wav file parser would clearly need to work with raw pointers to locations within a mapped audio file, but such usage would not need to bleed out to other components.

```Objective-C++
class Node {
private:
    std::weak_ptr<Node> _parent; // Correct - _parent ownership is clearly handled independently of this object's lifetime.

    std::weak_ptr<INode> _root; // Correct - _root ownership is clearly handled independently of this object's lifetime.

    WRL::WeakRef _root; // Correct - _root ownership is clearly handled independently of this object's lifetime.
}

class View {
private:
    std::shared_ptr<Node> _root; // Correct - _root ownership is clearly shared across multiple objects.

    std::unique_ptr<IDataSource> _source; // Correct - _source ownership is clearly self-contained within this View.

    WRL::ComPtr<IDataSource> _source; // Correct - _source ownership is clearly self-contained within this View.
}

class Node {
private:
    Node* _parent; // Incorrect - _parent ownership is not clear; do I need to free it in my dtor?

    INode* _root; // Incorrect - _root ownership is not clear; do I need to free it in my dtor?
}

class View {
private:
    Node* _root; // Incorrect - _root ownership is not clear; do I need to free it in my dtor?

    IDataSource* _source; // Incorrect - _source ownership is not clear; do I need to free it in my dtor?
}
```

#### 4.1.6    Prefer alias Declarations to typedefs
Aliases support template arguments.

*Further reading*:

-   *Meyers, S. (2015). - Effective Modern C++* - "Item 19: Use std::shared_ptr for shared-ownership resource management."

### 4.2 RAII

#### 4.2.1 Use std::unique_ptr for exclusive-ownership of C++ types
Start with a unique_ptr if you're unsure whether or not you need to share ownership of a resource with other components -- this is usually the correct choice. The nice thing about exclusive ownership is that the shutdown is deterministic, which allows you to provide temporary controlled access to your exclusive resource via a strong C++ reference.

```Objective-C++
class Bar {
public:
    void doSomething(const Node& node);
}

class Foo {
private:
    std::unique_ptr<Node> _root; 
    std::unique_ptr<Bar> _listener; 

    void update()
    {
        _listener->doSomething(*_root); // Passing a controlled reference into _listener 
    }
}
```

*Further reading*:

-   *Meyers, S. (2015). - Effective Modern C++* - "Item 18: Use std::unique_ptr for exclusive-ownership resource management."

#### 4.2.2 Use std::shared_ptr for shared-ownership of C++ types
Use std::shared_ptr if you must share ownership with multiple components, of if you need to hand out std::weak_ptrs to a resource to avoid cyclic dependencies.

*Further reading*:

-   *Meyers, S. (2015). - Effective Modern C++* - "Item 19: Use std::shared_ptr for shared-ownership resource management."

#### 4.2.3    Use WRL::ComPtr for shared-ownership of COM objects
COM usage isn't common in our code, but if you must call into a COM API, all COM pointer usage must be wrapped in WRL::ComPtrs at all times.

#### 4.2.4    Smart Handles
*__TODO: Write up examples/guidance for smart handle usage.__*

#### 4.2.5    ScopeGuard/ScopeExit
*__TODO: Write up examples/guidance for scopeexit usage; include in 'goto' cleanup example.__*

#### 4.2.6    Avoid the use of gotos
*__TODO: Write up justification/guidance, how to use RAII to avoid the need for gotos, etc.__*

### 4.3 Objective C Memory Management
*__TODO: Write up guidance; ARC, usage of variable qualifiers (__unsafe_unretained, etc.).__*

### 4.4    Method Parameters

#### 4.4.1    Pass smart pointers into methods by const reference, return smart pointers by value when possible

```Objective-C++
// Correct
CComPtr<IMyInterface> getFoo(); // Throws on failure
HRESULT tryGetFoo(IMyInterface** outInterface); // Returns error on failure
HRESULT tryDoSomethingWithFoo(const CComPtr<IMyInterface>& interface); // Allows ownership acquisition by the callee
HRESULT tryDoSomethingWithFoo(IMyInterface& interface); // Discourages ownership acquisition by the callee

// Incorrect
HRESULT getFoo(CComPtr<IMyInterface>& myInterface);
HRESULT getFoo(CComPtr<IMyInterface>* myInterface);
HRESULT doSomethingWithFoo(CComPtr<IMyInterface> myInterface); // Unnecessary addref/release
HRESULT doSomethingWithFoo(const CComPtr<IMyInterface> myInterface); // Unnecessary addref/release - and never pass by-value const.
```

#### 4.4.2    Prefer C++ references over raw pointers in method arguments
Except for at ABI boundaries, use C++ references whenever possible, and avoid raw pointers. 

This is true for even mutable method arguments, but such cases should rarely be encountered publicly, because methods can and should return values instead of having 'out' params. Use STL's pair, tuple, or custom structs to return compound values.

```Objective-C++
// Correct
int GetFoo();
const std::wstring& getName();
std::pair<Foo, Bar> getValue();
MyStruct getValue();
bool inspectMyStructForSomeCondition(const MyStruct& value);

// Ok
bool populate(MyStruct& value); // Ok, but odd on a public method.  Populates the struct.
bool populateIfExists(MyStruct* value); // Ok, but odd on a public method.  Populates the struct if non-null.

// Incorrect
void getFoo(int* pFoo); // Should return int
void getFoo(int& foo); // Should return int
void getName(std::wstring* value); // Should return std::wstring
void getName(std::wstring& value);    // Should return std::wstring
Foo getValue(Bar* value);    // Should return e.g. std::pair<Foo, Bar> or similar construct
Foo getValue(Bar& value);    // Should return e.g. std::pair<Foo, Bar> or similar construct
void getValue(Foo* found, Bar* value); // Should return e.g. std::pair<Foo, Bar> or similar construct
```

#### 4.4.3    Use encapsulated resource types, except when crossing boundaries
For internal use, resources should be encapsulated in smart types (e.g. STL containers or constructs), instances of which are passed around by reference. However, C++ types should not be passed across certain boundaries; resources must be unwrapped and accepted and returned in raw form. The definition of a boundary depends on context; in general a publicly consumable COM object is a boundary, as is a DLL.

```Objective-C++
// Correct
class SomePublicFacingClass {
    void somePublicFacingCall(char* data, size_t len);
};

// Incorrect - unsafe
class SomePublicFacingClass {
    void somePublicFacingCall(std::vector<char>& data); // Incorrect - unsafe
};
```

### 4.5    Multiple Inheritance
C++ supports multiple inheritance and certain common patterns rely heavily on this language feature. The most obvious example is COM, where multiple *interface* inheritance is used routinely (although COM will not be very commonly used in our codebase).

Multiple *implementation* inheritance, on the other hand, is confusing, leading to issues such as [the diamond problem](http://en.wikipedia.org/wiki/Diamond_problem), casting ambiguities, and constructor ordering issues. Do not use it in new code. Instead, consider design patterns involving encapsulation and interfaces.

Bottom line: inherit from at most one concrete class, and any number of interface classes.

## 5 Error Handling

### 5.1 Assertions 

Use assertions liberally, but be careful to distinguish between what is an assertion and what is a run-time error.

Assertions ***always*** indicate programmer error or miscommunication; valid assertions include cases where an internal contract or invariant is violated or broken.

Assertions should ***never*** be used for a run-time error which your code could handle gracefully.

Assertions should ***never*** be used for a run-time error which is catastrophic/unrecoverable; use [failfast semantics](#5.2-failfast) instead.

An assertion failure ***always*** indicates a bug in the code, whether it is triggered by end-user usage, self-host usage, or tests.

**Incorrect** assertions include (but are not limited to):

-   Before a conditional test that handles the same error condition.

-   Checking a pointer for being not nullptr (crashing is of higher diagnostic value than the assertion failure).

    -   **Note:** Given that sending messages to nil Objective C objects silently fails, asserts for non-nil are ok. However, ***prefer*** handling the error in code, returning an error to the caller, or using [failfast semantics](#5.2-failfast) if any of those options make more sense.

-   Validating any input parameters to a function where the values may come from external sources (external component, user, registry, database, file, etc.).

-   Validating that a function succeeded or failed.

All of the above items should be converted from an ASSERT to the appropriate error handling and/or telemetry-logging mechanism, if not removed altogether.

#### 5.1.1 Prefer static_assert Over ASSERT Where Possible
The only allowed assertion macros are ASSERT and static_assert.  Use static_assert wherever it's possible to perform the check at compile time.

#### 5.1.2    Asserts in tests
Assertions hit under test always indicate bugs.  Unit tests should not deliberately test for assertions.

### 5.2 FailFast
*__TODO: Add guidance on when to assert vs. fail fast.__*

*__TODO: Add guidance on usage of unsupported/invalid_state macros.__*

### 5.3 Exceptions
*__TODO: Add guidance on our exception-handling strategy.  When to use over HRESULTs, and vice-versa.__*

*__TODO: Add guidance on where to add exception guards to prevent leaked exceptions.__*

### 5.4 Error Codes
*__TODO: Add guidance on our error-code handling strategy; HRESULTs, etc.  When to use over exceptions, and vice-versa.__*