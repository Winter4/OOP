#pragma once

//#include <iostream>
#include "PaperStaff.h"

//using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

class ExerciseBook : public PaperStaff {
private:
	string author; // Автор
	string editorName; // Название издательства
	Date printDate; // Дата печати (выпуска)

public:
	// Конструктор по умолчанию
	ExerciseBook() :PaperStaff() {
		author = "none";
		editorName = "none";
		printDate = { 0, 0, 0 };
	}
	// Конструктор с предметом
	ExerciseBook(string subject) : PaperStaff(subject) {
		author = "";
		editorName = "";
		printDate = { 0, 0, 0 };
	}
	// Конструктор с параметрами
	ExerciseBook(string subject, int pagesAmount, string, string, Date) : PaperStaff(subject, pagesAmount) {
		this->author = author;
		this->editorName = editorName;
		this->printDate = printDate;
	};
	// Конструктор копирования
	ExerciseBook(ExerciseBook* exerciseBookToCopy) : PaperStaff(exerciseBookToCopy) {
		this->author = exerciseBookToCopy->author;
		this->editorName = exerciseBookToCopy->editorName;
		this->printDate = exerciseBookToCopy->printDate;
	}

	~ExerciseBook();
	
	void SetAuthor(string author);
	void SetEditorName(string);
	void SetPrintDate(Date);

	// subject, author, editorName, printDate, pagesAmount
	void Set(string, int, string, string, Date);

	string GetAuthor();
	string GetEditorName();
	Date GetPrintDate();

	// отобразить объект
	void Show();
};