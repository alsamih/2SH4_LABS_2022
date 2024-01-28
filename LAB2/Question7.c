#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){

	 int a = 0, b = 0, i=0, x=0,k=0;


	if(pos1[k1-1]>= pos2[k2-1]) //if statement to set the highest values of pos1 and pos2 into variable x
	{
		x = pos1[k1-1];
	}
	else{
		x = pos2[k2-1];
	}

	for(i=0; i<=(k1+k2); i++) //loops through every value of val3
		{

		if((pos1[a] == pos2[b]) && (pos1[a] == (i+1)) ) //if values of val1 and val2 = values of pos1
		{
			val3[k] = (val1[a] + val2[b]); // add values of val1 and val2
			pos3[k] = pos1[a];
			a++;
			b++;
			k++;
		}

		else // if values of val1 and val2 do not equal values of pos1
			{
			if(pos1[a]> pos2[b] && pos2[b] == (i+1)) //if values not found in k1
			{
			val3[k] = val2[b]; //add values of k2 to val3 and pos3
			pos3[k] = pos2[b];
			b++;
			k++;
			}

		else
			{
			if(pos1[a]< pos2[b] && pos1[a] == (i+1)) //if values is not found in k2
			{
			val3[k] = val1[a]; //add values of k1 to val3 and pos3
			pos3[k] = pos1[a];
			a++;
			k++;
			}


	else
		{
		if (i>x)
		{
			val3[i] = 0; //adds '0' to end of array
		}
		}

			}
			}

	}

}
