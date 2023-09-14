#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <memory>

template <class TKey, class TBase, class... TParam>
class Factory
{

public:

    typedef TBase* TBasePtr;

    Factory(Factory &rhs) = delete;
    void operator=(const Factory &rhs) = delete;

    static Factory &Instance()
    {
        static Factory m_instance;
        return m_instance;
    }

    TBasePtr Create(const TKey &key, TParam... args)
    {
        if (m_map.find(key) != m_map.end())
            return m_map[key](args...);
        else
            return nullptr;
    }

    bool Register(const TKey &key, const std::function<TBasePtr(TParam...)> &val)
    {
        if (m_map.find(key) == m_map.end())
        {
            m_map[key] = val;
            return true;
        }
        else
            return false;
    }

    void PrintClasses()
    {
        std::string msg = "Available classes = [ ";
        for (auto it = m_map.begin(); it != m_map.end(); ++it)
        {
            if (it != m_map.begin())
                msg += ", ";
            msg += it->first;
        }
        msg += " ]";
        std::cout << msg << "\n";
    }

protected:
    Factory()
    {
        std::cout << "Factory ctor\n";
    }

    static Factory m_instance;

    std::unordered_map<TKey, std::function<TBasePtr(TParam...)>> m_map;
};