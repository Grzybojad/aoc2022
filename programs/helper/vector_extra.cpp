#include <iostream>
#include <vector>

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n)
{
    std::vector<T> vec(n - m + 1);
    std::copy(v.begin() + m, v.begin() + n + 1, vec.begin());
    return vec;
}

template<typename T>
bool contains(std::vector<T> const &v, T key) {
    return std::count(v.begin(), v.end(), key);
}