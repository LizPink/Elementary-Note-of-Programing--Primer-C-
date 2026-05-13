#include <iostream>
#include <vector>

int main(){
    /* 向量的定义 */
    std::vector<int> v1;
    std::vector<int> v2(10);
    for (auto i:v2){
        std::cout << i << "\n";
    }

    /* 向量的操作 */
    std::vector<int>::size_type size = v2.size();
    auto iter = v2.end();
    iter -= 1;
    std::cout << "The last element of v2 is: " << *iter << std::endl;

    std::vector<int> v4 = {10};

    return 0;
}