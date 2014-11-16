#include "Air.h"

Air::Air()
:Robot("Air Bot", "00000000000", 75555.99, false, false)
{
	rotorType = "Basic";
	highAltitude = false;
	autoPilot = false;
}
Air::~Air()
{

}
void Air::Reset(string num)
{
	setReset(true);
	setNum(num);
	setPrice(75555.99);
	setiOS(false);
	setAndroid(false);
	rotorType = "Basic";
	autoPilot = false;
	highAltitude = false;
}
void Air::setRotor(string setRotor)
{
	rotorType = setRotor;
}
void Air::setAlt(bool setAlt)
{
	if(setAlt)
	{
		if(highAltitude)
		{
			cout << "\nThis Air Bot already has a high altitude upgrade\n";
		}
		else
		{
			highAltitude = setAlt;
			setPrice(getPrice() + 700.99);
			cout << "\nPrucahsed high-altitude capability ($700.99)\n";
		}
	}
	else if(!setAlt && !getReset())
	{
		if(highAltitude)
		{
			highAltitude = setAlt;
			setPrice(getPrice() - 700.99);
			cout << "\nRemoved high-altitude capability (-$700.99)\n";
		}
		else
		{
			cout << "\nThis Air Bot does not have high altitude capabilities\n";
		}
	}

}
void Air::setAuto(bool setAuto)
{
	if(setAuto)
	{
		if(autoPilot)
		{
			cout << "\nThis Air Bot already has an auto pilot upgrade\n";
		}
		else
		{
			autoPilot = setAuto;
			setPrice(getPrice() + 1200.99);
			cout << "\nPurchased auto-pilot ($1200.99)\n";
		}
	}
	else if(!setAuto && !getReset())
	{
		if(autoPilot)
		{
			autoPilot = setAuto;
			setPrice(getPrice() - 1200.99);
			cout << "\nRemoved auto pilot capability (-$1200.99)\n";
		}
		else
		{
			cout << "\nThis Air Bot does not have auto pilot\n";
		}
	}

}
string Air::getRotor()
{
	return rotorType;
}
bool Air::getAlt()
{
	return highAltitude;
}
bool Air::getAuto()
{
	return autoPilot;
}
void Air::Display(ostream &file)
{
	Robot::Display(file);
	DisplayUpgrades(file);
}
void Air::DisplayUpgrades(ostream &file)
{
	Robot::DisplayUpgrades(file);
	if(highAltitude)
	{
		file << "High altitude upgrade\n";
	}
	if(autoPilot)
	{
		file << "Auto-pilot upgrade\n";
	}
	if(!getiOS() && !getAndroid() && !highAltitude && !autoPilot)
	{
		file << "None\n";
	}
}
