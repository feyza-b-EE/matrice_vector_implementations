#include <stdio.h>
#include "my_array_library.h"

// Function to search for a value in the array
void searchValue(int row_size, int column_size, float a, float array[MAX_SIZE][MAX_SIZE]) 
{
    int i, j;
    int found = 0;
    for (i = 0; i < row_size; i++) {
        for (j = 0; j < column_size; j++) {
            if (array[i][j] == a) {
                printf("\nNumber %.1f is in row: %d, column: %d \n", a, i + 1, j + 1);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("\nNumber %.1f is not found in the matrix.\n", a);
    }
}

// Function to find non-repeated elements in the array
void nonRepeated(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]) 
{
    int i, j, k, l;
    int count = 0;
    int found;

    for (i = 0; i < row_size; i++) {
        for (j = 0; j < column_size; j++) {
            float num = array[i][j];
            found = 0;
            
            for (k = 0; k < row_size; k++) {
                for (l = 0; l < column_size; l++) {
                    if (k != i || l != j) {
                        if (array[k][l] == num) {
                            found = 1;
                            break;
                        }
                    }
                }
                if (found) break;
            }
            if (!found) {
                printf("\nNumber %.1f in row: %d, column: %d is the non-repeated element in the matrix.\n", num, i + 1, j + 1);
                count++;
            }
        }
    }

    printf("\nThere are %d non-repeated numbers in total.\n", count);
}

// Function to find the minimum number in the array
void findMinNumber(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    float min = array[0][0];

    for (i = 0; i < row_size; i++) {
        for (j = 0; j < column_size; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }

    printf("\nNumber %.1f is the minimum number of the matrix.\n", min);
}

// Function to find the maximum number in each row of the array
void findMaxNum(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < row_size; i++) {
        float max = array[i][0];
        for (j = 0; j < column_size; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }

        printf("Number %.1f is the maximum number of the %dth row.\n", max, i + 1);
    }
}

void sortRowsDescending(float matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) 
{
    int i, j, k;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            for (k = 0; k < cols - j - 1; k++) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    float temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

// Function to find the transpose of the array
void findTranspose(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    float t_array[MAX_SIZE][MAX_SIZE]; 

    for (i = 0; i < row_size; i++) {
        for (j = 0; j < column_size; j++) {
            t_array[j][i] = array[i][j];
        }
    }

    printf("\nTranspose of the matrix:\n______________\n");
    
    for (i = 0; i < column_size; i++) {
        for (j = 0; j < row_size; j++) {
            printf("%4.1f ", t_array[i][j]);
        }
        printf("\n");
    }
}

// Function to find the product of two matrices
void findProduct(int row_size, int column_size, int row_size2, int column_size2, float array[MAX_SIZE][MAX_SIZE], float array2[MAX_SIZE][MAX_SIZE]) {
    int i, j, k;
    float p_array[MAX_SIZE][MAX_SIZE] = {0}; 
	
	printf("\n______________\n");
	
    if (column_size != row_size2) {
        printf("\nProduct of the matrices cannot be computed.\n");
        return;
    }

    for (i = 0; i < row_size; i++) {
        for (j = 0; j < column_size2; j++) {
            for (k = 0; k < column_size; k++) {
                p_array[i][j] += array[i][k] * array2[k][j];
            }
        }
    }

    printf("\nProduct of the two matrices:\n______________\n");
    for (i = 0; i < row_size; i++) {
        for (j = 0; j < column_size2; j++) {
            printf("%4.1f ", p_array[i][j]); 	
        }
        printf("\n");
    }
}

// Function to check if the matrix is an identity matrix
int isIdentityMatrix(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE])
{
    int i, j;
    if (row_size != column_size) {
        printf("\nThe matrix is not a square matrix therefore it's not an identity matrix\n");
        return 0;
    }

    for (i = 0; i < row_size; i++) {
        for (j = 0; j < column_size; j++) {
            if (i == j && array[i][j] != 1) {
                printf("\nThe matrix is not an identity matrix.\n");
                return 0;
            } else if (i != j && array[i][j] != 0) {
                printf("\nThe matrix is not an identity matrix.\n");
                return 0;
            }
        }
    }
    printf("\nThe matrix is an identity matrix.\n");
    return 1;
}

// Function to check if the matrix is symmetric
int isSymmetricMatrix(int row_size, int column_size, float array[MAX_SIZE][MAX_SIZE]) 
{
    int i, j;
    for (i = 0; i < row_size; i++) {
        for (j = 0; j < column_size; j++) {
            if (array[i][j] != array[j][i]) {
                printf("\nThe matrix is not a symmetric matrix.\n");
                return 0;
            }
        }
    }
    printf("\nThe matrix is a symmetric matrix.\n");
    return 1;
}

// LU decomposition algorithm

void luDecomposition(float matrix[MAX_SIZE][MAX_SIZE], int size, float L[MAX_SIZE][MAX_SIZE], float U[MAX_SIZE][MAX_SIZE]) 
{
    int i, j, k;
    // Initialize L and U matrices
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j) L[i][j] = 1;  // Diagonal elements of L are 1
            else L[i][j] = 0;
            U[i][j] = 0; // Initialize U with zeros
        }
    }

    // Compute LU decomposition
    for (i = 0; i < size; i++) {
        // Compute upper triangular matrix U
        for (j = i; j < size; j++) {
            float sum = 0;
            for (k = 0; k < i; k++) {
                sum += (L[i][k] * U[k][j]);
            }
            U[i][j] = matrix[i][j] - sum;
            if (U[i][i] == 0) {
                // Handle division by zero or other arithmetic errors
                printf("Error: Division by zero or arithmetic error occurred.\n");
                return;
            }
        }

        // Compute lower triangular matrix L
        for (j = i + 1; j < size; j++) {
            float sum = 0;
            for (k = 0; k < i; k++) {
                sum += (L[j][k] * U[k][i]);
            }
            L[j][i] = (matrix[j][i] - sum) / U[i][i];
        }
    }
}

// Solve equations using LU decomposition
void solveMatrixUsingGaussElimination(float L[MAX_SIZE][MAX_SIZE], float U[MAX_SIZE][MAX_SIZE], int size, float *b, float *x) 
{
    int i, j;
    float y[MAX_SIZE]; // Temporary vector for solving Ly = b

    // Solve Ly = b using forward substitution
    for (i = 0; i < size; i++) {
        y[i] = b[i];
        for (j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }

    // Solve Ux = y using backward substitution
    for (i = size - 1; i >= 0; i--) {
        if (U[i][i] == 0) {
            // Handle division by zero or other arithmetic errors
            printf("Error: Division by zero or arithmetic error occurred.\n");
            return;
        }
        x[i] = y[i];
        for (j = i + 1; j < size; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i]; // Divide by the diagonal element of U
    }
}



