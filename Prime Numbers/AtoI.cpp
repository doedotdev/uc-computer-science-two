// AtoI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

using namespace std;

bool isPrime(int);

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> my_vec;
	int k = 1;
	for (int i = 0; i < 15000; i++)
	{
		if (isPrime(i) == true)
		{
			cout << "The " << k << "th prime number is: " << i << endl;
			k++;
			my_vec.push_back(i);
		}
	}
	cout << my_vec[0] << endl;

	

	return 0;
}


bool isPrime(int);





bool isPrime(int num)
{
	if (num < 2) // numbers less than 2 are a special case
		return false;
	bool checkPrime = true; // change here
	int limit = sqrt(num);
	for (int i = 2; i <= limit; i++)
	{
		if (num%i == 0)
		{
			checkPrime = false;
			break;
		}
	}
	return checkPrime;
}


