#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "BoundCheckArray.h"
#include "Account.h"
/*
클래스이름: AccountHandler
클래스 종류: Controller
*/
class AccountHandler  //계좌 관리 클래스 
{
private:
	int accNum; //계좌수
	BoundCheckArray<Account*> accArr;//계좌객체 담을 객체배열
public:
	AccountHandler(); //생성자: 계좌수 0으로 초기화
	void showMenu(void) const; //메뉴출력 - 단순 출력문- const
	void makeAccount(void); //계좌생성 
	void depositMoney(void); //입금
	void withdrawMoney(void); //출금
	void showAll(); //전체 출력
	~AccountHandler();

protected:
	void makeNormalAccount(void); 
	void makeCreditAccount(void);
};

#endif // !__ACCOUNT_HANDLER_H__
