#include <iostream>

/* Phrase1: 函数声明与函数类型 */
int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int (*fp)(int, int) = add;

/* Phrase2: 函数指针 */
int calculate(int a, int b, int (*op)(int, int)){
    return op(a, b);
}

/* Phrase3: 函数引用 */
int(&rf)(int, int) = add;


int main(){
    std::cout << fp(1,2) << std::endl;

    std::cout << "Phrase2----------" << std::endl;
    std::cout << calculate(3,4,add) << "\n" << calculate(3,4,sub) << std::endl;

    std::cout << "Phrase3----------" << std::endl;
    std::cout << rf(3,4) << std::endl;
}