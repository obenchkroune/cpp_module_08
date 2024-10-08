#include "Span.h"
#include <iostream>
#include <vector>
#include <cassert>

void basic_test() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    assert(sp.shortestSpan() == 2);
    assert(sp.longestSpan() == 14);

    std::cout << "=> basic test Passed!" << std::endl;
}

void test_range_insertion() {
    int nbrs[5] = {6, 3, 17, 9, 11};
    Span sp0(nbrs, nbrs + 5);

    assert(sp0.shortestSpan() == 2);
    assert(sp0.longestSpan() == 14);

    std::vector<int> vec(nbrs, nbrs + 5);
    Span sp1(vec.begin(), vec.end());
    
    assert(sp1.shortestSpan() == 2);
    assert(sp1.longestSpan() == 14);

    std::cout << "=> range insertion tests Passed!" << std::endl;
}

void test_large_input() {
    int N = 100000;
    Span sp(N);
    for (int i = 0; i < N; i++) {
        sp.addNumber(i);
    }
    assert(sp.longestSpan() == N - 1);
    assert(sp.shortestSpan() == 1);
    std::cout << "=> large input tests Passed!" << std::endl;
}

int main() {
    basic_test();
    test_range_insertion();
    test_large_input();
}
