// WidgetPlay.cpp
// Created 10/25/2021 7:02:32 PM

#include <iostream>

class Widget {
    int data;
    static int sn_source;
    int serial_number;
public:
    Widget(int data) : data(data), serial_number(++sn_source) {
        std::cout << "Creating widget #" << serial_number << '\n';
    }

    Widget(const Widget& other) : Widget(other.data) {}


    //Widget(Widget&& other) noexcept : Widget(other.data) {}

    Widget& operator=(const Widget& other) {
        std::cout << "Calling assignment operator" << '\n';
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }
    
    Widget& operator=(Widget&& other) noexcept {
        std::cout << "Calling move assignment operator" << '\n';
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }
    
    ~Widget() {
        std::cout << "Destroying widget #" << serial_number << '\n';
    }

    int get_data() const {
        return data;
    }

};

Widget make_widget(int n) {
    return Widget{ n };
}

int Widget::sn_source = 0;


int main() {
    Widget w1{ 45 }, w2{ 100 };
    std::cout << "w1: " << w1.get_data() << '\n';
    w1 = w2;
    std::cout << "w1: " << w1.get_data() << '\n';
    w1 = make_widget(250);
    std::cout << "w1: " << w1.get_data() << '\n';
}
