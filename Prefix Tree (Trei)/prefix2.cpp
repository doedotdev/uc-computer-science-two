
1
NEW
.
Folder Path
My Drive
All
Archive
Folders and views
My Drive
Shared with me
Recent
Google Photos
Starred
Trash
Get Drive for PC
589 MB of 15 GB used
Upgrade storage
NAME
Folders
.
Photos.Archive
Projects
Python
School.Archive
SmsHexView
SmsHexViewFinal
Technical Writing
Text Books
Files
.

C++
trie.cpp
All selections cleared


// Simple Prefix Tree
// trie
// Benjamin Horn
// 12/18/2015

#include <iostream>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <stdio.h>

using namespace std;

const unsigned int B_FACTOR = 27;  // a..z plus space

struct Node_t {
	bool word;
	Node_t* links[B_FACTOR]; // array 27 long. Every letter is toLower
};

class Prefix{
public:
	Prefix(){    // constructor
		root = new Node_t;
		total_words = 0;
		nullMyNode(root);
	}

	void nullMyNode(Node_t* n){
		for (int i = 0; i < B_FACTOR; i++){
			n->links[i] = NULL;
		}
	}

	int getLinksValue(char c){
		if (isalpha(c)){
			return int(tolower(c) - 96);
		}
		return 26; // it is a space or something else !@#$%123456789
	}

	bool insertTrie(string thing){
		Node_t* cur = root;
		if (thing.length() == 0){
			cout << "hit" << endl;

			cur->word = true;
			total_words++;
			return true;
		}
		for (unsigned int i = 0; i < thing.length(); i++){
			cout << "hit" << endl;

			if (cur->links[getLinksValue(thing[i])] == NULL){
				cur->links[getLinksValue(thing[i])] = new Node_t; // its not so make a new one
				nullMyNode(cur->links[getLinksValue(thing[i])]);
			}
			cur = cur->links[getLinksValue(thing[i])];
		}
		total_words++;
		if (cur->word == true){ // it was already entered before, do not increment total_words;
			cout << "was already true" << endl;

			return true; // stop
		}
		cout << "DO I EVER GET HERE -- no :(" << endl;
		cur->word = true;
		total_words++;
		cout << "Total++ " << total_words << endl;

		return true;
	}

	int getWordsStored(){
		return total_words;
	}

	vector<string> getWPrefix(string thing){
		Node_t * cur = root;
		for (unsigned int i = 0; i < thing.length(); i++){
			cur = cur->links[getLinksValue(thing[i])];
		}
		vector<string> my_vec;
		string prefix = "";
		traverse(prefix, cur, my_vec);
		for (unsigned int i = 0; i < my_vec.size(); i++){
			my_vec[i] = thing + my_vec[i];
		}
		return my_vec;
	}

	void traverse(string const& prefix, Node_t * n, vector<string> &my_vec){
		if (n->word == true){
			my_vec.push_back(prefix);
		}
		for (unsigned int i = 0; i < 27; i++){
			if (n->links[i]){
				int a;
				if (i == 26){
					a = ' ';
				}
				else{
					a = i + 'a' - 1;
				}
				traverse(prefix + char(a), n->links[i], my_vec);
			}
		}
	}


	vector<string> getAllStored() {
		vector<string> my_vec;
		if (total_words == 0){
			//return my_vec;
		}
		string prefix = "";
		traverse(prefix, root, my_vec);
		return my_vec;
	}

private:
	Node_t *root;
	int total_words;
	//vector<string> allStored;
	//void nullMyNode(Node_t *);
};


int main(){
	cout << "Trie" << endl;

	Prefix a;
	a.insertTrie("hello");
	a.insertTrie("hellow");
	a.insertTrie("helloer");
	a.insertTrie("hellorwf");
	cout << "Words: " << a.getWordsStored() << endl;

	vector<string> all_stored = a.getAllStored();
	for (int i = 0; i < all_stored.size(); i++){
		cout << all_stored[i] << endl;

	}


	return 0;
}