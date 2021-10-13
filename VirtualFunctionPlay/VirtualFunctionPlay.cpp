// VirtualFunctionPlay.cpp
// Created 9/13/2021 6:02:57 PM

#include <iostream>
#include <vector>
#include <algorithm>

class Rectangle {
protected:
    int length;
    int width;
public:
    Rectangle(int len, int wid) : length(len), width(wid) {}
    virtual int area() const;
    virtual void lengthen(int amt);
    int get_length() const {
        return length;
    }
    int get_width() const {
        return width;
    }
    virtual void show() const {
        std::cout << "<<" << length << ", " << width << ">>" << '\n';
    }
};

int Rectangle::area() const {
    return length * width;
}

void Rectangle::lengthen(int amt) {
    length += amt;
}

class Cuboid : public Rectangle{
protected:
    int height;
public:
    Cuboid(int len, int wid, int ht) : Rectangle(len, wid), height(ht) {}
    void lengthen(int amt) override;
    void show() const override {
        std::cout << "^^" << length << ", " << width << ", "
                  << height << "^^" << '\n';
    }
};

void Cuboid::lengthen(int amt) {
    length += 2 * amt;
}

void f(Rectangle rect) {
    std::cout << rect.get_length() << '\n';
}

int main() {
    Rectangle *r = new Rectangle{10, 20};
    Rectangle *c = new Cuboid{11, 21, 31};

    r->show();
    c->show();

    r->lengthen(5);
    c->lengthen(5);

    //r->show();
    //c->show();

    std::cout << "-----------------------------\n";

    Rectangle r1(100, 200);
    Cuboid c1(101, 201, 301);

    r1.show();
    c1.show();

    r1.lengthen(5);
    c1.lengthen(5);

    r1.show();
    c1.show();

    std::cout << "-----------------------------\n";

    f(r1);
    f(c1);


    std::cout << "=============================\n";

    std::vector<Rectangle> rects;
    rects.push_back(r1);  // 100
    rects.push_back(c1);  // 101
    rects.push_back(r1);  // 100
    rects.push_back(*r);  // 10
    rects.push_back(*c);  // 11

    std::for_each(rects.begin(), rects.end(),
                  [](Rectangle r) { r.show(); });
    std::cout << '\n';

    std::cout << "-----------------------------\n";

    std::vector<Rectangle *> rect_ptrs;
    rect_ptrs.push_back(&r1);  // 100
    rect_ptrs.push_back(&c1);  // 101
    rect_ptrs.push_back(&r1);  // 100
    rect_ptrs.push_back(r);  // 10
    rect_ptrs.push_back(c);  // 11

    std::for_each(rect_ptrs.begin(), rect_ptrs.end(),
                  [](Rectangle *r) { r->show(); });
    std::cout << '\n';



}
