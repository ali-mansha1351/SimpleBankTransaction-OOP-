#include "Bank.h"
#include<string>
#include<iostream>
using namespace std;
Bank::Bank()
{

}
Bank::Bank(string name, string location)
{
	this->name = name;
	this->location = location;
}
void Bank::set_bank_data()
{
	cout << "enter the name of the bank" << endl;
	getline(cin, name);
	cout << "enter the location of the bank" << endl;
	getline(cin, location);
}
string Bank::get_bank_location()
{
	return location;
}
string Bank::get_name()
{
	return name;
}
void Bank::display()
{
	//cout << "the details of the bank are:" << endl;
	cout << "\t\t\t\t\t     " << name << endl;
	cout << endl;
	cout << "\t\t\t\t\t " << location << endl;

}