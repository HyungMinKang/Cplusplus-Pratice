
/*
Ŭ�����̸�: AccountHandler.cpp - AccountHandler ��� ����
Ŭ���� ����: Controller
*/


#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"




void AccountHandler::showMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� �� " << endl;
	cout << "3. �� �� " << endl;
	cout << "4. �������� ��ü��� " << endl;
	cout << "5. ���α׷� ���� " << endl;
}

void AccountHandler::makeAccount(void)
{
	int sel;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ���" << "2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
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

	cout << "[���뿹�� ���� ����]" << endl;
	cout << "����ID: ";  cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�ܾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
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

	cout << "[���뿹�� ���� ����]" << endl;
	cout << "����ID: ";  cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�ܾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���:(1toA, 2toB, 3toC) "; cin >> creditLevel;
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
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�� �� �� ��" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;
}


void AccountHandler::withdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;


	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺��� " << endl << endl;
				return;
			}
			cout << "�� �� �� ��" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;
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