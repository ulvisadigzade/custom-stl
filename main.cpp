#include <bits/stdc++.h>

#include "Vector.hpp"

using namespace std;

int main() {

    try {
        Vector a;

        std::cout<<a.back();
    }
    catch (const std::runtime_error& e) {
        std::cout<<"Error: "<<e.what();
    }
}
