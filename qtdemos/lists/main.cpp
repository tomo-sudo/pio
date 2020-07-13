#include "widget.h"

#include <QApplication>
#include <QDebug>
#include <QVariant>
#include <QColor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    int t7(void);
    w.show();
    t7();

    return a.exec();
}


void t1()
{
    QList<QString> list;
    {
        QString str("This is a test string");
        list << str;

    }
    qDebug() << list[0] << "How are you! ";
}

int t2(void)
{

    QList<int> list;
    list << 1 << 2 << 3 << 4 << 5;
    QListIterator<int> i(list);
    for(; i.hasNext();)
        qDebug() << i.next();
    return 0;
}

int t3(void)
{
    QList<int> list;
    QMutableListIterator<int> i(list);

    for(int j = 0; j < 10; ++j)
        i.insert(j);

    for(i.toFront();i.hasNext();)
        qDebug() << i.next();

    for(i.toBack(); i.hasPrevious();)
    {
        if(i.previous() % 2 == 0)
            i.remove();
        else
            i.setValue(i.peekNext() * 10);
    }
    for(i.toFront(); i.hasNext();)
        qDebug() << i.next();
    return 0;

}

int t4(void)
{
    QList<int> list;
    for(int j = 0; j < 10; j++)
        list.insert(list.end(), j);

    QList<int>::iterator i;
    for(i = list.begin(); i != list.end(); ++i)
    {
        qDebug() << (*i);
        *i = (*i) * 10;
    }

    QList<int>::const_iterator ci;
    for(ci = list.constBegin(); ci != list.constEnd(); ++ci)
    {
        qDebug() << *ci;
    }

    return 0;
}


int t5(void)
{
    QMap<QString, QString> map;
    map.insert("beijing", "111");
    map.insert("shanghai", "021");
    map.insert("nanjing", "025");

    QMapIterator<QString, QString> i(map);

    for(; i.hasNext();)
    {
        i.next();
        qDebug() << " " << i.key() << "  " << i.value();
    }

    QMutableMapIterator<QString, QString> mi(map);
    if(mi.findNext("111"))
        mi.setValue("010");

    QMapIterator<QString, QString> modi(map);
    qDebug() << "   ";

    for(;modi.hasNext();)
    {
        modi.next();
        qDebug() << " " << modi.key() << " " << modi.value();
    }

    return 0;
}

int t6(void)
{
    QMap<QString,QString> map;//创建了一个QMap容器，容器内存储的键是QString类型，值是int类型，一个键只对应一个值，并且存储是讲究键顺序的。
    map["one"]="1";//当给一个容器内不存在的键赋值时，会自动将键和值添加进容器内
    map["three"]="3";
    map.insert("seven","7");//也可以使用insert来为容器添加键值对。

    QString value1=map["six"];//当采用键索引的方式访问键的值时，若容器内无该键，那么就会自动插入该新键，并且值默认设为0。
    qDebug()<<"value1:"<<value1;
    qDebug()<<"contains'six'?"<<map.contains("six");

    QString value2=map.value("five");//调用value函数，若指定要访问的键在容器内找不到，那么不会自动插入该新键，并且默认返回0，函数的参数2可以指定返回的值。
    qDebug()<<"value2:"<<value2;
    qDebug()<<"contains'five'?"<<map.contains("five");

    QString value3=map.value("nine","9");//函数的参数2指定返回的值。
    qDebug()<<"value3:"<<value3;

    //map默认是一个键只对应存在一个值，所以，如果重新给该键设置了值，那么以前的值就会被删除替换，只保留最新的值。
    map.insert("ten","10");
    map.insert("ten","100");
    qDebug()<<"ten:"<<map.value("ten");

    QMapIterator<QString, QString> i(map);
    for(; i.hasNext();)
    {
        i.next();
        i.key();

    }

    /*
       map可以调用insertMulti函数来实现一键多值，值得注意的是，在QMap容器中，若存在某个键拥有多个值，那么调用平常的value和
       使用map[键名]索引的方式访问元素，那么实际上返回的就是调用insertMulti函数最后一次添加的值，而values函数是专门提供给
       一键多值的元素用来返回这个元素的所有存在的值形成的列表，这个列表可以使用QList来保存起来。
       */
    map.insertMulti("two","2");
    map.insertMulti("two","4");
    QList<QString> values=map.values("two");
    qDebug()<<"two:"<<values;

    //上面是QMap容器对象调用insertMulti函数实现一键多值，其实有专门的容器类实现一键多值的操作和存储，例如：QMultimap
    //注意，这个QMultimap生成的一键多值对象和insertMulti函数实现的一键多值是有区别的，QMultimap对象不能够索引方式访问，但可以使用value函数来访问多值中最新的那个值，还有values函数可以返回该键对应的所有值列表。
    QMultiMap<QString,int> map1,map2,map3;
    map1.insert("values",1);//插入values键，指定第一个值为1
    map1.insert("values",2);//再次为values键插入第二个值为2
    map1.insert("qwe",888);//后面插入操作以此类推
    map1.insert("qwe",999);
    map2.insert("values",3);
    map2.insert("rty",444);

    map3=map1+map2;//相当于把map1对象内存储的values和qwe键（不管键对应多值还是单值），还有map2对象存储的values和rty键相合并然后全部放入到map3容器中。
    QList<int> myValues=map3.values("values");//QMultiMap容器类对象也跟QMap一样拥有values函数来返回指定键的所有值的列表
    qDebug()<<"the values are:";
    for(int i=0;i<myValues.size();++i)
    {
        qDebug()<<myValues.at(i);
    }
    return  0;
}


int t7(void)
{
    QMap<QString, QString> map;
    map.insert("beijing", "111");
    map.insert("shanghai", "021");
    map.insert("nanjing", "025");

    QMap<QString, QString>::const_iterator i;

    for(i = map.constBegin(); i != map.constEnd(); ++i)
    {
        qDebug() << " " << i.key() << "  " << i.value();
    }

    QMap<QString, QString>::iterator mi;
    mi = map.find("beijing");
    if(mi != map.end())
        mi.value() = "010";

    QMap<QString, QString>::const_iterator modi;
    qDebug() << "   ";

    for(modi = map.constBegin(); modi != map.constEnd(); ++modi)
    {
        qDebug() << " " << modi.key() << " " << modi.value();
    }

    return 0;
}


int t8()
{

    return 0;

}


