
#ifndef H0WXD_TEST_TESTS_MACROTEST_HPP
#define H0WXD_TEST_TESTS_MACROTEST_HPP

#include "Main.hpp"
#include "h0wXD/Macros.hpp"

namespace h0wXD
{
	namespace Test
	{
		class MacrosSampleClass
		{
			bool m_bTestBool;
			int32 m_iTestInt;
			uint32 m_uiTestInt2;

		public:
			ACCESSOR(bool, TestBool, m_bTestBool);
			ACCESSOR_GET(int32, TestInt, m_iTestInt);
			ACCESSOR_SET(uint32, TestInt2, m_uiTestInt2);

			PROPERTY(MacrosSampleClass, int, EpicProperty);

			MacrosSampleClass() :
				m_bTestBool(false),
				m_iTestInt(1234),
				m_uiTestInt2(0)
			{
				EpicProperty = 0;
			}
		};

		const lest::test MacrosTest[] =
		{
			CASE("Getter and setter macros can be accessed" "[MacrosSampleClass]")
			{
				SETUP("A test class implementing macros")
				{
					MacrosSampleClass testClass;
					
					SECTION("TestBool get & set (ACCESSOR)")
					{
						EXPECT(testClass.GetTestBool() == false);

						testClass.SetTestBool(true);
						EXPECT(testClass.GetTestBool());

						testClass.SetTestBool(false);
						EXPECT(!testClass.GetTestBool());
					}
					SECTION("TestInt get (ACCESSOR_GET)")
					{
						EXPECT(testClass.GetTestInt() == 1234);
					}
					SECTION("TestInt2 set (ACCESSOR_SET)")
					{
						testClass.SetTestInt2(156316);
					}

					SECTION("EpicProperty get & set (PROPERTY)")
					{
						auto value = 123;
						EXPECT(testClass.EpicProperty == 0);

						testClass.EpicProperty = value;
						EXPECT(testClass.EpicProperty == value);

						value = 456;
						testClass.EpicProperty = value;
						EXPECT(testClass.EpicProperty == value);
					}
				}
			}
		};
	}
}

#endif
