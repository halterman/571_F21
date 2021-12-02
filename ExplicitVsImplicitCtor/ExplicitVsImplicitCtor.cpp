// ExplicitVsImplicitCtor.cpp
// Created 11/1/2021 6:26:02 PM

#include <iostream>

class Widget {
    int data;
public:
    explicit Widget(int n) : data(n) {}
    int get() const {
        return data;
    }
};

int main() {
    Widget w1{ 4 };
    Widget w2 = 25.0;
    std::cout << "w1: " << w1.get() << "   w2: " << w2.get() << '\n';
    
}
