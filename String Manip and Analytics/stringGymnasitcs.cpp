// AtoI.cpp : Defines the entry point for the console application.
//


//Benjamin Horn
// Laboratory #5:		Strings and Arrays
//
// We will be exploring string arrays in this problem. See main()
// for examples of what we are going to do.
//
// You only need to complete the functions listed at the end of this file
// and add a few output statements to main()

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int number_of_lines = 0;
	int word_count;
	int character_count;
	int uppercase_letter_count;
	int lowercase_letter_count;
	int punctuation_count;
	string filename = "testfile.txt";	 // Modify this to point to your test file
	string ArrayOfStrings[500];  // This means we can NOT have files with more than 500 lines in them.
	string longest_string;
	string shortest_string;
	// Could use getline and cout to prompt and retrieve the filename from the command window
	// instead of hard coding it above.
	// Could replace the following with a loop to retry a different filename on a failure.
	if ((ReadStringsFile(filename, ArrayOfStrings, number_of_lines)) != true)
	{
		cout << "Can not Read File: " << filename << endl;
		exit(-1);
	}
	cout << "The File " << filename << " was evaluated. It has " << number_of_lines << " lines" << endl;
	character_count = CountCharactersInArray(number_of_lines, ArrayOfStrings);
	word_count = CountWordsInArray(number_of_lines, ArrayOfStrings);
	longest_string = LongestLineOfTextInArray(number_of_lines, ArrayOfStrings);
	shortest_string = ShortestLineOfTextInArray(number_of_lines, ArrayOfStrings);
	uppercase_letter_count = CountUpperCaseCharactersInArray(number_of_lines, ArrayOfStrings);
	lowercase_letter_count = CountLowerCaseCharactersInArray(number_of_lines, ArrayOfStrings);
	punctuation_count = CountPunctuationCharactersInArray(number_of_lines, ArrayOfStrings);
	cout << " " << endl << " " << endl;
	cout << "character_count:   " << character_count << endl;
	cout << " " << endl << " " << endl;
	cout << "word_count:   " << word_count << endl;
	cout << " " << endl << " " << endl;
	cout << "longest_string:   " << longest_string << endl;
	cout << " " << endl << " " << endl;
	cout << "shortest_string:   " << shortest_string << endl;
	cout << " " << endl << " " << endl;
	cout << "uppercase_letter_count:   " << uppercase_letter_count << endl;
	cout << " " << endl << " " << endl;
	cout << "lowercase_letter_count:   " << lowercase_letter_count << endl;
	cout << " " << endl << " " << endl;
	cout << "punctuation_count:   " << punctuation_count << endl;
	// Please call the proper function to output the array
	cout << " " << endl << " " << endl;
	PrintStringArray(number_of_lines, ArrayOfStrings);

	getchar();

	return 0;
}


// Prototypes
//   The ReadStringsFile is complete
bool ReadStringsFile(string fileName, string ArrayOfStrings[], int &number_of_lines);

void PrintStringArray(int number_of_lines, string ArrayOfStrings[]);

int CountWordsInArray(int number_of_lines, string ArrayOfStrings[]);
int CountWordsInString(string InputString);
int CountCharactersInString(string InputString);
int CountCharactersInArray(int number_of_lines, string ArrayOfStrings[]);
int CountUpperCaseCharactersInArray(int number_of_lines, string ArrayOfStrings[]);
int CountLowerCaseCharactersInArray(int number_of_lines, string ArrayOfStrings[]);
int CountPunctuationCharactersInArray(int number_of_lines, string ArrayOfStrings[]);

string LongestLineOfTextInArray(int number_of_lines, string ArrayOfStrings[]);
string ShortestLineOfTextInArray(int number_of_lines, string ArrayOfStrings[]);

// main() is almost complete please add proper cout statements to print longest string,
//	smallest string, etc..
//		See Sample Output
// 	- You may need to modify the filename assignment below to point to your test file


// The "incomplete" functions below are sometimes called "stub" functions. They are used
// as place holders while testing other (possibly) more important parts of the code.
void PrintStringArray(int number_of_lines, string ArrayOfStrings[])/////////DONE
{
	cout << " " << endl << " " << endl;
	for (int i = 0; i < number_of_lines; i++)
		cout << ArrayOfStrings[i] << endl;
	cout << " " << endl << " " << endl;


}

// This function Counts all characters in Array.
// Please loop through array and use the function
// CountCharactersInString to help calculate the number of characters.
int CountCharactersInArray(int number_of_lines, string ArrayOfStrings[])//////////done
{
	int numberOfChars = 0;
	for (int i = 0; i < number_of_lines; i++)
	{
		int  amount = ArrayOfStrings[i].length();
		numberOfChars += amount;
	}
	return numberOfChars;
}

// This function counts "words" in the array.
// Please loop through array and use the function
// CountWordsInString to finish this function
int CountWordsInArray(int number_of_lines, string ArrayOfStrings[])/////////////done
{
	int word = 0;
	for (int i = 0; i < number_of_lines; i++)
	{
		word += CountWordsInString(ArrayOfStrings[i]);
	}
	return word;
}
// This function takes a string and counts the "words" in that string
//
// This function my require some research but a crude approxitamation
// of counting words can be attempted using isspace and the c_str()
// function.
//
// Example Input String:
// String1 String2 String3
// would result in a word count of three (3)
//
// I do not want you to spend a lot of time on this.
int CountWordsInString(string InputString)///////////////done
{
	int word = 0;
	for (int i = 0; i < InputString.length() - 1; i++)
	{
		if ((isspace(InputString[i]) || ((ispunct(InputString[i])) && (isspace(InputString[i + 1])))))
			word++;
	}
	return word;
}

// This function returns the count of the characters in a string
// This is a one line function..
// Hint: You will want to look at the length() function
int CountCharactersInString(string InputString)
{
	int word = 0;

	for (int i = 0; i < InputString.length() - 1; i++)
	{
		if ((isspace(InputString[i]) || ((ispunct(InputString[i])) && (isspace(InputString[i + 1])))))
			word++;
	}
	return word;
}

// This function counts the number of upper case letters in the Array/File
// Look at the isupper() function to make this work
int CountUpperCaseCharactersInArray(int number_of_lines, string ArrayOfStrings[]) ///////////done
{
	int count = 0;
	for (int i = 0; i < number_of_lines; i++)
	{
		for (int j = 0; j < ArrayOfStrings[i].length(); j++)
		{
			if (isupper(ArrayOfStrings[i][j]))
				count++;
		}
	}
	return count;
}

// This function counts the number of lower case letters in the Array/File
// Look at the islower() function to make this work
int CountLowerCaseCharactersInArray(int number_of_lines, string ArrayOfStrings[]) //////////done
{
	int count = 0;
	for (int i = 0; i < number_of_lines; i++)
	{
		for (int j = 0; j < ArrayOfStrings[i].length(); j++)
		{
			if (islower(ArrayOfStrings[i][j]))
				count++;
		}
	}
	return count;
}

// This function counts the number of punctuation characters in the Array/File
// Look at the ispunct() function to make this work
int CountPunctuationCharactersInArray(int number_of_lines, string ArrayOfStrings[])////////DONE
{
	int count = 0;
	for (int i = 0; i < number_of_lines; i++)
	{
		for (int j = 0; j < ArrayOfStrings[i].length(); j++)
		{
			if (ispunct(ArrayOfStrings[i][j]))
				count++;
		}
	}
	return count;
}

// This function finds the Longest line of text in the Array
// You have to use the length() function on strings
string LongestLineOfTextInArray(int number_of_lines, string ArrayOfStrings[])////////////// done
{
	int newest = 0;
	int location;
	for (int i = 0; i < number_of_lines; i++)
	{
		if (ArrayOfStrings[i].length() > newest)
		{
			newest = ArrayOfStrings[i].length();
			location = i;
		}
	}
	return ArrayOfStrings[location];
}

// This function finds the Shortest line of text in the Array
// This function needs to be completed.

string ShortestLineOfTextInArray(int number_of_lines, string ArrayOfStrings[])///////done
{
	int newest = 1000000000;
	int location;
	for (int i = 0; i < number_of_lines; i++)
	{
		if (ArrayOfStrings[i].length() < newest)
		{
			newest = ArrayOfStrings[i].length();
			location = i;
		}
	}
	return ArrayOfStrings[location];
}

///////////done
// This function is complete and it uses material that we did not cover
// so please do not try to modify it.
bool ReadStringsFile(string fileName, string ArrayOfStrings[], int &number_of_lines)
{
	string input_line;
	ifstream infile(fileName.c_str()); // This might be useful for you.
	if (!infile)
	{
		return false;
	}
	number_of_lines = 0;
	while (getline(infile, input_line))
	{
		ArrayOfStrings[number_of_lines] = input_line;
		number_of_lines = number_of_lines + 1;
	}
	return true;
