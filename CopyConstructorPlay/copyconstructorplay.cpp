// Example making objects uncopyable

#include <iostream>

class Widget {
private:
    int data;

    // Option #1 to prevent copying: Make the copy constructor private 
    //Widget(const Widget& other) : Widget(other.data) {}

public:
    Widget(int data) : data(data) {}

    // Normal copy constructor
    Widget(const Widget& other) : Widget(other.data) {}

    // Option #2 to prevent copying: Make the copy constructor "deleted" 
    //Widget(const Widget& other) = delete;

    int get() const {
        return data;
    }
};

int main() {
    Widget w1{2};
    std::cout << w1.get() << '\n';
    // Replace the normal copy constructor with one of the options above to make
    // the copy construction of w2 illegal
    Widget w2{ w1 };
    std::cout << w2.get() << '\n';
}