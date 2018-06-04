#define CATCH_CONFIG_RUNNER
#include "List.hpp"
#include <catch.hpp>
#include <iostream>

// 4.2
TEST_CASE("testing list methods", "[list]") {
    List<int> l1;
    REQUIRE(l1.size() == 0);
    REQUIRE(l1.empty() == true);
}

int main(int argc, char *argv[]) {
    return Catch::Session().run(argc, argv);
}