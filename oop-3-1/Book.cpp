#include "Book.h"

// ___________________________________ Конструкторы _____________________________________________

Book::Book()
{
	name = "none";
	author = "none";
	editorName = "none";
	printDate.day = 0;
	printDate.month = 0;
	printDate.year = 0;
	pagesAmount = 0;
}

Book::Book(string name, string author, string editorName, Date printDate, int pagesAmount)
{
	this->name = name;
	this->author = author;
	this->editorName = editorName;
	this->printDate = printDate;
	this->pagesAmount = pagesAmount;
}

Book::Book(const Book& book)
{
	this->name = book.name;
	this->author = book.author;
	this->editorName = book.editorName;
	this->printDate = book.printDate;
	this->pagesAmount = book.pagesAmount;
}

Book::~Book() {}

// ____________________________ Сеттеры _________________________

void Book::SetName(string newName)
{
	cout << "The book's name was changed from " << name << " to " << newName << "." << endl;
	name = newName;
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
	SetName(newName);
	SetAuthor(newAuthor);
	SetEditorName(newEditorName);
	SetPrintDate(newPrintDate);
	SetPagesAmount(newPagesAmount);
}

// ___________________________ Геттеры _____________________________

string Book::GetName()
{
	return name;
}

string Book::GetAuthor()
{
	return author;
}

string Book::GetEditorName()
{
	return editorName;
}

Date Book::GetPrintDate()
{
	return printDate;
}

int Book::GetPagesAmount()
{
	return pagesAmount;
}

void Book::ShowBook()
{
	cout << "The name of book is " << name << "." << endl;
	cout << "The author is " << author << "." << endl;
	cout << "The editor name is " << editorName << "." << endl;
	cout << "The print date is " << printDate.day << "." << printDate.month << "." << printDate.year << "." << endl;
	cout << "The amount of pages is " << pagesAmount << "." << endl << endl;
}