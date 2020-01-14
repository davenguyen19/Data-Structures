/*
Here is a test driver you can use to get started
with your own testing.  This is not a complete
driver and you should not consider your solution
as being thoroughly tested just because you used
this program.

This is not the program that we will use to grade
your assignment.

Just because your code works with this driver does
not necessarily mean it is correct.

Testing your solution is part of the homework and
is your responsibility!

Your solution is correct if it satisfies all requirements.
*/

#include <iostream>
using namespace std;

#include <cstdlib>

#include "MyVector.h"

int main()
{
	MyVector v;

	try
	{
		v.pop_back();
	}
	catch (const char* e)
	{
		cout << e << endl;
	}


	for (int i = 0; i < 15; i++)
		v.push_back(1 + rand() % 100);

	for (int i = 0; i < 15; i++)
		cout << v.at(i) << "\t";

	try
	{
		v.at(16);
	}
	catch (const char* e)
	{
		cout << e << endl;
	}

	

	system("pause");
}