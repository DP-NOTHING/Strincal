#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "StringCalc.hpp" // Include the header file for StringCalculator

TEST_CASE("StringCalculator tests", "[StringCalculator]") {
    StringCalculator calculator;

    SECTION("Handles empty string") {
        REQUIRE(calculator.Add("") == 0);
    }

    SECTION("Handles single number") {
        REQUIRE(calculator.Add("4\n") == 4);
    }

    SECTION("Handles two numbers") {
        REQUIRE(calculator.Add("1,2") == 3);
    }
}

TEST_CASE("new line tests", "[StringCalculator]") {
    StringCalculator calculator;

    SECTION("Handles empty string") {
        REQUIRE(calculator.Add("") == 0);
    }

    SECTION("Handles two number") {
        REQUIRE(calculator.Add("4\n2") == 6);
    }

    SECTION("Handles multiple numbers") {
        REQUIRE(calculator.Add("1,2\n3,1\n1") == 8);
    }
    SECTION("Handles multiple numbers with different delimiter") {
        REQUIRE(calculator.Add("//:\n1:2\n3,1\n1") == 8);
    }
    SECTION("Handles multiple delimiter") {
        REQUIRE(calculator.Add("//:;\n1;2:3,4\n1\n1:2:1") == 15);
    }
    SECTION("Handles multiplication when * is delimiter") {
        REQUIRE(calculator.Add("//*\n1,2*3,1") == 6);
    }

}
