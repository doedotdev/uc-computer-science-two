/*
   Trie (Prefix) class for storing and retrieving strings.
   Paul Talaga
   November 2015
 */
#include <iostream>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "prefix.h"
#include <vector>
#include <stdio.h>

using namespace std;

	Prefix::Prefix(){
	  root = new Node_t;
	  nullMyNode(root);
	  total_words = 0;
	  total_nodes = 1;
	  height = 0;
	}

	Prefix::Prefix(const Prefix &other){
	  root = new Node_t;
	  nullMyNode(root);
	  total_words = 0;
	  total_nodes = 1;
	  height = 0;
	  vector<string> all = other.getAllStored();
	  for(unsigned int i = 0 ; i < all.size(); i++){
	    insert(all[i]);
	  }
	}

	void emptyIt(Node_t * n){
	  for(int i = 0 ; i < 27; i++){
	    if(n->links[i]){
	      emptyIt(n->links[i]);
	    }
	    delete n->links[i];
	  }
	}

	void Prefix::clearAll(){
    emptyIt(root);
	  total_words = 0;
	  total_nodes = 1;
	  height = 0;
	}

	Prefix& Prefix::operator=(const Prefix& other){
	  if(this == &other){
      return *this;
    }
    clearAll();
	  root = new Node_t;
	  nullMyNode(root);
	  total_words = 0;
	  total_nodes = 1;
	  height = 0;
	  vector<string> all = other.getAllStored();
	  for(unsigned int i = 0 ; i < all.size(); i++){
	    insert(all[i]);
	  }
    return *this;
	}

	int getLinksValue(char c){
	  if(isalpha(c)){
	    return int(tolower(c)-96);
	  }
	  return 26; // it is a space or something else !@#$%
	}

	void recursiveFree(Node_t * n){
	  for(int i = 0 ; i < 27; i++){
	    if(n->links[i]){
	      recursiveFree(n->links[i]);
	      delete n->links[i];
	    }
    }
  }

	void Prefix::nullMyNode(Node_t * n ){
	  for (unsigned int i = 0; i < 27; i++){
	    n->links[i] = NULL;
	  }
	}



	void destruct(Node_t * n){
	if( n == NULL){
	  return;
	}
	  for (int i = 0; i <27; i++){
	    destruct(n->links[i]);
	    delete n->links[i];
	    n->links[i] = NULL;
	  }
	}

	Prefix::~Prefix(){
	  recursiveFree(root);
	  for(int i = 0 ; i < 27; i++){
	    root->links[i] = NULL;
	  }
	  delete root;
	}

	bool Prefix::insert(string thing){
	  Node_t * cur = root; // start at beggining created in constructor
	  int temp_height = 0;
	  if(thing.length() == 0){
      cur->word = true;
      total_words++;
      return true; // end it becasue no letter to store
	  }

	  for(unsigned int i = 0 ; i < thing.length(); i++){
	    if(cur->links[ getLinksValue( thing[i] ) ] == NULL){ // never been a letter after that one
	      cur->links[ getLinksValue( thing[i] ) ] = new Node_t; // its not so make a new one
	      nullMyNode(cur->links[ getLinksValue( thing[i] ) ]);
	      total_nodes++;
	    }
	    cur = cur->links[ getLinksValue( thing[i] ) ]; // link current to the
	    temp_height++;
    }
    // got to last letter now is_word = true
    if(temp_height > height){
      height = temp_height;
    }
    if(cur->word == true){ // it was already entered before, do not increment total_words;
      return true; // stop
    }
    cur->word = true;
    total_words++;

	  return true;
	}

	int Prefix::getHeight(){
	  return height;
	}

	int Prefix::getNumNodes(){
	  return total_nodes;
	}

	int Prefix::getNumStored(){
	  return total_words;
	}

	void traverse(string const& prefix, Node_t * n, vector<string> &my_vec){
	  if(n->word==true){
	    my_vec.push_back(prefix);
	  }
	  for(unsigned int i = 0 ; i < 27; i++){
	    if(n->links[i]){
        int a;
        if(i == 26){
          a = ' ';
        }
        else{
          a = i + 'a' - 1;
        }
        traverse(prefix + char(a) , n->links[i], my_vec);
      }
    }
	}

	vector<string> Prefix::getWPrefix(string thing){
	  Node_t * cur = root;
	  for(unsigned int i = 0 ; i < thing.length(); i ++){
	    cur = cur->links[ getLinksValue( thing[i] ) ];
	  }
	  vector<string> my_vec;
	  string prefix = "";
	  traverse(prefix, cur, my_vec);
	  for(unsigned int i = 0; i < my_vec.size(); i ++){
	    my_vec[i] = thing + my_vec[i];
	  }
	  return my_vec;
	}


	vector<string> Prefix::getAllStored() const{
	  vector<string> my_vec;
	  if(total_words == 0){
	    return my_vec;
	  }
	  string prefix = "";
	  traverse(prefix, root, my_vec);
	  return my_vec;
	}


	int Prefix::getNumWPrefix(string thing){
	  Node_t * cur = root;
	  for(unsigned int i = 0 ; i < thing.length(); i ++){
	    if(cur->links[ getLinksValue( thing[i] ) ]){
	      cur = cur->links[ getLinksValue( thing[i] ) ];
      }
      else{
        return 0;
      }
	  }
	  vector<string> my_vec;
	  string prefix = "";
	  traverse(prefix, cur, my_vec);
	  return my_vec.size();
	}

	bool Prefix::isStored(string thing){
	  Node_t * cur = root; // start at beggining created in constructor
	  for(unsigned int i = 0 ; i < thing.length(); i++){
      if(cur->links[ getLinksValue( thing[i] ) ] == NULL){
        return false; // a node was never created there
      }
      cur = cur->links[ getLinksValue( thing[i] ) ];
    }
    if( cur->word == true){ // check for word now that we are at end ex: hi should not return true for his
      return true;
    }

	  return false; // word was not true;
	}
