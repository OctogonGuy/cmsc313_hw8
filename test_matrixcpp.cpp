#include "matrixcpp.h"
#include <iostream>

int main() {
	Matrix A(2, 2);
	A = (int[]) {
		6, 4,
		8, 3,
	};
	Matrix B(2, 3);
	B = (int[]) {
		1, 2, 3,
		4, 5, 6,
	};
	Matrix C(2, 3);
	C = (int[]) {
		2, 4, 6,
		1, 3, 5,
	};
	Matrix D(2, 2);
	D = A + (3 * B) * C.t();
	std::cout << D << std::endl;
	return 0;
}
