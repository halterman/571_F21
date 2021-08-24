// AddressOfReference.cpp
// Created 8/23/2021 11:10:24 PM

#include <iostream>

int main() {
    int x = 5;
    int& r = x;

    std::cout << "x = " << x << ", r = " << r << '\n';
    std::cout << "address of x is " << &x << ", address of r is " << &r << '\n';
}
