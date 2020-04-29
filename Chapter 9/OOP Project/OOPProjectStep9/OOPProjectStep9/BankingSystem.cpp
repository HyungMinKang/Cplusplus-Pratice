/*
����Ʈ���� ����: Banking System Ver 0.7
�����̸�: BankingSystem.cpp
���α׷� main �κ�
*/
#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
	AccountHandler manager;
	int choice;
	while (1)
	{
		manager.showMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.makeAccount();
			break;
		case DEPOSIT:
			manager.depositMoney();
			break;

		case WITHDRAW:
			manager.withdrawMoney();
			break;
		case INQUIRE:
			manager.showAll();
			break;
		case EXIT:
			return 0;
		default:
			cout << "illegal selection!" << endl;

		}
	}
	return 0;
}