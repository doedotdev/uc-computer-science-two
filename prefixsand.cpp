// sand box .cpp
// prefix tree tests

/*
	Prefix Tree Sandbox
	Paul Talaga
	November 2015
*/

#include <string>
#include <iostream>

#include "prefix.h"

using namespace std;

int main(int argc, char* argv[]){

  Prefix a;
  a.insert("a");
  a.insert("ab");
  a.insert("abc");
  a.insert("abcd");
  a.insert("b");
  a.insert("c");

   cout << "words: " << a.getNumStored() << endl;




}
