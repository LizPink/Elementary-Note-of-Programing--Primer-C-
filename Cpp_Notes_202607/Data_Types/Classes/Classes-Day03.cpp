/* Day03 */
// 构造函数
#include <iostream>
// Exer1
class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle();
    Rectangle(double width, double height);

    double area();
};

Rectangle::Rectangle():
    width(1.0),
    height(1.0)
    {}
Rectangle::Rectangle(double width, double height):
    width(width),
    height(height)
    {}
double Rectangle::area(){
    return width * height;
}


int main() {
    std::cout << "Exercise1----------:" << std::endl;

    Rectangle a;
    Rectangle b{3.0, 4.0};

    std::cout << a.area() << std::endl;
    std::cout << b.area() << std::endl;

    return 0;
}