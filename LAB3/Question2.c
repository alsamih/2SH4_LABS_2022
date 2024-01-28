#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/
	FILE *input = fopen(filename, "r"); //initializes file to read
	fscanf(input, "%d", sizePtr);
	class_list = calloc(*sizePtr, sizeof(student)); //allocates memory

	for (int i=0; i < *sizePtr; i++) //forloop to loop through each line in the file
	{
		student *k = calloc(1, sizeof(student)); //allocates memory for each line in the file
		fscanf(input, "%d", &k->student_id); //scans the line for the student ID and adds it to k
		fscanf(input, "%s", k->first_name);//scans the line for the first name and adds it to k
		fscanf(input, "%s", k->last_name);//scans the line for the last name and adds it to k
		class_list[i] = k; //places the variable k into array
	}

	fclose(input);

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{

	/*write your implementation here and update the return accordingly*/

	int i;


	for (i=0; i<size; i++) //loops through list
	{
		int k = list[i]->student_id; //assigns k to the student ID in index i
		if (k == idNo)
		{
			return i; //returns index
		}
	}

	return -1;
}


void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	int i,x, list_index;
	FILE *file = fopen(filename, "r"); //opens and reads file

	for (i=0; i< size; i++)
	{
		fscanf(file, "%d", &x); //assign student ID to x
		list_index = find(x, list, size); // calls on function to find the index of the student

		fscanf(file, "%d %d", &list[list_index]->project1_grade , &list[list_index]->project2_grade);

	}


}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	int i;
	double average;

	for (i=0; i<size; i++) //loops through each index in array list[]
	{
	average = ((list[i]->project1_grade) + (list[i]->project2_grade)) / 2.0; // finds the average grade for each student
	list[i]->final_grade = average; //changes the final grade in the list for each student to the average grade

}
}

void output_final_course_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	FILE *file = fopen(filename, "w"); //opens file to write in
	int i;
	fprintf(file, "%d", size); // prints the number of students at the top of the file
	for (i=0; i<size; i++)//loops through each index in array list[]
	{
		fprintf(file, "\n%d %lf", list[i]->student_id, list[i]->final_grade); //prints the student ID and average on each line
	}

	fclose(file);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int i,x;

	for (i=0; i<*sizePtr; i++) //loops through each student in list[]
	{
		if ((list[i]->student_id) == idNo) //if the student ID is the same as idNo
		{
			free(list[i]); //removes the student from the allocated memory
			x = 1; // keeps track of how many students are removed
		}

	}

	if (x == 0) // if the student is not found in the list
	{
		printf("The ID '%d' is not found in the list", idNo);
	}
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/

	free(list); //deletes everything in the list

		*sizePtr = 0; //sets the number of students to 0

}


int student_grades(char *students_files, char *grades_files, char *output_files ){
    int size;
    student **list = create_class_list(students_files,&size); //calls on function to create list

    find(8879, list, size); // calls on function to find the index of the student with ID '8879'
    input_grades(grades_files, list, size);
    compute_final_course_grades(list, size);
    int listsize = size;
    output_final_course_grades(output_files, list, size); //calls on function to output the final grade

    withdraw(3897, list, &size);
    size--;
    withdraw(5778, list, &size);
    size--;
    withdraw(2265, list, &size);
    size--;

    destroy_list(list,&size); // calls on function to delete everything in the class list

return listsize;
}

