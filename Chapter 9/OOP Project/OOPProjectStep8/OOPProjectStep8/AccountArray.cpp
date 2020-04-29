#include"BankingCommonDecl.h"
#include "AccountArray.h"

BountCheckAccountPtrArray::BountCheckAccountPtrArray(int len) : arrlen(len)
{
	arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BountCheckAccountPtrArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array Index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR BountCheckAccountPtrArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array Index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

int BountCheckAccountPtrArray::GetArrLen() const
{
	return arrlen;
}

BountCheckAccountPtrArray::~BountCheckAccountPtrArray()
{
	delete[] arr;
}