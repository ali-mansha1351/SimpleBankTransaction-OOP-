#pragma once
#include "Account.h"
#include<string>
#include<iostream>
using namespace std;
class Account_holder
{
protected:
	//Transaction T;
	Account acc;
	string name;
	string CNIC;
	string city, block, house, street, country;
	int ZIP;
	string income_s;
public:
	Account_holder();
	Account_holder(string name,string CNIC,string city,string block, string house,string street,string country,int ZIP,string income_s,Account acc);
	void set_account_holder_data();
	void set_account_data();
	string get_name();
	string get_CNIC();
	string get_house();
	string get_block();
	string get_street();
	string get_city();
	string get_country();
	int get_ZIP();
	string get_income_s();
	void display();


};

