

#include "String.h"

String::String() //디폴트 생성자
{
	len = 0;
	str = NULL;
}

String::String(const char* s) //생성자
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s) //복사생성자
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String() //삭제
{
	if (str != NULL)
		delete[] str;
}

String& String::operator=(const String& s) //대입연산자 오버로딩
{
	if (str != NULL)
		delete[] str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s) //이어붙이기 연산자 오버로딩
{
	len += (s.len - 1);
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	if (str != NULL)
		delete[] str;
	str = tempstr;
	return*this;
}

bool String::operator==(const String& s) //strcmp 오버로딩
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+(const String& s) //문자열 합치기 오버로딩
{
	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	String temp(tempstr); //String temp= tempstr;
	delete[]tempstr;
	return temp;
}

ostream& operator<<(ostream& os, const String& s) //출력 오버로딩
{
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s) //입력 오버로딩
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}