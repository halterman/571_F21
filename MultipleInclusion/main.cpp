#include <iostream>
#include "widget.h"
#include "widgetholder.h"

/*
 * Simple example showing how include guards
 * prevent multiple inclusion
 */

struct Steal {
    int data;
};

int main() {
    Widget w{ 42 };
    //std::cout << w.get() << '\n';
    //Steal *addr = reinterpret_cast<Steal *>(&w);
    //addr->data = 10;
    //std::cout << w.get() << '\n';
    
    WidgetHolder wid_box{ 100 };

    std::cout << "w        : " << w.get() << '\n';
    std::cout << "wid_user : " << wid_box.get() << '\n';
}