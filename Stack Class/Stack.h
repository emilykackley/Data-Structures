/* File: Stack.h
*  Purpose: Definition of a class for inheriting LinkedList
*/

#ifndef STACK_H
#define STACK_H

#include "node.h"
#include "LinkedList.h"

template <class T>
class Stack : private LinkedList<T>
{
	public:
		//Purpose: Default constructor
		//Parameters: N/A
		//Postconditions: Initialize LinkedList members to its default
		Stack() {};

		//Purpose: Destructor
		//Parameters: N/A
		//Postconditions: LinkedList: current size is 0, LinkedList contains
		//  no data and all memory deallocated
		//  Stack: contains no data and all memory deallocated
		~Stack() {};

		//Purpose: Effectively empties the list in LinkedList
		//Parameters: N/A
		//Postconditions: LinkedList: current size set to 0, head and tail ptrs
		//  set to NULL, and all dynamically allocated memory for nodes deallocated
		void clear();

		//Purpose: Accessor function for the current number of data values
		//  in the list for LinkedList
		//Parameters: N/A
		//Returns: the current size of the list
		const unsigned int size();

		//Purpose: Determines whether list from LinkedList is empty
		//Parameters: N/A
		//Returns: True if the list is empty otherwise it returns false
		bool isEmpty()const;

		//Purpose: Returns a reference to the top element of the stack
		//Parameters: N/A
		//Exceptions: If the stack is empty, it will throw a length_error
		//Postconditions: N/A
		const T& top()const;

		//Purpose:Inserts a value at the top of the stack
		//Parameters: x is the value placed at the top of the stack
		//Postconditions: The current size is incremented and x is now at the 
		//  top of the stack
		void push(const T& x);

		//Purpose: Removes the element at the top of the stack
		//Parameters: N/A
		//Exceptions: If the stack is empty, it will throw a length_error
		//Postconditions: The current size is decremented and the element at the
		//  top of the stack is removed
		void pop();

		//Purpose: A deep copy of the data in LinkedList from rhs into this 
		//Parameters: rhs is a stack accessing rhs LinkedList
		//Postconditions: This list contains the same data values and order as rhs 
		//  any memory previously used by this list is deallocated
		Stack<T>& operator=(const Stack<T>& rhs);

		//Purpose: Determines whether this linkedList is identical to rhs LinkedList
		//Parameters: rhs is the LinkedList to be compared
		//Returns: True if lists are identical, otherwise it returns false
		bool operator==(const Stack<T>& rhs)const;

};
#include "Stack.hpp"
#endif;