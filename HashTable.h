#include <iostream>
#include <string>
//#include "maxHeap.h"

using namespace std;


class HashTable
{
private:
	OrderedMap* entries; // Array of OrdereMap of HashNodes
	//Heap maximumHeap;
	int _size;
	int unique_size;
	int capacity;
	int wordCount;
	int collisions;
	int number;
public:
	HashTable(int cap, int num);
	~HashTable();
	unsigned long hashCode1(const string key);
	unsigned long hashCode2(const string key);
	unsigned long hashCode3(const string key);
	unsigned long hashCode4(const string key);
	unsigned long switch_hashFun(const string key);
	void insert(const string key);
	int getCollisions();
	int count_words(); // total number of word
	int count_unique_words(); // return the unique words
	int find_freq(const string key); // return the value of a key
	void find_max(); // return word with max occurance
	void find_min(); // return word with minimun occurance
	int size(); // size of the hash table
};