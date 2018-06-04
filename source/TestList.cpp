#define CATCH_CONFIG_RUNNER
#include "List.hpp"
#include <catch.hpp>
#include <iostream>


// Default Constructor
List();
// http://en.cppreference.com/w/cpp/container/list/empty

bool empty() const;
// http://en.cppreference.com/w/cpp/container/list/size

std::size_t size() const;

int main() {
    return 0;
}