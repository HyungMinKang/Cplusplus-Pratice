#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int applePrice;
	int numOfApple;
	int myMoney;

public:

	void Init(int price, int num, int money)
	{
		applePrice = price;
		numOfApple = num;
		myMoney = money;
	}

	int sellApple(int money)
	{	
		if (money < 0)
		{
			cout << "�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�" << endl;
			return 0;
		}
		int num = money / applePrice;
		numOfApple -= num;
		myMoney += money;
		return num;
	}

	void ShowResult() const
	{
		cout << "���� ���: " << numOfApple << endl;
		cout << "�Ǹ� ���� : " << myMoney << endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numofApple; 

public:
	void Init(int money)
	{
		myMoney = money;
		numofApple = 0;
	}

	void buyApple(FruitSeller& seller, int money)
	{ 
		if (money < 0)
		{
			cout << "�߸��� ������ ���޵Ǿ� ���Ÿ� ����մϴ�" << endl;
			return;
		}
		int num = seller.sellApple(money);
		myMoney -= money;
		numofApple += num;
	}

	void ShowResult() const
	{
		cout << "������ �����: " << numofApple << endl;
		cout << "���� ��:  " << myMoney << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.Init(1000, 20,0);
	FruitBuyer buyer;
	buyer.Init(5000);
	buyer.buyApple(seller, 2000);

	cout << "���� �Ǹ��� ��Ȳ" << endl;
	seller.ShowResult();
	cout << endl;
	cout << "���� ������ ��Ȳ" << endl;
	buyer.ShowResult();
	return 0;
}