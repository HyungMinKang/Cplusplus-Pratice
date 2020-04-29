/* step6 ��������

 ��� ���� ����
 ���� ����/ �ſ밳��= enum ����
 �ſ� ��� A,B,C = enum ����
 ���� ������ 3
 �ſ� ������ 3
 ��޺� 7, 4, 2 �߰� ����
 ���ڰ�� ���� ��Ʈ�� ó�� 
 �ʱ��Ա� �ݾ� ��� X
 ���� Ŭ���� ���� X 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;


//���α׷� ������� ���� �޴�
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//�ſ���
enum{LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

//���� ����
enum{NORMAL=1, CREDIT=2};

/*
Ŭ���� �̸�: Account
Ŭ���� ����: Entity
*/

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

	virtual void Deposit(int money)
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

/*
Ŭ�����̸�: NormalAccount
Ŭ��������: Entity
*/
class NormalAccount : public Account
{
private:
	int basicrate;

public:
	NormalAccount(int id, int money,char* name, int rate): Account(id,money,name), basicrate(rate){}

	virtual void Deposit(int money)
	{	
		Account::Deposit(money);
		Account::Deposit(money * (basicrate / 100.0));
	}
};



/*
Ŭ�����̸�: HighCreditAccount 
Ŭ���� ����: Entity
*/

class HighCreditAccount : public NormalAccount
{
private:
	int specialrate;

public:
	HighCreditAccount(int id, int money, char* name, int rate, int credit) : NormalAccount(id, money, name,rate), specialrate(credit)
	{}

	virtual void Deposit(int money)
	{	
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialrate / 100.0));
	}
};

/*
Ŭ�����̸�: AccountHandler
Ŭ���� ����: Controller
*/

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

protected:
	void makeNormalAccount(void);
	void makeCreditAccount(void);
};

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
	cout << "����ID: ";  cin>> id ;
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
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate,LEVEL_A);
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


