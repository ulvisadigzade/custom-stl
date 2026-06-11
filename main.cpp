#include <iostream>

#include "Vector.hpp"

int main() {
    int n;
    std::cin>>n;


    Vector v;
    v.push_back(12);
    v.push_back(13);


    std::cout<<v.back()<<"\n";
    v.pop_back();
    std::cout<<v.back()<<"\n";

    /*
    for (int i=0;i<n;i++)v[i] = i*2;

    for (int i=n-1;i>=0;i--)std::cout<<v[i]<<" ";
    */
}
