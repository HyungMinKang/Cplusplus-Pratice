#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* myname, int myage) : age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}

	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* myname, int myage, const char* myaddr, const char* myphone) : MyFriendInfo(myname, myage)
	{
		addr = new char[strlen(myaddr) + 1];
		strcpy(addr, myaddr);
		phone = new char[strlen(myphone) + 1];
		strcpy(phone, myphone);
	}

	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl<<endl;
	}
};

int main(void)
{
	MyFriendDetailInfo inf1("AA", 23, "111-222", "333-444-555");
	MyFriendDetailInfo inf2("BB", 27, "333-444", "345-6666-777");

	inf1.ShowMyFriendDetailInfo();
	inf2.ShowMyFriendDetailInfo();
}