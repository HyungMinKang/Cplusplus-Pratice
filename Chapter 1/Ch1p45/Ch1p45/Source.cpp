#include <iostream>

namespace Hybrid
{
	void HybFun(void)
	{
		std::cout << "SO SIMPLE FUNCTION" << std::endl;
		std::cout << "IN NAMESPACE HYBRID" << std::endl;
	}
}

int main(void)
{
	using Hybrid::HybFun;
	HybFun();
	return 0;
}