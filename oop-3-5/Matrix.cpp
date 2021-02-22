#include "Matrix.h"

void RandomMatrix(Matrix* matrix)
{
	// left, right - левая и правая границы рандома
	float left = -2 * (matrix->rows + matrix->columns);
	float right = -left;

	for (int i = 0; i < matrix->rows; i++)
		for (int j = 0; j < matrix->columns; j++)
			matrix->items[i][j] = (right - left) * rand() / RAND_MAX + left;
}

void PrintMatrix(Matrix matrix)
{
	std::cout << std::endl << "Matrix:" << std::endl;
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++)
			//std::cout << matrix.items[i][j] << "\t";
			printf("%.2f\t", matrix.items[i][j]);
		std::cout << std::endl;
	}
}

float ArraySum(float* items, int number)
{
	float sum = 0;
	for (int i = 0; i < number; i++)
		sum += items[i];

	return sum;
}

float ArrayMinimum(float* items, int number)
{
	float min = INT_MAX;
	for (int i = 0; i < number; i++)
		if (items[i] < min) min = items[i];

	return min;
}

Matrix::Matrix(int rows, int columns)
{
	// устанавливаем параметры матрицы
	if (rows > 0 && columns > 0) {
		this->rows = rows;
		this->columns = columns;

		// выделяем память согласно параметрам
		this->items = new float* [rows];
		for (int i = 0; i < rows; i++)
			this->items[i] = new float[columns];

		RandomMatrix(this);
	}
	else {
		std::cout << " Некорректные параметры матрицы. Матрица не была создана." << std::endl;
	}

	std::cout << "Отработал конструктор с параметрами " << this << std::endl;
}

Matrix::Matrix(const Matrix& matrixToCopy)
{
	std::cout << std::endl << "Copy open matrix[" << matrixToCopy.rows << "] [" << matrixToCopy.columns << "]";
	// копируем параметры матрицы
	this->rows = matrixToCopy.rows;
	this->columns = matrixToCopy.columns;

	// выделяем память согласно параметрам
	this->items = new float* [rows];
	for (int i = 0; i < rows; i++)
		this->items[i] = new float[columns];

	// переносим значения
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			this->items[i][j] = matrixToCopy.items[i][j];
	
	std::cout << "Отработал конструктор копирования " << this << std::endl;
}

Matrix::~Matrix()
{
	// если память не очищена, очищаем
	if (this->items != nullptr) {
		for (int i = 0; i < this->rows; i++)
			delete[] this->items[i];
		delete[] this->items;
	}

	std::cout << "Отработал деструктор " << this << std::endl;
}

Matrix Matrix::operator = (const Matrix& other)
{
	//std::cout << "equal opened" << std::endl;
	if (this == &other) return *this;

	// удаляем память матрицы
	for (int i = 0; i < this->rows; i++)
		delete[] this->items[i];
	delete[] this->items;

	// копируем параметры
	this->rows = other.rows;
	this->columns = other.columns;

	// выделяем новую память
	this->items = new float* [rows];
	for (int i = 0; i < this->rows; i++)
		this->items[i] = new float[columns];

	// переносим значения
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			this->items[i][j] = other.items[i][j];

	//std::cout << "equal closed" << std::endl;

	return *this;
}

Matrix Matrix:: operator / (const Matrix& other)
{
	// Обрезка матриц
	int rows = 0, columns = 0;
	if (this->rows < other.rows) rows = this->rows;
	else rows = other.rows;

	if (this->columns < other.columns) columns = this->columns;
	else columns = other.columns;


	Matrix temporary(rows, columns);
	//std::cout << "temporary" << std::endl;

	for (int i = 0; i < rows; i++) {
		float arithmeticMean1 = 0; // служебные переменные для ср. арифметических
		float arithmeticMean2 = 0;

		//std::cout << "befor array sum" << std::endl;
		// находим сумму строк в обоих матрицах
		arithmeticMean1 = ArraySum(this->items[i], columns) / columns;
		arithmeticMean2 = ArraySum(other.items[i], columns) / columns;
		//std::cout << "after array sum" << std::endl;

		// переносим строку
		if (arithmeticMean1 > arithmeticMean2)
			for (int j = 0; j < columns; j++)
				temporary.items[i][j] = this->items[i][j];
		else
			for (int j = 0; j < columns; j++)
				temporary.items[i][j] = other.items[i][j];
	}

	//std::cout << "temp: " << &temporary << std::endl;
	//std::cout << "1";
	return temporary;
}

Matrix Matrix::operator - (const Matrix& other)
{
	// Обрезка матриц
	int rows = 0;
	if (this->rows < other.rows) rows = this->rows;
	else rows = other.rows;

	Matrix vector(rows, 1); // создаём новую матрицу

	for (int i = 0; i < rows; i++) {
		// минимумы матриц
		float min1 = ArrayMinimum(this->items[i], this->columns),
			min2 = ArrayMinimum(other.items[i], other.columns);

		vector.items[i][1] = min1 - min2;
	}

	return vector;
}

Matrix Matrix::operator + (const Matrix& other)
{
	Matrix tmp(this->rows, this->columns + 1);

	// копируем значения в новую матрицу
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			tmp.items[i][j] = this->items[i][j];

	// добавляем вектор в последний столбец
	for (int i = 0; i < tmp.rows; i++)
		tmp.items[i][tmp.columns - 1] = other.items[0][i];

	// если вектор больше, он обрезается
	// если вектор меньше, он дозаполняется нулями

	// заполнение нулями, если вектор меньше
	for (int i = other.columns; i < tmp.rows; i++)
		tmp.items[i][tmp.columns - 1] = 0;

	return tmp;
}

