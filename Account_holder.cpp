#include "Account_holder.h"
Account_holder::Account_holder()
{
	ZIP = 0;
}
Account_holder::Account_holder(string name, string CNIC, string city, string block, string house, string street, string country, int ZIP, string income_s, Account acc)
{
	this->name = name;
	this->CNIC = CNIC;
	this->city = city;
	this->block = block;
	this->house = house;
	this->street = street;
	this->country = country;
	this->ZIP = ZIP;
	this->income_s = income_s;
	this->acc = acc;
}
void Account_holder::set_account_holder_data()
{
	cout << "enter the name of the account holder: " << endl;
	getline(cin, name);
	cout << "enter your national identity number: " << endl;
	getline(cin, CNIC);
	cout << "enter your house number: " << endl;
	cin >> house;
	cout << "enter your street number: " << endl;
	cin >> street;
	cout << "enter your block number: " << endl;
	cin >> block;
	cout << "enter your city: " << endl;
	cin >> city;
	cout << "enter your country: " << endl;
	cin >> country;
	cout << "enter your ZIP code: " << endl;
	while (!(cin >> ZIP))
	{
		cout << "enter a valid ZIP code: " << endl;
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();
	cout << "enter your source of income: " << endl;
	getline(cin, income_s);
}
void Account_holder::set_account_data()
{
	acc.set_account_data();
}
string Account_holder::get_name()
{
	return name;
}
string Account_holder::get_CNIC()
{
	return CNIC;
}
string Account_holder::get_house()
{
	return house;
}
string Account_holder::get_block()
{
	return block;
}
string Account_holder::get_street()
{
	return street;
}
string Account_holder::get_city()
{
	return city;
}
string Account_holder::get_country()
{
	return country;
}
int Account_holder::get_ZIP()
{
	return ZIP;
}
string Account_holder::get_income_s()
{
	return income_s;
}
void Account_holder::display()
{
	acc.display();
	cout << "--- --- --- --- --- --- --- --- --- --- --- ---" << endl;
	cout << "the account holder details are: " << endl;
	cout << "name: " << name << endl;
	cout << "CNIC: " << CNIC << endl;
	cout << "house number: "<<house << endl;
	cout << "street number: " << street << endl;
	cout << "block: " << block << endl;
	cout << "city: " << city << endl;
	cout << "country: " << country << endl;
	cout << "ZIP: " << ZIP << endl;
	cout << "source of income: " << income_s << endl;
}