/*
  �����̸�: Account.h
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accID; //���� ID
	int balance; // �ܾ�
	char* cusName; // �� �̸�

public:
	Account(int ID, int money, char* name);  // Account Ŭ���� ������
	Account(const Account& ref); // ���� ������
	Account& operator=(const Account& ref);

	int GetAccID() const;  //����ID ��ȯ �ż���
	virtual void Deposit(int money); // �����Լ� ���� ����- NormalAccount, HighCreditAccount���� �����ε� // ���¿� �Ա� �Լ�
	int Withdraw(int money); // ���¿��� �� �����Լ�
	void ShowAccInfo() const; //�������� ���
	~Account(); // ��ü ���� �ż���

};
#endif