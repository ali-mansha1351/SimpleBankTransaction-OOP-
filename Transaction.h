#pragma once
#include<string>
#include<iostream>
using namespace std;
class Transaction
{
protected:
	int id;
	//double initial_balance;
	double changed;
	string y;
public:
	static int number;
	int number1;
	Transaction();
	Transaction(int id, double changed,int number1);
	virtual void  set_transaction_data();
	void set_transaction_time();
	int get_id();
	double get_changed();
	string get_time();
	int get_no_of_transactions();
	void display();

};

