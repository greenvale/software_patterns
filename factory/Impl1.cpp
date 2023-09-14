#include "Factory.hpp"
#include "Impl1.hpp"

bool CounterImpl1::m_reg = Factory<std::string, Counter, const size_t&>::Instance().Register(
    "FirstImpl",
    [](const size_t& n)
    {
        return CounterImpl1::create(n);
    }
);