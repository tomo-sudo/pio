#include <iostream>
#include <cstdio>

using namespace std;

class A
{
public:
    void foo()
    {
        printf("1\n");
    }
    virtual void fuu()
    {
       printf("2\n");    
    }
};

class B:public A
{
public :
    void foo()
    {
        printf("3\n");
    }
    void fuu()
    {
        printf("4\n");
    }
};

int main()
{
    A a;
    B b;
    
    A *p = &a;
    cout<< "p->foo()---" ; p->foo() ; 
    cout<<"p->fuu()---";p->fuu();    

    cout <<"-------向上转型-----------"<<endl;
    p=&b;
    cout<<"p->foo()---";p->foo();    
    cout<<"p->fuu()---";p->fuu();    
    
    cout <<"--------向下转型----------"<<endl;
    
    B *ptr =(B *)&a;
    cout<<"ptr->foo()----";ptr->foo();
    cout<<"ptr->fuu()-----";ptr->fuu();
    return 0;
}
