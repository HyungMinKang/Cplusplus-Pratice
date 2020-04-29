/*
소프트웨어 버전: Banking System Ver 0.7
파일이름: BankingSystem.cpp
프로그램 main 부분
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
		cout << "선택: ";
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