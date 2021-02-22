#include <iostream>
#include "Matrix.h"
#include "locale.h"

// Сумма массива
float ArraySum(float*, int);

int main()
{
    setlocale(LC_ALL, "russian");

    Matrix A(3, 4), B(5, 7), C(8, 4);

    std::cout << "A / C: " << std::endl;
    //Matrix AdiffC = (A / C);

    //std::cout << "before print" << std::endl;
    PrintMatrix(A / C);
    //std::cout << "after print" << std::endl;

    std::cout << "(A / C) - B: " << std::endl;
    PrintMatrix((A / C) - B);

    std::cout << "A - B: " << std::endl;
    PrintMatrix(A - B);

    std::cout << "(A / C) - B + (A - B): " << std::endl;
    PrintMatrix((A / C) - B + (A - B));
    

    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}


