#include <iostream>
using namespace std;

void Addone(int& ref)
{
	ref += 1;
}

void Changeone(int& ref)
{
	ref = -ref;
}

int main(void)
{
	int val = 5;
	Addone(val);
	cout << val << endl;
	Changeone(val);
	cout << val << endl;
	Addone(val);
	cout << val << endl;
}