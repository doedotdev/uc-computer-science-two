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




void recursiveQuickSort(int index_begin, int index_end, vector<int>& data){ // passed by reference from quickSort(& data)
  int i = index_begin;
  int j = index_end;
  int middle = data[(index_begin + index_end) / 2];
  while (i <= j) {
    while (data[i] < middle)
      i++;
    while (data[j] > middle)
      j--;
    if (i <= j) {
      swap(data[i], data[j]);
      i++;
      j--;
    }
  }
  if (index_begin < j)
        recursiveQuickSort(index_begin, j, data); // recall because left side is not done
  if (i < index_end)
        recursiveQuickSort(i, index_end, data); // recall because right side is not done
}


void quickSort(vector<int>& data){
  if( isSorted(data)){ return; }
  recursiveQuickSort(0, data.size() -1, data); // does not work; update, fixed
}

void runCurrentSort(vector<int> & data){
    quickSort(data);
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
