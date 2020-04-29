#include <iostream>
using namespace std;

int main(void)
{
	int dan;
	cout << "¸î ´Ü? ";
	cin >> dan;

	for (int i = 1; i < 10; i++)
	{
		cout << dan << " * " << i << " = " << dan * i << endl;
	}
	
	return 0;
}