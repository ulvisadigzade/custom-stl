#include <bits/stdc++.h>

#include "Vector.hpp"

int main() {
    Vector a,b;

    for (int i=0;i<10;i++) {
        a.push_back(i);
        b.push_back(i);
    }

    if (a==b) {
        std::cout<<"a==b"<<std::endl;
    }
    Vector& c = b;

    if (c == b) {
        std::cout<<"c==b"<<std::endl;
    }

    for (auto &i:a)std::cout<<i<<" ";
}
