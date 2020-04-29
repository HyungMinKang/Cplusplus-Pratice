#include <iostream>

namespace BestComImp1
{
	void SimpleFun(void)
	{
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}

namespace ProgComImpl
{
	void SimpleFun(void)
	{
		std::cout << "ProCom이 정의한 함수" << std::endl;
	}
}

int main(void)
{
	BestComImp1::SimpleFun();
	ProgComImpl::SimpleFun();
	return 0;
}