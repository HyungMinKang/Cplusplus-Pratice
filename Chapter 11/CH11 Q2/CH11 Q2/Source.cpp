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
		this->title = new char[strlen(bTitle) + 1];
		strcpy(this->title, bTitle);

		this->isbn = new char[strlen(bisbn) + 1];
		strcpy(this->isbn, bisbn);
	}

	Book(const Book& ref):price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}

	Book& operator=(const Book& ref)
	{
		delete[] title;
		delete[] isbn;
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	~Book()
	{
		delete[] title;
		delete[] isbn;
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

	EBook(const EBook& ref):Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}

	EBook& operator=(const EBook& ref)
	{
		Book::operator=(ref);
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl << endl;
	}
	~EBook()
	{
		delete[] DRMKey;
	}
};

int main(void)
{
	
	EBook ebook1("좋은 C++ ebook", "555-12345-890-0", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	cout << endl;
	EBook ebook3("dumy", "dumy", 0, "dumy");
	ebook3 = ebook2;
	ebook3.ShowEBookInfo();
	return 0;
	
}