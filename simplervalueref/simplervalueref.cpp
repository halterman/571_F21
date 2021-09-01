// simplervalueref.cpp
// Created 8/31/2021 11:01:58 AM

#include <iostream>

//int twice(int n) {
//    std::cout << "Calling twice with value\n";
//    return 2 * n;
//}

int twice(int& n) {
    std::cout << "Calling twice with reference\n";
    return 2 * n;
}

int twice(int&& n) {
    std::cout << "Calling twice with rvalue reference\n";
    return 2 * n;
}

int main() {
    int x = 6;
    std::cout << twice(x) << '\n';
    std::cout << twice(x + 2) << '\n';
    std::cout << twice(6) << '\n';
}