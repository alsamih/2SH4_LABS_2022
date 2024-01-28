#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){

int i,j, count=0, a=0;

for(i=0; i<26; i++) //loops through every letter in the alphabet, starting at 0 (a)
{
	for (j=0; word[j] != '\0'; j++)//loops through every character in the string word[]
		{
		if (word[j]==(a+97) || word[j] == (a+65)) //checks if the character in the corresponding indices is a letter in the alphabet
		{
			count ++; // adds 1 for each letter
		}

		}
	
	freq[a] = count; //inputs the number of counts for each letter
	a++; //adds 1 to a so the loop can check for the next letter
	count = 0;

}

   
}
