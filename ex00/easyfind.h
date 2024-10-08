#pragma once

#include <iterator>
#include <iostream>

template<typename Tp>
typename Tp::iterator easyfind(Tp &c, int v) {
    typename Tp::iterator it;
    for (it = c.begin(); it != c.end(); it++) {
        if (*it == v)
            return it;
    }
    return c.end();
}

template<typename Tp>
typename Tp::const_iterator easyfind(const Tp &c, int v) {
    typename Tp::const_iterator it;
    for (it = c.begin(); it != c.end(); it++) {
        if (*it == v) {
            return it;
        }
    }
    return c.end();
}
