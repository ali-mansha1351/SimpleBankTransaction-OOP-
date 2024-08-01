#pragma once
#include "Account.h"
#include "Transaction.h"
class Transfer:public Account, public Transaction
{
protected:
	double money_to_transfer;
public:
	int number;
	Transfer();
	Transfer(double money_to_transfer,int number);
	void transfer_money(Account &fromacc, Account &toacc);
	//void set_amount();
	void deposit_money(Account& obj);
	void withdraw_money(Account& obj);
	double get_amount();
	void display();
};

