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




#include <iostream>
#include <time.h>
#include <math.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;


int reverse_number(int);

int reverse_number(int old_number)
{
	int new_number = 0;
	for (; old_number != 0;)
	{
		new_number = new_number * 10;
		new_number = new_number + old_number % 10;
		old_number = old_number / 10;
	}
	return new_number;
}



int _tmain(int argc, _TCHAR* argv[])
{

	int number_to_reverse;
	cout << "Enter A old_number to Reverse: ";
	cin >> number_to_reverse;
	cout << endl;
	cout << reverse_number(number_to_reverse) << endl;

	return 0;
}
