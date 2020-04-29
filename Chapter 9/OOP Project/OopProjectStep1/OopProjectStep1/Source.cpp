//1 �޴����
//2���°��� - ����ID, �̸�, ������ -����ü =>  ����ü���� ���� �迭 �ʿ�
//3 �� �� -  ����ID ,  �Աݾ� �Է� -> ����ID�� �������� ���� ��� �����޼��� 
//4 �� �� -  ����ID , ��ݾ� �Է�-> ��ݾ�> ������ �����޼��� 
//5 ��ü���� ��� - for������ ����ü �迭 �� ���
//6 ���� - break������ while�� Ż��
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

typedef struct {
	int accID; //����Id
	char cusname[NAME_LEN]; //���¼����� �̸�
	int balacne; //�ܾ�
}Account;

Account accArr[100]; //�������� ���� �迭
int accNum = 0; //������ ���� ��

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
		cout << "����: ";
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
	cout << "1. ���°���" << endl;
	cout << "2. �� �� " << endl;
	cout << "3. �� �� " << endl;
	cout << "4. �������� ��ü��� " << endl;
	cout << "5. ���α׷� ���� " << endl;
}

void makeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "���°���" << endl;
	cout << "����ID: "; 
	cin >>id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
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
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balacne += money;
			cout << "�� �� �� ��" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;
}

void withdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;


	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balacne < money)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			accArr[i].balacne -= money;
			cout << "�� �� �� ��" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;
}

void showAll(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "���� ID: " << accArr[i].accID << endl;
		cout << "�� �� :" << accArr[i].cusname << endl;
		cout << " �� ��: " << accArr[i].balacne << endl << endl;
	}
}