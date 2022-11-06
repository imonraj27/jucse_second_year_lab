#include <iostream>
using namespace std;

class A
{
public:
    virtual void f1()
    {
        cout << "inside A f1 void" << endl;
    }

    virtual void f2()
    {
        cout << "inside A f2 void" << endl;
    }
};

class B : public A
{
public:
    void f1(int a)
    {
        cout << "inside B f1 int" << endl;
    }

    void f2()
    {
        cout << "inside B f2 void" << endl;
    }
};

int main()
{
    A *p;
    B b;
    p = &b;

    p->f1(10);
}