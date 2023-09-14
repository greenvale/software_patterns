#pragma once

#include "Base.hpp"

class CounterImpl2 : public Counter
{

public:

    CounterImpl2() : Counter()
    {
    }

    CounterImpl2(const size_t& n) : Counter(n)
    {
    }

    size_t size(const std::string &str)
    {
        return str.size() + this->m_base;
    }

    static CounterImpl2* create(const size_t &n)
    {
        return new CounterImpl2(n);
    }

protected:
    static bool m_reg;
};