#include <iostream>
#include <string>
#include <vector>

const int NUM = 5;

int main()
{
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;

	vector<int> ratings(NUM);
	vector<string> titles(NUM);
	cout << "enter\n"
		<< NUM << " book titles and your ratings (0-10).\n";

	int i;
	for(i = 0; i < NUM; i++)
	{
		cout << "Enter title #" << i + 1 << ": ";
		getline(cin, titles[i]);
		cout << "enter your rating (0-10): ";
		cin >> ratings[i];
		cin.get();
	}

	cout << "thanks. enter \n"
		<< "Rating\tBook\n";
	for(i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}
	return 0;
}
