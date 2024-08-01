#include "Transfer.h"
Transfer::Transfer()
{
	money_to_transfer = 0;
	number = 0;
}
Transfer::Transfer(double money_to_transfer, int number)
{
	this->money_to_transfer = money_to_transfer;
	this->number = number;
}
//void  Transfer::set_amount()
//{
//	cout<<"enter the "
//}
void Transfer::transfer_money(Account &fromacc, Account &toacc)
{
	number++;
	cout << "enter the amount you want to transfer: " << endl;
	cin >> money_to_transfer;
	double am = money_to_transfer;
	int opt = 1;
	while (am > fromacc.get_balance())
	{
		cout << "there are insufficient funds in your account, enter again" << endl;
		cin >> am;
		
	}
	money_to_transfer = am;
		fromacc.set_balance(fromacc.get_balance() - money_to_transfer);
		toacc.set_balance(toacc.get_balance() + money_to_transfer);
		//Transfer::set_transaction_data();
		//cout << "money transfered and the id is: " << Transfer::get_id() << endl;
		fromacc.set_transaction_data();
		toacc.set_transaction_data();
		//fromacc.disp();
		//toacc.disp();
		//cout << "money transfered and the id is: " << fromacc.get_ID() << endl;
		//cout << "money transfered and the id is: " << toacc.get_ID() << endl;
	
	
}
void Transfer::deposit_money(Account& obj)
{
	number++;
	cout << "enter the amount to deposit: " << endl;
	cin >> money_to_transfer;
	obj.set_balance(obj.get_balance() + money_to_transfer);
	obj.set_transaction_data();
	/*Transfer::Transaction::set_transaction_data();
	Transfer::Transaction::set_transaction_time();*/
	
}
void Transfer::withdraw_money(Account& obj)
{
	number++;
	double am = 0;
	cout << "enter the amount you want to withdraw: " << endl;
	cin >> money_to_transfer;
	am= money_to_transfer;
	while (am > obj.get_balance())
	{
		cout << "insufficient funds enter again: " << endl;
		cin >> am;
	}
	money_to_transfer = am;
	obj.set_balance(obj.get_balance() - money_to_transfer);
	obj.set_transaction_data();
	/*Transfer::Transaction::set_transaction_data();
	Transfer::Transaction::set_transaction_time();*/
}
void Transfer::display()
{
	cout<<"the transaction id: "<< Transfer::Transaction::get_id()<<endl;
	cout << "the trasnaction time is: " << Transfer::Transaction::get_time() << endl;
}
double Transfer::get_amount()
{
	return money_to_transfer;
}