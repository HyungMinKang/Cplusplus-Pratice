/*
�����̸�: Accout.cpp
Account Ŭ���� body�κ�
*/

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int id, int money, String name) : accID(id), balance(money) //������ ���� 
{
	cusName = name;
}

//Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance) //���������


//Account& Account::operator=(const Account& ref) //���Կ����� 

int Account::GetAccID() const { return accID; }  // ����ID�� ��ȯ, const  ����

void Account::Deposit(int money)  //�����Լ�- ���� ��� Ŭ�������� ������
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

void Account::ShowAccInfo() const  //���� ���� ����Լ�, const ����
{
	cout << "����ID: " << accID << endl;
	cout << "�̸�: " << cusName << endl;
	cout << "�ܾ�: " << balance << endl;
}

//Account::~Account()
