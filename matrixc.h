#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>

struct matrix {
	int rows; // Number of rows
	int columns; // Number of columns
	int** entries; // Two-dimensional array to hold matrix entries
};
typedef struct matrix Matrix;

// Function to initialize the matrix with given rows and columns
Matrix initEmptyMatrix(int rows, int columns) {
	Matrix matrix;
	matrix.rows = rows;
	matrix.columns = columns;
	matrix.entries = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		matrix.entries[i] = (int*)malloc(columns * sizeof(int));
		for (int j = 0; j < columns; j++) {
			matrix.entries[i][j] = 0;
		}
	}
	return matrix;
}
// Function to initialize the matrix with given rows, columns, and entries
Matrix initMatrix(int rows, int columns, int entries[rows][columns]) {
	Matrix matrix = initEmptyMatrix(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix.entries[i][j] = entries[i][j];
		}
	}
	return matrix;
}

// Function to display the matrix
void printMatrix(Matrix matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++) {
			printf("%d ", matrix.entries[i][j]);
		}
		printf("\n");
	}
}
// Addition function that adds two matrices
Matrix add(Matrix a, Matrix b) {
	if (a.rows != b.rows || a.columns != b.columns) {
		printf("Matrices must have the same dimensions for addition.\n");
		exit(1);
	}
	Matrix sum = initEmptyMatrix(a.rows, b.columns);
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.columns; j++) {
			sum.entries[i][j] = a.entries[i][j] + b.entries[i][j];
		}
	}
	return sum;
}
// Subtraction function that subtracts two matrices
Matrix subtract(Matrix a, Matrix b) {
	if (a.rows != b.rows || a.columns != b.columns) {
		printf("Matrices must have the same dimensions for subtraction.\n");
		exit(1);
	}
	Matrix difference = initEmptyMatrix(a.rows, b.columns);
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.columns; j++) {
			difference.entries[i][j] = a.entries[i][j] - b.entries[i][j];
		}
	}
	return difference;
}
// Multiplication function that multiplies a matrix by a scalar
Matrix multiplyScalar(Matrix a, int scalar) {
	Matrix product = initEmptyMatrix(a.rows, a.columns);
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.columns; j++) {
			product.entries[i][j] = a.entries[i][j] * scalar;
		}
	}
	return product;
}
// Multiplication function that multiplies two matrices
Matrix multiplyMatrix(Matrix a, Matrix b) {
	if (a.columns != b.rows) {
		printf("Matrices must have compatible dimensions for multiplication.\n");
		exit(1);
	}
	Matrix product = initEmptyMatrix(a.rows, b.columns);
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < b.columns; j++) {
			product.entries[i][j] = 0;
			for (int k = 0; k < a.columns; k++) {
				product.entries[i][j] += a.entries[i][k] * b.entries[k][j];
			}
		}
	}
	return product;
}
// Transpose function that transposes a matrix
Matrix transpose(Matrix a) {
	Matrix transposed = initEmptyMatrix(a.columns, a.rows);
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.columns; j++) {
			transposed.entries[j][i] = a.entries[i][j];
		}
	}
	return transposed;
}

#endif // MATRIX_H
