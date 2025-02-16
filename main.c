#include <stdio.h>
#include <stdlib.h>
#include "my_array_library.h"

void inputMatrix(float matrix[MAX_SIZE][MAX_SIZE], int matrix_number, int *rows, int *cols) 
{
    int i, j;
    
    while (1) 
	{
        printf("\nEnter row size of the matrix: ");
        scanf("%d", rows);
    
        if (*rows > MAX_SIZE) 
		{
            printf("\nRow size cannot be greater than %d.\n", MAX_SIZE);
        } 
		else 
		{
            break;
        }
    }
    
    while (1) 
	{
        printf("\nEnter column size of the matrix: ");
        scanf("%d", cols);
    
        if (*cols > MAX_SIZE) 
		{
            printf("\nColumn size cannot be greater than %d.\n", MAX_SIZE);
        } 
		else 
		{
            break;
        }
    }
    
    for (i = 0; i < *rows; ++i) 
	{
        for (j = 0; j < *cols; ++j) 
		{
            printf("\nEnter row %d, column %d value of %dx%d matrix %d: ", i + 1, j + 1, *rows, *cols, matrix_number);
            scanf("%f", &matrix[i][j]);
        }
    }
}

void inputVector(float vector[MAX_SIZE], int vector_number, int vector_size) 
{
    int i;
    for (i = 0; i < vector_size; ++i) 
	{
        printf("\nElement [%d] of %d-dimensional vector %d: ", i + 1, vector_size, vector_number);
        scanf("%f", &vector[i]);
    }
}

void printMatrixAndVector(float matrix[MAX_SIZE][MAX_SIZE], float vector[MAX_SIZE], int rows, int cols, int matrix_number) 
{
    int i, j;
    printf("\nMatrix A%d and Vector b%d in the form Ax = b:\n", matrix_number, matrix_number);
    for (i = 0; i < rows; ++i) 
	{
        for (j = 0; j < cols; ++j) 
		{
            printf("%4.1f  ", matrix[i][j]);
        }
        printf("  x[%d]  =  %.1f\n", i + 1, vector[i]);
    }
}

void printSortedMatrixAndVector(float matrix[MAX_SIZE][MAX_SIZE], float vector[MAX_SIZE], int rows, int cols, int matrix_number) 
{
    int i, j;
    printf("\nSorted matrix A%d and Vector b%d in descending order in the form Ax = b:\n", matrix_number, matrix_number);
    for (i = 0; i < rows; ++i) 
	{
        printf("%6.1f  =  x[%d]  ",  vector[i], i + 1);
        for (j = 0; j < cols; ++j) 
		{
            printf("%4.1f   ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, rows1, cols1, rows2, cols2;
    float a;
    float my_arr[MAX_SIZE][MAX_SIZE], my_arr2[MAX_SIZE][MAX_SIZE];
    float vector[MAX_SIZE], vector2[MAX_SIZE];
    float L[MAX_SIZE][MAX_SIZE], U[MAX_SIZE][MAX_SIZE];
    float x[MAX_SIZE];
    
    inputMatrix(my_arr, 1, &rows1, &cols1);
    inputVector(vector, 1, rows1);
    inputMatrix(my_arr2, 2, &rows2, &cols2);
    inputVector(vector2, 2, rows2);
	
	printf("\nMatrix A1:\n____________\n");
    printMatrixAndVector(my_arr, vector, rows1, cols1, 1);
    
    printf("\nMatrix A2:\n____________\n");
    printMatrixAndVector(my_arr2, vector2, rows2, cols2, 2);

	printf("\nEnter a number to search in matrix 1: ");
	scanf("%f", &a);
	
	searchValue(rows1, cols1, a, my_arr);
	nonRepeated(rows1, cols1, my_arr);
	findMinNumber(rows1, cols1, my_arr);
	findMaxNum(rows1, cols1, my_arr);
	sortRowsDescending(my_arr, rows1, cols1);
	printf("\nSorted matrix in descending order: \n");
	printSortedMatrixAndVector(my_arr, vector, rows1, cols1, 1);
	findTranspose(rows1, cols1, my_arr);
	findProduct(rows1, cols1, rows2, cols2, my_arr, my_arr2);
	isIdentityMatrix(rows1, cols1, my_arr);
	isSymmetricMatrix(rows1, cols1, my_arr);
    luDecomposition(my_arr, rows1, L, U);
    printf("\nLower triangular matrix (L):\n");
    for (i = 0; i < rows1; i++) {
        for ( j = 0; j < cols1; j++) {
            printf("%4.1f ", L[i][j]);
        }
        printf("\n");
    }

    printf("\nUpper triangular matrix (U):\n");
    for ( i = 0; i < rows1; i++) {
        for ( j = 0; j < cols1; j++) {
            printf("%4.1f ", U[i][j]);
        }
        printf("\n");
    }
    
    solveMatrixUsingGaussElimination(L, U, rows1, vector, x);
    printf("Solution Vector x:\n");
    for ( i = 0; i < rows1; i++) 
	{
    	printf("x[%d] = %.1f\n", i+1, x[i]);
    }
}

