#include <map>
#include <sstream>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include "expense_balancer.h"

TEST_CASE("calculating owed Rs of each member") {

    SUBCASE("given there are no members, "
            "when compute minimimum balances, "
            "the result is empty") {
        std::map<std::string, double> min_balances{compute_min_balances({})};
        CHECK(min_balances.empty());
    }

    SUBCASE("given one member 'Bob' with an expense of 0.0, "
            "when compute minimum balances, "
            "Bob's minimum balance is 0.0") {
        std::map<std::string, double> expenses{{"Bob", 0.0}};
        auto min_balances = compute_min_balances(expenses);
        REQUIRE(min_balances.find("Bob") != min_balances.end());
        CHECK(min_balances.at("Bob") == 0.0);
    }

    SUBCASE("given one member 'Bob Yays' with an expense of 6.4, "
            "and another member 'Alice' with an expense of 0.0, "
            "when compute minimum balances, "
            "'Alice's minimum balance is 3.2, "
            "and 'Bob Yays's minimum balance is 0.0") {
        std::map<std::string, double> expenses{
            {"Alice", 0.0}, {"Bob Yays", 6.4}};
        auto min_balances = compute_min_balances(expenses);

        REQUIRE(min_balances.find("Alice") != min_balances.end());
        CHECK(min_balances.at("Alice") == doctest::Approx{3.2});
        REQUIRE(min_balances.find("Bob Yays") != min_balances.end());
        CHECK(min_balances.at("Bob Yays") == doctest::Approx{0.0});

    }

    SUBCASE("given one member 'Alice' with an expense of 0.1, "
            "and another member 'Bob' with an expense of 9.9, "
            "and another member 'Charlie' with an expense of 0.6, "
            "when compute minimum balances, "
            "'Alice's minimum balance is 3.433333333333, "
            "and 'Bob's minimum balance is 0.0, "
            "and 'Charlie's minimum balance is 3.1") {
        std::map<std::string, double> expenses{
            {"Alice", 0.1}, {"Bob", 9.9}, {"Charlie", 0.6}};
        auto min_balances = compute_min_balances(expenses);

        REQUIRE(min_balances.find("Alice") != min_balances.end());
        CHECK(min_balances.at("Alice") == doctest::Approx{3.433333333333});
        REQUIRE(min_balances.find("Bob") != min_balances.end());
        CHECK(min_balances.at("Bob") == doctest::Approx{0.0});
        REQUIRE(min_balances.find("Charlie") != min_balances.end());
        CHECK(min_balances.at("Charlie") == doctest::Approx{3.1});
    }
}

TEST_CASE("printing members and balances") {
    std::ostringstream ss;

    SUBCASE("given there are no members, "
            "when print balances, "
            "nothing is printed") {
        print_balances({}, ss);
        CHECK(ss.str() == "");
    }

    SUBCASE("given one member Bob with a balance of 0.0, "
            "when print balances, "
            "'Bob: 0\\n' is printed") {
        std::map<std::string, double> balances{{"Bob", 0.0}};
        print_balances(balances, ss);
        CHECK(ss.str() == "Bob: 0\n");
    }

    SUBCASE("given one member 'Bob Yays' with a balance of 0.0, "
            "and another member 'Alice' with a balance of 8.5, "
            "when print balances, "
            "'Alice: 8.5\\nBob Yays: 0\\n' is printed") {
        std::map<std::string, double> balances{
            {"Bob Yays", 0.0}, {"Alice", 8.5}};
        print_balances(balances, ss);
        CHECK(ss.str() == "Alice: 8.5\nBob Yays: 0\n");
    }
}
