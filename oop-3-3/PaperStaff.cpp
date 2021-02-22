#include "PaperStaff.h"

// _________________ Constructors ____________________

PaperStaff::PaperStaff() 
{
	subject = "";
	pagesAmount = 0;
}

PaperStaff::PaperStaff(string subject, int pagesAmount)
{
	this->subject = subject;
	this->pagesAmount = pagesAmount;
}

PaperStaff::PaperStaff(string subject)
{
	this->subject = subject;
}

PaperStaff::PaperStaff(PaperStaff* staffToCopy)
{
	this->subject = staffToCopy->subject;
	this->pagesAmount = staffToCopy->pagesAmount;
}

PaperStaff::~PaperStaff() {}

// ______________________ Setters ____________________________

void PaperStaff::SetSubject(string subject)
{
	this->subject = subject;
}

void PaperStaff::SetPagesAmount(int pagesAmount)
{
	this->pagesAmount = pagesAmount;
}

// _______________________ Getters ___________________________

string PaperStaff::GetSubject()
{
	return this->subject;
}

int PaperStaff::GetPagesAmount()
{
	return this->pagesAmount;
}

void PaperStaff::Show()
{
	cout << "Subject: " << subject << endl;
	cout << "Pages number: " << pagesAmount << endl;
}

