#include "ExerciseBook.h"

// ___________________________ Const/Dest-ructors _________________________

ExerciseBook::~ExerciseBook() {}

// ____________________________ Сеттеры _________________________

void ExerciseBook::SetAuthor(string newAuthor)
{
	author = newAuthor;
}

void ExerciseBook::SetEditorName(string newEditorName)
{
	editorName = newEditorName;
}

void ExerciseBook::SetPrintDate(Date newPrintDate)
{
	printDate = newPrintDate;
}

void ExerciseBook::Set(string subject, int pagesAmount, string author, string editorName, Date printDate)
{
	PaperStaff::Set(subject, pagesAmount);

	this->author = author;
	this->editorName = editorName;
	this->printDate = printDate;
}

// ___________________________ Геттеры _____________________________

string ExerciseBook::GetAuthor() {
	return author;
}

string ExerciseBook::GetEditorName() {
	return editorName;
}

Date ExerciseBook::GetPrintDate() {
	return printDate;
}

void ExerciseBook::Show()
{
	PaperStaff::Show();

	cout << "The author is " << author << "." << endl;
	cout << "The editor name is " << editorName << "." << endl;
	cout << "The print date is " << printDate.day << "." << printDate.month 
		<< "." << printDate.year << "." << endl;
}