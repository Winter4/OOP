#pragma once

#include "PaperStaff.h"

class CopyBook: public PaperStaff {
private:
	string producer; // производитель
	string type; // тип тетради (клетка, линия)
public:
	// конструктор по умолчанию
	CopyBook() : PaperStaff() {
		this->producer = "";
		this->type = "";
	}
	// конструктор с параметрами
	CopyBook(string subject, int pagesAmount, string, string) : PaperStaff(subject, pagesAmount) {
		this->producer = producer;
		this->type = type;
	}
	// конструктор с предметом
	CopyBook(string subject) : PaperStaff(subject) {}
	// конструктор копирования 
	CopyBook(CopyBook* copyBookToCopy) : PaperStaff(copyBookToCopy) {
		this->producer = copyBookToCopy->producer;
		this->type = copyBookToCopy->type;
	}

	~CopyBook();

	void SetProducer(string);
	void SetType(string);

	// subject, pagesAmount, producer, type
	void Set(string, int, string, string);

	string GetProducer();
	string GetType();

	// отобразить объект
	void Show();
};
