#pragma once
#include "Book.h"

using namespace std;

class Backpack {
private:
	Book** books;
	int booksNumber; // ������������ ���-�� ����
	int booksPut; // ���� ������

public:
	Backpack();
	~Backpack();

	// �������� �����
	void AddBook(Book*);
	// ������� �����; int [1; N]
	void DeleteBook(int);
	// ������� ��� �����
	void DeleteAllBooks();
	// ���������� ������� ����� � ��������
	void ShowBooks();
};