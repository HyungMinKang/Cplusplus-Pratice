#include <iostream>
using namespace std;

class Calculator
{
private:
	
	int addCount;
	int minCount;
	int mulCount;
	int divCount;
public:

	void Init();
	double Add(double x, double y );
	double Div(double x, double y);
	double Min(double x, double y);
	double Mul(double x, double y);
	void ShowOpCount();
};

void Calculator::Init()
{
	this->addCount = 0;
	this->divCount = 0;
	this->minCount = 0;
	this->mulCount = 0;
}

double Calculator::Add(double x, double y)
{
	this->addCount++;
	return x + y;
}

double Calculator::Min(double x, double y)
{
	this->minCount++;
	return x - y;
}

double Calculator::Mul(double x, double y)
{
	this->mulCount++;
	return x * y;
}

double Calculator::Div(double x, double y)
{
	this->divCount++;
	return x / y;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << this->addCount << ' ' << "»¬¼À: " << this->minCount << ' ' << "°ö¼À: " << this->mulCount << ' ' << "³ª´°¼À: " << this->divCount;
}

int main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}



