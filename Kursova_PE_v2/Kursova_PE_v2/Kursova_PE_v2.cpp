
// Kursov proekt - Books system
// Created by Stefan Stanishev
// f.n: 123218001, 51.gr. 
// FKST, KSI
// TU-SOFIA 2020

#include <iostream>
#include <string>
#include <vector> 
#include <cstdlib>
#include <fstream>
#include <iterator>

#include "Bookseller.h"
#include "Book.h"
#include "Order.h"

using namespace std;

fstream bookFile, booksellerFile; // filles for book and bookseller

vector<Order> orders; // vector of orders that stores current orders made by user

//printing on the screen all the books from the base
bool booksFromBase() {
    bookFile.open("books.txt", fstream::in | fstream::out | fstream::app);
    string line;
    while (!bookFile.eof()) {

        getline(bookFile, line,  ' ');
        cout << line << " ";
    }
    bookFile.close();
    return true;
}

//printing on the screen al the bookseller available in the base
bool booksellersFromBase() {
    booksellerFile.open("booksellers.txt", fstream::in | fstream::out | fstream::app);
    string line;
    while (!booksellerFile.eof()) {
        getline(booksellerFile, line, '|');
        cout << line;
    }
    booksellerFile.close();
    return true;
}

//reading bookseller from the base and creating object of the chosen line
Bookseller readBSDataFromFile(int lineNumber) {
    Bookseller bS;
    booksellerFile.open("booksellers.txt", fstream::in | fstream::out | fstream::app);
    int currentLine = 0;
    string sLine = "|"; // delimiter for ending line

    string token; // string token for data
    
    while (currentLine != lineNumber && getline(booksellerFile, sLine)) {
        currentLine++;
    }
    if (currentLine == lineNumber) {
        
            getline(booksellerFile, token, ',');        // reading Name, Addres and Phone
            bS.setName(token);
            getline(booksellerFile, token, ',');
            bS.setAddress(token);
            getline(booksellerFile, token, '|');
            bS.setPhone(token);
        
        
    }
    
    booksellerFile.close();
    cout << "You chose: \n";
    cout << "Bookseller name: " << bS.getName() << "\n";    // writing on the screen chosed bookseller
    return bS;
}

//reading books from the base and creating object of the chosen book (line)
Book readBookDataFromFile(int lineNumber) {
    Book book;
    bookFile.open("books.txt", fstream::in | fstream::out | fstream::app);
    int currentLine = 0;
    string sLine = "|";

    string token;
   
    while (currentLine != lineNumber && getline(bookFile, sLine)) {
        currentLine++;
    }
    if (currentLine == lineNumber) {

        getline(bookFile, token, ',');
        book.setTitle(token);

        getline(bookFile, token, ',');
        book.setAuthor(token);

        getline(bookFile, token, ',');
        book.setEdition(token); // set Edition

        getline(bookFile, token, ',');
        book.setISBN(token); // set ISBN

        getline(bookFile, token, ',');
        book.setPrintDate(token);

        getline(bookFile, token, ',');
        book.setEditionDate(token);

        getline(bookFile, token, ',');
        book.setCertificateDate(token);

        getline(bookFile, token, ',');
        book.setQuantity(token);

        getline(bookFile, token, '|');
        book.setPrice(token);

    }


    bookFile.close();
    cout << "You chose: \n";
    cout << "Book title: " << book.getTitle() << "\n";
    cout << "Author: " << book.getAuthor() << "\n";
    return book;
}

//function for creating a book and storing it in the base
Book addBook() {
    string title, author, printDate, editionDate, certificateDate, edition, ISBN, quantity, price;
    Book book;

    cout << "# New Book\n";
    cout << "# Insert Book's Title:\n";
    getline(cin, title);
    book.setTitle(title);

    cout << "# Insert Book's Author:\n";
    getline(cin, author);
    book.setAuthor(author);

    cout << "# Insert Book's Edition:\n";
    getline(cin, edition); 
    book.setEdition(edition);

    cout << "# Insert Book's ISBN [XXXX-XXXX-XXXX]:\n";
    getline(cin, ISBN);
    book.setISBN(ISBN);

    cout << "# Insert Book's Print Date [DD/MM/YYYY]:\n";
    getline(cin, printDate);
    book.setPrintDate(printDate);

    cout << "# Insert Book's Edition Date [DD/MM/YYYY]:\n";
    getline(cin, editionDate);
    book.setEditionDate(editionDate);
 
    cout << "# Insert Book's Certificate Date [DD/MM/YYYY]:\n";
    getline(cin, certificateDate);
    book.setCertificateDate(certificateDate);

    cout << "# Insert Book's quantity: \n";
    getline(cin, quantity);
    book.setQuantity(quantity);

    cout << "# Insert Book's price: \n";
    getline(cin, price);
    book.setPrice(price);
    

    bookFile.open("books.txt", fstream::in | fstream::out | fstream::app);
    bookFile << book;
    bookFile.close();

    return book;

}

//creating a new bookseller
Bookseller addNewBookSeller() {
    string name, address, phone;
    Bookseller bS;

    cout << "# New Bookseller\n";
    cout << "# Insert Bookseller's name:\n";
    getline(cin, name);
    bS.setName(name);

    cout << "# Insert Bookseller's address:\n";
    getline(cin, address);
    bS.setAddress(address);

    cout << "# Insert Bookseller's phone:\n";
    getline(cin, phone);
    bS.setPhone(phone);

    booksellerFile.open("booksellers.txt", fstream::in | fstream::out | fstream::app);
    booksellerFile << bS;
    booksellerFile.close();

    return bS;
}


//function that creates a new book and stores it in the vector of books
vector<Book> makeOrder(vector<Book> b)
{
    b.push_back(addBook());

    return b;
}

//function that adds the book in the vector of books
vector<Book> makeOrder(vector<Book> books, Book book) {
    books.push_back(book);
    return books;
}

//Options called from MainMenu() for indepth chosing
void Options()
{
    int choice, selectedBook, selectedBS, booksPrice = 0;
    vector<Book> totalBooks;
    Bookseller bS;
    Book currentBook;


    do {
        cout << "________________________________________\n";
        cout << "Add a new Book or choose from the Base? |\n";
        cout << "- - - - - - - - - - - - - - - - - - - - |\n";
        cout << "Type 1 to create a new Book!            |\n";
        cout << "Type 2 to choose from the Base!         |\n";
        cout << "- - - - - - - - - - - - - - - -         |\n";
        cout << "Type 0 to continue your order!          |\n";
        cout << "________________________________________|\n";
        cout << "Your choice: ", cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush cin

        switch (choice) {
        case 1:         
            totalBooks = makeOrder(totalBooks); // creating a new book and storing it into the vector of total books
            break;
        case 2:
            cout << "\nCurrent Books in base!\n";
            cout << "- - - - - - - - - - - - - -\n";

            booksFromBase(); // listing all the available books from the base (file - books.txt)

            cout << "\nWhich one you choose?\n";
            cout << "Your choice: ", cin >> selectedBook;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush cin

            currentBook = readBookDataFromFile(selectedBook);

            totalBooks = makeOrder(totalBooks, currentBook); // storing book from the base into the vector
            break;
        }
    } while (choice != 0);
 
    do {
        cout << "_________________________________________________\n";
        cout << "Add a new Bookseller or choose from the Base?    |\n";
        cout << "- - - - - - - - - - - - - - - - - - - - - - - -  |\n";
        cout << "Type 1 to create a new Bookseller!               |\n";
        cout << "Type 2 to choose from the Base!                  |\n";
        cout << "_________________________________________________|\n";
        cout << "Your choice: ", cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush cin
        
        switch (choice) {
        case 1:
            bS = addNewBookSeller();
            break;
        case 2:
            booksellersFromBase(); // listing all the booksellers available from the base (file - booksellers.txt)
            cout << "\nWhich one you choose?\n";
            cin >> selectedBS;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush cin
            bS = readBSDataFromFile(selectedBS);
            break;
        }
    } while (choice != 1 && choice != 2);
    

    for (int i = 0; i < totalBooks.size(); i++) {
        int currentPrice = std::stoi(totalBooks[i].getPrice());
        booksPrice += currentPrice; //calculating the price from the all books

    }
    Order order(totalBooks, bS , booksPrice); // making a new order with total books, bookseller and a price of the order.
    orders.push_back(order);

}

// Main Menu for for dynamic data entry
void MainMenu() {
    int choice = 0, counter = 1; // counter for counting the Orders (starting from 1)

    do {
        cout << "\n____________________________________\n";
        cout << "# Main Menu                         |\n";
        cout << "____________________________________|\n";
        cout << "# Please make your selection        |\n";
        cout << "# 1 - Add a Bookseller              |\n";
        cout << "# 2 - Add a Book (Certificate also) |\n";
        cout << "____________________________________|\n";
        cout << "# 3 - See all Booksellers           |\n";
        cout << "# 4 - See all Books                 |\n";
        cout << "____________________________________|\n";
        cout << "# 5 - Make an Order                 |\n";
        cout << "# 6 - Order Info                    |\n";
        cout << "____________________________________|\n";
        cout << "# 9 - Quit                          |\n";
        cout << "____________________________________|\n";

        cout << "Your choice: ", cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush cin

        switch (choice)
        {
        case 1: addNewBookSeller();
            break;
        case 2: addBook();
            break;
        case 3:
            cout << "# Booksellers in base:\n";      
            booksellersFromBase();
            break;
        case 4:
            cout << "# Books in base:\n";
            booksFromBase();
            break;
        case 5:
            Options();
            break;

        case 6:      

            cout << "______________________________________________________________________________________________________________________ \n";
            for (Order order : orders) {
                cout <<"# Order #:"<< counter << "\n";
                cout << "______________________________________________________________________________________________________________________ \n";
                cout << "# Books ordered: \n";
                order.getBooks();
                         
                cout << "______________________________________________________________________________________________________________________ \n";
                cout << "# Chosen bookseller: \n";
                order.getBookSeller();
               
                cout << "______________________________________________________________________________________________________________________ \n";
                counter++;
            }     
            break;
        case 9: cout << "Goodbye!\n";
            break;
  
        default:
            break;
        }

    } while (choice != 9);

}

int main()
{
    MainMenu(); // calling MainMenu function

    system("PAUSE");
    return EXIT_SUCCESS;

}
