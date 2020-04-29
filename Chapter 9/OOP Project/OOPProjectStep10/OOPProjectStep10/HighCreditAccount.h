#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
/*
Ŭ�����̸�: HighCreditAccount
Ŭ���� ����: Entity
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
		NormalAccount::Deposit(money); //���ݰ� ���� �߰�
		Account::Deposit(money * (specialrate / 100.0)); //Ư�� ���� �߰�
	}
};

#endif // !__HIGHCREDIT_ACCOUNT_H__
