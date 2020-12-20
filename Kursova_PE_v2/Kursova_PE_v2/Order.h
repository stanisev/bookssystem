#pragma once
#include <vector>

#include "Book.h"
#include "Bookseller.h"


using namespace std;

class Order
{
private:
	vector<Book> books;
	Bookseller bookSeller;
	int price;

public:
	Order() {}
	Order(vector<Book> , Bookseller, int);
	void getBooks();
	void getBookSeller();
	~Order() {}
};

Order::Order(vector<Book> _books, Bookseller _bookSeller, int _price) {
	books = _books;
	bookSeller = _bookSeller;

	if (!(_price <= 0)) {
		price = _price;
	}
}
void Order::getBooks() {
	for (Book book : books) {
		cout << "Author" << " : " << book.getAuthor() << " | "
			<< "Title" << " : " << book.getTitle() << " | "
			<< "Edition" << " : " << book.getEdition() << " | "
			<< "ISBN" << " : " << book.getISBN() << " | "
			<< "Print Date" << " : " << book.getPrintDate() << " |\n"
			<< "Edition Date" << " : " << book.getEditionDate() << " |"
			<< "Certificate Date" << " : " << book.getCertificateDate() << " |"
			<< "Book's price" << " : " << book.getPrice() << " BGN" << "\n";
	}
}
void Order::getBookSeller() {
	cout << "Bookseller's name" << " : " << bookSeller.getName() << " | "
		<< "Bookseller's address" << " : " << bookSeller.getAddress() << " | "
		<< "Bookseller's phone" << " : " << bookSeller.getPhone() <<"\n"
		<< "Price to pay" << " : " << price << " BGN\n";

		
}