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
	string author; // �����
	string editorName; // �������� ������������
	Date printDate; // ���� ������ (�������)

public:
	// ����������� �� ���������
	ExerciseBook() :PaperStaff() {
		author = "none";
		editorName = "none";
		printDate = { 0, 0, 0 };
	}
	// ����������� � ���������
	ExerciseBook(string subject) : PaperStaff(subject) {
		author = "";
		editorName = "";
		printDate = { 0, 0, 0 };
	}
	// ����������� � �����������
	ExerciseBook(string subject, int pagesAmount, string, string, Date) : PaperStaff(subject, pagesAmount) {
		this->author = author;
		this->editorName = editorName;
		this->printDate = printDate;
	};
	// ����������� �����������
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

	// ���������� ������
	void Show();
};