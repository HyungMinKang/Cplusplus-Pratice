#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;

public:
	Book(const char* bTitle, const char* bisbn, int bprice) : price(bprice)
	{
		title = new char[strlen(bTitle) + 1];
		strcpy(title, bTitle);

		isbn = new char[strlen(bisbn) + 1];
		strcpy(isbn, bisbn);
	}

	void ShowBookInfo()
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;

public:
	EBook(const char* bTitle, const char* bisbn, int bprice, const char* bDRMKey) : Book(bTitle, bisbn, bprice)
	{
		DRMKey = new char[strlen(bDRMKey) + 1];
		strcpy(DRMKey, bDRMKey);
	}

	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl << endl;
	}
};

int main(void)
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-0", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}