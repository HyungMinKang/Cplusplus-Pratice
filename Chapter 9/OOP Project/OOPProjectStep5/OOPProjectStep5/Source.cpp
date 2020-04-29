/* step4 수정사항

 AccountHandler 클래스 구현- 컨트롤 클래스
 전역함수,  Accout 객 체저장을 위해 선언한 배열, 변수 

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
	char* cusName; // 고객이름
	int accID; //고객 아이디
	int balance; // 잔액

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
		cout << "계좌ID: " << accID << endl;
		cout << "이름: " << cusName << endl;
		cout << "잔액: " << balance << endl;
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금 " << endl;
	cout << "3. 출 금 " << endl;
	cout << "4. 계좌정보 전체출력 " << endl;
	cout << "5. 프로그래 종료 " << endl;
}

void AccountHandler:: makeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "계좌개설" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler:: depositMoney(void)
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




