/* Day13:类的继承 */
#include<iostream>

// Exercise1
class Animal{
public:
    void eat(){}
};

class Dog: public Animal{
public:
    void bark(){}
};


// Exercise2
class Base{
private:
    int my_private_value;
protected:
    int my_protected_value;
public:
    int my_public_value;
};

class Derived: public Base{
public:
    void test(){
        my_public_value = 1;
        my_protected_value = 2;
        // my_private_value = 2;
    }
};


// Exercise3
class Base2 {
private:
    int private_value = 0;

protected:
    void set_private_value(int value) {
        private_value = value;
    }

public:
    int get_private_value() const {
        return private_value;
    }
};

class Derived2 : public Base2 {
public:
    void update() {
        set_private_value(100);
    }
};


int main()
{

    return 0;
}