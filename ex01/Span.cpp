#include "Span.h"
#include <climits>

Span::Span(unsigned int size) : _size(size), _count(0), _shortest_span(INT_MAX)
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
        _shortest_span = other._shortest_span;
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
    std::multiset<int>::iterator it = _c.insert(nbr);
    if (it != _c.begin()) {
        std::multiset<int>::iterator prev_it = it; prev_it--;
        int tmp = *it - *prev_it;
        if (tmp < _shortest_span) _shortest_span = tmp;
    }
    if (it != --_c.end()) {
        std::multiset<int>::iterator next_it = it; next_it++;
        int tmp = *next_it - *it;
        if (tmp < _shortest_span) _shortest_span = tmp;
    }
}

unsigned int Span::shortestSpan() {
    if (_count < 2)
        throw Span::NoSpanException();
    return _shortest_span;
}

unsigned int Span::longestSpan() {
    if (_count < 2)
        throw Span::NoSpanException();
    return *(_c.rbegin()) - *_c.begin();
}
