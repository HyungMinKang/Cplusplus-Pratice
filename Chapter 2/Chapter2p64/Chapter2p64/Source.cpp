#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int num = 10;
	int i = 0;

	cout << "true:" << true << endl;
	cout << "false: " << false << endl;

	while (true)
	{
		cout << i++ << ' ';
		if (i > num)
			break;
	}
	cout << endl;

	cout << "sizeof 1: " << sizeof(1) << endl;
	cout << "sizeof 0: " << sizeof(0) << endl;
	cout << "size of true: " << sizeof(true) << endl;
	cout << "size of false:" << sizeof(false) << endl;
	return 0;
}