#pragma once
#include "DynArray.h"

template<class T>
class BinaryHeap :
	public DynArray<T>
{
public:
	BinaryHeap();
	~BinaryHeap();

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
		for (unsigned int i = 0; i < size()-1; ++i)
		{
			int parent = (i - 1) / 2;
			if (i > 0)
			{
				if (DynArray<T>::array[i] < DynArray<T>::array[parent])
				{
					temp = DynArray<T>::array[i];
					DynArray<T>::array[i] = DynArray<T>::array[parent];
					DynArray<T>::array[parent] = temp;
				}
			}
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
		delete[] DynArray<T>::array;
		DynArray<T>::array = nullptr;
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