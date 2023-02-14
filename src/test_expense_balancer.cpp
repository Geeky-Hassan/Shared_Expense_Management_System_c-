#include "expense_balancer.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <string>
#include <tuple>
#include <vector>
#include <utility>

static std::pair<double, bool> find_account_balance(const std::vector<Account>& accounts,
        const std::string& name) {

    for (const auto& account : accounts) {
        if (account.name == name) {
            return {account.balance, true};
        }
    }
    return {0.0, false};
}

TEST_CASE("calculating owed Rs of each member") {

    SUBCASE("given there are no members, "
            "when compute minimimum balances, "
            "the result is empty") {
        std::vector<Account> min_balances{compute_min_balances({})};
        CHECK(min_balances.empty());
    }

    SUBCASE("given one member 'Bob' with an expense of 0.0, "
            "when compute minimum balances, "
            "Bob's minimum balance is 0.0") {
        std::vector<Account> expenses{{"Bob", 0.0}};
        const auto min_balances = compute_min_balances(expenses);
        const auto [balance, ok] = find_account_balance(min_balances, "Bob");
        REQUIRE(ok);
        CHECK(balance == 0.0);
    }

    SUBCASE("given one member 'Bob Yays' with an expense of 6.4, "
            "and another member 'Alice' with an expense of 0.0, "
            "when compute minimum balances, "
            "'Alice's minimum balance is 3.2, "
            "and 'Bob Yays's minimum balance is 0.0") {
        std::vector<Account> expenses{
            {"Alice", 0.0}, {"Bob Yays", 6.4}};
        const auto min_balances = compute_min_balances(expenses);

        auto [balance, ok] = find_account_balance(min_balances, "Alice");
        REQUIRE(ok);
        CHECK(balance == doctest::Approx{3.2});
        std::tie(balance, ok) = find_account_balance(min_balances, "Bob Yays");
        REQUIRE(ok);
        CHECK(balance == doctest::Approx{0.0});
    }

    SUBCASE("given one member 'Alice' with an expense of 0.1, "
            "and another member 'Bob' with an expense of 9.9, "
            "and another member 'Charlie' with an expense of 0.6, "
            "when compute minimum balances, "
            "'Alice's minimum balance is 3.433333333333, "
            "and 'Bob's minimum balance is 0.0, "
            "and 'Charlie's minimum balance is 3.1") {
        std::vector<Account> expenses{
            {"Alice", 0.1}, {"Bob", 9.9}, {"Charlie", 0.6}};
        auto min_balances = compute_min_balances(expenses);

        auto [balance, ok] = find_account_balance(min_balances, "Alice");
        REQUIRE(ok);
        CHECK(balance == doctest::Approx{3.433333333333});
        std::tie(balance, ok) = find_account_balance(min_balances, "Bob");
        REQUIRE(ok);
        CHECK(balance == doctest::Approx{0.0});
        std::tie(balance, ok) = find_account_balance(min_balances, "Charlie");
        REQUIRE(ok);
        CHECK(balance == doctest::Approx{3.1});
    }
}
