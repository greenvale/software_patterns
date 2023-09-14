#pragma once

#include <string>

class Counter
{

public:

    Counter()
    {
    }

    Counter(const size_t& n)
    {
        m_base = n;
    }

    virtual size_t size(const std::string &str) = 0;

protected:
    size_t m_base;
};