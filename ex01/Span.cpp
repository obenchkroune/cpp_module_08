#include "Span.h"
#include <algorithm>
#include <limits>

Span::Span(std::size_t size) : _size(size), _count(0)
{
}

Span::Span(const Span &other)
{
    *this = other;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _c = other._c;
        _count = other._count;
        _size = other._size;
    }
    return *this;
}

const char *Span::OutOfRangeException::what() const throw() {
    return "the span is full";
}

const char *Span::NoSpanException::what() const throw() {
    return "no span can be found";
}

void Span::addNumber(int nbr) {
    if (_count >= _size)
        throw Span::OutOfRangeException();
    _count++;
    _c.push_back(nbr);
}

int Span::shortestSpan() const
{
    if (_count < 2)
        throw Span::NoSpanException();
    std::vector<int> temp(_c);
    std::sort(temp.begin(), temp.end());
    int result = std::numeric_limits<int>::max();
    for (std::size_t i = 0; i < temp.size() - 1; i++) {
        if (temp[i + 1] - temp[i] < result)
            result = temp[i + 1] - temp[i];
    }
    return result;
}

int Span::longestSpan() const
{
    if (_count < 2)
        throw Span::NoSpanException();
    int min = *std::min_element(_c.begin(), _c.end());
    int max = *std::max_element(_c.begin(), _c.end());
    return max - min;
}
