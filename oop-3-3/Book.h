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
	string author; // �����
	string editorName; // �������� ������������
	Date printDate; // ���� ������ (�������)

public:
	// ����������� �� ���������
	Book();
	// ����������� � ���������
	Book(string subject) : PaperStaff(subject) {};
	// ����������� � �����������
	Book(string subject, int pagesAmount, string, string, Date) : PaperStaff(subject, pagesAmount) {};
	// ����������� �����������
	Book(Book*);
	
	void SetAuthor(string author);
	void SetEditorName(string);
	void SetPrintDate(Date);

	// subject, author, editorName, printDate, pagesAmount
	void SetBook(string, string, string, Date, int);
};

