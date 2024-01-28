
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){


	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/

	int i,j;

		if (row <= 0) //checks if the is 0 or less
		{
			rowsNum = 3; //replaces row with 3
		}
		else
		{
			rowsNum = row;
		}

		if (col <= 0) //checks if column is 0 or less
		{
			colsNum = 3; // replaces column with 3

		}
		else
		{
			colsNum = col;
		}

		matrixData = (int **)malloc(rowsNum*sizeof(int*)); //allocates memory for the number of rows


		for (i = 0 ; i < rowsNum ; ++i ) //loops through each orw in matrix
		{

		matrixData[i] = (int*) malloc(colsNum*sizeof(int)); // allocates space for each row

			    for (j = 0 ; j < colsNum ; ++j ) //loops through each column in the row
			    {
			    matrixData[i][j]=0; //sets the element to 0
			    }
		}


	}

Matrix::Matrix(int row, int col, int** table){

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/
this->rowsNum=row;
this->colsNum=col;
this->matrixData=NULL;
this->matrixData=(int**)malloc(this->rowsNum*sizeof(int*));
int i,j;

for (i = 0 ; i < this->rowsNum ; ++i ) //loops through the rows in the matrix
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (i = 0 ; i < this->rowsNum ; ++i ) //loops through each column in the matrix
        for (j = 0 ; j < this->colsNum ; ++j )
            this->matrixData[i][j]=table[i][j];

}

int Matrix::getElement(int i, int j){


    if (i >= this->rowsNum || i<0 || j >= this->colsNum || j<0)
    {
        throw out_of_range("Invalid indexes."); //if values of i and j are invalid, it prints out this statement
        return -1;
    }

    return matrixData[i][j];


}
bool Matrix::setElement(int x, int i, int j){

	if((i>=0 && i< this->rowsNum) && (j>=0 && j< this->colsNum)) //checks if the values of i and j are valid
	{
		matrixData [i][j] = x; //set the element in the matrix to x

		return true;
	}

	    return false;
	}


Matrix Matrix::copy(){

	/* fix the code and write your implementation below */
	Matrix copy=  Matrix(this->rowsNum, this->colsNum, this->matrixData); //copies matrix

    // Matrix copy=  Matrix(rowsNum,colsNum );


    return  copy;


}


void Matrix::addTo( Matrix m ){
	int i,j;

	if ((this -> rowsNum != m.rowsNum) ||(this -> colsNum != m.colsNum) ) //checks if the operation is possible
	{
		throw invalid_argument("Invalid operation");
	}

	for (i = 0; i< m.rowsNum; i++)
	{
		for (j=0; i< m.colsNum; j++){
			this -> matrixData[i][j] = this -> matrixData[i][j] + m.matrixData[i][j]; // adds the values from the other matrix
	}

	}


}

Matrix Matrix::subMatrix(int i, int j){

    /* The exception detail message should read: "Submatrix not defined"*/
int k,t;

	 if (i >= this->rowsNum || i<0 || j >= this->colsNum || j<0) //checks to see if values of i and j are acceptable
	    {
	        throw out_of_range("Submatrix not defined");
	    }

	    /* fix the code and write your implementation below */
	    Matrix subM = Matrix (i+1, j+1);

	    for (k = 0; k <= i; k++) //loops through every row in matrix
	    {
	        for (t = 0; t <= j; t++) //loops through every element in the row
	        {
	            subM.matrixData[k][t] = (this->matrixData[k][t]); //adds elements to the subM matrix
	        }
	    }
	    return  subM;
	}



int Matrix::getsizeofrows(){



	/* update below return */
	return this->rowsNum; //returns row value
}


int Matrix::getsizeofcols(){



	/* update below return */
    return this->colsNum; //returns value of column
}


bool Matrix::isUpperTr(){

	/* write your implementation here and update return accordingly */
	int i,j,sum= 0 ;

	for (i=0; i< rowsNum; i++ ) //loops through each row in matrix
	{
		for (j=i+1; j<colsNum; j++) //loops through each element in the row
		{
			sum = sum + matrixData[i][j];

		}
	}

	if (sum != 0)//if all the values in the diagonal don't add up to 0
	{

		return false;
	}
	  return true;
}



string Matrix::toString(){

	string output=""; //ooutput is an empty string

	int i,j;

	for(i=0; i<this->rowsNum; i++) //loops through all the rows in matrix
	{
		for (j = 0; j< this->colsNum; j++) //loops through each element in the row
		{
			output = output + to_string(this->matrixData[i][j]) + ' '; //inputs matrix element into the string

		}

		output = output +'\n';

	}
	//return output;
	 return output;
}
