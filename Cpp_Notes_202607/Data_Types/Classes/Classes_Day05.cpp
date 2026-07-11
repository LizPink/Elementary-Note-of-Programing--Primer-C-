/* Day05:封装与const */
#include <iostream>

// exercise1
class Student {
private:
    int age;

public:
    Student(int age):
        age(age)
    {}

    int get_age() const
    {
        return age;
    }
    void set_age(int new_age)
    {
        age = new_age;
    }
};


int main()
{
    std::cout << "Task1..." << std::endl;

    Student s1{20};
    s1.set_age(25);
    std::cout << s1.get_age() << std::endl;

    const Student s2{30};
    // s2.set_age(25);
    std::cout << s2.get_age() << std::endl;
    return 0;
}

