#include<string>
#include<iostream>
#include<exception>
#include<cmath>
#include "HashNode.h"
#include "OrderedMap.h"
#include "HashTable.h"
#include "maxHeap.h"

using namespace std;

//=============================================
HashTable::HashTable(int cap, int num)
{
	this->_size = 0;
	this->wordCount = 0;
	this->capacity = cap;
	this->unique_size = 0;
	this->collisions = 0;
	this->number = num;
	this->entries = new OrderedMap[capacity];
	//maximumHeap = Heap(100);
}
HashTable::~HashTable()
{
	// for (int i = 0; i<capacity; i++)
	// 	entries[i] = NULL;
	delete[] entries;
}
unsigned long HashTable::hashCode1(const string key) // bitwise shift hash function
{
	unsigned long int _hashValue = 0;
	for (int i = 0; i < key.size(); i++)
	{
		_hashValue = (_hashValue << 5) | (_hashValue >> 27);
		_hashValue += (unsigned int) key[i];
	}
	_hashValue = _hashValue % capacity;
	return _hashValue;
}

unsigned long HashTable::hashCode2(const string key) // summation hashFunciton
{
	unsigned long int _hashValue = 0;
	for (int i = 0; i < key.size(); i++)
	{
		_hashValue += (unsigned int) key[i];
	}
	_hashValue = _hashValue % capacity;
	return _hashValue;
}
unsigned long HashTable::hashCode3(const string key)// polynimial hashFunction
{
	unsigned long int _hashValue = 0;
	for (int i = 0; i < key.size(); i++)
	{
		_hashValue += ((unsigned int) key[i]) * pow(5, i);
		_hashValue += (unsigned int) key[i];
	}

	_hashValue = _hashValue % capacity;
	return _hashValue;
}
unsigned long HashTable::hashCode4(const string key)// XOR hashFunction
{
	unsigned long int _hashValue = 0;
	long int A = 54059;
	long int B = 76963;
	//long int C = 86969;
	long int FirstP = 37;
	for (int i = 0; i < key.size(); i++)
	{
		//_hashValue = FirstP;
		_hashValue += (A * FirstP ^ (unsigned int) key[i] * B);
	}
	_hashValue = _hashValue % capacity;
	return _hashValue;
}

unsigned long HashTable::switch_hashFun(const string key)
{
	// switching between hash functions
	if (number == 1)
	{
		return hashCode1(key);
	}
	else if (number == 2)
		return hashCode2(key);
	else if (number == 3)
		return hashCode3(key);
	else
		return hashCode4(key);
}

int HashTable::getCollisions()
{
	return this->collisions; // returning the number of collisions 
}
int HashTable::count_words()
{
	return this->wordCount; // returning the total number of words in the file
}

int HashTable::size()
{
	return this->_size; // returning the size of the hash table 
}
int HashTable::count_unique_words()
{
	return this->unique_size; // returning the unique words in the file
}

int HashTable::find_freq(const string key)
{
	unsigned long int _hashCode = switch_hashFun(key);

	//calling the binary search method in the ordered map
	return entries[_hashCode].search(key);
}

void HashTable::insert(const string key)
{
	unsigned long int _hashCode = switch_hashFun(key);
	// when the bucket is empty
	if (entries[_hashCode].empty())
	{
		HashNode* newNode = new HashNode(key, 1);
		entries[_hashCode].push_back(newNode);
		_size++;
		unique_size++;
		wordCount++;
	}
	else
	{
		// when the there is a duplicate value
		int length = entries[_hashCode].size();
		bool hasSeen = false;
		for (int i = 0; i < length; i++)
		{
			if (entries[_hashCode][i]->key == key)
			{
				entries[_hashCode][i] ->value += 1;
				wordCount++;
				hasSeen = true;
				break;
			}
		}
		
		if (!hasSeen)
		{// incrementing the colliisons and the value of the non unique word
			collisions++;
			// appending new elements in a non empty bucket
			HashNode* newNode = new HashNode(key, 1);
			_size++;
			wordCount++;
			unique_size++;
			entries[_hashCode].push_back(newNode);
		}
	}

}

void HashTable::find_max()
{
	// inserting the entires into the heap
	Heap* maximumHeap = new Heap();
	for (int i = 0; i < capacity; i++)
	{
		if (!entries[i].empty())
		{
			maximumHeap->insert(entries[i].maxNode());
		}
	}

	cout << "The word with the maximum frequency is : " << "\"" << maximumHeap->getMax()->key << "\"" << " its frequency is: " << maximumHeap->getMax()->value << endl;
	delete maximumHeap;
}
void HashTable::find_min()
{
	Heap* maximumHeap = new Heap();
	// inserting the entires into the heap
	for (int i = 0; i < capacity; i++)
	{
		if (!entries[i].empty())
		{
			maximumHeap->insert(entries[i].maxNode());
		}
	}

	cout << "The word with the minimum frequency is : " << "\"" << maximumHeap->getMin()->key << "\"" << " its frequency is: " << maximumHeap->getMin()->value << endl;
	delete maximumHeap;
}
