#include "Account.h"
Account::Account()
{
	account_number = 0;
	balance = 0;
}
Account::Account(string account_title, int account_number, string IBAN, string account_type,double balance)
{
	this->account_title = account_title;
	this->account_number = account_number;
	this->IBAN = IBAN;
	this->account_type = account_type;
	this->balance = balance;
}
void Account::set_account_data()
{
	cout << "enter account title(with a slash between first and last name)" << endl;
	getline(cin, account_title);
	cout << "enter the account number only digits(minimum 6 digits)" << endl;
	cin >> account_number;
	int num = account_number;
	while (num <= 0)
	{
				
		cout << "account number cannot be negative number, enter valid account number" << endl;
		cin >> num;
	}
	account_number = num;
	int len = 0;
	while (true)
	{
		num = account_number;
		while (num > 0)
		{
			len++;
			num /= 10;
		}
		if (len < 6)
		{
			cout << "account number is less then 6 digits ,  enter valid account number" << endl;
			cin >> num;
			account_number = num;
		}
		else
		{
			break;
		}
	}
	cin.ignore();
	cout << "enter the IBAN number" << endl;
	getline(cin, IBAN);
	cout << "enter the account type" << endl;
	cin >> account_type;
	cout << "enter the account balance: " << endl;
	cin >> balance;
	double num1 = balance;
	while (num1 < 0)
	{
		cout << "enter the balance again it can not be negative: " << endl;
		cin >> num1;
	}
	balance = num1;
}
void Account::set_data_from_file(string account_title, int account_number, string IBAN, string account_type, double balance)
{
	this->account_title = account_title;
	this->account_number = account_number;
	this->IBAN = IBAN;
	this->account_type = account_type;
	this->balance = balance;
}
double Account::get_balance()
{
	return balance;
}
void Account::set_account_number()
{
	//cout << "enter the account number: " << endl;
	cin >> account_number;
}
void Account::set_balance(double n)
{
	balance = n;
}
int Account::get_ID()
{
	return T.get_id();
}
int Account::get_account_number()
{
	return account_number;
}
string Account::get_title()
{
	return account_title;
}
string Account::get_type()
{
	return account_type;
}
string Account::get_IBAN()
{
	return IBAN;
}

void Account::display()
{
	cout << "the account details are: " << endl;
	cout << "account titile: " << account_title << endl;
	cout << "account type: " << account_type << endl;
	cout << "account number: " << account_number << endl;
	cout << "IBAN: " << IBAN << endl;
	cout << "-----------------------------------------------" << endl;
	T.display();
}
void Account::display_only_account()
{
	cout << "the account details are: " << endl;
	cout << "account titile: " << account_title << endl;
	cout << "account type: " << account_type << endl;
	cout << "account number: " << account_number << endl;
	cout << "IBAN: " << IBAN << endl;
	cout << "the acount's  balannce is: " << balance << endl;
}
//void Account::display_for_file(Account&obj)
//{
//	obj.get_account_number();
//	cout << endl;
//	obj.get_balance();
//	cout << endl;
//	obj.get_title();
//	cout << endl;
//	obj.get_IBAN();
//	cout << endl;
//	obj.get_type();
//}
void Account::disp()
{
	T.display();
}
void Account::set_transaction_data()
{
	T.set_transaction_data();
}
string Account::get_transaction_time()
{
	return T.get_time();
}
int Account::get_transaction_id()
{
	return T.get_id();
}
ostream& operator <<(ostream& out, Account& obj)
{
	out << "account titile: " <<obj.account_title << endl;
	out << "account type: " << obj.account_type << endl;
	out << "account number: " << obj.account_number << endl;
	out << "IBAN: " << obj.IBAN << endl;
	out << "the acount's  balannce is: " << obj.balance << endl;
	return out;
}
istream& operator >>(istream& in, Account& obj1)
{
	in >> obj1.account_number;
	in >> obj1.balance;
	in >> obj1.account_title;
	in >> obj1.IBAN;
	in >> obj1.account_type;
	return in;
}
//void Account::transfer(Transaction& obj, Transaction& object, Account& ob, Account& ob1)
//{
//	int acc_number = 0,acc_number1, pin = 0;
//	cout << "enter the account number you want to send money to: " << endl;
//	cin >> pin;
//	acc_number = ob.account_number;
//	acc_number1 = ob1.account_number;
//	if (pin == ob.account_number)
//	{
//
//	}
//}