#include <iostream>
using namespace std;

int main(void)
{
	int pay = 50;
	int sales;
	int salary = 0;

	while (1)
	{
		cout << "판매 금액을 만원단위로 입력(-1 to end): ";
		cin >> sales;

		if (sales != -1)
		{
			salary = pay + (sales * 0.12);
			cout << "이번 달 급여: " << salary << endl;
		}
		else
		{
			cout << "프로그램을 종료합니다";
			return 0;
		}
	}
}