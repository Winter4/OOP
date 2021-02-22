#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    Book math, laser1("English laser B1", "Afanaseva", "RusPechat", { 24, 8, 2015 }, 93), laser2(laser1);

    math.ShowBook();
    cout << endl;
    laser1.ShowBook();
    cout << endl;
    laser2.ShowBook();

    string bookName;
    laser2.SetName("English laser B2");
    bookName = laser2.GetName();

    cout << bookName << endl;
    laser2.SetPrintDate({ 20, 11, 2016 });

    cout << endl;
    system("pause");
    return 0;
}
