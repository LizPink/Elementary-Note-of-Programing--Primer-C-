/* Day09:移动 */
#include <iostream>
// 移动构造函数
class Buffer1{
private:
    int* data;
public:
    Buffer1(Buffer1&& other)
    : data(other.data)
    {
        other.data = nullptr;
    }
};



int main()
{
    return 0;
}