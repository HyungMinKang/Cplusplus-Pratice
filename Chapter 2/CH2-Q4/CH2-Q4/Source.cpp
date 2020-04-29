#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* temp = new Point;
	temp->xpos = (p1.xpos + p2.xpos);
	temp->ypos = (p1.ypos + p2.ypos);
	return *temp;
}

int main(void)
{
	Point* p1 = new Point;
	Point* p2 = new Point;
	p1->xpos = 3;
	p1->ypos = 5;
	p2->xpos = 4;
	p2->ypos = 6;

	Point& pref = PntAdder(*p1, *p2);
	cout << "[" << pref.xpos << " , " << pref.ypos << "]" << endl;

	delete[]p1;
	delete[]p2;
	delete &pref;
}