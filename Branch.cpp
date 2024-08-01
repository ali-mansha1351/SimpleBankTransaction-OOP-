#include "Branch.h"
Branch::Branch()
{
	branch_code = 0;
	count++;
}
Branch::Branch(int branch_code, string location)
{
	this->branch_code = branch_code;
	this->location = location;
}
void Branch::set_branch_data()
{

	cout << "enter the address of the branch: " << endl;
	getline(cin, location);
	
	cout << "enter the branch code" << endl;
	while (!(cin >> branch_code))
	{
		cout << "enter a valid branch code: " << endl;
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();
}
int Branch::get_branch_code()
{
	return branch_code;
}
string Branch::get_branch_location()
{
	return location;
}
void Branch::display()
{
	cout << "the branch details are: " << endl;
	cout << "Branch code: " << branch_code << endl;
	cout << "Branch address: " << location << endl;
}
int Branch::count = 0;