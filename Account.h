#pragma once
#include "Branch.h"
#include "Transaction.h"
#include<string>
#include<iostream>
using namespace std;
class Account:public Branch
{
protected:
	Transaction T;
	string account_title;
	int account_number;
	string IBAN;
	string account_type;
	double balance;
public:
	Account();
	Account(string account_title, int account_number, string IBAN, string account_type,double balance);
	void set_account_data();
	void set_data_from_file(string account_title, int account_number, string IBAN, string account_type, double balance);
	void set_account_number();
	void set_transaction_data();
	string get_transaction_time();
	int get_transaction_id();
	string get_title();
	int get_account_number();
	void set_balance(double);
	double get_balance();
	string get_type();
	string get_IBAN();
	void display();
	void disp();
	int get_ID();
	void display_only_account();
	friend ostream& operator <<(ostream& out, Account& obj);
	friend istream& operator >>(istream& in, Account& obj);
};

