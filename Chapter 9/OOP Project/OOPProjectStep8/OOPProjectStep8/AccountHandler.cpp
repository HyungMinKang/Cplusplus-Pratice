
/*
클래스이름: AccountHandler.cpp - AccountHandler 기능 구현
클래스 종류: Controller
*/


#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"




void AccountHandler::showMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금 " << endl;
	cout << "3. 출 금 " << endl;
	cout << "4. 계좌정보 전체출력 " << endl;
	cout << "5. 프로그래 종료 " << endl;
}

void AccountHandler::makeAccount(void)
{
	int sel;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌" << "2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> sel;

	if (sel == NORMAL)
	{
		makeNormalAccount();
	}
	else
		makeCreditAccount();

}

void AccountHandler::makeNormalAccount(void)
{
	int id;
	int balance;
	char name[NAME_LEN];
	int interRate;

	cout << "[보통예금 계좌 개설]" << endl;
	cout << "계좌ID: ";  cin >> id;
	cout << "이름: "; cin >> name;
	cout << "잔액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::makeCreditAccount(void)
{
	int id;
	int balance;
	char name[NAME_LEN];
	int interRate;
	int creditLevel;

	cout << "[보통예금 계좌 개설]" << endl;
	cout << "계좌ID: ";  cin >> id;
	cout << "이름: "; cin >> name;
	cout << "잔액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << "신용등급:(1toA, 2toB, 3toC) "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
	}

}


void AccountHandler::depositMoney(void)
{
	int id;
	int money;
	cout << "[입 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입 금 완 료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" << endl << endl;
}


void AccountHandler::withdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;


	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액부족 " << endl << endl;
				return;
			}
			cout << "출 금 완 료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" << endl << endl;
}


void  AccountHandler::showAll(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::AccountHandler() :accNum(0) {};

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}