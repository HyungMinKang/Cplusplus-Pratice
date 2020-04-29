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
		cout << "[���� �޼���: �ܾ׿���" << reqMon-balance << "��(��) �����մϴ�]" << endl;
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
		cout << "��(��)�ݾ�" << eval << "�� ��ȿ���� �ʽ��ϴ�" << endl;
	}

		
};
#endif // !__ACOUNT_EXCEPTION_H__
