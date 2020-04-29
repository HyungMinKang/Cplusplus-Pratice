/* step4 ��������

 AccountHandler Ŭ���� ����- ��Ʈ�� Ŭ����
 �����Լ�,  Accout �� ü������ ���� ������ �迭, ���� 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void showMenu(void);
void makeAccount(void);
void depositMoney(void);
void withdrawMoney(void);
void showAll(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	char* cusName; // ���̸�
	int accID; //�� ���̵�
	int balance; // �ܾ�

public:
	Account(int id, int money, char* name) : accID(id), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	Account(const Account& ref) : accID(ref.accID), balance(ref.balance)
	{
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}

	int GetAccID() const { return accID; }

	void Deposit(int money)
	{
		balance += money;
	}

	int Withdraw(int money)
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	void ShowAccInfo() const
	{
		cout << "����ID: " << accID << endl;
		cout << "�̸�: " << cusName << endl;
		cout << "�ܾ�: " << balance << endl;
	}

	~Account()
	{
		delete[] cusName;
	}
};

class AccountHandler
{
private:
	int accNum;
	Account* accArr[100];

public:
	AccountHandler();
	void showMenu(void) const;
	void makeAccount(void);
	void depositMoney(void);
	void withdrawMoney(void);
	void showAll();
	~AccountHandler();
};

void AccountHandler:: showMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� �� " << endl;
	cout << "3. �� �� " << endl;
	cout << "4. �������� ��ü��� " << endl;
	cout << "5. ���α׷� ���� " << endl;
}

void AccountHandler:: makeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "���°���" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler:: depositMoney(void)
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




