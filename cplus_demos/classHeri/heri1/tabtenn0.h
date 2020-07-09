#pragma once
#include <string>
using std::string;      //  cannot put here but where it can be put?
class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string &fn = "none",
			const string &ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return hasTable; }
	void ResetTable(bool v){ hasTable = v; }
};
