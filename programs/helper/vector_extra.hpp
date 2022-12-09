#ifndef VECTOR_EXTRA_HPP
#define VECTOR_EXTRA_HPP

#include "vector_extra.cpp"

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n);

template<typename T>
bool contains(std::vector<T> const &v, T key);

#endif

