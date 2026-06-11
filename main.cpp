#include <iostream>

#include "Vector.hpp"

int main() {
    Vector v;
    v.reserve(1000);
    for (int i=1;i<=10;i++)v.push_back(i);

    std::cout<<v.capacity()<<" "<<v.size()<<"\n";

    v.shrink_to_fit();

    std::cout<<v.capacity()<<" "<<v.size()<<"\n";

    /*
    for (int i=0;i<n;i++)v[i] = i*2;

    for (int i=n-1;i>=0;i--)std::cout<<v[i]<<" ";
    */
}
