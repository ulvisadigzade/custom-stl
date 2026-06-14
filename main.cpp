#include <bits/stdc++.h>

#include "Vector.hpp"

using namespace std;

int main() {
    Vector a;

    for (int i=1;i<=5;i++) {
        a.push_back(i);
    }

    a.assign(200,4);

    for (auto &i:a) {
        cout<<i<<" ";
    }

}
