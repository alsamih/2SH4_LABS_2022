

#include "Questions.h"



int Q1_for(){
	int sum =0, i;
	
	// calculate your sum below..this has to use for loop
	for (i=30; i<= 1000; i++)
	{
	
	if ( i % 4 == 0 )
		{
		sum = sum + i;
		}
	
	}
	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_while()
{
	int sum = 0, i= 30;


	// calculate your sum below..this has to use while loop
	while ( i <= 1000)
	{
		i = i + 1;
	 if ( i % 4 == 0)
	 {
		 sum = sum + i;

	 }
	
	}
	// here, we return the calcualted sum:
	return sum;
}
int Q1_do(){
	int sum = 0, i = 30;
	
	// calculate your sum below..this has to use do-while loop
	do
	{
		if (i%4 == 0)
		{
			sum += i;
		}
		i+=1;
	}
	while(i<=1000);

	  
	
	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit = 0;
	
	// Do your coding below to check
	int big_n = 99999;
	int small_n = 10000;
	
	if ((Q2_input <= big_n && Q2_input >= small_n) || (Q2_input >= -big_n && Q2_input <= -small_n))
	{
		IsFiveDigit = 1;
	}


	            
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program shouldreturn -1
*/	
	// this is the varaible that holds the out value to return
	float GPA;
	
	if (90 <= Q3_input && Q3_input <= 100)
		{
			GPA = 4;
		}

	else if (80 <= Q3_input && Q3_input <= 89)
		{
			GPA = 3;
		}

	else if (70 <= Q3_input && Q3_input <= 79)
		{
			GPA = 2;
		}

	else if (60 <= Q3_input && Q3_input <= 69)
		{
			GPA = 1;
		}

	else if (0 <= Q3_input && Q3_input <= 59)
		{
			GPA = 0;
		}

	else
		{
			GPA = -1;
		}
	// Do your coding below to calculate the GPA variable value
	
	 
	
	
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){

    // this is the varaible that holds the pi value to return
    double pi=0;
    pi = 4;
    int i=0, n=0;




     //Do your coding below to calculate the pi value
    for (i = 0; 0 <= Q4_input ; i++)
    {
        if (i % 2)
        {
        	pi = pi+(4/n);
        	n= n+2;
        }

        else
        {
        	(pi = pi-(4/n));
            n= n+2;
        }
    }


    // finally, we return the pi value
    return pi;
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0, side2, side1, hyp;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/
	for (side2=1; side2 <= 400; side2++)
	{
		for(side1 = 1; side1  <= side2; side1++)
		{
			for (hyp=1; hyp <= 400; hyp++)
				{
			        if( (side2*side2)+(side1*side1) == (hyp*hyp))
			        {
			          totNumTribles += 1;
			        }

				}
		}
	}
	


	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
	 //counts is teh variable that should hold the total number of found perfect numbers
	        //you should update it within your code and return it at the end
	        int counts=0;


	        /*
	        *
	        *perfect is an array that you need to add into it any perfect number you find
	        *which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
	        *you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will
	        *autmoatically reflect in the main calling function.
	        */


	        int i = 0, j=0, sum=0;

	        for (i=1; i <= Q6_input; i++)
	        {
	        	for (j=(i-1); j>0; j--)
	        	{
	        		if (i % j == 0)
	        		{
	        			sum +=j;

	        		}
	        	}
	        	if (sum == i)
	        	{
	        		sum = 0;
	        		perfect[counts] = i;
	        		counts += 1;
	        	}
	        	else
	        	{
	        		sum = 0;
	        	}
	        }


		
		

	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0, remainder = 0, i = 1;
	
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	for (i=1; i<=7; i++)
	{
		remainder = Q7_input % 10;
		reversedInt = reversedInt *10;
		Q7_input = Q7_input/10;

		reversedInt = reversedInt + remainder;
	}
	
		return reversedInt;
	
}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0, remainder = 0, i = 1;
	
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	while (Q7b_input/1)
	{
		remainder = Q7b_input % 10;
		reversedInt = reversedInt * 10;
		Q7b_input = Q7b_input /10;

		reversedInt += remainder;
	}
	
	
	return reversedInt;

	
	
	
}
