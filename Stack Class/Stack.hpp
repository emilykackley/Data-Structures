/* File: Stack.hpp
*  Purpose: Function definitions of a class for inheriting LinkedList
*/

#include "node.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

template <class T>
void Stack<T>::clear()
{
	LinkedList<T>::clear();
}

template <class T>
const unsigned int Stack<T>::size()
{
	return(LinkedList<T>::size());
}

template <class T>
bool Stack<T>::isEmpty()const
{
	return(LinkedList<T>::isEmpty());
}

template <class T>
const T& Stack<T>::top()const
{
	if (!LinkedList<T>::isEmpty())
	{
		return(LinkedList<T>::m_tail->m_data);
	}
	throw std::length_error("queue is empty");
}

template <class T>
void Stack<T>::push(const T& x)
{
	LinkedList<T>::insertAtTail(x);
}

template <class T>
void Stack<T>::pop()
{
	LinkedList<T>::removeAtTail();
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{
	LinkedList<T>::operator=(rhs);
	return *this;
}

template <class T>
bool Stack<T>::operator==(const Stack<T>& rhs)const
{
	return LinkedList<T>::operator==(rhs);
}