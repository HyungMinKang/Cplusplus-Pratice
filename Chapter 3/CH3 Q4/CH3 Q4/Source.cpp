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
			cout << "잘못된 정보가 전달되어 판매를 취소합니다" << endl;
			return 0;
		}
		int num = money / applePrice;
		numOfApple -= num;
		myMoney += money;
		return num;
	}

	void ShowResult() const
	{
		cout << "남은 사과: " << numOfApple << endl;
		cout << "판매 수익 : " << myMoney << endl;
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
			cout << "잘못된 정보가 전달되어 구매를 취소합니다" << endl;
			return;
		}
		int num = seller.sellApple(money);
		myMoney -= money;
		numofApple += num;
	}

	void ShowResult() const
	{
		cout << "보유한 사과수: " << numofApple << endl;
		cout << "남은 돈:  " << myMoney << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.Init(1000, 20,0);
	FruitBuyer buyer;
	buyer.Init(5000);
	buyer.buyApple(seller, 2000);

	cout << "과일 판매자 현황" << endl;
	seller.ShowResult();
	cout << endl;
	cout << "과일 구매자 현황" << endl;
	buyer.ShowResult();
	return 0;
}