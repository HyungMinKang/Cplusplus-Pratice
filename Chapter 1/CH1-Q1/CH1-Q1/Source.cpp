#include <iostream>
using namespace std;

int main(void)
{
	
	int val;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "���� ���� �Է�: ";
		cin >> val;
		sum += val;
	}

	cout << "�հ�: " << sum;
}