/* File: bst.hpp
*  Purpose: Class implementation for a binary search tree
*/

#include <iostream>
#include "binaryTree.h"
#include "bst.h"
#include <stdexcept>
#include <string>
using namespace std;

template <class T>
void BST<T>::insert(const T& x)
{
	insertStartingAtNode(x, BinaryTree<T>::m_root);
}

template <class T>
void BST<T>::insertStartingAtNode(const T& x, BNode<T>*& nodePtr)
{
	if (nodePtr == NULL)
	{
		nodePtr = new BNode<T>(x);
		BinaryTree<T>::m_size++;
	}
	else
	{
		if (x < nodePtr->m_data)
			insertStartingAtNode(x, nodePtr->m_left);
		else if (x > nodePtr->m_data)
			insertStartingAtNode(x, nodePtr->m_right);
		else if (x == nodePtr->m_data)
			nodePtr->m_count++;
	}
}

template <class T>
bool BST<T>::find(const T& x) const
{
	return(findStartingAtNode(x, BinaryTree<T>::m_root));
}

template <class T>
bool BST<T>::findStartingAtNode(const T& x, BNode<T>* nodePtr)const
{
	if (nodePtr == NULL)
		return false;
	if (nodePtr->m_data == x)
		return true;
	if (x < nodePtr->m_data)
		return(findStartingAtNode(x, nodePtr->m_left));
	else
		return(findStartingAtNode(x, nodePtr->m_right));
}

template<class T>
bool BST<T>::operator==(const BST<T>& rhs)const
{
	return BinaryTree<T>::operator delete(rhs);
}
