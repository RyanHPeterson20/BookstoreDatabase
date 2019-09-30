#include <string>

using namespace std;

//bookType.h, is the specification file for class bookType

class bookType
{
public:

	void setBookInfo(string title, string ISBN, string Publisher, int PublishYear, string auth[], double cost, int copies, int authorCount);
	//Function to set information for a book.
	//The information regarding a book is set per the parameters listed.
	//Postcondition:  	book_title = title; ISBN_num = ISBN; Publisher_name = Publisher; Publish_Year = PublishYear; author[4] = auth[];
	//                  price = cost; num_copies = copies; author_Count = authorCount
	void printInfo() const;
	//Function to output all information regarding a book
	//Postcondition:    Outputs all information in the following order:
	//                  Title: "book_title"
	//                  ISBN Number: "ISBN_num"
	//                  Publisher Name: "Publisher_name"
	//                  Publish Year:  "Publish_Year"
	//					Author(s): 
	//					"author[s]" 
	//					Price: "price"
	//					Number of Copies available: "num_copies"
	//					Number of Authors: "author_Count"
	void printbookTitle() const;
	//Function to output only the title of the book
	//Postcondition:	Outputs the book title as follows:
	//					Title: "book_title"
	void printbookTitleAndISBN() const;
	//Function to output both the title and ISBN number of the book
	//Postcondition:	Outputs the book title and ISBN number as follows:
	//					Title: "book_title";     ISBN: "ISBN_num"
	bool isISBN(string ISBN) const;
	//Function to compare inputed ISBN number with private ISBN number and if they are the same output true condition
	//Postcondition:	Outputs true bool condition
	bool isTitle(string title) const;
	//Function to compare inputed book title with private book title and if they are the same output true condition
	//Postcondition:	Outputs true bool condition
	void updateQuantity(int& count);
	//Function to update the quantity of a book in stock
	//Postcondition:	The quantity of a book in stock is adjusted to the parameter passed to the function
	bookType();
	//Default Constructor, all values set to zero or null
	~bookType();
	//Default destructor

private:
	//private variables
	string book_title; //variable to store the book title
	string ISBN_num; //stores the ISBN number
	string Publisher_name; //stores publisher name
	int Publish_Year; //stores the year the book was published
	string author[4]; //stores up to 4 authors
	double price; //stores price of the book
	int num_copies; //stores the quantity of the book in stock
	int author_Count;  //stores the number of authors of the book
};