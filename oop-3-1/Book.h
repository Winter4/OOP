#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

class Book {
private:
	string name; // Название книги
	string author; // Автор
	string editorName; // Название издательства
	Date printDate; // Дата печати (выпуска)
	int pagesAmount; // Кол-во страниц

public:
	Book();
	Book(string, string, string, Date, int);
	Book(const Book&);

	~Book();

	void SetName(string);
	void SetAuthor(string);
	void SetEditorName(string);
	void SetPrintDate(Date);
	void SetPagesAmount(int);
	void SetBook(string, string, string, Date, int);

	string GetName();
	string GetAuthor();
	string GetEditorName();
	Date GetPrintDate();
	int GetPagesAmount();
	void ShowBook();
};