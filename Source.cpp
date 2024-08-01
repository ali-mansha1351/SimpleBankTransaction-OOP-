#include "Bank.h"
#include "Account.h"
#include "Account_holder.h"
#include "Branch.h"
#include "Transfer.h"
#include<iostream>
#include <conio.h>
#include<string>
#include <Windows.h>
#include <fstream>
using namespace std;
void resize(Account*& obj, int &size)
{
	size++;
	Account *obj1 = new Account[size];
	for (int i = 0; i < size - 1; i++) {
		obj1[i] = obj[i];
	}
	delete []obj;
	obj = obj1;
}
void resizet(Transfer*& obj, int& size1)
{
	size1++;
	Transfer* obj1 = new Transfer[size1];
	for (int i = 0; i < size1 - 1; i++) {
		obj1[i] = obj[i];
	}
	delete[]obj;
	obj = obj1;
}
int* regrow(int* arr, int& size2)
{
	size2++;
	int* newar = new int[size2];
	for (int i = 0; i < size2; i++)
	{
		newar[i] = arr[i];
	}
	delete[]arr;
	arr = nullptr;
	return newar;
}
void MakeAccountFolder()
{
	string foldername = "Account's Information";
	CreateDirectory(foldername.c_str(),NULL);
}
void MakeTrasnactionFolder()
{
	string foldername = "Account's Information\\Trasnaction's Details";
	CreateDirectory(foldername.c_str(), NULL);
}
int MakeFile(int num)
{
	string temp = to_string(num);
	string filename = "Account's Information\\" + temp + ".txt";
	ifstream f1(filename);
	if (f1.good())
	{
		return 1;
	}
	else {
		fstream f(filename);
		f.open(filename);
		f.close();
		return 0;
	}
	
}
void MakeTransactionFile(int num)
{
	string temp = to_string(num);
	string filename = "Account's Information\\Trasnaction's Details\\" + temp + ".txt";
	fstream f(filename);
	f.open(filename);
	f.close();
}
void EnterDataInAccount(int num, Account& obj)
{
	string temp = to_string(num);
	string filename = "Account's Information\\" + temp + ".txt";
	fstream f;
	f.open(filename, ios::app);
	f << obj.get_account_number();
	f << endl;
	f << obj.get_balance();
	f << endl;
	f << obj.get_title();
	f << endl;
	f << obj.get_IBAN();
	f << endl;
	f << obj.get_type();
	f << endl;
	f.close();
	
}
void EnterDataInAccount_atlast(int num, Account& obj)
{
	string temp = to_string(num);
	string filename = "Account's Information\\" + temp + ".txt";
	fstream f;
	f.open(filename, ios::out);
	f << obj.get_account_number();
	f << endl;
	f << obj.get_balance();
	f << endl;
	f << obj.get_title();
	f << endl;
	f << obj.get_IBAN();
	f << endl;
	f << obj.get_type();
	f << endl;
	f.close();

}
void RadDataFromAccount(int num,Account &obj)
{
	int anum = 0;
	double bal = 0;
	string name, iban, type;
	string temp = to_string(num);
	string filename = "Account's Information\\" + temp + ".txt";
	ifstream f;
	f.open(filename);
	for(int i=1;i<=5;i++)
	{
		f >> anum >> bal >> name >> iban >> type;
		if (f.eof())
		{
			break;
		}
	}
	f.close();
	obj.set_data_from_file(name, anum, iban, type, bal);
}
void Collection_of_accounts(int num)
{
	string filename = "Account's Information\\account-collection.txt";
	fstream f;
	f.open(filename, ios::app);
	f << num << endl;
	f.close();
}

void InfoEntryOfAccount_onDeposit(int num,Account &obj,Transfer &t)
{
	string temp = to_string(num);
	string filename = "Account's Information\\Trasnaction's Details\\" + temp + ".txt";
	fstream f;
	f.open(filename, ios::app);
	f << "initial balance: " << obj.get_balance() - t.get_amount() << endl;;
	f << "amount deposited: "<<t.get_amount() << endl;
	f << "updated balance: " << obj.get_balance() << endl;
	f << "transaction id: " << obj.get_transaction_id() << endl;
	f << "transaction time: " << obj.get_transaction_time() << endl;
	f.close();
}
void InfoEntryOfAccount_onWithdraw(int num, Account& obj, Transfer& t)
{
	string temp = to_string(num);
	string filename = "Account's Information\\Trasnaction's Details\\" + temp + ".txt";
	fstream f;
	f.open(filename, ios::app);
	f << "initial balance: " << obj.get_balance() + t.get_amount() << endl;
	f << "amount withdrawn: " << t.get_amount() << endl;
	f << "updated balance: " << obj.get_balance() << endl;
	f << "transaction id: " << obj.get_transaction_id() << endl;
	f << "transaction time: " << obj.get_transaction_time() << endl;
	f.close();
}
void InfoEntryOfAccount_onTransfer(int num, int num1, Account& obj, Account& obj1, Transfer& t)
{
	string temp = to_string(num);
	string filename = "Account's Information\\Trasnaction's Details\\" + temp + ".txt";
	string temp1 = to_string(num1);
	string filename1 = "Account's Information\\Trasnaction's Details\\" + temp1 + ".txt";
	fstream f;
	f.open(filename, ios::app);
	f << "initial balance: " << obj.get_balance() + t.get_amount() << endl;
	f << "amount trasnfered: " << t.get_amount() << endl;
	f << "updated balance: " << obj.get_balance() << endl;
	f << "transaction id: " << obj.get_transaction_id() << endl;
	f << "transaction time: " << obj.get_transaction_time() << endl;
	f.close();
	fstream f1;
	f1.open(filename1, ios::app);
	f << "initial balance: " << obj.get_balance() - t.get_amount();
	f1 << "amount received: " << t.get_amount() << endl;
	f1 << "updated balance: " << obj1.get_balance() << endl;
	f1 << "transaction id: " << obj1.get_transaction_id() << endl;
	f1 << "transaction time: " << obj1.get_transaction_time() << endl;
	f1.close();
}
void header(Bank& obj)
{
	cout << "\t\t\t\t---WELCOME TO BANKING MANAGEMENT SYSTEM---" << endl;
	cout << endl;
	obj.display();
	cout << endl;
	cout << endl;
}
int main()
{
	MakeAccountFolder();
	MakeTrasnactionFolder();
	int size = 0, size1 = 0,size2=0,size3=0,size4=0, opt = 1, i = 0, option = 1, option1 = 0, acc = 0,acc1=0, check = 0,check1=0,check3 = 0,checker=0,q=0,w=0, z = 0, x = 0,s=0,count=1;
	int* arr = new int[size2];
	Bank b1("Bank of Punjab", "Gulberg 3, Lahore Pakistan");
	Account* a;
	a = new Account[size];
	Account* a1;
	a1 = new Account[size3];
	Transfer* t;
	t = new Transfer[size1];
	while (opt != 0)
	{
		
		resize(a1, size3);
		header(b1);
		cout << "\t\t\t\t   Welcome to Account Registration Portal " << endl;
		cout << endl;
		cout << "enter the account number : " << endl;
		a1[s].set_account_number();
		cin.ignore();
		check3 = MakeFile(a1[s].get_account_number());
		MakeTransactionFile(a1[s].get_account_number());
		if(check3 == 1) {
			resize(a, size);
			
			checker++;
			cout << "account already exists in database" << endl;
			 RadDataFromAccount( a1[s].get_account_number(), a[i]);
			cout << a[i];
			i++;
		}
		else {
			resize(a, size);
			cout << "account does not exists, enter the account details for registring the account: " << endl;
			a[i].set_account_data();
			EnterDataInAccount(a[i].get_account_number(), a[i]);
			Collection_of_accounts(a[i].get_account_number());
			i++;
		}
		count++;
		cout << "enter 1 to continue registrating or 0 to exit: " << endl;
		cin >> opt;
		system("cls");
		cin.ignore();

	}
	cout << "---------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		a[i].display_only_account();
		cout << "---------------------------------------" << endl;
	}
	while (option != 99)
	{
		header(b1);
		cout << "Enter 1 to deposit money in your account" << endl;
		cout << "Enter 2 to withdraw money from your account" << endl;
		cout << "Enter 3 to transfer money to another account" << endl;
		cout << "Enter 4 to Display info of account" << endl;
		cout << "Enter 99 to exit" << endl;
		cin >> option;
		if (option == 1)
		{
			check = 0;
			while (check != 1)
			{

				cout << "enter your account number to deposit money: " << endl;
				while (!(cin >> acc))
				{
					cout << "enter a valid account number: " << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}

				for (int i = 0; i < size3; i++)
				{
					if (acc == a[i].get_account_number())
					{
						z = i;
						check = 1;
						break;
					}
					else {
						check = 0;
					}
				}
				if (check == 0)
				{
					cout << "you have entered invaid account number:" << endl;
				}
			}
			if (check == 1)
			{
				resizet(t, size1);
				arr = regrow(arr, size2);
				arr[w++] = z;
				t[x].deposit_money(a[z]);
				InfoEntryOfAccount_onDeposit(a[z].get_account_number(),a[z],t[x]);
				x++;
				cout << "Press any key to continue" << endl;
				_getch();
				system("cls");
			}
		}
		if (option == 2)
		{
			check1 = 0;
			while (check1 != 1)
			{
				cout << "enter your account number to withdraw money: " << endl;
				while (!(cin >> acc))
				{
					cout << "enter a valid account number: " << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}

				for (int i = 0; i < size; i++)
				{
					if (acc == a[i].get_account_number())
					{
						q = i;
						check1 = 1;
						break;
					}
					else {
						check1 = 0;
					}
				}
				if (check1 == 0)
				{
					cout << "you have entered invaid account number:" << endl;
				}
			}
			if (check1 == 1)
			{
				resizet(t, size1);
				arr = regrow(arr, size2);
				arr[w++] = q;
				t[x].withdraw_money(a[q]);
				InfoEntryOfAccount_onWithdraw(a[q].get_account_number(), a[q], t[x]);
				x++;
				cout << "Press any key to continue" << endl;
				_getch();
				system("cls");
			}
		}
		if (option == 3)
		{
			check = 0;
			while (check != 1)
			{
				cout << "enter the account number you want to send money from: " << endl;
				while (!(cin >> acc))
				{
					cout << "enter a valid account number: " << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
				for (int i = 0; i < size; i++)
				{
					if (a[i].get_account_number() == acc)
					{
						z = i;
						check = 1;
						break;
					}
					else {
						check = 0;
					}
				}
				if (check == 0)
				{
					cout << "invalid account number: " << endl;
				}
			}
			if (check == 1)
			{
				arr = regrow(arr, size2);
				arr[w++] = z;
			}
			check1 = 0;
			while(check1!=1)
			{
				cout << "enter the account number you want to send money to: " << endl;
				while (!(cin >> acc1))
				{
					cout << "enter a valid account number: " << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
				for (int i = 0; i < size; i++)
				{
					if (a[i].get_account_number() == acc1)
					{
						q = i;
						check1 = 1;
						break;
					}
					else {
						check1 = 0;
					}
				}
				if (check1 == 0)
				{
					cout << "invalid account number" << endl;
				}
			}
			if ( check1 == 1)
			{
				arr = regrow(arr, size2);
				arr[w++] = q;
			}
			if (check == 1 && check1 == 1)
			{
				resizet(t, size1);
				t[x].transfer_money(a[z], a[q]);
				InfoEntryOfAccount_onTransfer(a[z].get_account_number(), a[q].get_account_number(), a[z], a[q], t[x]);
				x++;
				cout << "Press any key to continue" << endl;
				_getch();
				system("cls");
			}
		}
		for (int d = 0; d < size; d++)
		{
			EnterDataInAccount_atlast(a[d].get_account_number(), a[d]);
		}
		if (option == 4)
		{
			cout << "enter the account number to display information: " << endl;
			while (!(cin >> acc1))
			{
				cout << "enter a valid account number: " << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
			for (int i = 0; i < size; i++)
			{
				if(acc1==a[i].get_account_number())
				{
					a[i].display_only_account();
				}	
			}
			cout << "Press any key to continue" << endl;
			_getch();
			system("cls");
		}	
	}
}