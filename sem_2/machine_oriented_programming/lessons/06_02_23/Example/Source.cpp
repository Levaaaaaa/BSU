//#include<iostream>
//#include<memory>
//
//class MyClass
//{
//public:
//    MyClass();
//    ~MyClass();
//private:
//};
//
//MyClass::MyClass()
//{
//    std::cout << "Object MyClass created\n";
//}
//
//MyClass::~MyClass()
//{
//    std::cout << "Object MyClass deleted\n";
//}
//
//class AnotherClass
//{
//public:
//    AnotherClass(std::shared_ptr<MyClass> obj_);
//    ~AnotherClass();
//    void function()
//    {
//        std::cout << "AnotherClass.function()\n";
//    }
//private:
//    std::shared_ptr<MyClass> obj;
//};
//
//AnotherClass::AnotherClass(std::shared_ptr<MyClass> obj_) : obj(obj_)
//{
//    std::cout << "Object AnotherClass created\n";
//}
//
//AnotherClass::~AnotherClass()
//{
//    std::cout << "Object AnotherClass deleted\n";
//}
//
//AnotherClass Anotherfunction()
//{
//    return AnotherClass(std::make_shared<MyClass>());
//}

//int main()
//{
//    std::shared_ptr<MyClass> ptr = std::make_shared<MyClass>();
//    std::cout << ptr << "\n";
//    ptr = nullptr;
//    Anotherfunction().function();
//    return 0;
//}