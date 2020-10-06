#include "Array.h"

#include <bits/stdc++.h>
using namespace std;

Array::Array(size_t count, int value = 0) {
    m_list = new int[count * sizeof(int)];
    for (int i = 0; i < count; i++) *(m_list + i) = value;
}
Array::Array(const Array& other) {
    int count = other.m_size;
    m_list = new int[count * sizeof(int)];
    for (int i = 0; i < count; i++) *(m_list + i) = other.at(i);
}
int& Array::at(std::size_t pos) {
    for (int i = 0; i < pos && i < m_size; i++)
        if (i == pos) return *(m_list + i);
}
const int& Array::at(std::size_t pos) const {
    for (int i = 0; i < pos && i < m_size; i++)
        if (i == pos) {
            const int& v = *(m_list + i);
            return v;
        };
}
