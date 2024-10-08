#pragma once

#include <stack>

template<typename Tp>
class MutantStack : public std::stack<Tp>
{
public:
    MutantStack() : std::stack<Tp>() {}
    MutantStack(const MutantStack &other) : std::stack<Tp>(other) {}
    MutantStack &operator=(const MutantStack &other)
    {
        return std::stack<Tp>::operator=(other);
    }
    ~MutantStack() {}

    typedef typename std::stack<Tp>::container_type::iterator iterator;
    typedef typename std::stack<Tp>::container_type::reverse_iterator reverse_iterator;

    typedef typename std::stack<Tp>::container_type::const_iterator const_iterator;
    typedef typename std::stack<Tp>::container_type::const_reverse_iterator const_reverse_iterator;

    typename MutantStack<Tp>::iterator begin() { return this->c.begin(); }
    typename MutantStack<Tp>::iterator end() { return this->c.end(); }
    typename MutantStack<Tp>::reverse_iterator rbegin() { return this->c.rbegin(); }
    typename MutantStack<Tp>::reverse_iterator rend() { return this->c.rend(); }

    typename MutantStack<Tp>::const_iterator begin() const { return this->c.begin(); }
    typename MutantStack<Tp>::const_iterator end() const { return this->c.end(); }
    typename MutantStack<Tp>::const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    typename MutantStack<Tp>::const_reverse_iterator rend() const { return this->c.rend(); }

};
