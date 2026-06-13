#include <bits/stdc++.h>

#include "Vector.hpp"

int main() {
    const Vector a(3,4);

    std::cout<<a[0]<<" ";

    for (auto &i:a) {
        std::cout<<i<<" ";
    }
    std::cout<<a.size();
    int* z = a.begin();
    z[0] = 234;

}
