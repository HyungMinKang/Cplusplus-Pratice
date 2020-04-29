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
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
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
		cout << "이름: " << name << endl;
		cout << "회사: " << compName << endl;
		cout << "전화번호: " << phNumber << endl;
		cout << "직급: "; NAME_CARD::ShowPosition(pos);
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