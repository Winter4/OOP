#pragma once
#include <iostream>

class Matrix {
	// заполнить матрицу рандомом
	friend void RandomMatrix(Matrix*);
	// печать матрицы
	friend void PrintMatrix(Matrix);

	// Сумма строки
	friend float ArraySum(float*, int);
	friend float ArrayMinimum(float*, int);

private:
	float** items; // элементы матрицы
	int rows; // кол-во строк
	int columns; // кол-во столбцов

public:
	Matrix();
	// int rows, int cols
	Matrix(int, int);
	// конструктор копирования
	Matrix(const Matrix&);
	// деструктор
	~Matrix();
		
	// перегрузка операторов по варианту
	Matrix operator = (const Matrix&);
	Matrix operator / (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator + (const Matrix&);
};

