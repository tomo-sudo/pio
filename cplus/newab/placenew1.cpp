#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class T2
{
private:
	int a;
	int b;
public:
	void Show();

};

void T2::Show()
{
	cout << "a is " << a << ", " << b << endl;
}

class JustTesting
{
private:
	string words;
	int number;
	int a;
public:
	//JustTesting(const string &s = "Just Testing", int n = 0)
	JustTesting(const string s = "Just Testing", int n = 0)
	{
		words = s;
		number = n;
		cout << words << " constructed\n";
	}
		
	~JustTesting() 
	{
		cout <<  words << " destroyed" << endl;
	}
	
	void Show() const 
	{
		cout << words << ", " << number << endl;
	}	

	void Show2(JustTesting &t1);
	bool operator==(const JustTesting &jt2);
	friend bool operator==(const JustTesting &jt, const JustTesting &jt2);


};
void JustTesting::Show2(JustTesting &t1)
{
	number = t1.a;
}

bool JustTesting::operator==(const JustTesting &jt2)
{
	int number1 = jt2.number;
	if (number > number1)
		return false;
	return true;
}

bool operator==(const JustTesting &jt, const JustTesting &jt2)
{
	return jt.number == jt2.number;
}

int main()
{
	char *buffer = new char[BUF];
	JustTesting *pc1, *pc2;
	pc1 = new (buffer)JustTesting;
	pc2 = new JustTesting("Heap1", 20);

	cout << "Memory block address:\n" << "buffer: "
		<< (void*)buffer << "	heap: " << pc2 << endl;
	cout << "Memory contents:\n ";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting *pc3, *pc4;
	pc3 = new (buffer)JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heep2", 10);

	cout << "Memory contents:\n";
	cout << pc3 << ": ";
	pc3->Show();

	cout << pc4 << ": ";
	pc4->Show();

	delete pc2;
	delete pc4;

//	delete pc1;
//	delete pc3;

	//JustTesting aa1();
	JustTesting aa1 = JustTesting();
	//JustTesting aa1("aa", 33);

	//aa1.Show();
	JustTesting tmp = aa1;
	delete []buffer;
	cout << "Done\n";

	
	return 0;
}
