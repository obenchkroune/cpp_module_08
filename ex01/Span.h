#pragma once

#include <exception>
#include <set>
#include <iterator>

class Span {
public:
    Span(unsigned int size);
    template<typename InputIterator>
    Span(InputIterator begin, InputIterator end);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void            addNumber(int nbr);
    unsigned int    shortestSpan();
    unsigned int    longestSpan();

    // Exceptions
    class OutOfRangeException : public std::exception {
    public:
        const char *what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        const char *what() const throw();
    };

private:
    unsigned int        _size;
    unsigned int        _count;
    std::multiset<int>  _c;
    int                 _shortest_span;
};

template<typename InputIterator>
Span::Span(InputIterator begin, InputIterator end)
{
    for (InputIterator it = begin; it != end; it++) {
        this->addNumber(*it);
    }
}
