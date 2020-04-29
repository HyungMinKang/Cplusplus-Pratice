#include <iostream>
using namespace std;

template <typename  T>
void Swap(T* x, T* y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	int num1 = 20, num2 = 30;
	Swap(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;

	char ch1 = 'A', ch2 = 'Z';
	Swap(&ch1, &ch2);
	cout << ch1 << ' ' << ch2 << endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	Swap(&dbl1, &dbl2);
	cout << dbl1 << ' ' << dbl2 << endl;
}