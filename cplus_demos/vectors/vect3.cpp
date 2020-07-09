#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
	std::string title;
	int rating;
};

bool operator<(const Review &r1, const Review &r2);
bool worseThan(const Review &r1, const Review &r2);
bool FillReview(Review &rr);
void ShowReview(const Review &rr);

int main()
{
	using namespace std;

	vector<Review> books;
	Review temp;

	while(FillReview(temp))
		books.push_back(temp);

	int num = books.size();
	cout << "books.size " << num << std::endl;
	if(num > 0)
	{
		cout << "Thanks you, enter the following: "
			<< books.size() << " ratings:\n"
			<< "Rating\tBOOK\n";
	//	for(int i = 0; i < num; i++)
	//		ShowReview(books[i]);
		for_each(books.begin(), books.end(), ShowReview);
		sort(books.begin(), books.end());
		cout << "Reprising:\n"
			<< "Rating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
		sort(books.begin(), books.end(), worseThan);
		cout << "Reprising:\n"
			<< "Rating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
		random_shuffle(books.begin(), books.end());
		for_each(books.begin(), books.end(), ShowReview);

	}
	else
		cout << "Nothing entered, nothing gained.\n";
	return 0;
}

//for conbination of sort
bool operator<(const Review &r1, const Review &r2)
{
	if(r1.title < r2.title)
		return true;
	else if(r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}
//for combination of sort
bool worseThan(const Review &r1, const Review &r2)
{
	if(r1.rating < r2.rating)
		return true;
	else
		return false;
}


bool FillReview(Review &rr)
{
	std::cout << "Enter book title (q to quit): ";
	std::getline(std::cin, rr.title);
	if(rr.title == "quit")
		return false;

	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if(!std::cin)
		return false;
	while(std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const Review &rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}
