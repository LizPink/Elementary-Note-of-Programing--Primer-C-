/* Day10:智能指针 */
#include<iostream>
#include<memory>

// Exercise1
class Student {
private:
    int age;
public:
    explicit Student(int age)
    : age(age)
    {
        std::cout << "Call Student constructor\n";
    }

    ~Student()
    {
        std::cout << "Student destruction\n";
    }

    void print() const
    {
        std::cout << age << std::endl;
    }
};

// Exercise2
auto p = std::make_unique<int>(10);

// Exercise3
class Buffer {
private:
    std::unique_ptr<int> data;

public:
    explicit Buffer(int value)
    : data(std::make_unique<int>(value))
    {}

    Buffer(const Buffer& other)
    : data(other.data ? std::make_unique<int>(*other.data) : nullptr)
    {}

    Buffer& operator=(const Buffer& other)
    {
        if(this == &other)
        {
            return *this;
        }

        data = other.data? std::make_unique<int>(*other.data): nullptr;
        return *this;
    }

    Buffer(Buffer&&) noexcept = default;
    Buffer& operator=(Buffer&&) noexcept = default;
};


// Exercise4: shared pointer
auto first = std::make_shared<Student>(20);

int main()
{   
    std::cout << "Task1..." << std::endl;
    auto student = std::make_unique<Student>(20);
    student -> print();

    std::cout << "Task2..." << std::endl;
    std::cout << p.get() << "\n" << *p << "\n";
    p.reset();
    std::cout << p.get() << "\n";
    p = std::make_unique<int>(25);
    int* p1 = p.release();
    std::cout << "p1 is: " << *(p1) << "\n" << "p is: " << p.get() << "\n";

    std::cout << "Task4..." << std::endl;
    std::cout << first << "\n" << "the pointing location is: " << first.get() << std::endl;




    return 0;
}