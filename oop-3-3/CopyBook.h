#pragma once

#include "PaperStaff.h"

class CopyBook: public PaperStaff {
private:
	string producer; // �������������
	string type; // ��� ������� (������, �����)
public:
	// ����������� �� ���������
	CopyBook() : PaperStaff() {
		this->producer = "";
		this->type = "";
	}
	// ����������� � �����������
	CopyBook(string subject, int pagesAmount, string, string) : PaperStaff(subject, pagesAmount) {
		this->producer = producer;
		this->type = type;
	}
	// ����������� � ���������
	CopyBook(string subject) : PaperStaff(subject) {}
	// ����������� ����������� 
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

	// ���������� ������
	void Show();
};
