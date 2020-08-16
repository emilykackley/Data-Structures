/* File: Vector.hpp
*  Purpose: Implements functions for Vector Class
*/

#include "Vector.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::log;
using namespace std;

template <class T>
void Vector<T>::clear()
{
	m_size = 0;
	m_max_size = 0;
	delete[]m_data;
	m_data = NULL;
}

template <class T>
void Vector<T>::push_back(const T& x)
{
	if (m_size == 0)
	{
		m_data = new T[2];
		m_max_size = 2;
	}

	if (m_size + 1 >= m_max_size)
	{
		T* temp = new T[2 * m_max_size];
		for (int z = 0; z < m_size; z++)
		{
			temp[z] = m_data[z];
		}
		delete[]m_data;
		m_data = temp;
		m_max_size = 2 * m_max_size;
	}
	m_data[m_size] = x;
	m_size++;
}

template <class T>
void Vector<T>::remove(const T& x)
{
	if (m_size == 0)
	{
		return;
	}
	bool c = false;
	int d = 0;
	while (c == false || d < m_size)
	{
		if (m_data[d] == x)
		{
			if (m_size == 1)
			{
				clear();
			}
			else
			{
				while (d < m_size)
				{
					m_data[d] = m_data[d + 1];
					d++;
				};
			}
			c = true;
			m_size = m_size - 1;
		}
		else
		{
			d++;
		}
	};
	if (m_size <= m_max_size / 4)
	{
		T* temp;
		temp = new T[m_max_size / 2];
		for (int e = 0; e < m_size; e++)
		{
			temp[e] = m_data[e];
		}
		m_max_size = m_max_size / 2;
		delete[]m_data;
		m_data = temp;
	}
}

template <class T>
void Vector<T>::pop_back()
{
	if (m_size == 0)
	{
		throw std::length_error("Vector already empty");
	}
	else
	{
		if (m_size == 1)
		{
			clear();
		}
		else
		{
			T* temp;
			temp = new T[m_size - 1];
			for (int f = 0; f < m_size - 1; f++)
			{
				temp[f] = m_data[f];
			}
			delete[]m_data;
			m_data = temp;
			m_size = m_size - 1;
			if (m_size <= m_max_size / 4)
			{
				T* resize;
				resize = new T[m_max_size / 2];
				for (int g = 0; g < m_size; g++)
				{
					resize[g] = m_data[g];
				}
				m_max_size = m_max_size / 2;
				delete[]m_data;
				m_data = resize;
			}
		}
	}
}

template <class T>
T& Vector<T>::operator[](unsigned int i)
{
	if (i < 0 || i >= m_size)
	{
		throw std::out_of_range("i < 0 or i > m_size");
	}
	return m_data[i];
}

template <class T>
const T& Vector<T>::operator[](unsigned int i)const
{
	if (i < 0 || i >= m_size)
	{
		throw std::out_of_range("i < 0 or i > m_size");
	}
	return m_data[i];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
	if (&rhs = this)
	{
		return(*this);
	}
	else
	{
		clear();
		m_size = rhs.m_size;
		m_max_size = rhs.m_max_size;
		T* temp;
		temp = new T[m_size];

		for (int i = 0; i < m_size; i++)
		{
			temp[i] = rhs.m_data[i];
		}

		delete[]m_data;
		m_data = temp;
		return(*this);
	}
}



