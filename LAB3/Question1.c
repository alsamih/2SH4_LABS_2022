#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	int i,j, k=0;
	/*write your implementation here*/
	int str1_length = strlen(str1); //counts the number of characters in string 1
	int str2_length = strlen(str2); //counts the number of characters in string 2
	int total_size = str1_length + str2_length; //calculates total characters
	z = calloc(total_size + 1, sizeof(char)); //allocates memory for the amount of total characters

	for (i=0; i < str1_length; i++) //adds the first string into the list z[]
	{
		z[i] = str1[i];
	}

	for (j=i; j< total_size; j++) //adds string 2 to the rest of the list z[]
	{
		z[j] = str2[k];
		k += 1;

	}

	z[total_size + 1] = "\0"; //adds "\0" to the end of the list


	/* finally, return the string*/
	return z;
	
}
