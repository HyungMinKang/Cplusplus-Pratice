#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& ref){}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& ref){}

public:
	BoundCheckIntArray(int len) :arrlen(len) { arr = new int[len]; }
	int& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray()
	{
		delete[]  arr;
	}
};

typedef BoundCheckIntArray* ARRAY_PTR;

class BoundCheckInt2DArray
{
private:
	BoundCheckIntArray ** arr;
	int arrlen;
	BoundCheckInt2DArray(const BoundCheckInt2DArray& ref) {}
	BoundCheckInt2DArray& operator=(const BoundCheckInt2DArray& ref) {}

public:
	BoundCheckInt2DArray(int col, int row) :arrlen(col)
	{
		arr = new ARRAY_PTR[col];
		for (int i = 0; i < arrlen; i++)
			arr[i] = new BoundCheckIntArray(row);
	}

	BoundCheckIntArray& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return *(arr[idx]);
	}

	~BoundCheckInt2DArray()
	{
		for (int i = 0; i < arrlen; i++)
			delete arr[i];
		delete[] arr;
	}

};

int main(void)
{
	BoundCheckInt2DArray arr2d(3, 4);
	for (int n = 0; n < 3; n++)
		for (int m = 0; m < 4; m++)
			arr2d[n][m] = n + m;

	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			cout << arr2d[n][m] << ' ';
		}
		cout << endl;
	}
	return 0;
}