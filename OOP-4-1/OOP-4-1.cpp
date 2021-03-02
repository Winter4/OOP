#include <iostream>
#include <time.h>

template <class Type>
class Vector {
private:
	Type* items;
	size_t size;

public:
	Vector() {
		items = nullptr;
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
		if (sizeToSet >= 0) size = sizeToSet;
		else throw -1;

		if (items != nullptr) delete[] items;
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

	Type operator[] (int i)
	{
		if (i >= 0 && i < size) return items[i];
		else throw -1;
	}

	template <class Type>
	friend std::ostream& operator << (std::ostream&, const Vector<Type>&);
};

template <class Type>
std::ostream& operator << (std::ostream& out, const Vector<Type>& vector)
{
	for (int i = 0; i < vector.size; i++)
		std::cout << vector.items[i] << "\t";
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
		if (rowsToSet < 1 || columnsToSet < 1) throw -1;

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
		Matrix(rowsToSet, columnsToSet);
		
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				this->vectors[i][j] = a * (float(i + 1) + b) * powf(sinf(float(j + 1) + c), 2);
				
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

	

	float CalculateP() {
		float max;
		int i_max;
		for (int i = 0; i < rows; i++) {
			max = INT_MIN;
			for (int j = 0; j < columns; j++)
				if (vectors[i][j] > max) {
					max = vectors[i][j];
					i_max = i;
				}
		}

		float P = 1;
		for (int j = 0; j < columns; j++)
			if (vectors[i_max][j] != 0) P *= vectors[i_max][j];

		return P;
	}

	float ArithmeticAverage() {
		float average = 0;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				average += vectors[i][j];

		return average / (rows * columns);
	}

	void Transform(float average) {
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
			(result[i] = vectors[i][j_min];

		return result;
	}

	Vector<Type> operator[](int row) {
		if (row >= 0 && row < rows) return vectors[row];
	}

	template <class Type>
	friend std::ostream& operator << (std::ostream&, const Matrix<Type>&);
};

template <class Type>
std::ostream& operator << (std::ostream& out, const Matrix<Type>& matrix)
{
	for (int i = 0; i < matrix.rows; i++)
		std::cout << matrix.vectors[i];
	return out;
}


int main()
{
	srand(time(0));
	Matrix<float> A(5,4, 1.2, -2.1, 3.5);
	std::cout << A;
	Matrix<float> B(6, 5, 5.9, -5.1, -4.2);
	std::cout << B;

	if (A.CalculateP() > 0) A.Transform(A.ArithmeticAverage());
	Vector<float> A_vector = A.GetVector();
	std::cout << A_vector;
	

	system("pause");
	return 0;
}
