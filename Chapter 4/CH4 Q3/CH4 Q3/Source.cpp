#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace NAME_CARD
{
	enum{CLERK,SENIOR,ASSIST,MANAGER};


	void ShowPosition(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
			break;

		}
	}
}

class NameCard
{
private:
	char *name;
	char *compName;
	char* phNumber;
	int pos;

public :
	NameCard(char* _name, char* _compName, char* _phNumber, int pos) :pos(pos)
	{
		name = new char[strlen(_name) + 1];
		compName = new char[strlen(_compName) + 1];
		phNumber = new char[strlen(_phNumber) + 1];
		strcpy(name, _name);
		strcpy(compName, _compName);
		strcpy(phNumber, _phNumber);
	}

	void ShowNameCardInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << compName << endl;
		cout << "��ȭ��ȣ: " << phNumber << endl;
		cout << "����: "; NAME_CARD::ShowPosition(pos);
		cout << endl;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", NAME_CARD::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", NAME_CARD::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", NAME_CARD::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}