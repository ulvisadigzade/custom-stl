#include <bits/stdc++.h>

#include "Vector.hpp"

int main() {
    Vector a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(1);

    std::sort(a.rbegin(), a.rend());

    for (auto &i:a)std::cout<<i<<" ";
}
