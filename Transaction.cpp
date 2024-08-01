#include "Transaction.h"
#include <cstdlib>
#include <chrono>
#include <ctime>
int Transaction::number = 0;
Transaction::Transaction()
{
	number++;
	id = rand();
	changed = 0;
	number1 = 0;
}
Transaction::Transaction(int id, double changed,int number1)
{
	this->id = id;
	this->changed = changed;
	this->number1 = number1;
}
void Transaction::set_transaction_data()
{
	id = rand();
	auto start = chrono::system_clock::now();
	auto legacyStart = chrono::system_clock::to_time_t(start);
	y = ctime(&legacyStart);
}
int Transaction::get_id()
{
	return id;
}
double Transaction::get_changed()
{
	return changed;
}
int Transaction::get_no_of_transactions()
{
	return number1;
}
void Transaction::set_transaction_time()
{
	auto start = chrono::system_clock::now();
	auto legacyStart = chrono::system_clock::to_time_t(start);
	y=ctime(&legacyStart);
	//cout << "the time of your transaction is: " << ctime(&legacyStart) << '\n';
}
string Transaction::get_time()
{
	return y;
}
void Transaction::display()
{
	cout << "the transation id: " << id << endl;
	cout << "the transaction time is: " << y << endl;
}

