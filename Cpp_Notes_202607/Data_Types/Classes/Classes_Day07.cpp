/* Day07:类之间的关系 */
#include <iostream>

class Engine {
private:
    double power;

public:
    explicit Engine(double power):
    power(power)
    {
        std::cout << "Engine(" << power << ")" << std::endl;
    }
};


class Car {
private:
    Engine engine;
public:
    Car():
    engine{100}
    {
        std::cout << "Car Constructor body\n";
    }
};


int main()
{
    Car car;
}
