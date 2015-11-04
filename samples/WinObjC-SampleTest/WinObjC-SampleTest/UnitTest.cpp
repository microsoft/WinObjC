#include "pch.h"
#include "CppUnitTest.h"

/*
 * Should be moved to Obj-C header(s).
 */
extern "C" void SanityTest1();

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WinObjC_SampleTest
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
			SanityTest1();
        }
    };

	/*
	 * Logger wrapper - Yes we are not able to include CppUnitTest.h in Obj-C source file directly.
	 */
	extern "C" void myLog()
	{
		Logger::WriteMessage("Hello");
	}

	/*
	* Assert wrapper example - We need to do this for all asserts we are interested in.
	*/
	extern "C" void AssertIsTrue(bool condition)
	{
		Assert::IsTrue(condition);
	}

}