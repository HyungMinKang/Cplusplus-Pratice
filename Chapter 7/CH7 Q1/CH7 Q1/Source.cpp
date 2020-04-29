#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int gasGauage):gasolineGauge(gasGauage){}
	
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:

	HybridCar(int gasGauage, int elecGauage):  Car(gasGauage), electricGauge(elecGauage){}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gasGauage, int elecGauage, int watGauage): HybridCar(gasGauage, elecGauage), waterGauge(watGauage){}
	void ShowCurrentGauage()
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl;
	}

};

int main(void)
{
	HybridWaterCar hwCar1(1000, 2000, 3000);
	hwCar1.ShowCurrentGauage();

}