#include <iostream>
using std::cout;
using std::endl;
class A
{
public:
	virtual void foo()
	{
		cout << "A::foo() is called" << endl;
	}
};

class B : public A
{
public:
	virtual void foo(){ cout << "B::foo() is called" << endl; }
};

int main(void)
{
	A *a = new B();
	a->foo();
	return 0;
}
