/* Day08:类的拷贝 */
#include <iostream>

// 复制构造函数
class Student1 {
private:
    int age;

public:
    explicit Student1(int age)
    : age(age)
    {}

    Student1(const Student1& other)
    : age(other.age)
    {
        std::cout << "Call Copy Constructor\n";
        std::cout << "this: " << this << "\n";
        std::cout << "other: " << &other << "\n";
    }
};

// 复制运算符
class Student2 {
private:
    int age;
public:
    Student2& operator=(const Student2& other) {
        age = other.age;
        return *this;
    }
};

// 浅拷贝
class Buffer {
private:
    int* data;

public:
    explicit Buffer(int value)
    : data(new int(value))
    {
        std::cout << "constructor: " << data << std::endl;
    }


    ~Buffer()
    {
        std::cout << "destructor: " << data << std::endl;
        delete data;
    }

    void set_value(int value)
    {
        *data = value;
    }

    int get_value() const
    {
        return *data;
    }

    const int* get_address() const
    {
        return data;
    }
};


// 深拷贝



int main()
{
    std::cout << "复制构造函数..." << std::endl;
    Student1 first1{20};
    Student1 second1 = first1;

    std::cout << "浅拷贝..." << std::endl;
    Buffer first2{10};
    Buffer second2 = first2;


    return 0;
}


