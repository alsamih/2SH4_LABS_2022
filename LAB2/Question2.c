#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	int sum = 0;
	int i,j,x;
	int y = 0;

	for(i=0; i<N2; i++) //for loop goes through each row
	{
		for(j=0; j < N2; j++) //for loops goes through each column
		{
			if (j == i) //if indices are same then the element is the diagonal element
				{
				x = fabs(mat[i][j]);
				}
			else //if indices are not same then element is not a diagonal element
			{
				y += fabs(mat[i][j]); //add the elements in the row that are not diagonal elements
			}
			if (x > y)
					{
						sum += 1; // add one for each row that is diagonally dominant
					}

		}


	}
	
	if (sum == N2) //if the number of diagonally dominant rows = the number of rows
	{
		isDiag = 1; //the matrix is diagonally dominant
	}
	else {
		isDiag = 0; //the matrix is not diagonally dominant
	}
	


    return isDiag;
}
