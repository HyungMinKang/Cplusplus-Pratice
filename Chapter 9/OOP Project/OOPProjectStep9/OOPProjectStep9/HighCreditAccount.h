#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
/*
클래스이름: HighCreditAccount
클래스 종류: Entity
*/

class HighCreditAccount : public NormalAccount
{
private:
	int specialrate;

public:
	HighCreditAccount(int id, int money, String name, int rate, int credit) : NormalAccount(id, money, name, rate), specialrate(credit)
	{}

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money); //원금과 이자 추가
		Account::Deposit(money * (specialrate / 100.0)); //특별 이자 추가
	}
};

#endif // !__HIGHCREDIT_ACCOUNT_H__
