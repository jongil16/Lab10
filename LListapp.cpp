#include "LList.hpp"
#include <iostream>
using namespace std;
int main()
{
	LList<int> intList;
	LList<string> stringList;
	cout << "Integer list: " << intList << endl;
	cout << "String list: " << stringList << endl;
	intList.InsertLast (-1);
	intList.InsertFirst(10);
	stringList.InsertFirst("Hello");
	stringList.InsertLast("World");
	cout << "Integer list: " << intList << endl;
	cout << "String list: " << stringList << endl;
	intList.SetDirection (BACKWARD);
	stringList.SetDirection (BACKWARD);
	cout << "Integer list: " << intList << endl;
	intList.SetDirection(FORWARD);
	stringList.SetDirection (FORWARD);
	cout << "Integer list: " << intList << endl;
	cout << "String list: " << stringList << endl;
	return 0;
}







