#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char* test1 = "ABC 123";
	char* test2 = "DEF 456";
	char test3[50];
	
	
	cout << strlen(test1) << endl;
	cout << strlen(test2) << endl;
	strcpy(test3, test1);
	strcat(test3, test2);
	cout << test3 << endl;

	if (strcmp(test1, test2) == 0)
		cout << "문자열이 같다" << endl;
	else
		cout << "문자열이 같지 않다" << endl;
	return 0;

}