
#include "h0wXD/Types.hpp"
#include <lest.hpp>

#define CASE_E(_NAME) \
    _NAME, [](env &)

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

const lest::test BooleanTest[] =
{
    CASE("Just testing lest...")
    {
        EXPECT(false == false);
        EXPECT(true == true);
    },
};

const lest::test StringTest[] =
{
    CASE("Just testing lest...")
    {
        EXPECT("123" == std::to_string(123));
        EXPECT("124" != std::to_string(123));
    },
};

int main()
{
	auto iResult = 0;

	iResult |= lest::run(BooleanTest);
	iResult |= lest::run(StringTest);

	return iResult;
}
