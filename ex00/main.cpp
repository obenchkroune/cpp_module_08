#include "easyfind.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cassert>

void test_vector() {
    int values[5] = {10, 1337, 42, 0, -10};
    std::vector<int> nbrs_vec(values, values + 5);
    assert(easyfind(nbrs_vec, 10) != nbrs_vec.end());
    assert(easyfind(nbrs_vec, 1337) != nbrs_vec.end());
    assert(easyfind(nbrs_vec, -10) != nbrs_vec.end());
    assert(easyfind(nbrs_vec, 11) == nbrs_vec.end());
    std::cout << "=> Testing with vector passed!\n";
}

void test_const_vector() {
    int values[5] = {10, 1337, 42, 0, -10};
    const std::vector<int> nbrs_vec(values, values + 5);
    assert(easyfind(nbrs_vec, 10) != nbrs_vec.end());
    assert(easyfind(nbrs_vec, 1337) != nbrs_vec.end());
    assert(easyfind(nbrs_vec, -10) != nbrs_vec.end());
    assert(easyfind(nbrs_vec, 11) == nbrs_vec.end());
    std::cout << "=> Testing with const vector passed!\n";
}

void test_list() {
    int values[5] = {10, 1337, 42, 0, -10};
    const std::list<int> nbrs_list(values, values + 5);
    assert(easyfind(nbrs_list, 10) != nbrs_list.end());
    assert(easyfind(nbrs_list, 1337) != nbrs_list.end());
    assert(easyfind(nbrs_list, -10) != nbrs_list.end());
    assert(easyfind(nbrs_list, 11) == nbrs_list.end());
    std::cout << "=> Testing with list passed!\n";
}

void test_deque() {
    int values[5] = {10, 1337, 42, 0, -10};
    const std::list<int> nbrs_list(values, values + 5);
    assert(easyfind(nbrs_list, 10) != nbrs_list.end());
    assert(easyfind(nbrs_list, 1337) != nbrs_list.end());
    assert(easyfind(nbrs_list, -10) != nbrs_list.end());
    assert(easyfind(nbrs_list, 11) == nbrs_list.end());
    std::cout << "=> Testing with double ended queue passed!\n";
}

int main(void) {
    test_vector();
    test_const_vector();
    test_list();
    test_deque();
    return 0;
}
