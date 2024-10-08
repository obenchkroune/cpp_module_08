#include <iostream>
#include <cassert>
#include "MutantStack.h"
#include <list>

void test_basic() {
    std::cout << "===================== [ test_basic ] ====================" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;
        
        mstack.pop();

        std::cout << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "<<<=====" << std::endl;


    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);

        std::cout << mstack.back() << std::endl;
        
        mstack.pop_back();

        std::cout << mstack.size() << std::endl;
        
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    }
}

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
    test_basic();
    test_iterator();
    test_const_iterator();
    test_reverse_iterator();
}
