/* step6 수정사항

 상속 관계 구현
 보통 계좌/ 신용개좌= enum 구현
 신용 등급 A,B,C = enum 구현
 보통 이자율 3
 신용 이자율 3
 등급별 7, 4, 2 추가 이율
 이자계산 과정 인트형 처리 
 초기입금 금액 계산 X
 제어 클래스 변경 X 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;


//프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//신용등급
enum{LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

//계좌 종류
enum{NORMAL=1, CREDIT=2};

/*
클래스 이름: Account
클래스 유형: Entity
*/

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
		cout << "계좌ID: " << accID << endl;
		cout << "이름: " << cusName << endl;
		cout << "잔액: " << balance << endl;
	}

	~Account()
	{
		delete[] cusName;
	}
};

/*
클래시이름: NormalAccount
클래시종류: Entity
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
클래스이름: HighCreditAccount 
클래스 종류: Entity
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
클래스이름: AccountHandler
클래스 종류: Controller
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
	cout << "계좌ID: ";  cin>> id ;
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


