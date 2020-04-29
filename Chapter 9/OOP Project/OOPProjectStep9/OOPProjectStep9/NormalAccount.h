/*
Ŭ�����̸�: NormalAccount
Ŭ��������: Entity
*/
#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
	int basicrate; //������ %���� 

public:
	NormalAccount(int id, int money, String name, int rate) : Account(id, money, name), basicrate(rate) {}

	virtual void Deposit(int money)
	{
		Account::Deposit(money); //���� �߰�
		Account::Deposit(money * (basicrate / 100.0)); //���� �߰�
	}
};


#endif // !__NORMAL_ACCOUNT_H__