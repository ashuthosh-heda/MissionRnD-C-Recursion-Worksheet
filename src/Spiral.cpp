/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void spiralUtil(int **input, int rows, int columns, int *res,int ind,int inner){
	if (rows <= 0 || columns <= 0)
		return;

	if (rows == 1){
		for (int i = 0; i < columns; i++)
			res[ind++] = input[inner][inner + i];
		return;
	}

	if (columns == 1){
		for (int i = 0; i < rows; i++)
			res[ind++] = input[inner + i][inner];
		return;
	}

	for (int i = 0; i < columns - 1; i++)
		res[ind++] = input[inner][inner + i];

	for (int i = 0; i < rows - 1; i++)
		res[ind++] = input[inner + i][inner + columns - 1];

	for (int i = 0; i < columns - 1; i++)
		res[ind++] = input[inner + rows - 1][inner + columns - 1 - i];

	for (int i = 0; i < rows - 1; i++)
		res[ind++] = input[inner + rows - 1 - i][inner];

	spiralUtil(input, rows - 2, columns - 2, res, ind, inner + 1);
}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0)
		return NULL;
	if (input_array == NULL)
		return NULL;
	
	int *res = (int*)calloc(rows*columns, sizeof(int));

	spiralUtil(input_array, rows, columns, res, 0, 0);

	return res;
}
