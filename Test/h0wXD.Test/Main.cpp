
#include "Main.hpp"
#include "Tests/MacrosTest.hpp"

namespace h0wXD
{
	namespace Test
	{
		const lest::test no_using_namespace_lest[] =
		{
			CASE("Namespace lest is specified correctly in lest.hpp [compile-only]")
			{
				EXPECT(true);
				EXPECT_NOT(false);
				EXPECT_NO_THROW(true);
				EXPECT_THROWS(true);
				EXPECT_THROWS_AS(true, std::exception);
			},
		};
	}
}

int main()
{
	auto iResult = 0;

	iResult |= lest::run(h0wXD::Test::MacrosTest);

	return iResult;
}

