#include<iostream>
#include<memory>

class MyClass
{
public:
    MyClass();
    ~MyClass();
private:
};

MyClass::MyClass()
{
    std::cout << "Object MyClass created\n";
}

MyClass::~MyClass()
{
    std::cout << "Object MyClass deleted\n";
}

//int main() {
//    int i = 5;
//    std::shared_ptr<int> ptr, ptr1; //аналогично int* ptr, ptr1;
//
//    ptr = std::make_shared<int>(i); //аналогично ptr = new int(i);
//    ptr1 = ptr;
//
//    std::cout << "ptr.use_count() = " << ptr.use_count() << "\n";
//    std::cout << "ptr1.use_count() = " << ptr1.use_count() << "\n";
//
//    return 0;
//}