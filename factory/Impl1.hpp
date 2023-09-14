#pragma once

#include "Base.hpp"

class CounterImpl1 : public Counter
{

public:

    CounterImpl1() : Counter()
    {
    }

    CounterImpl1(const size_t &n) : Counter(n)
    {
    }

    size_t size(const std::string &str)
    {
        size_t n = 0;
        for (size_t i = 0; i < str.length(); ++i)
        {
            n++;
        }
        return n + this->m_base;
    }

    static CounterImpl1* create(const size_t &n)
    {
        return new CounterImpl1(n);
    }

protected:
    static bool m_reg;
};