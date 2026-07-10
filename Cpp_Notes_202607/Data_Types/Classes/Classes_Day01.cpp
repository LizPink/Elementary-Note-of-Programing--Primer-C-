/* 类与对象 */
// Day1: 类、对象、成员
#include<cmath>
#include<string>
#include<iostream>

class Student{
private:
    // 私有数据成员只能通过类内部函数访问
    std::string name;
    int age;

public:
    // 公开数据成员可以在任意访问
    void set_info(std::string new_name, int new_age) {
        name = new_name;
        age = new_age;
    }

    void introduce() {
        std::cout << name << "," << age << "\n";
    }
};

class Rectangle {
private:
    double width;
    double height;

public:
    void set_size(double new_width, double new_height);
    double area();
};

void Rectangle::set_size(double new_width, double new_height){
    width = new_width;
    height = new_height;
}

double Rectangle::area(){
    return width*height;
}

class Circle{
private:
    static constexpr double pi = 3.1415926;
private:
    double radius = 0;

public:
    void set_radius(double new_radius);
    double get_radius(){
        return radius;
    }
    double area(){
        return pi*std::pow(radius,2);
    }
};


int main(){
    Student s1;
    s1.set_info("Alice", 20);
    s1.introduce();

    Rectangle r1;
    r1.set_size(3,5);
    std::cout << "The area is " << r1.area() << std::endl;

    std::cout << std::pow(2,4);
}