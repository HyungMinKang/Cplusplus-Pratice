#include <iostream>

namespace BestComImpl
{
	void SimpleFun(void);
}

namespace BestComImpl
{
	void PrettyFun(void);
}

namespace ProComImpl
{
	void SimpleFun(void);
}

int main(void)
{
	BestComImpl::SimpleFun();
	return 0;
}

void BestComImpl ::SimpleFun(void)
{
	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFun(); //동일 이름공간 함수 호출
	ProComImpl::SimpleFun(); // 다른 이른공간 함수 호출
}

void BestComImpl::PrettyFun(void)
{
	std::cout << "So Pretty" << std::endl;
}

void ProComImpl::SimpleFun(void)
{
	std::cout << "ProCom이 정의한 함수" << std::endl;
}