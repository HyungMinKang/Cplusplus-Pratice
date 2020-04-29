/*
파일이름: Accout.cpp
Account 클래스 body부분
*/

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int id, int money, char* name) : accID(id), balance(money) //생성자 정의 
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance) //복사생성자
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

Account& Account::operator=(const Account& ref) //대입연산자 
{	
	accID = ref.accID;
	balance = ref.balance;
	delete[] cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
	
	return *this;
}
int Account::GetAccID() const { return accID; }  // 계좌ID값 반환, const  선언

void Account::Deposit(int money)  //가상함수- 추후 상속 클래스에서 재정의
{
	balance += money;
}

int Account::Withdraw(int money) 
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const  //계좌 정보 출력함수, const 선언
{
	cout << "계좌ID: " << accID << endl;
	cout << "이름: " << cusName << endl;
	cout << "잔액: " << balance << endl;
}

Account::~Account()
{
	delete[] cusName;
}
