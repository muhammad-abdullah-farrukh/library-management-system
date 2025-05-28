#include<iostream>
#include <string>

using namespace std;

// record data type to store and present data of library
struct librarydata
{
    int bookserial;
    string bookname;
    string author;
    int remainingbooks;
    int IDlibrarian;
    string LibrarianName;
    int studentReg;
    string StudentName;
    string IssueDate;
    string Returndate;
};

// Function for the display menu of the library 
void Menu(const librarydata books[][5])
 {
    cout<<endl<<"Books that are avaliable: "<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Serial   Bookname                                    Author              Copies"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;

    for (int i = 0; i < 10; i++) 
	{
        bool flag = false;
    	int totalbooksremaining = 0;

        for (int j = 0; j < 5; j++) 
		{
			if (books[i][j].remainingbooks > 0) 
			{
            	 
				
                if (!flag) 
				{
                	cout<<books[i][j].bookserial<<"\t"<<books[i][j].bookname<<"\t"<<books[i][j].author<<"\t"<<books[i][j].remainingbooks<<endl;
                    flag = true;
                }

                totalbooksremaining += books[i][j].remainingbooks;
				
    		}
		}

        if (flag) 
		{
            cout<<"Remaining copies: "<<totalbooksremaining<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
        }
    }
}

// Function to convert a string to an integer
int strToint(const string& str) 
{
    int ans = 0;
    for (size_t i = 0; i < str.size(); ++i) 
	{
        ans = ans * 10 + (str[i] - '0');
    }
    return ans;
}

// Function to caluclate the fine which increases each day the user is late
int CalFine(const string& returnDate, const string& returndeadline) 
{
    const int fine = 10;
	int late;
	
    if (returnDate > returndeadline)// conditional statement to compare the dates
	{   
        late = strToint(string(1, returnDate[8])) - strToint(string(1, returndeadline[8])); // Calculate the number of days the book is late
        return fine * late; // Calculating and returing the fine
    }

    return 0; 
}


int main() 
{
    int indexOfBook;
	int choice;
	int fine;
	int IDlibrarian;
	char anotherchoice;
    int studentReg;
    string currentDate;
	string LibrarianName;
    string StudentName;
    
	librarydata books[10][5];
	//intialising all the books with the authors names, by using an array it makes it easier to resuse ahead
    string namesofbooks[10] = 
	{
        "War and Peace by Leo Tolstoy",
        "Moby Dick by Herman Melville",
        "One Hundred Years of Solitude by Gabriel Garcia Marquez",
        "Crime and Punishment by Fyodor Dostoyevsky",
        "King Lear by William Shakespeare",
        "The Odyssey by Homer",
        "Pride and Prejudice by Jane Austen",
        "The Divine Comedy by Dante Alighieri",
        "Classroom of the Elite",
        "No Longer Human"
    };

    string writer[10] = 
	{
        "Leo Tolstoy",
        "Herman Melville",
        "Gabriel Garcia Marquez",
        "Fyodor Dostoyevsky",
        "William Shakespeare",
        "Homer",
        "Jane Austen",
        "Dante Alighieri",
        "Author Unknown",
        "Osamu Dazai"
    };
	
    cout<<"Enter Librarian ID: ";
    cin>>IDlibrarian;
    cout<<"Enter Librarian Name: ";
    cin>>LibrarianName;
    cout<<"Enter Student ID: ";
    cin>>studentReg;
    cout<<"Enter Student Name: ";
    cin>>StudentName;
	cout<<endl;
   

    for (int i = 0; i < 10; i++) 
	{
        for (int j = 0; j < 5; j++) 
		{
			books[i][j].IDlibrarian = IDlibrarian; 
            books[i][j].LibrarianName = LibrarianName;
            books[i][j].studentReg = studentReg;
            books[i][j].StudentName = StudentName;
            books[i][j].bookserial = (i * 5) + j + 1;
            books[i][j].bookname = namesofbooks[i];
            books[i][j].author = writer[i];
            books[i][j].remainingbooks = 5;
            books[i][j].IssueDate = "2023-12-23";  
            books[i][j].Returndate = "2024-01-23";  
        }
    }

    while (true) {
        // ask the user if they want to issue a book, or return a book or neither
        cout<<"--------------------------------"<<endl;
        cout<<"press 1 to Issue a book"<<endl;
        cout<<"press 2 to Return a book"<<endl;
        cout<<"press 3 to Exit"<<endl;
		cout<<"--------------------------------"<<endl;
		
        cin>>choice;

        if (choice == 1) 
		{
            while (true)// loop to issue the book 
			{
                Menu(books);

                
                cout<<"Enter the serial number of the book u want to issue (or enter 0 to go back): ";
                cin>>indexOfBook;
                cout<<endl;

                if (indexOfBook == 0) 
				{
                    break; //break to bring user back to the main menu
                }

                if (indexOfBook >= 1 && indexOfBook <= 50 && books[(indexOfBook - 1) / 5][(indexOfBook - 1) % 5].remainingbooks > 0) 
				{
                    books[(indexOfBook - 1) / 5][(indexOfBook - 1) % 5].remainingbooks--;//issuing a book and decrementing the number of remaining books
                    books[(indexOfBook - 1) / 5][(indexOfBook - 1) % 5].IssueDate = "2023-12-23";//assuming that the day is 2023-12-23

                    cout<<"the book is issued on "<<books[(indexOfBook - 1) / 5][(indexOfBook - 1) % 5].IssueDate << endl;

                    cout<<"--------------------------------"<<endl;
					cout<<"Student ID: "<<studentReg<<endl;
                    cout<<"Student Name: "<<StudentName<<endl;
                    cout<<"--------------------------------"<<endl;
					cout<<"Librarian ID: "<<IDlibrarian<<endl;
                    cout<<"Librarian Name: "<<LibrarianName<<endl;
                    cout<<"--------------------------------"<<endl;
                } else
				{
                    cout<<"Either no copies are left or the serial number entered is incorrect"<<endl;
                    cout<<"--------------------------------------------------------"<<endl;
                }
                
                cout<<"Do you wish to issue another book? (y/n): ";//asking if the user wants to issue another book
                cin>>anotherchoice;
                cout<<endl;

                if (anotherchoice != 'y') 
				{
                    break;//returing user to the main menu if they do not wish to issue a new book
                }
            }
        } else if (choice == 2) 
		{
            while (true) 
			{
                Menu(books);//loop to return the books

                
                cout<<"Enter the serial number of the book u want to return (or enter 0 to go back): ";
                cin>>indexOfBook;
                cout<<endl;

                if (indexOfBook == 0)
				{
                    break;
                }

                if (indexOfBook >= 1 && indexOfBook <= 50 && books[(indexOfBook - 1) / 5][(indexOfBook - 1) % 5].remainingbooks < 5) 
				{
                    books[(indexOfBook - 1) / 5][(indexOfBook - 1) % 5].remainingbooks++;//returing a book and incrementing the number of remaining books
                    
                    cout<<"Enter the date today in the format (YYYY-MM-DD): ";
                    cin>>currentDate;
                    cout<<endl;

                    fine = CalFine(currentDate, books[(indexOfBook - 1) / 5][(indexOfBook - 1) % 5].Returndate);//calculating a fine
                    if (fine > 0) 
					{
                        cout<<"The book was returned late, kindly pay Fine of $"<<fine<<endl;//displaying the fine
                    } else //if book was returned on time
					{
                        cout<<"Book has been returned and on time"<<endl;
                        cout<<"Thank you"<<endl;
                    }
                    cout<<"--------------------------------"<<endl;
					cout<<"Student ID: "<<studentReg<<endl;
                    cout<<"Student Name: "<<StudentName<<endl;
                    cout<<"--------------------------------"<<endl;
					cout<<"Librarian ID: "<<IDlibrarian<<endl;
                    cout<<"Librarian Name: "<<LibrarianName<<endl;
                    cout<<"--------------------------------"<<endl;
                } else 
				{
                    cout<<"-------------------------------------------------------"<<endl;
					cout<<"Either no copies are left or the serial number entered is incorrect."<<endl;
					cout<<"------------------------------------------------------"<<endl;
                }
                
                cout<<"Do you wish to return another book? (y/n): ";//asking if the user wants to return another book
                cin>>anotherchoice;

                if (anotherchoice != 'y') 
				{
                    break;//puuling the user back to the main menu if they dont wish to return the book
                }
            }
        } else if (choice == 3) 
		{
            break;//if user wishes to exit the program we break the intial loop
        } else 
		{
            cout<<"--------------------------------------------"<<endl;
			cout<<"Invalid option."<<endl;
			cout<<"--------------------------------------------"<<endl;
        }
    }
}//end of code
