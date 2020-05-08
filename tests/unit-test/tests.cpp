#include <catch2/catch.hpp>

unsigned int Factorial(unsigned int n) { return n <= 1 ? n : Factorial(n - 1) * n; }

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}
