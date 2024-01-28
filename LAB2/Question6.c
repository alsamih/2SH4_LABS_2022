#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){

	int k=0,i;

	for(i=0;i<size;i++)
	{
		if(source[i] != 0)
		{
			val[k] = source[i];
			pos[k] = i;
			k++;
		}
	}

	

}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

    int k = 0,i;

    for(i=0; i<m ; i++)
    	{
    	if(i == pos[k])
    	{
    		source[i] = val[k];
    		k++;
    	}
    	else
    	{
    		source[i] = 0;
    	}
    }

    
	

}
