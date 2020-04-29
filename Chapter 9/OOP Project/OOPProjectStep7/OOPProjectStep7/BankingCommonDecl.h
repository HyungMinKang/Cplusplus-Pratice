/*
파일이름: BankingCommonDecl.h
프로그램 전체 공통 헤드부분
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

//프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//계좌 종류
enum { NORMAL = 1, CREDIT = 2 };


#endif // !__BANKING_COMMON_H__

