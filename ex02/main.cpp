#include <iostream>
#include <cassert>
#include "MutantStack.h"

void test_iterator() {
    std::cout << "=================== [ test_iterator ] ===================" << std::endl;

    MutantStack<int> nbrs;

    nbrs.push(10);
    nbrs.push(1337);
    nbrs.push(42);
    nbrs.push(24);

    MutantStack<int>::iterator it = nbrs.begin();
    for (; it != nbrs.end(); it++) {
        std::cout << "- " << *it << std::endl;
    }
}

void test_const_iterator() {
    std::cout << "================ [ test_const_iterator ] ================" << std::endl;
    MutantStack<int> nbrs;

    nbrs.push(10);
    nbrs.push(1337);
    nbrs.push(42);
    nbrs.push(24);

    const MutantStack<int> const_nbrs(nbrs);
    MutantStack<int>::const_iterator it = const_nbrs.begin();
    for (; it != const_nbrs.end(); it++) {
        std::cout << "- " << *it << std::endl;
    }
}

void test_reverse_iterator() {
    std::cout << "=============== [ test_reverse_iterator ] ===============" << std::endl;
    MutantStack<int> nbrs;

    nbrs.push(10);
    nbrs.push(1337);
    nbrs.push(42);
    nbrs.push(24);

    MutantStack<int>::reverse_iterator it = nbrs.rbegin();
    for (; it != nbrs.rend(); it++) {
        std::cout << "- " << *it << std::endl;
    }
}

int main() {
    test_iterator();
    test_const_iterator();
    test_reverse_iterator();
}
