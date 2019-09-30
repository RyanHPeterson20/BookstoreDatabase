//Ryan Peterson
//Professor William Clements
//CSC 160 Comp Sci I
//04 August, 2018

//Analysis:
//Develop a class for a book store's database of books that includes the ability to hold the title, author, publisher, etc and enables the client program the ability
// to update the quantity to in stock and search by book title or ISBN number.
//The data will be input from a .txt file that has the data from various books in stock, includes the book title, author, publisher, year of publishing, ISBN number,
// price, and number of copies in stock
//The output should depend upon the selection by the user from a menu but typically includes the previously stated data in its entirety. Output will be in the main
// text of the running executable program

//Algorithm:
//The client (main) program solution was provided
//Create class book Type with header and cpp file for the class functions
//Define the header into public and private
//Public function prototypes should include a setbook mutator function that takes in all variables, print information accessor function, print book title accessor function, 
// print title and ISBN accessor function, a check ISBN accessor function that has an ISBN string parameter, a check book title accessor function that has a book title string 
// parameter, an update quantity mutator function that takes in an amount integer parameter, and a default constructor and destructor functions.
//Private variable should include the data variables in analysis, which are: book title, ISBN Number, Publisher Name, Publish Year, Authors, Price, Number of Copies, and
// number of authors
//The header file should include all ADT information for client program user with postcondition descriptions for all public functions.
//The book type implementation file should contain all function definitions
//Create function class default constructor and destructor
//Define mutator function for set book information, parameters should match all variables defined in the private header
//-Function sets all parameter inputs with coresponding private variable, the author variable is an array so array will need to be initialize with appropriate for loop
//Define accesor function to print out all relevent information regarding the book type 
//-Outputs to the end-user all information regarding the book from the private variables in a readable format
//Define accessor function to print out only the book title
//-Outputs to the end-user only the book title
//Define accessor function to print out both the book title and ISBN number
//-Outputs both the book title and ISBN number from the private variables
//Define accessor bool function to take in a string for an ISBN number as parameter
//-Compare the input parameter with the string ISBN from the private variables, if they are the same return true
//Define accessor bool function to take in a string for a Book Title as parameter
//-Compare the input parameter with the book title variable and if they are the same reutrn true.
//Define mutator function that takes in an integer parameter of a new quantity
//-Set the number of books equal to the parameter of the new quantity of books
//Ensure that the post conditions in the header file match the actual outputs and conditions of the functions

//User Documentation:
////Enter all desired book data to: bookData.txt
//Open the program from either the file system or by searching for CSC160_Prog_CH10_1.1.exe or by searching for the file. Once found double click on CSC160_Prog_CH10_1.1.exe to run program.
//Program runs user main menu, where user has 5 options to view or manipulate data. 
//Option 1: Print a list of books
//Option 2: Print a list of books and ISBN numbers
//Option 3: To see if a book in store
//- Gives sub menu for search by Book Title or ISBN
//Option 4: To update the number of copies of a book
//- Gives sub menu for search by Book Title or ISBN
//Option 5: To print books data
//Option 9 to exit program.
//To terminate the file either press 9 then enter to exit menu or by pressing the x in the top right corner of the window.

//header
#include <iostream>
#include <string>
#include <fstream>
#include "bookType.h"

using namespace std;
//fucntion prototypes for client
void getBookData(bookType books[], int& noOfBooks);
void printBookData(bookType books[], int noOfBooks);
void searchBookData(bookType books[], int bookCount);
void searchBookDataByISBN(bookType books[], int bookCount, string ISBN, int& loc);
void searchBookDataByTitle(bookType books[], int bookCount, string title, int& loc);
void updateCopiesInStock(bookType books[], int bookCount);
void showMenu();
void subMenu();

int main()
{
	//constructor for class objects, sets array size of 100 potential objects
	bookType books[100];
	//variable definition
	int numberOfBooks = 0;

	int choice;

	int i;
	//function to get data from txt file and input into class object, needs to be done first so the array is initialized.
	getBookData(books, numberOfBooks);
	//user interface menu
	showMenu();
	cin >> choice;
	//loop to keep running the main menu choices
	while (choice != 9)
	{
		//switch statement from main menu options
		switch (choice)
		{
		case 1:
			//call class function to print book title
			for (i = 0; i <numberOfBooks; i++)
				books[i].printbookTitle();
			cout << endl;
			break;
		case 2:
			//call class function to print out book title and isbn number
			for (i = 0; i <numberOfBooks; i++)
				books[i].printbookTitleAndISBN();
			cout << endl;
			break;
		case 3:
			//call function to search book data
			searchBookData(books, numberOfBooks);
			break;
		case 4:
			//call function to update the stock for a specific book
			updateCopiesInStock(books, numberOfBooks);
			break;
		case 5:
			//call function to output all book information
			printBookData(books, numberOfBooks);
			break;
		default:
			cout << "Invalid selection." << endl;
		}

		showMenu();
		cin >> choice;
	}

	return 0;
}
//function to get book data from input file and pass it to the class object function
void getBookData(bookType books[], int& noOfBooks)
{
	//define variables for all the data
	string title;
	string ISBN;
	string Publisher;
	int PublishYear;
	string auth[4];
	double cost;
	int copies;
	int authorCount;
	//define iterators
	int i, j;
	//define file name
	ifstream infile;
	char ch;
	//open input file
	infile.open("bookData.txt");
	//check infile 
	if (!infile)
	{
		cout << "Cannot open Input file" << endl;
		cout << "Exit the program" << endl;
		return;
	}
	//data from input file for total number of books in file
	infile >> noOfBooks;
	infile.get(ch);
	//loop through all books setting input stream to the previously defined data variables
	for (i = 0; i < noOfBooks; i++)
	{
		getline(infile, title);
		getline(infile, ISBN);
		getline(infile, Publisher);
		infile >> PublishYear >> cost >> copies >> authorCount;
		infile.get(ch);
		//loop through all the authors
		for (j = 0; j < authorCount; j++)
			getline(infile, auth[j]);
		//pass all the data to the class function for setting all book informtion
		books[i].setBookInfo(title, ISBN, Publisher,
			PublishYear, auth, cost, copies,
			authorCount);
	}
}
//function to output the book data
void printBookData(bookType books[], int noOfBooks)
{
	//define iterator variable
	int i;
	//step through all the books and call the class function for printing all book data
	for (i = 0; i < noOfBooks; i++)
	{
		books[i].printInfo();
		cout << endl << "---------------------------------" << endl;
	}
}
//function to search by ISBN number
void searchBookDataByISBN(bookType books[], int bookCount, string ISBN,
	int& loc)
{
	//define iterator variable
	int i;
	//set location
	loc = -1;
	//For loop that steps through all books and checks the passed ISBN number in the class function of isISBN
	for (i = 0; i < bookCount; i++)
		if (books[i].isISBN(ISBN))
		{
			loc = i;
			break;
		}
}
//function to search by book title
void searchBookDataByTitle(bookType books[], int bookCount, string title,
	int& loc)
{
	//define iterator variable
	int i;
	loc = -1;
	//loop to step through all books and checks for the passed book title in the isTitle class function
	for (i = 0; i < bookCount; i++)
		if (books[i].isTitle(title))
		{
			loc = i;
			break;
		}
}
//function to search for book information based on criteria
void searchBookData(bookType books[], int bookCount)
{
	//define variables
	int choice;
	char ch;

	int loc;

	string str;
	//call submenu function to display that menu
	subMenu();
	//get user input
	cin >> choice;
	cin.get(ch);
	//switch statement to either search by ISBN or Book Title
	switch (choice)
	{
	case 1:
		//get user input and call and pass that input to the search by ISBN function
		cout << "Enter the ISBN of the book." << endl;
		getline(cin, str);
		searchBookDataByISBN(books, bookCount, str, loc);
		if (loc != -1)
			cout << "The store sells this book." << endl;
		else
			cout << "The store does not sell this book" << endl;
		break;
	case 2:
		//get user input and call adn pass the input to the search by book title function
		cout << "Enter the title of the book." << endl;
		getline(cin, str);
		searchBookDataByTitle(books, bookCount, str, loc);
		if (loc != -1)
			cout << "The store sells this book." << endl;
		else
			cout << "The store does not sell this book" << endl;
		break;
	default:
		cout << "Invalid choice" << endl;
	}
}
//function to update the quantity of a book in stock
void updateCopiesInStock(bookType books[], int bookCount)
{
	//define variables
	int choice;

	int loc;

	int count;
	char ch;

	string str;
	//display submenu by calling it and get user input
	subMenu();
	cin >> choice;
	cin.get(ch);
	//switch statement from user input
	switch (choice)
	{
	case 1:
		//search by ISBN number to find what book to update
		cout << "Enter the ISBN of the book." << endl;
		getline(cin, str);
		searchBookDataByISBN(books, bookCount, str, loc);
		if (loc != -1)
		{
			cout << "Enter the number of books: ";
			cin >> count;
			cout << endl;
			//call class function to update quantity and pass new quantity to it
			books[loc].updateQuantity(count);
		}
		else
			cout << "The store does not sell this book: " << endl;
		break;
	case 2:
		//search by book title
		cout << "Enter the title of the book." << endl;
		getline(cin, str);
		searchBookDataByTitle(books, bookCount, str, loc);
		if (loc != -1)
		{
			cout << "Enter the number of books";
			cin >> count;
			cout << endl;
			//call class function to update the quantity in sotck and pass new quantity to it
			books[loc].updateQuantity(count);
		}
		else
			cout << "The store does not sell this book" << endl;
		break;
	default:
		cout << "Invalid choice" << endl;
	}
}
//function to display main menu for user choices
void showMenu()
{
	cout << "Welcome to Rock's Book Store" << endl;
	cout << "To make a selection enter the number and press enter"
		<< endl;
	cout << "1: Print a list of books" << endl;
	cout << "2: Print a list of books and ISBN numbers" << endl;
	cout << "3: To see if a book in store" << endl;
	cout << "4: To update the number of copies of a book" << endl;
	cout << "5: To print books data" << endl;
	cout << "9: Exit the program." << endl;
}
//function submenu that allows for lower menu operations of search by ISBN or Book Title
void subMenu()
{
	cout << "Enter" << endl;
	cout << "1: To search the book by ISBN" << endl;
	cout << "2: To search the book by title" << endl;
}