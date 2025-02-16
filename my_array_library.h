#ifndef MY_ARRAY_LIBRARY_H
#define MY_ARRAY_LIBRARY_H

#define MAX_SIZE 10

// Function declarations
void searchValue(int row_size, int column_size, float a, float array[MAX_SIZE][MAX_SIZE]);
void nonRepeated(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]);
void findMinNumber(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]);
void findMaxNum(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]);
void sortRowsDescending(float matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void findTranspose(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]);
void findProduct(int row_size, int column_size, int row_size2, int column_size2, float array[MAX_SIZE][MAX_SIZE], float array2[MAX_SIZE][MAX_SIZE]);
int isIdentityMatrix(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]);
int isSymmetricMatrix(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]);
void luDecomposition(float matrix[MAX_SIZE][MAX_SIZE], int size, float L[MAX_SIZE][MAX_SIZE], float U[MAX_SIZE][MAX_SIZE]) ;
void ssolveMatrixUsingGaussElimination(float L[MAX_SIZE][MAX_SIZE], float U[MAX_SIZE][MAX_SIZE], int size, float *b, float *x);

#endif

