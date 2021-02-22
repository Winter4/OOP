#include "Book.h"

// ___________________________ Constructors _________________________

Book::Book()
{
	author = "none";
	editorName = "none";
	printDate = { 0, 0, 0 };
}

Book::Book(string subject) {}

Book::Book(string subject, int pagesAmount, string author, string editorName, Date printDate)
{
	this->author = author;
	this->editorName = editorName;
	this->printDate = printDate;
}

Book::Book(Book* book)
{
	this->subject = book->subject;
	this->author = book->author;
	this->editorName = book->editorName;
	this->printDate = book->printDate;
	this->pagesAmount = book->pagesAmount;
}

Book::~Book() {}

// ____________________________ Сеттеры _________________________

void Book::SetSubject(string newSubject)
{
	cout << "The book's subject was changed from " << subject << " to " << newSubject << "." << endl;
	subject = newSubject;
}

void Book::SetAuthor(string newAuthor)
{
	cout << "The author was changed from " << author << " to " << newAuthor << "." << endl;
	author = newAuthor;
}

void Book::SetEditorName(string newEditorName)
{
	cout << "The editor name was changed from " << editorName << " to " << newEditorName << "." << endl;
	editorName = newEditorName;
}

void Book::SetPrintDate(Date newPrintDate)
{
	cout << "The print date was changed from " << printDate.day << "." << printDate.month << "." << printDate.year << " to ";
	cout << newPrintDate.day << "." << newPrintDate.month << "." << newPrintDate.year << "." << endl;
	printDate = newPrintDate;
}

void Book::SetPagesAmount(int newPagesAmount)
{
	cout << "The amount of pages was changed from " << pagesAmount << " to " << newPagesAmount << "." << endl;
	pagesAmount = newPagesAmount;
}

void Book::SetBook(string newName, string newAuthor, string newEditorName, Date newPrintDate, int newPagesAmount)
{
	SetSubject(newName);
	SetAuthor(newAuthor);
	SetEditorName(newEditorName);
	SetPrintDate(newPrintDate);
	SetPagesAmount(newPagesAmount);
}

// ___________________________ Геттеры _____________________________

string Book::GetSubject() {
	return subject;
}

string Book::GetAuthor() {
	return author;
}

string Book::GetEditorName() {
	return editorName;
}

Date Book::GetPrintDate() {
	return printDate;
}

int Book::GetPagesAmount() {
	return pagesAmount;
}

void Book::ShowBook()
{
	cout << "The subject of book is " << subject << "." << endl;
	cout << "The author is " << author << "." << endl;
	cout << "The editor name is " << editorName << "." << endl;
	cout << "The print date is " << printDate.day << "." << printDate.month << "." << printDate.year << "." << endl;
	cout << "The amount of pages is " << pagesAmount << "." << endl << endl;
}