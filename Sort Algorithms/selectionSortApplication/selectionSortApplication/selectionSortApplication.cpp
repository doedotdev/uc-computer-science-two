// selectionSortApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;


bool isSorted(vector<int> data){
	if (data.size() <= 1){
		cout << "List is Sorted" << endl;
		return true;
	}

	for (unsigned int i = 0; i < data.size() - 1; i++){
		if (data[i]>data[i + 1]){
			return false;
		}
	}
	cout << "List is Sorted" << endl;
	return true;
}



void printList(vector<int> a){
	if (a.size() == 0){
		cout << "[empty]" << endl;
		return;
	}
	cout << "[";
	for (int i = 0; i < a.size() - 1; i++){
		cout << a[i] << ",";
	}
	cout << a[a.size() - 1];
	cout << "]" << endl;

}


// selection sort
// sorts from left to right
// finds next smallest element and swaps them
// Sorting Speeds
// Best Case(already sorted): O(n^2)
// Worst Case Sort Speed: O(n^2)
void selectionSort(vector<int>& data){
	if (isSorted(data)){ return; }

	for (unsigned int i = 0; i < data.size(); i++){
		for (unsigned int j = i + 1; j < data.size(); j++){// start at the next value and check it
			if (data[i] > data[j]){
				swap(data[i], data[j]);
			}
		}
	}
}

void runCurrentSort(vector<int> & data){
	selectionSort(data);
}




int _tmain(int argc, _TCHAR* argv[]){
	//////////////////////////////////////////////////////////////////////
	cout << "\nTest 1: \n" << endl;
	srand(time(0));
	vector<int> a;
	for (int i = 0; i < 20; i++){
		a.push_back(rand() % 20);
	}
	printList(a);
	runCurrentSort(a);
	isSorted(a);
	printList(a);
	//////////////////////////////////////////////////////////////////////
	cout << "\nTest 2: \n" << endl;

	srand(time(0));
	vector<int> b;
	for (int i = 0; i < 1; i++){
		b.push_back(rand() % 20);
	}
	printList(b);
	runCurrentSort(b);
	isSorted(b);
	printList(b);
	//////////////////////////////////////////////////////////////////////
	cout << "\nTest 3: \n" << endl;

	srand(time(0));
	vector<int> c;
	printList(c);
	runCurrentSort(c);
	isSorted(c);
	printList(c);

	//////////////////////////////////////////////////////////////////////
	cout << "\nTest 4: \n" << endl;

	srand(time(0));
	vector<int> d;
	for (int i = 0; i < 200; i++){
		d.push_back(rand() % 20);
	}
	printList(d);
	runCurrentSort(d);
	isSorted(d);
	printList(d);

}
