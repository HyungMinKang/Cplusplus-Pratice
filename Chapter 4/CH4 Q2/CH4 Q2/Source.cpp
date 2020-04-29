#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	
	Point(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	
	
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << '[' << xpos << " , " << ypos << ']' << endl;
	}
};

class Circle
{
private:
	Point cpos;
	int rad;
public:


	Circle(int x, int y, int len) :cpos(x,y), rad(len)
	{

	}


	void ShowCircleInfo()const
	{
		cout << "radius: " << rad << endl;
		cpos.ShowPointInfo();
	}

};

class Ring
{
private:
	Circle innerCircle;
	Circle outterCircle;
public:

	Ring(int Inx, int Iny, int Inlen, int OutX, int OutY, int Outlen) : innerCircle(Inx, Iny, Inlen), outterCircle(OutX, OutY, Outlen)
	{}
	

	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		innerCircle.ShowCircleInfo();
		cout << "Outer Circle Info..." << endl;
		outterCircle.ShowCircleInfo();

	}
};

int main(void)
{
	Ring ring(1, 1, 4, 2, 2, 9);
	
	ring.ShowRingInfo();
	return 0;
}