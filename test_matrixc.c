#include "matrixc.h"
#include <stdio.h>

int main() {
	Matrix A = initMatrix(2, 2, (int[2][2]) {
			{6, 4},
			{8, 3}
			});
	Matrix B = initMatrix(2, 3, (int[2][3]) {
			{1, 2, 3},
			{4, 5, 6}
			});
	Matrix C = initMatrix(2, 3, (int[2][3]) {
			{2, 4, 6},
			{1, 3, 5}
			});
	Matrix D = add(A, multiplyMatrix(multiplyScalar(B, 3), transpose(C)));
	printMatrix(D);
	return 0;
}
