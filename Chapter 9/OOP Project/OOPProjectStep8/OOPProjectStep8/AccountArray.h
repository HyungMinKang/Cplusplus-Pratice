#pragma once
#ifndef __ACCOUNT_ARRAY_H__
#define __ACCONT_ARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BountCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* arr;
	int arrlen;
	BountCheckAccountPtrArray(const BountCheckAccountPtrArray& arr) {}
	BountCheckAccountPtrArray& operator=(const BountCheckAccountPtrArray& arr) {}

public:
	BountCheckAccountPtrArray(int len = 100);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BountCheckAccountPtrArray();
};

#endif // !1


