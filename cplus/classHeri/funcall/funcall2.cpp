#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;


class abstractcls
{
public:
    abstractcls(float speed,int total)   //构造函数
    {
        this->speed = speed;
        this->total = total;
    }

    virtual void showmember()= 0;    //纯虚函数的定义
protected:
    float speed;
    int total;
};

class car : public abstractcls
{
public:
    car(int aird,float speed,int total):abstractcls(speed,total)
    {
        this->aird = aird;
    }

    virtual void showmember()
    {
        cout << speed <<"--------" <<total <<"-----------"<<aird<<endl;
    }
protected:
    int aird;
};
int main()
{
    car b(250,150,4);
    b.showmember();
    return 0;
}
