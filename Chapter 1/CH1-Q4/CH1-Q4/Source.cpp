#include <iostream>
using namespace std;

int main(void)
{
	int pay = 50;
	int sales;
	int salary = 0;

	while (1)
	{
		cout << "�Ǹ� �ݾ��� ���������� �Է�(-1 to end): ";
		cin >> sales;

		if (sales != -1)
		{
			salary = pay + (sales * 0.12);
			cout << "�̹� �� �޿�: " << salary << endl;
		}
		else
		{
			cout << "���α׷��� �����մϴ�";
			return 0;
		}
	}
}