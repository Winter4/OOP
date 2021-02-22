#pragma once
#include "Book.h"

using namespace std;

class Backpack {
private:
	Book** books;
	int booksNumber; // максимальное кол-во книг
	int booksPut; // книг занято

public:
	Backpack();
	~Backpack();

	// добавить книгу
	void AddBook(Book*);
	// удалить книгу; int [1; N]
	void DeleteBook(int);
	// удалить все книги
	void DeleteAllBooks();
	// отобразить текущие книги в портфеле
	void ShowBooks();
};