#pragma once

#include <iostream>
#include <string>
#include "PaperStaff.h"

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

class Book : public PaperStaff {
private:
	string author; // Автор
	string editorName; // Название издательства
	Date printDate; // Дата печати (выпуска)

public:
	// Конструктор по умолчанию
	Book();
	// Конструктор с предметом
	Book(string subject) : PaperStaff(subject) {};
	// Конструктор с параметрами
	Book(string subject, int pagesAmount, string, string, Date) : PaperStaff(subject, pagesAmount) {};
	// Конструктор копирования
	Book(Book*);
	
	void SetAuthor(string author);
	void SetEditorName(string);
	void SetPrintDate(Date);

	// subject, author, editorName, printDate, pagesAmount
	void SetBook(string, string, string, Date, int);
};

