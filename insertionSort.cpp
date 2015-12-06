#ifndef SORT_H
#define SORT_H
/*
 * Sort.h
 * Name: FILL ME IN
 *
 * November 2015
 */

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
  if( data.size() <= 1){
    cout<<"List is Sorted"<<endl;
    return true;
  }

  for (unsigned int i = 0 ; i < data.size() - 1; i++){
    if(data[i]>data[i+1]){
      return false;
    }
  }
  cout<<"List is Sorted"<<endl;
  return true;
}


void printList(vector<int> a){
    if(a.size() == 0){
        cout<<"[empty]"<<endl;
        return;
    }
    cout<<"[";
    for(int i = 0; i < a.size() -1; i++){
		cout << a[i] << ",";
	}
    cout<<a[a.size() -1];
    cout<<"]"<<endl;

}

// insertion sort
// shifts and inserts in the correct spot\
// how you sort cards
// Sorting Speeds
// Best Case(already sorted): O(n)
// Worst Case Sort Speed: O(n^2)
void insertionSort(vector<int>& data){
    if( isSorted(data)){ return; }
    int j;
	for (int i = 0; i < data.size(); i++){
		j = i;
		while (j > 0 && data[j] < data[j-1]){
            swap(data[j], data[j-1]);
            j--;
        }
    }
}




void runCurrentSort(vector<int> & data){
    insertionSort(data);
}


int main(){
    //////////////////////////////////////////////////////////////////////
    cout<<"\nTest 1: \n"<<endl;
    srand(time(0));
    vector<int> a;
	for(int i = 0; i < 20; i++){
		a.push_back(rand() % 20);
	}
    printList(a);
	runCurrentSort(a);
	isSorted(a);
	printList(a);
    //////////////////////////////////////////////////////////////////////
    cout<<"\nTest 2: \n"<<endl;

    srand(time(0));
    vector<int> b;
	for(int i = 0; i < 1; i++){
        b.push_back(rand() % 20);
	}
    printList(b);
	runCurrentSort(b);
	isSorted(b);
	printList(b);
    //////////////////////////////////////////////////////////////////////
    cout<<"\nTest 3: \n"<<endl;

    srand(time(0));
    vector<int> c;
    printList(c);
	runCurrentSort(c);
	isSorted(c);
	printList(c);

	//////////////////////////////////////////////////////////////////////
    cout<<"\nTest 4: \n"<<endl;

    srand(time(0));
    vector<int> d;
	for(int i = 0; i < 200; i++){
        d.push_back(rand() % 20);
	}
    printList(d);
	runCurrentSort(d);
	isSorted(d);
	printList(d);

}


#endif
