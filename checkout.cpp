// Jason Mora-Mendoza
// Section 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}

void readBooks(vector<Book *> & myBooks)
{
	int id;
	string title, author, category, discard;
	ifstream file("books.txt");
	
	if(file.is_open())
	{
		while(file>>id)
		{
			cout<<id<<endl;
			getline(file, discard);
			getline(file, title);
			cout<<title<<endl;
			getline(file, author);
			cout<<author<<endl;
			getline(file, category);
			cout<<category<<endl<<endl;
		}
	}
	file.close();
}

int readPersons(vector<Person *> & myCardholders)
{
    int cardNo;
    bool act;
    string firstName, lastName;
    ifstream file("persons.txt");
    
    if(file.is_open())
    {
    	while(file>>cardNo>>act>>firstName>>lastName)
    	{
    		cout<<cardNo<<" "<<act<<" "<<firstName<<" "<<lastName<<endl;
    	}
    }
    file.close();
}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders)
{
	int id, cardNo;
	ifstream file("rentals.txt");
	
	if(file.is_open())
	{
		while(file>>id>>cardNo)
		{
			cout<<id<<" "<<cardNo<<endl;
		}
	}
	file.close();
}

/*void openCard(vector<Person *> & myCardholders, int nextID)
{
    return;
}

Book * searchBook(vector<Book *> myBooks, int id)
{
    return nullptr;
}*/

int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;
    
    cout<<"---READING 'books.txt'---"<<endl<<endl;
    readBooks(books);
    cout<<endl<<"---READING 'persons.txt'---"<<endl<<endl;
    readPersons(cardholders);
    cout<<endl<<"---READING 'rentals.txt'---"<<endl<<endl;
    readRentals(books, cardholders);
    
    /*int choice;
    do
    {
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that 
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                // Book checkout
                break;

            case 2:
                // Book return
                break;

            case 3:
                // View all available books
                break;

            case 4:
                // View all outstanding rentals
                break;

            case 5:
                // View outstanding rentals for a cardholder
                break;

            case 6:
                // Open new library card
                break;

            case 7:
                // Close library card
                break;
                
            case 8:
                // Must update records in files here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);*/
   
   cin.get();
   return 0;
}
