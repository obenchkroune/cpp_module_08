#pragma once

#include <iterator>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &c, int v) {
    typename T::iterator it;
    for (it = c.begin(); it != c.end(); it++) {
        if (*it == v)
            return it;
    }
    return c.end();
}

template<typename T>
typename T::const_iterator easyfind(const T &c, int v) {
    typename T::const_iterator it;
    for (it = c.begin(); it != c.end(); it++) {
        if (*it == v) {
            std::cout << "value " << *it << " found!" << std::endl;
            return it;
        }
    }
    std::cout << "value " << *it << " not found!" << std::endl;
    return c.end();
}
