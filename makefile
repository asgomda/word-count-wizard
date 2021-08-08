

output : AbdulSamadGomdaAssignment_3.o HashNode.o helpers.o OrderedMap.o HashTable.o maxHeap.o
	g++ HashNode.o AbdulSamadGomdaAssignment_3.o helpers.o  OrderedMap.o HashTable.o maxHeap.o -o output

AbdulSamadGomdaAssignment_3.o : AbdulSamadGomdaAssignment_3.cpp
	g++ -c -w AbdulSamadGomdaAssignment_3.cpp

helpers.o : helpers.h helpers.cpp
	g++ -c helpers.cpp

HashNode.o : HashNode.h HashNode.cpp
	g++ -c HashNode.cpp

OrderedMap.o : OrderedMap.h OrderedMap.cpp
	g++ -c OrderedMap.cpp

maxHeap.o : maxHeap.h maxHeap.cpp 
	g++ -c maxHeap.cpp

HashTable.o : HashTable.h HashTable.cpp
	g++ -c HashTable.cpp