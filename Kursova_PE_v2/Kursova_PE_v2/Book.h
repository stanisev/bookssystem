#pragma once
#include <string>
#include <regex>

using namespace std;

class Book
{
private:
	string title;
	string author;
	string edition;
	string ISBN;
	string printDate, editionDate, certificateDate;
	string quantity, price;

public:
	Book();
	Book(string, string, string, string, string, string, string, string, string);

	void setTitle(string);
	string getTitle();

	void setAuthor(string);
	string getAuthor();

	void setEdition(string);
	string getEdition();

	void setISBN(string);
	string getISBN();

	void setPrintDate(string);
	string getPrintDate();

	void setEditionDate(string);
	string getEditionDate();

	void setCertificateDate(string);
	string getCertificateDate();

	void setQuantity(string);
	string getQuantity();

	void setPrice(string);
	string getPrice();

	bool validateDate(string);

	~Book() {}

	friend ostream& operator << (ostream& out, const Book& obj)
	{
		out << obj.title << "," << obj.author << "," << obj.edition << "," << 
			obj.ISBN << "," << obj.printDate << "," << obj.editionDate << ","<< obj.certificateDate
			<< "," << obj.quantity << "," << obj.price <<"|"<<endl;
		return out;
	}
	friend istream& operator >> (istream& in, Book& obj)
	{
		in >> obj.title;
		in >> obj.author;
		in >> obj.edition;
		in >> obj.ISBN;
		in >> obj.printDate;
		in >> obj.editionDate;
		in >> obj.certificateDate;
		in >> obj.quantity;
		in >> obj.price;
		return in;
	}

};
Book::Book(){}

Book::Book(string _title, string _author, string _edition, string _ISBN, string _printDate, string _editionDate, string _certificateDate, string _quantity, string _price)
{
	setTitle(_title);
	setAuthor(_author);
	setEdition(_edition);
	setISBN(_ISBN);
	setPrintDate(_printDate);
	setEditionDate(_editionDate);
	setCertificateDate(_certificateDate);
	setQuantity(_quantity);
	setPrice(_price);
}

void Book::setTitle(string _title) {
	title = _title;
}

string Book::getTitle() {
	return title;
}

void Book::setAuthor(string _author) {
	author = _author;
}
string Book::getAuthor() {
	return author;
}

void Book::setEdition(string _edition) {	
	edition = _edition;
}
string Book::getEdition() {
	return edition;
}

void Book::setISBN(string _ISBN) {
	ISBN = _ISBN;
}
string Book::getISBN() {
	return ISBN;
}

void Book::setPrintDate(string _printDate) {
	if (validateDate(_printDate)) {
		printDate = _printDate;
	}
	else {
		cout << "Please enter a valid format!";
		abort();
	}
}
string Book::getPrintDate() {
	return printDate;
}

void Book::setEditionDate(string _editionDate) {
	if (validateDate(_editionDate)) {
		editionDate = _editionDate;
	}
	else {
		cout << "Please enter a valid format!";
		abort();
	}
}
string Book::getEditionDate() {
	return editionDate;
}

void Book::setCertificateDate(string _certificateDate) {
	if (validateDate(_certificateDate)) {
		certificateDate = _certificateDate;
	}
	else {
		cout << "Please enter a valid format!";
		abort();
	}
}
string Book::getCertificateDate() {
	return certificateDate;
}

void Book::setQuantity(string _quantity) {

	int quantityInt = std::stoi(_quantity);
	if (quantityInt <= 0) {
		quantity = "0";
	}
	else {
		quantity = _quantity;
	}

}

string Book::getQuantity() {
	return quantity;
}

void Book::setPrice(string _price) {
	int priceInt = std::stoi(_price);
	if (priceInt <= 0) {
		price = "0";
	}
	else {
		price = _price;
	}
}

string Book::getPrice() {
	return price;
}

bool Book::validateDate(string input) {
	std::regex r("\\b\\d{2}[/]\\d{2}[/]\\d{4}\\b"); //regex for DD/MM/YYYY format
	return std::regex_match(input, r);

}