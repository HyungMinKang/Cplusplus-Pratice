#include <iostream>
using namespace std;

class Rectangle
{
private:
	int row;
	int col;

public:
	Rectangle(int len1, int len2) :row(len1), col(len2)
	{}

	void ShowAreaInfo()
	{
		cout << "¸éÀû: " << row * col<<endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int side) : Rectangle(side, side) 
	{}

	
};

int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}