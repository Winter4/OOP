#include "CopyBook.h"

// ___________________________ Const/Dest-ructors _________________________

CopyBook::~CopyBook() {}

// ____________________________ Setters _________________________

void CopyBook::SetProducer(string producer)
{
	this->producer = producer;
}

void CopyBook::SetType(string type)
{
	this->type = type;
}

void CopyBook::Set(string subject, int pagesAmount, string producer, string type)
{
	PaperStaff::Set(subject, pagesAmount);

	this->producer = producer;
	this->type = type;
}

// ____________________________ Getters _________________________

string CopyBook::GetProducer()
{
	return producer;
}

string CopyBook::GetType()
{
	return type;
}

void CopyBook::Show()
{
	PaperStaff::Show();

	cout << "The producer is " << producer << "." << endl;
	cout << "The type of copybook is " << type << "." << endl;
}