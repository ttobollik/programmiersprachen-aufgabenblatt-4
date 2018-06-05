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

// 4.3 
TEST_CASE("add an element with push_front", "[modifiers]") {
    List<int> list;
    list.push_front(42);
    REQUIRE(42 == list.front());
}

TEST_CASE("add an element with push_back", "[modifiers]") {
    List<int> list;
    list.push_back(42);
    REQUIRE(42 == list.back());
}

TEST_CASE("delete element-front", "[modifiers]") {
    List<int> list;
    list.push_back(42);
    list.pop_front();
    REQUIRE(list.empty() == true);
}

TEST_CASE("delete element-front2", "[modifiers]") {
    List<int> list;
    list.push_front(42);
    list.push_front(30);
    list.push_front(20);
    list.pop_front();
    REQUIRE(list.front() == 30);
}

TEST_CASE("delete element-back", "[modifiers]") {
    List<int> list;
    list.push_back(42);
    list.pop_back();
    REQUIRE(list.empty() == true);
}

TEST_CASE("delete element-back2", "[modifiers]") {
    List<int> list;
    list.push_front(42);
    list.push_front(25);
    list.push_front(20);
    list.pop_back();
    REQUIRE(list.back() == 25);
}

//Aufgabe 4.4
TEST_CASE("clear list", "[modifiers]") {
    List<int> list;
    list.push_front(42);
    list.push_front(25);
    list.push_front(20);
    list.clear();
    REQUIRE(list.empty() == true);
}


int main(int argc, char *argv[]) {
    return Catch::Session().run(argc, argv);
}