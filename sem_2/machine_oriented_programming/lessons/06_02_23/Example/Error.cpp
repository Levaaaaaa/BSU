//#include<iostream>
//#include<memory>
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
//    AnotherClass(MyClass* obj_);
//    ~AnotherClass();
//    void function()
//    {
//        std::cout << "AnotherClass.function()\n";
//    }
//private:
//    MyClass* obj;
//};
//
//AnotherClass::AnotherClass(MyClass* obj_) :obj(obj_)
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
//    return AnotherClass(new MyClass());
//}

//int main()
//{
//    MyClass* ptr = new MyClass();
//    std::cout << ptr << "\n";
//    ptr = nullptr;
//    Anotherfunction().function();
//    return 0;
//}