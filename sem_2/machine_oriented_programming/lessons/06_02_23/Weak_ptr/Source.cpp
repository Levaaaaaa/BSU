#include<iostream>
struct B;
struct A
{
    std::shared_ptr<B> b;
    A() { std::cout << "A()\n"; }
    ~A() { std::cout << "~A()\n"; }
};
struct B
{
    //достаточно добавить хотя бы одн weak_ptr
    //иначе не будет освобождаться память из-за зацикливания
    std::weak_ptr<A> a; //std::shared_ptr<A> a;
    B() { std::cout << "B()\n"; }
    ~B() { std::cout << "~B()\n"; }
};
void useAB()
{
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->b = b;
    b->a = a;

}
int main() {

    useAB();

    system("pause");
    return 0;
}