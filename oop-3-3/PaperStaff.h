#pragma once

#include <iostream>
#include <string>

using namespace std;

class PaperStaff {
protected:
	string subject; // ���������� 
	int pagesAmount; // ���-�� �������

public:
	// ����������� �� ���������
	PaperStaff();
	// ����������� � �����������; subject, pagesAmount
	PaperStaff(string, int);
	// ����������� � ���������
	PaperStaff(string);
	// ���������� �����������
	PaperStaff(PaperStaff*);

	~PaperStaff();

	void SetSubject(string);
	void SetPagesAmount(int);
	
	

	string GetSubject();
	int GetPagesAmount();

	virtual void Show();
};