#include<iostream>
#include<memory>

class MyClass
{
public:
    MyClass();
    MyClass(int x_) : x(x_) { std::cout << "Object MyClass created\n"; }
    ~MyClass();

    int x;
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

void del_MyClass(MyClass* obj) 
{
    std::cout << "Object MyClass deleted\n";
    delete obj;
}

int main() 
{
    int i = 5;
    std::shared_ptr<MyClass> c(new MyClass(i), del_MyClass);    //первый параметр - куда выделить память, второй параметр - как освободить
    std::cout << "c.use_count() = " << c.use_count() << " " << c->x << "\n";

    std::shared_ptr<int> int_array(new int[10], std::default_delete<int[]>(), std::allocator<int[]>()); //третий аргумент - как выделять память
    std::cout << "int_array.use_count() = " << int_array.use_count() << " " << "\n";

    return 0;
}

/*
int main() {
    int i = 5;
    std::shared_ptr<int> ptr, ptr1; //аналогично int* ptr, ptr1;

    ptr = std::make_shared<int>(i); //аналогично ptr = new int(i);
    ptr1 = ptr;

    std::cout << "ptr.use_count() = " << ptr.use_count() << "\n";
    std::cout << "ptr1.use_count() = " << ptr1.use_count() << "\n";

    std::shared_ptr<MyClass> a;
    a = std::make_shared<MyClass>(i);   //a = new MyClass(i);

    std::shared_ptr<int> b(a, &a->x);   //int* b (a);

    a = nullptr;

    std::cout << "a.use_count() = " << a.use_count() << "\n";
    std::cout << "b.use_count() = " << b.use_count() << "\n";

    return 0;
}*/