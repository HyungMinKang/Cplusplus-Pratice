#include <iostream>

namespace BestComImp1
{
	void SimpleFun(void)
	{
		std::cout << "BestCom�� ������ �Լ�" << std::endl;
	}
}

namespace ProgComImpl
{
	void SimpleFun(void)
	{
		std::cout << "ProCom�� ������ �Լ�" << std::endl;
	}
}

int main(void)
{
	BestComImp1::SimpleFun();
	ProgComImpl::SimpleFun();
	return 0;
}