#include <string>
#include <iostream>


using namespace std;


class OrderedMap
{
	private:
		HashNode **data;						//pointer to HashNode(array) to store elements
		int v_size;						//current size of OrderedMap (number of elements in OrderedMap)
		int v_capacity;					//capacity of OrderedMap
	public:
		class Iterator;
		OrderedMap();						//No argument constructor
		OrderedMap(int cap);				//One Argument Constructor
		~OrderedMap();					//Destructor
		void push_back(HashNode* element);		//Add an element at the end of OrderedMap
		void insert(int index, HashNode* element);
		void sort(); 
		HashNode* maxNode();
		int search(string word);
		HashNode* at(int index); 				//return reference to the element at index
		const HashNode* front();				//Returns reference to the first element in the OrderedMap
		const HashNode* back();				//Returns reference to the Last element in the OrderedMap
		int size() const;				//Return current size of OrderedMap
		int capacity() const;			//Return capacity of OrderedMap
		bool empty() const; 			//Rturn true if the OrderedMap is empty, False otherwise
		HashNode* operator[](int index);
		
		const Iterator begin() // iterator for the ordered map
		{
			return Iterator(data[0]);
		}
		const Iterator end()
		{
			return Iterator(data[v_size]);
		}

		class Iterator{
		private:
			HashNode* ptr;
		public:
			Iterator(HashNode* ptr) : ptr(ptr) {}
			HashNode* operator*()
			{
				return ptr;
			}
			Iterator& operator++()
			{
				ptr++;
				return *this;
			}
			Iterator& operator--()
			{
				ptr--;
				return *this;
			}
			bool operator==(const Iterator& other) const
			{
				return this->ptr == other.ptr;
			}
			bool operator!=(const Iterator& other) const
			{
				return this->ptr != other.ptr;
			}
		};
		friend class HashTable;

};