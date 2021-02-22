#include "Backpack.h"

Backpack::Backpack()
{
	do {
		cout << " Enter the number of books in the bag: ";
		cin >> booksNumber;
	} while (booksNumber < 1);
	books = new Book * [booksNumber];
	booksPut = 0;
}

Backpack::~Backpack()
{
	for (int i = 0; i < booksPut; i++)
		delete books[i];
	delete[] books;
}

void Backpack::AddBook(Book* book)
{
	if (booksPut < booksNumber) {
		books[booksPut] = new Book(book);
		booksPut++;
	}
	else
		cout << "Too many books!" << endl;
}

void Backpack::DeleteBook(int bookToDelete)
{
	if (bookToDelete >= 1 && bookToDelete <= booksPut) {
		delete books[bookToDelete - 1];
		Book* buf = books[bookToDelete - 1];

		if (bookToDelete < booksPut)
			for (int i = bookToDelete - 1; i < booksPut - 1; i++)
				books[i] = books[i + 1];
		books[booksPut - 1] = buf;

		booksPut--;
	}
}

void Backpack::DeleteAllBooks()
{
	for (int i = 0; i < booksPut; i++)
		delete books[i];
	delete[] books;
	booksPut = 0;

	do {
		cout << " Enter the number of books in the bag: ";
		cin >> booksNumber;
	} while (booksNumber < 1);
	books = new Book * [booksNumber];
}

void Backpack::ShowBooks()
{
	for (int i = 0; i < booksPut; i++)
		cout << i + 1 << ". " << books[i]->GetSubject() << endl;
}

