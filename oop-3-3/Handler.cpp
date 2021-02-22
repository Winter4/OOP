#include "Handler.h"

Handler::Handler()
{
	myBooks[0].SetSubject("English");
	myBooks[1].SetSubject("Russian");
	myBooks[2].SetSubject("Math");
	myBooks[3].SetSubject("Object prog.");
	myBooks[4].SetSubject("Visual prog.");
	myBooks[5].SetSubject("Web prog.");
	system("cls");

	bag = new Backpack();
	
	int choice = 0;
	while (true) {
		cout << endl;
		bag->ShowBooks();
		cout << "\n Choose the action: " << endl
			<< "1 - Add book" << endl
			<< "2 - Delete Book" << endl
			<< "3 - Delete all books" << endl
			<< "0 - Finish" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << endl;
			for (int i = 0; i < 6; i++)
				cout << i + 1 << ". " << myBooks[i].GetSubject() << endl;

			int bookChoice1;
			do {
				cout << " Choose the book: ";
				cin >> bookChoice1;
			} while (bookChoice1 < 1 || bookChoice1 > 6);

			bag->AddBook(&myBooks[bookChoice1 - 1]);
			break;
		case 2:
			cout << " Enter the book number: ";
			int bookChoice2;
			cin >> bookChoice2;

			bag->DeleteBook(bookChoice2);
			break;
		case 3:
			bag->DeleteAllBooks();
			break;
		case 0:
			bag->ShowBooks();
			exit(0);
			break;
		}
	}
}

Handler::~Handler()
{
	delete bag;
}