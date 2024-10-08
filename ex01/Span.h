#pragma once

#include <exception>
#include <iterator>
#include <vector>

class Span {
public:
    Span(std::size_t size);
    template<typename InputIterator>
    Span(InputIterator begin, InputIterator end);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void    addNumber(int nbr);
    int     shortestSpan() const;
    int     longestSpan() const;

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
    std::size_t         _size;
    std::size_t         _count;
    std::vector<int>    _c;
};

template<typename InputIterator>
Span::Span(InputIterator begin, InputIterator end) : _size(end - begin), _count(0)
{
    for (InputIterator it = begin; it != end; it++) {
        this->addNumber(*it);
    }
}
