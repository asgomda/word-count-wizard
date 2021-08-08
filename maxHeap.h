#include <string>
#include <iostream>

using namespace std;

// maximum heap class
class Heap
{
private:
	HashNode** array;
	int capacity;
	int size;
public:
	Heap(int cap);
	Heap();
	~Heap();
	void insert(HashNode* node);
	HashNode* removeMax();
	HashNode* getMax();
	HashNode* getMin();
	int parent(int k);
	int left(int k);
	int right(int k);
	void siftup(int k);
	void siftdown(int k);
	void sort();
private:
	void adjustSize();
};