#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}

	void ShowPosition() const
	{
		cout << '[' << xpos << " , " << ypos << ']' << endl;
	}

	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}

	Point& operator-()
	{	
		Point copy=Point(-xpos,-ypos);
		
		return copy;
	}


	friend Point& operator--(Point& ref);
	friend Point operator~(const Point& ref);
};

Point& operator--(Point& ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

Point operator~(const Point& ref)
{
	Point copy(ref.ypos, ref.xpos);
	
	return copy;
	
}


int main(void)
{
	Point pos1(1, 2);
	
	Point pos2 = pos1.operator-();
	pos2.ShowPosition();
	pos2 = operator~(pos2);
	pos2.ShowPosition();

	return 0;
}