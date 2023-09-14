#include "Factory.hpp"
#include "Impl2.hpp"

bool CounterImpl2::m_reg = Factory<std::string, Counter, const size_t&>::Instance().Register(
    "SecondImpl",
    [](const size_t& n)
    {
        return CounterImpl2::create(n);
    }
);