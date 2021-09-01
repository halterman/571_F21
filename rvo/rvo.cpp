// rvo.cpp
// Created 8/31/2021 11:43:57 AM

// Note different behavior with "Debug" build
// vs. "Release" build

#include <iostream>

using std::cout;

struct Widget {
    Widget() {
        cout << "Default ctor" << '\n';
    }
    Widget(const Widget&) {
        cout << "Copy ctor" << '\n';
    }
};

Widget make_widget() {
    Widget w;
    return w;
}

int main() {
    cout << "Program begin" << '\n';
    Widget wid = make_widget();
    cout << "Program end" << '\n';
}
