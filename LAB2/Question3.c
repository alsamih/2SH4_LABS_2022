#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){

	
	int i=1, x = ((N3*2)-1) , m, k=0;


	for (m=1 ; m<=x; m++) //loops through diagonals of the matrix
	{
		int j =1;
		for(i=m; i>0; i--) // loops through each row of the matrix
		{
			if ( i+j == (m+1) && (i<=N3) && (j<= N3)) // if statement to check is i+j are not bigger than N3
			{
				arr[k] = mat[i-1][j-1]; //inserts matrix element into arr[] in order of diagonal
				j++;
				k++;

			}

			else //if i+j is greater than N3
			{
				j++;
			}
		}
	}


}
