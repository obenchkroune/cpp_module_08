#pragma once

#include <iterator>
#include <iostream>
#include <algorithm>

template<typename Tp>
typename Tp::iterator easyfind(Tp &c, int v) {
    typename Tp::iterator it;
    return std::find(c.begin(), c.end(), v);
}

template<typename Tp>
typename Tp::const_iterator easyfind(const Tp &c, int v) {
    typename Tp::const_iterator it;
    return std::find(c.begin(), c.end(), v);
}
