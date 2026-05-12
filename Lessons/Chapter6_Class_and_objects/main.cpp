#include <iostream>

class A {
private:
    int x = 10;
};

int main() {
    A a;
    a.x = 5;   // 错误：x 是私有成员
}