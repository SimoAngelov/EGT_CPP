//============================================================================
// Name        : PrintArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int row, column;


template<typename T> void printArray(T* array, int size){
	cout << "[";
	for(int i = 0; i < size; i++){
		if(i < size - 1){
			cout << array[i] << ", ";
		} else{
			cout << array[i] << "]" << endl;
		}
	}
}

template<typename T> void printMatrix(T** matrix, int row, int column){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			cout << right << setw(5) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double d[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.5, 7.7, 8, 9, 10};
	char* ch = {"Hello"};
	row = 9;
	column = 10;
	int** matrix;
	matrix = new int*[column];
	for(int i = 0; i < row; i++){
		matrix[i] = new int[column];
	}
	for(int i = 0; i < 9; i++ ){
		for(int j = 0; j < 10; j++){
			matrix[i][j] = i+j;
		}
	}

	for(int i = 0; i < row; i++){
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = NULL;
	printArray(n, 10);
	printArray(d, 10);
	printArray(ch, 6);

	printMatrix(matrix, 9, 10);
	cout << "hey" << endl;
	return 0;
}
