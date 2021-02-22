#pragma once

#include <iostream>
#include <string>

using namespace std;

class PaperStaff {
protected:
	string subject; // Дисциплина 
	int pagesAmount; // Кол-во страниц

public:
	// Конструктор по умолчанию
	PaperStaff();
	// Конструктор с параметрами; subject, pagesAmount
	PaperStaff(string, int);
	// Конструктор с предметом
	PaperStaff(string);
	// Конструкор копирования
	PaperStaff(PaperStaff*);

	~PaperStaff();

	void SetSubject(string);
	void SetPagesAmount(int);
	
	

	string GetSubject();
	int GetPagesAmount();

	virtual void Show();
};