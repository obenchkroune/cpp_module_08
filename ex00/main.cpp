#include "easyfind.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void) {
    int values[5] = {10, 1337, 42, 0, -10};

    std::cout << "=> Testing with vector\n";
    std::vector<int> nbrs_vec(values, values + 5);

    easyfind(nbrs_vec, 10);
    easyfind(nbrs_vec, 1337);
    easyfind(nbrs_vec, -10);
    easyfind(nbrs_vec, 11);

    std::cout << "=> Testing with const vector\n";
    const std::vector<int> const_nbrs_vec(values, values + 5);

    easyfind(const_nbrs_vec, 10);
    easyfind(const_nbrs_vec, 1337);
    easyfind(const_nbrs_vec, -10);
    easyfind(const_nbrs_vec, 11);

    std::cout << "=> Testing with list\n";
    std::list<int> nbrs_lst(values, values + 5);
    easyfind(const_nbrs_vec, 10);
    easyfind(const_nbrs_vec, 1337);
    easyfind(const_nbrs_vec, -10);
    easyfind(const_nbrs_vec, 11);

    std::cout << "=> testing with double ended queue\n";
    std::deque<int> nbrs_deque(values, values + 5);
    easyfind(const_nbrs_vec, 10);
    easyfind(const_nbrs_vec, 1337);
    easyfind(const_nbrs_vec, -10);
    easyfind(const_nbrs_vec, 11);

    return 0;
}
