#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class ManyFriend
{
private:
	T item;

public:
	ManyFriend(const T & i) : item(i) {}
	template <typename C, typename D> friend void show2(C &, D &);
};

template <typename C, typename D> void show2(C &c, D &d)
{
	cout << c.item << ", " << d.item << endl;
}


int main()
{
	ManyFriend<int> hfil1(10);
	ManyFriend<int> hfil2(20);
	ManyFriend<double> hfdb(10.5);

	cout << "hfil1, hfil2: ";
	show2(hfil1, hfil2);

	cout << "hfdb, hfil2";
	show2(hfdb, hfil2);

	return 0;
}
