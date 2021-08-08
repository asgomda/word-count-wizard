#include <string>
#include <iostream>

using namespace std;

// HashNode class with a string as the key and an integer as the value
class HashNode{
private:
	string key;
	int value;
public:
	HashNode(string key, int value);
	friend class OrderedMap;
	friend class MyVector;
	friend class HashTable;
	friend class Heap;
};