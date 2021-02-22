#include <iostream>
#include "windows.h"
#include "conio.h"

#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "ShapesKit.h"

using namespace std;

int main()
{
    HWND hwnd = GetConsoleWindow(); // Берём ориентир на консольное окно (В нём будем рисовать)
    HDC hdc = GetDC(hwnd); // Цепляемся к консольному окну

    RECT window = {}; // Переменная window будет использована для получения ширины и высоты окна
    HBRUSH brush; // Переменная brush - это кисть, она будет использоваться для закрашивания

        //1. Рисуем фон
    brush = CreateSolidBrush(RGB(255, 255, 255)); // Создаём кисть определённого стиля и цвета
    SelectObject(hdc, brush); //Выбираем кисть

    MoveWindow(hwnd, 5, 10, 1366, 768, 0);
    GetWindowRect(hwnd, &window);
    Rectangle(hdc, 0, 0, window.right, window.bottom);

    DeleteObject(brush); //Очищаем память от созданной кисти

    HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, pen);

    Square square(300, 300, 74);
    Triangle triangle(300, 154, 200);
    square.Draw(hdc);
    triangle.Draw(hdc);

    ShapesKit* kit1 = new ShapesKit(300, 200, 50, 300, 101, 134);
    ShapesKit* kit2 = new ShapesKit(500, 200, 50, 500, 101, 134);
    ShapesKit* kit3 = new ShapesKit(700, 200, 50, 700, 101, 134);

    while (true) {
        Sleep(100);
        Rectangle(hdc, 0, 0, window.right, window.bottom);
        kit1->Move(1, 0);
        kit1->Scale(1.001);
        kit1->Draw(hdc);

        kit2->Move(1, 1);
        kit2->Scale(1.002);
        kit2->Draw(hdc);

        kit3->Move(0, 1);
        kit3->Scale(0.98);
        kit3->Draw(hdc);
    }
    ReleaseDC(hwnd, hdc);
    
    delete kit1, kit2, kit3;

    _getch();
    return 0;
}
