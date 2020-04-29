/* step3 수정사항
 깊은 복사- 복사 생성자 정의
 Account 클래스

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

	int GetAccID() { return accID; }

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

	void ShowAccInfo()
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

Account* accArr[100]; //객체 배열
int accNum = 0; // 객체수

int main(void)
{
	int choice;
	while (1)
	{
		showMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			makeAccount();
			break;
		case DEPOSIT:
			depositMoney();
			break;

		case WITHDRAW:
			withdrawMoney();
			break;
		case INQUIRE:
			showAll();
			break;
		case EXIT:
			return 0;
		default:
			cout << "illegal selection!" << endl;

		}
	}
	return 0;
}

void showMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금 " << endl;
	cout << "3. 출 금 " << endl;
	cout << "4. 계좌정보 전체출력 " << endl;
	cout << "5. 프로그래 종료 " << endl;
}

void makeAccount(void)
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

void depositMoney(void)
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

void withdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;


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

void showAll(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}