#include <iostream>

#include "Factory.hpp"
#include "Impl1.hpp"
#include "Impl2.hpp"

int main(int argc, char *argv[])
{
    std::cout << "START\n";

    Factory<std::string, Counter, const size_t&>::Instance().PrintClasses();

    auto ctr1 = Factory<std::string, Counter, const size_t&>::Instance().Create("FirstImpl", 10);

    auto ctr2 = Factory<std::string, Counter, const size_t&>::Instance().Create("SecondImpl", 5);

    std::cout << ctr1->size("Test") << "\n";
    std::cout << ctr2->size("Test") << "\n";

    std::cout << "END\n";
}