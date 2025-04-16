#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix {
	public:
		// Constructor to initialize the matrix with given rows and columns
		Matrix(int r, int c) : rows(r), columns(c) {
			entries = new int*[rows];
			for (int i = 0; i < rows; i++) {
				entries[i] = new int[columns];
			}
		}
		// Destructor to free allocated memory
		~Matrix() {
			for (int i = 0; i < rows; i++) {
				delete[] entries[i];
			}
			delete[] entries;
		}
		// Overloaded assignment operator to set values of entries
		Matrix& operator=(const int* entries) {
			for (int i = 0; i < rows; i++) {
				delete[] this->entries[i];
			}
			delete[] this->entries;
			this->entries = new int*[rows];
			for (int i = 0; i < rows; i++) {
				this->entries[i] = new int[columns];
				for (int j = 0; j < columns; j++) {
					this->entries[i][j] = entries[i * columns + j];
				}
			}
			return *this;
		}
		// Overloaded assignment operator to copy another matrix
		Matrix& operator=(const Matrix& other) {
			if (this == &other) return *this;
			for (int i = 0; i < rows; i++) {
				delete[] entries[i];
			}
			delete[] entries;
			rows = other.rows;
			columns = other.columns;
			entries = new int*[rows];
			for (int i = 0; i < rows; i++) {
				entries[i] = new int[columns];
				for (int j = 0; j < columns; j++) {
					entries[i][j] = other.entries[i][j];
				}
			}
			return *this;
		}
		// Overloaded insertion operator to print the matrix
		friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
			for (int i = 0; i < matrix.rows; i++) {
				for (int j = 0; j < matrix.columns; j++) {
					os << matrix.entries[i][j] << " ";
				}
				os << std::endl;
			}
			return os;
		}
		// Overloaded addition operator to add two matrices
		Matrix operator+(const Matrix& other) const {
			if (rows != other.rows || columns != other.columns) {
				throw std::invalid_argument("Matrices must have the same dimensions for addition.");
			}
			Matrix sum(rows, columns);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					sum.entries[i][j] = entries[i][j] + other.entries[i][j];
				}
			}
			return sum;
		}
		// Overloaded subtraction operator to subtract two matrices
		Matrix operator-(const Matrix& other) const {
			if (rows != other.rows || columns != other.columns) {
				throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
			}
			Matrix difference(rows, columns);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					difference.entries[i][j] = entries[i][j] - other.entries[i][j];
				}
			}
			return difference;
		}
		// Overloaded scalar multiplication operator to multiply a matrix by a scalar
		Matrix operator*(int scalar) const {
			Matrix product(rows, columns);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					product.entries[i][j] = entries[i][j] * scalar;
				}
			}
			return product;
		}
		// Reversed scalar multiplication operator to multiply a scalar by a matrix
		friend Matrix operator*(int scalar, const Matrix& matrix) {
			return matrix * scalar;
		}
		// Overloaded multiplication operator to multiply two matrices
		Matrix operator*(const Matrix& other) const {
			if (columns != other.rows) {
				throw std::invalid_argument("Matrices must have compatible dimensions for multiplication.");
			}
			Matrix product(rows, other.columns);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < other.columns; j++) {
					product.entries[i][j] = 0;
					for (int k = 0; k < columns; k++) {
						product.entries[i][j] += entries[i][k] * other.entries[k][j];
					}
				}
			}
			return product;
		}
		// Transpose operator to transpose the matrix
		Matrix t() const {
			Matrix transposed(columns, rows);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					transposed.entries[j][i] = entries[i][j];
				}
			}
			return transposed;
		}
	private:
		int rows; // Number of rows
		int columns; // Number of columns
		int** entries; // Two-dimensional array to hold matrix entries
};

#endif // MATRIX_H
