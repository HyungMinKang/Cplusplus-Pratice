/*
클래시이름: NormalAccount
클래시종류: Entity
*/
#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
	int basicrate; //이자율 %단위 

public:
	NormalAccount(int id, int money, char* name, int rate) : Account(id, money, name), basicrate(rate) {}

	virtual void Deposit(int money)
	{
		Account::Deposit(money); //원금 추가
		Account::Deposit(money * (basicrate / 100.0)); //이자 추가
	}
};


#endif // !__NORMAL_ACCOUNT_H__