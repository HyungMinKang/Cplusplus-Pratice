#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "BoundCheckArray.h"
#include "Account.h"
/*
Ŭ�����̸�: AccountHandler
Ŭ���� ����: Controller
*/
class AccountHandler  //���� ���� Ŭ���� 
{
private:
	int accNum; //���¼�
	BoundCheckArray<Account*> accArr;//���°�ü ���� ��ü�迭
public:
	AccountHandler(); //������: ���¼� 0���� �ʱ�ȭ
	void showMenu(void) const; //�޴���� - �ܼ� ��¹�- const
	void makeAccount(void); //���»��� 
	void depositMoney(void); //�Ա�
	void withdrawMoney(void); //���
	void showAll(); //��ü ���
	~AccountHandler();

protected:
	void makeNormalAccount(void); 
	void makeCreditAccount(void);
};

#endif // !__ACCOUNT_HANDLER_H__
