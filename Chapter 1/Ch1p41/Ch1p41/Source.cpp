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
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
	PrettyFun(); //���� �̸����� �Լ� ȣ��
	ProComImpl::SimpleFun(); // �ٸ� �̸����� �Լ� ȣ��
}

void BestComImpl::PrettyFun(void)
{
	std::cout << "So Pretty" << std::endl;
}

void ProComImpl::SimpleFun(void)
{
	std::cout << "ProCom�� ������ �Լ�" << std::endl;
}