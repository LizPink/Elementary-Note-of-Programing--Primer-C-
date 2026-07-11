/* Day2 */
// 对象、成员访问、对象指针、对象引用与 this
#include<iostream>

class Counter{
private:
    int value = 0;

public:
    Counter& increase(){
        ++value;
        return *this;
    }

    Counter& decrease(){
        --value;
        return *this;
    }

    int get_value() {
        return value;
    }
};

int main(){
    Counter counter;
    counter
        .increase()
        .decrease()
        .increase()
        .increase();

    std::cout << counter.get_value() << "\n";

    return 0;
}