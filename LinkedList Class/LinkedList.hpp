/* File: LinkedList.hpp
   Purpose: Fuction Definintions for a LinkedList class
*/
#include "node.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

template <class T>
void LinkedList<T>::clear()
{
	while (m_head != NULL)
	{
		removeAtHead();
	};
	m_size = 0;
	m_head = NULL;
	m_tail = NULL;
}

template <class T>
bool LinkedList<T>::find(const T& x)const
{
	Node<T>* temp = m_head;
	while (temp != NULL)
	{
		if (temp->m_data == x)
		{
			return true;
		}
		else
		{
			temp = temp->m_next;
		}
	};
	return false;
}

template <class T>
void LinkedList<T>::insertAtHead(const T& x)
{
	Node<T>* ptrToNewNode;
	if (m_head == NULL)
	{
		ptrToNewNode = new Node<T>(x, NULL, NULL);
		m_head = ptrToNewNode;
		m_tail = ptrToNewNode;
		m_size = 1;
	}
	else
	{
		ptrToNewNode = new Node<T>(x, NULL, m_head);
		m_head->m_prev = ptrToNewNode;
		m_head = ptrToNewNode;
		m_size++;
	}
}

template <class T>
void LinkedList<T>::insertAtTail(const T& x)
{
	Node<T>* ptrToNewNode;
	if (m_head == NULL)
	{
		ptrToNewNode = new Node<T>(x, NULL, NULL);
		m_head = ptrToNewNode;
		m_tail = ptrToNewNode;
		m_size = 1;
	}
	else
	{
		ptrToNewNode = new Node<T>(x, m_tail, NULL);
		m_tail->m_next = ptrToNewNode;
		m_tail = ptrToNewNode;
		m_size++;
	}
}

template <class T>
void LinkedList<T>::removeAtHead()
{
	if (m_size == 0)
	{
		throw std::length_error("List Empty!");
	}
	else
	{
		Node<T>* temp = m_head;
		if (m_size == 1)
		{
			m_head = NULL;
			m_tail = NULL;
		}
		else
		{
			m_head = temp->m_next;
			m_head->m_prev = NULL;
		}
		delete temp;
		m_size--;
	}
}

template <class T>
void LinkedList<T>::removeAtTail()
{
	if (m_size == 0)
	{
		throw std::length_error("List Empty!");
	}
	Node<T>* temp = m_tail;
	m_tail = temp->m_prev;
	if (m_size == 1)
	{
		m_head = NULL;
		m_tail = NULL;
	}
	else
	{
		m_tail->m_next = NULL;
	}
	delete temp;
	m_size--;
}

template <class T>
bool LinkedList<T>::removeFirstOccurrence(const T& x)
{
	bool find_val = false;
	if (m_size == 0)
	{
		return false;
	}

	if (m_head->m_data == x)
	{
		removeAtHead();
		return true;
	}
	else if (m_tail->m_data == x)
	{
		removeAtTail();
		return true;
	}
	else
	{
		int i = 0;
		Node<T>* temp;
		temp = m_head;
		while ((temp != NULL) && (find_val == false))
		{
			if (temp->m_data == x)
			{
				m_size--;
				find_val = true;
				temp->m_prev->m_next = temp->m_next;
				temp->m_next - m_prev = temp->m_prev;
				delete temp;
			}
			else
				temp = temp->m_next;
			i++;
		};
		return find_val;
	}
	return false;
}

template <class T>
unsigned int LinkedList<T>::removeAllOccurrences(const T& x)
{
	int count = 0;
	while (removeFirstOccurrence(x))
		count++;
	return(count);
}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs)const
{
	if (m_size != rhs.m_size)
	{
		return false;
	}

	Node<T>* temp1 = m_head;
	Node<T>* temp2 = rhs.m_head;
	while (temp1 != NULL)
	{
		if (temp1->m_data != temp2->m_data)
		{
			return false;
		}
		else
		{
			temp1 = temp1->m_next;
			temp2 = temp2->m_next;
		}
	};
	return true;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	m_size = 0;
	clear();
	Node<T>* temp = rhs.m_head;
	while (temp != NULL)
	{
		insertAtTail(temp->m_data);
		temp = temp->m_next;
	};
	return *this;
}

