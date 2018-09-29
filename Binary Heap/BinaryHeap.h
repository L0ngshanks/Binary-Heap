#pragma once
#include "DynArray.h"

template<class T>
class BinaryHeap :
	protected DynArray<T>
{
public:


	/////////////////////////////////////////////////////////////////////////////
// Function : enqueue
// Parameters : v - the item to add to the heap
// Notes : after the new item is added, this function ensures that the 
//	smallest value in the heap is in [0]
/////////////////////////////////////////////////////////////////////////////
	void enqueue(const T &v)
	{
		DynArray<T>::append(v);
		T temp;
		for (unsigned int i = size()-1; i > 0;)
		{
			int parent = (i - 1) / 2;
			if (DynArray<T>::array[i] < DynArray<T>::array[parent])
			{
				temp = DynArray<T>::array[i];
				DynArray<T>::array[i] = DynArray<T>::array[parent];
				DynArray<T>::array[parent] = temp;

				i = parent;
			}
			else
				break;
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : dequeue 
	// Return : the smallest item in the heap, or Type() if the heap is empty
	// Notes : after the smallest item is dequeued, this function ensures that 
	//	the smallest item is in [0]
	/////////////////////////////////////////////////////////////////////////////
	T dequeue()
	{
		T temp;
		T top = DynArray<T>::array[0];
		DynArray<T>::array[0] = DynArray<T>::array[size() - 1];
		DynArray<T>::Size--;
		for (unsigned int i = 0; i < size();)
		{
			unsigned int left = (i * 2) + 1;
			unsigned int right = (i * 2) + 2;
			if (left >= size())
				break;
			else if (right >= size())
			{
				if (DynArray<T>::array[i] > DynArray<T>::array[left])
				{
					temp = DynArray<T>::array[i];
					DynArray<T>::array[i] = DynArray<T>::array[left];
					DynArray<T>::array[left] = temp;

					i = left;
				}
				else
					break;
			}
			else
			{
				if (DynArray<T>::array[left] < DynArray<T>::array[right])
				{
					if (DynArray<T>::array[i] > DynArray<T>::array[left])
					{
						temp = DynArray<T>::array[i];
						DynArray<T>::array[i] = DynArray<T>::array[left];
						DynArray<T>::array[left] = temp;

						i = left;
					}
					else
						break;
				}
				else
				{
					if (DynArray<T>::array[i] > DynArray<T>::array[right])
					{
						temp = DynArray<T>::array[i];
						DynArray<T>::array[i] = DynArray<T>::array[right];
						DynArray<T>::array[right] = temp;

						i = right;
					}
					else
						break;
				}
			}
		}
		return top;
	}

	///////////////////////////////////////////////////////////////////////////////
	// Function : operator[]
	// Parameters : index - the index to access
	// Return : Type& - the item in the index
	/////////////////////////////////////////////////////////////////////////////
	T& operator[](int index)
	{
		return DynArray<T>::array[index];
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : clear	
	// Notes : clears the heap out
	/////////////////////////////////////////////////////////////////////////////
	void clear()
	{
		
		DynArray<T>::clear();
	}

	///////////////////////////////////////////////////////////////////////////////
	// Function : size
	// Return : the number of valid items in the heap
	/////////////////////////////////////////////////////////////////////////////
	unsigned int size()
	{
		
		return DynArray<T>::Size;
	}
};