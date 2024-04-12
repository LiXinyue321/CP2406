// AssociativeArray.h
#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>

template <typename T>
class AssociativeArray {
public:
    virtual ~AssociativeArray() = default;

    T& operator[](const std::string& key);
    const T& operator[](const std::string& key) const;

private:
    class Element {
    public:
        Element(std::string key, T value)
            : m_key{std::move(key)}, m_value{std::move(value)} {}
        std::string m_key;
        T m_value;
    };

    std::vector<Element> m_data;
};

// AssociativeArray.cpp
#include "AssociativeArray.h"

template <typename T>
T& AssociativeArray<T>::operator[](const std::string& key) {
    for (auto& element : m_data) {
        if (element.m_key == key) {
            return element.m_value;
        }
    }
    m_data.emplace_back(key, T{});
    return m_data.back().m_value;
}

template <typename T>
const T& AssociativeArray<T>::operator[](const std::string& key) const {
    for (auto& element : m_data) {
        if (element.m_key == key) {
            return element.m_value;
        }
    }
    std::ostringstream os;
    os << "Key '" << key << "' doesn't exist.";
    throw std::invalid_argument(os.str());
}

// Ensure template methods are instantiated
template class AssociativeArray<int>; // Example instantiation for int
