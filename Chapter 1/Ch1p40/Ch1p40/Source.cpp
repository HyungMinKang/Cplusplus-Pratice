#include <iostream>

namespace BestComImpl
{
	void SimpleFun(void);
}

namespace ProComImpl
{
	void SimpleFun(void);
}

int main(void)
{
	BestComImpl::SimpleFun();
	ProComImpl::SimpleFun();
	return 0;
}

void BestComImpl::SimpleFun(void)
{
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
}

void ProComImpl::SimpleFun(void)
{
	std::cout << "ProCom�� ������ �Լ�" << std::endl;
}