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

/* 类型化简 */
using BinaryFunc = int (int, int);
BinaryFunc* fp1 = add;
BinaryFunc& rf1 = add;

using BinaryFuncPtr = int(*) (int, int);
BinaryFuncPtr fp2 = add;

/* Phrase4: 回调函数 */
// Exer1: 遍历数组
void print(int x){
    std::cout << x << " ";
}
void print_square(int x){
    std::cout << x*x << " ";
}
void print_double(int x){
    std::cout << x*2 << " ";
}
void for_each_int(int arr[], int n, void(*visit)(int)){
    for (int i=0; i<n; i++){
        visit(arr[i]);
    }
}
// Exer2: 条件判断
bool is_even(int x){
    return x%2 == 0;
}
bool is_positive(int x){
    return x>0;
}
bool is_greater_than_3(int x){
    return x>3;
}
int count_if_int(int arr[], int n, bool(*pred)(int)){
    int count = 0;
    for (int i=0; i<n; i++){
        if(pred(arr[i]))
            {count++;}
    }
    return count;
}

/* Phrase5: Lambda */
auto f = [](int x){
    return x+2;
};

/* Phrase6:  */


int main(){
    std::cout << fp(1,2) << std::endl;

    std::cout << "Phrase2----------" << std::endl;
    std::cout << calculate(3,4,add) << "\n" << calculate(3,4,sub) << std::endl;

    std::cout << "Phrase3----------" << std::endl;
    std::cout << rf(3,4) << std::endl;

    std::cout << "Phrase4----------" << std::endl;
    std::cout << rf1(3,5) << "," << fp1(3,6) << "," << fp2(3,7) << std::endl;

    std::cout << "Phrase5----------" << std::endl;
    std::cout << "Task1: 遍历访问" << std::endl;
    int arr[] = {1,2,3,4,5};
    int n = 5;
    for_each_int(arr, n, print);
    for_each_int(arr, n, print_square);
    for_each_int(arr, n, print_double);

    std::cout << "Task2: 条件判断" << std::endl;
    std::cout << count_if_int(arr, n, is_even) << std::endl;
    std::cout << count_if_int(arr, n, is_positive) << std::endl;
    std::cout << count_if_int(arr, n, is_greater_than_3) << std::endl;

    std::abs(-1);
}