#pragma once
#include<string>
#include<iostream>
using namespace std;
class Bank
{
protected:
	string name;
	string location;
public:
	Bank();
	Bank(string name, string location);
	void set_bank_data();
	string get_name();
	string get_bank_location();
	virtual void display();
};

