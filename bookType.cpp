#include <iostream>
#include <string>
#include <iomanip>
#include "bookType.h"

//bookType.cpp, the implementation file

//default constructor 
bookType::bookType()
{
}

//destructor
bookType::~bookType()
{
}

//mutator function to set book information, takes in parameters for all the private variables and assinges them to the coressponding private variable
void bookType::setBookInfo(string title, string ISBN, string Publisher, int PublishYear, string auth[], double cost, int copies, int authorCount)
{
	//define iterator variable
	int i;

	//set all private variables to parameters
	book_title = title;
	ISBN_num = ISBN;
	Publisher_name = Publisher;
	Publish_Year = PublishYear;
	//step through the author array up to the number of authors listed
	for (i = 0; i < authorCount; i++)
		author[i] = auth[i];
	price = cost;
	num_copies = copies;
	author_Count = authorCount;

}

//accessor function to output the information of a book, outputs information only
void bookType::printInfo() const
{
	//define iterator variable
	int i;
	//set decimal points for output appropriate to represent money
	cout << fixed << showpoint;
	cout << setprecision(2);
	//user output of all the book information
	cout << "Title: " << book_title << endl;
	cout << "ISBN Number: " << ISBN_num << endl;
	cout << "Publisher Name: " << Publisher_name << endl;
	cout << "Publish Year: " << Publish_Year << endl;
	cout << "Author(s): " << endl;
	for (i = 0; i < author_Count; i++)
		cout << author[i] << endl;
	cout << "Price: $" << price << endl;
	cout << "Number of Copies available: " << num_copies << endl;
	cout << "Number of Authors: " << author_Count << endl;
}

//accessor function to output only the book title
void bookType::printbookTitle() const
{
	//user output of the title
	cout << "Title: " << book_title << endl;
}

//accessor function to output both the book title and ISBN number
void bookType::printbookTitleAndISBN() const
{
	//user output of the data
	cout << "Title: " << book_title << ";     ";
	cout << "ISBN: " << ISBN_num << endl;
}

//accessor function to check the parameter with the ISBN private variable
bool bookType::isISBN(string ISBN) const
{
	//compare input parameter with ISBN private variable, if the same return true
	if (ISBN == ISBN_num)
		return true;
}

//accessor function to check the parameter with the Book Title private variable
bool bookType::isTitle(string title) const
{
	//compare input parameter with Book Title private variable, if the same return true
	if (title == book_title)
		return true;
}

//mutator function to update the quanity of the book in stock
void bookType::updateQuantity(int& count)
{
	//set the number of copies private variable equal to the new amount that has been passed from parameter
	num_copies = count;
}