/* Day04:析构函数 */
#include <iostream>

// Exer1
class Student {
public:
    Student();
    ~Student();
};

Student::Student(){
    std::cout << "Call Construction Function." << std::endl;
}
Student::~Student(){
    std::cout << "Call Destruction Function." << std::endl;
}

// Exer2
class IntBuffer {
private:
    int* data;
    int size;

public:
    explicit IntBuffer(int size):
        data(new int[size]),
        size(size)
        {
            std::cout << "buffer allocated\n" << std::endl;
        }
    ~IntBuffer()
    {
        delete[] data;
    }
    int get_size()
    {
        return size;
    }
};

int main(){
    std::cout << "Task1..." << std::endl;
    Student s1;

    std::cout << "Task2..." << std::endl;
    IntBuffer buffer{100};
    std::cout << buffer.get_size() << std::endl;
    return 0;
}