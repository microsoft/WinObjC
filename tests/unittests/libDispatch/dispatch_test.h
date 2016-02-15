#include <TestFramework.h>
#include <errno.h>
//#include "os_shims.h"
#include <dispatch/dispatch.h>

__DISPATCH_BEGIN_DECLS
// The dispatch test cases are open source code, and there is no as_do definition for _CPlusPlus Macro.
#define as_do(para) para

void test_start(const char* desc);
void test_stop(void);
void test_stop_after_delay(void* delay);

#define test_ptr_null(desc, val) ASSERT_TRUE_MSG((val == NULL), desc)

#define test_ptr_notnull(desc, val) ASSERT_TRUE_MSG((val != NULL), desc)

#define test_ptr(desc, actual, expected) ASSERT_EQ_MSG(actual, expected, desc)

#define test_long(desc, actual, expected) ASSERT_EQ_MSG(actual, expected, desc)

#define test_long_less_than(desc, actual, expected) ASSERT_LT_MSG(actual, expected, desc)

#define test_double_less_than_or_equal(desc, actual, expected) ASSERT_LE_MSG(actual, expected, desc)

#define test_double_less_than(desc, actual, expected) ASSERT_LT_MSG(actual, expected, desc)

__DISPATCH_END_DECLS