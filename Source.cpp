#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include "Header.h"
#include <conio.h>
using namespace std;
//Function to draw line
void drawLine(char ch) {
	for (int i = 1; i < 80; i++)
		cout << ch;
	cout << endl;
}

int main() {
//Labelled 1 so that later on control can be shifted
	//Counter1 is gloabal counter for users
	//Counter2 is global counter for books
	int x = 0, count1 = 0, count2 = 0;
	//dynamic arrays
	User* users = new User[20];
	Book* books = new Book[50];
	system("COLOR 5F");
	drawLine('+');
	cout << "\t\tW E L C O M E   T O   K I N G S T O N   L I B R A R Y \n";
	drawLine('+');
	system("pause");
label1:
	system("CLS");
	system("COLOR 8E");
	cout << "Enter 1 for Admin Login: " << endl;
	cout << "Enter 2 for User Login: " << endl;
	cout << "Enter -1 to exit: " << endl;
	cin >> x;
	//Loop to keep program running
	while (x != -1) {
		if (x == 1) {
			system("COLOR 8F");
			x = 0;
			Admin obj;
			if (obj.AdminLogin() != 0) {
				return 1;
				break;
			}
			else {
			//Label 2 for control to return	
			label2:
				int a = -1;
				system("CLS");
				cout << "Enter 1 to add users" << endl;
				cout << "Enter 2 to add Books" << endl;
				cout << "Enter 3 to view Book List" << endl;
				cout << "Enter 4 to show users that have a Library membership" << endl;
				cout << "Enter 5 to view borrow record" << endl;
				cout << "Enter 6 to view return record" << endl;
				cout << "Enter 0 to go back: ";
				while (a != 0) {

					cin >> a;
					if (a == 0) {
						goto label1;
					}
					if (a == 1) {

						if (users[count1].AddUser() == 0) {
							cout << "User added successfully" << endl;
							count1++;
							system("pause");
							goto label2;

						}
						else {
							return 2;
							break;
						}


					}
					else if (a == 2) {
						if (books[count2].AddBooks() == 0) {
							cout << "Book Added Successfully!" << endl;
							books[count2].print();
							count2++;
							system("pause");
							goto label2;
						}
						else {
							return 3;
							break;
						}

					}
					else if (a == 3) {
						cout << "Showing books available: " << endl;
						books->readData();
						system("pause");
						goto label2;

					}
					else if (a == 4) {
						cout << "Showing lst of registered users: " << endl;
						for (int x = 0; x < count1; x++) {
							users[x].ShowUsers();
						}
						system("pause");
						goto label2;

					}
					else if (a == 5) {
						users->borrowrec();
						system("pause");
						goto label2;
					}
					else if (a == 6) {
						users->returnrec();
						system("pause");
						goto label2;
					}


				}
			}
		}
		if (x == 2) {
			system("CLS");
			system("COLOR 0A");
			User temp;
			int x;
			temp.Name = temp.UserLogin(users, count1);
			if (temp.Name == "1") {
				return 4;
				break;
			}
			else {
			label3:
				system("CLS");
				cout << "Enter 1 to view books available: " << endl;
				cout << "Enter 2 to borrow a book: " << endl;
				cout << "Enter 3 to return a book: " << endl;
				cin >> x;
				if (x == 1) {
					cout << "Showing books available: " << endl;
					books->readData();
					system("pause");
					goto label3;

				}
				else if (x == 2) {

					//for (int x = 0; x < count2; x++) {
					//	cout << x + 1 << " ";
					//	books[x].ShowBooks();
					//}
					temp.BorrowBooks(books, temp);
					cout << "Book Borrowed" << endl;
					system("pause");
					goto label3;

				}
				else if (x == 3) {
					temp.returnbk(books, count2);
					goto label3;
				}
			}

		}
	}

}