#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
	
public:
	string Name;
	string Author;
	Book();
	
	int Copies_avail;
	static int BookCount;
	//shows books avail
	void ShowBooks();
	//reads data from file
	void readData();

	int AddBooks();
	//Prints to a file
	virtual void print();
};

class User : public Book {
	
	string UserName;
	string Password;
public:
	
	string Date_borrowed;
	User();
	static int UserCount;

	
	int AddUser();
	void ShowUsers();
	//Prints Borrow Record
	void print(Book arr[],int x);
	//Returns a book and prints record in a file
	void returnbk(Book arr[], int size);
	//Shows borrow and return records
	void borrowrec();
	void returnrec();

	string UserLogin(User arr[], int si);
	//Function to borrow a book
	int BorrowBooks(Book arr[], User tp);

};



class Admin {
	string AdminName = "Hasan";
	string Password = "Idkwhat";
	
public:
	//admin login
	int AdminLogin();
	
};