#include <iostream>
#include <time.h>

// __________________________ VECTOR _____________________________-

template <class Type>
class Vector {
private:
	Type* items;
	size_t size;

public:
	Vector() {
		size = 0;
	}

	Vector(int sizeToSet) 
	{
		size = sizeToSet;
		items = new Type[size];

		for (int i = 0; i < size; i++)
			items[i] = 0;
	}

	Vector(const Vector<Type>& vectorToCopy) {
		items = new Type[vectorToCopy.size];
		this->size = vectorToCopy.size;

		for (int i = 0; i < size; i++)
			this->items[i] = vectorToCopy.items[i];
	}

	~Vector()
	{
		delete[] items;
	}

	size_t GetSize() {
		return size;
	}

	void SetSize(int sizeToSet) {
		if (size > 0) delete[] items;

		if (sizeToSet > 0 && sizeToSet <= 100) size = sizeToSet;
		else throw -1;

		items = new Type[size];

		for (int i = 0; i < size; i++)
			items[i] = 0;
	}

	void EnterVectorByKeyboard() {
		for (int i = 0; i < size; i++) {
			std::cout << "Item " << i + 1 << ": ";
			std::cin >> items[i];
		}
	}

	void RandomVector() {
		for (int i = 0; i < size; i++) 
			items[i] = (size * 2) * rand() / RAND_MAX - size;
	}

	Type& operator[] (int i)
	{
		if (i >= 0 && i < size) return items[i];
		else throw -1;
	}

	template <class Type>
	friend std::ostream& operator << (std::ostream&, const Vector<Type>&);
};

template <class Type>
std::ostream& operator << (std::ostream& out, Vector<Type>& vector)
{
	std::cout.width(5);
	std::cout.precision(2);
	for (int i = 0; i < vector.GetSize(); i++)
		std::cout << vector[i] << "\t";
	std::cout << std::endl;
	return out;
}

// _____________________________ MATRIX ________________________________________

template<class Type>
class Matrix {
private:
	Vector<Type>* vectors;
	size_t rows;
	size_t columns;

public:
	Matrix() {
		vectors = nullptr;
		rows = columns = 0;
	}

	Matrix(int rowsToSet, int columnsToSet) {
		if (rowsToSet < 1 || rowsToSet > 100 || columnsToSet < 1 || columnsToSet > 100) throw -1;

		rows = rowsToSet;
		columns = columnsToSet;

		vectors = new Vector<Type>[rows];
		for (int i = 0; i < rows; i++)
			vectors[i].SetSize(columns);
	}

	Matrix(const Matrix<Type>& matrixToCopy) {
		rows = matrixToCopy.rows;
		columns = matrixToCopy.columns;

		vectors = new Vector<Type>[rows];

		for (int i = 0; i < rows; i++) {
			vectors[i].SetSize(columns);

			for (int j = 0; j < columns; j++)
				vectors[i][j] = matrixToCopy.vectors[i][j];
		}
	}

	Matrix(int rowsToSet, int columnsToSet, float a, float b, float c) {
		//Matrix(rowsToSet, columnsToSet);
		if (rowsToSet < 1 || rowsToSet > 100 || columnsToSet < 1 || columnsToSet > 100) throw - 1;

		rows = rowsToSet;
		columns = columnsToSet;

		vectors = new Vector<Type>[rows];
		
		for (int i = 0; i < rows; i++) {
			vectors[i].SetSize(columns);
			for (int j = 0; j < columns; j++)
				this->vectors[i][j] = a * (float(i + 1) + b) * powf(sinf(float(j + 1) + c), 2);
		}
	}

	size_t GetColumns() {
		return columns;
	}

	size_t GetRows() {
		return rows;
	}

	void EnterMatrixByKeyboard() {
		for (int i = 0; i < rows; i++) {
			std::cout << "Row " << i + 1 << ": \n";
			vectors[i].EnterVectorByKeyboard();
		}
	}

	void RandomMatrix() {
		for (int i = 0; i < rows; i++)
			vectors[i].RandomVector();
	}

	Type CalculateP() {
		float max = INT_MIN;
		int i_max = -1;
		for (int i = 0; i < rows; i++) 
			for (int j = 0; j < columns; j++)
				if (vectors[i][j] > max) {
					max = vectors[i][j];
					i_max = i;
				}

		Type P = 1;
		for (int j = 0; j < columns; j++)
			if (vectors[i_max][j] != 0) P *= vectors[i_max][j];

		return P;
	}

	float ArithmeticAverage() {
		Type average = 0;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				average += vectors[i][j];

		return float(average / (rows * columns));
	}

	void Transform() {
		float average = ArithmeticAverage();
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				vectors[i][j] -= average;
	}

	Vector<Type> GetVector() {
		float sum_min = INT_MAX;
		int j_min;

		for (int j = 0; j < columns; j++) {
			float sum = 0;
			for (int i = 0; i < rows; i++)
				sum += fabs(vectors[i][j]);

			if (sum < sum_min) {
				sum_min = sum;
				j_min = j;
			}
		}

		Vector<Type> result(rows);
		for (int i = 0; i < rows; i++)
			result[i] = vectors[i][j_min];

		return result;
	}

	Vector<Type> operator[](int row) {
		if (row >= 0 && row < rows) return vectors[row];
	}

	template <class Type>
	friend std::ostream& operator << (std::ostream&, const Matrix<Type>&);
};

template <class Type>
std::ostream& operator << (std::ostream& out, Matrix<Type>& matrix)
{
	std::cout.precision(2);
	for (int i = 0; i < matrix.GetRows(); i++) {
		for (int j = 0; j < matrix.GetColumns(); j++)
			std::cout << matrix[i][j] << "\t";
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	return out;
}

// __________________________________________________________________________________

int main()
{
	srand(time(0));

	Matrix<float> A(5,4, 1.2, -2.1, 3.5);
	std::cout << "Matrix A: \n";
	std::cout << A;
	
	if (A.CalculateP() > 0) {
		std::cout << "Parameter > 0. The matrix A was transformed. \n";
		A.Transform();
		std::cout << A;
	}
	Vector<float> A_vector = A.GetVector();
	std::cout << A_vector;
	

	Matrix<float> B(6, 5, 5.9, -5.1, -4.2);
	std::cout << "\nMatrix B: \n";
	std::cout << B;

	if (B.CalculateP() > 0) {
		std::cout << "Parameter > 0. The matrix B was transformed. \n";
		B.Transform();
		std::cout << B;
	}
	Vector<float> B_vector = B.GetVector();
	std::cout << B_vector;


	system("pause");
	return 0;
}
