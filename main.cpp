#include <bits/stdc++.h>

#include "Vector.hpp"

using namespace std;

int main() {

    try {
        Vector<std::string>v(3,"3");
        Vector<std::string>& z = v;

        z[0] = "1";

        for (auto &i:v)cout<<i<<" ";
        cout<<"\n";
        for (auto &i:z)cout<<i<<" ";
    }
    catch (const std::runtime_error& e) {
        std::cout<<"Error: "<<e.what();
    }
}
