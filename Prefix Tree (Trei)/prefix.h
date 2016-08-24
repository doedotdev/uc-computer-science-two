#ifndef PREFIX_H
#define PREFIX_H

 #include <string>
 #include <vector>

using namespace std;

const unsigned int B_FACTOR = 27;  // a..z plus space

struct Node_t {
		bool word;
		Node_t* links[B_FACTOR]; // array 27 long. Every letter is toLower
	} ;

class Prefix {

	public:
	Prefix();
	Prefix(const Prefix &copy);
	Prefix& operator=(const Prefix& other);
	~Prefix();

	bool insert(string thing);

	int getHeight();
	int getNumNodes();
	int getNumStored();
	vector<string> getWPrefix(string);
	vector<string> getAllStored() const;
	int getNumWPrefix(string prefix);
	bool isStored(string thing);
	void clearAll();


	private:
	Node_t *root;
	int total_words;
	int total_nodes;
	int height;
	vector<string> allStored;
	void nullMyNode(Node_t *);

	// Hint... fill in functions here!


};
#endif
