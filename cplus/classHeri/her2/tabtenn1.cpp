#include "tabtenn1.h"
#include <iostream>

using std::cout;
TableTennisPlayer::TableTennisPlayer(const string &fn,
		const string &ln, bool ht) : firstname(fn),
	lastname(ln), hasTable(ht)
	{
		cout << "here is base class \n";
	}
	
void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn, 
		const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
	: TableTennisPlayer(tp), rating(r)
{

}

//TableTennisPlayer::TableTennisPlayer(const string &fn,
//		const string &ln, bool ht)
//{
//	firstname = fn;
//	lastname = ln;
//	hasTable = ht;
//}
