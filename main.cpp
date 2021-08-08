#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <exception>
#include <algorithm>
#include <sstream>
#include <ctime>
#include "helpers.h"

using namespace std;

///////////////////////////////////////////////////////////////////////
// This program uses header files and a make file which compiles into "output"
// for parsing the lines, the punctuations are converted into spaces 
// Numbers are not included
////////////////////////////////////////////////////////////////////

void displayDetails(HashTable& table, string& path, string hashFunctionName)
{
	cout << "===================================================" << endl;
	cout << "File name: " << path << endl;
	cout << "Hash Fuction Name: " << hashFunctionName << endl;
	cout << "Total Number Of Words = " << table.count_words() << endl;
	cout << "Number of Unique Words = " << table.count_unique_words() << endl;
	cout << "Total Number of Collisions = " << table.getCollisions() << endl;
	cout << "Avg. Number of Collisions Per Entry = " << float(table.getCollisions()) / table.size() << endl;
	cout << "===================================================" << endl;


}


int main() {
	welcome();

	string path;
	string command, argument1, user_input, hashFunctionName;
	ifstream file_in;
	int hashNum;

	cout << "Enter the full path of an input file: ";
	getline(cin, path);

	cout << "This is the path entered: " << path << endl;


	//path = "/Users/gomda/Desktop/DataStructures/assignments/AbdulSamadGomdaAssignment_3/test_files/";
	file_in.open(path);
	while (!file_in)
	{
		cout << "Can't open file.........!" << endl;
		cout << "Enter the full path of an input file: ";
		getline(cin, path);
		file_in.open(path);
	}


	// string of all the unwanted characters 
	string unwantedChars = "``\'\'\'\"\"\"~!@#$%^&*****()--_+=]:;[\\|}{\"\'?/.,><0987654321";

	string hashFunc;
	cout << "\n1. Bitwise/Cyclic Shift\n2. Summation HashCode\n3. Polynomial HashCode\n4. XOR Function" << endl;
	do {
		cout << "Enter your prefered Hash Function: ";
		getline(cin, hashFunc);

		// selecting the hash function based on the input chosen
		if (hashFunc == "1")
		{hashNum = stoi(hashFunc); hashFunctionName = "Bitwise/Cyclic Shift Hash Function"; break;}
		else if (hashFunc == "2")
		{hashNum = stoi(hashFunc); hashFunctionName = "Summation Hash Function"; break;}
		else if (hashFunc == "3")
		{hashNum = stoi(hashFunc); hashFunctionName = "Polynomial Hash Function"; break;}
		else if (hashFunc == "4")
		{hashNum = stoi(hashFunc); hashFunctionName = "XOR Hash Function"; break;}
		else if (hashFunc == "") // using default hashFunction;
		{hashNum = 1; hashFunctionName = "Bitwise/Cyclic Shift Hash Function"; break;}
		else cout << "Invalid Input, try again" << endl;

	} while ( true);

	// initializing the HashTable
	HashTable WordCountWizard(109621, hashNum);

	string line;
	char p = ' ';
	int cnt = 0;
	while (file_in >> line)
	{
		getline(file_in, line);

		//replacing unwanted characters with a space the unwanted characters
		for (char c : unwantedChars) {
			std::replace(line.begin(), line.end(), c, p);
			//line.erase(std::remove(line.begin(), line.end(), c), line.end());
		}

		stringstream ss(line);
		string word;
		while (ss >> word) {
			cnt ++;
			//making the word lower case
			makeLower(word);
			WordCountWizard.insert(word);
		}
	}

	// displaying the analysis of the file
	displayDetails(WordCountWizard, path, hashFunctionName);
	// displaying the commands 
	cout << "Commands available \n1. countCollisons\n2. countWords\n3. findFreq <word>\n4. countUniqueWords <word>\n5. findMax\n6. findMin\n7. help" << endl;

	while (true)
	{
		cout << ">";
		getline(cin, user_input);
		stringstream sstr(user_input);
		getline(sstr, command, ' ');
		getline(sstr, argument1, ',');

		try {
			if (command == "findFreq") cout << "The frequency for " << argument1 << " is: " << WordCountWizard.find_freq(argument1) << endl;
			else if (command == "countCollisions") cout << "The number of collisons are: " << WordCountWizard.getCollisions() << endl;
			else if (command == "countWords") cout << "The number of words are: " << WordCountWizard.count_words() << endl;
			else if (command == "findMax")  WordCountWizard.find_max();
			else if (command == "findMin") WordCountWizard.find_min();
			else if (command == "countUniqueWords") cout << "The number of unique words are: " << WordCountWizard.count_unique_words() << endl;
			else if (command == "help")	  cout << "Commands available \ncountCollisons : return the number of collisions\ncountWords :    return the number of words\nfindFreq <word> :    find the frequency of a word\ncountUniqueWords :    return the number of unique words\nfindMax :    return the word with the maximum frequency\nfindMin :    returns a word with the minimum frequency" << endl;
			else if (command == "exit")	 { cout<< "Have a nice day!"<<endl ; break;}
			else cout << "Invalid command !!!" << endl;
		}
		catch (exception &e)
		{
			cout << "The Exception is: " << e.what() << endl;
		}

	}


	return EXIT_SUCCESS;
}
