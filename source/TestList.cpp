#define CATCH_CONFIG_RUNNER
#include "List.hpp"
#include <catch.hpp>
#include <iostream>
#include <vector>

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

//Aufgabe 4.6

TEST_CASE("should be an empty range after default construction", "[iterators]")
{
    List<int> list;
    auto b = list.begin();
    auto e = list.end();
    REQUIRE(b == e);
}
TEST_CASE("provide access to the first element with begin", "[iterators]") {
    List<int> list;
    list.push_front(42);
    REQUIRE(42 == *list.begin());
}


TEST_CASE("copy constructor", "[constructor]") {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int> list2{list};
    REQUIRE(list == list2);
}

//Aufgabe 4.9 Test
// TEST_CASE("inster", "[insert]") {
//     List<int> list;
//     ListIterator<int> it;
//     list.push_front(1);
//     list.push_front(2);
//     list.push_front(3);
//     list.push_front(4);
//     auto i = list.begin();
//     list.insert(i, 5);
//     REQUIRE(list.front() == 5);
// }

//Aufgabe 4.10 Test

TEST_CASE("reverse", "[list_reverse]") {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.reverse();
    REQUIRE(list.front() == 1);
    List<int> list2 = reverse(list);
    REQUIRE(list2.front() == 4);

}

//Aufgabe 4.11 

TEST_CASE("std_copy, list", "[copy]") {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    std::vector<int> vector(list.size());
    std::copy(list.begin(), list.end(), vector.begin());
    REQUIRE(4 == *vector.begin());
}

//Aufgabe 4.12

TEST_CASE("assign operator", "[assign]") {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int> list2;
    list2.push_front(10);
    list2.push_front(8);
    list = list2;    
    REQUIRE(8 == *list.begin());
}







int main(int argc, char *argv[]) {
    return Catch::Session().run(argc, argv);
}