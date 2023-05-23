#include "Header.h"
#include <string>
#include <fstream>

ofstream out;
ofstream out3;
ifstream in;

int Admin::AdminLogin()
{

	string in;
	string p;
	cout << "Enter Admin Name: ";
	cin >> in;
	if (in == AdminName) {
		cout << "Enter Password: ";
		cin >> p;
		if (p == Password) {
			return 0;
		}
		else {
			cout << "Incorrect Password" << endl;
			return 2;

		}
	}
	else {
		cout << "Incorrect Name";
		return 1;
	}
	return 0;
	
}

int User::UserCount = 0;
int Book::BookCount = 0;

int User::AddUser()
{
	if (UserCount > 20) {
		return 1;
	}
	cout << "Enter Username: ";
	cin >> UserName;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter User Password: ";
	cin >> Password;
	UserCount++;
	return 0;

}

int Book::AddBooks()
{
	if (BookCount > 50) {
		return 1;
	}
	cout << "Enter Book Name: ";
	cin >> Name;
	cout << "Enter the Author's name: ";
	cin >> Author ;
	cout << "Available copies?";
	cin >> Copies_avail;
	BookCount++;
	return 0;
}


void Book::print()
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	out.open("Records.txt", ios::app);
	out3.open("Bk.txt", ios::app);
	out << Name << " by " << Author << endl;
	out3 << Name << " by " << Author << endl;
	out << "Available Copies: ";
	out << Copies_avail << endl;
	out << "Date Added:  " << endl;
	out << str << endl;
	out.close();
}

Book::Book()
{
	Name = "\0";
	Author = "\0";
	Copies_avail = 0;
}

void Book::ShowBooks()
{
	cout << "Available books: ";
	cout << Name << " by " << Author << endl;
	cout << "Available Copies: " << Copies_avail << endl;
	
}

void Book::readData()
{
	string read;
	in.open("Records.txt");
	while (!in.eof()) {
		getline(in, read);
		cout << read << endl;
	}
	in.close();
	
}

void User::ShowUsers()
{
	
	cout << UserName << endl;

}

void User::print(Book arr[],int x)
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	out.open("Borrow_Record.txt", ios::app);
	out << arr[x].Name << " by " << arr[x].Author << endl;
	out << "Date Borrowed:  " << endl;
	out << str << endl;
	out << "Borrowed By " << UserName << endl;
	out << endl;
	out.close();
}

void User::returnbk(Book arr[],int size)
{
	int ch;
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);

	for (int i = 0; i < size; i++) {
		cout << i + 1;
		arr[i].ShowBooks();
	}
	cout << "Which Book do you want to return?";
	cin >> ch;
	
	out.open("Returned_rec.txt", ios::app);
	out << arr[ch-1].Name << " by " << arr[ch-1].Author << endl;
	out << "Return Date  " << endl;
	out << str << endl;
	out << "Date Returned:  " << endl;
	out << str << endl;
	out << "Returned By " << UserName << endl;
	arr[ch - 2].Copies_avail++;
	out.close();
	
	
}
//Prints to a borrow record file
void User::borrowrec()
{
	string read;
	in.open("Borrow_Record.txt");
	while (!in.eof()) {
		getline(in, read);
		cout << read << endl;
	}
	in.close();
}
//Reads the record
void User::returnrec()
{
	string read;
	in.open("Returned_rec.txt");
	while (!in.eof()) {
		getline(in, read);
		cout << read << endl;
	}
	in.close();

}

string User::UserLogin(User arr[],int si)
{
	
	cout << "Enter Username: ";
	cin >> UserName;
	for (int i = 0; i < si; i++) {
		if(UserName != arr[i].UserName) {
			return "1";
			break;
		}
		
	}
	cout << "Enter Password: ";
	cin >> Password;
	for (int i = 0; i < si; i++) {
		if (Password != arr[i].Password) {
			return "1";
			break;
		}
	}
	return UserName;
}

int User::BorrowBooks(Book arr[],User tp)
{
	int no;
	string temp;
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	in.open("Bk.txt");
	while (!in.eof()) {
		getline(in, temp);
		cout << temp << endl;
	}
	cout << "Enter book number to borrow it: ";
	cin >> no;
	if (arr[no - 1].Copies_avail == 0) {
		return 1;
	}
	cout << "Book Lended: ";
	cout << arr[no - 1].Name << " by " << arr[no - 1].Author << endl;
	cout << "Date Borrowed: " << endl;
	cout << str << endl;
	arr[no - 1].Copies_avail--;
	cout << "Book Borrowed Successfulyy! " << endl;
	tp.print(arr,no-1);
	return 0;
}

User::User()
{
	UserName = "\0";
	Password = "\0";
	Date_borrowed = "\0";
}
