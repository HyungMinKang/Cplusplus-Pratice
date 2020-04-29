/*
파일이름: Accout.cpp
Account 클래스 body부분
*/

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int id, int money, String name) : accID(id), balance(money) //생성자 정의 
{
	cusName = name;
}

//Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance) //복사생성자


//Account& Account::operator=(const Account& ref) //대입연산자 

int Account::GetAccID() const { return accID; }  // 계좌ID값 반환, const  선언

void Account::Deposit(int money)  //가상함수- 추후 상속 클래스에서 재정의
{	
	if (money < 0)
		throw MinusException(money);
	balance += money;
}

int Account::Withdraw(int money) 
{
	if (money < 0)
		throw MinusException(money);
	
	if (balance < money)
		throw InSuffException(balance, money);

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const  //계좌 정보 출력함수, const 선언
{
	cout << "계좌ID: " << accID << endl;
	cout << "이름: " << cusName << endl;
	cout << "잔액: " << balance << endl;
}

//Account::~Account()
