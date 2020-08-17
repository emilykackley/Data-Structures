/* File: BST.h
*  Purpose: Class definition for a binary search tree
*/

#ifndef BST_H
#define BST_H

#include "bnode.h"
#include "binaryTree.h"

template <class T>
class BST : public BinaryTree<T>
{
	public:
		//Purpose: default constructor
		//Postconditions: (see BinaryTree default constructor)
		BST() {
			//automatically calls BinaryTree destructor
		}

		//Purpose: destructor
		//Postconditions: (see BinaryTree default destructor)
		~BST() {
			//automatically calls BinaryTree destructor
		}

		//Purpose: determine whether or not a specified value is in this tree
		//Parameters: x is specified value to be found
		//Returns: true if x is in this tree; otherwise returns false
		bool find(const T& x)const;

		//Purpose: insert the specified value into this tree
		//Parameters: x is value to be inserted
		//Postcondtions: if x already exists in this tree, that node's count is
		//  incremented; otherwise, a new node with data value x and count 1
		//  is added to this tree, and m_size is incremented
		void insert(const T& x);

		//Purpose: determine whether or not this tree is equivalent to a 
		//  specified tree
		//Parameters: rhs is the tree to be compared to this tree
		//Returns: if the trees are exactly the same in terms of structure and
		//  content, return true; otherwise, return false
		bool operator==(const BST<T>& rhs) const;

	private:
		//Purpose: insert the specified value into this tree
		//Parameters: x is the value to be inserted, nodePtr is the pointer
		//  that points where to start the traversal
		void insertStartingAtNode(const T& x, BNode<T>*& nodePtr);

		//Purpose: determine whether or not a specified value is in the tree
		//Parameters: x is the value to be found, nodePtr is the pointer
		//  that points where to start the traversal
		//Returns: true if x is in the tree, false if not
		bool findStartingAtNode(const T& x, BNode<T>* nodePtr)const;
};
#include "bst.hpp"
#endif //