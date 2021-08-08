#include<iostream>
#include<string>
#include "helpers.h"
// #include "HashNode.h"
// #include "OrderedMap.h"
//#include "HashTable.h"

using namespace std;

// function that makes strings lowercase
void makeLower (string& s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
}

//welcome display
void welcome(){
	cout<<"\n\n\n"<<endl
		<<"\t\t\t"<<"#############################################################"<<endl
		<<"\t\t\t"<<"#############################################################"<<endl
		<<"\t\t\t"<<"########### WELCOME TO THE WORD COUNT WIZARD ################"<<endl
		<<"\t\t\t"<<"#############################################################"<<endl
		<<"\t\t\t"<<"#############################################################"<<endl
		<<"\n\n\n"<<endl;
}

