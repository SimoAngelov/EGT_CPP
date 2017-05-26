//============================================================================
// Name        : RemoveOddOccurrenceOfIntegers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <map>

typedef map<int, int, less<int> > intMap;
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int array[] = {2, 5, 79, 66, 55, 2, 66, 5, 66, 1};
	vector<int> numbers(array, array+10);
	intMap im;
	intMap::iterator it;
	for(unsigned int i = 0; i < numbers.size(); i++){
		int key = numbers[i];
		it = im.find(key);
		if(it != im.end()){
			im[key]++;
		} else{
			im[key] = 1;
		}
	}

	cout << "Key\tValue" << endl;
	for(it = im.begin(); it != im.end(); it++){
		cout << it->first << "\t" << it->second << endl;
		// first => key; second => value

	}

	vector<int>::iterator vectorIt;

	for(vectorIt = numbers.end(); vectorIt >= numbers.begin(); vectorIt--){
		if(im[*vectorIt] % 2 !=0){
			numbers.erase(vectorIt);
		}
	}

	for(vectorIt = numbers.begin(); vectorIt != numbers.end(); vectorIt++){
		cout << *vectorIt << endl;
	}

	return 0;
}
