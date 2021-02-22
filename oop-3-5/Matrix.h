#pragma once
#include <iostream>

class Matrix {
	// ��������� ������� ��������
	friend void RandomMatrix(Matrix*);
	// ������ �������
	friend void PrintMatrix(Matrix);

	// ����� ������
	friend float ArraySum(float*, int);
	friend float ArrayMinimum(float*, int);

private:
	float** items; // �������� �������
	int rows; // ���-�� �����
	int columns; // ���-�� ��������

public:
	Matrix();
	// int rows, int cols
	Matrix(int, int);
	// ����������� �����������
	Matrix(const Matrix&);
	// ����������
	~Matrix();
		
	// ���������� ���������� �� ��������
	Matrix operator = (const Matrix&);
	Matrix operator / (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator + (const Matrix&);
};

