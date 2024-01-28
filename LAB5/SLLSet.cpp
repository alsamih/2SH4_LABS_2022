/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}
SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	int i;

	size = arrSize;
	head = NULL;

	for(i= size-1; i >= 0; i--) //for loop to move left in the list
	{
	SLLNode*x = new SLLNode(); //create node x
	 x->value = sortedArray[i]; //the value is each component of the array
	 x->next = head;
	 head = x; //set left node as head value

	}
}

int SLLSet::getSize()
{
	return size;
}

SLLSet SLLSet::copy()
{

	SLLNode*copy_node = new SLLNode(head->value, NULL); //set new node to a new list
	SLLSet*Copy = new SLLSet(); //create new set
	SLLNode*NODE = head; // set variable NODE as node head


	NODE = NODE->next;
	Copy->size = size;
	Copy->head = copy_node;

	while(NODE!=NULL) //while the node head NODE is not equal to null
	{
		copy_node->next = new SLLNode(NODE->value, NULL); //the next value of the node is the next value from variable NODE
		NODE = NODE->next;
		copy_node = copy_node->next; //sets the head as the current head
	}

	 return *Copy; //return copied set
}


bool SLLSet::isIn(int v)
{
	int i;
    SLLNode*x = head; //sets x as the node head


    for(i=0; i<size; i++)
    {

    	if(x->value == v) //if the value of the head of the node is equal to v
    	{
    		return true;
    	}

    	x = x->next; //continue through to the next head

    }

	return false;
}
void SLLSet::add(int v)
{
    if(!isIn(v)) //if the head value does not exist in previous function
    {
    	SLLNode*y = head; //assigns y as node head
    	if(y == NULL) //if y is after the tail
    		head = new SLLNode(v,NULL);

    else if(y -> value > v) //if y is bigger than v
    	head = new SLLNode(v,y);

    else
    {
    	while(y -> next!= NULL) //while next value of y is not NULL
    	{
    		if(y->next -> value > v)
    			break;
    		y = y->next; //replace y with the next value

    		}

    		y->next = new SLLNode(v, y->next);
    	}
    size++; //add 1 to size
	}
}
void SLLSet::remove(int v)
{

   if(isIn(v) == true) //if v exists in previous function
   	   {
	   SLLNode*node = head;
	   if(v == head -> value)
	   {
		   head = head->next;
		   size--; //subtract 1 from size

	   }

	   while (node -> next!=NULL)
	   {
		   if((node->next)->value == v) //if v is equal to next node value
		   {
			   node -> next = (node -> next) -> next; //value of next node will be the next, next node
			   size--;
		   }
		   else
		   {
			   node = node -> next;
		   }
	   }

   }
}

SLLSet SLLSet::setUnion(SLLSet s)
{

	SLLNode*list = s.head;
	SLLNode*main_list = head;
	SLLSet*set_union = new SLLSet(); //new set


	while(main_list!=NULL) //while node head is not NULL
	{

		set_union->add(main_list->value);
		main_list = main_list -> next;
	}

	while(list != NULL) //goes through each component in the inputted list
	{

		set_union->add(list->value);
		list = list->next;

	}

	 return *set_union; //returns new list set
}

SLLSet SLLSet::intersection(SLLSet s)
{
	SLLSet*int_set = new SLLSet(); //creates new set int_set
	SLLNode*main_list = head;


    while(main_list!=NULL) //while the node head is not equal to NULL
    {
    	if((isIn(main_list->value))&&(s.isIn(main_list->value)))
    	{

    		int_set->add(main_list->value); //add s into set int_set

    	}

    	main_list = main_list->next; //moves on to the next value

    }
	 return *int_set; //returns set int_set
}

SLLSet SLLSet::difference(SLLSet s)
{
    SLLSet*diff_s = new SLLSet();

	 if(s.head == NULL) //if the head of the set s is equal to NULL
	 {
		 *diff_s = copy(); //creates a copy of set diff_s
		 return *diff_s; //returns copy
	 }

	 SLLNode*temparature = head; //sets variable temperature as node head

	 while (temparature != NULL) //while node head does not equal to NULL
	 {
		 if(s.isIn(temparature->value)==true) //if the set value s does not exist
		 {
			 remove(temparature->value);
		 }
		 temparature = temparature->next; //set node temperature as next
	 }

	 if(head==NULL)
	 {
		 return *diff_s; //returns set diff_s
	 }
	 *diff_s = copy();
	 return *diff_s;

}

SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
	int i;

    SLLSet* set_union = new SLLSet(); //creates new set set_union

    for(i=0; i < size; i++) //loops through array
    {

    	*set_union = (*set_union).setUnion(sArray[i]);
    }

	 return *set_union;
}

string SLLSet::toString()
{

	int i;
   string x;

   SLLNode*m = head;

   for (i=0; i<size; i++)
   {
	   x = x + std:: to_string(m->value);
	   x = x + (i == size-1 ? "" : ", ");
	   m = m -> next;

   }

   return x;
}
