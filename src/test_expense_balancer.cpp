#include <map>
#include <sstream>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include "expense_balancer.h"

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
        std::map<std::string, double> members{{"Bob", 0.0}};
        print_balances(members, ss);
        CHECK(ss.str() == "Bob: 0\n");
    }

    SUBCASE("given one member 'Bob Yays' with a balance of 0.0, "
            "and another member 'Alice' with a balance of 8.5, "
            "when print balances, "
            "'Alice: 8.5\\nBob Yays: 0\\n' is printed") {
        std::map<std::string, double> members{{"Bob Yays", 0.0}, {"Alice", 8.5}};
        print_balances(members, ss);
        CHECK(ss.str() == "Alice: 8.5\nBob Yays: 0\n");
    }
}
