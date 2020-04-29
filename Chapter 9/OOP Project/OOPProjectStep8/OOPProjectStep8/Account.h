/*
  파일이름: Account.h
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accID; //계좌 ID
	int balance; // 잔액
	char* cusName; // 고객 이름

public:
	Account(int ID, int money, char* name);  // Account 클래스 생성자
	Account(const Account& ref); // 복사 생성자
	Account& operator=(const Account& ref);

	int GetAccID() const;  //계좌ID 반환 매서드
	virtual void Deposit(int money); // 가상함수 선언 이유- NormalAccount, HighCreditAccount에서 오버로딩 // 계좌에 입금 함수
	int Withdraw(int money); // 계좌에서 돈 인출함수
	void ShowAccInfo() const; //계좌정보 출력
	~Account(); // 객체 삭제 매서드

};
#endif