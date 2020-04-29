#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class InSuffException
{
private:
	int balance;
	int reqMon;
public:
	InSuffException(int val, int req) : balance(val),reqMon(req)
	{}

	void ShowExceptionReason()const
	{
		cout << "[예외 메세지: 잔액에서" << reqMon-balance << "가(이) 부족합니다]" << endl;
	}
};

class MinusException
{
private:
	int eval;

public:
	MinusException(int mon):eval(mon){}

	void ShowExceptionReason() const
	{
		cout << "입(출)금액" << eval << "은 유효하지 않습니다" << endl;
	}

		
};
#endif // !__ACOUNT_EXCEPTION_H__
