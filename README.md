# Matrix Library for C and C++

## Authoring

Alexander Gill
UMBC
CMSC 313 - Spring 2025 - Mon/Wed 8:30AM-9:45AM
Homework 8 - Due 4/16/25

## Purpose of software

This is a library that allows user to create matrices and perform operations on them.

## Files

- `matrixc.h`: Library file for C
- `matrixcpp.h`: Library file for C++
- `test_matrixc.c`: Test file for C library that contains example usage
- `test_matrixcpp.cpp`: Test file for C++ library that contains example usage

## Build instructions

The build command should be in the following format:

```
[cxx] [library_file] [main_file] -o [executable_filename]
```

For example, to build the C++ library using the C++ test file, you would write

```
g++ matrixcpp.h test_matrixcpp.cpp -o test_matrix
```

The executable can then be run using the command

```
./test_matrix
```

## Testing methodology

Both the C and C++ test files show how to instantiate matrices and perform operations on them, but they are accomplished differently.

### C

When using the C library, the user must call the `initMatrix` function to create a matrix. The function takes three arguments: the number of rows, the number of columns, and a pointer to an array of integers.

```
Matrix A = initMatrix(2, 2, (int[2][2]) {
        {6, 4},
        {8, 3}
        });
```

To perform operations on the matrix, the user must call the appropriate function. For example, to add two matrices, the user would call the `addMatrix` function:

```
Matrix C = addMatrix(A, B);
```

To print the matrix, the user would call the `printMatrix` function:

```
printMatrix(A);
```

### C++

When using the C++ library, the user must create a matrix object using the `Matrix` class. The constructor takes two arguments: the number of rows and the number of columns. You then use the equals operator to assign values to the elements of the matrix:

```
Matrix A(2, 2);
A = {
    {6, 4},
    {8, 3}
};
```

To perform operations on the matrix, the user can use the overloaded operators. For example, to add two matrices, the user would use the `+` operator:

```
Matrix C = A + B;
```

To print the matrix, the user can use the `<<` operator:

```
std::cout << A << std::endl;
```
