#include <iostream>
using namespace std;

int main(void)
{
	
	int val;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "번쨰 정수 입력: ";
		cin >> val;
		sum += val;
	}

	cout << "합계: " << sum;
}