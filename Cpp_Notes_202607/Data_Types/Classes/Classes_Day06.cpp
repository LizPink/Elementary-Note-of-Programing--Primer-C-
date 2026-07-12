/* Day06:静态成员 */
#include <iostream>

class Student {
private:
    int age = 0;                    // 对象属性
    inline static int count = 0;    // 类属性

public:
    Student(int age);
    static int get_count()
    {
        return Student::count;
    }

    int get_age() const
    {
        Student::count += 1;
        return this->age;
    }
};

Student::Student(int age):
    age(age)
{
    std::cout << "Call Constructor..." << std::endl;
}


int main() {
    Student s1{20};
    std::cout << s1.get_age() << std::endl;
    std::cout << "total number of students:" << std::endl << Student::get_count() <<std::endl;

    return 0;
}