

#include "String.h"

String::String() //����Ʈ ������
{
	len = 0;
	str = NULL;
}

String::String(const char* s) //������
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s) //���������
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String() //����
{
	if (str != NULL)
		delete[] str;
}

String& String::operator=(const String& s) //���Կ����� �����ε�
{
	if (str != NULL)
		delete[] str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s) //�̾���̱� ������ �����ε�
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

bool String::operator==(const String& s) //strcmp �����ε�
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+(const String& s) //���ڿ� ��ġ�� �����ε�
{
	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	String temp(tempstr); //String temp= tempstr;
	delete[]tempstr;
	return temp;
}

ostream& operator<<(ostream& os, const String& s) //��� �����ε�
{
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s) //�Է� �����ε�
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}