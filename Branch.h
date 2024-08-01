#pragma once
#include "Bank.h"
#include<string>
#include<iostream>
using namespace std;
class Branch :public Bank
{
protected:
	int branch_code;
	string location;
public:
	static int count;
	Branch();
	Branch(int branch_code, string location);
	void set_branch_data();
	int get_branch_code();
	string get_branch_location();
	void display();
};

