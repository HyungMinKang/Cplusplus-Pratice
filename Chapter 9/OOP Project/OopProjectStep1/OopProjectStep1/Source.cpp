//1 메뉴출력
//2계좌개설 - 계좌ID, 이름, 보유액 -구조체 =>  구조체들을 담을 배열 필요
//3 입 금 -  계좌ID ,  입금액 입력 -> 계좌ID가 존재하지 않은 경우 오류메세지 
//4 출 금 -  계좌ID , 출금액 입력-> 출금액> 보유액 오류메세지 
//5 전체정보 출력 - for문으로 구조체 배열 다 출력
//6 종료 - break문으로 while문 탈출
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

typedef struct {
	int accID; //계좌Id
	char cusname[NAME_LEN]; //계좌소유자 이름
	int balacne; //잔액
}Account;

Account accArr[100]; //계좌정보 담을 배열
int accNum = 0; //개설한 계좌 수

void showMenu(void);
void makeAccount(void);
void depositMoney(void);
void withdrawMoney(void);
void showAll(void);

int main(void)
{
	int choice;
	while (1)
	{
		showMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			makeAccount();
			break;
		case 2:
			depositMoney();
			break;

		case 3:
			withdrawMoney();
			break;
		case 4:
			showAll();
			break;
		case 5:
			return 0;
		default:
			cout << "illegal selection!" << endl;

		}
	}
	return 0;
}

void showMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금 " << endl;
	cout << "3. 출 금 " << endl;
	cout << "4. 계좌정보 전체출력 " << endl;
	cout << "5. 프로그래 종료 " << endl;
}

void makeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "계좌개설" << endl;
	cout << "계좌ID: "; 
	cin >>id;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;

	accArr[accNum].accID = id;
	strcpy(accArr[accNum].cusname, name);
	accArr[accNum].balacne = balance;
	accNum++;
}

void depositMoney(void)
{
	int id;
	int money;
	cout << "[입 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balacne += money;
			cout << "입 금 완 료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" << endl << endl;
}

void withdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;


	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balacne < money)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i].balacne -= money;
			cout << "출 금 완 료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" << endl << endl;
}

void showAll(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌 ID: " << accArr[i].accID << endl;
		cout << "이 름 :" << accArr[i].cusname << endl;
		cout << " 잔 액: " << accArr[i].balacne << endl << endl;
	}
}