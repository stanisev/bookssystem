#pragma once
#include <string>
#include <regex>
#include <sstream>

using namespace std;

class Bookseller
{
private:
	string name;
	string address;
	string phone;
public:
	Bookseller();
	Bookseller(string, string, string);

	void setName(string);
	string getName();

	void setAddress(string);
	string getAddress();

	void setPhone(string);
	string getPhone();

	bool isNumber(string);

	~Bookseller() {}

	friend ostream& operator << (ostream& out, const Bookseller& obj)
	{
		out << obj.name << ", " << obj.address << ", " << obj.phone <<"|"<< endl;
			
		return out;
	}
	friend istream& operator >> (istream& in, Bookseller& obj)
	{
		in >> obj.name;
		in >> obj.address;
		in >> obj.phone;

		return in;
	}


};

Bookseller::Bookseller() {

	
}

Bookseller::Bookseller(string _name, string _address, string _phone) {
	setName(_name);
	setAddress(_address);
	setPhone(_phone);
	
}

void Bookseller::setName(string _name) {
	name = _name;
}
string Bookseller::getName() {
	return name;
}

void Bookseller::setAddress(string _address) {
	address = _address;
}
string Bookseller::getAddress() {
	return address;
}

void Bookseller::setPhone(string _phone) {
	int number = std::stoi(_phone);
	if (number < 0) {
		phone = "000000000";
	}
	else {
		phone = _phone;
	}
	
}
string Bookseller::getPhone() {
	return phone;
}

bool Bookseller::isNumber(string str) {
	stringstream ss;
	ss << str;
	string temp;
	int found;
	while (!ss.eof()) {
		ss >> temp;
		if (istringstream(temp) >> found)
		{
			return true;
		}
		else {
			return false;
		}
		}
	return false;
	}

