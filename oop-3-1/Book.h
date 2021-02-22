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
	string name; // �������� �����
	string author; // �����
	string editorName; // �������� ������������
	Date printDate; // ���� ������ (�������)
	int pagesAmount; // ���-�� �������

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