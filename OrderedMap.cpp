#include <iostream>
#include <cmath>
#include <string>
#include "HashNode.h"
#include "OrderedMap.h"

using namespace std;

//======================================
OrderedMap::OrderedMap()
{
	this->v_size = 0;
	this->v_capacity = 10;
	this->data = new HashNode*[v_capacity];
}
OrderedMap::OrderedMap(int cap)
{
	this->v_capacity = cap;
	this->v_size = 0;
	this->data = new HashNode*[v_capacity];
}

OrderedMap::~OrderedMap()
{
	delete[] this-> data; // deallocating the dynamic memory

}

void OrderedMap::push_back(HashNode* element)
{
	// adding a HashNode to the ordered Map
	if (v_size == v_capacity)
	{
		HashNode** data1; //creating a new pointer
		int new_size = max(1, 2 * v_size); // accounting for when the size of the OrderedMap is zero
		data1 = new HashNode*[new_size];

		// copying all the elements from the old OrderedMap to the new one
		for (int i = 0; i < v_size; i++)
		{
			data1[i] = data[i];
		}
		if (data != NULL) { // deleting the current array
			delete[] data;
			data = data1; // setting the previous array to the current one
			v_capacity = new_size; // updating the size
		}

	}
	data[v_size++] = element;
	sort();
}

void OrderedMap::insert(int index, HashNode* element)
{
	if (index > v_size || index < 0) throw out_of_range("The Index exceeds the size of the OrderedMap");
	else if (index == v_size)
	{
		push_back(element);
		sort();
	}
	else
	{
		//extending the array if the OrderedMap is full
		if (v_size == v_capacity)// checking if the OrderedMap is full
		{
			HashNode** data1; //creating a new pointer
			int new_size = max(1, 2 * v_size); // accounting for when the size of the OrderedMap is zero
			data1 = new HashNode*[new_size];
			// copying all the elements from the old OrderedMap to the new one
			for (int i = 0; i < v_size; i++)
			{
				data1[i] = data[i];
			}
			if (data != NULL) { // deleting the current array
				for (int i=0; i<v_capacity; i++)
					delete data[i];
				delete[] data;
				data = data1; // setting the previous array to the current one
				v_capacity = new_size; // updating the size
			}

		}

		for (int i = v_size - 1; i >= index; i--) // moving all the elements until the index
		{
			data[i + 1] = data[i];
		} data[index] = element;
		v_size++; //incrementing the size
		sort(); // sorting the elements
	}

}
void OrderedMap::sort()
{
	//sorting the entires
	bool run = true;

	while (run)
	{
		run = false;
		for (int i = 1; i<v_size; i++)
		{
			HashNode* tmp1;
			HashNode* tmp2;
			if (data[i-1]->key > data[i]->key)
			{
				tmp1 = data[i-1];
				tmp2 = data[i];
				data[i] = tmp1;
				data[i-1] = tmp2;
				run = true;
			}
		}
	}
}

// creating a method to return the maximum HashNode in the array
HashNode* OrderedMap::maxNode()
{
	HashNode* _maxHashNode;
	if (v_size == 1) 
	{
		_maxHashNode = data[0];
		return _maxHashNode;
	}

	_maxHashNode = data[0];

	for (int i=1; i<v_size; i++)
	{
		if (data[i]->value > _maxHashNode->value)
		{
			_maxHashNode = data[i];
		}
	}
	return _maxHashNode;
}

int OrderedMap::search(string word)
{
	//implementing binary search for the word
	int lowInd = 0;
	int HighInd = v_size-1;
	int middleInd = 0;

	while(lowInd <= HighInd)
	{
		middleInd = ceil((lowInd+HighInd)/2);

		if (word > data[middleInd]->key)
		{
			lowInd = middleInd+1;	
		}
		else if (word< data[middleInd]->key)
		{
			HighInd = middleInd-1;
		}
		else if (word == data[middleInd]->key)
		{
		
			return data[middleInd]->value;
		}
		else if (lowInd == HighInd == middleInd)
		{
			return 0;
		}
	}
	return 0;
}
HashNode* OrderedMap::at(int index)
{
	if (empty() || (index > v_size - 1)) throw out_of_range("The index entered is out of range! OR the OrderedMap is empty!");
	else
	{
		return data[index];
	}
}
const HashNode* OrderedMap::front()
{
	if (empty()) throw runtime_error("The OrderedMap is Empty!");
	else {
		return data[0];
	}
}
const HashNode* OrderedMap::back()
{
	if (empty()) throw runtime_error("The OrderedMap is Empty!");
	else {
		return data[v_size - 1];
	}
}
int OrderedMap::size() const
{
	
	return v_size;
}
int OrderedMap::capacity() const
{
	return v_capacity;
}
bool OrderedMap::empty() const
{
	return (v_size == 0);
}
HashNode* OrderedMap::operator[](int index)
{
	// overloaded cosnstructor for [] to access the ordered map indeces
	if (empty() || (index > v_size - 1)) throw out_of_range("The index entered is out of range! OR the OrderedMap is empty!");
	else
	{
		return data[index];
	}
}
