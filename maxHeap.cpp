#include <iostream>
#include <cmath>
#include <string>
#include <exception>
#include "HashNode.h"
#include "maxHeap.h"

using namespace std;

Heap::Heap()
{
	this->capacity = 10;
	this->array  = new HashNode*[capacity];
	this->size = 0;
}
Heap::Heap(int cap)
{
	this->capacity = cap;
	this->array  = new HashNode*[capacity];
	this->size = 0;
}

Heap::~Heap()
{
	delete[] array; // deleting the dynamically allocated memory
}

void Heap::adjustSize()
{
	// increasing the size of the heap if the current heap is full
	HashNode** newArray;
	int newCap = max(1, 2*capacity);
	newArray = new HashNode*[newCap];
	for (int i=0; i<size; i++)
	{
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
	capacity = newCap;
}

void Heap::insert(HashNode* node)
{
	// inserting to the max heap
	if (size == capacity){adjustSize();}
	array[size++] = node;

	siftup(size-1);
}
void Heap::siftup(int k)
{
	// sifting up from the bottom 
	if (parent(k) < 0 || (k > size-1) || array[k]->value < array[parent(k)]->value) return; // base case if there are no children
	else if (array[k]->value > array[parent(k)]->value)
	{
		int par = parent(k);
		HashNode* tmp1 = array[k];
		HashNode* tmp2 = array[par];

		array[k] = tmp2;
		array[par] = tmp1;
		siftup(par);
	}
}
void Heap::siftdown(int k)
{
	// no children
	if (left(k) > (size-1) && right(k) > (size-1)) return; // base case if there are no children
	if (left(k) <= (size-1) && right(k) > (size-1) && array[left(k)]->value > array[k]->value) // case for is there is one left child
	{
		HashNode* par = array[k];
		int lef = left(k);
		array[k] = array[lef];
		array[lef] = par;
	}
	if (left(k) <= (size-1) && (right(k) <= (size -1))) // case for if there are two children
	{
		int indexOfBiggerChild = (array[left(k)]->value > array[right(k)]->value ? left(k) : right(k));

		if (array[indexOfBiggerChild]->value > array[k]->value)
		{
			HashNode* par = array[k];
			HashNode* biggerNode = array[indexOfBiggerChild];
			array[k] = biggerNode;
			array[indexOfBiggerChild] = par;
			siftdown(indexOfBiggerChild);
		}
	}
}
// sorting the elements in the heap using heap sort
void Heap::sort()
{
	HashNode** newArray;
	newArray = new HashNode*[capacity];
	int newS = size;
	for(int i=0; i<newS; i++)
	{
		HashNode* maxim = getMax();
		removeMax();
		newArray[i] = maxim;
	}

	delete[] array;
	size = newS;
	array = newArray;
}
HashNode* Heap::removeMax()
{
	// remove the max element
	if (size>0)
	{
		HashNode* tmp = array[0];
		array[0] = array[size-1];
		size--;
		siftdown(0);
		return tmp; 
	}

	else throw runtime_error("The heap is empty!");
}

HashNode* Heap::getMax()
{
	return array[0]; // returning the maximum element
}

HashNode* Heap::getMin()
{
	//sorting the elements
	sort(); // O(nlog(n))
	// returnin the last element
	if (size<=0) throw runtime_error("The Heap is empty");
	else{
	return array[size-1]; //  returning the minimum element
	}

	// second implementation O(n)
	
	// int height = log2(size);
	// int beg = pow(2, height) -1;
	// int end = (pow(2, height) -1) + pow(2, height);
	// HashNode* minNode = getMax();

	// for (int i=0; i< size; i++)
	// {
	// 	if (minNode->value > array[i]->value)
	// 	{
	// 		minNode = array[i];
	// 	}
	// }
	// return minNode;
}

int Heap::parent(int k)
{
	return (k-1)/2;
}
int Heap::left(int k)
{
	return 2* k +1;
}
int Heap::right(int k)
{
	return 2*(k+1);
}